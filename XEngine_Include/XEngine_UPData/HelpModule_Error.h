#pragma once
/********************************************************************
//	Created:	2014/7/25  17:53
//	File Name: 	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_HelpModule\HelpModule_Error.h
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_HelpModule
//	File Base:	HelpModule_Error
//	File Ext:	h
//  Project:    XyRySoft_NetEngine(网络通信引擎)
//	Author:		qyt 486179@qq.com
//	Purpose:	更新帮助模块错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    错误码导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_UPDATA_HELPMODULE_API_INSTAL_PARAMENT 0xA3001000  //安装失败，参数错误
#define ERROR_XENGINE_UPDATA_HELPMODULE_API_CLEAR_PARAMENT 0xA3001001   //清理失败，参数错误
#define ERROR_XENGINE_UPDATA_HELPMODULE_API_CLEAR_DELFILE 0xA3001002    //删除文件出现错误，失败
#define ERROR_XENGINE_UPDATA_HELPMODULE_API_CLEAR_PARSE 0xA3001003      //解析要删除的文件失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_COPY_PARAMENT 0xA3001010 //拷贝文件出错，参数错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_COPY_ISFAILED 0xA3001011 //拷贝文件内部错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_COPY_DELFILE 0xA3001012  //删除文件内部错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_PARAMENT 0xA3001020 //设置版本号失败，参数错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_PARSENEWJSON 0xA3001021//解析新的JSON失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_MALLOC 0xA3001022 //申请内存失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_OPENFILE 0xA3001023//打开本地JSON失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_PARSELOCALJSON 0xA3001024 //解析本地JSON版本失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_DELETELOCALJSON 0xA3001025//删除本地JSON版本失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_SETVER_WRITENEWJSON 0xA3001026   //写入新的版本信息JSON失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_RUN_PARAMENT 0xA3001030  //运行程序失败，参数错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_RUN_ISFAILED 0xA3001031  //运行程序失败，内部错误
#define ERROR_XENGINE_UPDATA_HELPMODULE_API_BUILDVER_PARAMENT 0xA3001040
