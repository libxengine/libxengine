﻿#pragma once
/********************************************************************
//	Created:	2012/11/23  16:24
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Lib\NetEngine_Algorithm\Algorithm_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Lib\NetEngine_Algorithm
//	File Base:	Algorithm_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	算法库导出模块函数
//	History:    
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         回调函数
//////////////////////////////////////////////////////////////////////////
//数据计算回调,参数:句柄,发送平均,接受平均,次数平均,<1,2,3:平均的当前流量巪>,自定义参数
typedef void(XCALLBACK* CALLBACK_XENGINE_BASELIB_ALGORITHM_PASSIVE)(XHANDLE xhToken, bool bSDFlow, bool bRVFlow, bool bTime, __int64u nSDFlow, __int64u nRVFlow, __int64u nTimeFlow, XPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG Algorithm_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                     字符串算法导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：Algorithm_String_GetMemoryInt
函数功能：获取内存指定大小字符串的整数值
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获取的缓冲区
 参数.二：nStart
  In/Out：In
  类型：整数型
  可空：N
  意思：输入内存开始字节位置
 参数.三：nEnd
  In/Out：In
  类型：整数型
  可空：N
  意思：输入内存结束位置
 参数.四：pInt_Value
  In/Out：In
  类型：整数型指针
  可空：N
  意思：输出他们的值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_String_GetMemoryInt(LPCXSTR lpszMsgBuffer, int nStart, int nEnd, int* pInt_Value);
/********************************************************************
函数名称：Algorithm_String_XFastMatch
函数功能：X快速匹配算法
 参数.一：lpszSourceStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：被匹配的原始字符串
 参数.二：lpszFindStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要匹配的字符串
 参数.三：pInt_PosEnd
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出匹配后的字符串位置，123456 m 45 返回的就是6
 参数.四：nSourceLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入原始字符串长度，可以为0。0原始字符串不能是二进制。
 参数.五：pInt_PosStart
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出起始位置
返回值
  类型：逻辑型
  意思：是否匹配成功
备注：支持字符串和二进制快速匹配
*********************************************************************/
extern "C" bool Algorithm_String_XFastMatch(LPCXSTR lpszSourceStr, LPCXSTR lpszFindStr, int* pInt_PosEnd, int nSourceLen = 0, int* pInt_PosStart = NULL);
/************************************************************************/
/*                     查找与排序导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：Algorithm_FSort_DoubleSort
函数功能：冒泡排序算法
 参数.一：pInt_ArrayNumber
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：要排序的数组,输出：排序好的数组
 参数.二：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要排序的个数
返回值
  类型：逻辑型
  意思：是否排序成功
备注：
*********************************************************************/
extern "C" bool Algorithm_FSort_DoubleSort(int *pInt_ArrayNumber, int nCount);
/********************************************************************
函数名称：Algorithm_FSort_InsertSort
函数功能：插入排序
 参数.一：pInt_ArrayNumber
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：要排序的数组,输出：排序好的数组
 参数.二：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要排序的个数
返回值
  类型：逻辑型
  意思：是否排序成功
备注：
*********************************************************************/
extern "C" bool Algorithm_FSort_InsertSort(int *pInt_Array, int nValue);
/************************************************************************/
/*                     数学类算法导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：Algorithm_Math_Swap
函数功能：两个数字交换,支持多种类型
 参数.一：lPSource
  In/Out：In
  类型：无类型指针
  可空：N
  意思：要交换的值
 参数.二：lPDest
  In/Out：In
  类型：无类型指针
  可空：N
  意思：要交换的值
 参数.三：lpszType
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要交换的值的类型
返回值
  类型：逻辑型
  意思：是否成功
备注：支持的类型有:int long uint32_t __int64x __int64u float double
*********************************************************************/
extern "C" bool Algorithm_Math_Swap(XPVOID lPSource, XPVOID lPDest, LPCXSTR lpszType = "int");
/********************************************************************
函数名称：Algorithm_Math_GetValue
函数功能：获取一个数字的符号位从低到高位上的数字
 参数.一：nValue
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要获取的数字
 参数.二：pInt_Bits
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的内容
 参数.三：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出内容数组个数
返回值
  类型：逻辑型
  意思：是否成功
备注：支持正负数
*********************************************************************/
extern "C" bool Algorithm_Math_GetValue(__int64x nValue, __int64x *pInt_Bits, int* pInt_Count);
/********************************************************************
函数名称：Algorithm_Math_GetBit
函数功能：获取二进制数值的某一位
 参数.一：lParam
  In/Out：In
  类型：无符号指针
  可空：N
  意思：输入要获取的值
 参数.二：nBits
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要获取哪一位的值
 参数.三：lPBits
  In/Out：Out
  类型：无符号指针
  可空：N
  意思：输出获取到的值(如果此位为0,那么返回0,如果为1,返回这个位的十进制数)
 参数.四：nSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入输出缓冲区大小.sizeof(*)
返回值
  类型：逻辑型
  意思：是否成功
备注：145 = 10010001,从右到左数0 1 2 3
*********************************************************************/
extern "C" bool Algorithm_Math_GetBit(XPVOID lParam, int nBits, XPVOID lPBits, int nSize = 4);
/********************************************************************
函数名称：Algorithm_Math_SetBit
函数功能：设置二进制数值的某一位
 参数.一：lParam
  In/Out：In/Out
  类型：无符号指针
  可空：N
  意思：输入要设置的值,输出设置完成后的值
 参数.二：nBits
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要设置哪一位的值
 参数.三：nSet
  In/Out：In
  类型：整数型
  可空：Y
  意思：这个位要设置为1,还是0,只能是这两个值
 参数.四：nSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入输出缓冲区大小.sizeof(*)
返回值
  类型：逻辑型
  意思：是否成功
备注：145 = 10010001,从右到左数0 1 2 3
*********************************************************************/
extern "C" bool Algorithm_Math_SetBit(XPVOID lParam, int nBits, int nSet = 1, int nSize = 4);
/************************************************************************/
/*                     计算类导出函数                                   */
/************************************************************************/
/********************************************************************
函数名称：Algorithm_Calculation_Create
函数功能：创建一个计算函数
 参数.一：nTraceTime
  In/Out：In
  类型：整数型
  可空：N
  意思：输入追溯时间范围,单位:秒
返回值
  类型：句柄
  意思：返回句柄数据,失败,返回NULL
备注：追溯模式可以计算多少秒内的平均次数或者流量
*********************************************************************/
extern "C" XHANDLE Algorithm_Calculation_Create(int nTraceTime = 0);
/********************************************************************
函数名称：Algorithm_Calculation_Close
函数功能：关闭一个创建的计算句柄
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_Close(XHANDLE pxhToken);
/********************************************************************
函数名称：Algorithm_Calculation_Reset
函数功能：重置数据函数
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：nTraceTime
  In/Out：In
  类型：整数型
  可空：Y
  意思：追溯时间.为0不修改
 参数.三：bTime
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否重置次数信息
 参数.四：bSDFlow
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否重置发送流量
 参数.五：bRVFlow
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否重置接受流量
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_Reset(XHANDLE pxhToken, int nTraceTime = 0, bool bTime = true, bool bSDFlow = true, bool bRVFlow = true);
/********************************************************************
函数名称：Algorithm_Calculation_SetTime
函数功能：增加一次使用次数
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：和Algorithm_Calculation_GetTime配合使用
*********************************************************************/
extern "C" bool Algorithm_Calculation_SetTime(XHANDLE pxhToken);
/********************************************************************
函数名称：Algorithm_Calculation_GetTime
函数功能：获取平均次数
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Timer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出平均调用次数
 参数.三：bTrace
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是获取总的还是追溯的
返回值
  类型：逻辑型
  意思：是否成功
备注：通过开始时间到调用此函数为止的平均调用次数,单位为秒
*********************************************************************/
extern "C" bool Algorithm_Calculation_GetTime(XHANDLE pxhToken, __int64u * pInt_Timer, bool bTrace = false);
/********************************************************************
函数名称：Algorithm_Calculation_ADDRVFlow
函数功能：增加接受流量
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：nFlow
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要添加的接受的流量大小,单位:字节
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_ADDRVFlow(XHANDLE pxhToken, int nFlow);
/********************************************************************
函数名称：Algorithm_Calculation_ADDSDFlow
函数功能：增加发送流量
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：nFlow
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要添加的发送的流量大小,单位:字节
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_ADDSDFlow(XHANDLE pxhToken, int nFlow);
/********************************************************************
函数名称：Algorithm_Calculation_GetRVFlow
函数功能：获取接受流量的平均流量
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Timer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出接受的每秒平均流量
 参数.三：bTrace
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是获取总的还是追溯的
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_GetRVFlow(XHANDLE pxhToken, __int64u * pInt_Timer, bool bTrace = false);
/********************************************************************
函数名称：Algorithm_Calculation_GetSDFlow
函数功能：获取发送流量的平均流量
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Timer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出发送的每秒平均流量
 参数.三：bTrace
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是获取总的还是追溯的
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_GetSDFlow(XHANDLE pxhToken, __int64u * pInt_Timer, bool bTrace = false);
/********************************************************************
函数名称：Algorithm_Calculation_GetFlowHighest
函数功能：获取发送接受流量以来每秒最高平均速度
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_SDFlow
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出发送的最高每秒平均流量
 参数.三：pInt_RVFlow
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出接受的最高每秒平均流量
返回值
  类型：逻辑型
  意思：是否成功
备注：需要启用时间追踪才有效
*********************************************************************/
extern "C" bool Algorithm_Calculation_GetFlowHighest(XHANDLE pxhToken, __int64u* pInt_SDFlow = NULL, __int64u* pInt_RVFlow = NULL);
/********************************************************************
函数名称：Algorithm_Calculation_GetFlowLowest
函数功能：获取发送接受流量以来每秒最低平均速度
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_SDFlow
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出发送的最低每秒平均流量
 参数.三：pInt_RVFlow
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出接受的最低每秒平均流量
返回值
  类型：逻辑型
  意思：是否成功
备注：需要启用时间追踪才有效
*********************************************************************/
extern "C" bool Algorithm_Calculation_GetFlowLowest(XHANDLE pxhToken, __int64u* pInt_SDFlow = NULL, __int64u* pInt_RVFlow = NULL);
/********************************************************************
函数名称：Algorithm_Calculation_GetCount
函数功能：获取统计信息
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Timer
  In/Out：Out
  类型：整数型
  可空：Y
  意思：输出次数统计
 参数.三：pInt_SDFlow
  In/Out：Out
  类型：整数型
  可空：Y
  意思：输出发送数据统计
 参数.四：pInt_RVFlow
  In/Out：Out
  类型：整数型
  可空：Y
  意思：输出接受数据统计
 参数.五：bTrace
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入是追溯数据统计还是总共的统计信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_GetCount(XHANDLE pxhToken, __int64u* pInt_Timer = NULL, __int64u* pInt_SDFlow = NULL, __int64u* pInt_RVFlow = NULL, bool bTrace = false);
/********************************************************************
函数名称：Algorithm_Calculation_Sleep
函数功能：根据带宽限制参数计算休眠时间
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_WaitTime
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出sleep的值,如果结果为0,那么返回输入的值
 参数.三：nLimitCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入限制总大小,比如1000.单位字节...
 参数.四：nUserCount
  In/Out：In
  类型：整数型
  可空：N
  意思：用户个数(每次循环调用次数)
 参数.五：nSendCount
  In/Out：In
  类型：整数型
  可空：N
  意思：每次调用处理数据大小,单位字节
返回值
  类型：逻辑型
  意思：是否成功
备注：休眠函数使用微妙作为精度
*********************************************************************/
extern "C" bool Algorithm_Calculation_SleepFlow(XHANDLE pxhToken, __int64u * pInt_WaitTime, __int64x nLimitCount, __int64x nUserCount, __int64x nSendCount);
/********************************************************************
函数名称：Algorithm_Calculation_PassiveOPen
函数功能：被动模式开启
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：fpCall_CBPassive
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：触发设置后的回调函数
 参数.三：nAvgSDFlow
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入发送的触发值,为0不启用
 参数.四：nAvgSDFlow
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入接受的触发值
 参数.五：nAvgTime
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入次数的触发值
 参数.六：bTrace
  In/Out：In
  类型：整数型
  可空：Y
  意思：是否使用追踪模式
 参数.七：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：输入自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_PassiveOPen(XHANDLE pxhToken, CALLBACK_XENGINE_BASELIB_ALGORITHM_PASSIVE fpCall_CBPassive, int nAvgSDFlow = 0, int nAvgRVFlow = 0, int nAvgTime = 0, bool bTrace = false, XPVOID lParam = NULL);
/********************************************************************
函数名称：Algorithm_Calculation_PassiveClose
函数功能：被动触发器关闭
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：blParamDel
  In/Out：In
  类型：句柄
  可空：N
  意思：删除自定义参数内存,使用此功能内存必须是malloc的才可以
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Algorithm_Calculation_PassiveClose(XHANDLE pxhToken, bool blParamDel = false);