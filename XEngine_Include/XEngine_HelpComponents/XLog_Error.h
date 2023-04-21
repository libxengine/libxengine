#pragma once
/********************************************************************
//	Created:	2012/11/24  1:03
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_HelpComponents\HelpComponents_XLog\XLog_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_HelpComponents\HelpComponents_XLog
//	File Base:	XLog_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	日志系统错误码导出
//	History:
*********************************************************************/
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_INIT_PARAMENT 0x50F0001      //初始化失败,参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_INIT_OPENFILE 0x50F0002      //打开文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_INIT_GETSIZE 0x50F0003       //获取大小失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_INIT_MALLOCSUT 0x50F0004     //申请数据结构内存失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_INIT_MALLOCLIST 0x50F0005    //申请队列内存失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_WRITELOG_OPENFILE 0x50F0011  //写入打开文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_WRITELOG_FAILED 0x50F0021    //写入日志失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_WRITELOG_CPFILE 0x50F0022    //拷贝文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_PRINT_NOTSUPPORT 0x50F0030   //打印失败,不支持的类型
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_PRINT_MALLOC 0x50F0031       //申请内存失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_GETIDLETIME_PARAMENT 0x50F0050//获取间隔时间失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_GETLOG_PARAMENT 0x50F0060     //参数错误,获取失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_GETLOG_NOTENABLE 0x50F0061    //没有启用
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_GETLOG_SIZE 0x50F0062         //提供的缓冲区大小不合适
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_BACKNAME_PARAMET 0x50F1001     //参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_BACKNAME_NOTSUPPORT 0x50F1002  //不支持的类型
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_BACKFILE_PARAMET 0x50F1010     //参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_BACKFILE_COPYFILE 0x50F1011    //拷贝文件失败
