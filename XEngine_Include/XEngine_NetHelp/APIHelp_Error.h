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
//////////////////////////////////////////////////////////////////////////
//                        网络错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_NETAPI_EMAIL_PARAMENT 0x60B1000            //判断电子邮件地址失败，参数错误
#define ERROR_XENGINE_NETHELP_NETAPI_EMAIL_NOTMATCH 0x60B1001            //不匹配，不是正确的电子邮件地址