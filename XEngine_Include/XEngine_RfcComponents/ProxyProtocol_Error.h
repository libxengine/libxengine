﻿#pragma once
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
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_CREATE_PARAMENT 0x120B0001        //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_CREATE_MALLOC 0x120B0002          //申请内存失败
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_STATUS_PARAMENT 0x120B0010        //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_STATUS_NOTFOUND 0x120B0011        //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_AUTH_PARAMENT 0x120B0020          //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_AUTH_NOTFOUND 0x120B0021          //验证失败,没有找到
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_AUTH_VERSION 0x120B0022           //协议错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_USER_PARAMENT 0x120B0030          //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_USER_NOTFOUND 0x120B0031          //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_CONNECT_PARAMENT 0x120B0040       //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_CONNECT_NOTFOUND 0x120B0041       //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_PACKET_PARAMENT 0x120B0050        //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_PACKET_NOTFOUND 0x120B0051        //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_INFO_PARAMENT 0x120B0060          //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_INFO_NOTFOUND 0x120B0061          //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_INFO_MALLOC 0x120B0062            //内存申请失败
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_INFO_NOTSET 0x120B0063            //没有设置客户端数据
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_LIST_PARAMENT 0x120B0070          //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_REQUEST_PARAMENT 0x120B0101       //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_HANDLE_PARAMENT 0x120B0101        //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_HANDLE_VERSION 0x120B0102         //处理失败,协议不正确
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_HANDLE_LOGIN 0x120B0103           //登录失败,如果非匿名登录可能用户名密码不对
#define ERROR_RFCCOMPONENTS_PROXY_SOCKS_HANDLE_FAILED 0x120B0104          //处理失败,服务器返回错误
/************************************************************************/
/*                     隧道代理服务错误                                 */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_CREATE_PARAMENT 0x120B1001       //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_CREATE_MALLOC 0x120B1002         //申请内存失败
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_PARSE_PARAMENT 0x120B1010        //参数错误解析失败
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_PARSE_NOTFOUND 0x120B1011        //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_GETIP_NOTFOUND 0x120B1020        //协议不正确
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_GETIP_NOADDR 0x120B1021          //没有找到地址内容
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_INFO_PARAMENT 0x120B1030         //参数错误
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_INFO_NOTFOUND 0x120B1031         //没有找到
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_INFO_MALLOC 0x120B1032           //申请内存失败
#define ERROR_RFCCOMPONENTS_PROXY_TUNNEL_INFO_NOTSET 0x120B1033           //没有设置内容