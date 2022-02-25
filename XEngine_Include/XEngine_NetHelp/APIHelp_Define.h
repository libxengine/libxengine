#pragma once
/********************************************************************
//	Created:	2014/1/27  11:47
//	File Name: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_NetHelp/NetEngine_APIHelp/APIHelp_Define.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_NetHelp/NetEngine_APIHelp/
//	File Base:	APIHelp_Define.h
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎) For Linux
//	Author:		dowflyon
//	Purpose:	导出的网络帮助API函数库
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的枚举型
//////////////////////////////////////////////////////////////////////////
//访问类型
typedef enum en_APIHelp_DomainType
{
    ENUM_APIHELP_DOMAIN_TYPE_UNKOW = 0,                                      //未知类型
    ENUM_APIHELP_DOMAIN_TYPE_HTTP = 1,                                       //HTTP访问
    ENUM_APIHELP_DOMAIN_TYPE_HTTPS = 2                                       //HTTPS访问
}ENUM_APIHELP_DOMAINTYPE, *LPENUM_APIHELP_DOMAINTYPE;
//////////////////////////////////////////////////////////////////////////
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
//URL地址信息
typedef struct tag_APIHelp_Domain
{
    int nPort;                                                           //端口
    CHAR tszTopDomain[MAX_PATH];                                         //顶级域名
    CHAR tszMainDomain[MAX_PATH];                                        //主域名
    CHAR tszDomainName[MAX_PATH];                                        //域名名称
    CHAR tszSubDomain[MAX_PATH];                                         //子域名
}APIHELP_DOMAIN, *LPAPIHELP_DOMAIN;
//IP地址信息
typedef struct 
{
    CHAR tszIPAddr[128];                                                 //IP地址
    CHAR tszIPCountry[128];                                              //国家/地区
    CHAR tszIPProvince[128];                                             //省/自治区
    CHAR tszIPCity[128];                                                 //市
    CHAR tszIPCounty[128];                                               //县
    CHAR tszIPAddress[128];                                              //详细地址
    CHAR tszIPISP[128];                                                  //运营商
    CHAR tszIPTime[128];                                                 //数据库日期
}APIHELP_IPADDRINFO, * LPAPIHELP_IPADDRINFO;
//////////////////////////////////////////////////////////////////////////
//                        导出的回调函数
//////////////////////////////////////////////////////////////////////////
//HTTP GET请求的CHUNKED数据回调,参数:,自定义参数
typedef void(CALLBACK* CALLBACK_XENGINE_APIHELP_HTTP_CHUNKED_RECV)(LPVOID lpszMsgBuffer, int nMsgLen, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD APIHelp_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          URL解析器导出的函数                                   *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_Domain_GetInfo
函数功能：获取URL信息
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：URL地址
 参数.二：pSt_APIUrl
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出解析完毕的URL结构
 参数.三：penUrlType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：导出获取到的访问类型
 参数.四：ptszUrlPath
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出域名的后续URL路径
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_Domain_GetInfo(LPCSTR lpszUrl, APIHELP_DOMAIN *pSt_APIUrl, ENUM_APIHELP_DOMAINTYPE *penUrlType, CHAR *ptszUrlPath = NULL);
/********************************************************************
函数名称：APIHelp_Domain_IsEMailAddr
函数功能：判断字符串是否是合法的EMAIL地址
 参数.一：lpszEMailAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要判断的缓冲区
返回值
  类型：逻辑型
  意思：返回真表示是,假不是
备注：
*********************************************************************/
extern "C" BOOL APIHelp_Domain_IsEMailAddr(LPCSTR lpszEMailAddr);
/*********************************************************************************
*                          HTTP请求导出函数                                      *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_HttpRequest_SetGlobalTime
函数功能：设置全局超时时间
 参数.一：nConnectTime
  In/Out：In
  类型：整数型
  可空：Y
  意思：连接超时时间,单位秒-1表示默认,0表示立即返回
 参数.二：nOperatorTime
  In/Out：In
  类型：整数型
  可空：Y
  意思：数据交换超时时间
 参数.三：nTransBytes
  In/Out：In
  类型：整数型
  可空：Y
  意思：5秒内,每秒小于这个值,认为超时
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_SetGlobalTime(int nConnectTime = -1, int nOperatorTime = -1, int nTransBytes = -1);
/********************************************************************
函数名称：APIHelp_HttpRequest_Post
函数功能：提交一段POST请求
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交到的URL地址
 参数.二：lpszBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：提交的内容,可以输入NULL
 参数.三：pInt_ReponseCode
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出HTTP 返回的状态码
 参数.四：pptszBody
  In/Out：Out
  类型：字符指针的指针
  可空：Y
  意思：输出获取到的内容,此内容需要手动释放内存
 参数.五：pInt_BLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出HTTP负载内容大小
 参数.六：lpszCustomHdr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入自定义HTTP头字段
 参数.七：ptszHdr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的头
 参数.八：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权所需要的用户名
 参数.九：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权所需要的密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_Post(LPCSTR lpszUrl, LPCSTR lpszBody = NULL, int* pInt_ReponseCode = NULL, CHAR * *pptszBody = NULL, int* pInt_BLen = NULL, LPCSTR lpszCustomHdr = NULL, CHAR * ptszHdr = NULL, LPCSTR lpszUser = NULL, LPCSTR lpszPass = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_Get
函数功能：提交一段GET请求
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交到的URL地址
 参数.四：pptszBody
  In/Out：Out
  类型：字符指针的指针
  可空：Y
  意思：输出获取到的内容,此内容需要手动释放内存
 参数.三：pInt_BLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出HTTP内容大小
 参数.四：pInt_ReponseCode
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出返回的HTTP状态码
 参数.五：lpszCustomHdr
  In/Out：I
  类型：常量字符指针
  可空：Y
  意思：添加自定义协议头，如果需要的话：NetEngine_Auth_User: 123123aa\r\nNetEngine_Auth_Pass: 123123\r\n
 参数.六：ptszHdr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的HTTP头
 参数.七：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权所需要的用户名
 参数.八：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权所需要的密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_Get(LPCSTR lpszUrl, CHAR * *pptszBody = NULL, int* pInt_BLen = NULL, int* pInt_ReponseCode = NULL, LPCSTR lpszCustomHdr = NULL, CHAR * ptszHdr = NULL, LPCSTR lpszUser = NULL, LPCSTR lpszPass = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_Create
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
extern "C" BOOL APIHelp_HttpRequest_Create(XNETHANDLE* pxhToken, CALLBACK_XENGINE_APIHELP_HTTP_CHUNKED_RECV fpCall_ChunkedRecv = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_SetUser
函数功能：可以支持基本验证和摘要算法验证
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的HTTP句柄
 参数.二：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入用户名
 参数.三：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入密码
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数只有在服务器要求的情况下才需要使用
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_SetUser(XNETHANDLE xhToken, LPCSTR lpszUser, LPCSTR lpszPass);
/********************************************************************
函数名称：APIHelp_HttpRequest_SetUrl
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
extern "C" BOOL APIHelp_HttpRequest_SetUrl(XNETHANDLE xhToken, LPCSTR lpszUrl, LPCSTR lpszMethod, LPCSTR lpszCustomBody = NULL, LPCSTR lpszCustomHdr = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_SetTime
函数功能：设置超时时间
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的HTTP句柄
 参数.二：nConnectTime
  In/Out：In
  类型：整数型
  可空：N
  意思：输入连接超时时间
 参数.三：nDataTime
  In/Out：In
  类型：整数型
  可空：N
  意思：输入数据接受数据超时时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_SetTime(XNETHANDLE xhToken, int nConnectTime, int nDataTime);
/********************************************************************
函数名称：APIHelp_HttpRequest_Excute
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
extern "C" BOOL APIHelp_HttpRequest_Excute(XNETHANDLE xhToken, CHAR * *pptszBody = NULL, int* pInt_BLen = NULL, CHAR * ptszHdr = NULL, int* pInt_ReponseCode = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_Close
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
extern "C" BOOL APIHelp_HttpRequest_Close(XNETHANDLE xhToken);
/*********************************************************************************
*                          字节序转换导出函数                                       *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_NetWork_hl64ton
函数功能：64位主机字节转网络字节序
 参数.一：ullHost
  In/Out：In
  类型：无符号64位整数
  可空：N
  意思：要转换的主机字节序
返回值
  类型：无符号64位整数
  意思：返回网络字节序
备注：
*********************************************************************/
extern "C" __int64u APIHelp_NetWork_hl64ton(__int64u ullHost);
/********************************************************************
函数名称：APIHelp_NetWork_ntohl64
函数功能：64位网络字节转主机字节序
 参数.一：ullNet
  In/Out：In
  类型：无符号64位整数
  可空：N
  意思：要转换的网络字节序
返回值
  类型：无符号64位整数
  意思：返回主机字节序
备注：
*********************************************************************/
extern "C" __int64u APIHelp_NetWork_ntohl64(__int64u ullNet);
/********************************************************************
函数名称：APIHelp_NetWork_GetIPNet
函数功能：获得网络IP地址
 参数.一：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出网络IP地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_NetWork_GetIPNet(CHAR* ptszIPAddr);
/********************************************************************
函数名称：APIHelp_NetWork_GetIPInfo
函数功能：获得IP地址信息
 参数.一：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的IP地址，支持IPV4和IPV6
 参数.二：pSt_IPInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出IP地址信息
返回值
  类型：逻辑型
  意思：是否成功
备注：此为在线版本，需要连网，离线版本可以参考IP解析服务
*********************************************************************/
extern "C" BOOL APIHelp_NetWork_GetIPInfo(LPCSTR lpszIPAddr, APIHELP_IPADDRINFO* pSt_IPInfo);