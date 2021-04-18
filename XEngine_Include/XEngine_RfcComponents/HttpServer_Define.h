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
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
//HTTP发送参数
typedef struct
{
    int nHttpCode;                                       //返回的状态码，必须设置
    BOOL bIsClose;                                       //是否启用关闭标志位
    BOOL bChunked;                                       //是否开启CHUNK传输模式，分割需要自己分割，如果块发送完毕，你需要这个值为真并且消息大小设置为0在发送一次给用户
    BOOL bChunkFirst;                                    //如果开启了CHUNK必须指明这个包是否是第一个包
    BOOL bGZip;                                          //数据是否使用了GZIP压缩（用户自己压缩，使用函数HelpCompress_Algorithm_GZipCompress进行压缩）
    BOOL bAuth;                                          //请求鉴权开关
    CHAR tszMimeType[64];                               //mime类型,如果为空，将使用 html
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
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD HttpServer_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          简单的HTTP服务区导出函数                              *
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
  类型：常量字符指针
  可空：N
  意思：HTTPMIME配置文件位置
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_HttpServer_Init(LPCSTR lpszCodeFile,LPCSTR lpszMimeFile, int nPoolCount = 0);
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
extern "C" BOOL RfcComponents_HttpServer_Destroy(BOOL bActiveEvent = TRUE);
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
extern "C" BOOL RfcComponents_HttpServer_CreateClient(LPCSTR lpszClientAddr, int nPoolIndex = -1);
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
  意思：添加响应的内容
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
extern "C" BOOL RfcComponents_HttpServer_SendMsg(CHAR *ptszMsgBuffer, int *pInt_Len, RFCCOMPONENTS_HTTP_HDRPARAM *pSt_HdrParam, LPCSTR lpszBody = NULL, int nBodyLen = 0, LPCSTR lpszHdr = NULL);
/********************************************************************
函数名称：RfcComponents_HttpServer_GetClient
函数功能：从队列中获取一个待处理的客户端的包
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的包的客户端地址
 参数.二：pppszListHdrField
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出解析好的HTTP协议头请求字段
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出协议字段个数
 参数.四：ptszHdrRequest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出HTTP协议头请求的URL
 参数.五：ptszBodyBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出他的后续数据包
 参数.六：pInt_BodyLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入BODY缓冲区大小，输出真实缓冲区大小
返回值
  类型：逻辑型
  意思：是否获取成功
备注：参数二的内存需要调用基础库的释放内存函数BaseLib_OperatorMemory_Free
*********************************************************************/
extern "C" BOOL RfcComponents_HttpServer_GetClient(LPCSTR lpszClientAddr, CHAR * **pppszListHdrField, int* pInt_ListCount, RFCCOMPONENTS_HTTP_REQPARAM *pSt_ReqParam, CHAR *ptszBodyBuffer, int *pInt_BodyLen);
//随机取包函数
extern "C" BOOL RfcComponents_HttpServer_GetRandom(CHAR *ptszClientAddr, CHAR * **pppszListHdrField, int* pInt_ListCount, RFCCOMPONENTS_HTTP_REQPARAM *pSt_ReqParam, CHAR *ptszBodyBuffer, int *pInt_BodyLen);
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
extern "C" BOOL RfcComponents_HttpServer_GetList(RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount, int nPoolIndex = 0, int nPoolCount = 4);
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
extern "C" BOOL RfcComponents_HttpServer_GetPool(int nPoolIndex, RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount);
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
extern "C" BOOL RfcComponents_HttpServer_InserQueue(LPCSTR lpszClientAddr,LPCSTR lpszMsgBuffer,int nMsgLen);
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
extern "C" BOOL RfcComponents_HttpServer_CloseClinet(LPCSTR lpszClientAddr);
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
extern "C" BOOL RfcComponents_HttpServer_EventWait(int nPoolIndex = -1, int nTimeOut = -1);
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
extern "C" BOOL RfcComponents_HttpServer_EventActive(int nPoolIndex = -1);
//扩展类,支持多个HTTP服务器
extern "C" XHANDLE RfcComponents_HttpServer_InitEx(LPCSTR lpszCodeFile, LPCSTR lpszMimeFile, int nPoolCount = 0);
extern "C" BOOL RfcComponents_HttpServer_DestroyEx(XHANDLE xhToken, BOOL bActiveEvent = TRUE);
extern "C" BOOL RfcComponents_HttpServer_CreateClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, int nPoolIndex = -1);
extern "C" BOOL RfcComponents_HttpServer_SendMsgEx(XHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_Len, RFCCOMPONENTS_HTTP_HDRPARAM* pSt_HdrParam, LPCSTR lpszBody = NULL, int nBodyLen = 0, LPCSTR lpszHdr = NULL);
extern "C" BOOL RfcComponents_HttpServer_GetClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr, CHAR * **pppszListHdrField, int* pInt_ListCount, RFCCOMPONENTS_HTTP_REQPARAM* pSt_ReqParam, CHAR* ptszBodyBuffer, int* pInt_BodyLen);
extern "C" BOOL RfcComponents_HttpServer_GetRandomEx(XHANDLE xhToken, CHAR* ptszClientAddr, CHAR * **pppszListHdrField, int* pInt_ListCount, RFCCOMPONENTS_HTTP_REQPARAM* pSt_ReqParam, CHAR* ptszBodyBuffer, int* pInt_BodyLen);
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
extern "C" BOOL RfcComponents_HttpServer_GetPoolEx(XHANDLE xhToken, int nPoolIndex, RFCCOMPONENTS_HTTP_PKTCLIENT * **pppSt_ListClient, int* pInt_ListCount);
extern "C" BOOL RfcComponents_HttpServer_InserQueueEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen);
extern "C" BOOL RfcComponents_HttpServer_CloseClinetEx(XHANDLE xhToken, LPCSTR lpszClientAddr);
extern "C" BOOL RfcComponents_HttpServer_EventWaitEx(XHANDLE xhToken, int nPoolIndex = -1, int nTimeOut = -1);
extern "C" BOOL RfcComponents_HttpServer_EventActiveEx(XHANDLE xhToken, int nPoolIndex = -1);
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
 参数.三：ptszUser
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的用户名
 参数.四：ptszPass
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_HttpHelp_GetAuthInfo(CHAR * **pppSt_ListHttpHdr, int nListCount, CHAR *ptszUser, CHAR *ptszPass);
/********************************************************************
函数名称：RfcComponents_HttpHelp_RegisterProcess
函数功能：为HTTP服务器注册一个新的处理程序
 参数.一：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要注册的处理程序名称(比如 HTTP协议头字段为 XPROCESS-NAME : XCGI，XCGI就是你注册的名称)
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
返回值
  类型：逻辑型
  意思：是否注册成功
备注：帮助内容，请访问：http://bbs.xyry.org/forum.php?mod=viewthread&tid=43&extra=page%3D1
*********************************************************************/
extern "C" BOOL RfcComponents_HttpHelp_RegisterProcess(LPCSTR lpszProcessName,LPCSTR lpszProcessPath,RFCCOMPONENTS_HTTP_REGPROCESS *pSt_RegProcess);
/********************************************************************
函数名称：RfcComponents_HttpHelp_CancelProcess
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
extern "C" BOOL RfcComponents_HttpHelp_CancelProcess(LPCSTR lpszProcessName);
/********************************************************************
函数名称：RfcComponents_HttpHelp_HandleProcess
函数功能：为HTTP服务器注册一个新的处理程序
 参数.一：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要处理的程序类型名称，比如XCGI
 参数.二：pInt_HttpCode
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出程序需要返回的HTTP状态码
 参数.三：ptszMiniType
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出程序需要返回的MINI类型
 参数.四：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出注册处理程序返回的内容，如果返回的大小为0,这个参数将没有值！
 参数.五：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出返回内容的大小，如果这个值为0,那么表示程序不需要返回内容，只需要头
 参数.六：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入这次请求的客户端地址信息，如果为NULL，就算处理程序设置了需要也不会报错，而是忽略这个参数(下同)
 参数.七：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入客户端请求的URL信息
 参数.八：lpszHttpBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入客户端请求的内容
 参数.九：nBodyLen
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入客户端请求的内容大小
返回值
  类型：逻辑型
  意思：是否处理成功
备注：你的程序需要接受到的参数是：app.exe ip:port http://www.xyry.org/api 5 hello
     你需要返回的内容是：200\r\nhtml\r\n5\r\nworld
*********************************************************************/
extern "C" BOOL RfcComponents_HttpHelp_HandleProcess(LPCSTR lpszProcessName,int *pInt_HttpCode,CHAR *ptszMiniType,CHAR *ptszMsgBuffer,int *pInt_Len,LPCSTR lpszClientAddr = NULL,LPCSTR lpszUrl = NULL,LPCSTR lpszHttpBody = NULL,int nBodyLen = 0);
/********************************************************************
函数名称：RfcComponents_HttpHelp_ExecCgi
函数功能：执行一个标准的CGI程序
 参数.一：pSt_HttpCgi
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入设置的CGI环境变量
 参数.二：ptszTitle
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出CGI标题,如果有的话
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出CGI的内容
 参数.四：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出内容大小,如果是0,表示CGI程序没有内容
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数仅支持标准的HTTP CGI输入输出.
*********************************************************************/
extern "C" BOOL RfcComponents_HttpHelp_ExecCgi(RFCCOMPONENTS_HTTP_CGIINFO *pSt_HttpCgi, CHAR *ptszTitle, CHAR *ptszMsgBuffer, int *pInt_Len);
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
