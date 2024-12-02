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
#define ERROR_NETHELP_APIADDR_DOMAIN_PARSE_PARAMENT 0x60D0001    //参数错误
#define ERROR_NETHELP_APIADDR_DOMAIN_PARSE_NODOMAIN 0x60D0002    //可能不是一个域名
//////////////////////////////////////////////////////////////////////////
//                        网络错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_APIADDR_EMAIL_PARAMENT 0x60D1000            //判断电子邮件地址失败，参数错误
#define ERROR_NETHELP_APIADDR_EMAIL_NOTMATCH 0x60D1001            //不匹配，不是正确的电子邮件地址
//////////////////////////////////////////////////////////////////////////
//                       IP地址操作
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_APIADDR_IP_SEGADDR_PARAMENT 0x60D2000       //分割失败，参数错误
#define ERROR_NETHELP_APIADDR_IP_SEGADDR_NOTFOUND 0x60D2001       //不是XENGINE标准
#define ERROR_NETHELP_APIADDR_IP_IPVER_PARAMENT 0x60D2010         //参数错误
#define ERROR_NETHELP_APIADDR_IP_IPVER_FMT 0x60D2011              //格式错误
#define ERROR_NETHELP_APIADDR_IP_IPTYPE_PARAMENT 0x60D2020        //参数错误
#define ERROR_NETHELP_APIADDR_IP_IPV4ADDR_PARAMENT 0x60D2030      //不是IPV4,参数为空
#define ERROR_NETHELP_APIADDR_IP_IPV4ADDR_RANGE 0x60D2031         //地址的范围是错误的
#define ERROR_NETHELP_APIADDR_IP_IPV4ADDR_POINT 0x60D2032         //IP地址分割的点个数不正确
#define ERROR_NETHELP_APIADDR_IP_IPV6ADDR_PARAMENT 0x60D2040      //参数错误
#define ERROR_NETHELP_APIADDR_IP_IPV6ADDR_LEN 0x60D2041           //长度不正确
#define ERROR_NETHELP_APIADDR_IP_IPV6ADDR_FMT 0x60D2042           //格式不正确