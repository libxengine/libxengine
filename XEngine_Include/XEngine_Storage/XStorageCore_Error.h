#pragma once
/********************************************************************
//	Created:	2019/6/28   14:56
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Storage\NetEngine_XStorageCore\XStorageCore_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Storage\NetEngine_XStorageCore
//	File Base:	XStorageCore_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	X存储服务导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的数据库错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XSTROGE_CORE_DB_INIT_PARAMENT 0x130B0001          //初始化失败.参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_INIT_THREAD 0x130B0002            //初始化线程失败
#define ERROR_XENGINE_XSTROGE_CORE_DB_INSERTFILE_PARAMENT 0x130B0010    //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_DELETEFILE_PARAMENT 0x130B0020    //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_QUERYFILE_PARAMENT 0x130B0030     //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_QUERYFILE_EMPTY 0x130B0031        //查找数据为空
#define ERROR_XENGINE_XSTROGE_CORE_DB_GETCOUNT_PARAMENT 0x130B0040      //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_GETCOUNT_BROKE 0x130B0041         //数据库被损坏
#define ERROR_XENGINE_XSTROGE_CORE_DB_INSERTDIR_PARAMENT 0x130B0050     //插入文件夹失败,参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_DELETEDIR_PARAMENT 0x130B0060     //删除失败
#define ERROR_XENGINE_XSTROGE_CORE_DB_QUERYDIR_PARAMENT 0x130B0070      //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_QUERYDIR_NODATA 0x130B0071        //没有记录
#define ERROR_XENGINE_XSTROGE_CORE_DB_REGISER_PARAMENT 0x130B0080       //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_REGISER_NOTDATA 0x130B0081        //没有记录
#define ERROR_XENGINE_XSTROGE_CORE_DB_USERQUERY_PARAMENT 0x130B0090     //参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_USERQUERY_NOTDATA 0x130B0091      //没有数据
#define ERROR_XENGINE_XSTROGE_CORE_DB_USERQUERYTOKEN_PARAMENT 0x130B00A0//参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_USERQUERYTOKEN_NOTDATA 0x130B00A1 //没有数据
#define ERROR_XENGINE_XSTROGE_CORE_DB_QUERYFILETABLE_PARAMENT 0x130B00B1//参数错误
#define ERROR_XENGINE_XSTROGE_CORE_DB_QUERYFILETABLE_EMPTY 0x130B00B2   //空的表
#define ERROR_XENGINE_XSTROGE_CORE_DB_USERFILESET_PARAMENT 0x130B00C0   //参数错误
//////////////////////////////////////////////////////////////////////////
//                        导出的会话管理错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XSTROGE_CORE_SESSION_INSERT_PARAMENT 0x130B1001   //参数错误,插入失败
#define ERROR_XENGINE_XSTROGE_CORE_SESSION_INSERT_EXIST 0x130B1002      //这个用户已经登录过了
#define ERROR_XENGINE_XSTROGE_CORE_SESSION_GET_PARAMENT 0x130B1010      //参数错误,获取失败
#define ERROR_XENGINE_XSTROGE_CORE_SESSION_GET_NOTFOUND 0x130B1011      //没有找到用户
