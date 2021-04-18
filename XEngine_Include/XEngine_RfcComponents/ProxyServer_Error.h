#pragma once
/********************************************************************
//	Created:	2012/10/11  21:53
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_ProxyServer\RfcProxyServer_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_ProxyServer
//	File Base:	RfcProxyServer_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	代理服务器错误导出表
//	History:
*********************************************************************/
/************************************************************************/
/*                     代理服务器错误                                     */
/************************************************************************/
/************************************************************************/
/*                     隧道代理服务错误                                    */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_START_CREATETHREAD 0x120B0000   //创建线程失败
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRPARAM_NOTHTTP 0x120B0001     //没有找到，解析HTTP请求头失败
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRPARAM_NOTCONNECT 0x120B0002  //不是隧道协议，无法继续
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRPARAM_NOADDR 0x120B0003   //没有找到请求的地址
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRAUTH_NOTAUTH 0x120B0010   //验证失败，无法继续
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRECV_PARAMENT 0x120B0030   //参数错误，接收数据失败
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRECV_NOTFOUND 0x120B0031   //没有找到可以处理的客户端
#define ERROR_RFCCOMPONENTS_PROXYSERVER_TUNNEL_HDRECV_CREATETHREAD 0x120B0032  //创建线程失败
