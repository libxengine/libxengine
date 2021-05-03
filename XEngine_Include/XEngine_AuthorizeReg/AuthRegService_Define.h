#pragma once
/********************************************************************
//	Created:	2013/1/21  13:22
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_AuthorizeReg\NetEngine_AuthRegService\AuthRegService_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_AuthorizeReg\NetEngine_AuthRegService
//	File Base:	AuthRegService_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	导出定义和函数
//	History:
*********************************************************************/
#define XENGINE_AUTHREG_SERVICE_SQL_MAX_USERNAME 32
//////////////////////////////////////////////////////////////////////////
//                         导出的回调函数
//////////////////////////////////////////////////////////////////////////
//用户在线时间事件回调处理函数，用户名 在线时间 剩余时间（分,天） 注册的卡类型 自定义参数
typedef void(CALLBACK *CALLBACK_XENGIEN_AUTHREG_SERVICE_EVENTS)(LPCSTR lpszUserAddr, LPCSTR lpszUserName,__int64x nOnlineTimer,__int64x nLeftTimer,LPCSTR lpszLeftDate,ENUM_AUTHREG_GENERATESERIALTYPE en_AuthRegSerialType,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
//充值协议
typedef struct
{
    CHAR tszUserName[XENGINE_AUTHREG_SERVICE_SQL_MAX_USERNAME];        //用户
    CHAR tszSerialNumber[128];                                           //序列号
}AUTHREG_PROTOCOL_USERPAY,*LPAUTHREG_PROTOCOL_USERPAY;
//时间信息协议
typedef struct
{
    CHAR tszUserAddr[XENGINE_AUTHREG_SERVICE_SQL_MAX_USERNAME];       //地址
    CHAR tszUserName[XENGINE_AUTHREG_SERVICE_SQL_MAX_USERNAME];       //用户
    CHAR tszLeftTime[64];                                                //过期日期
    __int64x nTimeLeft;                                                   //剩余时间
    __int64x nTimeONLine;                                                 //在线时间
    ENUM_AUTHREG_GENERATESERIALTYPE enSerialType;
}AUTHREG_PROTOCOL_TIME,*LPAUTHREG_PROTOCOL_TIME;
//用户表
typedef struct tag_AuthReg_UserTable
{
    XENGINE_PROTOCOL_USERREG st_UserInfo;
    CHAR tszLeftTime[64];                                                 //剩余日期
    CHAR tszHardCode[32];                                                 //硬件码
    ENUM_AUTHREG_GENERATESERIALTYPE en_AuthRegSerialType;                 //充值卡类型
}AUTHREG_USERTABLE, *LPAUTHREG_USERTABLE;
//注册序列号表
typedef struct tag_AuthReg_SerialTable
{
    CHAR tszUserName[XENGINE_AUTHREG_SERVICE_SQL_MAX_USERNAME];        //使用者是谁
    CHAR tszSerialNumber[128];                                           //序列号
    CHAR tszMaxTime[64];                                                 //使用时间
    ENUM_AUTHREG_GENERATESERIALTYPE en_AuthRegSerialType;                 //充值卡类型
    BOOL bIsUsed;                                                         //是否已经使用
}AUTHREG_SERIALTABLE,*LPAUTHREG_SERIALTABLE;
//网络临时验证表
typedef struct tag_AuthReg_NetVer
{
    CHAR tszVerSerial[256];                                               //验证序列号
    CHAR tszVerData[64];                                                  //验证时间
    ENUM_AUTHREG_GENERATESERIALTYPE enVerMode;                            //验证方式
    int nTryTime;                                                         //试用时间
}AUTHREG_NETVER, * LPAUTHREG_NETVER;
//////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AuthRegService_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                         数据库服务导出函数                           */
/************************************************************************/
/********************************************************************
函数名称：AuthRegService_Sql_Init
函数功能：初始化数据库服务
 参数.一：lpszSQLFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：数据库文件路径
 参数.二：bIsChange
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否允许更改用户充值类型
返回值
  类型：逻辑型
  意思：是否成功
备注：先初始化数据库服务，在初始化网络服务，才可以使用本验证服务器！
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_Init(LPCSTR lpszSQLFile, BOOL bIsChange = TRUE);
/********************************************************************
函数名称：AuthRegService_Sql_Destroy
函数功能：销毁数据库服务
返回值
  类型：逻辑型
  意思：是否销毁成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_Destroy();
/********************************************************************
函数名称：AuthRegService_Sql_UserDelete
函数功能：删除一个用户从数据库中
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的用户
返回值
  类型：逻辑型
  意思：是否删除成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_UserDelete(LPCSTR lpszUserName);
/********************************************************************
函数名称：AuthRegService_Sql_UserRegister
函数功能：用户注册处理数据库语句函数
 参数.一：pSt_UserInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要插入的用户数据
返回值
  类型：逻辑型
  意思：是否插入成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_UserRegister(LPAUTHREG_USERTABLE pSt_UserInfo);
/********************************************************************
函数名称：AuthRegService_Sql_UserQuery
函数功能：查询用户相对应的值
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要查询的指定用户
 参数.二：pSt_UserInfo
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：如果为空NULL，那么将只判断此用户是否存在
返回值
  类型：逻辑型
  意思：是否查询成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_UserQuery(LPCSTR lpszUserName,LPAUTHREG_USERTABLE pSt_UserInfo);
/********************************************************************
函数名称：AuthRegService_Sql_UserPay
函数功能：用户充值函数
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要充值的用户名
 参数.二：lpszSerialName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：充值使用的序列号
返回值
  类型：逻辑型
  意思：是否成功充值
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_UserPay(LPCSTR lpszUserName,LPCSTR lpszSerialName);
/********************************************************************
函数名称：AuthRegService_Sql_UserLeave
函数功能：用户离开处理事件
 参数.一：pSt_UserTable
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：离开的用户信息
 参数.二：nLeftTime
  In/Out：In
  类型：整数型
  可空：N
  意思：用户剩余时间,这个值才有分钟卡和天数卡才生效
返回值
  类型：逻辑型
  意思：是否处理成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_UserLeave(LPAUTHREG_USERTABLE pSt_UserTable, __int64x nLeftTime);
/********************************************************************
函数名称：AuthRegService_Sql_UserSet
函数功能：设置用户信息
 参数.一：pSt_UserTable
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要设置的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_UserSet(AUTHREG_USERTABLE* pSt_UserTable);
/********************************************************************
函数名称：AuthRegService_Sql_SerialInsert
函数功能：插入一个序列号到数据库
 参数.一：lpszSerialNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的序列号
返回值
  类型：逻辑型
  意思：是否插入成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_SerialInsert(LPCSTR lpszSerialNumber);
/********************************************************************
函数名称：AuthRegService_Sql_SerialDelete
函数功能：从数据库删除指定序列号
 参数.一：lpszSerialNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的序列号
返回值
  类型：逻辑型
  意思：是否删除成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_SerialDelete(LPCSTR lpszSerialNumber);
  /********************************************************************
函数名称：AuthRegService_Sql_SerialQuery
函数功能：查询一个指定的序列号信息
 参数.一：lpszSerialNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要查询的序列号
 参数.二：pSt_SerialTable
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：导出查询到的信息，如果为NULL，此参数将不起作用
返回值
  类型：逻辑型
  意思：是否查询成功，如果第二个参数为NULL，那么将只返回是否有这个序列号
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_SerialQuery(LPCSTR lpszSerialNumber,LPAUTHREG_SERIALTABLE pSt_SerialTable);
/********************************************************************
函数名称：AuthRegService_Sql_SerialQueryAll
函数功能：查询序列卡表中的所有序列号
 参数.一：pppSt_SerialTable
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出序列卡列表
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出多少张卡
返回值
  类型：逻辑型
  意思：是否查询成功
备注：参数一需要调用基础库的释放内存函数进行内存释放
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_SerialQueryAll(AUTHREG_SERIALTABLE * **pppSt_SerialTable, int* pInt_ListCount);
/********************************************************************
函数名称：AuthRegService_Sql_TryInsert
函数功能：网络使用模式插入一条数据
 参数.一：pSt_AuthVer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要插入的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_TryInsert(AUTHREG_NETVER* pSt_AuthVer);
/********************************************************************
函数名称：AuthRegService_Sql_TryQuery
函数功能：试用序列号查询函数
 参数.一：pSt_AuthVer
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入序列号,输出获取到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_TryQuery(AUTHREG_NETVER* pSt_AuthVer);
/********************************************************************
函数名称：AuthRegService_Sql_TryDelete
函数功能：删除一条指定的试用数据
 参数.一：lpszSerial
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要删除的序列号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_TryDelete(LPCSTR lpszSerial);
/********************************************************************
函数名称：AuthRegService_Sql_TryClear
函数功能：清理函数,自动清理过期数据
 参数.一：nThanValue
  In/Out：In
  类型：整数型
  可空：N
  意思：清理用于判断需要大于此的值
 参数.二：enVerMode
  In/Out：In
  类型：枚举型
  可空：Y
  意思：判断注册类型,默认不判断全部执行
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_TryClear(int nThanValue, ENUM_AUTHREG_GENERATESERIALTYPE enVerMode = ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_UNKNOW);
/********************************************************************
函数名称：AuthRegService_Sql_TrySet
函数功能：设置用户信息函数
 参数.一：pSt_AuthVer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要更新的用户信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Sql_TrySet(AUTHREG_NETVER* pSt_AuthVer);
/************************************************************************/
/*                         网络服务导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：AuthRegService_Net_Init
函数功能：初始化网络库
 参数.一：fpCall_AuthEvent
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：验证服务器事件时间回调函数，通过此来通知上层用户时间更新
 参数.二：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_Init(CALLBACK_XENGIEN_AUTHREG_SERVICE_EVENTS fpCall_AuthEvent,LPVOID lParam = NULL);
/********************************************************************
函数名称：AuthRegService_Net_GetClient
函数功能：获取客户端信息
 参数.一：pppSt_ListClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的客户端信息
 参数.二：pInt_ListCount
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输出列表个数
 参数.三：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要获取的客户端地址，为空表示获取所有
返回值
  类型：逻辑型
  意思：是否获取成功
备注：参数一必须通过基础库的内存释放函数BaseLib_OperatorMemory_Free进行释放内存
*********************************************************************/
extern "C" BOOL AuthRegService_Net_GetClient(AUTHREG_USERTABLE * **pppSt_ListClient, int* pInt_ListCount, LPCSTR lpszClientAddr);
/********************************************************************
函数名称：AuthRegService_Net_GetTimer
函数功能：获取客户端时间信息
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查找用户名
 参数.二：pSt_AuthTime
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：用户时间信息结构体
返回值
  类型：逻辑型
  意思：是否获取成功
备注：通过卡类型来判断导出的时间是分钟还是天
*********************************************************************/
extern "C" BOOL AuthRegService_Net_GetTimer(LPCSTR lpszUserName,AUTHREG_PROTOCOL_TIME *pSt_AuthTime);
/********************************************************************
函数名称：AuthRegService_Net_SendMsg
函数功能：发送验证协议数据填充函数
 参数.一：pSt_ProtocolHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的协议头
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：发送数据填充后的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出发送数据缓冲区大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：发送缓冲区内容,如果没有附加信息可以为NULL
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：发送数据长度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_SendMsg(XENGINE_PROTOCOLHDR *pSt_ProtocolHdr,CHAR *ptszMsgBuffer,int *pInt_MsgLen,LPCSTR lpszMsgBuffer = NULL,int nMsgLen = 0);
/********************************************************************
函数名称：AuthRegService_Net_RecvMsg
函数功能：分析协议处理器
 参数.一：lpszRecvMsg
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要分析的数据
 参数.二：pInt_Protocl
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出协议
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出后续数据长度
返回值
  类型：逻辑型
  意思：是否分析成功
备注：要分析的数据必须是一个完整的包
*********************************************************************/
extern "C" BOOL AuthRegService_Net_RecvMsg(LPCSTR lpszMsgBuffer,int *pInt_Protocl = NULL,int *pInt_MsgLen = NULL);
/********************************************************************
函数名称：AuthRegService_Net_GetAddrForUser
函数功能：通过用户名获取对应地址
 参数.一：lpszClientUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入用户名
 参数.二：ptszClientAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的用户套接字地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_GetAddrForUser(LPCSTR lpszClientUser,CHAR *ptszClientAddr);
/********************************************************************
函数名称：AuthRegService_Net_GetUserForAddr
函数功能：通过IP地址获取对应用户名
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入IP地址端口
 参数.二：ptszClientUser
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的用户名
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_GetUserForAddr(LPCSTR lpszClientAddr, CHAR *ptszClientUser);
/********************************************************************
函数名称：AuthRegService_Net_CloseClient
函数功能：移除一个客户端
 参数.一：lpszClientUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要移除的用户名
返回值
  类型：逻辑型
  意思：是否移除成功
备注：此函数会自动调用AuthRegService_Sql_UserLeave来处理离开时间
*********************************************************************/
extern "C" BOOL AuthRegService_Net_CloseClient(LPCSTR lpszClientUser);
/********************************************************************
函数名称：AuthRegService_Net_Destroy
函数功能：销毁网络服务
返回值
  类型：逻辑型
  意思：是否销毁成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_Destroy();
/********************************************************************
函数名称：AuthRegService_Net_LoginAnalysis
函数功能：用户登陆协议分析
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：用户的IP地址加端口
 参数.二：pSt_AuthProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：用户传递的协议数据
返回值
  类型：逻辑型
  意思：是否允许登陆
备注：如果成功，服务器会自动进行计时
*********************************************************************/
extern "C" BOOL AuthRegService_Net_ProLogin(LPCSTR lpszClientAddr,XENGINE_PROTOCOL_USERAUTH *pSt_AuthProtocol);
/********************************************************************
函数名称：AuthRegService_Net_ProDelete
函数功能：用户删除自身协议处理
 参数.一：pSt_AuthProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：用户传递的协议数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_ProDelete(AUTHREG_USERTABLE *pSt_UserTable);
/********************************************************************
函数名称：AuthRegService_Net_ProDelete
函数功能：用户删除自身协议处理
 参数.一：pSt_AuthProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：用户传递的协议数据
 参数.二：pSt_AuthProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出查询的用户名和密码，这个结构体需要返回给客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_ProGetPass(AUTHREG_USERTABLE *pSt_UserTable,XENGINE_PROTOCOL_USERAUTH *pSt_AuthProtocol);
/********************************************************************
函数名称：AuthRegService_Net_SetUser
函数功能：设置用户信息
 参数.一：pSt_UserTable
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要设置的用户信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegService_Net_SetUser(AUTHREG_USERTABLE* pSt_UserTable);
