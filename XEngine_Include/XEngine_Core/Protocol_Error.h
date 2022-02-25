#pragma once
/********************************************************************
//	Created:	2012/1/8  12:15
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_Protocol\Protocol_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_Protocol
//	File Base:	Protocol_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	协议模块导出错误定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                          ICMP协议导出错误
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                          PING                                        */
/************************************************************************/
#define  ERROR_XCORE_PROTOCOL_ICMP_PING_PARAMENT 0x10E0001     //参数错误
#define  ERROR_XCORE_PROTOCOL_ICMP_PING_SEND 0x10E0002         //发送数据失败
#define  ERROR_XCORE_PROTOCOL_ICMP_PING_TIMEOUT 0x10E0003      //超时
/************************************************************************/
/*                  TRACER路由路径过程                                  */
/************************************************************************/
#define  ERROR_XCORE_PROTOCOL_TRACE_TRACE_PARAMENT 0x10E1001   //参数错误
#define  ERROR_XCORE_PROTOCOL_TRACE_SEND_TIMEOUT 0x10E1002     //发送数据失败
#define  ERROR_XCORE_PROTOCOL_TRACE_RECV_TIMEOUT 0x10E1003     //超时
//////////////////////////////////////////////////////////////////////////
//                         原始套接字错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_IPHDR_PARAMENT 0x10E3000           //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_IPHDR_NOTSUPPORT 0x10E3001         //不支持的协议类型
//TCP
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_INIT_PARAMENT 0x10E3100        //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_INIT_SOCKET 0x10E3101          //获取套接字失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_INIT_SET 0x10E3102             //设置套机字失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_PACKET_PARAMENT 0x10E3110      //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_PARSE_PARAMENT 0x10E3120       //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_PARSE_NOTTCP 0x10E3121         //后续不是TCP数据,已经过滤
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_PARSE_NOTMATCH 0x10E3122       //不匹配,这个报文不是请求的TCP返回的数据
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_TCP_PARSE_NOTSUPPORT 0x10E3123     //不支持的报文
//UDP
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_INIT_PARAMENT 0x10E3200        //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_INIT_SOCKET 0x10E3201          //初始化套接字失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_INIT_SET 0x10E3202             //设置套接字属性失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_PACKET_PARAMENT 0x10E3210      //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_PARSE_PARAMENT 0x10E3220       //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_PARSE_NOTICMP 0x10E3221        //不是ICMP协议
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_UDP_PARSE_NOTSUPPORT 0x10E3222     //不支持的协议解析类型
//ICMP
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_INIT_PARAMENT 0x10E3300       //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_INIT_SOCKET 0x10E3301         //初始化套接字失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_INIT_SET 0x10E3302            //设置套接字属性失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_PACKET_PARAMENT 0x10E3310     //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_PARSE_PARAMENT 0x10E33120     //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_PARSE_NOTICMP 0x10E33121      //不是ICMP协议
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ICMP_PARSE_NOTSUPPORT 0x10E33122   //不支持的协议解析
//ARP
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ARP_INIT_PARAMENT 0x10E3400        //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ARP_INIT_SOCKET 0x10E3401          //设置套接字失败
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ARP_PACKET_PARAMENT 0x10E3410      //参数错误
#define ERROR_XCORE_PROTOCOL_RAWSOCKET_ARP_PARSE_PARAMENT 0x10E3420       //参数错误