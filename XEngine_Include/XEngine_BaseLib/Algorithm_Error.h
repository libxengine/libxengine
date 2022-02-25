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
#define ERROR_XENGINE_LIB_ALGORITHM_STRING_XFM_PARAMENT 0x80A0000       //快速匹配算法使用失败，参数错误
#define ERROR_XENGINE_LIB_ALGORITHM_STRING_XFM_NOTMATCH 0x80A0001       //没有匹配到数据
/************************************************************************/
/*                     排序与查找导出错误表                             */
/************************************************************************/
#define ERROR_XENGINE_LIB_ALGORITHM_FSORT_DOUBLESORT_PARAMENT 0x80A1000 //冒泡排序失败，参数错误
#define ERROR_XENGINE_LIB_ALGORITHM_FSORT_QSORT_PARAMENT 0x80A1010      //快排失败，参数错误
#define ERROR_XENGINE_LIB_ALGORITHM_FSORT_INSERT_PARAMENT 0x80A2020     //插入排序失败,参数错误
/************************************************************************/
/*                     数学算法导出错误表                               */
/************************************************************************/
#define ERROR_XENGINE_LIB_ALGORITHM_MATH_SWAP_PARAMENT 0x80A3000        //参数错误
#define ERROR_XENGINE_LIB_ALGORITHM_MATH_SWAP_NOTSUPPORT 0x80A3001      //不支持的类型
/************************************************************************/
/*                     计算类型导出错误表                               */
/************************************************************************/
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_CREATE_MALLOC 0x80A4001 //申请内存失败
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_CLOSE_PARAMENT 0x80A4010//参数错误,关闭失败
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_RESETTIME_PARAMENT 0x80A4020 //参数错误
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_SETTIME_PARAMENT 0x80A4030
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_GETTIME_PARAMENT 0x80A4040
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_RVFLOW_PARAMENT 0x80A4050
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_SDFLOW_PARAMENT 0x80A4060 
#define ERROR_XENGINE_LIB_ALGORITHM_CALCULATION_SLEEP_PARAMENT 0x80A4070 //同上