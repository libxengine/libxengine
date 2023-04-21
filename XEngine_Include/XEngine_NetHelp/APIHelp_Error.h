#pragma once
/********************************************************************
//	Created:	2014/1/27  11:48
//	File Name: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_NetHelp/NetEngine_APIHelp/APIHelp_Error.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_NetHelp/NetEngine_APIHelp/
//	File Base:	APIHelp_Error.h
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎) For Linux
//	Author:		dowflyon
//	Purpose:	导出的网络帮助库错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的域名解析错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_NETAPI_DOMAIN_PARSE_PARAMENT 0x60B0001    //参数错误
#define ERROR_XENGINE_NETHELP_NETAPI_DOMAIN_PARSE_NODOMAIN 0x60B0002    //可能不是一个域名
#define ERROR_XENGINE_NETHELP_NETAPI_DOMAIN_ISEMAIL_PARAMENT 0x60B0010  //判断电子邮件地址失败，参数错误
#define ERROR_XENGINE_NETHELP_NETAPI_DOMAIN_ISEMAIL_NOTMATCH 0x60B0011  //不匹配，不是正确的电子邮件地址
//////////////////////////////////////////////////////////////////////////
//                        HTTP请求服务
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_PARAMENT 0x60B1000//参数错误
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_INIT 0x60B1001    //初始化失败
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_PERFORM 0x60B1002 //执行失败
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_GETCODE 0x60B1003 //获取返回的HTTP码失败
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_MALLOC 0x60B1004  //申请内存失败
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_PARAMENT 0x60B1010
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_INIT 0x60B1011
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_PERFORM 0x60B1012
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_GETCODE 0x60B1013
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_PARAMENT 0x60B1020
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_MALLOC 0x60B1021
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_INIT 0x60B1022
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_NOTFOUND 0x60B1023
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_PERFORM 0x60B1024
#define ERROR_XENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_GETCODE 0x60B1025
//////////////////////////////////////////////////////////////////////////
//                        网络错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_NETAPI_NETWORK_IPINFO_PARAMENT 0x60B2001   //参数错误