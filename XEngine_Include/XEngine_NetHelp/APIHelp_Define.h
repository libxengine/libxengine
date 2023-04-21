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
extern "C" bool APIHelp_Domain_IsEMailAddr(LPCXSTR lpszEMailAddr);
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