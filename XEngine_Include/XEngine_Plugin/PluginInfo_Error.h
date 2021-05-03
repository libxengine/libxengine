#pragma once
/********************************************************************
//	Created:	2013/9/18   13:54
//	Filename: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginInfo/PluginInfo_Error.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginInfo/
//	File Base:	PluginInfo_Error
//	File Ext:	h
//  Project:    NetEngien_Linux(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:    插件信息模块导出错误定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       获取信息错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_PLUGIN_INFO_GET_GET_VERSION_PARAMENT 0x120B1001       //参数错误，获取版本号失败
#define ERROR_XENGINE_PLUGIN_INFO_GET_GET_ALLVERSION_PARAMENT 0x120B1010    //参数错误，获取所有版本号失败
//////////////////////////////////////////////////////////////////////////
//                       设置信息错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_ADDMODULE_PARAMENT 0x120B2001  //参数错误，添加失败
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_ADDMODULE_NOTFOUND 0x120B2002  //添加失败，没有找到
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_ADDFUNCTION_PARAMENT 0x120B2010
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_ADDFUNCTION_NOTFOUND 0x120B2011
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_ADDFUNCTION_NOTMODULE 0x120B2012  //没有这个模块
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_GET_PARAMENT 0x120B2020
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_GET_NOTFOUND 0x120B2021
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_WRITE_PARAMENT 0x120B2030 
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_WRITE_NOTFOUND 0x120B2031
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_WRITE_MALLOC 0x120B2032       //申请内存失败
#define ERROR_XENGINE_PLUGIN_INFO_LIST_CREATE_WRITE_FILE 0x120B2033         //创建文件失败

#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_INIT_PARAMENT 0x120B2100       //参数错误
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_INIT_OPEN 0x120B2101           //打开文件失败
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_INIT_SIZE 0x120B2102           //获取文件大小失败
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_INIT_MALLOC 0x120B2103         //申请内存失败
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_INIT_FAILED 0x120B2104         //解析失败
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_COUNT_PARAMENT 0x120B2110
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_COUNT_NOTFOUND 0x120B2111
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_COUNT_NOTMODULE 0x120B2112
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_GET_PARAMENT 0x120B2120
#define ERROR_XENGINE_PLUGIN_INFO_LIST_PARSE_GET_NOTFOUND 0x120B2121