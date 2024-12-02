#pragma once
/********************************************************************
//	Created:	2012/1/24  16:25
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_NetXApi\NetXApi_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_NetXApi
//	File Base:	NetXApi_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	网络XAPI 错误导出表
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       网络嗅探器错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_XSOCKET_SNIFFER_PARAMENT 0x60C1001                 //参数错误
#define ERROR_NETHELP_XSOCKET_SNIFFER_MALLOC 0x60C1002                   //申请内存失败
#define ERROR_NETHELP_XSOCKET_SNIFFER_SOCKET 0x60C1003                   //打开句柄失败
#define ERROR_NETHELP_XSOCKET_SNIFFER_BIND 0x60C1004                     //绑定端口失败
#define ERROR_NETHELP_XSOCKET_SNIFFER_IOCTL 0x60C1005                    //IOCTL错误
#define ERROR_NETHELP_XSOCKET_SNIFFER_THREAD 0x60C1006                   //启动线程失败
#define ERROR_NETHELP_XSOCKET_SNIFFER_NOTFOUND 0x60C1007                 //过滤器设置失败,句柄没有找到
//////////////////////////////////////////////////////////////////////////
//                    套接字函数错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_XSOCKET_SOCKET_NOTFOUND 0x10A2001                  //没有找到
#define ERROR_NETHELP_XSOCKET_SOCKET_NOTSUPPORT 0x10A2002                //不支持的协议
#define ERROR_NETHELP_XSOCKET_SOCKET_PARAMENT 0x10A2003                  //参数错误
#define ERROR_NETHELP_XSOCKET_SOCKET_MALLOC 0x10A2004                    //申请内存失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETTABLE 0x10A2005                  //获取TCP列表失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETAPPNAME 0x10A2006                //获取名称失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETAPPPID 0x10A2007                 //获取应用程序PID失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETUSERNAME 0x10A2008               //获取所属用户失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETIPVERSION 0x10A2009              //获取协议版本失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETPROTOCOL 0x10A2010               //获取协议类型失败
#define ERROR_NETHELP_XSOCKET_SOCKET_GETSTATE 0x10A2011                  //获取状态失败
#define ERROR_NETHELP_XSOCKET_SOCKET_NOTDOMAIN 0x10A2012                 //不是域名或者没有连接网络
#define ERROR_NETHELP_XSOCKET_SOCKET_OPENPID 0x10A2013                   //打开PID失败
#define ERROR_NETHELP_XSOCKET_SOCKET_ENUMFIRST 0x10A2014                 //枚举第一个列表失败
#define ERROR_NETHELP_XSOCKET_SOCKET_EMPTY 0x10A2015                     //列表为空
#define ERROR_NETHELP_XSOCKET_SOCKET_UNKNOW 0x10A2016                    //未知
#define ERROR_NETHELP_XSOCKET_SOCKET_NOCONNECT 0x10A2017                 //没有连接
#define ERROR_NETHELP_XSOCKET_SOCKET_OPEN 0x10A2018                      //打开失败
#define ERROR_NETHELP_XSOCKET_SOCKET_READ 0x10A20A0                      //读取失败
#define ERROR_NETHELP_XSOCKET_SOCKET_FAILED 0x10A20A1                    //处理失败,可能不是套接字
#define ERROR_NETHELP_XSOCKET_SOCKET_CONVERT 0x10A20A2                   //转换失败