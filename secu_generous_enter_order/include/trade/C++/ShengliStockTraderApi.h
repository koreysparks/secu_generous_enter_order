/*!
* \file  ShengliStockTraderApi.h
* \brief 交易和查询客户端公共的头文件
*
* 此文件描述了使用交易客户端所需类型和函数的定义
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#pragma  once 
#include "ShengliStockUserTraderApiStruct.h"
#include <time.h>

#ifdef WIN32
	#ifdef  SL_TRADE_EXPORTS
		#define SL_TRADE_CLASS		__declspec(dllexport)	  
		#define SL_TRADE_FUN		extern "C" __declspec(dllexport)
	#else
		#define SL_TRADE_CLASS		__declspec(dllimport)	  
		#define SL_TRADE_FUN		extern "C" __declspec(dllimport)
	#endif

#ifdef _DEBUG

	#define SHENGLI_TRADER_DLL_NAME    "RemStockTradeApiD.1.8.dll"
	#define SHENGLI_TRADER_LIB_NAME    "RemStockTradeApiD.1.8.lib"

#else

#define SHENGLI_TRADER_DLL_NAME    "RemStockTradeApi.1.8.dll"
#define SHENGLI_TRADER_LIB_NAME    "RemStockTradeApi.1.8.lib"

#endif

	#include <windows.h>
#else	
	#define SL_TRADE_CLASS 
	#define SL_TRADE_FUN				extern "C" 

	#define SHENGLI_TRADER_DLL_NAME    "libRemStockTradeApi.so"

	#ifndef NULL
		#define NULL 0
	#endif
#endif

/// \brief Shengli交易客户端回调基类
class  CShengliStockTraderSpi
{
public:	
	virtual ~CShengliStockTraderSpi() {}

	///连接消息的回调
	virtual void OnConnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	///连接断开消息的回调
	virtual void OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	/// 查询连接断开消息的回调
	virtual void OnQueryDisconnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	///登录消息的回调
	virtual void OnRspUserLogon(CShengliStockRespUserLoginField* pLogon, int nRequestID){}

	///修改密码响应回调
	virtual void OnRspChangePassword(CShengliStockRespChangePwdField* pChangePwd, int nRequestID){}

	///查询客户号列表的返回事件
	virtual void OnRspQueryClientId(CShengliStockClientIDListField* pClientInfo, int nRequestID, bool bIsLast){}

	///查询资金账户列表的返回事件
	virtual void OnRspQueryAccount(CShengliStockAccountListField* pAccountInfo, int nRequestID, bool bIsLast){}

	///查询合约列表的返回事件
	virtual void OnRspQuerySymbol(CShengliStockNormalSecurityCodeField* pSymbolInfo, int nRequestID, bool bIsLast){}

	///查询ETF成份股查询的返回事件
	virtual void OnRspQueryETFMember(CShengliStockEtfMemberField* pEtfMember, int nRequestID, bool bIsLast){}

	///查询期权细节的返回事件
	virtual void OnRspQueryOptionDetail(CShengliStockOptionSecurityCodeField* pOption, int nRequestID, bool bIsLast){}

	///查询帐户交易费用的返回事件 
	virtual void OnRspQueryAccountTradeFee(CShengliStockAccountTradeFeeField* pFee, int nRequestID, bool bIsLast){}

	///查询仓位列表的股票仓位返回事件
	virtual void OnRspQueryNormalPosition(CShengliStockNormalPositionField* pPos, int nRequestID, bool bIsLast){}

	///查询仓位列表的期权仓位返回事件
	virtual void OnRspQueryOptionPosition(CShengliStockOptionPositionField* pPos, int nRequestID, bool bIsLast){}

	///查询仓位列表的期权组合策略仓位返回事件
	virtual void OnRspQueryOptionCombStrategyPosition(CShengliStockOptionCombStrategyPositionField* pPos, int nRequestID, bool bIsLast){}

	///订单rewind的返回事件
	virtual void OnRtnOrderRewind(CShengliStockOrderAcceptedField* pOrder, int nRequestID){}

	///成交rewind的返回事件
	virtual void OnRtnExecRewind(CShengliStockOrderExecedField* pExec, int nRequestID){}

	///撤单请求rewind响应
	virtual void OnRtnCxlReqRewind(CShengliStockOrderCxledField* pCxlReq, int nRequestID){}

	///客户号订单rewind完成的返回事件
	virtual void OnRtnOrderRewindFinish(CShengliStockOrderRewindFinishField* pOrderFinish, int nRequestID){}

	///成交rewind完成的返回事件
	virtual void OnRtnExecRewindFinish(CShengliStockExecRewindFinishField* pExecFinish, int nRequestID){}

	///撤销请求rewind完成的返回事件
	virtual void OnRtnCxlReqRewindFinish(CShengliStockCxlReqRewindFinishField* pCxlReqFinish, int nRequestID){}

	///客户号资金状态查询的返回事件
	virtual void OnRspQueryClientBpStatus(CShengliStockBpStatusField* pBpInfo, int nRequestID, bool bIsLast){}

	///交易所连接查询的返回事件
	virtual void OnRspQueryMarketSession(CShengliStockExchangeConnectField* pSession, int nRequestID, bool bIsLast){}

	///交易所状态变化通知事件
	virtual void OnRtnMarketStatusChangeReport(CShengliStockExchangeStatusReportField* pReport){}

	///订单接受的返回事件
	virtual void OnRtnOrderAccepted(CShengliStockOrderAcceptedField* pAccept){}

	///订单拒绝的返回事件
	virtual void OnRtnOrderRejected(CShengliStockOrderRejectedField* pReject){}

	///成交回报的返回事件
	virtual void OnRtnOrderExecuted(CShengliStockOrderExecedField* pExec){}

	///撤单成功的返回事件
	virtual void OnRtnOrderCxled(CShengliStockOrderCxledField* pCxled){}

	///撤单拒绝的返回事件
	virtual void OnRtnOrderCxlRejected(CShengliStockOrderCxlRejectedField* pCxlRejected){}

	///ETF申购赎回成交的返回事件
	virtual void OnRtnETFExecuted(CShengliStockEtfExecHeadField* pHead, CShengliStockEtfExecBodyField* pBody, bool bIsLast){}
	
	///心跳的回复
	virtual void OnRtnHeartbeat( ){}

	///查询可锁券数量返回事件
	virtual void OnRspQueryUnderlyingSymbolQty(CShengliStockUnderlyingSymbolQtyField* pUnderlyingSymbolQty, int nRequestID){}

	///主席请求锁定、解锁标的券返回事件
	virtual void OnRspFrozenUnderlyingSymbolQty(CShengliStockFrzUnderlyingSymbolQtyField* pFrzUnderlyingSymbolQty, int nRequestID){}

	///同主席资金划拔返回事件
	virtual void OnRtnInOutFundAccountMargin(CShengliStockInOutFundAccountAmountField* pInOutFundAccountAmount, int nRequestID){}	

	///向交易节点资金划转回调
	virtual void OnOutFundAccountAmountNode(CShengliStockTrasnBpField* pFields, int nRequestID) {}

	///查询向交易节点资金划转回调
	virtual void OnQueryOutFundAccountAmountNode(CShengliStockTrasnQueryBpDetailField* pFields, int nRequestID, bool bIsLast) {}

	///系统上报信息回调
	virtual void OnRecvSystemReportMsg(CShengliSystemMsgReportField* p_Field) {} 

	///OPSTATION上报信息回调
	virtual void OnRecvOpStationReportMsg(CShengliOpStationReportResp* p_Field) {}

	///回复查询交易账户列表回调
	virtual void OnRspQueryTradeAccountList(CShengliTradeAccountListField* pTradeAccount, int nRequestID, bool bIsLast) {}

	///查询风控门限值返回事件
	virtual void OnRspQueryRiskRuleThresholds(CShengliStockReqQueryRiskThresholdValueRespField* pResp, int nRequestID, bool bIsLast) {}

	///查询风控实时累加值返回事件
	virtual void OnRspQueryRiskRuleAccumulate(CShengliStockReqQueryRiskValueRespField* pResp, int nRequestID, bool bIsLast) {}

	///回复查询出入金列表回调
	virtual void OnRspQueryCashInOutList(CShengliStockRespCashInOutField* p_Field, int nRequestID, bool bIsLast) {}

	///推送出入金回调
	virtual void OnRspPushCashInOut(CShengliStockRespCashInOutField* p_Field) {}

	/// 中继提交采集信息返回消息回调
	virtual void OnRspProxySubmitInfo(CShengliStockRspInfoField *pRspInfo, int nRequestId) {};

	/// 订阅交易所订单单号回复
	virtual void OnRspSubscribeInfo(CShengliStockRespSubscribeField *p_Field, int nRequestID) {};

	/// 推送交易所订单单号消息
	virtual void OnRspPushMktCltOrdIDMsg(CShengliStockRespMktCltOrdIDField * p_Field) {};

	/// 推送通用信息
	virtual void OnRspCommonMsg(CShengliStockCommonMsgField* p_Field) {};
};

class SL_TRADE_CLASS CShengliStockTraderApi
{
public:
	
	virtual ~CShengliStockTraderApi(){ }

	///注册回调接口
	virtual void RegisterSpi(CShengliStockTraderSpi *pSpi) = 0;

	///初始化
	virtual void Init() = 0;

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszTradeAddress,char *pscQueryAddress) = 0;
	virtual void RegisterFront(const char* TradeIP, unsigned short TradePort, const char* QueryIP, unsigned short QueryPort) = 0;

	///初始化socket线程模型，需要再Init之前调用。
	virtual void InitSocketThreadMode(CShengliStockConnConfigField* pConfig) = 0;

	///断开服务器
	virtual int DisConnServer() = 0;

	///用户登录
	virtual int ReqUserLogon(CShengliStockReqUserLoginField* pLogin) = 0;

	///发送心跳消息
	virtual int ReqHeartbeat() = 0;

	///用户密码修改
	virtual int ReqChangePassword(CShengliStockReqChangePwdField* pPassword) = 0;

	///客户号列表查询
	virtual int ReqQueryClientIdList(CShengliStockReqQueryClientIDListField* pClient, int nRequestID) = 0;

	///资金账号列表查询
	virtual int ReqQueryAccountList(CShengliStockReqQueryAccountListField* pAccount, int nRequestID) = 0;

	///证券列表查询
	virtual int ReqQuerySymbolList(CShengliStockReqQuerySecurityCodeField* pSymbol, int nRequestID) = 0;

	///ETF成份股查询
	virtual int ReqQueryETFMember(CShengliStockReqQueryEtfMemberField* pEtf, int nRequestID) = 0;

	///期权细节查询
	virtual int ReqQueryOptionDetail(CShengliStockReqQueryOptionDetailField* pOption, int nRequestID) = 0;

	///股票仓位查询
	virtual int ReqQueryNormalPosition(CShengliStockReqQueryPositionField* pPosition, int nRequestID) = 0;

	///期权仓位查询
	virtual int ReqQueryOptionPosition(CShengliStockReqQueryPositionField* pPosition, int nRequestID) = 0;

	///交易信息rewind请求
	virtual int ReqRewindTradingInfo(CShengliStockReqTradeInfoRewindField* pRewind, int nRequestID) = 0;

	///客户号资金状态查询
	virtual int ReqQueryClientBpStatus(CShengliStockReqQueryBpStatusField* pBp, int nRequestID) = 0;

	///获取订单最大token值
	virtual int GetMaxToken(TShengliStockClientOrderTokenType* orderToken ) = 0;

	///下单
	virtual int EnterOrder(CShengliStockEnterOrderField* pOrder) = 0;

	///下组合单
	virtual int EnterCombOrder(CShengliStockEnterOrderField* pOrder, CShengliStockExternCombOrder* pExternCombOrder, CShengliStockCombLegField* pCombLeg) = 0;

	///下组合行权
	virtual int EnterCombExercise(CShengliStockEnterOrderField* pOrder, int Nolegs, CShengliStockCombLegField* pCombLeg) = 0 ;

	///撤单
	virtual int CancelOrder(CShengliStockCxlOrderField* pOrder) = 0;

	///向主席查询标的券数
	virtual int ReqQueryUnderlyingSymbolQty(CShengliStockReqUnderlyingSymbolQtyField* pReq, int nRequestID) = 0;

	///请求主席锁定/解锁标的券数量
	virtual int ReqFrzUnderlyingSymbolQty(CShengliStockFrzUnderlyingSymbolQtyReqField* pReq, int nRequestID) = 0;

	///请求同主席划入划出资金
	virtual int ReqInOutFundAccountAmount(CShengliStockInOutFundAccountAmountReqField* pReq, int nRequestID) = 0;

	///时间戳转换函数，用于将API中所有的TShengliStockTimeStampType类型，转换成C语言标准的struct tm结构体，以及这个时间在一秒内的纳秒数
	virtual void ConvertFromTimestamp( TShengliStockTimeStampType timeStamp, tm& tmResult, unsigned int& nanoSsec ) = 0;

	///请求从交易所划出资金到另外一个交易所
	virtual int ReqOutFundAccountAmountNode(CShengliStockTrasnBpReqField* pReq, int nRequestID) = 0;

	///查询账户内部，交易所划转记录
	virtual int ReqQueryOutFundAccountAmountNodeDetail(CShengliStockTrasnBpQueryField* pReq, int nRequestID) = 0;

	///OpStation上报
	virtual void ReqOpStationReport( CShengliOpStationReportReq*pReq ) = 0;

	///请求查询交易账户列表
	virtual int ReqQueryTradeAccountList(CShengliStockReqQueryTradeAccountListField* pAccount, int nRequestID) = 0;

	///请求查询风控门限值
	virtual int ReqQueryRiskRuleThresholds(CShengliStockReqQueryRiskThresholdValueField* pReq, int nRequestID) = 0;

	///请求查询风控实时累加值
	virtual int ReqQueryRiskRuleAccumulateVal(CShengliStockReqQueryHeaderField* pReq, CShengliStockReqQueryRiskValueField* pReqVal, int nRequestID) = 0;


	///出入金查询
	virtual int ReqQueryCashInOutList(CShengliStockQueryCashInOutField* pReq, int nRequestId) = 0;
	
	/// 中继用户登录 
	virtual int ReqUserProxyLogon(CShengliStockReqUserLoginField* pLogin) = 0;
	
	///  中继提交客户采集信息
	virtual int ReqProxySubmitInfo(CShengliStockProxySubmitDataField *pDSProxySubmitData, int nRequestId) = 0;

	/// 订阅交易所订单单号消息
	virtual int ReqSubscribe(CShengliStockSubscribeField *pReq, int nRequestID) = 0;

	/// 获取API版本号
	virtual const char* GetVersion() = 0; 
};

/// 创建Shengli交易客户端实例的函数名
#define CREATE_SHENGLI_TRADER_API_NAME ("CreateShengliTraderApi")

/// 销毁Shengli交易客户端实例的函数名
#define DESTROY_SHENGLITRADER_API_NAME ("DestroyShengliTraderApi")

/// 创建Shengli交易客户端实例函数声明
SL_TRADE_FUN CShengliStockTraderApi* CreateShengliTraderApi(const char* logDir); 

/// 销毁Shengli交易客户端实例函数声明
SL_TRADE_FUN void DestroyShengliTraderApi(CShengliStockTraderApi* pShengliTraderApi) ; 

/// 创建Shengli交易客户端实例函数指针类型
typedef CShengliStockTraderApi* (*FuncCreateShengliTraderApi)(const char* logDir) ;

/// 销毁Shengli交易客户端实例函数指针类型
typedef void (*FuncDestroyShengliTraderApi)(CShengliStockTraderApi* pShengliTraderApi) ;