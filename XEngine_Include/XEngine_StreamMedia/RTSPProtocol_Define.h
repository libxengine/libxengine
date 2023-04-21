#pragma once
/********************************************************************
//	Created:	2019/8/21   15:31
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtspProtocol\RTSPProtocol_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtspProtocol
//	File Base:	RTSPProtocol_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	RTSP协议处理模块头文件
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       导出的枚举型
//////////////////////////////////////////////////////////////////////////
//RTSP方法
typedef enum en_RTSPProtocol_Method
{
    ENUM_RTSPPROTOCOL_METHOD_TYPE_OPTIONS = 1,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_DESCRIBE,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_SETUP,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_PLAY,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_PASUE,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_GETPARAMETER,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_SETPARAMENT,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_TEARDOWN
}ENUM_RTSPPROTOCOL_METHOD;
//////////////////////////////////////////////////////////////////////////
//                       导出的数据结构
//////////////////////////////////////////////////////////////////////////
//支持方法开关
typedef struct tag_RTSPProtocol_Options
{
    bool bOptions;                       //选项
    bool bDescribe;                      //描述
    bool bSetup;                         //配置
    bool bTeardown;                      //关闭
    bool bPlay;                          //播放
    bool bPause;                         //暂停
    bool bGetParam;                      //获取参数
    bool bSetParam;                      //设置参数
}RTSPPROTOCOL_OPTIONS;
//用户验证信息
typedef struct tag_RTSPProtocol_AuthInfo
{
    int nAuthMode;                       //验证类型,目前只能为0,基本
    XCHAR tszAuthUser[64];                //原始地址
    XCHAR tszAuthPass[64];                //目标IP地址
}RTSPPROTOCOL_AUTHINFO;
//SETUP网络配置
typedef struct tag_RTSPProtocol_Setup
{
    XCHAR tszSourceAddr[32];              //原始地址
    XCHAR tszDestAddr[32];                //目标IP地址
    int nClientRTPPort;                  //客户端RTP端口,如果是TCP模式,只有Client端口有效,SERVER端口无效
    int nClientRTCPPort;                 //客户端RTCP端口
    int nServerRTPPort;                  //服务器RTP绑定端口
    int nServerRTCPPort;                 //服务器RTCP绑定端口
    int nIPProtol;                       //使用的传输协议
}RTSPPROTOCOL_SETUP;
//客户端请求信息
typedef struct tag_RTSPProtocol_Request
{
    ENUM_RTSPPROTOCOL_METHOD enMethod;   //方法类型
    XCHAR tszMethod[64];                  //访问的方法名称
    XCHAR tszVersion[64];                 //版本
    XCHAR tszUrl[MAX_PATH];               //地址

    int nCseq;                           //序列号
    XCHAR tszUserAgent[MAX_PATH];         //用户信息
    //通道信息
    struct
    {
        XCHAR tszChannels[64];            //通道内容
        XCHAR tszChannelName[64];         //通道名称
        int nChannelNumber;              //通道号
    }st_ChannelInfo;
    //附加信息
    struct
    {
        bool bKeyFrame;                  //设置参数的关键帧字段值
        XCHAR tszAccept[64];              //客户端接受类型
        XCHAR tszTransport[64];           //客户端传输信息
        XCHAR tszSession[64];             //客户端会话ID
        XCHAR tszRange[64];               //开始位置
    }st_ExtInfo;
    //内容信息
    struct
    {
        XCHAR tszCtxBuffer[2048];         //附加内容缓冲区
        XCHAR tszCtxType[64];             //附加内容信息
        bool bContext;                   //是否有负载内容
        int nCtxLen;                     //附加信息长度
    }st_CtxInfo;
    //验证信息
    struct
    {
        XCHAR tszUser[64];                //验证的用户名
        XCHAR tszPass[64];                //验证的密码
        bool bAuth;                      //是否启用了验证
    }st_AuthInfo;
}RTSPPROTOCOL_REQUEST;
//服务器返回信息
typedef struct tag_RTSPProtocol_Response
{
    int nCode;                           //服务器返回结果
    int nCSeq;                           //服务器返回的序列号
    XCHAR tszDate[128];                   //服务器返回的时间
    //附加信息
    struct
    {
        RTSPPROTOCOL_OPTIONS st_OPTion;  //服务器接受的参数
        RTSPPROTOCOL_SETUP st_Setup;     //服务器传输信息
        XCHAR tszRTPInfo[128];            //RTP信息
        XCHAR tszSession[64];             //服务器返回的客户端会话ID
        XCHAR tszRange[64];               //开始位置
        int nTimeout;                    //超时时间
    }st_ExtInfo;
    //验证信息
    struct
    {
        XCHAR tszMode[64];                //验证的模式,Basic Digest
        XCHAR tszContext[64];             //验证的内容
        bool bAuth;                      //是否启用了验证
    }st_AuthInfo;
    //内容信息
    struct
    {
        XCHAR tszCtxBuffer[2048];         //附加内容缓冲区
        XCHAR tszCtxType[64];             //附加内容信息
        bool bContext;                   //是否有负载内容
        int nCtxLen;                     //附加信息长度
    }st_CtxInfo;
}RTSPPROTOCOL_RESPONSE;
//////////////////////////////////////////////////////////////////////////
//                       导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG RTSPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      解析函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_CoreParse_Create
函数功能：创建一个客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符串指针
  可空：N
  意思：要创建的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreParse_Create(LPCXSTR lpszClientAddr);
/********************************************************************
函数名称：RTSPProtocol_CoreParse_Delete
函数功能：删除一个客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreParse_Delete(LPCXSTR lpszClientAddr);
/********************************************************************
函数名称：RTSPProtocol_CoreParse_Insert
函数功能：解析缓冲区并且插入队列
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：创建的客户端地址
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreParse_Insert(LPCXSTR lpszClientAddr, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTSPProtocol_CoreParse_Get
函数功能：从队列里面获取一个请求包
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的客户端地址
 参数.二：pSt_RtspRequest
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的RTSP请求包
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreParse_Get(LPCXSTR lpszClientAddr, RTSPPROTOCOL_REQUEST *pSt_RtspRequest);
/********************************************************************
函数名称：RTSPProtocol_CoreParse_Parse
函数功能：解析缓冲区
 参数.一：pSt_RtspRequest
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析出来的RTSP请求
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数可单独使用
*********************************************************************/
extern "C" bool RTSPProtocol_CoreParse_Parse(RTSPPROTOCOL_REQUEST *pSt_RtspRequest, LPCXSTR lpszMsgBuffer, int nMsgLen);
/************************************************************************/
/*                      帮助函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_CoreHelp_Transport
函数功能：传输端口解析帮助函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解析的缓冲区
 参数.二：pInt_IPProto
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出客户端接受的数据报协议,TCP或UDP
 参数.三：pInt_RTPPort
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出客户端接受数据的RTP端口
 参数.四：pInt_RTCPPort
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出客户端接受RTCP端口
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreHelp_Transport(LPCXSTR lpszMsgBuffer, int* pInt_IPProto, int* pInt_RTPPort, int* pInt_RTCPPort);
/********************************************************************
函数名称：RTSPProtocol_CoreHelp_Range
函数功能：传输端口解析帮助函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解析的缓冲区
 参数.二：ptszType
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出客户端时间类型npt
 参数.三：plfTimeStart
  In/Out：Out
  类型：双精度浮点型指针
  可空：N
  意思：导出客户端需要的开始时间节点
 参数.四：plfTimeEnd
  In/Out：Out
  类型：双精度浮点型指针
  可空：N
  意思：导出客户端需要的结束时间节点,如果为0,表示,没有结束
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreHelp_Range(LPCXSTR lpszMsgBuffer, XCHAR *ptszType, double *plfTimeStart, double *plfTimeEnd);
/********************************************************************
函数名称：RTSPProtocol_CoreHelp_Url
函数功能：URL请求的地址分割
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解析的缓冲区
 参数.二：ptszFileName
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的文件或者串流地址
 参数.三：ptszUrl
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的URL地址
 参数.四：ptszType
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的请求头
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CoreHelp_Url(LPCXSTR lpszMsgBuffer, XCHAR *ptszFileName = NULL, XCHAR *ptszUrl = NULL, XCHAR *ptszType = NULL);
/************************************************************************/
/*                      打包函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Option
函数功能：选项方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_Options
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入你服务器支持的方法
 参数.四：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入客户端请求的序列号
 参数.五：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Option(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, RTSPPROTOCOL_OPTIONS *pSt_Options, int nCseq, int nCode = 200);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Describe
函数功能：描述方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入RTSP请求的URL地址
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入返回的SDP信息
 参数.五：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.六：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
返回值
  类型：逻辑型
  意思：是否成功
备注：如果状态码不为200,那么参数三和四将不起作用
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Describe(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, LPCXSTR lpszRtspUrl, LPCXSTR lpszMsgBuffer, int nCseq, int nCode = 200);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Setup
函数功能：配置方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：创建的RTP会话ID
 参数.四：pSt_RtspSetup
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入RTSP网络配置信息
 参数.五：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.六：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
返回值
  类型：逻辑型
  意思：是否成功
备注：如果状态码不为200,那么参数四将不起作用
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Setup(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszSession, RTSPPROTOCOL_SETUP * pSt_RtspSetup, int nCseq, int nCode = 200);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Play
函数功能：播放方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的会话ID
 参数.四：lpszRange
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入播放时间范围
 参数.五：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的URL地址
 参数.六：lpszTrack
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：通道名称
 参数.七：nRtpSeq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入RTP包序号
 参数.八：nRtpTime
  In/Out：In
  类型：整数型
  可空：N
  意思：输入RTP包时间
 参数.九：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.十：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Play(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, LPCXSTR lpszSession, LPCXSTR lpszRange, LPCXSTR lpszRtspUrl, LPCXSTR lpszTrack, int nRtpSeq, unsigned int nRtpTime, int nCseq, int nCode = 200);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Pasue
函数功能：暂停操作打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的会话ID
 参数.四：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.五：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Pasue(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, LPCXSTR lpszSession, int nCseq, int nCode = 200);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Teardown
函数功能：关闭方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的会话ID
 参数.四：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.五：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Teardown(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, LPCXSTR lpszSession, int nCseq, int nCode = 200);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Parament
函数功能：参数方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的会话ID
 参数.四：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.五：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
 参数.六：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：附加负载数据,如果有的话
返回值
  类型：逻辑型
  意思：是否成功
备注：获取参数方法可以用来表示心跳
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Parament(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, LPCXSTR lpszSession, int nCseq, int nCode = 200, LPCXSTR lpszMsgBuffer = NULL);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_CodeMsg
函数功能：打包一个指定消息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.四：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入返回的处理结果码
 参数.五：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入请求的会话ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_CodeMsg(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, int nCseq, int nCode = 404, LPCXSTR lpszSession = NULL);
/********************************************************************
函数名称：RTSPProtocol_CorePacket_Auth
函数功能：请求对方进行鉴权
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出封装好的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出缓冲区大小
 参数.三：nCseq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入序列号
返回值
  类型：逻辑型
  意思：是否成功
备注：返回此包给客户端,客户端需要进行HTTP BASIC鉴权
*********************************************************************/
extern "C" bool RTSPProtocol_CorePacket_Auth(XCHAR *ptszMsgBuffer, int *pInt_MsgLen, int nCseq);
/************************************************************************/
/*                      客户端打包类导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Option
函数功能：选项方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要请求的URL
 参数.四：nCSeq
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入请求的序列号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Option(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, int nCSeq = 1);
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Describe
函数功能：描述方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入RTSP请求的URL地址
 参数.四：nCSeq
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入请求的序列号
 参数.五：pSt_AuthInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入验证信息,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Describe(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, int nCSeq = 2, RTSPPROTOCOL_AUTHINFO * pSt_AuthInfo = NULL);
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Setup
函数功能：配置连接打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的RTSP地址
 参数.四：nIPProto
  In/Out：In
  类型：整数型
  可空：N
  意思：输入客户端需要的传输协议类型,IPPROTO_TCP,IPPROTO_UDP
 参数.五：nTrackID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的ID
 参数.六：nRTPNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：根据协议类型这个值不同,UDP表示端口,TCP表示通道
 参数.七：nRTCPNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：根据协议类型这个值不同,UDP表示端口,TCP表示通道
 参数.八：nCSeq
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入请求的序列号
 参数.九：pSt_AuthInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入验证信息,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Setup(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, int nIPProto, int nTrackID, int nRTPNumber, int nRTCPNumber, int nCSeq = 3, RTSPPROTOCOL_AUTHINFO * pSt_AuthInfo = NULL);
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Play
函数功能：播放方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的RTSP地址
 参数.四：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入会话ID
 参数.五：nCSeq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.六：pSt_AuthInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入验证信息,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Play(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, LPCXSTR lpszSession, int nCSeq = 4, RTSPPROTOCOL_AUTHINFO * pSt_AuthInfo = NULL);
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Pasue
函数功能：暂停操作打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的RTSP地址
 参数.四：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的会话ID
 参数.五：nCSeq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.六：pSt_AuthInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入验证信息,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Pasue(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, LPCXSTR lpszSession, int nCSeq = 5, RTSPPROTOCOL_AUTHINFO * pSt_AuthInfo = NULL);
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Teardown
函数功能：关闭方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入RTSP请求地址
 参数.四：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的会话ID
 参数.五：nCSeq
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入请求的序列号
 参数.六：pSt_AuthInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入验证信息,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Teardown(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, LPCXSTR lpszSession, int nCSeq = 6, RTSPPROTOCOL_AUTHINFO * pSt_AuthInfo = NULL);
/********************************************************************
函数名称：RTSPProtocol_ClientPacket_Parament
函数功能：参数方法打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszRtspUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的RTSP地址
 参数.四：lpszSession
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入会话ID
 参数.五：nCSeq
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求的序列号
 参数.六：bGet
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入时GET还是SET请求
 参数.七：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：附加负载数据,如果有的话
 参数.八：pSt_AuthInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入验证信息,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：获取参数方法可以用来表示心跳
*********************************************************************/
extern "C" bool RTSPProtocol_ClientPacket_Parament(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszRtspUrl, LPCXSTR lpszSession, int nCSeq, bool bGet = true, LPCXSTR lpszMsgBuffer = NULL, RTSPPROTOCOL_AUTHINFO * pSt_AuthInfo = NULL);
/************************************************************************/
/*                      客户端解析类导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_ClientParse_Parse
函数功能：解析缓冲区
 参数.一：pSt_RtspResponse
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析出来的RTSP回复
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_ClientParse_Parse(RTSPPROTOCOL_RESPONSE* pSt_RtspResponse, LPCXSTR lpszMsgBuffer, int nMsgLen);
