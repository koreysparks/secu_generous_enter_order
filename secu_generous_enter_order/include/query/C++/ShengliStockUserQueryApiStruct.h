/*!
* \file  ShengliStockUserQueryApiStruct.h
* \brief 查询客户端公共的头文件
*
* 此文件描述了查询客户端结构体的定义
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

#include "../../common/C++/ShengliStockUserApiCommonStruct.h"

#pragma pack(push, 1)

/// 增加委托查询请求
struct CShengliStockReqEntrustField
{
	///用户ID
	TShengliStockUserIDType			UserID;

	///客户号
	TShengliStockClientIdType		ClientID;

	///资金账号
	TShengliStockAccountType		FundAccount;

	///市场
	TShengliStockExchangeIDType		ExchID;

	///证券代码
	TShengliStockSymbolType			SecurityCode;

	///股东账户名称
	TShengliStockTradeAccountType	TradeAccount;

	///委托编码ID
	TShengliStockEntrustIDType		OrderID;

	///请求序号
	TShengliStockRequestIDType		 RequestID;

	///查询类型 0 表示全部 1表示可撤单，可撤订单是订单未终结的订单，已成，已撤，部撤，废单是终结状态
	TShengliStockQueryTypeType       QueryType;

	///本次查询最大返回数量
	TShengliStockRequestNumType      RequestNum;

	///委托查询起始定位串，目前格式填写具体数字,用以表示服务器从哪里获取
	TShengliStockPositionStrType     PositionStr;
};

/// 增加成交查询请求
struct CShengliStockReqExecField
{
	///用户ID
	TShengliStockUserIDType			UserID;

	///客户号
	TShengliStockClientIdType		ClientID;

	///资金账号
	TShengliStockAccountType		FundAccount;

	///市场
	TShengliStockExchangeIDType		ExchID;

	///证券代码
	TShengliStockSymbolType			SecurityCode;

	///股东账户名称
	TShengliStockTradeAccountType	TradeAccount;

	///委托编码ID
	TShengliStockEntrustIDType		OrderID;

	///请求序号
	TShengliStockRequestIDType		RequestID;

	///查询类型 默认0 表示全部 
	TShengliStockQueryTypeType      QueryType;

	///本次查询最大返回数量
	TShengliStockRequestNumType     RequestNum;

	///成交所查询起始定位串，目前格式填写具体数字,用以表示服务器从哪里获取
	TShengliStockPositionStrType     PositionStr;
};

/// 委托对外报送结构(集成订单和撤销)
struct CShengliStockEntrustField
{
	///用户ID
	TShengliStockUserIDType					UserID;

	///客户号
	TShengliStockClientIdType				ClientID;

	///资金账号
	TShengliStockAccountType				FundAccount;

	///市场
	TShengliStockExchangeIDType				ExchID;

	///请求序号
	TShengliStockRequestIDType				RequestID;

	///查询类型 0 表示全部  1 表示不包括撤单
	TShengliStockQueryTypeType				QueryType;

	/// 当前记录在服务器中游标 
	TShengliStockCursorMarkType				CurCursorMark;

	/// 本次查询实查总记录数
	TShengliStockTotalNumType				TotalNum;

	/// 当前记录在本次查询中记录游标，从0开始， 若TotalNum -1 = CurIndex表示结束?????
	TShengliStockCurIndexType				CurIndex;

	/// 当前记录委托类型 0 订单  1 撤销
	TShengliStockEntrustTypeType			CurEntrustType;

	///订单和撤单共有字段
	///用户ID
	TShengliStockUserIDType					EntrustUserID;
	///客户端编号
	TShengliStockClientOrderTokenType		ClOrdToken;
	///客户号
	TShengliStockClientIdType				EntrustClientID;
	///交易所单号
	TShengliStockExchangeOrderIDType		ExchangeOrderID;
	///REM内核(硬件)处理完毕接受的时间戳，和开始发往交易所的时间戳相同&REM接受撤单请求并发往交易所的时间戳
	TShengliStockTimeStampType				AcceptTimestamp;
	///交易所提供的撤单时间戳，交易所接受时，交易所给出的时间戳
	TShengliStockTimeStampType				ExchangeTransTimestamp;
	///下单时候的UserInfo，UserInfo1为opstationID，UserInfo2为用户的自定义数据
	TShengliStockUserInfo1Type				UserInfo1;
	TShengliStockUserInfoType				UserInfo2;
	///REM系统单cluster唯一编号，撤单标识原始订单号OrigOrderID
	TShengliStockOrderIDType				OrderID;
	///REM处理撤单成功的时间戳，撤单时如果订单已经关闭，订单关闭的时间戳ClosedTimestamp
	TShengliStockTimeStampType				CxledTimestamp;
	///订单特有
	///证券类型
	TShengliStockSecurityTypeType			SecurityType;
	///证券子类型
	TShengliStockSecuritySubTypeType		SecuritySubType;
	///方向
	TShengliStockSideType					Side;
	///数量
	TShengliStockQtyType					OrderQty;
	///最小成交数量
	TShengliStockQtyType					MinQty;
	///订单类型
	TShengliStockPriceTypeType				PriceType;
	///市价单时有效,最多成交价位数,0表示不限
	TShengliStockMaxPriceLevelsType			MaxPriceLevels;
	///单子的存活时间
	TShengliStockTIFType					TIF;
	///价格
	TShengliStockOrderPriceType				Price;
	///止损价
	TShengliStockOrderPriceType				StopPrice;
	///代码
	TShengliStockSymbolType					SecurityCode;
	///交易类型
	TShengliStockCashMarginFlagType			CashMarginFlag;
	///会话ID
	TShengliStockSessionIDType				SessionID;
	///会话模式
	TShengliStockSessoinSelModeType			SessionSelMode;
	///交易所接受标志
	TShengliStockExchangeAcceptFlagType		ExchangeAcceptFlag;
	///订单状态
	TShengliStockOrderStatusType			OrderState;
	///被动单/外部单标志
	TShengliStockPassiveOrderFlagType		PassiveOrderFlag;
	///收到订单的时间，单位为纳秒
	TShengliStockTimeStampType				RecvTimestamp;
	///REM系统收到交易所接受的时间戳
	TShengliStockTimeStampType				ExchangeAcceptTimestamp;
	///总成交量
	TShengliStockQtyType					FilledQty;
	///--期权扩展字段--///
	///期权合约过期日
	TShengliStockTradingDateType			ExpireDate;
	///期权标的证券代码
	TShengliStockSymbolType					UnderlyingSecurityCode;
	///期权合约账户代码
	TShengliStockContractAccountCodeType	ContractAccountCode;
	///期权合约代码
	TShengliStockContractIDType				ContractID;
	///交易所
	TShengliStockExchangeIDType				UnderlyingExchID;
	///期权看涨看跌
	TShengliStockCallOrPutType				CallOrPut;
	///期权行权价
	TShengliStockOrderPriceType				StrikePrice;
	///只要不为0，就是强平的原因
	TShengliStockForceCoverFlag				ForceCoverFlag; 
	///撤单特有
	///要撤订单的ClOrdToken
	TShengliStockClientOrderTokenType		OrigClOrdToken;
	///单子被取消后所希望剩下的数量
	TShengliStockQtyType					LeavesQty;
	///撤单请求发送的UserID,如果是市场方向主动发起的撤单，该值填0。
	TShengliStockUserIDType					OrigUserID;
	///撤单时该订单已成交数量
	//TShengliStockQtyType  FilledQty;
	///被动撤单标志
	TShengliStockOrderCxlPassiveFlagType	PassiveFlag;
	///撤单状态标志
	TShengliStockCxlReqStatusType			CxlReqStatus;
};

///
struct CShengliStockExecField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType			FundAccount;
	///市场
	TShengliStockExchangeIDType			ExchID;
	///请求序号
	TShengliStockRequestIDType			RequestID;
	///查询类型 0 表示全部
	TShengliStockQueryTypeType			QueryType;
	/// 当前记录在服务器中游标 
	TShengliStockCursorMarkType			CurCursorMark;
	/// 本次查询实查总记录数
	TShengliStockTotalNumType			TotalNum;
	/// 当前记录在本次查询中记录游标，从0开始
	TShengliStockCurIndexType			CurIndex;
	///客户端编号
	TShengliStockClientOrderTokenType	ClOrdToken;
	///委托用户号
	TShengliStockUserIDType				EntrustUserID;
	///委托客户号
	TShengliStockClientIdType			EntrustClientID;
	///REM系统单cluster唯一编号
	TShengliStockOrderIDType			OrderID;
	///REM系统cluster唯一成交编号
	TShengliStockExecIDType				ExecID;
	///本次成交价
	TShengliStockOrderPriceType			LastPrice;
	///本次成交量
	TShengliStockQtyType				LastQty;
	///被动成交标志
	TShengliStockExecPassiveFlagType	PassiveFlag;
	///交易所单号
	TShengliStockExchangeOrderIDType	ExchangeOrderID;
	///交易所成交编号
	TShengliStockExchangeExecIDType		ExchangeExecID;
	///交易所成交时间戳
	TShengliStockTimeStampType			ExchangeTimestamp;
	///收到订单的时间
	TShengliStockTimeStampType			ExecTimestamp;
};

///
struct CShengliStockRespQryUserLoginField
{
	///客户端协议版本号
	TShengliStockProtoVersionType		ProtoVersion;
	///登录是否错误
	TShengliStockLogonResultType		Result;
	///登录名
	TShengliStockLogonIDType			LogonID;
	///用户ID
	TShengliStockUserIDType				UserID;
	///交易日
	TShengliStockTradingDateType		TradingDate;
};

///客户号资金状态查询请求
struct CShengliStockReqQueryBpStatusField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
	///市场
	TShengliStockExchangeIDType		ExchID;
};

#pragma pack(pop)

#endif