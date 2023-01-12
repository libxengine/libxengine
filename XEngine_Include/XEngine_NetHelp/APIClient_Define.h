#pragma once
/********************************************************************
//    Created:     2023/01/06  11:05:07
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIClient\APIClient_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIClient
//    File Base:   APIClient_Define
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     网络客户端导出函数
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    导出的回调函数
//////////////////////////////////////////////////////////////////////////
//POP3回调，如果你设置的索引号为0，那么这个参数将导出邮件个数，第二个参数无效，第三个参数是获取到的内容，内容格式是 1 3333（第一封邮件，大小3333）以换行符为分割，输出多少封，第四个参数无效。
//否则 第二个参数表明是否收取成功，为假表示收取失败，第三个参数是邮件内容，第四个参数是内容大小。
typedef void(CALLBACK* CALLBACK_XENGINE_NETHELP_APICLIENT_EMAIL)(XHANDLE xhToken, LPCSTR lpszMsgBuffer, int nMsgLen, LPVOID lParam);
//HTTP GET请求的CHUNKED数据回调,参数:,自定义参数
typedef void(CALLBACK* CALLBACK_XENGINE_NETHELP_APICLIENT_HTTP_CHUNKED)(XNETHANDLE xhToken, LPVOID lpszMsgBuffer, int nMsgLen, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
//HTTP访问参数
typedef struct 
{
    CHAR tszAuthStr[MAX_PATH];                                           //设置用户验证信息,用户名:密码
    CHAR tszProxyStr[MAX_PATH];                                          //设置代理,比如:socks5:// 或者 https://
    CHAR tszCertFile[MAX_PATH];                                          //证书文件,不使用将不验证DNS
    BOOL bHTTP2Enable;                                                   //是否启用HTTP2,HTTP2必须使用SSL
    BOOL bIPVisit;                                                       //启用SSL的IP访问
    int nTimeConnect;                                                    //连接超时时间,毫秒
    int nTimeOperator;                                                   //发送接受超时时间,毫秒
    int nTimeTrans;                                                      //5秒传输最小大小,BYTE
}NETHELP_HTTPCLIENT;
//邮件内容构造
typedef struct
{
	CHAR tszServiceAddr[MAX_PATH];                                        //服务器地址 smtp://mainserver.example.net:587
	CHAR tszCertFile[MAX_PATH];                                           //PEM个人证书路径，如果为NULL，将不使用SSL传送
	CHAR tszUserName[MAX_PATH];                                           //发送的用户名 486179@qq.com
	CHAR tszPassWord[MAX_PATH];                                           //你的邮箱密码 486179
	CHAR tszFromAddr[MAX_PATH];                                           //回复地址，也可以是你的用户名，有的邮箱如果有防洪水邮件会验证你的回复地址，如果你传递假的会造成发送失败
	int nIndex;                                                           //要收取第几个文件，为0表示获取邮件多少封
}NETHELP_EMAILCLIENT;
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD APIHelp_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          EMail请求导出函数                                     *
*********************************************************************************/
/********************************************************************
函数名称：APIClient_EMail_Init
函数功能：初始化一个电子邮件客户端
 参数.一：pSt_EmailInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：电子邮箱的常规信息
返回值
  类型：句柄型
  意思：成功返回句柄,失败返回NULL
备注：初始化的客户端只能是SMTP或者POP3,不能同时使用
*********************************************************************/
extern "C" XHANDLE APIClient_EMail_Init(NETHELP_EMAILCLIENT* pSt_EMailClient);
/********************************************************************
函数名称：APIClient_EMail_Send
函数功能：发送已经准备好的电子邮件
 参数.一：xhToken
  In/Out：In
  类型：X网络句柄
  可空：N
  意思：要发送的指定客户端
 参数.二：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：对方的邮件地址,使用;符号分割多个
 参数.三：lpszSubJect
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：邮件标题
 参数.四：lpszPayLoad
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：邮件正文，换行符\n
返回值
  类型：逻辑型
  意思：是否成功发送
备注：
*********************************************************************/
extern "C" BOOL APIClient_EMail_Send(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszSubJect, LPCSTR lpszPayLoad);
/********************************************************************
函数名称：APIClient_EMail_Recv
函数功能：开始接受电子邮件
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要接受的网络客户端
 参数.二：fpCall_EMailClient
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：接受数据回调
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功接受
备注：
*********************************************************************/
extern "C" BOOL APIClient_EMail_Recv(XHANDLE xhToken, CALLBACK_XENGINE_NETHELP_APICLIENT_EMAIL fpCall_EMailClient, LPVOID lParam = NULL);
/********************************************************************
函数名称：APIClient_EMail_Close
函数功能：关闭客户端
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的指定客户端句柄
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL APIClient_EMail_Close(XHANDLE xhToken);
/*********************************************************************************
*                          HTTP请求导出函数                                      *
*********************************************************************************/
/********************************************************************
函数名称：APIClient_Http_Request
函数功能：自定义HTTP请求
 参数.一：lpszMethodName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：请求的方法,POST GET HEAD 等...
 参数.二：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交到的URL地址
 参数.三：lpszBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：提交的内容,可以输入NULL
 参数.四：pInt_ReponseCode
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出HTTP 返回的状态码
 参数.五：pptszBody
  In/Out：Out
  类型：字符指针的指针
  可空：Y
  意思：输出获取到的内容,需要手动释放内存
 参数.六：pInt_BLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入要传输的HTTP负载大小(0自动),输出HTTP获取到的负载内容大小
 参数.七：lpszCustomHdr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入自定义HTTP头字段
 参数.八：ptszHdr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的头
 参数.九：pSt_HTTPParam
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：HTTP参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIClient_Http_Request(LPCSTR lpszMethodName, LPCSTR lpszUrl, LPCSTR lpszBody = NULL, int* pInt_ReponseCode = NULL, CHAR * *pptszBody = NULL, int* pInt_BLen = NULL, LPCSTR lpszCustomHdr = NULL, CHAR * ptszHdr = NULL, NETHELP_HTTPCLIENT * pSt_HTTPParam = NULL);
/********************************************************************
函数名称：APIClient_Http_Create
函数功能：创建一个HTTP请求
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建成功的句柄
 参数.二：fpCall_ChunkedRecv
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：如果有值表示使用CHUNKED模式接受数据
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIClient_Http_Create(XNETHANDLE * pxhToken, CALLBACK_XENGINE_NETHELP_APICLIENT_HTTP_CHUNKED fpCall_ChunkedRecv = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：APIClient_Http_SetParam
函数功能：设置HTTP参数
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的HTTP句柄
 参数.二：pSt_HTTPParam
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入HTTP参数
返回值
  类型：逻辑型
  意思：是否成功
备注：按照服务器要求设置请求
*********************************************************************/
extern "C" BOOL APIClient_Http_SetParam(XNETHANDLE xhToken, NETHELP_HTTPCLIENT * pSt_HTTPParam);
/********************************************************************
函数名称：APIClient_Http_SetUrl
函数功能：设置必要的请求信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的HTTP句柄
 参数.二：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送请求的地址
 参数.三：lpszMethod
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要请求的方法.POST,GET,PUT...等等
 参数.四：lpszCustomBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入请求的附加数据
 参数.五：lpszCustomHdr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入请求的自定义头\r\n分割
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIClient_Http_SetUrl(XNETHANDLE xhToken, LPCSTR lpszUrl, LPCSTR lpszMethod, LPCSTR lpszCustomBody = NULL, LPCSTR lpszCustomHdr = NULL);
/********************************************************************
函数名称：APIClient_Http_Excute
函数功能：执行一个请求并且获得一段数据
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的HTTP句柄
 参数.二：pptszBody
  In/Out：Out
  类型：字符指针的指针
  可空：Y
  意思：输出获取到的HTTP负载内容,此内容需要手动释放内存
 参数.三：pInt_BLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出负载内容大小
 参数.四：ptszHdr
  In/Out：In
  类型：字符指针
  可空：Y
  意思：输出负载的HTTP头缓冲区
 参数.五：pInt_ReponseCode
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出HTTP状态码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIClient_Http_Excute(XNETHANDLE xhToken, CHAR * *pptszBody = NULL, int* pInt_BLen = NULL, CHAR * ptszHdr = NULL, int* pInt_ReponseCode = NULL);
/********************************************************************
函数名称：APIClient_Http_Close
函数功能：关闭HTTP请求
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIClient_Http_Close(XNETHANDLE xhToken);