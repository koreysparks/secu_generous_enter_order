#include "EESTrader.h"

#include <iostream>
#include <string.h>

Order::Order()
	:Qty(0)
	,SecuType(0)
	,SecuSubType(0)
	,CashMarginFlag(0)
	,Side(0)
	,Price(0.0)
	,PriceType(0)
	,MaxPriceLevel(0)
	,Tif(0)
	,ForceCoverFlag(0)
{}

Param::Param()
	:m_traderServerPort(0)
	,m_queryServerPort(0)
	,m_loopTime(10)
{}

CTrader::CTrader(const Param& p)
	:m_traderServerIp(p.m_traderServerIp)
	,m_traderServerPort(p.m_traderServerPort)
	,m_queryServerIp(p.m_queryServerIp)
	,m_queryServerPort(p.m_queryServerPort)
	,m_logonId(p.m_logonId)
	,m_logonPwd(p.m_logonPwd)
	,m_clinetId(p.m_clinetId)
	,m_fundAccount(p.m_fundAccount)
	,m_app_id(p.m_appID)
	,m_auth_code(p.m_authCode)
	,m_loopTime(p.m_loopTime)
	,m_local_mac("00-01-02-03-04-05")
	,m_logonStatus(0)
	,m_orderAcceptCount(0)
	,m_order(p.m_order)
	,m_exchangeID(p.m_exchangeID)
	,m_orderCount(p.m_orderCount)
{
}

CTrader::~CTrader(void)
{}

void CTrader::Run()
{
	bool ret = Init();
	if (!ret)
	{
		printf("%sIntence Init Failed !\n", TIME);
		return;
	}

	if(1 == m_logonStatus)
	{
		EnterOrder();		
	}
}

bool CTrader::Init()
{
	bool ret = LoadEESTrader();
	if (!ret)
	{
		return false;
	}
	
	char ch_trade_front_addr[128] = {0};
	sprintf(ch_trade_front_addr, "tcp://%s:%d", m_traderServerIp.c_str(), m_traderServerPort);

	char ch_query_front_addr[128] = {0};
	sprintf(ch_query_front_addr, "tcp://%s:%d", m_queryServerIp.c_str(), m_queryServerPort);
	
	assert(NULL != m_tradeApi);

	m_tradeApi->RegisterFront( ch_trade_front_addr, ch_query_front_addr );
	m_tradeApi->RegisterSpi(this);
	m_tradeApi->Init();	

	// µÈ´ýµÇÂ¼
	for(size_t i = 0; i < 500; ++i)
	{
		if(m_logonStatus != 0)
		{
			break;
		}

		_sleep_(40);
	}

	return true;
}

void CTrader::Close()
{
	if (m_tradeApi)
	{
		m_tradeApi->DisConnServer();
	}

	UnloadEESTrader();
}

void CTrader::_sleep_(size_t t)
{
	if(t == 0)
	{
		return;
	}

#ifdef WIN32

	Sleep(t);
#else

	usleep(t * 1000);

#endif
	
}

bool CTrader::LoadEESTrader()
{
#ifdef WIN32

	return Windows_LoadEESTrader();

#else

	return Linux_LoadEESTrader();

#endif
}

void CTrader::UnloadEESTrader()
{
#ifdef WIN32

	return Windows_UnloadEESTrader();

#else

	return Linux_UnloadEESTrader();

#endif
}

bool CTrader::Windows_LoadEESTrader()
{
#ifdef WIN32

	m_handle =  LoadLibrary(SHENGLI_TRADER_DLL_NAME);
	if (!m_handle)
	{
		printf("Load %s Failed\n", SHENGLI_TRADER_DLL_NAME);
		return false;
	}

	FuncCreateShengliTraderApi createFun = (FuncCreateShengliTraderApi)GetProcAddress(m_handle, CREATE_SHENGLI_TRADER_API_NAME);
	if (!createFun)
	{
		printf("Get %s Addr Failed!\n", CREATE_SHENGLI_TRADER_API_NAME);
		return false;
	}

	m_distoryFun = (FuncDestroyShengliTraderApi)GetProcAddress(m_handle, DESTROY_SHENGLITRADER_API_NAME);
	if (!m_distoryFun)
	{
		printf("Get %s Addr Failed!\n", DESTROY_SHENGLITRADER_API_NAME);
		return false;
	}

	m_tradeApi = createFun("./");
	if (!m_tradeApi)
	{
		printf("Create REM Object Failed!\n");
		return false;
	}

#endif

	return true;
}

void CTrader::Windows_UnloadEESTrader()
{
#ifdef WIN32

	if (m_tradeApi)
	{
		m_distoryFun(m_tradeApi);
		m_tradeApi = NULL;
		m_distoryFun = NULL;
	}

	if (m_handle)
	{
		FreeLibrary(m_handle);
		m_handle = NULL;
	}
#endif
}

bool CTrader::Linux_LoadEESTrader()
{
#ifndef WIN32
	m_handle =  dlopen(SHENGLI_TRADER_DLL_NAME, RTLD_LAZY);
	if (!m_handle)
	{
		printf("Load %s Failed, err:%s.\n", SHENGLI_TRADER_DLL_NAME, dlerror());
		return false;
	}

	FuncCreateShengliTraderApi createFun = (FuncCreateShengliTraderApi)dlsym(m_handle, CREATE_SHENGLI_TRADER_API_NAME);
	if (!createFun)
	{
		printf("Get %s Addr Failed!\n", CREATE_SHENGLI_TRADER_API_NAME);
		return false;
	}

	m_distoryFun = (FuncDestroyShengliTraderApi)dlsym(m_handle, DESTROY_SHENGLITRADER_API_NAME);
	if (!createFun)
	{
		printf("Get %s Addr Failed!\n", DESTROY_SHENGLITRADER_API_NAME);
		return false;
	}

	m_tradeApi = createFun(NULL);
	if (!m_tradeApi)
	{
		printf("Create REM Object Failed!\n");
		return false;
	}
#endif

	return true;
}

void CTrader::Linux_UnloadEESTrader()
{
#ifndef WIN32
	if (m_tradeApi)
	{
		m_distoryFun(m_tradeApi);
		m_tradeApi = NULL;
		m_distoryFun = NULL;
	}

	if (m_handle)
	{
		dlclose(m_handle);
		m_handle = NULL;
	}
#endif
}

int CTrader::ReqUserLogon()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n", TIME);
		return -1;
	}

	CShengliStockReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.LogonID, m_logonId.c_str());
	strcpy(req.Password, m_logonPwd.c_str());
	strcpy(req.ClientProdInfo, "APITest");
	strcpy(req.ClientMac, m_local_mac.c_str());
	strcpy(req.AppID, m_app_id.c_str());
	strcpy(req.AuthCode, m_auth_code.c_str());

	int ret =  m_tradeApi->ReqUserLogon(&req);
	if(NO_ERROR != ret)
	{
		printf("%sReqUserLogon Failed! ret:%d\n", TIME, ret);
	}

	return ret;
}


int CTrader::ReqQuerySymbolList()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n", TIME);
		return -1;
	}

	CShengliStockReqQuerySecurityCodeField req;
	memset(&req, 0, sizeof(CShengliStockReqQuerySecurityCodeField));
	req.UserID = m_userID;
	req.SecurityType = 0;
	
	int ret = m_tradeApi->ReqQuerySymbolList(&req, 0);
	if(NO_ERROR != ret)
	{
		printf("%sReqQuerySymbolList Failed! ret:%d\n", TIME, ret);
	}

	return ret;
}

int CTrader::ReqQueryOptionDetail()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n", TIME);
		return -1;
	}

	CShengliStockReqQueryOptionDetailField req;
	memset(&req, 0, sizeof(CShengliStockReqQueryOptionDetailField));
	req.UserID = m_userID;
	req.ExchID = m_exchangeID;

	int ret = m_tradeApi->ReqQueryOptionDetail(&req, 0);
	if(NO_ERROR != ret)
	{
		printf("%sReqQueryOptionDetail Failed! ret:%d\n", TIME, ret);
	}

	return ret;
}

int CTrader::GetMaxToken()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n", TIME);
		return -1;
	}

	unsigned int maxToken = 0;
	m_tradeApi->GetMaxToken(&maxToken);
	return maxToken ;
}

void CTrader::getSecurityType(CShengliStockEnterOrderField& order, string symbol)
{
	map<string, CShengliStockNormalSecurityCodeField>::const_iterator iterSc = m_security.find(symbol);
	if(iterSc != m_security.end())
	{
		order.SecurityType = iterSc->second.SecurityType;
		order.SecuritySubType = iterSc->second.SecuritySubtype;
		return;
	}

	map<string, CShengliStockOptionSecurityCodeField>::const_iterator iterOp = m_option.find(symbol.c_str());
	if(iterOp != m_option.end())
	{
		order.SecurityType = iterOp->second.SecurityType;
		order.SecuritySubType = iterOp->second.SecuritySubType;
		return;
	}

	printf("%sFind symbol Failed! Symbol:%s\n", TIME, symbol.c_str());
}

void CTrader::EnterOrder()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n",TIME);
		return ;
	}

	CShengliStockEnterOrderField orderField;
	memset(&orderField, 0, sizeof(CShengliStockEnterOrderField));
	orderField.UserID = m_userID;
	strcpy(orderField.ClientID, m_clinetId.c_str());
	strcpy(orderField.FundAccount, m_fundAccount.c_str());
	orderField.ExchID = m_exchangeID;
	
	memcpy(orderField.UserInfo, "1", sizeof(orderField.UserInfo));
	orderField.RecordID = 100001;

	while(m_orderAcceptCount <= m_orderCount)
	{
		for(size_t i = 0; i < m_order.size(); ++i)
		{
			strcpy(orderField.SecurityCode,  m_order[i].Symbol.c_str());
			orderField.SecurityType =  m_order[i].SecuType;
			orderField.SecuritySubType =  m_order[i].SecuSubType;
			orderField.OrderQty =  m_order[i].Qty;
			orderField.Price =  m_order[i].Price;
			orderField.Side =  m_order[i].Side;
			orderField.MinQty = 0;
			orderField.PriceType =  m_order[i].PriceType;
			orderField.MaxPriceLevels =  m_order[i].MaxPriceLevel;
			orderField.CashMarginFlag =  m_order[i].CashMarginFlag;
			orderField.ForceCoverFlag =  m_order[i].ForceCoverFlag;
			orderField.TIF =  m_order[i].Tif;
			orderField.ClOrdToken = GetMaxToken() + 1;
			int ret = m_tradeApi->EnterOrder(&orderField);
			if(NO_ERROR != ret)
			{
				printf("%sEnterOrder Failed! ret:%d\n", ret);
			}

			_sleep_(m_loopTime);
		}

	}
}


void CTrader::OnConnected(TShengliStockErrNoType errNo, const char* pErrStr)
{
	if (errNo != NO_ERROR)
	{
		printf("%sConnect Failed! ErrorNo:%d, %s!\n", TIME, errNo, pErrStr);
		m_logonStatus = -1;
		return;
	}

	ReqUserLogon();
}

void CTrader::OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr )
{
	m_logonStatus = -1;
	printf("%sDisconnected(%d), %s!\n", TIME, errNo,pErrStr);
}

void CTrader::OnRspUserLogon(CShengliStockRespUserLoginField* pLogon, int nRequestID)
{
	if (!pLogon)
	{
		m_logonStatus = -1;
		printf("%sRecv Logon Resp, But Null!\n", TIME);
		return;
	}

	if (pLogon->Result != SHENGLI_STOCK_LOGON_SUCCESS)
	{
		m_logonStatus = -1;
		printf("%sLogon Failed, %d\n", TIME, pLogon->Result);
		return;
	}

	m_userID = pLogon->UserID;
	m_logonStatus = 1;
	printf("%sLogon Ok  ProtoVersion:%d LogonID:%s UserID:%d TradingDate:%d MaxToken:%d DefClientID:%s\n", 
		TIME, pLogon->ProtoVersion, pLogon->LogonID, pLogon->UserID, pLogon->TradingDate, pLogon->MaxToken, pLogon->DefClientID);
}


void CTrader::OnRspQuerySymbol(CShengliStockNormalSecurityCodeField* pSymbolInfo, int nRequestID, bool bIsLast)
{
	if (pSymbolInfo && !bIsLast)
	{
		m_security[pSymbolInfo->SecurityCode] = *pSymbolInfo;
		return;
	}

	if (bIsLast)
	{
		printf("%sRecv All Query Symbol Resp, Symbol Count:%d\n", TIME, m_security.size());
		return;
	}
}

void CTrader::OnRspQueryOptionDetail(CShengliStockOptionSecurityCodeField* pOption, int nRequestID, bool bIsLast)
{
	if (pOption && !bIsLast)
	{
		m_option[pOption->SecurityCode] = *pOption;
		return;
	}

	if (bIsLast)
	{
		printf("%sRecv All Query Option Detail Resp, Option Count:%d\n", TIME, m_option.size());
		return;
	}
}

void CTrader::OnRtnOrderAccepted(CShengliStockOrderAcceptedField* pAccept)
{
	++m_orderAcceptCount;
	if(0 == m_orderAcceptCount % 100)
	{
		printf("%sOrder Accepted :%d\n", TIME, m_orderAcceptCount);
	}
}

void CTrader::OnRtnOrderRejected(CShengliStockOrderRejectedField* pReject)
{
	if (!pReject)
	{
		printf("%sRecv Order Rejected Resp, But Null!\n", TIME);
		return;
	}

	RejectReasonDesc  rej; 
	char RejectReason[1024];
	sprintf(RejectReason, "%s", rej.GetOrderRejectDesc(pReject->GrammarResult, pReject->RiskResult ).c_str());

	printf("%sOrder Rejected OrderToken:%d RejReson:%s\n", TIME, pReject->ClOrdToken, RejectReason);
}

void CTrader::OnRtnOrderExecuted(CShengliStockOrderExecedField* pExec)
{}