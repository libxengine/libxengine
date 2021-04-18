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
#define ERROR_NETENGINE_NETHELP_NETAPI_DOMAIN_PARSE_PARAMENT 0xA0A0001    //参数错误
#define ERROR_NETENGINE_NETHELP_NETAPI_DOMAIN_PARSE_NODOMAIN 0xA0A0002    //可能不是一个域名
#define ERROR_NETENGINE_NETHELP_NETAPI_DOMAIN_ISEMAIL_PARAMENT 0xA0A0010  //判断电子邮件地址失败，参数错误
#define ERROR_NETENGINE_NETHELP_NETAPI_DOMAIN_ISEMAIL_NOTMATCH 0xA0A0011  //不匹配，不是正确的电子邮件地址
//////////////////////////////////////////////////////////////////////////
//                        HTTP请求服务
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_PARAMENT 0xA0A1000//参数错误
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_INIT 0xA0A1001    //初始化失败
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_PERFORM 0xA0A1002 //执行失败
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_GETCODE 0xA0A1003 //获取返回的HTTP码失败
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_POST_LEN 0xA0A1004     //长度不合适
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_PARAMENT 0xA0A1010
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_INIT 0xA0A1011
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_PERFORM 0xA0A1012
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_GETCODE 0xA0A1013
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_GET_LEN 0xA0A1014
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_PARAMENT 0xA0A1020
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_INIT 0xA0A1021
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_PERFORM 0xA0A1022
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_GETCODE 0xA0A1023
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CUSTOM_LEN 0xA0A1024
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CHUNKED_PARAMENT 0xA0A1030 //参数错误
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CHUNKED_MALLOC 0xA0A1031   //申请内存失败
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CHUNKED_INIT 0xA0A1032     //初始化失败
#define ERROR_NETENGINE_NETHELP_NETAPI_HTTPREQUEST_CHUNKED_PERFORM 0xA0A1033  //执行失败
//////////////////////////////////////////////////////////////////////////
//                        IP地址解析
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_IPV4ADDR_PARAMENT 0xA0A2000 //不是IPV4,参数为空
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_IPV4ADDR_LEN 0xA0A2001      //长度不对
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_IPV4ADDR_RANGE 0xA0A2002    //地址的范围是错误的
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_IPV4ADDR_POINT 0xA0A2003    //IP地址分割的点个数不正确
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_LANADDR_PARAMENT 0xA0A2010  //参数错误，无法判断是否是内网IP
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_LANADDR_LEN 0xA0A2011       //长度不合适
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_LANADDR_NOTIP 0xA0A2012     //不是IP地址
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_LANADDR_GETRANGE 0xA0A2013  //获取内网IP地址范围失败
#define ERROR_NETENGINE_NETHELP_NETAPI_IPADDR_LANADDR_NOTLANIP 0xA0A2014  //不是内网IP
//////////////////////////////////////////////////////////////////////////
//                        网络操作错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_NETAPI_NET_GETIPADDR_PARAMENT 0xA0A3001   //参数错误
#define ERROR_NETENGINE_NETHELP_NETAPI_NET_GETIPADDR_GETHOST 0xA0A3002    //获取主机信息失败
#define ERROR_NETENGINE_NETHELP_NETAPI_NET_GETIPADDR_GETLIST 0xA0A3003    //获取列表失败
