#pragma once
/********************************************************************
//	Created:	2013/1/13  20:24
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_P2xp\NetEngine_P2XPDistribution\DistributionCache_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_P2xp\NetEngine_P2XPDistribution
//	File Base:	DistributionCache_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	数据分发错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                          网路读写错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_IO_CALLBACK_PARAMENT 0x110C0001 //参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_IO_CREATE_PARAMENT 0x110C0001   //参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_IO_CREATE_MALLOC 0x110C0002     //创建失败,申请内存失败
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_IO_CREATE_THREAD 0x110C0003     //申请空间错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_IO_SENDCLIENT_PARAMENT 0x110C0010//参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_IO_SENDCLIENT_NOTFOUND 0x110C0011//没有找到客户端
//////////////////////////////////////////////////////////////////////////
//                          文件缓冲错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_INIT_PARAMENT 0x110C1001    //参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_POSTFILE_PARAMENT 0x110C1010//参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_POSTFILE_NOTFOUND 0x110C1011//没有找到文件句柄
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_POSTFILE_OPEN 0x110C1012    //打开文件失败
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_POSTFILE_SEEK 0x110C1013    //移动文件失败
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_POSTFILE_WRITE 0x110C1014   //写入文件失败
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_GETFILE_PARAMENT 0x110C1020 //获取属性失败,参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_FILE_GETFILE_NOTFOUND 0x110C1021 //没有找到
//////////////////////////////////////////////////////////////////////////
//                          数据缓冲错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_STACK_POSTMSG_PARAMENT 0x110C2001   //参数错误
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_STACK_GETMSG_PARAMENT 0x110C2010
#define ERROR_NETENGINE_P2XP_DISTRIBUTION_STACK_CLOSEMSG_PARAMENT 0x110C2020
