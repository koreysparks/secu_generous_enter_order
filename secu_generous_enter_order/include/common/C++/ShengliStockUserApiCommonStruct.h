/*!
* \file  ShengliStockUserApiCommonStruct.h
* \brief 交易和查询客户端公共的头文件
*
* 此文件描述了使用交易和查询客户端的公共结构体类型
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#ifndef SECURITY_STOCKCOMMONSTRUCT_H
#define SECURITY_STOCKCOMMONSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ShengliStockUserApiDataType.h"

#pragma pack(push, 1)

///协议版本号校验
struct CShengliStockProtoVersionCheckField
{
	///客户端协议版本号
	TShengliStockProtoVersionType ProtoVersion;
};

//连接配置
struct CShengliStockConnConfigField
{
	///交易接收绑核（填写小于0的数为不绑核-1,默认绑核cpu2）
	TShengliStockBindCpuNumType		TradeRecvNum;
	///交易处理绑核（填写小于0的数为不绑核-1，默认不绑核）
	TShengliStockBindCpuNumType		TradeProcNum;
	///查询接收绑核（填写小于0的数为不绑核-1，默认绑核cpu4）
	TShengliStockBindCpuNumType		QueryRecvNum;
	///查询处理绑核（填写小于0的数为不绑核-1，默认不绑核）
	TShengliStockBindCpuNumType		QueryProcNum;
	///交易处理模式（同步为SOCKET_THREAD_SYNC，异步为SOCKET_THREAD_ASYNC，默认为同步）
	TShengliStockSyncMethodType		TradeSyncMethod;
	///查询处理模式（同步为SOCKET_THREAD_SYNC，异步为SOCKET_THREAD_ASYNC，默认为同步）
	TShengliStockSyncMethodType		QuerySyncMethod;
	///交易接收睡眠时间（填写时间大于等于0，单位为us，默认为0）
	TShengliStockTimeType			TradeRecvSleepTime;
	///交易处理异步睡眠时间（填写时间大于等于0，单位为us，默认为0）
	TShengliStockTimeType			TradeProcSleepTime;
	///查询接收睡眠时间（填写时间大于等于0，单位为us，默认为0）
	TShengliStockTimeType			QueryRecvSleepTime;
	///查询处理异步睡眠时间（填写时间大于等于0，单位为us，默认为0）
	TShengliStockTimeType			QueryProcSleepTime;
	///是否开启自动重连（不自动重连为NOT_AUTO_RECONN，自动重连为AUTO_RECONN，，默认为不自动重连）
	TShengliStockReconnType			IsReconn;
	///自动重连时间间隔（填写时间大于等于1，单位为s，默认为1s）
	TShengliStockTimeType			ReconnTime;

	CShengliStockConnConfigField()
	{
		TradeRecvNum = 2;
		TradeProcNum = -1;
		QueryRecvNum = 4;
		QueryProcNum = -1;
		TradeSyncMethod = SOCKET_THREAD_SYNC;
		QuerySyncMethod = SOCKET_THREAD_SYNC;
		TradeRecvSleepTime = 0;
		TradeProcSleepTime = 0;
		QueryRecvSleepTime = 0;
		QueryProcSleepTime = 0;
		IsReconn = NOT_AUTO_RECONN;
		ReconnTime = 1;
	}
};

///登录请求
struct CShengliStockReqUserLoginField
{
	///客户端协议版本号
	TShengliStockProtoVersionType	ProtoVersion;
	///登录名
	TShengliStockLogonIDType			LogonID;
	///MD5加密后的密码
	TShengliStockLogonPwdType		Password;
	///客户端mac地址
	TShengliStockClientMacType		ClientMac;
	///客户端类型名称
	TShengliStockClientProdInfoType  ClientProdInfo;
	/// 看穿式APP id 
	TShengliStockAppIDType			AppID; 
	/// 看穿式APP 校验码 
	TShengliStockAuthCodeType		AuthCode; 
};

///修改密码请求
struct CShengliStockReqChangePwdField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///老密码的md5加密串
	TShengliStockLogonPwdType  OldMd5Pwd;
	///新密码的md5加密串
	TShengliStockLogonPwdType  NewMd5Pwd;
};

///协议版本号校验回报
struct CShengliStockRespProtoVersionCheckField
{
	///客户端协议版本号
	TShengliStockProtoVersionType ProtoVersion;
};

///客户号列表查询
struct CShengliStockReqQueryClientIDListField
{
	///用户ID
	TShengliStockUserIDType    UserID;
};

///资金账号列表查询
struct CShengliStockReqQueryAccountListField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///股东账户列表查询
struct CShengliStockReqQueryTradeAccountListField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///证券代码列表查询
struct CShengliStockReqQuerySecurityCodeField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///要查询的证券类型
	TShengliStockSecurityTypeType		SecurityType;
};

///ETF成份股查询
struct CShengliStockReqQueryEtfMemberField
{
	///用户ID
	TShengliStockUserIDType			UserID;
	///ETF证券代码
	TShengliStockSymbolType			SecurityCode;
	///交易所
	TShengliStockExchangeIDType	ExchID;
};

///期权细节查询
struct CShengliStockReqQueryOptionDetailField
{
	///用户ID
	TShengliStockUserIDType			UserID;
	///ETF证券代码
	TShengliStockSymbolType			UnderlyingSecurityCode;
	///交易所
	TShengliStockExchangeIDType		ExchID;
};

///账户费率查询
struct CShengliStockReqQueryAccountTradeFeeField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///仓位查询
struct CShengliStockReqQueryPositionField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};



///交易所席位连接查询请求
struct CShengliStockReqQueryExchSessionField
{
	///用户ID
	TShengliStockUserIDType    UserID;
};

///查询标的券数请求
struct CShengliStockReqUnderlyingSymbolQtyField
{
	///用户ID
	TShengliStockUserIDType			UserID;
	///客户号
	TShengliStockClientIdType		ClientID;
	///资金账号
	TShengliStockAccountType		FundAccount;
	///交易所
	TShengliStockExchangeIDType		ExchangeID;
	///代码
	TShengliStockSymbolType			SecurityCode;
	///请求ID
	TShengliStockRequestIDType		RequestID;
};

/// 查询向其它节点划出资金的列表
struct CShengliStockTrasnBpQueryField
{
	TShengliStockUserIDType			UserID;
	TShengliStockClientIdType		ClientID;
	TShengliStockAccountType		FundAccount;
};

///登录请求回应
struct CShengliStockRespUserLoginField
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
	///该用户下单目前最大的编号
	TShengliStockClientOrderTokenType	MaxToken;
	///默认的客户号
	TShengliStockClientIdType			DefClientID; 
};

///修改密码响应
struct CShengliStockRespChangePwdField
{
	///用户ID
	TShengliStockUserIDType					UserID;
	///修改密码是否成功
	TShengliStockChangePasswordResultType	Result;
};


struct CShengliStockCombLegField
{
	TShengliStockSymbolType 			LegSecurityID;		///<	成份合约代码（期权code）
	TShengliStockExchangeIDType			Exchange;				///<	交易所
	TShengliStockPosDirectionType		LegPosDir;			///<	持仓方向
	TShengliStockQtyType				LegOrderQty;			////<	成份合约数量
};

/// 期权组合，折分持仓订单扩展
struct CShengliStockExternCombOrder
{
	TShengliStockSecondaryOrderType		SecondaryOrderID; ///<	组合策略流水号， 16位有效	构建组合申报时填全 0 ，解除组合申报时填写拟解除组合对应的组合流水号（构建组合申报时返回的执行报告中的OrderID）
	TShengliStockSymbolType		StrategyID;		///<	组合策略编码
	unsigned char				Nolegs;			///<	成分合约个数（最多支持4，目前市场最多是2）
};

///REM订单接受, 订单rewind响应
struct CShengliStockOrderAcceptedField
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
	TShengliStockAccountType				FundAccount;
	///交易所
	TShengliStockExchangeIDType			ExchID;
	///方向
	TShengliStockSideType				Side;
	///数量
	TShengliStockQtyType					OrderQty;
	///最小成交数量
	TShengliStockQtyType					MinQty;
	///订单类型
	TShengliStockPriceTypeType			PriceType;
	///市价单时有效,最多成交价位数,0表示不限
	TShengliStockMaxPriceLevelsType		MaxPriceLevels;
	///单子的存活时间
	TShengliStockTIFType					TIF;
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
	///下单时候的UserInfo
	TShengliStockUserInfo1Type			UserInfo1;
	TShengliStockUserInfoType			UserInfo2;
	///REM系统单cluster唯一编号
	TShengliStockOrderIDType    OrderID;
	///交易所单号
	TShengliStockExchangeOrderIDType ExchangeOrderID;
	///交易所接受标志
	TShengliStockExchangeAcceptFlagType ExchangeAcceptFlag;
	///订单状态
	TShengliStockOrderStatusType OrderState;
	///被动单/外部单标志
	TShengliStockPassiveOrderFlagType PassiveOrderFlag;
	///收到订单的时间，单位为纳秒
	TShengliStockTimeStampType   RecvTimestamp;
	///REM内核(硬件)处理完毕接受的时间戳，和开始发往交易所的时间戳相同
	TShengliStockTimeStampType   AcceptTimestamp;
	///REM系统收到交易所接受的时间戳
	TShengliStockTimeStampType   ExchangeAcceptTimestamp;
	///交易所接受时，交易所给出的时间戳
	TShengliStockTimeStampType  ExchangeTransTimestamp;
	///如果订单已经关闭，订单关闭的时间戳
	TShengliStockTimeStampType  ClosedTimestamp;
	///总成交量
	TShengliStockQtyType   FilledQty;
	///--期权扩展字段--///
	///期权合约过期日
	TShengliStockTradingDateType ExpireDate;
	///期权标的证券代码
	TShengliStockSymbolType  UnderlyingSecurityCode;
	///期权合约账户代码
	TShengliStockContractAccountCodeType ContractAccountCode;
	///期权合约代码
	TShengliStockContractIDType ContractID;
	///交易所
	TShengliStockExchangeIDType UnderlyingExchID;
	///期权看涨看跌
	TShengliStockCallOrPutType CallOrPut;
	///期权行权价
	TShengliStockOrderPriceType StrikePrice;

	/// 只要不为0，就是强平的原因。
	TShengliStockForceCoverFlag	ForceCoverFlag;

	// 多腿信息	
	CShengliStockExternCombOrder	Extern;	// 扩展信息
	CShengliStockCombLegField		Leg[4];	// 多腿信息，最多4腿
};

///成交回报, 成交rewind响应
struct CShengliStockOrderExecedField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户端编号
	TShengliStockClientOrderTokenType	ClOrdToken;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType				FundAccount;
	///REM系统单cluster唯一编号
	TShengliStockOrderIDType    OrderID;
	///REM系统cluster唯一成交编号
	TShengliStockExecIDType    ExecID;
	///本次成交价
	TShengliStockOrderPriceType LastPrice;
	///本次成交量
	TShengliStockQtyType LastQty;
	///被动成交标志
	TShengliStockExecPassiveFlagType PassiveFlag;
	///交易所单号
	TShengliStockExchangeOrderIDType ExchangeOrderID;
	///交易所成交编号
	TShengliStockExchangeExecIDType  ExchangeExecID;
	///交易所成交时间戳
	TShengliStockTimeStampType ExchangeTimestamp;
	///收到订单的时间
	TShengliStockTimeStampType ExecTimestamp;
	
	// 多腿信息	
	CShengliStockExternCombOrder	Extern;	// 扩展信息

	CShengliStockCombLegField		Leg[4];	// 多腿信息，最多4腿
	TShengliStockSideType			Side;	// 买卖方向
	TShengliStockSymbolType			SecuCode; // 合约编码

};

///撤单成功/撤单请求
struct CShengliStockOrderCxledField
{
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户端编号
	TShengliStockClientOrderTokenType	ClOrdToken;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金账号
	TShengliStockAccountType				FundAccount;
	///盛立系统产生的单子号
	TShengliStockOrderIDType             OrigOrderID;
	///要撤订单的ClOrdToken
	TShengliStockClientOrderTokenType    OrigClOrdToken;
	///单子取消的数量
	TShengliStockQtyType                 LeavesQty;

	///REM接受撤单请求并发往交易所的时间戳
	TShengliStockTimeStampType AcceptTimestamp;
	///REM处理撤单成功的时间戳
	TShengliStockTimeStampType CxledTimestamp;
	///交易所提供的撤单时间戳
	TShengliStockTimeStampType ExchangeTransTimestamp;
	///交易所单号
	TShengliStockExchangeOrderIDType ExchangeOrderID;
	///撤单请求发送的UserID,如果是市场方向主动发起的撤单，该值填0。
	TShengliStockUserIDType OrigUserID;
	///撤单时该订单已成交数量
	//TShengliStockQtyType  FilledQty;
	///交易所
	TShengliStockExchangeIDType ExchID;
	///被动撤单标志
	TShengliStockOrderCxlPassiveFlagType PassiveFlag;
	///撤单状态标志
	TShengliStockCxlReqStatusType	CxlReqStatus;

};

///客户号列表查询响应
struct CShengliStockClientIDListField
{
	///请求ID
	TShengliStockRequestIDType		RequestID;
	///用户ID
	TShengliStockUserIDType			UserID;
	///客户号
	TShengliStockClientIdType		ClientID;
	///客户名称
	TShengliStockClientNameType		ClientName;
	///营业部
	TShengliStockBranchIdType		BranchID;
};

///业务行为权限结构体
struct CShengliStockBizPrevilegeBody
{
	///二级市场交易权限
	TShengliPermission		Lev2MarketPer;
	///债券撮合业务权限
	TShengliPermission		BondMatchPer;
	///债券质押式回购权限
	TShengliPermission		BondPledgeBuybackPer;
	///单市场ETF申赎权限
	TShengliPermission		SigMarketEtfPer;
	///跨市场ETF申赎权限
	TShengliPermission		CrossMaketEtfPer;
	///跨境ETF申赎权限
	TShengliPermission		CrossBorderEtfPer;
	///港股通权限
	TShengliPermission		HkStockSharePer;
};

///品种权限结构体
struct CShengliStockVarietyPrevilegeBody
{
	///A股权限
	TShengliPermission		AStockPer;
	///国债权限
	TShengliPermission		NationalDebtPer;
	///地方债权限
	TShengliPermission		LocalDebtPer;
	///企业债权限
	TShengliPermission		EnterpriseDebtPer;
	///公司债权限
	TShengliPermission		CompDebtPer;
	///金融债权限
	TShengliPermission		FinancialDebtPer;
	///可转换债权限
	TShengliPermission		ConvertibleBondPer;
	///可交换公司债权限
	TShengliPermission		ExchCompDebtPer;
	///可交换私募债权限
	TShengliPermission		ExchPriDebtPer;
	///私募债权限
	TShengliPermission		PriDebtPer;
	///次级债权限
	TShengliPermission		SecondaryDebtPer;
	///资产支持证券权限
	TShengliPermission		AbSecurityPer;
	///证券公司短期债权限
	TShengliPermission		SecuCompShortDebtPer;
	///LOF基金权限
	TShengliPermission		LofFundPer;
	///封闭式基金权限
	TShengliPermission		ClosedFundPer;
	///单市场ETF权限
	TShengliPermission		SigMarketEtfVarPer;
	///跨市场ETF权限
	TShengliPermission		CrossMarketEtfVarPer;
	///跨境ETF权限
	TShengliPermission		CrossBorderEtfVarPer;
	///实物债券ETF权限
	TShengliPermission		EntityBondEtfPer;
	///现金债券ETF权限
	TShengliPermission		CashBondEtfPer;
	///货币ETF权限
	TShengliPermission		CurrencyEtfPer;
	///黄金ETF权限
	TShengliPermission		GoldEtfPer;
	///跨境LOF权限
	TShengliPermission		CrossBorderLofPer;
};

///资金账户列表查询响应
struct CShengliStockAccountListField
{
	///请求ID
	TShengliStockRequestIDType					RequestID;
	///用户ID
	TShengliStockUserIDType						UserID;
	///客户号
	TShengliStockClientIdType					ClientID;
	///资金帐户
	TShengliStockAccountType					FundAccount;
	///资金账户名称
	TShengliStockAccountNameType				FundAccountName;
	///资金帐户类型
	TShengliStockAccountTypeType				FundAccountType;
	///是否支持融资行权
	TShengliStockAccountFinanchingExerciseType	AccountFinanchingExercise;
	///业务行为权限结构体
	CShengliStockBizPrevilegeBody				BizPrevilegeBody;
	///品种权限结构体
	CShengliStockVarietyPrevilegeBody			VarietyPrevilegeBody;
};

///适当性权限结构体
struct CShengliStockInvestorPrevilegeBody
{
	///市价委托权限
	TShengliPermission					MarketPricePer;
	///买入风险警示股票权限
	TShengliPermission					BuyStStockPer;
	///买入退市股票权限
	TShengliPermission					BuyOutStockPer;
	///创业板权限
	TShengliPermission					StartBoardPer;
	///科创板权限
	TShengliPermission					KechuangBoardPer;
	///分级基金权限
	TShengliPermission					StructuredFundPer;
	///债券市场投资者权限
	TShengliPermission					BondMarketInvestorPer;
	///债券市场合格投资者权限
	TShengliPermission					BondMarketQualifiedPer;
	///债券质押式回购权限
	TShengliPermission					BondPledgeBuybackPer;
	///港股通权限
	TShengliPermission					HkStockSharePer;
	///期权不合格投资者
	TShengliPermission					OptUQIPer;
	///期权一级权限
	TShengliPermission					OptLevel1Per;
	///期权二级权限
	TShengliPermission					OptLevel2Per;
	///期权三级权限
	TShengliPermission					OptLevel3Per;
};

///股东账户列表查询响应
struct CShengliTradeAccountListField
{
	///用户ID
	TShengliStockUserIDType						UserID;
	///客户号
	TShengliStockClientIdType					ClientID;
	///资金帐户
	TShengliStockAccountType					FundAccount;
	///资金帐户类型
	TShengliStockAccountTypeType				FundAccountType;
	///资金账户名称
	TShengliStockTradeAccountType				TradeAccount;
	///股东账户的交易所
	TShengliStockExchangeIDType					Exchange;
	///是否是当前登录的节点绑定的股东账户
	TShengliBindingTradeAcctType				BindingFlag;
	///请求ID
	TShengliStockRequestIDType					RequestID;
	///适当性权限结构体
	CShengliStockInvestorPrevilegeBody			InvestorPrevilegeBody;
	///交易节点
	TShengliTradeNode							TradeNodeID;
};

///原始代码列表查询响应
struct CShengliStockSecurityCodeField
{
	TShengliStockUserIDType					UserID;					///< 用户ID
	TShengliStockExchangeIDType				ExchID;					///< 交易所
	TShengliStockSecurityTypeType			SecurityType;			///< 交易品种
	TShengliStockSecuritySubTypeType		SecuritySubtype;		///< 交易子品种
	TShengliStockSymbolType					SecurityCode;			///< 证券代码
	TShengliStockSymbolNameType				SecurityName;			///< 证券名称
	TShengliStockTradingDateType			ExpireDate;				///< 期权合约过期日	
	TShengliStockSymbolType					UnderlyingSecurityCode;	///< 期权标的证券代码	
	TShengliStockContractAccountCodeType	ContractAccountCode;	///< 期权合约账户代码	
	TShengliStockContractIDType				ContractID;				///< 期权合约代码
	TShengliStockExchangeIDType				UnderlyingExchID;		///< 标的所属交易所	
	TShengliStockCallOrPutType				CallOrPut;				///< 期权看涨看跌	
	TShengliStockOrderPriceType				StrikePrice;			///< 期权行权价
};

///证券代码列表查询响应
struct CShengliStockNormalSecurityCodeField
{
	TShengliStockRequestIDType				RequestID;				///< 请求ID
	TShengliStockUserIDType					UserID;					///< 用户ID
	TShengliStockExchangeIDType				ExchID;					///< 交易所
	TShengliStockSecurityTypeType			SecurityType;			///< 交易品种
	TShengliStockSecuritySubTypeType		SecuritySubtype;		///< 交易子品种
	TShengliStockSymbolType					SecurityCode;			///< 证券代码
	TShengliStockSymbolNameType				SecurityName;			///< 证券名称
	TShengliStockCoverTodayFlagType			CoverTodayFlag;			///< 是否可平今
	TShengliStockCurrencyType				Currency;				///< 货币品种
	TShengliStockParValueType				ParValue;				///< 面值
	TShengliStockQtyType					BuyMinQty;				///< 买最小数量
	TShengliStockQtyType					SellMinQty;				///< 卖最小数量
	TShengliStockQtyType					MinOrderQty;			///< 单个订单最小委托数量
	TShengliStockQtyType					MaxOrderQty;			///< 单个订单最大委托数量
	TShengliStockOrderPriceType				PreClosePrice;			///< 昨收价
	TShengliStockOrderPriceType				MinTickPrice;			///< 最小价格标动
	TShengliStockOrderPriceType				UpLimitPrice;			///< 涨停价
	TShengliStockOrderPriceType				LowLimitPrice;			///< 跌停价
	TShengliStockIsFinancingType			IsFinancing;			///< 是否可融资
	TShengliStockIsLendingType				IsLending;				///< 是否可融券
};

///期权代码列表查询响应
struct CShengliStockOptionSecurityCodeField
{
	TShengliStockRequestIDType				RequestID;				///< 请求ID
	TShengliStockUserIDType					UserID;					///< 用户ID
	TShengliStockExchangeIDType				ExchID;					///< 交易所
	TShengliStockSecurityTypeType			SecurityType;			///< 交易品种
	TShengliStockSecuritySubTypeType		SecuritySubType;		///< 交易子品种
	TShengliStockSymbolType					SecurityCode;			///< 证券代码
	TShengliStockSymbolNameType				SecurityName;			///< 证券名称
	TShengliStockTradingDateType			ExpireDate;				///< 期权合约过期日	
	TShengliStockSymbolType					UnderlyingSecurityCode;	///< 期权标的证券代码
	TShengliStockSymbolNameType				UnderlyingSecurityName;	///< 期权标的证券名称
	TShengliStockSecurityTypeType			UnderlyingSecurityType;			///< 期权标的交易品种
	TShengliStockSecuritySubTypeType		UnderlyingSecuritySubType;		///< 期权标的交易子品种
	TShengliStockOptionType					OptionType;				///< 期权类型
	TShengliStockVolMultiplerType			VolMultipler;			///< 合约单位
	TShengliStockTradingDateType			StartDate;				///< 期权首个交易日
	TShengliStockTradingDateType			EndDate;				///< 期权最后交易日
	TShengliStockTradingDateType			DeliveryDate;			///< 期权交割日期
	TShengliStockTradingDateType			ExerciseDate;			///< 期权行权日期
	TShengliStockUpdateVersionType			UpdateVersion;			///< 更新版本号
	TShengliStockTotalLongPositionQtyType   TotalLongPosition;		///< 当前合约未平仓数量
	TShengliStockOrderPriceType				SecurityClosePx;		///< 昨日收盘价格
	TShengliStockOrderPriceType				SettlePrice;			///< 昨日结算价格
	TShengliStockOrderPriceType				UnderlyingClosePx;		///< 标的昨日收盘价格
	TShengliStockOrderPriceType				DailyPriceUpLimit;		///< 涨幅上限价格
	TShengliStockOrderPriceType				DailyPriceDownLimit;	///< 跌幅下限价格
	TShengliStockQtyType					LmtMinOrderQty;			///< 限价单个订单最小委托数量
	TShengliStockQtyType					LmtMaxOrderQty;			///< 限价单个订单最大委托数量
	TShengliStockQtyType					MktMinOrderQty;			///< 市价单个订单最小委托数量
	TShengliStockQtyType					MktMaxOrderQty;			///< 市价单个订单最大委托数量
	TShengliStockOrderPriceType				MinTickPrice;			///< 最小价格标动
	TShengliStockContractAccountCodeType	ContractAccountCode;	///< 期权合约账户代码	
	TShengliStockContractIDType				ContractID;				///< 期权合约代码
	TShengliStockExchangeIDType				UnderlyingExchID;		///< 标的所属交易所	
	TShengliStockCallOrPutType				CallOrPut;				///< 期权看涨看跌	
	TShengliStockOrderPriceType				StrikePrice;			///< 期权行权价
};

///ETF成份股查询响应
struct CShengliStockEtfMemberField
{
	///请求ID
	TShengliStockRequestIDType		RequestID;
	///用户ID
	TShengliStockUserIDType			UserID;
	///交易所
	TShengliStockExchangeIDType		ExchID;
	///ETF证券代码
	TShengliStockSymbolType			SecurityCode;
	///交易所
	TShengliStockExchangeIDType		MemberExchID;
	///成份股证券代码
	TShengliStockSymbolType			MemberSecurityCode;
	///成份股数量
	TShengliStockQtyType			Share;
	///现金替代标志
	TShengliStockSubstCashFlagType	SubstCashFlag;
	// 溢价比例
	TShengliStockSubstCashRateType	PermiumRatio;
	// 折价比例
	TShengliStockSubstCashRateType	DiscountRatio;
	// 申购替代金额
	TShengliStockAmountType			CreationCashSubstitute;
	// 赎回替代金额 
	TShengliStockAmountType			RedemptionCashSubstitute;
};

///账户费率查询的响应
struct CShengliStockAccountTradeFeeField
{
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金帐户类型
	TShengliStockAccountTypeType		AccountType;
	///资金帐户
	TShengliStockAccountType			FundAccount;
	///交易所
	TShengliStockExchangeIDType			ExchID;
	///交易分类
	TShengliStockTradeTypeType			TradeType;
	///仓位方向（暂时不用）
	TShengliStockPosDirectionType		PosDir;
	///费率组合
	TShengliStockFeeIdxType				FeeIdx;
	///按照金额比例收取的费率
	TShengliStockFeeRateType			FeeAmount;
	///按照成交量每股收取的费率
	TShengliStockFeeRateType			FeeQty;
	///支持每笔最小收费
	TShengliStockFeeRateType			FeeMin;
};

///股票/ETF仓位查询的响应
struct CShengliStockNormalPositionField
{
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金帐户类型
	TShengliStockAccountTypeType		AccountType;
	///资金帐户
	TShengliStockAccountType			FundAccount;
	///交易所
	TShengliStockExchangeIDType			ExchID;
	///证券类型
	TShengliStockSecurityTypeType		SecurityType;
	///证券子类型
	TShengliStockSecuritySubTypeType	SecuritySubType;
	///证券代码
	TShengliStockSymbolType				SecurityCode;
	///初始隔夜仓数量
	TShengliStockPosQtyType				InitOvnPosQty;
	///剩余昨仓, 所持量, 不考虑备兑锁定, 平仓锁定等
	TShengliStockPosQtyType				CurOvnQty;
	///总仓位，包括今仓, 所持量, 不考虑备兑锁定, 平仓锁定等
	TShengliStockPosQtyType				CurQty;
	///总可平仓数量, 考虑所有锁定数量
	TShengliStockPosQtyType				AvailQty;
	///备兑锁定量中昨仓部分
	TShengliStockPosQtyType				OvnCoveredLockedQty;
	///总备兑锁定量
	TShengliStockPosQtyType				CoveredLockedQty;
	///备兑锁定挂单量中，影响昨仓的部分。
	TShengliStockPosQtyType				OvnCoveredLockPendingQty;
	///总备兑锁定挂单量
	TShengliStockPosQtyType				CoveredLockPendingQty;
	///备兑担保量, 即已用于期权备兑仓担保的量
	TShengliStockPosQtyType				CoveredPledgedQty;
	// 备兑不足的量
	TShengliStockPosQtyType				CoveredNotEnoughQty;
	///总备兑解锁挂单量
	TShengliStockPosQtyType				CoveredUnlockPendingQty;
	///总平仓挂单量
	TShengliStockPosQtyType				ClosePosPendingQty;
	/// 持仓均价
	TShengliStockBpType					AvgPx;
};

///期权仓位查询的响应
struct CShengliStockOptionPositionField
{
	///请求ID
	TShengliStockRequestIDType			RequestID;
	///用户ID
	TShengliStockUserIDType				UserID;
	///客户号
	TShengliStockClientIdType			ClientID;
	///资金帐户类型
	TShengliStockAccountTypeType AccountType;
	///资金帐户
	TShengliStockAccountType		FundAccount;
	///交易所
	TShengliStockExchangeIDType	ExchID;
	///证券类型
	TShengliStockSecurityTypeType SecurityType;
	///证券子类型
	TShengliStockSecuritySubTypeType SecuritySubType;
	///证券代码
	TShengliStockSymbolType SecurityCode;
	///仓位方向，期权分多头、空头、备兑3种
	TShengliStockPosDirectionType	PositionDirection;
	///初始昨仓
	TShengliStockPosQtyType			InitOvnQty;
	///当前仓位
	TShengliStockPosQtyType			CurQty;
	///当前可平仓位
	TShengliStockPosQtyType			AvailQty;
	/// 当前占用的保证金
	TShengliStockMarginPriceType	CurMargin;

	/// 当前占用的交易所保证金
	TShengliStockMarginPriceType	CurExchangeMargin;

	/// 持仓均价
	TShengliStockBpType				AvgPx;
	///合约买入成本
	TShengliStockBcostType			Bcost;
	///仓位市值
	TShengliStockMktVaLType Mktval;

	///权利金
	TShengliStockPremiumType Premium;

	/// 在途的开仓数量
	TShengliStockOpeningQtyType OpeningQty;

	///在途的平仓数量
	TShengliStockCoveringQtyType CoveringQty;

	///在途冻结资金
	TShengliStockBpType OpeningFrozenBp;


	///在途冻结权利金
	TShengliStockBpType OpeningPremium;
};

///交易所连接查询响应
struct CShengliStockExchangeConnectField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///交易所
	TShengliStockExchangeIDType		ExchID;
	///交易所连接个数，0-255
	TShengliStockSessionCountType   SessionCount;
	///交易所连接代号
	TShengliStockSessionIDListType  SessionID;
};

///客户号资金状态查询响应
struct CShengliStockBpStatusField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	////客户号
	TShengliStockClientIdType  ClientID;
	///资金账户
	TShengliStockAccountType   FundAccount;
	///初始可用资金
	TShengliStockBpType InitialBp;
	///当前可用资金
	TShengliStockBpType AvailableBp;

	///开仓冻结保证金
	TShengliStockBpType FrozenMargin;


	///开仓冻结权利金
	TShengliStockBpType FrozenPremium;

	///开仓冻结费用
	TShengliStockBpType FrozenFee;

	///收权利金
	TShengliStockBpType IncomePremium;
	///支出权利金
	TShengliStockBpType OutcomePremium;


	///持仓占用保证金
	TShengliStockBpType MarginInclRlt;

	///交易所可用资金
	TShengliStockBpType ExchangeAvailBp;



	///总费用
	TShengliStockBpType TotalFee;

	///总权益
	TShengliStockBpType TotalFundBln;
	
	///请求ID
	TShengliStockRequestIDType RequestID;
	///市值权益
	TShengliStockBpType MarketEquity;
};

///查询标的券数请求响应
struct CShengliStockUnderlyingSymbolQtyField
{
	TShengliStockUserIDType			UserID;
	TShengliStockClientIdType		ClientID;
	TShengliStockAccountType		FundAccount;
	TShengliStockRequestIDType		RequestID;
	TShengliStockExchangeIDType		ExchangeID;
	TShengliStockSymbolType			SecurityCode;
	TShengliStockQtyType			Quantity;
	TShengliStockResultType			Result;
	TShengliStockTextType			MsgText;
};

///查询向交易节点资金划转响应
struct CShengliStockTrasnQueryBpDetailField
{
	TShengliStockId				mID;
	TShengliStockDate			mTradingDate;
	TShengliStockClientIdType	mClientID;
	TShengliStockAccountType	mFundAccount;
	TShengliStockExchangeIDType	mExchange;
	TShengliStockAmountType		mOutAmount;
	TShengliStockDatetime		mUpDt;
};

/// 期权组合策略仓位查询的响应
struct CShengliStockOptionCombStrategyPositionField
{
	TShengliStockUserIDType				m_UserID;
	TShengliStockClientIdType			m_CustID;
	TShengliStockAccountType			m_FundAccount;
	TShengliStockExchangeIDType			m_exchange_id;
	TShengliStockTradeAccountType		m_trade_acct;
	TShengliStockExchangeOrderIDType	m_comb_id;
	TShengliStockPosDayType				m_day_type;
	TShengliStockSymbolType				m_comb_strategy_id;
	TShengliStockSymbolType				m_underlying_secu_code;
	TShengliStockPosQtyType				m_share;
	TShengliStockPosQtyType				m_frz_share;
	double								m_margin;
	TShengliStockPosQtyType				m_leg_count;
	struct
	{
		TShengliStockSymbolType			m_secu_code;
		TShengliStockPosDirectionType	m_pos_dir;
		TShengliStockPosQtyType			m_share;
		double							m_margin;
	} m_leg[4];
};

///客户号订单rewind完成消息
struct CShengliStockOrderRewindFinishField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///客户号订单成交完成消息
struct CShengliStockExecRewindFinishField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///客户号订单撤销请求完成消息
struct CShengliStockCxlReqRewindFinishField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///交易信息rewind请求
struct CShengliStockReqTradeInfoRewindField
{
	///用户ID
	TShengliStockUserIDType    UserID;
	///客户号
	TShengliStockClientIdType  ClientID;
};

///通用消息
struct CShengliStockCommonMsgField
{
	TShengliStockErrCodeType		ErrCode;
	TShengliStockDisconnFlag		DisconnFlag;
	TShengliStockResultText			Reason;
};

#pragma pack(pop)

#endif