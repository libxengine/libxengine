#pragma once
/********************************************************************
//	Created:	2019/1/18   9:32
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SIP\RfcSip_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SIP
//	File Base:	RfcSip_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	SIP协议导出函数
//	History:
*********************************************************************/
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_VIA_MAX_COUNT 10
//////////////////////////////////////////////////////////////////////////
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_REGISTER ("REGISTER")     //注册
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_INVITE ("INVITE")         //呼叫
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_OPTIONS ("OPTIONS")       //选项
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_MESSAGE ("MESSAGE")       //消息
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_ACK ("ACK")               //确认
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_BYE ("BYE")               //释放
#define XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_STR_TYPE_CANCEL ("CANCEL")         //取消
//////////////////////////////////////////////////////////////////////
//                      SIP事件定义
//////////////////////////////////////////////////////////////////////
typedef enum en_RfcSip_Events
{
    //注册相关事件
    ENUM_RFCCOMPONENTS_SIP_EVENTS_REGISTRATION_PROCESS,            //注册中
    ENUM_RFCCOMPONENTS_SIP_EVENTS_REGISTRATION_SUCCESS,            //用户成功注册
    //通话邀请相关事件
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CALL_INVITE,                     //报告一个新的呼叫
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CALL_PROCEEDING,                 //报告一个正在处理的远程程序,收到100 trying消息
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CALL_RINGING,                    //报告一个回铃,收到180 Ringing应答
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CALL_COMMUNICATE,                //开始通话
    //请求呼叫中的相关事件（INVITE除外）
    ENUM_RFCCOMPONENTS_SIP_EVENTS_MESSAGE_NEWMESSAGE,              //一条新消息
    ENUM_RFCCOMPONENTS_SIP_EVENTS_MESSAGE_PROCEEDING,              //处理中
    ENUM_RFCCOMPONENTS_SIP_EVENTS_MESSAGE_ANSWERED,                //200OK
    //取消状态
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CANCEL_REQUEST,                  //请求取消
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CANCEL_PROCEEDING,               //取消中
    ENUM_RFCCOMPONENTS_SIP_EVENTS_CANCEL_ANSWERED,                 //取消成功
    //断开状态
    ENUM_RFCCOMPONENTS_SIP_EVENTS_BYE_REQUEST,                     //结束
    ENUM_RFCCOMPONENTS_SIP_EVENTS_BYE_PROCEEDING,                  //结束中
    ENUM_RFCCOMPONENTS_SIP_EVENTS_BYE_ANSWERED,                    //结束成功
    //断开状态
    ENUM_RFCCOMPONENTS_SIP_EVENTS_OPTION_REQUEST,                  //选项请求
    ENUM_RFCCOMPONENTS_SIP_EVENTS_OPTION_PROCEEDING,               //处理中
    ENUM_RFCCOMPONENTS_SIP_EVENTS_OPTION_ANSWERED,                 //处理成功
    //在线状态和即时消息
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_NOANSWER,           //没有响应
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_PROCEEDING,         //报告一个1xx请求
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_ANSWERED,           //200OK
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_REDIRECTED,         //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_REQUESTFAILURE,     //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_SERVERFAILURE,      //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_GLOBALFAILURE,      //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_SUBSCRIPTION_NOTIFY,             //报告一个新的通知请求

    ENUM_RFCCOMPONENTS_SIP_EVENTS_IN_SUBSCRIPTION_NEW,             //新的订阅者

    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_NOANSWER,           //没有响应
    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_PROCEEDING,         //报告一个1xx请求
    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_ANSWERED,           //200OK
    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_REDIRECTED,         //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_REQUESTFAILURE,     //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_SERVERFAILURE,      //错误
    ENUM_RFCCOMPONENTS_SIP_EVENTS_NOTIFICATION_GLOBALFAILURE,      //错误
}ENUM_RFCCOMPONENTS_SIP_EVENTS;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    bool bRequest;                                                    //为真表示请求,为假表示回复
    //请求消息
    struct
    {
        XCHAR tszMethod[64];                                          //请求的方法 REGISTER
        XCHAR tszClientAddr[64];                                      //客户端地址 (xyry.org:5061;transport=tls) (xyry.org)
        XCHAR tszTansport[64];                                        //传输协议
        XCHAR tszVersion[64];                                         //版本
    }st_Request;
    //响应消息
    struct
    {
        XCHAR tszVersion[64];                                         //版本,如果通过HTTP服务模块得到的数据,那么这个值需要用户拷贝
        XCHAR tszMethod[64];                                          //响应内容,如果通过HTTP服务模块得到的数据,那么这个值需要用户拷贝
        int nCode;                                                   //返回的状态码
    }st_Response;
    //路由信息,穿透地址端口需要根据你自身情况填写,最多10个节点信息
    struct
    {
        XCHAR tszAddr[64];                                            //路由地址 192.168.1.104:52400
        XCHAR tszBranch[64];                                          //分支信息
        XCHAR tszNetType[32];                                         //网络类型 (UDP) (TLS)
        XCHAR tszRecvAddr[32];                                        //穿越地址,只有服务器返回响应才有
        bool bRport;                                                  //是否启用NAT穿越
        int nPort;                                                    //穿越端口,只有服务器返回响应才有
    }st_Via[XENGINE_RFCCOMPONENTS_SIP_PROTOCOL_VIA_MAX_COUNT];
    //包含信息
    struct
    {
        XCHAR tszAddr[256];                                           //地址 1001-0x20d1a38@192.168.1.104:52400
        XCHAR tszRinstance[64];                                       //多路ID
    }st_Contact;
    //接受者
    struct
    {
        XCHAR tszAddr[256];                                           //地址 1001@xyry.org:5061
        XCHAR tszName[64];                                            //名称
        XCHAR tszTag[64];                                             //接受者标签,只有响应才有
    }st_To;
    //发送者
    struct
    {
        XCHAR tszAddr[256];                                           //地址
        XCHAR tszName[64];                                            //名称
        XCHAR tszTag[64];                                             //发送者标签
    }st_From;
    //接受类型选项,用于OPTIONS
    struct
    {
        XCHAR tszAccept[64];                                          //可接受的负载类型
        XCHAR tszAcceptEncodec[64];                                   //可接受的编码类型
        XCHAR tszAcceptLanguage[64];                                  //可接受的语言
    }st_Accept;
    //会话标识
    struct
    {
        XCHAR tszUserAgent[128];                                      //用户信息
        XCHAR tszCallID[128];                                         //会话ID
        int nCSeq;                                                    //序列号
        int nExpires;                                                 //过期时间,单位秒,比如注册填写,表示注册后多久过期
        int nKeepAlive;                                               //包活计时
        int nForward;                                                 //转发跳跃限制
    }st_Session;
    //允许选项
    struct
    {
        bool bInvite;                                                 //呼叫
        bool bAck;                                                    //确认
        bool bBye;                                                    //关闭
        bool bCancel;                                                 //挂断
        bool bOption;                                                 //选项
        bool bRefer;                                                  //隐式订阅
        bool bNotify;                                                 //通知消息
        bool bSubscribe;                                              //订阅
        bool bInfo;                                                   //信息
        bool bMessage;                                                //消息
        bool bUPDate;                                                 //更新
        bool bPublish;                                                //发布
    }st_Allow;
    //支持选项
    struct
    {
        bool bTimer;                                                  //计时器
        bool bPath;                                                   //路径选择
        bool bReplaces;                                               //替换
    }st_Support;
    //验证结构
    struct
    {
        XCHAR tszRealm[128];
        XCHAR tszNonce[128];
        XCHAR tszOPaque[128];
        XCHAR tszQop[32];
        //以下字段只有请求才有
        XCHAR tszUserName[64];
        XCHAR tszUri[64];
        XCHAR tszNC[64];
        XCHAR tszCNonce[64];
        XCHAR tszResponse[128];                                        //可以通过OPenSsl_Help_Digest函数计算
    }st_Authenticate;
    //会话数据大小
    struct
    {
        int nHdrLen;                                                  //协议头大小
        int nBodyLen;                                                 //后续大小
        XCHAR tszContentType[64];                                      //数据类型
        XCHAR *ptszBodyBuffer;                                         //后续数据缓冲区,接受会自动申请内存,用户需要释放,发送为用户管理内存
    }st_Context;
}SIPPROTOCOL_HDRINFO;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" bool SIPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     SIP协议端导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SIPProtocol_Parse
函数功能：解析SIP协议
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
 参数.三：pSt_SIPProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析好的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPProtocol_Parse(LPCXSTR lpszMsgBuffer, int nMsgLen, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPProtocol_ParseByHttp
函数功能：通过HTTP服务模块得到的数据来解析SIP协议
 参数.一：lpszMethodStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的方法
 参数.二：lpszURLStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的URL地址
 参数.三：lpszVERStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入SIP版本字符串
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入BODY
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入BODY大小
 参数.六：pppszListHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入HTTP头字段列表
 参数.七：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入HTTP头字段个数
 参数.八：pSt_SIPProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析好的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPProtocol_ParseByHttp(LPCXSTR lpszMethodStr, LPCXSTR lpszURLStr, LPCXSTR lpszVERStr, LPCXSTR lpszMsgBuffer, int nMsgLen, XCHAR*** pppszListHdr, int nListCount, SIPPROTOCOL_HDRINFO* pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPProtocol_PacketRequest
函数功能：SIP请求打包函数
 参数.一：pSt_SIPProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入协议结构
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：bExChangeAddr
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否交换FROM和TO的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：一般的,名字和地址以及协议是必填的,其他可以选填
*********************************************************************/
extern "C" bool RfcComponents_SIPProtocol_PacketRequest(SIPPROTOCOL_HDRINFO *pSt_SIPProtocol, XCHAR *ptszMsgBuffer, int *pInt_MsgLen, bool bExChangeAddr = false);
/********************************************************************
函数名称：RfcComponents_SIPProtocol_PacketResponse
函数功能：SIP响应打包函数
 参数.一：pSt_SIPProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入协议结构
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：bExChangeAddr
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否交换FROM和TO的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：请求的解析结构需要输入到这个参数里面
*********************************************************************/
extern "C" bool RfcComponents_SIPProtocol_PacketResponse(SIPPROTOCOL_HDRINFO *pSt_SIPProtocol, XCHAR *ptszMsgBuffer, int *pInt_MsgLen, bool bExChangeAddr = false);
/************************************************************************/
/*                     SIP服务端导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SIPServer_Init
函数功能：初始化SIP服务器
 参数.一：lpszDomain
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入服务器的地址或者域名
 参数.二：bAnonymous
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否允许匿名注册
返回值
  类型：逻辑型
  意思：是否成功
备注：注意,此模块不包含网络服务
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_Init(LPCXSTR lpszDomain, bool bAnonymous = false);
/********************************************************************
函数名称：RfcComponents_SIPServer_Destory
函数功能：销毁服务器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_Destory();
/********************************************************************
函数名称：RfcComponents_SIPServer_Create
函数功能：创建一个客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要创建的客户端信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_Create(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RfcComponents_SIPServer_Delete
函数功能：删除一个指定的客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RfcComponents_SIPServer_Exist
函数功能：检查一个客户端句柄是否已经存在
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要判断的客户端
返回值
  类型：逻辑型
  意思：是否成功,返回真表示不存在
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_Exist(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RfcComponents_SIPServer_SetStatus
函数功能：设置状态
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要设置的客户端
 参数.二：enSIPEvent
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要设置的状态
返回值
  类型：逻辑型
  意思：是否成功
备注：在某些时候如果流程出错,需要还原状态
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_SetStatus(LPCXSTR lpszClientID, ENUM_RFCCOMPONENTS_SIP_EVENTS enSIPEvent = ENUM_RFCCOMPONENTS_SIP_EVENTS_REGISTRATION_SUCCESS);
/********************************************************************
函数名称：RfcComponents_SIPServer_GetStatus
函数功能：获取客户端当前状态
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的客户端
 参数.二：penSIPEvent
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：获取到的状态
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_GetStatus(LPCXSTR lpszClientID, ENUM_RFCCOMPONENTS_SIP_EVENTS *penSIPEvent);
/********************************************************************
函数名称：RfcComponents_SIPServer_Process
函数功能：处理一条完成的客户端请求
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的客户端
 参数.二：pSt_SIPHdr
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入通过RfcComponents_SIPProtocol_Parse解析后的请求.
        输出可以通过RfcComponents_SIPProtocol_PacketResponse打包的结构
返回值
  类型：逻辑型
  意思：是否成功
备注：必须解析完毕后的数据才能进行处理,处理后,返回成功你需要把结构体继续打包返回给客户端告诉其结果
      如果你想知道这个客户端请求是否成功,你可以通过此函数调用结束后的pSt_SIPHdr->st_Response.nCode
      值来确定
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_Process(LPCXSTR lpszClientID, SIPPROTOCOL_HDRINFO *pSt_SIPHdr);
/********************************************************************
函数名称：RfcComponents_SIPServer_FindAddr
函数功能：查找一个用户的通信地址
 参数.一：lpszClientUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查找的用户名
 参数.二：ptszClientAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出查找到的用户通信地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_FindAddr(LPCXSTR lpszClientUser, XCHAR *ptszClientAddr);
/********************************************************************
函数名称：RfcComponents_SIPServer_SetResponse
函数功能：设置客户端的RESPONSE信息摘要值
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的客户端
 参数.二：lpszResponseStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端计算的信息摘要值
返回值
  类型：逻辑型
  意思：是否成功
备注：如果要启用DIGEST验证,必须计算每个客户端的值后输入对应的RESPONSE值,不然会一直显示验证失败
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_SetResponse(LPCXSTR lpszUserName, LPCXSTR lpszResponseStr);
/********************************************************************
函数名称：RfcComponents_SIPServer_GetResponse
函数功能：获取计算RESPONSE需要的值
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入获取的用户
 参数.二：ptszNonce
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出客户端对应的唯一信息
 参数.三：ptszRealm
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出服务器作用域名,对应lpszDomain
 参数.四：ptszOpaque
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端对应的透传信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPServer_GetResponse(LPCXSTR lpszUserName, XCHAR* ptszNonce, XCHAR* ptszRealm = NULL, XCHAR* ptszOpaque = NULL);
/************************************************************************/
/*                     SIP客户端导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SIPClient_Create
函数功能：创建一个客户端
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出客户端句柄
 参数.二：lpszServerAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入服务器地址或者域名信息
 参数.二：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入用户名
 参数.二：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入密码.如果密码为NULL,表示客户端只支持匿名登录
 参数.二：bEnableHold
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：是否启用穿透,需要服务器支持
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_Create(XNETHANDLE *pxhToken, LPCXSTR lpszServerAddr, LPCXSTR lpszUser, LPCXSTR lpszPass = NULL, bool bEnableHold = false);
/********************************************************************
函数名称：RfcComponents_SIPClient_Delete
函数功能：移除客户端
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_Delete(XNETHANDLE xhToken);
/********************************************************************
函数名称：RfcComponents_SIPClient_Register
函数功能：客户端注册协议填充
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_SIPProtocol
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入已经填充好的部分协议,输出系统填充的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数会根据RfcComponents_SIPProtocol_Parse解析的请求继续填充需要的信息.
      导出的参数需要配合RfcComponents_SIPProtocol_PacketRequest函数使用
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_Register(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_ReqInvite
函数功能：请求一个呼叫
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_SIPProtocol
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入已经填充好的部分协议,输出系统填充的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要填充协议结构体的st_To,不然无法找到
      你需要填充SDP负载数据,否则对端不清楚通信的是什么
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_ReqInvite(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_RepInvite
函数功能：打包一个响应的呼叫协议
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_SIPProtocol
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入已经填充好的部分协议,输出系统填充的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：响应结构的nCode值你需要填充,200代表OK,否则请填写SIP的错误值
      这个代表是否接受呼叫,200代表接受,不返回将会一直处于响铃
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_RepInvite(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_ReqMessage
函数功能：打包一个消息发送协议
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端句柄
 参数.二：pSt_SIPProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出打包的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_ReqMessage(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_ReqCancel
函数功能：打包一个取消呼叫协议
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端句柄
 参数.二：pSt_SIPProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出打包的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_ReqCancel(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_ReqBye
函数功能：打包一个挂断协议
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端句柄
 参数.二：pSt_SIPProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出打包的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_ReqBye(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_ReqOptions
函数功能：打包一个选项请求支持协议
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端句柄
 参数.二：pSt_SIPProtocol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出打包的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_ReqOptions(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPProtocol);
/********************************************************************
函数名称：RfcComponents_SIPClient_GetStatus
函数功能：获取客户端当前状态
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_SIPProtocol
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入已经填充好的部分协议,输出系统填充的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：pEn_SIPEvent=ENUM_RFCCOMPONENTS_SIP_EVENTS_REGISTRATION_SUCCESS 表示用户空闲
      这个情况下才会允许有其他呼叫操作等
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_GetStatus(XNETHANDLE xhToken, ENUM_RFCCOMPONENTS_SIP_EVENTS *pEn_SIPEvent);
/********************************************************************
函数名称：RfcComponents_SIPClient_SetStatus
函数功能：设置状态
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
 参数.二：enSIPEvent
  In/Out：In
  类型：枚举型
  可空：Y
  意思：设置客户端状态,可强制改变当前状态
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_SetStatus(XNETHANDLE xhToken, ENUM_RFCCOMPONENTS_SIP_EVENTS enSIPEvent = ENUM_RFCCOMPONENTS_SIP_EVENTS_REGISTRATION_SUCCESS);
/********************************************************************
函数名称：RfcComponents_SIPClient_Process
函数功能：开始处理服务器返回的信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_SIPProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入已经解析好的协议结构
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数会根据RfcComponents_SIPProtocol_Parse解析的请求来处理
*********************************************************************/
extern "C" bool RfcComponents_SIPClient_Process(XNETHANDLE xhToken, SIPPROTOCOL_HDRINFO *pSt_SIPHdr);
