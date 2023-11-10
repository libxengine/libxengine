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
    XCHAR tszTopDomain[MAX_PATH];                                         //顶级域名
    XCHAR tszMainDomain[MAX_PATH];                                        //主域名
    XCHAR tszDomainName[MAX_PATH];                                        //域名名称
    XCHAR tszSubDomain[MAX_PATH];                                         //子域名
    XCHAR tszFullDomain[MAX_PATH];                                        //完整域名
}APIHELP_DOMAIN, *LPAPIHELP_DOMAIN;
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG APIHelp_GetLastError(int *pInt_SysError = NULL);
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
extern "C" bool APIHelp_Domain_GetInfo(LPCXSTR lpszUrl, APIHELP_DOMAIN *pSt_APIUrl, ENUM_APIHELP_DOMAINTYPE *penUrlType, XCHAR *ptszUrlPath = NULL);
/*********************************************************************************
*                          电子邮件解析器导出的函数                              *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_EMail_IsEMailAddr
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
extern "C" bool APIHelp_EMail_IsEMailAddr(LPCXSTR lpszEMailAddr);
/********************************************************************
函数名称：APIHelp_EMail_GetName
函数功能：获取电子邮件的名称和域名
 参数.一：lpszEMailAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的电子邮件地址
 参数.二：ptszNameStr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出邮件名称
 参数.三：ptszDomainStr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出邮件域名
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_EMail_GetName(LPCXSTR lpszEMailAddr, XCHAR* ptszNameStr = NULL, XCHAR* ptszDomainStr = NULL);