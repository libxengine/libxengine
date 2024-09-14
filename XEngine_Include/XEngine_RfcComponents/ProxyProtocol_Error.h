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
/*                     SOCKS5服务器错误                                 */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_PARAMENT 0x70D0001               //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_VERSION 0x70D0002                //协议错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_LOGIN 0x70D0003                  //登录失败
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_FAILED 0x70D0004                 //处理失败
/************************************************************************/
/*                     隧道代理服务错误                                 */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_PARAMENT 0x70D1001              //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_NOTFOUND 0x70D1002              //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_NOADDR 0x70D1003                //没有找到地址内容
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_NOPORT 0x70D1004                //没有指定端口