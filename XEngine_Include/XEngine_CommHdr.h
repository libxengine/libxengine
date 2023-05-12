#pragma once
/********************************************************************
//    Created:     2021/09/13  13:31:23
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_CommHdr.h
//    File Path:   D:\XEngine\XEngine_SourceCode
//    File Base:   XEngine_CommHdr
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     公用头文件-必须加载
//    History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////
//                          导出枚举型
///////////////////////////////////////////////////////////////////////////
//版本类型
typedef enum
{
	ENUM_XENGINE_VERSION_TYPE_PT = 0,
	ENUM_XENGINE_VERSION_TYPE_BT = 1,
	ENUM_XENGINE_VERSION_TYPE_RC = 2, 
	ENUM_XENGINE_VERSION_TYPE_LTS = 3
}ENUM_XENGINE_VERSION_TYPE;
///////////////////////////////////////////////////////////////////////////
//                          导出宏定义
///////////////////////////////////////////////////////////////////////////
//#define XENGINE_CHARSET_WOPEN 0                                           //UNICODE开关
#define XENGINE_USED_DEFINE 1                                             //使用标志
#define XENGINE_MEMORY_SIZE_MAX (1024 * 1024 * 10)                        //通用内存大小
//版本
#define XENGINE_VERSION_KERNEL 8
#define XENGINE_VERSION_MAIN 11
#define XENGINE_VERSION_SUB 000
#define XENGINE_VERSION_FIX 1001
#define XENGINE_VERSION_NUMBSTR "8.11.0.1001"
#define XENGINE_VERSION_NUMBBIT 8110001001
#define XENGINE_VERSION_TYPESTR "LTS"
#define XENGINE_VERSION_TYPEBIT ENUM_XENGINE_VERSION_TYPE_LTS
//过期函数管理
#if XENGINE_VERSION_BIT > 7230001001
#ifdef _MSC_BUILD
#define XENGINE_API_EXPORT __declspec(deprecated)
#else
#define XENGINE_API_EXPORT __attribute__ ((deprecated))
#endif
#endif
///////////////////////////////////////////////////////////////////////////
//                  自定义类型
///////////////////////////////////////////////////////////////////////////                                                   
typedef int XHTHREAD;
typedef void* XHANDLE;
typedef void* XEVENT;
typedef unsigned long long XNETHANDLE;                                   //网络句柄
typedef unsigned long long* (PXNETHANDLE);                               //网络句柄指针
typedef long long(__int64x);                                             //64位数值
typedef unsigned long long(__int64u);                                    //无符号64位数值
typedef void** XPPMEM;
typedef void*** XPPPMEM;
//类型重定义
typedef unsigned short(XSHOT);                                           //无符号短整数型
typedef unsigned long(XLONG);                                            //有符号短整数型
typedef unsigned char(XBYTE);                                            //无符号字符
typedef void* (XPVOID);                                                  //无类型指针
typedef unsigned int(XUINT);                                             //无符号整数型
//网络套接字句柄 
#ifdef _MSC_BUILD
#ifdef _WIN64
typedef XNETHANDLE(XSOCKET);
#else
typedef unsigned int(XSOCKET);
#endif
#else
typedef int(XSOCKET);
#endif
//类型处理
#if !defined(VOID)
typedef void(VOID);                                                   //无类型
#endif
#if !defined(INVALID_HANDLE_VALUE)
#define INVALID_HANDLE_VALUE -1                                        //失败的文件句柄
#endif
#if !defined(INVALID_SOCKET)
#define INVALID_SOCKET -1                                              //失败的XSOCKET句柄
#endif
#if !defined(SOCKET_ERROR)
#define SOCKET_ERROR -1                                                //错误的XSOCKET处理
#endif
#if !defined(SD_BOTH)
#define SD_BOTH SHUT_RDWR
#endif
#if !defined(MAX_PATH)
#define MAX_PATH 260                                                   //文件夹最大深度
#endif
#if !defined(CALLBACK)
#define CALLBACK
#endif
#if !defined(VOID)
#define VOID void                                                   //无类型
#endif
#if !defined(NULL)
#define NULL nullptr
#endif
///////////////////////////////////////////////////////////////////////
//                  自定义预处理
///////////////////////////////////////////////////////////////////////
#ifdef XENGINE_CHARSET_WOPEN
typedef const wchar_t* LPCXSTR;
typedef wchar_t XCHAR;
#define _X(x)      x
#else
typedef char XCHAR;
typedef const char* LPCXSTR;
#define _X(x)      x
#endif