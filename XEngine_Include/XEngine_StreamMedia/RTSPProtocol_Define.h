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
    ENUM_RTSPPROTOCOL_METHOD_TYPE_PAUSE,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_ANNOUNCE,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_RECORD,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_GETPARAMETER,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_SETPARAMENT,
    ENUM_RTSPPROTOCOL_METHOD_TYPE_TEARDOWN
}ENUM_RTSPPROTOCOL_METHOD;
//////////////////////////////////////////////////////////////////////////
//                       导出的数据结构
//////////////////////////////////////////////////////////////////////////
//支持方法开关
typedef struct 
{
    bool bOptions;                       //选项,如果有打包处理此方法的,此选项必须为真才有效
    bool bDescribe;                      //描述
    bool bSetup;                         //配置
    bool bTeardown;                      //关闭
    bool bPlay;                          //播放
    bool bPause;                         //暂停
	bool bAnnounce;                      //匿名访问支持
	bool bRecord;                        //录像支持
    bool bGetParam;                      //获取参数
    bool bSetParam;                      //设置参数
}RTSPPROTOCOL_OPTIONS;
//传输信息
typedef struct 
{
    XCHAR tszSSRCStr[128];                   //SSRC绑定句柄
	struct  
	{
		bool bTCP;                           //TCP传输开关
		bool bUDP;                           //UDP传输开关
		bool bRTP;                           //是否负载的RTP包
		bool bAVP;                           //是否是媒体包
		bool bTLS;                           //是否是TSL加密的数据
		bool bSAVPF;                         //是不是SRTP包
	}st_TransFlags;
    struct  
    {
        bool bUnicast;                       //单播开关
        bool bBroadCast;                     //广播开关
    }st_TransTypes;
    struct  
    {
        int nRTPPort;                        //RTP端口
        int nRTCPPort;                       //RTCP端口
    }st_ClientPorts;
	struct
	{
		int nRTPPort;                        //RTP端口
		int nRTCPPort;                       //RTCP端口
	}st_ServerPorts;
}RTSPPROTOCOL_TRANSPORTINFO;
typedef struct
{
	XCHAR tszURLStr[MAX_PATH];
    XUINT nCSeq;
	XUINT nNTPTime;
}RTSPPROTOCOL_RTPINFO;
//客户端请求信息
typedef struct tag_RTSPProtocol_Request
{
    RTSPPROTOCOL_TRANSPORTINFO st_TransportInfo;
    ENUM_RTSPPROTOCOL_METHOD enMethod;     //方法类型
    XCHAR tszUrl[MAX_PATH];                //地址
    XCHAR tszMethod[128];                  //访问的方法名称
    XCHAR tszVersion[128];                 //版本
    
	XCHAR tszSession[128];                 //客户端会话ID
    XCHAR tszUserAgent[128];               //用户信息
    XCHAR tszAuthorize[128];               //用户验证信息
    int nCseq;                             //序列号
    //范围信息
    struct 
    {
        double dlTimeStart;                //开始时间
        double dlTimeEnd;                  //结束时间
        bool bNPTTime;                     //是否为NPT时间
    }st_Range;
    //通道信息
    struct
    {
        XCHAR tszChannels[64];             //通道内容
        XCHAR tszChannelName[64];          //通道名称
        int nChannelNumber;                //通道号
    }st_ChannelInfo;
}RTSPPROTOCOL_REQUEST;
//服务器返回信息
typedef struct tag_RTSPProtocol_Response
{
    RTSPPROTOCOL_TRANSPORTINFO st_TransportInfo;
    RTSPPROTOCOL_OPTIONS st_OPTion;        //服务器接受的参数

    XCHAR tszConBase[MAX_PATH];            //服务器返回的播放URL
    XCHAR tszVersion[128];                 //版本
    XCHAR tszSession[64];                  //服务器返回的客户端会话ID
    XCHAR tszDate[64];                     //服务器返回的时间
    int nCode;                             //服务器返回结果
    int nCSeq;                             //服务器返回的序列号
    int nTimeout;                          //超时时间,如果有的话
    int nPLen;                             //后续数据大小,负载内容默认SDP
	//范围信息
	struct
	{
		double dlTimeStart;                //开始时间
		double dlTimeEnd;                  //结束时间
		bool bNPTTime;                     //是否为NPT时间
	}st_Range;
    //验证信息
    struct
    {
        XCHAR tszMode[64];                //验证的模式,Basic Digest
        XCHAR tszContext[64];             //验证的内容
        bool bAuth;                       //是否启用了验证
    }st_AuthInfo;
    //附加选项
    struct  
    {
        bool bDynamicRate;                //动态码率
        bool bRetransmit;                 //重传
	}st_AdditionalOPtions;
	//RTP信息
    int nRTPCount;
	RTSPPROTOCOL_RTPINFO** ppSt_RTPInfo;
}RTSPPROTOCOL_RESPONSE;
//////////////////////////////////////////////////////////////////////////
//                       导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG RTSPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      解析函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_REQParse_Request
函数功能：解析缓冲区
 参数.一：pSt_RTSPRequest
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析的请求信息
 参数.二：lpszMethodStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的方法
 参数.三：lpszURLStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的URL
 参数.四：lpszVERStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的版本
 参数.五：pppszListHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入RTSP请求头(HTTP解析头)
 参数.六：nListHdr
  In/Out：In
  类型：整数型
  可空：N
  意思：输入头字段列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_REQParse_Request(RTSPPROTOCOL_REQUEST * pSt_RTSPRequest, LPCXSTR lpszMethodStr, LPCXSTR lpszURLStr, LPCXSTR lpszVERStr, XCHAR * **pppszListHdr, int nListHdr);
/********************************************************************
函数名称：RTSPProtocol_REPParse_Request
函数功能：解析缓冲区
 参数.一：pSt_RTSPReponse
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
extern "C" bool RTSPProtocol_REPParse_Request(RTSPPROTOCOL_RESPONSE * pSt_RTSPReponse, LPCXSTR lpszMsgBuffer, int nMsgLen);
/************************************************************************/
/*                      打包函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTSPProtocol_REQPacket_Request
函数功能：打包请求函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.三：pSt_RTSPRequest
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_REQPacket_Request(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, RTSPPROTOCOL_REQUEST* pSt_RTSPRequest);
/********************************************************************
函数名称：RTSPProtocol_REPPacket_Response
函数功能：打包响应函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.三：pSt_RTSPResponse
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTSPProtocol_REPPacket_Response(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, RTSPPROTOCOL_RESPONSE* pSt_RTSPResponse);