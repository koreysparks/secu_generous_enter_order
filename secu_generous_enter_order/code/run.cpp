#include "EESTrader.h"

#include "../../common_libs_pub/include/linux/shengli_xml/xml_inc.h"

Param			g_param;

using namespace SHENGLI::XML;
using namespace SHENGLI::TOOLS;


int loadParam(Param& param)
{
	string xml = "secu_generous_enter_order.xml";

	xml_document doc;
	if(!doc.load_file(xml.c_str()))
	{
		printf("%sLoad Xml File Failed!\n", TIME);
		return -1;
	}

	xml_element grp = doc.get_root().first_child_element("param");
	if(!grp.is_good())
	{
		printf("%sFind Xml Node Param Failed!\n", TIME);
		return -1;		
	}

	xml_element item = grp.first_child_element();
	if(!item.is_good())
	{
		printf("%sFirst Xml Node Is Not Good!\n", TIME);
		return -1;		
	}

	while(item.is_good())
	{
		string s_name = item.get_element_name();
		string s_value = item.get_attribute("value");

		if(s_name == "trade_ip")				param.m_traderServerIp = s_value;
		if(s_name == "trade_port")				param.m_traderServerPort = atoi(s_value.c_str());
		if(s_name == "query_ip")				param.m_queryServerIp = s_value;
		if(s_name == "query_port")				param.m_queryServerPort = atoi(s_value.c_str());
		if(s_name == "exchange_id")				param.m_exchangeID = atoi(s_value.c_str());
		if(s_name == "enter_order_loop_time")	param.m_loopTime = atoi(s_value.c_str());
		if(s_name == "order_count")				param.m_orderCount = atoi(s_value.c_str());



		if(s_name == "user_info")
		{
			param.m_logonId = item.get_attribute("logon_id");
			param.m_logonPwd = item.get_attribute("pwd");
			param.m_clinetId = item.get_attribute("client_id");
			param.m_fundAccount = item.get_attribute("fund_account");
			param.m_appID = item.get_attribute("app_id");
			param.m_authCode = item.get_attribute("auth_code");
		}

		if(string::npos != s_name.find("order_info"))
		{
			Order order;
			order.Symbol = item.get_attribute("symbol");
			order.Qty = atoi(item.get_attribute("qty").c_str());
			order.CashMarginFlag = atoi(item.get_attribute("cash_margin_flag").c_str());
			order.Price = atof(item.get_attribute("price").c_str());
			order.Side = atoi(item.get_attribute("side").c_str());
			order.PriceType = atoi(item.get_attribute("price_type").c_str());
			order.MaxPriceLevel = atoi(item.get_attribute("max_price_level").c_str());
			order.Tif = atoi(item.get_attribute("tif").c_str());
			order.ForceCoverFlag = atoi(item.get_attribute("force_cover_flag").c_str());
			order.SecuType = atoi(item.get_attribute("security_type").c_str());
			order.SecuSubType = atoi(item.get_attribute("security_sub_type").c_str());
			g_param.m_order.push_back(order);
		}

		item = item.next_element(); 
	}

	assert(param.m_exchangeID == 100 || param.m_exchangeID == 101);
	printf("%strade_server_ip:%s trade_server_port:%d query_server_ip:%s query_server_port:%d\n", 
		TIME, param.m_traderServerIp.c_str(), param.m_traderServerPort, param.m_queryServerIp.c_str(), param.m_queryServerPort);
	printf("%slogon_id:%s pwd:%s client_id:%s fund_acount:%s app_id:%s auth_code:%s\n",
		TIME, param.m_logonId.c_str(), param.m_logonPwd.c_str(), param.m_clinetId.c_str(), param.m_fundAccount.c_str(), 
		param.m_appID.c_str(), param.m_authCode.c_str());

	for(size_t i = 0; i < g_param.m_order.size(); ++i)
	{
		printf("%ssymbol:%s security_type:%d security_sub_type:%d qty:%d price:%f side:%d price_type:%d max_price_level:%d tif:%d cash_margin_flag:%d force_cover_flag:%d\n", 
			TIME, param.m_order[i].Symbol.c_str(), param.m_order[i].SecuType, param.m_order[i].SecuSubType, param.m_order[i].Qty,
			param.m_order[i].Price, param.m_order[i].Side, param.m_order[i].PriceType, param.m_order[i].MaxPriceLevel, param.m_order[i].Tif, 
			param.m_order[i].CashMarginFlag, param.m_order[i].ForceCoverFlag);
	}
	
	// ÅÐ¶Ï²ÎÊý
	if(param.m_traderServerIp.empty() || param.m_traderServerPort == 0 || param.m_queryServerIp.empty() || param.m_queryServerPort == 0)
	{
		printf("%sServer IP Or Port Empty!\n", TIME) ;
		return -1;		
	}

	if(param.m_logonId.empty() || param.m_logonPwd.empty() || param.m_clinetId.empty() || param.m_fundAccount.empty())
	{
		printf("%sLogon Or Pwd Or ClientID Or FundAccount Empty!\n", TIME);
		return -1;		
	}

	return 0;
}


int main()
{
	if(0 != loadParam(g_param))
	{
		return 0;
	}

	CTrader temp(g_param);

	temp.Run();
	return 0;
}









