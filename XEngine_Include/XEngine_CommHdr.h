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
#define XENGINE_CHARSET_UNICODE 0                                          //UNICODE开关
#define XENGINE_USED_DEFINE 1                                              //使用标志
#define XENGINE_MEMORY_SIZE_MIX (1024 * 10)                                //通用内存一般大小,10KB
#define XENGINE_MEMORY_SIZE_MID (1024 * 1024)                              //通用内存最小大小,1MB
#define XENGINE_MEMORY_SIZE_MAX (1024 * 1024 * 10)                         //通用内存最大大小,10MB
//版本
#define XENGINE_VERSION_KERNEL 8
#define XENGINE_VERSION_MAIN 27
#define XENGINE_VERSION_SUB 000
#define XENGINE_VERSION_FIX 1001
//宏链接
#define _MACRO_TOSTR_OPEN(x) #x
#define _MACRO_TOSTR(x) _MACRO_TOSTR_OPEN(x)
#define _MACRO_TOLINK_OPEN(x, y) x##y
#define _MACRO_TOLINK(x, y) _MACRO_TOLINK_OPEN(x, y)
#define _MACRO_TOINT(a, b, c, d) _MACRO_TOLINK(_MACRO_TOLINK(_MACRO_TOLINK(a, b), c), d)
// 最终合并成的宏
#define XENGINE_VERSION_NUMBSTR _MACRO_TOSTR(XENGINE_VERSION_KERNEL) "." _MACRO_TOSTR(XENGINE_VERSION_MAIN) "." _MACRO_TOSTR(XENGINE_VERSION_SUB) "." _MACRO_TOSTR(XENGINE_VERSION_FIX)
#define XENGINE_VERSION_NUMBBIT _MACRO_TOINT(XENGINE_VERSION_KERNEL, XENGINE_VERSION_MAIN, XENGINE_VERSION_SUB, XENGINE_VERSION_FIX)
#define XENGINE_VERSION_TYPESTR "LTS"
#define XENGINE_VERSION_TYPEBIT ENUM_XENGINE_VERSION_TYPE_LTS
#define XENGINE_NAME_STR "XEngine"
#define XENGINE_NAME_DES "Network/Protocol/AVCodec/StreamMedia Development Framework"
//过期函数管理
#ifdef _MSC_BUILD
#define XENGINE_API_EXPORT_DEPRECATED __declspec(deprecated)
#else
#define XENGINE_API_EXPORT_DEPRECATED __attribute__ ((deprecated))
#endif
///////////////////////////////////////////////////////////////////////////
//                  自定义类型
///////////////////////////////////////////////////////////////////////////  
//句柄    
typedef void* (XHANDLE);
typedef void* (XEVENT);
typedef void* (XPVOID);                                                  //无类型指针
typedef int(XHTHREAD);
typedef unsigned long long(XNETHANDLE);                                  //网络句柄
typedef unsigned long long* (PXNETHANDLE);                               //网络句柄指针
typedef void** (XPPMEM);
typedef void*** (XPPPMEM);
//类型重定义
typedef unsigned char(XBYTE);                                            //无符号字符
typedef unsigned short(XSHOT);                                           //无符号短整数型
typedef unsigned int(XUINT);                                             //无符号整数型
typedef unsigned long(XLONG);                                            //有符号短整数型
typedef long long(__int64x);                                             //64位数值
typedef unsigned long long(__int64u);                                    //无符号64位数值
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
#define INVALID_HANDLE_VALUE -1                                       //失败的文件句柄
#endif
#if !defined(INVALID_SOCKET)
#define INVALID_SOCKET -1                                             //失败的XSOCKET句柄
#endif
#if !defined(SOCKET_ERROR)
#define SOCKET_ERROR -1                                               //错误的XSOCKET处理
#endif
#if !defined(SD_BOTH)
#define SD_BOTH SHUT_RDWR
#endif
#if !defined(MAX_PATH)
#define MAX_PATH 260                                                  //文件夹最大深度
#endif
#if !defined(MAX_ADDR)
#define MAX_ADDR 128                                                  //IP地址最大长度
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
#if 1 == XENGINE_CHARSET_UNICODE
typedef const wchar_t* LPCXSTR;
typedef wchar_t XCHAR;
#define _X(x)      x
#else
typedef char XCHAR;
typedef const char* LPCXSTR;
#define _X(x)      x
#endif