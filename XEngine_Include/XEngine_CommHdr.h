﻿#pragma once
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
//                          导出宏定义
///////////////////////////////////////////////////////////////////////////
#define XENGINE_USED_DEFINE 1             //使用标志
//版本
#define XENGINE_VERSION_KERNEL 7
#define XENGINE_VERSION_MAIN 42
#define XENGINE_VERSION_SUB 1
#define XENGINE_VERSION_FIX 1001
#define XENGINE_VERSION_STR "7.42.1.1001"
#define XENGINE_VERSION_BIT 7420011001
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
typedef short int (SHOT);                                              //有符号短整数型
typedef int XHTHREAD;
typedef void* XHANDLE;
typedef void* XSTRUCT;
typedef void* XEVENT;
typedef unsigned long long XNETHANDLE;                                 //网络句柄
typedef unsigned long long* (PXNETHANDLE);                             //网络句柄指针
typedef long long (__int64x);                                          //64位数值
typedef unsigned long long(__int64u);                                  //无符号64位数值
typedef void** XPPMEM;
typedef void*** XPPPMEM;
#ifndef _MSC_BUILD
typedef unsigned long int (DWORD);                                     //双字
typedef unsigned short (WORD);                                         //无符号短整数型
typedef unsigned char (BYTE);                                          //无符号字符
typedef int BOOL;                                                      //逻辑型
typedef int (HFILE);                                                   //文件句柄
typedef int (HDEVICE);                                                 //设备句柄
typedef void (VOID);                                                   //无类型
typedef void* (LPVOID);                                                //无类型指针
#ifndef SOCKET
typedef int (SOCKET);                                                  //网络套接字句柄 
#endif
#ifndef SD_BOTH
#define SD_BOTH SHUT_RDWR
#endif
typedef unsigned long int (HANDLE);                                    //线程句柄
typedef void * (HMODULE);                                              //模块句柄
typedef unsigned int (UINT);                                           //无符号整数型
typedef char (CHAR);                                                   //字符
typedef unsigned char (UCHAR);                                         //无符号字符型
typedef wchar_t (WCHAR);                                               //宽字符
typedef const char* (LPCSTR);                                          //常量字符指针
typedef const wchar_t* (LPCWSTR);                                      //常量宽字符指针
typedef unsigned short int (USHORT);                                   //无符号短整数型
typedef unsigned long* DWORD_PTR,*PDWORD_PTR;                          //双字指针
///////////////////////////////////////////////////////////////////////
//                  自定义定义
///////////////////////////////////////////////////////////////////////
#define INVALID_HANDLE_VALUE -1                                        //失败的文件句柄
#define INVALID_SOCKET -1                                              //失败的SOCKET句柄
#define SOCKET_ERROR -1                                                //错误的SOCKET处理
#ifndef FALSE
#define FALSE   0
#endif
#ifndef TRUE
#define TRUE    1
#endif
#define MAX_PATH 260                                                   //文件夹最大深度
#define __stdcall
#define CALLBACK
#define WINAPI
///////////////////////////////////////////////////////////////////////
//                  自定义预处理
///////////////////////////////////////////////////////////////////////
#ifdef _UNICODE
typedef const wchar_t* LPCTSTR;
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
typedef const char* LPCTSTR;
typedef const void* LPCVOID;
#endif
#ifdef _UNICODE
#define _T(x)      L ## x
#else
#define _T(x)      x
#endif
#endif
