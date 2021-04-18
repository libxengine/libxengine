#pragma once
/********************************************************************
//	Created:	2013/9/17   15:41
//	Filename: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginCore/PluginCore_Error.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginCore/
//	File Base:	PluginCore_Error
//	File Ext:	h
//  Project:    NetEngien_Linux(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:    插件核心错误导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       核心错误定义
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_PARAMENT 0x120A1001      //参数错误
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_OPENDL 0x120A1002        //打开模块插件失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_FPINIT 0x120A1003        //查找初始化函数失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_FPUNINIT 0x120A1004      //查找卸载函数失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_FPCALL 0x120A1005        //查找调用执行功能函数失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_FPERROR 0x120A1006       //获取错误函数失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_MALLOC 0x120A1007        //申请内存失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADD_INIT 0x120A1008          //初始化内部模块失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADDUSER_PARAMENT 0x120A1010  //参数错误
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADDUSER_NOTFOUND 0x120A1011  //没有找到句柄
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_ADDUSER_FPTIMER 0x120A1012   //查找调用函数失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_DEL_PARAMENT 0x120A1020      //参数错误
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_DEL_NOTFOUND 0x120A1021      //没有找到
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_DEL_CLOSE 0x120A1022         //关闭失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_EXEC_NOTFOUND 0x120A1031     //没有找到，执行失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_INIT_ISINITED 0x120A1040     //已经初始化了，不需要再次初始化
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_INIT_CREATETHREAD 0x120A1041 //创建线程失败
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_EXECFUNC_PARAMENT 0x120A1060 //参数错误，无法继续
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_EXECFUNC_NOTFOUND 0x120A1061 //没有找到插件句柄
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_EXECFUNC_AUTO 0x120A1062     //此函数被设置为自动执行，不能继续
#define ERROR_XENGINE_PLUGIN_CORE_FRAMEWORK_EXECFUNC_NOTFUNC 0x120A1063  //没有找到可执行的函数名称
//////////////////////////////////////////////////////////////////////////
//                       插件搜索服务错误定义
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_PLUGIN_CORE_SEARCH_START_PARAMENT 0x120A2000       //参数错误启动搜索失败
