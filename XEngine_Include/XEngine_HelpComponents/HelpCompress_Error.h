﻿#pragma once
/********************************************************************
//	Created:	2017/7/1   12:35
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_Compress\HelpCompress_Error.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_Compress
//	File Base:	HelpCompress_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	数据压缩错误导出文件
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        解压缩算法库错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_COMPRESS_PARAMENT 0x70B0001  //参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_COMPRESS_INIT 0x70B0002      //初始化失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_COMPRESS_DEH 0x70B0003       //压缩头失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_COMPRESS_ISFAILED 0x70B0004  //压缩失败,内部错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_COMPRESS_END 0x70B0005       //压缩失败,压缩尾失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_UNCOMPRESS_PARAMENT 0x70B0010//参数错误,解压失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_UNCOMPRESS_INIT 0x70B0011    //初始化失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_UNCOMPRESS_HDR 0x70B0012     //获取压缩头失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_UNCOMPRESS_ISFAILED 0x70B0013//解压失败,内部错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_GZIP_UNCOMPRESS_END 0x70B0014     //解压失败,效验失败
//////////////////////////////////////////////////////////////////////////
//                        内存解压缩错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_MEMORY_COMPRESS_PARAMENT 0x70B1001//参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_MEMORY_COMPRESS_LEN 0x70B1002     //提供的缓冲区长度不够
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_MEMORY_COMPRESS_ISFAILED 0x70B1003//压缩失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_MEMORY_UNCOMPRESS_PARAMENT 0x70B1010 //参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_MEMORY_UNCOMPRESS_ISFAILED 0x70B1011 //解压失败
//////////////////////////////////////////////////////////////////////////
//                        文件解压缩错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_CREATE_PARAMENT 0x70B2001  //初始化失败,参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_CREATE_FILE 0x70B2002      //打开文件失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_ADD_PARAMENT 0x70B2010     //获取失败,参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_ADD_CREATE 0x70B2011       //获取失败,没有找到可用的句柄
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_ADD_OPEN 0x70B2012         //获取头失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_ADD_CLOSE 0x70B2013        //不是标准二进制头,无法继续
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_NOTE_PARAMENT 0x70B2020    //获取参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_NOTE_GETTEXT 0x70B2021     //获取内容失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_COUNT_PARAMENT 0x70B2030   //获取文件个数失败,参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_COUNT_GET 0x70B2031        //获取个数失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_GOFILE_PARAMENT 0x70B2040  //跳转指定文件名失败,参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_GOFILE_ISFAILED 0x70B2041  //调整指定文件失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_GOFIRST_ISFAILED 0x70B2050 //跳转到压缩文件头失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_GONEXT_ISFAILED 0x70B2060  //跳转到下一个文件失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_GETINFO_PARAMENT 0x70B2070 //参数错误,获取信息失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_GETINFO_ISFAILED 0x70B2071 //获取信息错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_WRITEFILE_PARAMENT 0x70B2080 //写文件失败,参数错误
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_WRITEFILE_OPEN 0x70B2081   //打开ZIP文件句柄失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_WRITEFILE_CREATE 0x70B2082 //创建文件失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_WRITEFILE_CLOSE 0x70B2083  //关闭文件句柄失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_OPEN_PARAMENT 0x70B2090    //参数错误,打开失败
#define ERROR_NETENGINE_HELPCOMPONENTS_COMPRESS_FILE_OPEN_FILE 0x70B2091        //打开文件失败,可能不存在或者不是压缩文件
