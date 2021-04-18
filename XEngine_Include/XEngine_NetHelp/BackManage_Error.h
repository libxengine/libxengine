#pragma once
/********************************************************************
//	Created:	2017/5/26   10:26
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_BackManage\BackManage_Error.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_BackManage
//	File Base:	BackManage_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	后台管理服务导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的后台网络服务错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_INIT_PARAMENT 0xAB00F001   //参数错误
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_INIT_THREAD 0xAB00F002     //创建HTTP线程失败
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_PARAMENT 0xAB00F010  //解析失败,参数错误
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_JSON 0xAB00F011      //解析失败,JSON错误
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_DELETE 0xAB00F012    //删除文件失败
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_PROCESS 0xAB00F013   //创建进程失败
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_CMD 0xAB00F014       //执行命令失败
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_NOTSUPPORT 0xAB00F015//这个协议不被支持
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_SERVICE_PARSE_EXECUTED 0xAB00F016  //此任务已经执行过
//////////////////////////////////////////////////////////////////////////
//                        导出的后台服务信息获取错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_GETINFO_HARDWARE_PARAMENT 0xAB00F101//参数错误
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_GETINFO_HARDWARE_LEN 0xAB00F102     //提供的缓冲区内存不足够
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_GETINFO_SOFTWARE_PARAMENT 0xAB00F110//参数错误
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_GETINFO_SOFTWARE_LEN 0xAB00F111     //长度不够
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_GETINFO_SOFTWARE_GETNAME 0xAB00F111 //获取名称失败
#define ERROR_NETENGINE_NETHELP_BACKMANAGE_GETINFO_GETBUFF_PARAMENT 0xAB00F120 //参数错误
