#pragma once
/********************************************************************
//	Created:	2012/11/23  16:24
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Lib\NetEngine_Algorithm\Algorithm_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Lib\NetEngine_Algorithm
//	File Base:	Algorithm_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	算法库导出模块函数
//	History:    编译需要 -static-libstdc++ -lpthread
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD Algorithm_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                     字符串算法导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：Algorithm_String_XFastMatch
函数功能：血与荣誉快速匹配算法
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
 参数.三：pInt_Pos
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出匹配后的字符串位置，123456 m 45 返回的就是6
 参数.四：nSourceLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入原始字符串长度，可以为0。0原始字符串不能是二进制。
返回值
  类型：逻辑型
  意思：是否匹配成功
备注：支持字符串和二进制快速匹配
*********************************************************************/
extern "C" BOOL Algorithm_String_XFastMatch(LPCSTR lpszSourceStr, LPCSTR lpszFindStr, int *pInt_Pos, int nSourceLen = 0);
/********************************************************************
函数名称：Algorithm_String_HEXToInt
函数功能：16进制字符串转到10进制整数型
 参数.一：lpszSourceStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
返回值
  类型：整数型
  意思：转换后的值
备注：
*********************************************************************/
extern "C" int Algorithm_String_HEXToInt(LPCSTR lpszSourceStr);
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
extern "C" BOOL Algorithm_FSort_DoubleSort(int *pInt_ArrayNumber, int nCount);
/********************************************************************
函数名称：Algorithm_FSort_QSort
函数功能：快速排序算法
 参数.一：lPBase
  In/Out：In/Out
  类型：五类型指针
  可空：N
  意思：输入：要排序的结构,输出：排序好的
 参数.二：nNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要排序的个数
 参数.三：nSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要排序的结构大小
返回值
  类型：逻辑型
  意思：是否排序成功
备注：
*********************************************************************/
extern "C" BOOL Algorithm_FSort_QSort(LPVOID lPBase, int nNumber, int nSize);
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
extern "C" BOOL Algorithm_FSort_InsertSort(int *pInt_Array, int nValue);
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
备注：支持的类型有:int long uint32_t __int64x uint64_t float double
*********************************************************************/
extern "C" BOOL Algorithm_Math_Swap(LPVOID lPSource, LPVOID lPDest, LPCSTR lpszType = _T("int"));
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
  类型：整数型
  可空：N
  意思：输出获取到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：支持正负数
*********************************************************************/
extern "C" BOOL Algorithm_Math_GetValue(__int64x nValue, __int64x *pInt_Bits);
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
extern "C" BOOL Algorithm_Math_GetBit(LPVOID lParam, int nBits, LPVOID lPBits, int nSize = 4);
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
extern "C" BOOL Algorithm_Math_SetBit(LPVOID lParam, int nBits, int nSet = 1, int nSize = 4);
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
extern "C" BOOL Algorithm_Calculation_Close(XHANDLE pxhToken);
/********************************************************************
函数名称：Algorithm_Calculation_ResetTime
函数功能：重置开始时间函数
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：nTraceTime
  In/Out：In
  类型：句柄
  可空：N
  意思：输入追溯时间范围
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Algorithm_Calculation_ResetTime(XHANDLE pxhToken, int nTraceTime = 0);
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
extern "C" BOOL Algorithm_Calculation_SetTime(XHANDLE pxhToken);
/********************************************************************
函数名称：Algorithm_Calculation_GetTime
函数功能：获取平均次数
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pdl_CallSecond
  In/Out：Out
  类型：双精度浮点型
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
extern "C" BOOL Algorithm_Calculation_GetTime(XHANDLE pxhToken, double* pdl_CallSecond, BOOL bTrace = FALSE, BOOL * pbOperator = NULL);
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
extern "C" BOOL Algorithm_Calculation_ADDRVFlow(XHANDLE pxhToken, int nFlow);
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
extern "C" BOOL Algorithm_Calculation_ADDSDFlow(XHANDLE pxhToken, int nFlow);
/********************************************************************
函数名称：Algorithm_Calculation_GetRVFlow
函数功能：获取接受流量的平均流量
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pdl_Second
  In/Out：Out
  类型：双精度浮点型
  可空：N
  意思：输出接受的每秒平均流量
 参数.三：bTrace
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是获取总的还是追溯的
 参数.四：pbOperator
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：如果设置了限制,这个参数可用,表示是否可以继续操作
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Algorithm_Calculation_GetRVFlow(XHANDLE pxhToken, double* pdl_Second, BOOL bTrace = FALSE, BOOL * pbOperator = NULL);
/********************************************************************
函数名称：Algorithm_Calculation_GetSDFlow
函数功能：获取发送流量的平均流量
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pdl_Second
  In/Out：Out
  类型：双精度浮点型
  可空：N
  意思：输出发送的每秒平均流量
 参数.三：bTrace
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是获取总的还是追溯的
 参数.四：pbOperator
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：如果设置了限制,这个参数可用,表示是否可以继续操作
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Algorithm_Calculation_GetSDFlow(XHANDLE pxhToken, double* pdl_Second, BOOL bTrace = FALSE, BOOL * pbOperator = NULL);
/********************************************************************
函数名称：Algorithm_Calculation_SetLimit
函数功能：设置限制
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：nCountRecv
  In/Out：In
  类型：整数型
  可空：Y
  意思：最大接受流量
 参数.三：nCountSend
  In/Out：In
  类型：整数型
  可空：Y
  意思：最大发送流量
 参数.四：nCountTime
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入次数限制
 参数.五：nCountType
  In/Out：In
  类型：整数型
  可空：Y
  意思：限制类型,0 不启用 1:每秒 其他暂时不支持
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Algorithm_Calculation_SetLimit(XHANDLE pxhToken, int nCountRecv = 0, int nCountSend = 0, int nCountTime = 0, int nCountType = 1);
/********************************************************************
函数名称：Algorithm_Calculation_GetLimit
函数功能：获得限制信息
 参数.一：pxhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_CountRecv
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出设置的接受流量
 参数.三：pInt_CountSend
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出设置的发送流量
 参数.四：pInt_CountTime
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出设置的次数
 参数.五：pInt_CountType
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出设置的限制类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Algorithm_Calculation_GetLimit(XHANDLE pxhToken, int* pInt_CountRecv = NULL, int* pInt_CountSend = NULL, int* pInt_CountTime = NULL, int* pInt_CountType = NULL);