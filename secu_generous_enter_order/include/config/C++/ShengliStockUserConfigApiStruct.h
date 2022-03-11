/*!
* \file  ShengliStockUserConfigApiStruct.h
* \brief 配置API结构体
*
* 此文件描述了CNF API所需的结构体定义
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#ifndef SECURITY_STOCKQUERYSTRUCT_H
#define SECURITY_STOCKQUERYSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif 

#include "../../config/C++/ShengliStockUserConfigApiDataType.h"

#pragma pack(push, 1)

/// \brief 登录成功
#define SHENGLI_STOCK_CONFIG_LOGON_SUCCESS			0	

/// \brief CNF登录请求
struct CShengliStockConfigReqUserLoginField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 登录名
	TShengliStockLogonIDType        LogonID;
	/// 明文密码
	TShengliStockLogonPwdType		Password;
	/// 客户端MAC地址
	TShengliStockClientMacType		ClientMac;
	/// 客户端IPV4
	TShengliStockConfigIPV4Type     ClientIPV4;
	/// 客户端IPV6
	TShengliStockConfigIPV6Type		ClientIPV6;
};

/// \brief CNF登录响应
struct CShengliStockConfigRespUserLoginField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 登录返回码（成功登录返回0）
	TShengliStockConfigResult		Result;
	/// 返回信息
	TShengliStockConfigRspMsg		Msg;
};

/// \brief 请求设置主席资金账户的密码
struct CShengliStockConfigReqSetAcctPwdField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
    TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType		FundAccount;
	/// 明文密码
	TShengliStockLogonPwdType		Password;
};

/// \brief 设置主席资金账户的密码 响应
struct CShengliStockConfigRespSetAcctPwdField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 设置返回码（设置成功返回0）
	TShengliStockConfigResult		Result;
	/// 返回信息
	TShengliStockConfigRspMsg		Msg;
};

/// \brief 请求验证主席里面资金账户已经配置好的密码
struct CShengliStockConfigReqCheckAcctPwdField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
    TShengliStockClientIdType       CustID;
	/// 返回信息
	TShengliStockAccountType		FundAccount;
};

/// \brief 验证主席里面资金账户已经配置好的密码 响应
struct CShengliStockConfigRespCheckAcctPwdField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 验证返回码
	TShengliStockConfigResult		Result;
	/// 返回信息
	TShengliStockConfigRspMsg		Msg;
};

/// \brief 查询客户列表 请求
struct CShengliStockConfigReqQryCustField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
};

/// \brief 查询客户列表 响应
struct CShengliStockConfigRespQryCustField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 消息结束标识
	TShengliStockFlag				LastFlag;
	/// 客户号
	TShengliStockClientIdType       CustID;
	/// 客户名称
	TShengliStockClientNameType		CustName;
	///  营业部
	TShengliStockBranchIdType		BranchID;
	/// 客户类型
	TShengliStockCustType			CustType;
	/// 客户状态
	TShengliStockCustState			CustState;
};

/// \brief 查询资金账户列表
struct CShengliStockConfigReqQryFundAcctField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
    TShengliStockClientIdType       CustID;
};

/// \brief 查询资金账户列表 响应
struct CShengliStockConfigRespQryFundAcctField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 消息结束标识
	TShengliStockFlag				LastFlag;
	/// 资金账号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 资金账号名称
	TShengliStockAccountNameType	FundName;
	/// 资金账号类型
	TShengliStockAccType			AccType;
	/// 资金账户状态
	TShengliStockAccState			AccState;
};

/// \brief 查询交易账户
struct CShengliStockConfigReqQueryTradeAcctField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID;
};

/// \brief 查询交易账户 响应
struct CShengliStockConfigRespQueryTradeAcctField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	///  消息结束标识
	TShengliStockFlag				LastFlag;
	/// 资金账号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 资金账号类型
	TShengliStockAccType			AccType;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID;
	/// 席位
	TShengliStockPBUType			Pub;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc;
};

/// \brief 查询交易账户的交易节点
struct CShengliStockConfigReqQueryTradeNodeField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc;
};

/// \brief 查询交易账户的交易节点 响应
struct CShengliStockConfigRespQueryTradeNodeField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 消息结束标识
	TShengliStockFlag				LastFlag;
	/// 客户号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 资金账号类型
	TShengliStockAccType			AccType;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc;
	/// 交易节点ID
	TShengliTradeNodeIDType			TradeNodeID;
	/// OTID
	TShengliOTIDType				OtID;
	/// 交易IP
	TShengliIPType					TradeIP;
	/// 交易端口
	TShengliPortType				TradePort;
	/// 查询IP
	TShengliIPType					QueryIP;
	/// 查询端口
	TShengliPortType				QueryPort;
	/// 备份OTID
	TShengliOTIDType				BackOtID;
	/// 备份交易IP
	TShengliIPType					BackTradeIP;
	/// 备份交易端口
	TShengliPortType				BackTradePort;
	/// 备份查询IP
	TShengliIPType					BackQueryIP;
	/// 备份查询端口
	TShengliPortType				BackQueryPort;
};

/// \brief 设置交易账户的资金分配比例
struct CShengliStockConfigReqSetBpRatioField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
	TShengliStockClientIdType       CustID_1;
	/// 资金账号
	TShengliStockAccountType        FundAccount_1;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID_1;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc_1;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc_1;
	/// 资金比例
	TShengliStockBpRatioType		BpRatio_1;

	/// 客户号
	TShengliStockClientIdType       CustID_2;
	/// 资金账号
	TShengliStockAccountType        FundAccount_2;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID_2;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc_2;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc_2;
	/// 资金比例
	TShengliStockBpRatioType		BpRatio_2;
};

/// \brief 设置交易账户的资金分配比例 响应
struct CShengliStockConfigRespSetBpRatioField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 设置返回码
	TShengliStockConfigResult		Result;
	/// 返回信息
	TShengliStockConfigRspMsg		Msg;
};

/// \brief 查询交易账户的资金分配比例
struct CShengliStockConfigReqQueryBpRatioField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 客户号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc;
};

/// \brief 查询交易账户的资金分配比例 响应
struct CShengliStockConfigRespQueryBpRatioField
{
	/// 请求ID
	TShengliStockLogonReqIDType		ReqID;
	/// 消息结束标识
	TShengliStockFlag				LastFlag;
	/// 客户号
	TShengliStockClientIdType       CustID;
	/// 资金账号
	TShengliStockAccountType        FundAccount;
	/// 交易市场ID
	TShengliStockExchangeIDType		ExchangeID;
	/// 交易账号
	TShengliStockTradeAccountType	TradeAcc;
	/// 期权交易账号
	TShengliStockTradeAccountType	TradeSubAcc;
	/// 资金比例
	TShengliStockBpRatioType		BpRatio;
};
#pragma pack(pop)

#endif