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
//IP范围分类
typedef enum en_NetHelp_APIHelp_IPAddr_Type
{
    ENUM_NETENGINE_NETHELP_APIHELP_IPADDR_TYPE_UNKNOW = 0,
    ENUM_NETENGINE_NETHELP_APIHELP_IPADDR_TYPE_A = 1,
    ENUM_NETENGINE_NETHELP_APIHELP_IPADDR_TYPE_B = 2,
    ENUM_NETENGINE_NETHELP_APIHELP_IPADDR_TYPE_C = 3,
    ENUM_NETENGINE_NETHELP_APIHELP_IPADDR_TYPE_D = 4,
    ENUM_NETENGINE_NETHELP_APIHELP_IPADDR_TYPE_E = 5
}ENUM_NETHELP_APIHELP_IPADDR_TYPE, *LPENUM_NETHELP_APIHELP_IPADDR_TYPE;
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
    CHAR tszTopDomain[MAX_PATH];                                         //顶级域名
    CHAR tszMainDomain[MAX_PATH];                                        //主域名
    CHAR tszDomainName[MAX_PATH];                                        //域名名称
    CHAR tszSubDomain[MAX_PATH];                                         //子域名
}APIHELP_DOMAIN, *LPAPIHELP_DOMAIN;
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
*                          URL解析器导出的函数                                     *
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
*                          HTTP请求导出函数                                        *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_HttpRequest_Post
函数功能：提交一段POST请求
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交到的URL地址
 参数.二：pInt_ReponseCode
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出返回的HTTP状态码
 参数.三：lpszCustomBody
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：添加自定义的协议头后续数据
 参数.四：ptszBodyBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的HTTP内容
 参数.五：pInt_BodyLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的HTTP内容数据长度
 参数.六：ptszHdrBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的HTTP头
 参数.七：pInt_HdrLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的HTTP头大小
 参数.八：lpszCustomHdr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：添加自定义协议头，如果需要的话：NetEngine_Auth_User: 123123aa\r\nNetEngine_Auth_Pass: 123123\r\n
 参数.九：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权所需要的用户名
 参数.十：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权所需要的密码
返回值
  类型：逻辑型
  意思：是否投递成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_Post(LPCSTR lpszUrl, int *pInt_ReponseCode, LPCSTR lpszCustomBody = NULL, CHAR *ptszBodyBuffer = NULL, int *pInt_BodyLen = NULL, CHAR *ptszHdrBuffer = NULL, int *pInt_HdrLen = NULL, LPCSTR lpszCustomHdr = NULL, LPCSTR lpszUser = NULL, LPCSTR lpszPass = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_Get
函数功能：提交一段GET请求
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交到的URL地址
 参数.二：pInt_ReponseCode
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出返回的HTTP状态码
 参数.三：ptszBodyBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的HTTP内容
 参数.四：pInt_BodyLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的HTTP内容数据长度
 参数.五：ptszHdrBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的HTTP头
 参数.六：pInt_HdrLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的HTTP头大小
 参数.七：lpszCustomHdr
  In/Out：I
  类型：常量字符指针
  可空：Y
  意思：添加自定义协议头，如果需要的话：NetEngine_Auth_User: 123123aa\r\nNetEngine_Auth_Pass: 123123\r\n
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
  意思：是否投递成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_Get(LPCSTR lpszUrl, int *pInt_ReponseCode, CHAR *ptszBodyBuffer, int *pInt_BodyLen, CHAR *ptszHdrBuffer = NULL, int *pInt_HdrLen = NULL, LPCSTR lpszCustomHdr = NULL, LPCSTR lpszUser = NULL, LPCSTR lpszPass = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_Custom
函数功能：提交自定义方法
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要提交的网址
 参数.二：lpszMethod
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要提交的方法.(POST GET DELETE PUT,服务器可支持的方法)
 参数.三：pInt_ReponseCode
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出HTTP返回的CODE码
 参数.四：ptszBodyBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出HTTP接受到的数据
 参数.五：pInt_BodyLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出HTTP数据长度
 参数.六：ptszHdrBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出HTTP头
 参数.七：pInt_HdrLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出HTTP头大小
 参数.八：lpszCustomHdr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入自定义头字段,使用\r\n分割
 参数.九：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权用户名
 参数.十：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：HTTP鉴权密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_Custom(LPCSTR lpszUrl, LPCSTR lpszMethod, int *pInt_ReponseCode = NULL, CHAR *ptszBodyBuffer = NULL, int *pInt_BodyLen = NULL, CHAR *ptszHdrBuffer = NULL, int *pInt_HdrLen = NULL, LPCSTR lpszCustomHdr = NULL, LPCSTR lpszUser = NULL, LPCSTR lpszPass = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_ChunkedOPen
函数功能：打开一个CHUNKED网页
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要GET的网页地址
 参数.二：fpCall_ChunkedRecv
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
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE APIHelp_HttpRequest_ChunkedOPen(LPCSTR lpszUrl, CALLBACK_XENGINE_APIHELP_HTTP_CHUNKED_RECV fpCall_ChunkedRecv, LPVOID lParam = NULL);
/********************************************************************
函数名称：APIHelp_HttpRequest_ChunkedClose
函数功能：关闭Chunked回调
 参数.一：pxhChunked
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要关闭的回调句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL APIHelp_HttpRequest_ChunkedClose(XHANDLE pxhChunked);
/*********************************************************************************
*                          IP地址操作库导出函数                                   *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_IPAddr_IsIPV4Addr
函数功能：判断一个缓冲区是否为IP地址
 参数.一：lpszBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要判断的缓冲区
 参数.二：pSt_LibAddr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：导出IP分割的地址值
 参数.三：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：Y
  意思：导出此IP地址的分类
返回值
  类型：逻辑型
  意思：返回真表示是IP地址，返回假请获取错误码
备注：
*********************************************************************/
extern "C" BOOL APIHelp_IPAddr_IsIPV4Addr(LPCSTR lpszBuffer, XENGINE_LIBADDR *pSt_LibAddr = NULL, ENUM_NETHELP_APIHELP_IPADDR_TYPE *penIPType = NULL);
/********************************************************************
函数名称：APIHelp_IPAddr_IsLanAddr
函数功能：判断字符串是否是内网IP地址
 参数.一：lpszBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要判断的缓冲区
返回值
  类型：逻辑型
  意思：返回真表示是,假不是
备注：
*********************************************************************/
extern "C" BOOL APIHelp_IPAddr_IsLanAddr(LPCSTR lpszBuffer);
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
extern "C" uint64_t APIHelp_NetWork_hl64ton(uint64_t ullHost);
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
extern "C" uint64_t APIHelp_NetWork_ntohl64(uint64_t ullNet);
/********************************************************************
函数名称：APIHelp_NetWork_GetIPAddr
函数功能：获取网络IP地址信息
 参数.一：ptszLocalAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的本地IP地址信息
 参数.二：ptszRemoteAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的外网IP地址信息
返回值
  类型：逻辑型
  意思：是否成功
备注：两个参数不能同时为空,参数一如果有多个本地IP地址,使用;分割
*********************************************************************/
extern "C" BOOL APIHelp_NetWork_GetIPAddr(CHAR *ptszLocalAddr = NULL, CHAR *ptszRemoteAddr = NULL);
