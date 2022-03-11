#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string>
#include <unistd.h>
#include <assert.h>
#include <map>
#include <vector>

#include "ShengliTraderApi.h"
#include "logClass.hpp"

using namespace std;
using namespace Log;

#define				TIME	(CLog::getDateTimeString().c_str())
typedef				void*	T_DLL_HANDLE;

struct Order 
{
	Order();

	string		Symbol;
	int			SecuType;
	int			SecuSubType;
	int			Qty;
	int			CashMarginFlag;
	double		Price;
	int			Side;
	int			PriceType;
	int			MaxPriceLevel;
	int			Tif;
	int			ForceCoverFlag;
};

struct  Param 
{
	Param();

	string						m_traderServerIp;		///< 交易服务器IP地址
	int							m_traderServerPort;		///< 交易服务器端口

	string						m_queryServerIp;		///< 查询服务器地址
	int							m_queryServerPort ;		///< 查询服务器地址	
	int							m_exchangeID;

	string						m_logonId;				///< 登录交易服器编号
	string						m_logonPwd;				///< 登录交易服器密码

	string                      m_clinetId;             ///< 客户号
	string                      m_fundAccount;
	string						m_appID;
	string						m_authCode;

	int							m_loopTime;				///下单间隔
	int							m_orderCount;
	vector<Order>				m_order;
};

class CTrader : public CShengliStockTraderSpi
{
public:
	CTrader(const Param& p);
	virtual ~CTrader(void);

	/// \brief 测试入口函数
	void Run();

private:
	/// \brief 初始化
	bool Init();
	/// \brief 关闭
	void Close();

	/// \brief 延时函数
	void _sleep_(size_t t);
	/// \brief 暂停
	void Pause();

private:
	/// \brief 加载EES交易API的动态库
	bool LoadEESTrader();
	/// \brief 释放EES交易API的动态库
	void UnloadEESTrader();

	/// \brief Windows版加载交易API的动态库
	bool Windows_LoadEESTrader();
	/// \brief Windows版释放交易API的动态库
	void Windows_UnloadEESTrader();

	/// \brief Linux版本加载交易API的动态库
	bool Linux_LoadEESTrader();
	/// \brief Linux版本释放交易API的动态库
	void Linux_UnloadEESTrader();

	/// \brief 初始化参数调整方法
	void InputParam();

private:
	/// \brief 用户登录
	int ReqUserLogon();
	/// \brief 合约列表查询
	int ReqQuerySymbolList();
	/// \brief 期权细节查询
	int ReqQueryOptionDetail();
	/// \brief 客户号资金状态查询
	int ReqQueryClientBpStatus();
	/// \brief 获取订单最大token值
	int GetMaxToken();
	/// \brief 下单
	void EnterOrder();
	void getSecurityType(CShengliStockEnterOrderField& order, string symbol);


private:
	///	\brief	连接消息的回调
	virtual void OnConnected(TShengliStockErrNoType errNo, const char* pErrStr );
	///	\brief	连接断开消息的回调
	virtual void OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr );
	///	\brief	登录消息的回调
	virtual void OnRspUserLogon(CShengliStockRespUserLoginField* pLogon, int nRequestID);
	///	\brief	查询合约列表的返回事件
	virtual void OnRspQuerySymbol(CShengliStockNormalSecurityCodeField* pSymbolInfo, int nRequestID, bool bIsLast);
	///	\brief	查询期权细节的返回事件
	virtual void OnRspQueryOptionDetail(CShengliStockOptionSecurityCodeField* pOption, int nRequestID, bool bIsLast);
	///	\brief	订单接受的返回事件
	virtual void OnRtnOrderAccepted(CShengliStockOrderAcceptedField* pAccept);
	///	\brief	订单拒绝的返回事件
	virtual void OnRtnOrderRejected(CShengliStockOrderRejectedField* pReject);
	///	\brief	成交回报的返回事件
	virtual void OnRtnOrderExecuted(CShengliStockOrderExecedField* pExec);

private:
	CShengliStockTraderApi*		m_tradeApi;				///< EES交易API接口
	T_DLL_HANDLE				m_handle;				///< EES交易API句柄
	FuncDestroyShengliTraderApi	m_distoryFun;			///< EES交易API动态库销毁函数

	string						m_traderServerIp;		///< 交易服务器IP地址
	int							m_traderServerPort;		///< 交易服务器端口

	string						m_queryServerIp;		///< 查询服务器地址
	int							m_queryServerPort ;		///< 查询服务器地址	
	int							m_exchangeID;


	string						m_logonId;				///< 登录交易服器编号
	string						m_logonPwd;				///< 登录交易服器密码
	
	string                      m_clinetId;             ///< 客户号
	string                      m_fundAccount;
	string						m_local_mac;			///< 本机MAC地址

	string						m_app_id; 
	string						m_auth_code;

	int                         m_userID;               ///< 用户ID
	int							m_logonStatus;
	int							m_loopTime;				///< 下单间隔

	// 下单相关
	vector<Order>				m_order;

	map<string, CShengliStockNormalSecurityCodeField>	m_security;
	map<string, CShengliStockOptionSecurityCodeField>	m_option;
	unsigned long long int								m_orderAcceptCount;
	unsigned long long int								m_orderCount;

};

