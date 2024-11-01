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
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_PARAMENT 0x50F0001      //初始化失败,参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_OPENFILE 0x50F0002      //打开文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_GETSIZE 0x50F0003       //获取大小失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_MALLOC 0x50F0004        //申请数据结构内存失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_FAILED 0x50F0005    //写入日志失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_CPFILE 0x50F0006    //拷贝文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_NOTSUPPORT 0x50F0007   //打印失败,不支持的类型
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_NOTENABLE 0x50F0008    //没有启用
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_SIZE 0x50F0009         //提供的缓冲区大小不合适
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_PARAMET 0x50F1001     //参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_NOTSUPPORT 0x50F1002  //不支持的类型
#define ERROR_XENGINE_HELPCOMPONENTS_XLOG_HELP_COPYFILE 0x50F1003    //拷贝文件失败
