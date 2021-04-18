#pragma once
/********************************************************************
//	Created:	2014/7/17  15:53
//	File Name: 	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_FileParser\FileParser_Error.h
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_FileParser
//	File Base:	FileParser_Error
//	File Ext:	h
//  Project:    XyRySoft_NetEngine(网络通信引擎)
//	Author:		qyt 486179@qq.com
//	Purpose:	更新文件分析器导出错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      文件版本列表解析错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_INIT_PARAMENT 0xA1001000  //参数错误
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_INIT_JSON 0xA1001001      //JSON解析失败
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_PARAMENT 0xA1001010 //参数错误
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_JSON 0xA1001011     //JSON解析失败
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_NONEWVER 0xA1001012 //没有新版本
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_OPENFILE 0xA1001013 //打开文件失败
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_READ 0xA1001014     //读取数据失败
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_NOTNEWVER 0xA1001015//没有新版本
#define ERROR_XENGINE_UPDATA_FILEPARSER_MATCH_START_MALLOC 0xA1001016   //申请内存失败
//////////////////////////////////////////////////////////////////////////
//                      文件版本读取错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_UPDATA_FILEPARSER_READVER_ISUPVER_PARAMENT 0xA100101 //参数错误
#define ERROR_XENGINE_UPDATA_FILEPARSER_READVER_ISUPVER_JSON 0xA100102     //获取版本号失败
#define ERROR_XENGINE_UPDATA_FILEPARSER_READVER_GETDES_PARAMENT 0xA100120  //参数错误
#define ERROR_XENGINE_UPDATA_FILEPARSER_READVER_GETDES_LEN 0xA100121       //长度不合适
#define ERROR_XENGINE_UPDATA_FILEPARSER_READVER_GETDES_JSON 0xA100122      //获取描述URL地址失败
