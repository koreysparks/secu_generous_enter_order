/*!
* \file  ShengliStockUserTraderApiStruct.h
* \brief 查询客户端公共的头文件
*
* 此文件描述了交易客户端结构体的定义
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#ifndef SECURITY_STOCKTRADERSTRUCT_H
#define SECURITY_STOCKTRADERSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif 

#include "../../common/C++/ShengliStockUserApiCommonStruct.h"

#pragma pack(push, 1)

///下单
struct CShengliStockEnterOrderField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户端编号
	TShengliStockClientOrderTokenType	ClOrdToken;
	///客户号
	TShengliStockClientIdType			ClientID;
	///证券类型
	TShengliStockSecurityTypeType		SecurityType;
	///证券子类型
	TShengliStockSecurityTypeType		SecuritySubType;	
	///资金账号
	TShengliStockAccountType			FundAccount;	
	///交易所
	TShengliStockExchangeIDType			ExchID;
	///方向
	TShengliStockSideType				Side;
	///数量
	TShengliStockQtyType				OrderQty;
	///最小成交数量
	TShengliStockQtyType				MinQty;
	///订单类型
	TShengliStockPriceTypeType			PriceType;
	///市价单时有效,最多成交价位数,0表示不限
	TShengliStockMaxPriceLevelsType		MaxPriceLevels;
	///单子的存活时间
	TShengliStockTIFType				TIF;
	///价格
	TShengliStockOrderPriceType			Price;
	///止损价
	TShengliStockOrderPriceType			StopPrice;
	///代码
	TShengliStockSymbolType				SecurityCode;
	///交易类型
	TShengliStockCashMarginFlagType		CashMarginFlag;
	///会话ID,不关心时填0即可
	TShengliStockSessionIDType			SessionID;
	///会话模式
	TShengliStockSessoinSelModeType		SessionSelMode;
	///客户使用,回报时将回传
	TShengliStockUserInfoType			UserInfo;	
	///OpStation记录ID
	TShengliStockRecordID				RecordID;
	/// 强平标记
	/**
		0:正常交易，非强平
		1~254: 强平单，同时代表强平的原因ID
	*/	
	TShengliStockForceCoverFlag			ForceCoverFlag ;
};

/// 订单扩展
struct CShengliStockExternOrder
{
	///可用资金
	TShengliStockBpType					AvailBp;
	///仓位数量
	TShengliStockPosQtyType				PositonQty;
};

///撤单
struct CShengliStockCxlOrderField
{
	///要撤订单的UserId，配合OrigClOrdToken使用。
	TShengliStockOrigUserIdType			OrigUserId;
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户端编号
	TShengliStockClientOrderTokenType	ClOrdToken;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///盛立系统产生的单子号
	TShengliStockOrderIDType            OrigOrderID;
	///要撤订单的ClOrdToken
	TShengliStockClientOrderTokenType   OrigClOrdToken;
	///单子被取消后所希望剩下的数量
	///单子取消的数量 
	TShengliStockQtyType                LeavesQty;
	///客户使用,回报时将回传
	TShengliStockUserInfoType1			UserInfo1;
};

///向主席锁定/解锁标的券数量请求
struct  CShengliStockFrzUnderlyingSymbolQtyReqField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///交易所ID
	TShengliStockExchangeIDType			ExchangeID;
	///市场代码
	TShengliStockSymbolType				SecurityCode;
	///锁定解锁标志
	TShengliStockFrzFlagType			FrzFlag;
	///数量
	TShengliStockQtyType				Quantity;
	///评定
	TShengliStockTextType				Remark;
};

///同主席划入划出资金请求
struct CShengliStockInOutFundAccountAmountReqField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///交易所ID
	TShengliStockExchangeIDType			ExchangeID;
	///划入划出标志
	TShengliStockFrzFlagType			InOutFlag;
	///数量
	TShengliStockAmountType				Amount;
	///评定
	TShengliStockTextType				Remark;
};

///向其他节点划出资金请求
struct CShengliStockTrasnBpReqField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///资金账号类型
	TShengliStockAccountTypeType		FundAccountType;
	///交易所
	TShengliStockExchangeIDType			Exchange;
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///数量
	TShengliStockAmountType				Amount;
};

///交易所状态变化报告
struct CShengliStockExchangeStatusReportField
{
	///交易所代码
	TShengliStockExchangeIDType			ExchID;
	///交易所连接代号
	TShengliStockSessionIDType			SessionID;
	///交易所状态
	TShengliStockExchSessionSatusType	SessionStatus;
};

///订单拒绝
struct CShengliStockOrderRejectedField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///下单时指定的ClOrdToken
	TShengliStockClientOrderTokenType	ClOrdToken;
	///REM拒绝时该值为0. 交易所拒绝时为REM系统单号
	TShengliStockOrderIDType			OrderID;
	///拒绝的时间戳
	TShengliStockTimeStampType			RejectTimeStamp;
	///系统拒绝
	TShengliStockRejectedByType			RejectedBy;
	///拒绝原因
	TShengliStockRejectReasonType		RejectReason;
	///语法检查结果
	TShengliStockGrammerResultType		GrammarResult;
	///被动标志，只有交易所拒绝的情况有可能
	TShengliStockOrderCxlPassiveFlagType PassiveFlag;
	///风控检查结果
	TShengliStockRiskResultType			RiskResult;
	///错误原因文字
	TShengliStockReasonTextType			ReasonText;
};

///撤单拒绝
struct CShengliStockOrderCxlRejectedField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///订单凭证
	TShengliStockClientOrderTokenType	ClOrdToken;
	///单号
	TShengliStockOrderIDType            OrderID;
	///REM系统拒绝的时间戳，或者如果是交易所拒绝，REM处理交易所拒绝的时间戳
	TShengliStockTimeStampType          RejectTimeStamp;
	///如果是交易所撤单拒绝，交易所消息中提供的时间戳。
	TShengliStockTimeStampType			ExchangeTransTimestamp;
	///系统拒绝
	TShengliStockRejectedByType			RejectedBy;
	///拒绝原因
	TShengliStockRejectReasonType		RejectReason;
	///语法检查
	TShengliStockGrammerResultType		GrammarResult;
	///被动撤单标志
	TShengliStockOrderCxlPassiveFlagType PassiveFlag;
	///风控检查结果
	TShengliStockRiskResultType			RiskResult;
	///错误原因文字
	TShengliStockCxlRejectReasonTextType ReasonText;
	///被撤订单的UserID，找不到原单的场景时填0
	TShengliStockUserIDType				OrigUserID;
	///被撤订单的ClOrdToken，找不到原单的场景时填0
	TShengliStockClientOrderTokenType	OrigClOrdToken;
};

/// ETF申购赎回成交回报
/// Head
typedef CShengliStockOrderExecedField CShengliStockEtfExecHeadField;
/// Body
struct  CShengliStockEtfExecBodyField
{
	///成份股证券代码
	TShengliStockSymbolType				MemberSecurityCode;
	///股份交付数量
	TShengliStockQtyType				DeliveryQty;
	///交易所
	TShengliStockExchangeIDType			MemberExchID;
	///现金替代比例
	TShengliStockSubstCashRateType		SubstCashRate;
};

///向主席锁定/解锁标的券数量请求响应
struct  CShengliStockFrzUnderlyingSymbolQtyField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///交易所ID
	TShengliStockExchangeIDType			ExchangeID;
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///市场编码
	TShengliStockSymbolType				SecurityCode;
	///锁定解锁标志
	TShengliStockFrzFlagType			FrzFlag;
	///数量
	TShengliStockQtyType				Quantity;
	///结果标号
	TShengliStockResultType				Result;
	///结果内容
	TShengliStockTextType				MsgText;
};

///同主席划入划出资金请求响应
struct CShengliStockInOutFundAccountAmountField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账户
	TShengliStockAccountType			FundAccount;
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///划入划出标志
	TShengliStockFrzFlagType			RrzFlag;
	///数量
	TShengliStockAmountType				Amount;
	///结果标号
	TShengliStockResultType				Result;
	///消息内容
	TShengliStockTextType				MsgText;
};

///向交易节点划转资金请求响应
struct CShengliStockTrasnBpField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///资金账号类型
	TShengliStockAccountTypeType		FundAccountType;
	///交易所
	TShengliStockExchangeIDType			Exchange;
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///数量
	TShengliStockAmountType				Amount;
	///结果标号
	TShengliStockResultType				Result;
	///消息内容
	TShengliStockTextType				MsgText;
};

///系统信息上报
struct CShengliSystemMsgReportField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///消息类型
	int									MsgType;
	///消息码
	int									MsgCode;
	///消息内容
	TShengliStockTextType				MsgText;
};

struct CShengliOpStationReportReq
{
	///用户key
	TShengliOpStaionCustomerKey			CustomerKey;
	///上报内容
	TShengliOpStationReportContent		OpStationContent;
};

struct CShengliOpStationReportResp
{
	///用户key
	TShengliOpStaionCustomerKey			CustomerKey;
	///上报结果
	TShengliOpStationReportResult		Result;
	///OpStationID
	TShengliOpStationID					OpStationID;
	///用户ID
	TShengliUserID						UserID;
};

///客户号资金状态查询请求
struct CShengliStockReqQueryBpStatusField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
};

///查询出入金
struct CShengliStockQueryCashInOutField
{
	TShengliStockUserIDType			UserID;
	TShengliStockClientIdType		ClientID;
	TShengliStockAccountType		FundAccount;
};

///查询出入金的返回
struct CShengliStockRespCashInOutField
{
	TShengliStockUserIDType				UserID;
	TShengliStockClientIdType			ClientID;
	TShengliStockAccountType			FundAccount;
	TShengliStockAccountTypeType		FundAccountType;
	TShengliBpInOutSoutceType			InOutSource;
	TShengliBpInOutFlagType				CashInOutFlag;
	TShengliStockCashInOutAmountType	ModifyBp;
	TShengliStockCashInOutTimeType		UpDt;
};

/// 查询风控阈值  请求结构体
struct CShengliStockReqQueryRiskThresholdValueField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	/// 风控ID号
	TShengliRiskRuleID					RiskRuleID;
	///证券类型  填空
	TShengliStockSecurityTypeType		SecurityType;
	///证券子类型  填空
	TShengliStockSecurityTypeType		SecuritySubType;
	///交易所  填空
	TShengliStockExchangeIDType			ExchID;
	///代码  填空
	TShengliStockSymbolType				SecurityCode;
};

/// 查询风控阈值  返回结构体
struct CShengliStockReqQueryRiskThresholdValueRespField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///风控ID号
	TShengliRiskRuleID					RiskRuleID;
	///风控类型
	TShengliRiskRuleType				RiskRuleType;	
	///证券类型
	TShengliStockSecurityTypeType		SecurityType;
	///证券子类型 
	TShengliStockSecurityTypeType		SecuritySubType;
	///交易所
	TShengliStockExchangeIDType			ExchID;
	///代码
	TShengliStockSymbolType				SecurityCode;	
	///参数个数	最大为3 
	TShengliRiskRuleParamCount			ParamCount;	
	///门限值 
	TShengliRiskValue					RiskThreholdValue[3];
	///查询结果
	TShengliQueryResult					Result;
};

/// 查询风控统计值 头部消息
struct CShengliStockReqQueryHeaderField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	/// 查询个数  指向 CShengliStockReqQueryRiskValueField 的个数 
	TShengliRiskRuleParamCount			QryRiskCount;
};

/// 查询 风控统计值 结构体
struct CShengliStockReqQueryRiskValueField
{
	/// 风控ID号
	TShengliRiskRuleID					RiskRuleID;
	///证券类型  填空
	TShengliStockSecurityTypeType		SecurityType;
	///证券子类型  填空
	TShengliStockSecurityTypeType		SecuritySubType;
	///交易所  填空
	TShengliStockExchangeIDType			ExchID;
	///代码  填空
	TShengliStockSymbolType				SecurityCode;
};


/// 查询风控统计值   返回结构体
struct CShengliStockReqQueryRiskValueRespField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///风控ID号
	TShengliRiskRuleID					RiskRuleID;
	///风控类型
	TShengliRiskRuleType				RiskRuleType;
	///证券类型
	TShengliStockSecurityTypeType		SecurityType;
	///证券子类型 
	TShengliStockSecurityTypeType		SecuritySubType;
	///交易所
	TShengliStockExchangeIDType			ExchID;
	///代码
	TShengliStockSymbolType				SecurityCode;
	///门限值 
	TShengliRiskValue					RiskValue;
	///查询结果
	TShengliQueryResult					Result;
};


/// 中继登录请求
struct CShengliStockProxySubmitDataField
{
	/// AppID
	TShengliStockAppIDType				AppID;//终端客户的APPID
	/// AuthCode
	TShengliStockAuthCodeType			AuthCode;//终端客户的AppId对应的AuthCode
	/// 客户终端公网IP
	TShengliStockIP						TerminalPubNetIP;
	/// 客户终端公网端口号
	TShegliStockPort					TerminalPubNetPort;
	/// 客户终端登入时间
	TShengliStockLoginTimeType			TerminalLoginTime;
	/// 异常标识
	TShengliStockExceptionFlagType		ExceptionFlag;
	/// RealyID 必须是本次连接的登录请求中一致的APPidRelayId,不强制填写
	TShengliStockAppIDType				RelayID;
	/// 终端采集信息密文
	TShengliStockLocalSystemInfoType	TerminalSystemInfo; 
	///终端客户使用的资金账号
	TShengliStockAccountType			FundAccount ;//	可选，不填时，使用中继登录用户绑定的首个资金账号
};

/// 中继提交客户采集信息的返回结构
struct CShengliStockRspInfoField
{
	/// 错误码
	int									MsgCode;
	/// 错误内容
	TShengliStockTextType				MsgText;
};

//订阅请求
struct CShengliStockSubscribeField
{
	TShengliUserID						UserID;
};

//订阅回复
struct CShengliStockRespSubscribeField
{
	TShengliUserID						UserID;
	TShengliStockErrNoType				ErrCode;
	TShengliStockErrText				ErrText;
};

//推送交易所订单单号
struct CShengliStockRespMktCltOrdIDField
{
	TShengliUserID						UserID;
	TShengliStockClientIdType			ClientID;
	TShengliStockAccountType			FundAccount;
	TShengliStockOrderType				OrderType;
	TShengliStockClientOrderTokenType	CltOrderToken;
	TShengliUserID						OperUserID;
	TShengliStockOrderIDType			OrderID;
	TShengliUserID						OrigUserID;
	TShengliStockClientOrderTokenType	OrigCltOrderToken;
	TShengliStockOrderIDType			OrigOrderID;
	TShengliMktCltOrdID					MarketCltOrderID;
};

#pragma pack(pop)

#endif