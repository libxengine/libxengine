#pragma once
/********************************************************************
//	Created:	2012/5/21  17:04
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_Client\NetClient_P2PPeerManage\P2PPeerManage_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_Client\NetClient_P2PPeerManage
//	File Base:	P2PPeerManage_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		dowflyon
//	Purpose:	P2P节点管理器导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    导出错误表
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                    节点管理器错误                                    */
/************************************************************************/
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_ADD_ISEXIST 0xB0E0001           //用户已经存在
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_ADD_MALLOC 0xB0E0002            //申请内存失败
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GET_PARAMENT 0xB0E0010          //获取用户信息失败,参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GET_NOTFOUND 0xB0E0011          //没有找到用户
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_SET_PARAMENT 0xB0E0020          //参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_SET_NOTFOUND 0xB0E0021          //没有找到用户
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETWLIST_PARAMENT 0xB0E0030     //参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETWLIST_NOTFOUND 0xB0E0031     //没有找到
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_DELETE_PARAMENT 0xB0E0040       //参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_DELETE_NOTFOUND 0xB0E0041       //没有找到用户
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLAN_PARAMENT 0xB0E0050       //参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLAN_NOTPUBADDRR 0xB0E0051    //公网IP地址没有找到
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLAN_NOTPRIADDR 0xB0E0052     //私有网络IP地址没有找到
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLAN_NOLIST 0xB0E0053         //没有数据存在
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLAN_NOTFOUND 0xB0E0054       //没有找到链接地址
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETUSER_PARAMENT 0xB0E0060      //参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETUSER_NOTFOUND 0xB0E0061      //没有找到
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLLIST_PARAMENT 0xB0E0070     //获取列表失败,参数错误
#define ERROR_NETENGINE_P2XP_PEER_MANAGE_GETLLIST_NOTFOUND 0xB0E0071     //没有找到指定列表
/************************************************************************/
/*                    节点选择器错误                                    */
/************************************************************************/
#define ERROR_NETENGINE_P2XP_PEERSELECT_TRANSSELECT_PARAMENT 0xB0E1000   //参数错误
