/*! \file  EesTraderDefine.h
 *  \brief EES交易客户端API使用的消息体定义。
 *
 *  本文件详细描述了EES交易客户端API使用的数据结构以及消息体。 
*/
#pragma  once 


#ifndef _EES_TRADE_API_STRUCT_DEFINE_H_
#define _EES_TRADE_API_STRUCT_DEFINE_H_

#define SL_EES_API_VERSION    "0.0.1.0"   ///<  api 协议版本号

typedef int RESULT ;      ///< 定义返回值 
typedef int ERR_NO ;      ///< 定义错误值 

typedef int           EES_ClientToken ; ///< API端订单的客户端ID
typedef int           EES_UserID ;      ///< 帐户ID
typedef long long int EES_MarketToken ; ///< 订单的市场 ID
typedef int           EES_TradingDate ; ///< 交易日
typedef long long int EES_Nanosecond ;  ///< 纳秒时间

typedef char    EES_Account[17] ;      ///< 交易帐户
typedef char    EES_ProductID[5] ;     ///< 期货的产品类型

typedef char    EES_ReasonText[64];    ///< 错误描述

typedef char    EES_GrammerResult[32]; ///< 下单语法检查
typedef char    EES_RiskResult[96];    ///< 下单风控检查
                              
typedef char    EES_Symbol[9] ;        ///< 交易合约编码
typedef char    EES_SymbolName[21] ;   ///< 交易合约名称

typedef unsigned char EES_SideType ;            ///< 买卖方向
#define EES_SideType_open_long                  1   ///< =买单（开今）
#define EES_SideType_close_today_long           2   ///< =卖单（平今）
#define EES_SideType_close_today_short          3   ///< =买单（平今）
#define EES_SideType_open_short                 4   ///< =卖单（开今）
#define EES_SideType_close_ovn_short            5   ///< =买单（平昨）
#define EES_SideType_close_ovn_long             6   ///< =卖单（平昨）
#define EES_SideType_force_close_ovn_short      7   ///< =买单 （强平昨）
#define EES_SideType_force_close_ovn_long       8   ///< =卖单 （强平昨）
#define EES_SideType_force_close_today_short    9   ///< =买单 （强平今）
#define EES_SideType_force_close_today_long     10  ///< =卖单 （强平今）

typedef unsigned char EES_ExchangeID ;          ///< 交易所ID
#define EES_ExchangeID_sh_cs                    100   ///< =上交所
#define EES_ExchangeID_sz_cs                    101   ///< =深交所
#define EES_ExchangeID_cffex                    102   ///< =中金所
#define EES_ExchangeID_shfe                     103   ///< =上期所
#define EES_ExchangeID_dce                      104   ///< =大商所
#define EES_ExchangeID_zcze                     105   ///< =郑商所
#define EES_ExchangeID_done_away                255   ///< =Done-away 


typedef unsigned char EES_SecType ;             ///< 交易品种类型 
#define EES_SecType_cs                          1   ///< =股票
#define EES_SecType_options                     2   ///< =期权
#define EES_SecType_fut                         3   ///< =期货


typedef unsigned char EES_ForceCloseType ;      ///< 强平原因 
#define EES_ForceCloseType_not_force_close      0   ///< =非强平  
#define EES_ForceCloseType_not_enough_bp        1   ///< =资金不足  
#define EES_ForceCloseType_not_enough_position  2   ///< =客户超仓  
#define EES_ForceCloseType_not_enough_position2 3   ///< =会员超仓  
#define EES_ForceCloseType_not_round_lot        4   ///< =持仓非整数倍  
#define EES_ForceCloseType_invalid              5   ///< =违规
#define EES_ForceCloseType_other                6   ///< =其他

typedef unsigned char EES_OrderState ;          ///< 订单状态
#define EES_OrderState_order_live               1   ///< =单子活着
#define EES_OrderState_order_dead               2   ///< =单子死了

typedef int           EES_Previlege ;           ///< 目前硬件暂不支持，也就是说都是完全操作权限 99：完全操作  1：只读 2：只平仓
#define EES_Previlege_open_and_close            99    ///< =所有权限
#define EES_Previlege_readonly                  1     ///< =只读
#define EES_Previlege_close_only                2     ///< =只能平仓


typedef int     EES_PosiDirection;      ///< 多空方向 1：多头 5：空头
#define EES_PosiDirection_long          1   ///< =多头
#define EES_PosiDirection_short         5   ///< =空头


typedef unsigned char EES_RejectedMan;  ///< 被谁拒绝，盛立系统还是下面连的交易所 1=盛立
#define EES_RejectedMan_by_shengli      1     ///< =被盛立拒绝

typedef unsigned char EES_ReasonCode;         ///< 单子被拒绝的理由。这张表将来会增加。请见下表。

typedef unsigned char EES_CxlReasonCode ; ///< 撤单成功的原因
#define EES_CxlReasonCode_by_account      1   ///< =用户撤单
#define EES_CxlReasonCode_timeout         2   ///< =系统timeout, 单子到期被交易所系统取消
#define EES_CxlReasonCode_supervisory     3   ///< =Supervisory, 被盛立系统管理者取消
#define EES_CxlReasonCode_by_market       4   ///< =被市场拒绝
#define EES_CxlReasonCode_another       255   ///< =其他

typedef unsigned char EES_OrderStatus;    ///< 该定义还不完整，以后还需要改
#define EES_OrderStatus_                  0   ///< =挂单或者全成交  
#define EES_OrderStatus_cxled             1   ///< =已经撤单  
#define EES_OrderStatus_reject            2   ///< =被拒绝  
#define EES_OrderStatus_expiration        3   ///< =已过期，类似已经撤单


#pragma pack(push, 1)


/// 登录返回的消息
struct EES_LogonResponse
{
  int               m_Result;           ///< 返回0表示登录成功，非0表示登录失败，失败时，不会返回UserId   0-  登录成功    1-  用户名/密码错误   2-  用户存在配置问题，如账户列表为空等
  EES_UserID        m_UserId;           ///< 登录名对应的用户ID
  unsigned int      m_TradingDate;      ///< 交易日，格式为yyyyMMdd的int型值
  EES_ClientToken   m_MaxToken;         ///< 以前的最大 token 
};


/// 下单消息
struct EES_EnterOrderField
{ 
  EES_Account         m_Account;          ///< 用户代码
  EES_SideType        m_Side ;            ///< 买卖方向
  EES_ExchangeID      m_Exchange;         ///< 交易所
  EES_Symbol          m_Symbol;           ///< 合约代码
  EES_SecType         m_SecType ;         ///< 交易品种
  double              m_Price ;           ///< 价格
  unsigned int        m_Qty ;             ///< 数量
  EES_ForceCloseType  m_ForceCloseReason ;///< 强平原因
};

/// 下单被市场接受消息
struct EES_OrderAcceptField
{ 
  EES_ClientToken     m_ClientOrderToken ;      ///< 下单的时候，返回给你的token
  EES_MarketToken     m_MarketOrderToken;       ///< 市场里面挂单的token
  EES_OrderState      m_OrderState ;            ///< 订单状态
  EES_UserID          m_UserID ;                ///< 订单的 user id 
  EES_Nanosecond      m_AcceptTime ;            ///< 从凌晨开始（0）的纳秒时间
  EES_Account         m_Account;                ///< 用户代码
  EES_SideType        m_Side ;                  ///< 买卖方向
  EES_ExchangeID      m_Exchange;               ///< 交易所
  EES_Symbol          m_Symbol;                 ///< 合约代码
  EES_SecType         m_SecType ;               ///< 交易品种
  double              m_Price ;                 ///< 价格
  unsigned int        m_Qty ;                   ///< 数量
  EES_ForceCloseType  m_ForceCloseReason ;      ///< 强平原因
};


/// 下单被市场拒绝
struct EES_OrderRejectField
{
  EES_UserID        m_Userid ;            ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond    m_Timestamp ;         ///< 时间，从晚上零时算起的纳秒数
  EES_ClientToken   m_ClientOrderToken ;  ///< 原来单子的token
  EES_RejectedMan   m_RejectedMan ;       ///< 被谁拒绝，盛立系统还是下面连的交易所 1=盛立
  EES_ReasonCode    m_ReasonCode  ;       ///< 单子被拒绝的理由。这张表将来会增加。请见下表。
  EES_GrammerResult m_Grammer_result ;    ///< 语法检查的结果数组，每个字符映射一种检查错误原因，见文件末尾的附录
  EES_RiskResult    m_RriskResult ;       ///< 风控检查的结果数组，每个字符映射一种检查错误原因，见文件末尾的附录
};

/// 订单成交消息体
struct EES_OrderExecutionField
{
  EES_UserID        m_Userid ;            ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond    m_Timestamp ;         ///< 时间，从晚上零时算起的纳秒数
  EES_ClientToken   m_ClientOrderToken ;  ///< 原来单子的你的token
  EES_MarketToken   m_MarketOrderToken ;  ///< 盛立系统产生的单子号，和盛立交流时可用该号。
  unsigned int      m_Quantity;           ///< 单子成交量
  double            m_Price;              ///< 单子成交价
  EES_MarketToken   m_ExecutionID ;       ///< 单子成交号(TAG 1017)
};

/// 下单撤单指令
struct EES_CancelOrder
{
  EES_MarketToken m_MarketOrderToken;   ///< 盛立系统产生的单子号，和盛立交流时可用该号。
  unsigned int    m_Quantity ;          ///< 这是该单子被取消后所希望剩下的数量，如为0，改单子为全部取消。在中国目前必须填0，其他值当0处理。
  EES_Account     m_Account;            ///< 帐户ID号
};

/// 订单撤销完成
struct EES_OrderCxled
{ 
  EES_UserID        m_Userid ;            ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond    m_Timestamp ;         ///< 时间，从晚上零时算起的纳秒数
  EES_ClientToken   m_ClientOrderToken ;  ///< 原来单子的token
  EES_MarketToken   m_MarketOrderToken ;  ///< 盛立系统产生的单子号，和盛立交流时可用该号。
  unsigned int      m_Decrement ;         ///< 这次信息所取消的单子量
  EES_CxlReasonCode m_Reason ;            ///< 原因，见下表
};

/// 查询订单的结构
struct EES_QueryAccountOrder
{
  EES_UserID        m_Userid ;            ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond    m_Timestamp ;         ///< 6  8 Int8  时间，从晚上零时算起的纳秒数
  EES_ClientToken   m_ClientOrderToken ;  ///< 原来单子的token 
  EES_SideType      m_SideType ;          ///< 1 = 买单（开今） 2 = 卖单（平今）  3= 买单（平今） 4 = 卖单（开今）  5= 买单（平昨） 6= 卖单（平昨） 7=买单（强平昨）  8=卖单（强平昨）  9=买单（强平今）  10=买单（强平今）
  unsigned int      m_Quantity ;          ///< 数量（股票为股数，期货为手数）
  EES_SecType       m_InstrumentType ;    ///< 1＝Equity 股票 2＝Options 期权 3＝Futures 期货
  EES_Symbol        m_symbol ;            ///< 股票代码，期货代码或者期权代码，以中国交易所标准 (目前6位就可以)
  double            m_Price;              ///< 价格
  EES_Account       m_account;            ///< 61 16  Alpha 客户帐号.  这个是传到交易所的客户帐号。验证后，必须是容许的值，也可能是这个连接的缺省值。
  EES_ExchangeID    m_ExchengeID ;           ///< 100＝上交所  101=深交所  102=中金所  103=上期所  104=大商所  105=郑商所  255= done-away  See appendix 
  EES_ForceCloseType  m_ForceCloseReason ;   ///< 强平原因： - 0=非强平  - 1=资金不足  - 2=客户超仓  - 3=会员超仓  - 4=持仓非整数倍  - 5=违规  - 6=其他
  EES_MarketToken   m_OrderReferenceNumber ; ///< 盛立系统产生的单子号，和盛立交流时可用该号。 
  EES_OrderStatus   m_OrderStatus ;          ///< 0：挂单或者全成交  1：已经撤单 2：被拒绝 3：已过期，类似已经撤单
  EES_Nanosecond    m_CloseTime ;            ///< 0  8 Int8  如果订单已经全部成交，或者撤单、或者拒绝，则该值有效
  int               m_FilledQty ;            ///< 0  4 Int4  成交数量
};
/// 查询订单成交的结构
struct EES_QueryOrderExecution
{
  EES_UserID        m_Userid ;            ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond    m_Timestamp ;         ///< 时间，从晚上零时算起的纳秒数
  EES_ClientToken   m_ClientOrderToken ;  ///< 原来单子的你的token
  EES_MarketToken   m_MarketOrderToken ;  ///< 盛立系统产生的单子号，和盛立交流时可用该号。
  unsigned int      m_ExecutedQuantity ;  ///< 单子成交量
  double            m_ExecutionPrice  ;   ///< 单子成交价
  EES_MarketToken   m_ExecutionID ;       ///< 单子成交号(TAG 1017)
};

/// 当一个账户的所有订单和成交都回滚完成后的消息
struct EES_QueryAccountTradeFinish
{
  EES_Account     m_account ;  ///< 账户ID
};

/// 帐户信息基本信息
struct EES_AccountInfo
{
  EES_Account     m_Account ;         ///< 帐户ID 
  EES_Previlege   m_Previlege ;       ///< 操作权限，目前硬件暂不支持，也就是说都是完全操作权限 99：完全操作  1：只读 2：只平仓
  double          m_InitialBp ;       ///< 初始权益
  double          m_AvailableBp ;     ///< 总可用资金
  double          m_Margin ;          ///< 所有仓位占用的保证金
  double          m_FrozenMargin ;    ///< 所有挂单冻结的保证金
  double          m_CommissionFee  ;  ///< 已扣除的手续费总金额
  double          m_FrozenCommission ;///< 挂单冻结的总手续费金额
};

/// 帐户的仓位信息
struct EES_AccountPosition
{
  EES_Account     m_actId;            ///< Value  Notes
  EES_Symbol      m_Symbol ;          ///< 合约名称/股票代码
  EES_PosiDirection m_PosiDirection;  ///< 多空方向 2：多头 3：空头
  unsigned int    m_InitOvnQty;       ///< 隔夜仓初始数量，这个值不会变化，除非通过HelpDesk手工修改
  unsigned int    m_OvnQty;           ///< 当前隔夜仓数量，可以为0
  unsigned int    m_FrozenOvnQty;     ///< 冻结的昨仓数量
  unsigned int    m_TodayQty;         ///< 当前今仓数量，可能为0
  unsigned int    m_FrozenTodayQty;   ///< 冻结的今仓数量
  double          m_OvnMargin  ;      ///< 隔夜仓占用保证金
  double          m_TodayMargin ;     ///< 今仓占用的保证金
};

/// 帐户的仓位信息
struct EES_AccountBP
{
  EES_Account   m_account;            ///< Value  Notes
  double        m_InitialBp ;         ///< 初始权益
  double        m_AvailableBp ;       ///< 总可用资金
  double        m_Margin ;            ///< 所有仓位占用的保证金
  double        m_FrozenMargin ;      ///< 所有挂单冻结的保证金
  double        m_CommissionFee  ;    ///< 已扣除的手续费总金额
  double        m_FrozenCommission ;  ///< 挂单冻结的总手续费金额
  double        m_OvnInitMargin;      ///< 初始昨仓保证金
  double        m_TotalLiquidPL;      ///< 总平仓盈亏
  double        m_TotalMarketPL;      ///< 总持仓盈亏
};

/// 合约列表
struct EES_SymbolField
{
  EES_SecType     m_SecType ;               ///< 3=Future，目前只有这个
  EES_Symbol      m_symbol  ;               ///< 合约名称/股票代码
  EES_SymbolName  m_symbolName ;            ///< 合约名称
  EES_ExchangeID  m_ExchangeID ;            ///< 102=中金所   103=上期所    104=大商所    105=郑商所
  EES_ProductID   m_ProdID ;                ///< 产品代码
  unsigned int    m_DeliveryYear ;          ///< 交割年
  unsigned int    m_DeliveryMonth ;         ///< 交割月
  unsigned int    m_MaxMarketOrderVolume ;  ///< 市价单最大下单量
  unsigned int    m_MinMarketOrderVolume ;  ///< 市价单最小下单量
  unsigned int    m_MaxLimitOrderVolume ;   ///< 限价单最大下单量
  unsigned int    m_MinLimitOrderVolume ;   ///< 限价单最小下单量
  unsigned int    m_VolumeMultiple;         ///< 合约乘数
  double          m_PriceTick;              ///< 最小变动价位 
  unsigned int    m_CreateDate;             ///< 创建日期
  unsigned int    m_OpenDate ;              ///< 上市日期
  unsigned int    m_ExpireDate ;            ///< 到期日
  unsigned int    m_StartDelivDate ;        ///< 开始交割日
  unsigned int    m_EndDelivDate;           ///< 结束交割日
  unsigned int    m_InstLifePhase ;         ///< 合约生命周期状态   0=未上市    1=上市    2=停牌    3=到齐
  unsigned int    m_IsTrading;              ///< 当前是否交易   0=未交易    1=交易
} ;

/// 查询帐户的保证金率
struct EES_AccountMargin
{
  EES_SecType     m_SecType ;           ///< 3=Future，目前只有这个
  EES_Symbol      m_symbol ;            ///< 合约名称/股票代码
  EES_ExchangeID  m_ExchangeID ;        ///< 102=中金所   103=上期所    104=大商所    105=郑商所
  EES_ProductID   m_ProdID;             ///< 4  Alpha 产品代码
  double          m_LongMarginRatio ;   ///< 多仓保证金率
  double          m_ShortMarginRatio ;  ///< 空仓保证金率，目前用不上
};

/// 帐户合约费率查询
struct EES_AccountFee
{
  EES_SecType     m_SecType ;                    ///<  3=Future，目前只有这个
  EES_Symbol      m_symbol ;                     ///<  合约名称/股票代码
  EES_ExchangeID  m_ExchangeID  ;                ///<  102=中金所    103=上期所    104=大商所    105=郑商所
  EES_ProductID   m_ProdID ;                     ///<  产品代码
  double          m_OpenRatioByMoney ;           ///<  开仓手续费率，按照金额
  double          m_OpenRatioByVolume ;          ///<  开仓手续费率，按照手数
  double          m_CloseYesterdayRatioByMoney;  ///<  平昨手续费率，按照金额
  double          m_CloseYesterdayRatioByVolume; ///<  平昨手续费率，按照手数
  double          m_CloseTodayRatioByMoney;      ///<  平今手续费率，按照金额
  double          m_CloseTodayRatioByVolume ;    ///<  平今手续费率，按照手数
} ;

/// 撤单被拒绝的消息体
struct EES_CxlOrderRej
{
  EES_Account       m_account  ;            ///< 客户帐号. 
  EES_MarketToken   m_MarketOrderToken;     ///< 盛立内部用的orderID
  unsigned int      m_ReasonCode ;          ///< 错误码，每个字符映射一种检查错误原因，见文件末尾的附录
  EES_ReasonText    m_ReasonText ;          ///< 错误字符串，未使用
};

/// 被动订单
struct EES_PostOrder
{
  EES_UserID        m_Userid  ;           ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond    m_Timestamp ;         ///< 时间，从晚上零时算起的纳秒数
  EES_MarketToken   m_MarketOrderToken ;  ///< 盛立系统产生的单子号，和盛立交流时可用该号。
  EES_ClientToken   m_ClientOrderToken ;  ///< 不起作用，设为０
  EES_SideType      m_SideType ;          ///< Buy/Sell Indicator 27  1 Int1  1 = 买单（开今）    2 = 卖单（平今）    3= 买单（平今）   4= 卖单（开今）   5= 买单（平昨）   6= 卖单（平昨）   7= 买单 （强平昨）    8= 卖单 （强平昨）    9= 买单 （强平今）    10=买单 （强平今）
  unsigned int      m_Quantity ;          ///< 数量（股票为股数，期货为手数）
  EES_SecType       m_SecType ;           ///< 1＝Equity 股票   2＝Options 期权   3＝Futures 期货
  EES_Symbol        m_Symbol;             ///< 股票代码，期货代码或者期权代码，以中国交易所标准 (目前6位就可以)
  double            m_price ;             ///< 价格 
  EES_Account       m_account;            ///< 客户帐号.  这个是传到交易所的客户帐号。验证后，必须是容许的值，也可能是这个连接的缺省值。
  EES_ExchangeID    m_ExchangeID ;        ///< 255=Done-away
  EES_ForceCloseType  m_ForceCloseReason ;   ///< 不用，填６。   强平原因：    - 0=非强平    - 1=资金不足    - 2=客户超仓    - 3=会员超仓    - 4=持仓非整数倍    - 5=违规    - 6=其他
  EES_OrderState    m_OrderState ;        ///< 单子状态，绝大多时候是1，但是也有可能是2.    1=order live（单子活着）    2=order dead（单子死了）
};

/// 被动成交
struct EES_PostOrderExecution
{
  EES_UserID      m_Userid ;            ///< 原来单子的用户，对应着LoginID。
  EES_Nanosecond  m_Timestamp ;         ///< 时间，从晚上零时算起的纳秒数
  EES_MarketToken m_MarketOrderToken;   ///< 盛立系统产生的单子号，和盛立交流时可用该号。
  unsigned int    m_ExecutedQuantity;   ///< 单子成交量
  double          m_ExecutionPrice;     ///< 单子成交价
  EES_MarketToken  m_ExecutionNumber;   ///< 单子成交号
};

#pragma pack(pop)

//	委托指令的拒绝原因，语法检查结果对照表：
//	0	整体结果，下列任何原因造成拒绝，该位都会为1
//	1	强平原因非法，目前只支持“0-非强平”
//	2	交易所代码非法，目前只支持“102-中金所”
//	3	不使用
//	4	不使用
//	5	不使用
//	6	委托价格必须>0
//	7	不使用
//	8	不使用
//	9	交易品种不合法，目前只支持“3-期货”
//	10	委托数量不合法，必须>0
//	11	不使用
//	12	买卖方向不合法，目前只支持1-6
//	13	不使用
//	14	对没有权限的账户进行操作
//	15	委托编号重复
//	16	不存在的账户
//	17	不合法的合约代码
//	18	委托总数超限，目前系统容量是每日最多850万个委托

//	撤销指令的拒绝原因对照表
//	0	整体校验结果 
//	1	委托尚未被交易所接受
//	2	要撤销的委托找不到
//	3	撤销的用户名和委托的用户名不一致
//	4	撤销的账户和委托的账户不一致
//	5	委托已经关闭，如已经撤销/成交等
//	6	重复撤单
//	7	被动单不能被撤单
//	

// 委托指令的拒绝原因，风控检查结果对照表：
//	0	订单手数限制
//	1	订单占经纪商保证金额限制
//	2	订单报价增额超限：与盘口价相比
//	3	订单报价增额超限: 与最近成交价相比
//	4	订单报价百分比超限:与盘口价相比
//	5	订单报价百分比超限:与最近成交价相比
//	6	订单报价增额超限：与昨结算价相比
//	7	订单报价百分比超限：与昨结算价相比
//	8	限价委托订单手数限制
//	9	市价委托订单手数限制
//	10	累计下订单发出次数限制
//	11	累计下订单发出手数限制
//	12	累计下订单发出金额限制
//	13	在指定时间1内收到订单次数上限
//	14	在指定时间2内收到订单次数上限
//	15	禁止交易
//	16	累计开仓订单发出次数限制
//	17	累计平仓订单发出次数限制
//	18	风控校验不通过次数限制
//	19	客户权益核查
//	20	总挂单金额校验
//	21	最大撤单次数限制
//	22	某合约最大撤单发出次数限制
//	23	在指定时间1内撤单次数上限
//	24	在指定时间2内撤单次数上限
//	25	大额订单撤单次数限制
//	26	累计持仓手数限制
//	27	累计持仓占用保证金额总和限制
//	28	累计成交手数限制
//	29	成交金额总和限制
//	30	下订单被市场拒绝次数的限制
//	31	下单被柜台系统拒绝次数限制
//	32	撤单被市场拒绝次数限制
//	33	在指定时间1内下订单被市场拒绝次数上限
//	34	在指定时间2内下订单被市场拒绝次数上限
//	35	在指定时间1内撤单被市场拒绝次数上限
//	36	在指定时间2内撤单被市场拒绝次数上限
//	37	净盈亏限制
//	38	浮动盈亏限制
//	39	总盈亏限制
//	40	持多仓手数限制
//	41	持空仓手数限制
//	42	持多仓占用保证金额限制
//	43	持空仓占用保证金额限制
//	44	某合约持多仓手数限制
//	45	某合约持空仓手数限制
//	46	某合约持多仓占用保证金额限制
//	47	某合约持空仓占用保证金额限制
//	48	某合约持仓总手数限制
//	49	某合约持仓占保证金额总额限制
//	50	某合约净收益限制
//	51	某合约浮动盈亏限制
//	52	某合约总收益限制
//	53	累计开仓成交手数限制
//	54	累计开仓成交金额总和限制
//	55	累计开多仓成交手数限制
//	56	累计开空仓成交手数限制
//	57	累计开多仓成交金额总和限制
//	58	累计开空仓成交金额总和限制
//	59	经纪商风险度限制
//	60	交易所风险度限制
//	61	在指定时间1内下单被柜台系统拒绝次数上限
//	62	在指定时间2内下单被柜台系统拒绝次数上限
//	63	不使用
//	64	可用资金不足
//	65	可平仓位不足
//	66	委托价格超过涨跌停范围




#endif
