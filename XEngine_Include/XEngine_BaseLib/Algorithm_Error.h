#pragma once
/********************************************************************
//	Created:	2012/11/23  16:41
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Lib\NetEngine_Algorithm\Algorithm_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Lib\NetEngine_Algorithm
//	File Base:	Algorithm_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	算法模块导出错误表
//	History:
*********************************************************************/
/************************************************************************/
/*                     字符串算法导出错误表                             */
/************************************************************************/
#define ERROR_XENGINE_BASELIB_ALGORITHM_STRING_PARAMENT 0x10A0000         //快速匹配算法使用失败，参数错误
#define ERROR_XENGINE_BASELIB_ALGORITHM_STRING_NOTMATCH 0x10A0001         //没有匹配到数据
/************************************************************************/
/*                     排序与查找导出错误表                             */
/************************************************************************/
#define ERROR_XENGINE_BASELIB_ALGORITHM_FSORT_PARAMENT 0x10A1000          //参数错误
/************************************************************************/
/*                     数学算法导出错误表                               */
/************************************************************************/
#define ERROR_XENGINE_BASELIB_ALGORITHM_MATH_PARAMENT 0x10A2000           //参数错误
#define ERROR_XENGINE_BASELIB_ALGORITHM_MATH_NOTSUPPORT 0x10A2001         //不支持的类型
/************************************************************************/
/*                     计算类型导出错误表                               */
/************************************************************************/
#define ERROR_XENGINE_BASELIB_ALGORITHM_CALCULATION_MALLOC 0x10A3001      //申请内存失败
#define ERROR_XENGINE_BASELIB_ALGORITHM_CALCULATION_PARAMENT 0x10A3002    //参数错误,关闭失败
#define ERROR_XENGINE_BASELIB_ALGORITHM_CALCULATION_THREAD 0x10A3003      //线程创建错误