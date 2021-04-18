#pragma once
/********************************************************************
//	Created:	2014/7/20  14:39
//	File Name: 	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_Downloads\UPDataDl_Error.h
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_Downloads
//	File Base:	UPDataDl_Error
//	File Ext:	h
//  Project:    XyRySoft_NetEngine(网络通信引擎)
//	Author:		qyt 486179@qq.com
//	Purpose:	更新下载模块错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_INIT_PARAMENT 0xA2001000 //参数错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_INIT_MALLOC 0xA2001001   //申请内存失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_INIT_THREADDOWN 0xA2001002  //创建下载线程失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_INIT_THREADEVENT 0xA2001003 //创建事件线程失败
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_INIT_RUNNING 0xA2001004  //已经在运行中，或者你没有关闭
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_CBQUERT_PARAMENT 0xA2001020 //设置回调失败，参数错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_GETRATE_PARAMENT 0xA2001030 //获取百分比失败，参数错误
#define ERROR_XENGINE_UPDATA_UPDATADL_DLPARSER_GETRATE_ZEROPARA 0xA2001031 //参数为0
