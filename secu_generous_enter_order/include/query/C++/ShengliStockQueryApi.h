/*!
* \file  ShengliStockQueryApi.h
* \brief 查询客户端公共的头文件
*
* 此文件描述了查询客户端所需的的类型和函数
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#pragma  once 
#include "ShengliStockUserQueryApiStruct.h"

#ifdef WIN32
	#ifdef  SL_QUERY_EXPORTS
		#define SL_QUERY_CLASS		__declspec(dllexport)	  
		#define SL_QUERY_FUN		extern "C" __declspec(dllexport)
	#else
		#define SL_QUERY_CLASS		__declspec(dllimport)	  
		#define SL_QUERY_FUN		extern "C" __declspec(dllimport)
	#endif

#ifdef _DEBUG

	#define SHENGLI_QUERY_DLL_NAME    "RemStockQueryApiD.dll"
	#define SHENGLI_QUERY_LIB_NAME    "RemStockQueryApiD.lib"

#else

#define SHENGLI_QUERY_DLL_NAME    "RemStockQueryApi.dll"
#define SHENGLI_QUERY_LIB_NAME    "RemStockQueryApi.lib"

#endif

	#include <windows.h>
#else	
	#define SL_QUERY_CLASS 
	#define SL_QUERY_FUN				extern "C" 

	#define SHENGLI_QUERY_DLL_NAME		"libRemStockQueryApi.so"

	#ifndef NULL
		#define NULL 0
	#endif
#endif

/// \brief Shengli查询客户端回调基类
class  CShengliStockQuerySpi
{
public:	
	virtual ~CShengliStockQuerySpi() {}

	///连接消息的回调
	virtual void OnConnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	///连接断开消息的回调
	virtual void OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	///登录消息的回调
	virtual void OnRspUserLogon(CShengliStockRespQryUserLoginField* pLogon, int nRequestID){}

	///心跳的回复
	virtual void OnRtnHeartbeat() {}

	///查询客户号列表的返回事件
	virtual void OnRspQueryClientId(CShengliStockClientIDListField* pClientInfo, int nRequestID, bool bIsLast){}

	///查询资金账户列表的返回事件
	virtual void OnRspQueryAccount(CShengliStockAccountListField* pAccountInfo, int nRequestID, bool bIsLast){}

	///查询合约列表的返回事件
	virtual void OnRspQuerySymbol(CShengliStockNormalSecurityCodeField* pSymbolInfo, int nRequestID, bool bIsLast){}

	///查询期权细节的返回事件
	virtual void OnRspQueryOptionDetail(CShengliStockOptionSecurityCodeField* pOption, int nRequestID, bool bIsLast){}

	///客户号资金状态查询的返回事件
	virtual void OnRspQueryClientBpStatus(CShengliStockBpStatusField* pBpInfo, int nRequestID, bool bIsLast) {}

	/// 查询仓位列表的股票仓位返回事件
	virtual void OnRspQueryNormalPosition(CShengliStockNormalPositionField* pPos, int nRequestID, bool bIsLast){}

	/// 查询仓位列表的期权仓位返回事件
	virtual void OnRspQueryOptionPosition(CShengliStockOptionPositionField* pPos, int nRequestID, bool bIsLast){}

	/// 委托查询响应
	virtual void OnRspQueryEntrust(CShengliStockEntrustField* pOrder, int nRequestID, bool bIsLast) {}

	/// 成交查询响应
	virtual void OnRspQueryExec(CShengliStockExecField* pOrder, int nRequestID, bool bIsLast) {}

	///订单rewind的返回事件
	virtual void OnRtnOrderRewind(CShengliStockOrderAcceptedField* pOrder, int nRequestID) {}

	///成交rewind的返回事件
	virtual void OnRtnExecRewind(CShengliStockOrderExecedField* pExec, int nRequestID) {}

	///撤单请求rewind响应
	virtual void OnRtnCxlReqRewind(CShengliStockOrderCxledField* pCxlReq, int nRequestID) {}

	///客户号订单rewind完成的返回事件
	virtual void OnRtnOrderRewindFinish(CShengliStockOrderRewindFinishField* pOrderFinish, int nRequestID) {}

	///成交rewind完成的返回事件
	virtual void OnRtnExecRewindFinish(CShengliStockExecRewindFinishField* pExecFinish, int nRequestID) {}

	///撤销请求rewind完成的返回事件
	virtual void OnRtnCxlReqRewindFinish(CShengliStockCxlReqRewindFinishField* pCxlReqFinish, int nRequestID) {}

	///查询股东账号列表的返回事件
	virtual void OnRspQueryTradeAccountList(CShengliTradeAccountListField* pTradeAccount, int nRequestID, bool bIsLast) {}
};

class SL_QUERY_CLASS CShengliStockQueryApi
{
public:
	
	virtual ~CShengliStockQueryApi(){ }

	///注册回调接口
	virtual void RegisterSpi(CShengliStockQuerySpi *pSpi) = 0;

	///初始化
	virtual void Init() = 0;

	///注册前置机网络地址
	///@param pscQueryAddress ///前置机网络地址
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pscQueryAddress) = 0;

	///断开服务器
	virtual int DisConnServer() = 0;

	///用户登录
	virtual int ReqUserLogon(CShengliStockReqUserLoginField* pLogin) = 0;

	/// 发送心跳消息
	virtual int ReqHeartbeat() = 0;

	///客户号列表查询
	virtual int ReqQueryClientIdList(CShengliStockReqQueryClientIDListField* pClient, int nRequestID) = 0;

	///资金账号列表查询
	virtual int ReqQueryAccountList(CShengliStockReqQueryAccountListField* pAccount, int nRequestID) = 0;

	///股东账号列表查询
	virtual int ReqQueryTradeAccountList(CShengliStockReqQueryTradeAccountListField* pAccount, int nRequestID) = 0;

	///证券列表查询
	virtual int ReqQuerySymbolList(CShengliStockReqQuerySecurityCodeField* pSymbol, int nRequestID) = 0;

	///期权细节查询
	virtual int ReqQueryOptionDetail(CShengliStockReqQueryOptionDetailField* pOption, int nRequestID) = 0;

	///客户号资金状态查询
	virtual int ReqQueryClientBpStatus(CShengliStockReqQueryBpStatusField* pBp, int nRequestID) = 0;

	///股票仓位查询
	virtual int ReqQueryNormalPosition(CShengliStockReqQueryPositionField* pPosition, int nRequestID) = 0;

	///期权仓位查询
	virtual int ReqQueryOptionPosition(CShengliStockReqQueryPositionField* pPosition, int nRequestID) = 0;

	///委托查询
	virtual int ReqEntrustInfo(CShengliStockReqEntrustField* pEntrustReq, int nRequestID) = 0;

	///成交查询
	virtual int ReqExecInfo(CShengliStockReqExecField* pExecReq, int nRequestID) = 0;

	///交易信息rewind请求
	virtual int ReqRewindTradingInfo(CShengliStockReqTradeInfoRewindField* pRewind)= 0;


};

/// 创建Shengli交易客户端实例的函数名
#define CREATE_SHENGLI_QUERY_API_NAME ("CreateShengliQueryApi")

/// 销毁Shengli交易客户端实例的函数名
#define DESTROY_SHENGLI_QUERY_API_NAME ("DestroyShengliQueryApi")

/// 创建Shengli交易客户端实例函数声明
SL_QUERY_FUN CShengliStockQueryApi* CreateShengliQueryApi(const char* logDir); 

/// 销毁Shengli交易客户端实例函数声明
SL_QUERY_FUN void DestroyShengliQueryApi(CShengliStockQueryApi* pShengliQueryApi);

/// 创建Shengli交易客户端实例函数指针类型
typedef CShengliStockQueryApi* (*FuncCreateShengliQueryApi)(const char* logDir);

/// 销毁Shengli交易客户端实例函数指针类型
typedef void (*FuncDestroyShengliQueryApi)(CShengliStockQueryApi* pShengliQueryApi);
