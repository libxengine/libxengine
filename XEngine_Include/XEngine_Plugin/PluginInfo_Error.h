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
#define ERROR_XENGINE_PLUGIN_INFO_SET_ADD_PARAMENT 0x120B2001               //参数错误，添加失败
#define ERROR_XENGINE_PLUGIN_INFO_SET_ADD_ISFAILED 0x120B2002               //添加失败，内部错误
