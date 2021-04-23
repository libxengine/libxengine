#pragma once
/********************************************************************
//	Created:	2012/5/21  17:02
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_Client\NetClient_P2p\P2PPeerManage_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_Client\NetClient_P2p
//	File Base:	P2PPeerManage_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		dowflyon
//	Purpose:	P2P节点管理器导出错误
//	History:
*********************************************************************/
/************************************************************************/
/*                          P2P传输管理错误表                             */
/************************************************************************/
#define ERROR_NETENGINE_P2XP_CLIENT_COMMUNICATE_CB_PARAMENT 0xB0A0000     //设置回调函数失败，参数错误
#define ERROR_NETENGINE_P2XP_CLIENT_COMMUNICATE_CREATE_RUNNING 0xB0A0010  //命令通道已经创建，无法继续
#define ERROR_NETENGINE_P2XP_CLIENT_COMMUNICATE_CREATE_THREADRECV 0xB0A0011 //创建线程失败
#define ERROR_NETENGINE_P2XP_CLIENT_COMMUNICATE_CREATE_THREADHB 0xB0A0012 //创建心跳线程失败
#define ERROR_NETENGINE_P2XP_CLIENT_COMMUNICATE_CREATE_PARAMENT 0xB0A0013 //参数错误
#define ERROR_NETENGINE_P2XP_CLIENT_COMMUNICATE_SEND_PARAMENT 0xB0A0030   //发送失败
/************************************************************************/
/*                          P2P包管理器                                  */
/************************************************************************/
#define ERROR_NETENGINE_P2XP_CLIENT_HELP_GETINFO_PARAMENT 0xB0A1000       //获取节点信息失败,参数错误
#define ERROR_NETENGINE_P2XP_CLIENT_HELP_GETINFO_NOTIPADDR 0xB0A1001      //没有找到可用的网卡IP
#define ERROR_NETENGINE_P2XP_CLIENT_HELP_GETTYPE_PARAMENT 0xB0A1010       //获取节点类型失败,参数错误
