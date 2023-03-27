﻿#pragma once
/********************************************************************
//	Created:	2019/12/18   9:55
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_HttpServer\HttpServer_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_HttpServer
//	File Base:	HttpServer_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	HTTP服务导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                           枚举定义
//////////////////////////////////////////////////////////////////////////
typedef enum
{
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_DATA = 0x000,               //数据
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_HEADERS = 0x01,             //报头帧,用来打开一个流或者携带一个首部块片段
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_PRIORITY = 0x02,            //优先级帧,指定发送者建议的流优先级，可以在任何流状态下发送 PRIORITY 帧，包括空闲 (idle) 和关闭 (closed) 的流
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_RST_STREAM = 0x03,          //流终止帧,用来请求取消一个流，或者表示发生了一个错误，payload 带有一个 32 位无符号整数的错误码 (Error Codes)，不能在处于空闲 (idle) 状态的流上发送 RST_STREAM 帧
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_SETTINGS = 0x04,            //设置帧，设置此 连接 的参数，作用于整个连接
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_PUSH_PROMISE = 0x05,        //推送帧，服务端推送，客户端可以返回一个 RST_STREAM 帧来选择拒绝推送的流
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_PING = 0x06,                //PING帧，判断一个空闲的连接是否仍然可用，也可以测量最小往返时间 (RTT)
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_GOAWAY = 0x07,              //用于发起关闭连接的请求，或者警示严重错误。GOAWAY 会停止接收新流，并且关闭连接前会处理完先前建立的流
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_WINDOW_UPDATE = 0x08,       //窗口更新帧，用于执行流量控制功能，可以作用在单独某个流上 (指定具体 Stream Identifier) 也可以作用整个连接 (Stream Identifier 为 0x0)，只有 DATA 帧受流量控制影响。初始化流量窗口后，发送多少负载，流量窗口就减少多少，如果流量窗口不足就无法发送，WINDOW_UPDATE 帧可以增加流量窗口大小
	XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE_CONTINUATION = 0x09         //延续帧，用于继续传送首部块片段序列，见首部的压缩与解压缩
}XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE;
//////////////////////////////////////////////////////////////////////////
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
//HTTP发送参数
typedef struct
{
    //只有返回请求才有效
    struct  
    {
        __int64x nPosStart;                              //开始位置
        __int64x nPosEnd;                                //结束位置
        __int64x nPosCount;                              //总大小
    }st_Range;
    int nHttpCode;                                       //返回的状态码，必须设置
    int nStreamID;                                       //HTTP2必填
    BOOL bIsClose;                                       //是否启用关闭标志位
    BOOL bChunked;                                       //是否开启CHUNK传输模式，分割需要自己分割，如果块发送完毕，你需要这个值为真并且消息大小设置为0在发送一次给用户
    BOOL bChunkFirst;                                    //如果开启了CHUNK必须指明这个包是否是第一个包
    BOOL bGZip;                                          //数据是否使用了GZIP压缩（用户自己压缩，使用函数HelpCompress_Algorithm_GZipCompress进行压缩）
    BOOL bAuth;                                          //请求鉴权开关
    CHAR tszMimeType[64];                                //mime类型,如果为空，将使用 html
}RFCCOMPONENTS_HTTP_HDRPARAM, *LPRFCCOMPONENTS_HTTP_HDRPARAM;
//HTTP头参数
typedef struct
{
    CHAR tszHttpUri[MAX_PATH];                           //URI资源地址
    CHAR tszHttpMethod[64];                              //方法名称
    CHAR tszHttpVer[64];                                 //HTTP版本
}RFCCOMPONENTS_HTTP_REQPARAM, *LPRFCCOMPONENTS_HTTP_REQPARAM;
//可用数据表
typedef struct
{
    CHAR tszClientAddr[64];
    int nPktCount;
}RFCCOMPONENTS_HTTP_PKTCLIENT, * LPRFCCOMPONENTS_HTTP_PKTCLIENT;
//HTTP2所属
typedef struct
{
	int nStreamID;                                      //流ID
    int nPriority;                                      //流优先级,0-255
    int nPktCount;                                      //流ID包个数
}RFCCOMPONENTS_HTTP2_PKTSTREAM, * LPRFCCOMPONENTS_HTTP2_PKTSTREAM;
//HTTP2 HPACK
typedef struct
{
	CHAR tszNameBuffer[1024];                            //名称
	CHAR tszValueBuffer[1024];                           //内容
	int nNameLength;                                     //名大小
    int nValueLength;                                    //值大小
}RFCCOMPONENTS_HTTP2_HPACK, * LPRFCCOMPONENTS_HTTP2_HPACK;
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD HttpProtocol_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          HTTP服务导出函数                                      *
*********************************************************************************/
/********************************************************************
函数名称：HttpProtocol_Server_Init
函数功能：初始化HTTP服务器
 参数.一：lpszCodeFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：HTTP状态码配置文件位置
 参数.二：lpszMimeFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：HTTPMIME配置文件位置
 参数.三：nPoolCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：任务池个数,应该配合线程池个数使用
 参数.四：nLimitCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：每个包限制大小.0为不限制,单位BYTE
 参数.五：bAllowOrigin
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：跨域访问选项,默认为允许
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE HttpProtocol_Server_InitEx(LPCSTR lpszCodeFile, LPCSTR lpszMimeFile, int nPoolCount = 0, int nLimitCount = 0, BOOL bAllowOrigin = TRUE);
/********************************************************************
函数名称：HttpProtocol_Server_Destroy
函数功能：销毁这个简单的HTTP服务器
 参数.一：bActiveEvent
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否在销毁的时候激活一次事件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_DestroyEx(XHANDLE xhToken, BOOL bActiveEvent = TRUE);
/********************************************************************
函数名称：HttpProtocol_Server_CreateClient
函数功能：创建一个客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端地址
 参数.二：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：线程索引,-1表示没有启用,0表示自动选择
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_CreateClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nPoolIndex = -1);
/********************************************************************
函数名称：HttpProtocol_Server_SendMsg
函数功能：响应一个HTTP请求
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出封装好的要发送的HTTP数据包
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：导出发送数据包的大小，如果太小，这个参数会设置成需要的大小
 参数.三：pSt_HdrParam
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：发送HTTP协议配置选项
 参数.四：lpszBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：添加响应的内容,如果此参数为NULL,参数5不为NULL,那么将由调用者自己发送后续内容数据
 参数.五：nBodyLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：响应内容的长度
 参数.六：lpszHdr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：添加自定义协议头 格式 XEngine: 123\r\nXAuth: abc\r\n
返回值
  类型：逻辑型
  意思：是否响应成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_SendMsgEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_Len, RFCCOMPONENTS_HTTP_HDRPARAM* pSt_HdrParam, LPCSTR lpszBody = NULL, __int64x nBodyLen = 0, LPCSTR lpszHdr = NULL);
extern "C" BOOL HttpProtocol_Server_GetMemoryEx(XHANDLE xhToken, LPCSTR lpszClientAddr, CHAR** pptszBodyBuffer, int* pInt_BodyLen, RFCCOMPONENTS_HTTP_REQPARAM* pSt_ReqParam = NULL, CHAR*** pppszListHdr = NULL, int* pInt_ListCount = NULL);
/********************************************************************
函数名称：HttpProtocol_Server_GetList
函数功能：获取待处理客户端数据列表
 参数.一：pppSt_ListClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出可用客户端数据列表
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出客户端列表个数
 参数.三：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要获取的分布池索引,通过此值来分割任务列表,最大不超过第三个参数值
        为0表示不启用,获取所有
 参数.四：nPoolCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：总共可用分布池,表示要把任务列表切割成几份
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数是简单分割任务函数,参数一需要调用基础库的内存释放函数进行内存释放
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_GetListEx(XHANDLE xhToken, RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount, int nPoolIndex = 0, int nPoolCount = 4);
/********************************************************************
函数名称：HttpProtocol_Server_GetPool
函数功能：获取对应池化客户端列表
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入池化索引
 参数.二：pppSt_ListClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的对应类表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出客户端列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的内存释放函数BaseLib_OperatorMemory_Free进行内存释放
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_GetPoolEx(XHANDLE xhToken, int nPoolIndex, RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount);
/********************************************************************
函数名称：HttpProtocol_Server_InserQueue
函数功能：插入一段数据到队列中
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的客户端地址
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要插入的数据的长度
返回值
  类型：逻辑型
  意思：是否插入成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_InserQueueEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：HttpProtocol_Server_CloseClinet
函数功能：清理客户端资源
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的客户端地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_CloseClinetEx(XHANDLE xhToken, LPCSTR lpszClientAddr);
/********************************************************************
函数名称：HttpProtocol_Server_SetRecvMode
函数功能：设置接受数据模式
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：nRVMode
  In/Out：In
  类型：整数型
  可空：Y
  意思：0:直到完整的包才通知,1:只要有数据到达就通知(适合文件传输)
返回值
  类型：逻辑型
  意思：是否成功
备注：接受到完整的头后,1才会生效
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_SetRecvModeEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nRVMode = 0);
/********************************************************************
函数名称：HttpProtocol_Server_GetRecvMode
函数功能：获取当前接受数据包的模式
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的客户端
 参数.二：pInt_RVMode
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的模式
 参数.三：pInt_PKCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出当前会话包总大小
 参数.四：pInt_HDSize
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出已经处理(GET)的大小
 参数.五：pInt_PKSize
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出当前会话已经接受的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：一般的,参数3和4在MODE=1的情况下才有作用
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_GetRecvModeEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int* pInt_RVMode, int* pInt_PKCount = NULL, int* pInt_HDSize = NULL, int* pInt_PKSize = NULL);
/********************************************************************
函数名称：HttpProtocol_Server_EventWait
函数功能：等待一个完成包事件的发生
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布式池索引
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位毫秒 -1 不超时,0立即返回 > 0等待事件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_EventWaitEx(XHANDLE xhToken, int nPoolIndex = -1, int nTimeOut = -1);
/********************************************************************
函数名称：HttpProtocol_Server_EventActive
函数功能：手动激活一次事件
 参数.一：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布池索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server_EventActiveEx(XHANDLE xhToken, int nPoolIndex = -1);
//////////////////////////////////////////////////////////////////////////HTTP2
/********************************************************************
函数名称：HttpProtocol_Server2_Init
函数功能：初始化HTTP2服务器
 参数.一：nPoolCount
  In/Out：In
  类型：整数型
  可空：N
  意思：任务池个数,应该配合线程池个数使用
 参数.二：nLimitCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：每个包限制大小.0为不限制,单位BYTE
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE HttpProtocol_Server2_InitEx(int nPoolCount, int nLimitCount = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_Destroy
函数功能：销毁这个HTTP2服务器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_DestroyEx(XHANDLE xhToken);
/********************************************************************
函数名称：HttpProtocol_Server2_CreateClient
函数功能：创建一个客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端地址
 参数.二：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：线程索引,0表示自动选择
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_CreateClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nPoolIndex = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_InsertQueueEx
函数功能：插入一段数据到队列中
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的客户端地址
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要插入的数据的长度
返回值
  类型：逻辑型
  意思：是否插入成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_InsertQueueEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：HttpProtocol_Server2_CloseClinet
函数功能：关闭客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的客户端地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_CloseClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr);
/********************************************************************
函数名称：HttpProtocol_Server2_GetInfo
函数功能：获取客户端自定义信息
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：lParam
  In/Out：Out
  类型：无类型指针
  可空：N
  意思：导出获取到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_GetInfoEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPVOID lParam);
/********************************************************************
函数名称：HttpProtocol_Server2_SetInfo
函数功能：设置客户端自定义信息
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端地址
 参数.二：lParam
  In/Out：In
  类型：逻辑型
  可空：N
  意思：输入自定义的客户端信息,内存有用户管理
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_SetInfoEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPVOID lParam);
/********************************************************************
函数名称：HttpProtocol_Server_GetPool
函数功能：获取对应池化客户端列表
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入池化索引
 参数.二：pppSt_ListClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的对应类表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出客户端列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的内存释放函数BaseLib_OperatorMemory_Free进行内存释放
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_GetPoolEx(XHANDLE xhToken, int nPoolIndex, RFCCOMPONENTS_HTTP_PKTCLIENT*** pppSt_ListClient, int* pInt_ListCount);
/********************************************************************
函数名称：HttpProtocol_Server2_GetStream
函数功能：获取对应客户端的流索引信息
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要流列表的客户端
 参数.二：pppSt_PKTStream
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的对应的流列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的内存释放函数BaseLib_OperatorMemory_Free进行内存释放
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_GetStreamEx(XHANDLE xhToken, LPCSTR lpszClientAddr, RFCCOMPONENTS_HTTP2_PKTSTREAM*** pppSt_PKTStream, int* pInt_ListCount);
/********************************************************************
函数名称：HttpProtocol_Server2_GetClient
函数功能：获取客户端请求内容
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：nStreamID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入客户端流ID
 参数.三：penFrameType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出消息类型,你需要通过此参数来确定后续内容与处理方式
 参数.四：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：Y
  意思：输出客户端请求的内容,此内存需要手动删除
 参数.五：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出内容大小
 参数.六：pppSt_ListHdr
  In/Out：Out
  类型：三级指针
  可空：Y
  意思：输出请求的HEADER列表,此内存需要手动删除,客户端请求的实体在这里面
 参数.七：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出HEADER列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：DATA和HEADER包会分两次,所以如果包类型是HEADER后面可能会有DATA包,也可能没有
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_GetClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nStreamID, XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE * penFrameType, CHAR** pptszMsgBuffer = NULL, int* pInt_MsgLen = NULL, RFCCOMPONENTS_HTTP2_HPACK*** pppSt_ListHdr = NULL, int* pInt_ListCount = NULL);
/********************************************************************
函数名称：HttpProtocol_Server2_UPParse
函数功能：HTTP1升级到HTTP2的解析函数
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端地址
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.四：pSt_HTTPRequest
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：导出HTTP请求的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_UPParseEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen, RFCCOMPONENTS_HTTP_REQPARAM * pSt_HTTPRequest = NULL);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTUPGrade
函数功能：HTTP1升级到HTTP2打包返回协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nMaxStream
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的流ID大小
 参数.四：nWindowSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的滑动窗口大小
 参数.五：nHDRSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的头大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTUPGradeEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nMaxStream = 0, int nWindowSize = 0, int nHDRSize = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTSetting
函数功能：打包SETTING协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nMaxStream
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的流ID大小
 参数.四：nWindowSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的滑动窗口大小
 参数.五：nFrameSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的每帧最大大小
 参数.六：nHDRSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入允许的头大小
返回值
  类型：逻辑型
  意思：是否成功
备注：一般用于客户端连接请求后会发送一段SETTING用作通道参数
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTSettingEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nMaxStream = 0, int nWindowSize = 0, int nFrameSize = 0, int nHDRSize = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTWindow
函数功能：打包更新滑动窗口协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nWindowIncrement
  In/Out：In
  类型：整数型
  可空：N
  意思：输入允许的滑动窗口大小
返回值
  类型：逻辑型
  意思：是否成功
备注：一般用作于和SETTING一起
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTWindowEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nWindowIncrement);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTHeader
函数功能：打包HEADER协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_HDRParam
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入打包头的参数
 参数.四：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：是否有后续的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTHeaderEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, RFCCOMPONENTS_HTTP_HDRPARAM* pSt_HDRParam, int nMsgLen = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTData
函数功能：打包数据
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nStreamID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入流ID
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入打包的数据
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入打包的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTDataEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTMessage
函数功能：打包DATA协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nStreamID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入流ID
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入BODY后续内容
 参数.五：nBLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入BODY大小
 参数.六：bEndStream
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否为结束数据包
返回值
  类型：逻辑型
  意思：是否成功
备注：DATA协议之前一般需要跟上HEADER协议
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTMessageEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, LPCSTR lpszMsgBuffer = NULL, int nBLen = 0, BOOL bEndStream = TRUE);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTPing
函数功能：打包一个PING协议包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszOPData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入PING负载的自定义数据,只能是8个字节
 参数.四：bAck
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否包含ACK标志,如果不包含,将认为是请求,那么会收到一个不包含ACK的PING包
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTPingEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCSTR lpszOPData, BOOL bAck = TRUE);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTGoaway
函数功能：打包一个GOAWAY协议包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nStreamID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的流ID
 参数.四：nErrorCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：错误码,可以为0
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTGoawayEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, int nErrorCode = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_PKTPush
函数功能：打包一个PUSH协议包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nStreamID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的流ID
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要附加的推送数据,一般都是压缩的HEADER
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入附加数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_PKTPushEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, LPCSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：HttpProtocol_Server2_EventWait
函数功能：等待一个完成包事件的发生
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布式池索引
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位毫秒 -1 不超时,0立即返回 > 0等待事件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_EventWaitEx(XHANDLE xhToken, int nPoolIndex, int nTimeOut = -1);
/********************************************************************
函数名称：HttpProtocol_Server2_EventActive
函数功能：手动激活一次事件
 参数.一：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布池索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_Server2_EventActiveEx(XHANDLE xhToken, int nPoolIndex);
/*********************************************************************************
*                          HTTP服务导出帮助函数                                *
*********************************************************************************/
/********************************************************************
函数名称：HttpProtocol_ServerHelp_GetField
函数功能：获取协议头中协议字段内容
 参数.一：pppSt_ListHttpHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入协议头字段,此内存由用户申请和释放
 参数.二：nListCount
  In/Out：In
  类型：三级指针
  可空：N
  意思：协议头字段个数
 参数.三：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的字段名称，比如：Content-Type
 参数.四：ptszKey
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的值
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_GetField(CHAR * **pppSt_ListHttpHdr, int nListCount,LPCSTR lpszValue,CHAR *ptszKey);
/********************************************************************
函数名称：HttpProtocol_ServerHelp_GetUrlApi
函数功能：通过URL字段分别获取他们的值
 参数.一：lpszHdr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入获取到的HTTP头字段，如：POST /Api/BackService/GetTask HTTP/1.1
 参数.二：ptszApiType
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的API类型
 参数.三：ptszApiVer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的API版本
 参数.四：ptszApiName
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的API名称
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_GetUrlApi(LPCSTR lpszHdr, CHAR * ptszApiType, CHAR * ptszApiVer = NULL, CHAR * ptszApiName = NULL);
/********************************************************************
函数名称：HttpProtocol_ServerHelp_GetAuthInfo
函数功能：获取鉴权信息
 参数.一：pppSt_ListHttpHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入HTTP返回的字段列表,此内存由用户申请和释放
 参数.二：nListCount
  In/Out：In
  类型：整数型指针
  可空：N
  意思：输入头字段个数
 参数.三：ptszAuthStr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的验证信息内容
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的验证内容长度
 参数.五：pInt_AuthType
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出验证模式1 BASIC 2 DIGEST
返回值
  类型：逻辑型
  意思：是否成功
备注：通过OPenSsl_Codec_Base64 解码得到用户名和密码
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_GetAuthInfo(CHAR * **pppSt_ListHttpHdr, int nListCount, CHAR * ptszAuthStr, int* pInt_MsgLen, int* pInt_AuthType);
/********************************************************************
函数名称：HttpProtocol_ServerHelp_GetParament
函数功能：获得参数
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获得的参数集
 参数.二：pppSt_ListParament
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出HTTP参数列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
 参数.四：ptszUrl
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出之前的URL
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_GetParament(LPCSTR lpszUrl, CHAR*** pppSt_ListParament, int* pInt_ListCount, CHAR* ptszUrl = NULL);
/********************************************************************
函数名称：HttpProtocol_ServerHelp_HTTP2HdrConvert
函数功能：HTTP2头转换获取函数
 参数.一：pSt_HTTPRequest
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入
 参数.二：pppSt_ListHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入HEADER列表
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_HTTP2HdrConvert(RFCCOMPONENTS_HTTP_REQPARAM* pSt_HTTPRequest, RFCCOMPONENTS_HTTP2_HPACK*** pppSt_ListHdr, int nListCount);
/********************************************************************
函数名称：HttpProtocol_ServerHelp_ShortLink
函数功能：短连接生成器
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要生成的URL,全路径
 参数.二：ptszDomainUrl
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出生成的URL
 参数.三：ptszDomainKey
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出生成的URL的后续KEY,如果为NULL,参数二将会是完成的短连接地址
 参数.四：nSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入KEY的个数
 参数.五：lpszRepDomain
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入替换的URL域名,如果你有短连接URL可以使用此函数替换
返回值
  类型：逻辑型
  意思：是否成功
备注：输入的http://bbs.xyry.org/forum.php?mod=viewthread&tid=2&extra=page%3D1
      生成的http://bbs.xyry.org/asd21d 参数二:http://bbs.xyry.org 参数三:asd21d
      使用方式:http://bbs.xyry.org/asd21d 与 http://bbs.xyry.org/forum.php?mod=viewthread&tid=2&extra=page%3D1 进行数据映射并且写到数据库
      客户访问:http://bbs.xyry.org/asd21d 后302或者301 重定向到原始地址即可
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_ShortLink(LPCSTR lpszUrl, CHAR* ptszDomainUrl, CHAR* ptszDomainKey = NULL, int nSize = 6, LPCSTR lpszRepDomain = NULL);
/********************************************************************
函数名称：HttpProtocol_ServerHelp_CookieParse
函数功能：解析请求的Cookie
 参数.一：ppptszHttpHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要解析的HTTP头列表
 参数.二：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入头列表个数
 参数.三：pppSt_HttpCookie
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析的HTTP请求的信息列表,这个解构复用了HTTP2PACK的结构,大小字段为0不做填充
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出COOKIE个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerHelp_CookieParse(CHAR*** ppptszHttpHdr, int nListCount, RFCCOMPONENTS_HTTP2_HPACK*** pppSt_HttpCookie, int* pInt_ListCount);
/*********************************************************************************
*                          HTTP服务导出配置函数                                  *
*********************************************************************************/
/********************************************************************
函数名称：HttpProtocol_ServerConfig_InitCode
函数功能：初始化HTTP状态码映射表
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入CODE映射表文件所在路径
 参数.二：bLine
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否添加换行符,默认添加
返回值
  类型：逻辑型
  意思：是否成功
备注：不需要销毁，如果状态码文件改变，可以重新加载进行动态更改
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerConfig_InitCode(LPCSTR lpszFile, BOOL bLine = TRUE);
/********************************************************************
函数名称：HttpProtocol_ServerConfig_InitMime
函数功能：初始化HTTP MIME类型
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入映MIME映射文件所在路径
 参数.二：bLine
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：获取的时候是否自动添加换行
 参数.三：bHDRStr
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否添加content-type的表示头
 参数.四：lpszCharSet
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入服务器操作的字符编码
返回值
  类型：逻辑型
  意思：是否成功
备注：不需要销毁，如果MIME文件改变，可以重新加载进行动态更改
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerConfig_InitMime(LPCSTR lpszFile, BOOL bLine = TRUE, BOOL bHDRStr = TRUE, LPCSTR lpszCharSet = ("UTF-8"));
/********************************************************************
函数名称：HttpProtocol_ServerConfig_GetCode
函数功能：通过HTTP CODE来获得返回的状态信息字符串
 参数.一：nHttpCode
  In/Out：In
  类型：整数型
  可空：N
  意思：输入HTTP状态码
 参数.二：ptszApiType
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出状态码对应字符串信息
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerConfig_GetCode(int nHttpCode, CHAR* ptszCodeMsg);
/********************************************************************
函数名称：HttpProtocol_ServerConfig_GetMime
函数功能：通过MIME类型来获得返回的MIME描述字符串
 参数.一：lpszMimeType
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：类型名称，比如 html jpeg bin exe等等
 参数.二：ptszMimeDes
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出对应的MIMEHTTP描述符
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL HttpProtocol_ServerConfig_GetMime(LPCSTR lpszMimeType, CHAR* ptszMimeDes);