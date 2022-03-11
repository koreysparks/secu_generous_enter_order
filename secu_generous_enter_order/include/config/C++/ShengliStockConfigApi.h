/*!
* \file  ShengliStockConfigApi.h
* \brief 配置API结构体
*
* 此文件描述了使用CNF API所需的类型和函数
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#pragma  once 
#include "ShengliStockUserConfigApiStruct.h"

#ifdef WIN32
#ifdef  SL_CONFIG_EXPORTS
#define SL_CONFIG_CLASS		__declspec(dllexport)	  
#define SL_CONFIG_FUN		extern "C" __declspec(dllexport)
#else
#define SL_CONFIG_CLASS		__declspec(dllimport)	  
#define SL_CONFIG_FUN		extern "C" __declspec(dllimport)
#endif

#ifdef _DEBUG

#define SHENGLI_CONFIG_DLL_NAME    "RemStockConfigApiD.dll"
#define SHENGLI_CONFIG_LIB_NAME    "RemStockConfigApiD.lib"

#else

#define SHENGLI_CONFIG_DLL_NAME    "RemStockConfigApi.dll"
#define SHENGLI_CONFIG_LIB_NAME    "RemStockConfigApi.lib"

#endif

#include <windows.h>
#else	
#define SL_CONFIG_CLASS 
#define SL_CONFIG_FUN				extern "C" 

#define SHENGLI_CONFIG_DLL_NAME		"libRemStockConfigApi.so"

#ifndef NULL
#define NULL 0
#endif
#endif

/// \brief ShengliCNF客户端回调基类
class CShengliStockConfigSpi
{
public:
	virtual ~CShengliStockConfigSpi() {}

	/// \brief 连接消息的回调
	virtual void OnConnected(TShengliStockErrNoType errNo, const char* pErrStr) {}

	/// \brief 连接断开消息的回调
	virtual void OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr) {}

	/// \brief 登录消息的回调
	virtual void OnRspUserLogon(CShengliStockConfigRespUserLoginField* pLogon, int nRequestID) {}

	/// \brief 设置主席资金账户的密码的回调
	virtual void OnRspSetAcctPwd(CShengliStockConfigRespSetAcctPwdField* RespInfo, int nRequestID) {}

	/// \brief 验证主席里面资金账户已经配置好的密码的回调
	virtual void OnRspCheckAcctPwd(CShengliStockConfigRespCheckAcctPwdField* RespInfo, int nRequestID) {}

	/// \brief 查询客户列表的回调
	virtual void OnRspQryCust(CShengliStockConfigRespQryCustField* RespInfo, int nRequestID) {}

	/// \brief 查询资金账户列表的回调
	virtual void OnRspQryFundAcct(CShengliStockConfigRespQryFundAcctField* RespInfo, int nRequestID) {}

	/// \brief 查询交易账户的回调
	virtual void OnRspQueryTradeAcct(CShengliStockConfigRespQueryTradeAcctField* RespInfo, int nRequestID) {}

	/// \brief 查询交易账户的交易节点的回调
	virtual void OnRspQueryTradeNode(CShengliStockConfigRespQueryTradeNodeField* RespInfo, int nRequestID) {}

	/// \brief 设置交易账户的资金分配比例的回调
	virtual void OnRspSetBpRatio(CShengliStockConfigRespSetBpRatioField* RespInfo, int nRequestID) {}

	/// \brief 查询交易账户的资金分配比例的回调
	virtual void OnRspQueryBpRatio(CShengliStockConfigRespQueryBpRatioField* RespInfo, int nRequestID) {}
};

class SL_CONFIG_CLASS CShengliStockConfigApi
{
public:

	virtual ~CShengliStockConfigApi() { }

	/// \brief 注册回调接口
	virtual void RegisterSpi(CShengliStockConfigSpi *pSpi) = 0;

	/// \brief 连接服务器
	virtual int ConnConfigServer(const char* svrAddr, int nPort) = 0;

	/// \brief 断开服务器
	virtual int DisConnConfig() = 0;

	/// \brief 用户登录
	virtual int ReqUserLogon(CShengliStockConfigReqUserLoginField* pLogin) = 0;

	/// \brief 请求设置主席资金账户的密码
	virtual int ReqSetAccountPwd(CShengliStockConfigReqSetAcctPwdField* req) = 0;

	/// \brief 请求验证主席里面资金账户已经配置好的密码
	virtual int ReqCheckAcctPwd(CShengliStockConfigReqCheckAcctPwdField* req) = 0;

	/// \brief 请求客户列表查询
	virtual int ReqQueryCust(CShengliStockConfigReqQryCustField* req) = 0;

	/// \brief 请求资金客户列表查询
	virtual int ReqQueryFundAccount(CShengliStockConfigReqQryFundAcctField* req) = 0;

	/// \brief 请求查询交易账户
	virtual int ReqQueryTradeAccount(CShengliStockConfigReqQueryTradeAcctField* req) = 0;

	/// \brief 请求查询交易账户节点
	virtual int ReqQueryTradeNode(CShengliStockConfigReqQueryTradeNodeField* req) = 0;

	/// \brief 请求设置资金账户的资金分配比例
	virtual int ReqSetBpRatio(CShengliStockConfigReqSetBpRatioField* req) = 0;

	/// \brief 请求查询资金账户的资金分配比例
	virtual int ReqQueryBpRatio(CShengliStockConfigReqQueryBpRatioField* req) = 0;
};

/// \brief 创建Shengli交易客户端实例的函数名
#define CREATE_SHENGLI_CONFIG_API_NAME ("CreateShengliConfigApi")

/// \brief 销毁Shengli交易客户端实例的函数名
#define DESTROY_SHENGLI_CONFIG_API_NAME ("DestroyShengliConfigApi")

/// \brief 创建Shengli交易客户端实例函数声明
SL_CONFIG_FUN CShengliStockConfigApi* CreateShengliConfigApi(const char* logDir);

/// \brief 销毁Shengli交易客户端实例函数声明
SL_CONFIG_FUN void DestroyShengliConfigApi(CShengliStockConfigApi* pShengliConfigApi);

/// \brief 创建Shengli交易客户端实例函数指针类型
typedef CShengliStockConfigApi* (*FuncCreateShengliConfigApi)(const char* logDir);

/// \brief 销毁Shengli交易客户端实例函数指针类型
typedef void(*FuncDestroyShengliConfigApi)(CShengliStockConfigApi* pShengliConfigApi);
