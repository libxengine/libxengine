#pragma once
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
//注册处理程序
typedef struct tag_NetHelp_APIHttp_RegProcess
{
    BOOL bAddr;                                          //给的处理程序是否包含客户端地址信息
    BOOL bMethod;                                        //是否包含方法
    BOOL bHdr;                                           //是否包含HTTP头
    BOOL bUrl;                                           //给的处理程序是否包含HTTP请求URL
    BOOL bBody;                                          //是否包含HTTP数据
}RFCCOMPONENTS_HTTP_REGPROCESS, *LPRFCCOMPONENTS_HTTP_REGPROCESS;
//CGI运行环境设置,有默认参数的可以不用填充,但是必须初始化缓冲区为\0
//你不用传递所有参数内容.如果留空的参数内容那么这个参数将不起作用
typedef struct
{
    //与请求相关的环境变量
    CHAR tszHttpProto[64];                              //通信协议,默认为HTTP/1.0
    CHAR tszHttpMethod[64];                             //请求的方法,默认为POST
    CHAR tszHttpQuery[128];                             //输入的数据，URL中问号后的内容
    CHAR tszHttpContType[128];                          //HTTP中CONTENT_TYPE的值
    CHAR tszHttpContLen[128];                           //POST方法输入的数据的字节数
    CHAR tszHttpContFile[128];                          //使用Windows HTTPd/WinCGI标准时，用来传送数据的文件名
    CHAR tszHttpDirInfo[MAX_PATH];                      //浏览器用GET方式发送数据时的附加路径
    CHAR tszHttpCgiDir[MAX_PATH];                       //CGI程序的完整路径名,不能留空,如:/usr/share/http/cgi/
    CHAR tszHttpCgiName[64];                            //所调用的CGI程序的名字,不能留空,如:cgi.sh
    //与服务器相关的环境变量
    CHAR tszHttpVersion[64];                            //CGI程序的版本，默认为:CGI/1.1
    CHAR tszHttpName[64];                               //服务器名称
    CHAR tszHttpPort[64];                               //服务器端口(整数转字符串),默认为80
    CHAR tszHttpSw[64];                                 //调用CGI程序的HTTP服务器的名称和版本号
    //与客户端相关的环境变量
    CHAR tszHttpHostUser[64];                           //发送程序的名称
    CHAR tszHttpHostName[64];                           //发送程序的主机名
    CHAR tszHttpHostAddr[64];                           //发送程序的机器的IP地址
    CHAR tszHttpAccept[MAX_PATH];                       //服务器接受的处理类型
    CHAR tszHttpAcceptEncode[MAX_PATH];                 //列出客户机支持的编码方式
    CHAR tszHttpAcceptLanguage[64];                     //表明客户机可接受语言的ISO代码
    CHAR tszHttpUserAgent[64];                          //浏览器的有关信息
    CHAR tszHttpReferer[MAX_PATH];                      //指出连接到当前文档的文档的URL
}RFCCOMPONENTS_HTTP_CGIINFO, *LPRFCCOMPONENTS_HTTP_CGIINFO;
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
    int nStreamCount;                                   //流ID所拥有个数
}RFCCOMPONENTS_HTTP2_PKTSTREAM, * LPRFCCOMPONENTS_HTTP2_PKTSTREAM;
//动态字典才有用
typedef struct
{
    CHAR tszSrcBuffer[1024];                            //原始数据区,哈夫曼编码数据
    CHAR tszDstBuffer[1024];                            //解码数据区,解码后的数据
	BOOL bHuffman;                                      //编码标志
	BYTE byLength;                                      //大小
}RFCOMPONENTS_HTTP2DYNAMIC;
//HTTP2 HPACK
typedef struct
{
    RFCOMPONENTS_HTTP2DYNAMIC st_HTTP2Name;
    RFCOMPONENTS_HTTP2DYNAMIC st_HTTP2Value;
	BYTE byFlags;                                                  //0静态,1动态,2更新
	BYTE byIndex;                                                  //索引
}RFCCOMPONENTS_HTTP2_HPACK, * LPRFCCOMPONENTS_HTTP2_HPACK;
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD HttpServer_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          HTTP服务导出函数                                      *
*********************************************************************************/
/********************************************************************
函数名称：RfcComponents_HttpServer_Init
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
extern "C" XHANDLE RfcComponents_HttpServer_InitEx(LPCSTR lpszCodeFile, LPCSTR lpszMimeFile, int nPoolCount = 0, int nLimitCount = 0, BOOL bAllowOrigin = TRUE);
/********************************************************************
函数名称：RfcComponents_HttpServer_Destroy
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
extern "C" BOOL RfcComponents_HttpServer_DestroyEx(XHANDLE xhToken, BOOL bActiveEvent = TRUE);
/********************************************************************
函数名称：RfcComponents_HttpServer_CreateClient
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
extern "C" BOOL RfcComponents_HttpServer_CreateClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nPoolIndex = -1);
/********************************************************************
函数名称：RfcComponents_HttpServer_SendMsg
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
extern "C" BOOL RfcComponents_HttpServer_SendMsgEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_Len, RFCCOMPONENTS_HTTP_HDRPARAM* pSt_HdrParam, LPCSTR lpszBody = NULL, __int64x nBodyLen = 0, LPCSTR lpszHdr = NULL);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetClient
函数功能：从队列中获取一个待处理的客户端的包
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的包的客户端地址
 参数.二：ptszBodyBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出他的后续数据包
 参数.三：pInt_BodyLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入BODY缓冲区大小，输出真实缓冲区大小
 参数.四：ptszHdrRequest
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出HTTP协议头请求的URL
 参数.五：pppszListHdr
  In/Out：Out
  类型：三级指针
  可空：Y
  意思：导出解析好的HTTP协议头请求字段
 参数.六：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出协议字段个数
返回值
  类型：逻辑型
  意思：是否获取成功
备注：倒数第二个参数的内存需要调用基础库的释放内存函数BaseLib_OperatorMemory_Free
*********************************************************************/
extern "C" BOOL RfcComponents_HttpServer_GetClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, CHAR * ptszBodyBuffer, int* pInt_BodyLen, RFCCOMPONENTS_HTTP_REQPARAM * pSt_ReqParam = NULL, CHAR * **pppszListHdr = NULL, int* pInt_ListCount = NULL);
extern "C" BOOL RfcComponents_HttpServer_GetMemoryEx(XHANDLE xhToken, LPCSTR lpszClientAddr, CHAR** pptszBodyBuffer, int* pInt_BodyLen, RFCCOMPONENTS_HTTP_REQPARAM* pSt_ReqParam = NULL, CHAR*** pppszListHdr = NULL, int* pInt_ListCount = NULL);
extern "C" BOOL RfcComponents_HttpServer_GetRandomEx(XHANDLE xhToken, CHAR* ptszClientAddr, CHAR * ptszBodyBuffer, int* pInt_BodyLen, RFCCOMPONENTS_HTTP_REQPARAM * pSt_ReqParam = NULL, CHAR * **pppszListHdr = NULL, int* pInt_ListCount = NULL);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetList
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
extern "C" BOOL RfcComponents_HttpServer_GetListEx(XHANDLE xhToken, RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount, int nPoolIndex = 0, int nPoolCount = 4);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetPool
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
extern "C" BOOL RfcComponents_HttpServer_GetPoolEx(XHANDLE xhToken, int nPoolIndex, RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_HttpServer_InserQueue
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
extern "C" BOOL RfcComponents_HttpServer_InserQueueEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RfcComponents_HttpServer_CloseClinet
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
extern "C" BOOL RfcComponents_HttpServer_CloseClinetEx(XHANDLE xhToken, LPCSTR lpszClientAddr);
/********************************************************************
函数名称：RfcComponents_HttpServer_SetRecvMode
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
extern "C" BOOL RfcComponents_HttpServer_SetRecvModeEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nRVMode = 0);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetRecvMode
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
extern "C" BOOL RfcComponents_HttpServer_GetRecvModeEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int* pInt_RVMode, int* pInt_PKCount = NULL, int* pInt_HDSize = NULL, int* pInt_PKSize = NULL);
/********************************************************************
函数名称：RfcComponents_HttpServer_EventWait
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
extern "C" BOOL RfcComponents_HttpServer_EventWaitEx(XHANDLE xhToken, int nPoolIndex = -1, int nTimeOut = -1);
/********************************************************************
函数名称：RfcComponents_HttpServer_EventActive
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
extern "C" BOOL RfcComponents_HttpServer_EventActiveEx(XHANDLE xhToken, int nPoolIndex = -1);
//////////////////////////////////////////////////////////////////////////HTTP2
/********************************************************************
函数名称：RfcComponents_Http2Server_Init
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
extern "C" XHANDLE RfcComponents_Http2Server_InitEx(int nPoolCount, int nLimitCount = 0);
/********************************************************************
函数名称：RfcComponents_Http2Server_Destroy
函数功能：销毁这个HTTP2服务器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_Http2Server_DestroyEx(XHANDLE xhToken);
/********************************************************************
函数名称：RfcComponents_Http2Server_CreateClient
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
extern "C" BOOL RfcComponents_Http2Server_CreateClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nPoolIndex = 0);
/********************************************************************
函数名称：RfcComponents_Http2Server_InsertQueueEx
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
extern "C" BOOL RfcComponents_Http2Server_InsertQueueEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RfcComponents_Http2Server_CloseClinet
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
extern "C" BOOL RfcComponents_Http2Server_CloseClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetPool
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
extern "C" BOOL RfcComponents_Http2Server_GetPoolEx(XHANDLE xhToken, int nPoolIndex, RFCCOMPONENTS_HTTP_PKTCLIENT*** pppSt_ListClient, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetPool
函数功能：获取对应池化客户端列表
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
extern "C" BOOL RfcComponents_Http2Server_GetStreamEx(XHANDLE xhToken, LPCSTR lpszClientAddr, RFCCOMPONENTS_HTTP2_PKTSTREAM*** pppSt_PKTStream, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_Http2Server_GetClient
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
  可空：N
  意思：输出客户端请求的内容,此内存需要手动删除
 参数.五：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出内容大小
 参数.六：pppSt_ListHdr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出请求的HEADER列表,此内存需要手动删除,客户端请求的实体在这里面
 参数.七：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出HEADER列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：DATA和HEADER包会分两次返回.pptszMsgBuffer一般上一个包是POST才会有值
*********************************************************************/
extern "C" BOOL RfcComponents_Http2Server_GetClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nStreamID, XENGINE_RFCCOMPONENTS_HTTP2_FRAME_TYPE * penFrameType, CHAR** pptszMsgBuffer, int* pInt_MsgLen, RFCCOMPONENTS_HTTP2_HPACK*** pppSt_ListHdr, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTSetting
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
  可空：N
  意思：输入允许的流ID大小
 参数.四：nWindowSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入允许的滑动窗口大小
 参数.五：nFrameSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入允许的每帧最大大小
返回值
  类型：逻辑型
  意思：是否成功
备注：一般用于客户端连接请求后会发送一段SETTING用作通道参数
*********************************************************************/
extern "C" BOOL RfcComponents_Http2Server_PKTSettingEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nMaxStream, int nWindowSize, int nFrameSize);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTWindow
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
extern "C" BOOL RfcComponents_Http2Server_PKTWindowEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nWindowIncrement);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTWindow
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
返回值
  类型：逻辑型
  意思：是否成功
备注：一般用于返回客户端请求在DATA之前都需要有这个内容
*********************************************************************/
extern "C" BOOL RfcComponents_Http2Server_PKTHeaderEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, RFCCOMPONENTS_HTTP_HDRPARAM* pSt_HDRParam);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTMessage
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
extern "C" BOOL RfcComponents_Http2Server_PKTMessageEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, LPCSTR lpszMsgBuffer = NULL, int nBLen = 0, BOOL bEndStream = TRUE);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTPing
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
extern "C" BOOL RfcComponents_Http2Server_PKTPingEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCSTR lpszOPData, BOOL bAck = TRUE);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTGoaway
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
extern "C" BOOL RfcComponents_Http2Server_PKTGoawayEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, int nErrorCode = 0);
/********************************************************************
函数名称：RfcComponents_Http2Server_PKTPush
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
extern "C" BOOL RfcComponents_Http2Server_PKTPushEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nStreamID, LPCSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：RfcComponents_Http2Server_EventWait
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
extern "C" BOOL RfcComponents_Http2Server_EventWaitEx(XHANDLE xhToken, int nPoolIndex, int nTimeOut = -1);
/********************************************************************
函数名称：RfcComponents_Http2Server_EventActive
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
extern "C" BOOL RfcComponents_Http2Server_EventActiveEx(XHANDLE xhToken, int nPoolIndex);
/*********************************************************************************
*                          HTTP服务导出帮助函数                                *
*********************************************************************************/
/********************************************************************
函数名称：RfcComponents_HttpHelp_GetField
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
extern "C" BOOL RfcComponents_HttpHelp_GetField(CHAR * **pppSt_ListHttpHdr, int nListCount,LPCSTR lpszValue,CHAR *ptszKey);
/********************************************************************
函数名称：RfcComponents_HttpHelp_GetUrlApi
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
 参数.三：ptszApiName
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的API名称
 参数.四：ptszApiVer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的API版本
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_HttpHelp_GetUrlApi(LPCSTR lpszHdr,CHAR *ptszApiType,CHAR *ptszApiName = NULL,CHAR *ptszApiVer = NULL);
/********************************************************************
函数名称：RfcComponents_HttpHelp_GetAuthInfo
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
extern "C" BOOL RfcComponents_HttpHelp_GetAuthInfo(CHAR * **pppSt_ListHttpHdr, int nListCount, CHAR * ptszAuthStr, int* pInt_MsgLen, int* pInt_AuthType);
/********************************************************************
函数名称：RfcComponents_HttpHelp_GetParament
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
extern "C" BOOL RfcComponents_HttpHelp_GetParament(LPCSTR lpszUrl, CHAR*** pppSt_ListParament, int* pInt_ListCount, CHAR* ptszUrl = NULL);
/*********************************************************************************
*                          HTTP服务导出配置函数                                  *
*********************************************************************************/
/********************************************************************
函数名称：RfcComponents_HttpConfig_InitCode
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
extern "C" BOOL RfcComponents_HttpConfig_InitCode(LPCSTR lpszFile, BOOL bLine = TRUE);
/********************************************************************
函数名称：RfcComponents_HttpConfig_InitMime
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
  意思：是否添加换行符,默认添加
返回值
  类型：逻辑型
  意思：是否成功
备注：不需要销毁，如果MIME文件改变，可以重新加载进行动态更改
*********************************************************************/
extern "C" BOOL RfcComponents_HttpConfig_InitMime(LPCSTR lpszFile, BOOL bLine = TRUE);
/********************************************************************
函数名称：RfcComponents_HttpConfig_InitPack
函数功能：初始化HTTP2.HPACK静态表
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入静态表地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_HttpConfig_InitPack(LPCSTR lpszFile);
/********************************************************************
函数名称：RfcComponents_HttpConfig_GetCode
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
extern "C" BOOL RfcComponents_HttpConfig_GetCode(int nHttpCode, CHAR* ptszCodeMsg);
/********************************************************************
函数名称：RfcComponents_HttpConfig_GetMime
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
extern "C" BOOL RfcComponents_HttpConfig_GetMime(LPCSTR lpszMimeType, CHAR* ptszMimeDes);
/********************************************************************
函数名称：RfcComponents_HttpConfig_GetPack
函数功能：通过索引,获取值
 参数.一：nIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入静态表索引
 参数.二：pSt_HTTP2Pack
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出获取到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_HttpConfig_GetPack(int nIndex, RFCCOMPONENTS_HTTP2_HPACK* pSt_HTTP2Pack);
/*********************************************************************************
*                          HTTP注册程序导出                                      *
*********************************************************************************/
/********************************************************************
函数名称：RfcComponents_HttpExec_RegisterProcess
函数功能：为HTTP服务器注册一个新的处理程序
 参数.一：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要注册的处理程序名称.通过URL来确定,url:port/api/name 会获取api的名称作为注册程序
 参数.二：lpszProcessPath
  In/Out：Out
  类型：In
  可空：N
  意思：处理程序所在位置
 参数.三：pSt_RegProcess
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：处理程序配置属性
 参数.四：bModule
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真为模块程序(dll,so),为假为执行程序(exe,elf)
返回值
  类型：逻辑型
  意思：是否注册成功
备注：可以参考:http://bbs.xyry.org/forum.php?mod=viewthread&tid=6
*********************************************************************/
extern "C" BOOL RfcComponents_HttpExec_RegisterProcess(LPCSTR lpszProcessName, LPCSTR lpszProcessPath, RFCCOMPONENTS_HTTP_REGPROCESS * pSt_RegProcess, BOOL bModule = FALSE);
/********************************************************************
函数名称：RfcComponents_HttpExec_CancelProcess
函数功能：为HTTP服务器注销一个处理程序
 参数.一：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要注销的处理程序名称
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_HttpExec_CancelProcess(LPCSTR lpszProcessName);
/********************************************************************
函数名称：RfcComponents_HttpExec_HandleProcess
函数功能：为HTTP执行一个注册的小程序
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入这次请求的客户端地址信息
 参数.二：pSt_HTTPParam
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入请求的HTTP参数
 参数.三：pppszListHdr
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入请求的HTTP头列表
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入头列表个数
 参数.五：lpszHttpBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入客户端请求的内容
 参数.六：nBodyLen
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入客户端请求的内容大小
 参数.七：pInt_HttpCode
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出程序需要返回的HTTP状态码
 参数.八：ptszMiniType
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出程序需要返回的MINI类型
 参数.九：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出注册处理程序返回的内容，如果返回的大小为0,这个参数将没有值！
 参数.十：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出返回内容的大小，如果这个值为0,那么表示程序不需要返回内容，只需要头
返回值
  类型：逻辑型
  意思：是否处理成功
备注：你的程序需要接受到的参数是：app.exe ip:port post http://www.xyry.org/api 5 hello
      你需要printf的内容是：200\r\nhtml\r\n5\r\nworld 或者只返回200
      如果失败,说明这个URL不是注册程序需要处理的,你需要在自己代码处理
*********************************************************************/
extern "C" BOOL RfcComponents_HttpExec_HandleProcess(LPCSTR lpszClientAddr, RFCCOMPONENTS_HTTP_REQPARAM * pSt_HTTPParam, CHAR * **pppszListHdr, int nListCount, LPCSTR lpszHttpBody, int nBodyLen, int* pInt_HttpCode = NULL, CHAR * ptszMiniType = NULL, CHAR * ptszMsgBuffer = NULL, int* pInt_Len = NULL);