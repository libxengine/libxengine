#pragma once
/********************************************************************
//	Created:	2013/1/17  20:12
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_P2xp\NetEngine_P2XPProtocol\P2XPProtocol_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_P2xp\NetEngine_P2XPProtocol
//	File Base:	P2XPProtocol_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	P2XP协议构造分析器错误码导出
//	History:
*********************************************************************/
/************************************************************************/
/*                  用户协议错误表                                      */
/************************************************************************/
#define ERROR_NETENGINE_P2XP_PROTOCOL_USERMSG_REQUESTLOGIN_PARAMENT 0xB0F1010 //参数错误
#define ERROR_NETENGINE_P2XP_PROTOCOL_USERMSG_REQUESTHB_PARAMENT 0xB0F1020    //参数错误
#define ERROR_NETENGINE_P2XP_PROTOCOL_USERMSG_REQUESTIONET_PARAMENT 0xB0F1030 //参数错误
#define ERROR_NETENGINE_P2XP_PROTOCOL_USERMSG_REQUESTLIST_PARAMENT 0xB0F1040
#define ERROR_NETENGINE_P2XP_PROTOCOL_USERMSG_REQUESTQUERYUSER_PARAMENT 0xB0F1050
/************************************************************************/
/*                  服务协议错误表                                      */
/************************************************************************/
#define ERROR_NETENGINE_P2XP_PROTOCOL_SVRMSG_RESPONSEJSON_PARAMENT 0xB0F2000  //参数错误
#define ERROR_NETENGINE_P2XP_PROTOCOL_SVRMSG_RESPONSELAN_PARAMENT 0xB0F2010   //参数错误
#define ERROR_NETENGINE_P2XP_PROTOCOL_SVRMSG_RESPONSELAN_LEN 0xB0F2011        //提供的缓冲区大小不够
#define ERROR_NETENGINE_P2XP_PROTOCOL_SVRMSG_REPQUERYUSER_PARAMENT 0xB0F2020  //参数错误
