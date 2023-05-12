﻿#pragma once
/********************************************************************
//	Created:	2012/6/4  17:38
//	File Name: 	/BaseLib_Linux/BaseLib_SourceCode/BaseLib_Lib/BaseLib_PublicOperator/NetOperator_Define.h
//	File Path:	/BaseLib_Linux/BaseLib_SourceCode/BaseLib_Lib/BaseLib_PublicOperator/
//	File Base:	NetOperator_Define.h
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎) For Linux
//	Author:		dowflyon
//	Purpose:	导出的操作库函数
//	History:
*********************************************************************/
#define XW2A(a,b,c) BaseLib_OperatorString_UnicodeToAnsi(a,b,c)
#define XA2W(a,b,c) BaseLib_OperatorString_AnsiToUnicode(a,b,c)
//////////////////////////////////////////////////////////////////////////////////
//                         回调函数
//////////////////////////////////////////////////////////////////////////////////
//触发器ID,触发器设置的时间,触发器当前次数(-1 或者剩余次数),自定义参数
typedef void(CALLBACK* CALLBACK_XENGINE_LIB_BASELIB_TIME_TRIGGER)(int nIDEvent, __int64x nMillTimer, int nTTNumber, XPVOID lParam);
//////////////////////////////////////////////////////////////////////////////////
//                         导出的类型定义
//////////////////////////////////////////////////////////////////////////////////
//IPV4范围分类
typedef enum 
{
	ENUM_XENGINE_BASELIB_IPV4_TYPE_UNKNOW = 0,
	ENUM_XENGINE_BASELIB_IPV4_TYPE_A = 1,
	ENUM_XENGINE_BASELIB_IPV4_TYPE_B = 2,
	ENUM_XENGINE_BASELIB_IPV4_TYPE_C = 3,
	ENUM_XENGINE_BASELIB_IPV4_TYPE_D = 4,
	ENUM_XENGINE_BASELIB_IPV4_TYPE_E = 5
}ENUM_XENGINE_BASELIB_IPV4_TYPE, * LPENUM_XENGINE_BASELIB_IPV4_TYPE;
//IPV6地址类型
typedef enum
{
	ENUM_XENGINE_BASELIB_IPV6_TYPE_UNKNOW = 0,
	ENUM_XENGINE_BASELIB_IPV6_TYPE_NOAMAL = 1,                           //常规地址
	ENUM_XENGINE_BASELIB_IPV6_TYPE_ABBREVIATION = 2,                     //经过压缩的地址
	ENUM_XENGINE_BASELIB_IPV6_TYPE_MAPPING = 3,                          //IPV4映射地址
	ENUM_XENGINE_BASELIB_IPV6_TYPE_COMPATBLE = 4                         //IPV4兼容地址
}ENUM_XENGINE_BASELIB_IPV6_TYPE, * LPENUM_XENGINE_BASELIB_IPV6_TYPE;
//IP地址类型
typedef enum
{
	ENUM_XENGINE_BASELIB_IPADDR_TYPE_UNKNOW = 0,
	ENUM_XENGINE_BASELIB_IPADDR_TYPE_LOOP = 1,                           //回环地址
	ENUM_XENGINE_BASELIB_IPADDR_TYPE_UNICAST = 2,                        //单播地址
	ENUM_XENGINE_BASELIB_IPADDR_TYPE_GROUPCAST = 3,                      //组播地址
	ENUM_XENGINE_BASELIB_IPADDR_TYPE_BROADCAST = 4,                      //广播地址,IPV6本地链路,用于邻里发现
    ENUM_XENGINE_BASELIB_IPADDR_TYPE_LAN = 5,                            //内网地址,IPV6表示私有地址,不参与全球通信
}ENUM_XENGINE_BASELIB_IPADDR_TYPE, * LPENUM_XENGINE_BASELIB_IPADDR_TYPE;
//时间类型
typedef enum
{
    ENUM_XENGINE_BASELIB_TIME_SPAN_TYPE_DAY = 0,
    ENUM_XENGINE_BASELIB_TIME_SPAN_TYPE_HOUR = 1,
    ENUM_XENGINE_BASELIB_TIME_SPAN_TYPE_MINUTE = 2,
    ENUM_XENGINE_BASELIB_TIME_SPAN_TYPE_SECOND = 3
}ENUM_XENGINE_BASELIB_TIME_SPAN_TYPE;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    time_t tv_sec;
    __int64u tv_usec;
    __int64u tv_value;
}XENGINE_VALTIME;
//时间信息结构
typedef struct
{
    int wYear;                                                                    //年
    int wMonth;                                                                   //月
    int wDay;                                                                     //日
    int wHour;                                                                    //小时
    int wMinute;                                                                  //分钟
    int wSecond;                                                                  //秒
    __int64x wMicroseconds;                                                        //微妙
    int wDayofYear;                                                               //一年的某一天
    int wDayofWeek;                                                               //一周的星期几
    int wFlags;                                                                   //公历中表示夏令时标志,阴历中表示闰年
}XENGINE_LIBTIMER,*LPXENGINE_LIBTIMER;
//地址结构体,支持IPV4和IPV6.如果是IPV4,那么只有1-4成员有效,如果是IPV6,所有都有效,并且是16进制表示
//如果是IPV6压缩模式,那么根据有值的内容确定压缩位置,比如FF01::1,有值的就是IP1,IP3,IP2为空表示中间压缩
typedef struct
{
    int nIPAddr1;
    int nIPAddr2;
    int nIPAddr3;
    int nIPAddr4;
    int nIPAddr5;
    int nIPAddr6;
    int nIPAddr7;
    int nIPAddr8;
    int nIPVer;                                                                  //IP版本,AF_INET(2) AF_INET6(23)
}XENGINE_LIBADDR, *LPXENGINE_LIBADDR;
//版本号
typedef struct  
{
    unsigned short int nVerCore;                                                  //核心版本号
    unsigned short int nVerMain;                                                  //主版本号
    unsigned short int nVerSub;                                                   //次版本号
    unsigned short int nVerFix;                                                   //修复版本号
    ENUM_XENGINE_VERSION_TYPE enVType;                                            //版本类型
}XENGINE_LIBVERSION, * LPXENGINE_LIBVERSION;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG BaseLib_GetLastError(int *pInt_SysError = NULL);
/*********************************************************************************
*                          事件管理器导出的函数                                     *
*********************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorEvent_Create
函数功能：创建一个事件
 参数.一：bActiveMode
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：事件模式,自动还是手动,默认手动
返回值
  类型：逻辑型
  意思：是否成功
备注：如果是自动模式,需要使用BaseLib_OperatorEvent_Reset来设置为无信号状态.否则会一直触发
*********************************************************************/
extern "C" XEVENT BaseLib_OperatorEvent_Create(bool bActiveMode = false);
/********************************************************************
函数名称：BaseLib_OperatorEvent_Wait
函数功能：等待一个事件被激活
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要等待的事件句柄
返回值
  类型：逻辑型
  意思：是否等待成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEvent_Wait(XEVENT xhEvent);
/********************************************************************
函数名称：BaseLib_OperatorEvent_WaitTimedOut
函数功能：超时等待事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要等待的事件句柄
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：N
  意思：等待超时的时间，时间为毫秒
返回值
  类型：逻辑型
  意思：是否等待成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEvent_WaitTimedOut(XEVENT xhEvent,int nTimeOut);
/********************************************************************
函数名称：BaseLib_OperatorEvent_Avtive
函数功能：激活一个等待的事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要激活的事件句柄
返回值
  类型：逻辑型
  意思：是否激活成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEvent_Avtive(XEVENT xhEvent);
/********************************************************************
函数名称：BaseLib_OperatorEvent_Reset
函数功能：重置事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要重置的事件句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEvent_Reset(XEVENT xhEvent);
/********************************************************************
函数名称：BaseLib_OperatorEvent_Delete
函数功能：删除一个事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要删除的事件句柄
返回值
  类型：逻辑型
  意思：是否成功删除一个事件
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEvent_Delete(XEVENT xhEvent);
//信号操作，可以支持队列
/********************************************************************
函数名称：BaseLib_OperatorSemaphore_Create
函数功能：创建一个信号量
 参数.一：lpszSemaphoreName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入信号量名称,这个值可以和BaseLib_OperatorSemaphore_IsExist做进程互斥
 参数.二：nMaxCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：最大允许信号个数
返回值
  类型：句柄
  意思：返回创建成功的句柄,失败返回NULL
备注：
*********************************************************************/
extern "C" XEVENT BaseLib_OperatorSemaphore_Create(LPCXSTR lpszSemaphoreName = NULL, int nMaxCount = 65535);
/********************************************************************
函数名称：BaseLib_OperatorSemaphore_IsExist
函数功能：判断一个信号量是否存在
 参数.一：lpszSemaphoreName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要判断的信号名称
返回值
  类型：逻辑型
  意思：存在返回真,不存在返回假
备注：这个函数可以用来做进程间的互斥
*********************************************************************/
extern "C" bool BaseLib_OperatorSemaphore_IsExist(LPCXSTR lpszSemaphoreName);
/********************************************************************
函数名称：BaseLib_OperatorSemaphore_Wait
函数功能：超时等待事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要等待的事件句柄
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：等待超时的时间，时间毫秒,默认不超时
返回值
  类型：逻辑型
  意思：是否等待成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorSemaphore_Wait(XEVENT xhEvent, int nTimeOut = -1);
/********************************************************************
函数名称：BaseLib_OperatorSemaphore_Avtive
函数功能：激活一个等待的事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要激活的事件句柄
 参数.二：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出待处理的信号次数,macos不支持
返回值
  类型：逻辑型
  意思：是否激活成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorSemaphore_Avtive(XEVENT xhEvent, int* pInt_Count = NULL);
/********************************************************************
函数名称：BaseLib_OperatorSemaphore_Delete
函数功能：删除一个事件
 参数.一：xhEvent
  In/Out：In
  类型：句柄
  可空：N
  意思：要删除的事件句柄
返回值
  类型：逻辑型
  意思：是否成功删除一个事件
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorSemaphore_Delete(XEVENT xhEvent);
/*********************************************************************************
*                          句柄管理器导出的函数                                  *
*********************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorHandle_Create
函数功能：创建一个网络句柄
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出一个创建成功的网络句柄
 参数.二：nStartRange
  In/Out：In
  类型：整数型
  可空：Y
  意思：最低开始句柄随机数范围
 参数.三：nEndRange
  In/Out：In
  类型：整数型
  可空：Y
  意思：最高结束句柄随机数范围
 参数.四：bAuto
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：自动处理,保证不重复
返回值
  类型：逻辑型
  意思：是否创建成功
备注：创建独立的句柄，将没有对应的值
*********************************************************************/
extern "C" bool BaseLib_OperatorHandle_Create(PXNETHANDLE pxhNet, __int64x nStartRange = 1000000001, __int64x nEndRange = 9000000002, bool bAuto = true);
/********************************************************************
函数名称：BaseLib_OperatorHandle_CreateStr
函数功能：创建指定位数随机字符串
 参数.一：ptszKey
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出创建后的值
 参数.二：nSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要创建多少位
 参数.三：nType
  In/Out：In
  类型：整数型
  可空：Y
  意思：创建类型,默认0随机,1为全数字,2为全字母
 参数.四：nCharType
  In/Out：In
  类型：整数型
  可空：Y
  意思：字母类型,0为随机,1全部大写,2全部小写
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorHandle_CreateStr(XCHAR* ptszKey, int nSize = 16, int nType = 0, int nCharType = 0);
/********************************************************************
函数名称：BaseLib_OperatorHandle_CreateGuid
函数功能：生成一个GUID字符串
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出的缓冲区
 参数.二：bLine
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否添加-,默认添加
 参数.三：bUPPer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否使用大写,默认导出字母为大写
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorHandle_CreateGuid(XCHAR *ptszMsgBuffer, bool bLine = true, bool bUPPer = true);
/*********************************************************************************
*                          字符集转换导出                                        *
*********************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorCharset_AnsiToUnicode
函数功能：把ANSI字符串转为UNICODE字符串
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要转换的ANSI字符串
 参数.二：pszDest
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出转换后的缓冲区
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：输入提供缓冲区大小,输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二为NULL表示不转换,只导出需要的大小
*********************************************************************/
extern "C" bool BaseLib_OperatorCharset_AnsiToUnicode(const char* lpszSource, wchar_t* pszDest = NULL, int* pInt_Len = NULL);
/********************************************************************
函数名称：BaseLib_OperatorCharset_UnicodeToAnsi
函数功能：把UNICODE字符串转为ANSI字符串
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要转换的UNICODE字符串
 参数.二：pszDest
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出转换后的缓冲区
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小,输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二为NULL表示不转换,只导出需要的大小
*********************************************************************/
extern "C" bool BaseLib_OperatorCharset_UnicodeToAnsi(const wchar_t* lpszSource, char* pszDest = NULL, int* pInt_Len = NULL);
/********************************************************************
函数名称：BaseLib_OperatorCharset_UTFToUnicode
函数功能：UTF8转UNICODE
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
 参数.二：ptszDst
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的字符串
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorCharset_UTFToUnicode(const char* lpszSource, wchar_t* ptszDst, int* pInt_Len);
/********************************************************************
函数名称：BaseLib_OperatorCharset_UTFToAnsi
函数功能：UTF8转ANSI
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
 参数.二：ptszDst
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的字符串
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorCharset_UTFToAnsi(const char* lpszSource, char* ptszDst, int* pInt_Len);
/********************************************************************
函数名称：BaseLib_OperatorCharset_UnicodeToUTF
函数功能：UNICODE转UTF8
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
 参数.二：ptszDst
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的字符串
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorCharset_UnicodeToUTF(const wchar_t* lpszSource, char* ptszDst, int* pInt_Len);
/********************************************************************
函数名称：BaseLib_OperatorCharset_AnsiToUTF
函数功能：ANSI转UTF8
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
 参数.二：ptszDst
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的字符串
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorCharset_AnsiToUTF(const char* lpszSource, char* ptszDst, int* pInt_Len);
/*********************************************************************************
*                          字符串操作导出的函数                                  *
*********************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorString_DelSub
函数功能：从一个指定的字符串中删除指定字符串
 参数.一：ptszSource
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入：待删除的字符串缓冲区，导出，删除后的字符串
 参数.二：lpszDelString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_DelSub(XCHAR *ptszSource, LPCXSTR lpszDelString);
/********************************************************************
函数名称：BaseLib_OperatorString_Change
函数功能：从一个指定的缓冲区中查找开始和结束位置的中间进行字符串修改和插入操作
 参数.一：ptszSource
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：导入原始字符串，导出操作成功后的字符串
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入原始字符串长度，输出修改后字符串长度
 参数.三：lpszStart
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：要查找的开始字符串
 参数.四：lpszEnd
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：要查找的结束字符串
 参数.五：lpszChange
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：要修改或者插入的字符串
 参数.六：bMixMatch
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用最小匹配,启用后将会一直搜索到匹配到的最小索引
返回值
  类型：逻辑型
  意思：是否改变成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_Change(XCHAR *ptszSource,int *pInt_Len, LPCXSTR lpszStart, LPCXSTR lpszEnd, LPCXSTR lpszChange, bool bMixMatch = false);
/********************************************************************
函数名称：BaseLib_OperatorString_GetStartEnd
函数功能：通过开始和结束字符串获取中间的字符串
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的源字符串内容
 参数.二：ptszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：获取到的字符串保存位置
 参数.三：lpszStart
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：开始字符串
 参数.四：lpszEnd
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：结束字符串
 参数.五：bMixMatch
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用最小匹配,启用后将会一直搜索到匹配到的最小索引
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_GetStartEnd(LPCXSTR lpszSource,XCHAR *ptszDest, LPCXSTR lpszStart, LPCXSTR lpszEnd, bool bMixMatch = false);
/********************************************************************
函数名称：BaseLib_OperatorString_GetFileAndPath
函数功能：通过URL获取文件路径和文件名
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：路径地址
 参数.二：ptszPath
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：全路径
 参数.三：ptszFile
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：文件名称
 参数.四：ptszDrive
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：驱动器名称
 参数.五：ptszFileExt
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：文件扩展名
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_GetFileAndPath(LPCXSTR lpszUrl, XCHAR * ptszPath = NULL, XCHAR * ptszFile = NULL, XCHAR * ptszDrive = NULL, XCHAR * ptszFileExt = NULL);
/********************************************************************
函数名称：BaseLib_OperatorString_GetKeyValue
函数功能：通过一个字符串，从一段字符串中分割出前后两个内容
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要分割的字符串
 参数.二：lpszSqlit
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：作为分割的字符串
 参数.三：ptszKey
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出分割之前的部分
 参数.四：ptszValue
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出分割之后的部分
 参数.五：bBreak
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否跳过首位空格
 参数.六：pInt_Hdr
  In/Out：Out
  类型：整数指针
  可空：Y
  意思：导出HTTP头的长度
 参数.七：pInt_Body
  In/Out：Out
  类型：整数指针
  可空：Y
  意思：导出HTTP内容长度
返回值
  类型：逻辑型
  意思：是否分割成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_GetKeyValue(LPCXSTR lpszSource, LPCXSTR lpszSqlit, XCHAR * ptszKey = NULL, XCHAR * ptszValue = NULL, bool bBreak = true, int* pInt_Hdr = NULL, int* pInt_Body = NULL);
/********************************************************************
函数名称：BaseLib_OperatorString_FixPath
函数功能：修复路径字符串
 参数.一：ptszStrBuffer
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要修改的路径缓冲区,输出修复好的缓冲区
 参数.二：nType
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要处理的路径,0,自动,1使用绝对路径,2使用相对路径
 参数.三：nRelativeCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：如果大于0,那么绝对路径将被修改为相对路径,并且设置相对路径保留的路径数
返回值
  类型：逻辑型
  意思：是否成功
备注：通过此函数可以修正对于绝对路径或者相对路径中出现其他路径标识符的问题
      比如 C:\\aa/b.txt 可以修复为C:\\aa\\b.txt
*********************************************************************/
extern "C" bool BaseLib_OperatorString_FixPath(XCHAR* ptszStrBuffer, int nType = 0, int nRelativeCount = 0);
/********************************************************************
函数名称：BaseLib_OperatorString_GetPath
函数功能：获取路径字符串类型
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的缓冲区
 参数.二：pInt_Type
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输入要处理的路径,1绝对路径,2相对路径
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_GetPath(LPCXSTR lpszMsgBuffer, int* pInt_Type = NULL);
/********************************************************************
函数名称：BaseLib_OperatorString_StrToHex
函数功能：字符串转十六进制
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要转换的字符串
 参数.二：nSrcLen
  In/Out：In
  类型：整数型
  可空：N
  意思：字符串长度
 参数.三：ptszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出16进制字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_StrToHex(LPCXSTR lpszSource, int nSrcLen, XCHAR *ptszDest);
/********************************************************************
函数名称：BaseLib_OperatorString_HexToStr
函数功能：十六进制转字符串
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要转换的缓冲区
 参数.二：nSrcLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区长度
 参数.三：ptszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorString_HexToStr(LPCXSTR lpszSource, int nSrcLen, XCHAR *ptszDest);
/*********************************************************************************
*                          时间操作导出的函数                                       *
*********************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorTime_GetTimeOfday
函数功能：与LINUX gettimeofday 函数功能相同，意思参考LINUX的。
返回值
  类型：逻辑型
  意思：是否获取成功
备注：参数二被省略了，默认为NULL
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_GetTimeOfday(XENGINE_VALTIME * pSt_Timeval);
/********************************************************************
函数名称：BaseLib_OperatorTime_GetSysTime
函数功能：获取系统时间
 参数.一：pSt_LibTimer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出时间信息
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_GetSysTime(LPXENGINE_LIBTIMER pSt_LibTimer);
/********************************************************************
函数名称：BaseLib_OperatorTime_GetTickCount
函数功能：获取系统开机以来的毫秒数
 参数.一：b64BIt
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的GMT时间格式字符串
返回值
  类型：无符号长长整型
  意思：返回毫秒数
备注：这个函数没有错误处理，和WINDOWS效果一样
*********************************************************************/
extern "C" __int64u BaseLib_OperatorTime_GetTickCount(bool b64BIt = false);
extern "C" __int64u BaseLib_OperatorTime_GetTickCount64();
/********************************************************************
函数名称：BaseLib_OperatorTime_TimeToStr
函数功能：时间结构转字符串
 参数.一：ptszYMDTimer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出时间的年月日,如果bIsCombo为真那么将导出完整的时间格式字符串
 参数.二：ptszHMSTimer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出时间的时分秒结构
 参数.三：bIsCombo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：参数一是否打包成完整时间
 参数.四：pSt_Timer
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入要转换的时间,为NULL获取当前时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_TimeToStr(XCHAR* ptszYMDTimer, XCHAR * ptszHMSTimer = NULL, bool bIsCombo = true, XENGINE_LIBTIMER* pSt_Timer = NULL);
/********************************************************************
函数名称：BaseLib_OperatorTime_StrToTime
函数功能：字符串转结构体
 参数.一：lpszTimer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的时间格式%d-%d-%d %d:%d:%d
 参数.二：pSt_LibTimer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出转换成功的格式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_StrToTime(LPCXSTR lpszTimer, XENGINE_LIBTIMER* pSt_LibTimer);
/********************************************************************
函数名称：BaseLib_OperatorTime_TTimeToStuTime
函数功能：TIME时间转数据结构时间
 参数.一：ulTimer
  In/Out：In
  类型：无符号长整数型
  可空：N
  意思：要转换的TIME获取或者返回的时间
 参数.二：pSt_LibTimer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出TIME的数据结构时间
返回值
  类型：逻辑型
  意思：是否转换成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_TTimeToStuTime(time_t ulTimer,LPXENGINE_LIBTIMER pSt_LibTimer);
/********************************************************************
函数名称：BaseLib_OperatorTime_StuTimeToTTime
函数功能：时间结构转TIME时间
 参数.一：pSt_LibTimer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要转换的时间
 参数.二：pulTimer
  In/Out：Out
  类型：时间指针
  可空：N
  意思：导出转换后的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_StuTimeToTTime(LPXENGINE_LIBTIMER pSt_LibTimer, time_t* pulTimer);
/********************************************************************
函数名称：BaseLib_OperatorTime_StrToInt
函数功能：字符串转整数型时间
 参数.一：lpszTimeStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
 参数.二：pInt_Time
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的时间
返回值
  类型：逻辑型
  意思：是否成功
备注：时间字符串; 2021-6-09 22:1:03  转换为: 20210609221003
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_StrToInt(LPCXSTR lpszTimeStr, __int64x * pInt_Time);
/********************************************************************
函数名称：BaseLib_OperatorTime_IntToStr
函数功能：整数转字符串
 参数.一：nTime
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要转换的数值
 参数.二：ptszTime
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_IntToStr(__int64x nTime, XCHAR* ptszTime);
/********************************************************************
函数名称：BaseLib_OperatorTime_SetXTPTime
函数功能：设置指定参数为XTP时间格式
 参数.一：pxhXTPTime
  In/Out：Out
  类型：时间句柄指针
  可空：N
  意思：输出设置成功后的时间格式
返回值
  类型：逻辑型
  意思：是否成功
备注：XTP为XENGINE专用时间格式,用于生成当前时间
      XTP高32位为当前UTC时间秒.低32位为UTC时间的微妙
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_SetXTPTime(XNETHANDLE * pxhXTPTime);
/********************************************************************
函数名称：BaseLib_OperatorTime_GetXTPTime
函数功能：转换指定XTP时间为当前显示时间
 参数.一：xhXTPTime
  In/Out：In
  类型：时间句柄
  可空：N
  意思：输出设置成功后的时间格式
 参数.二：pSt_LibTimer
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出转换后的时间
 参数.三：pnTTimer
  In/Out：Out
  类型：时间型
  可空：Y
  意思：输出time时间值,这个值将不包括微妙
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_GetXTPTime(XNETHANDLE xhXTPTime, XENGINE_LIBTIMER * pSt_LibTimer = NULL, time_t * pnTTimer = NULL);
/********************************************************************
函数名称：BaseLib_OperatorTime_GMTTime
函数功能：获取GMT时间字符串
 参数.一：ptszTime
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的GMT时间格式字符串
 参数.二：nTTime
  In/Out：In
  类型：时间类型
  可空：Y
  意思：输入要转换的时间,如果为空,将使用本机时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_GMTTime(XCHAR *ptszTime, time_t nTTime = 0);
/********************************************************************
函数名称：BaseLib_OperatorTime_TimezoneCvt
函数功能：时区转换
 参数.一：pSt_LibTimer
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入要转换的时间结构,输出转换成功的时间结构
 参数.二：nTimeHour
  In/Out：In
  类型：整数型
  可空：N
  意思：输入时间差
 参数.三：bTZRange
  In/Out：In
  类型：整数型
  可空：Y
  意思：时区是加还是减,默认加
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTime_TimezoneCvt(XENGINE_LIBTIMER* pSt_LibTimer, int nTimeHour, bool bTZRange = true);
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_GetForStu
函数功能：通过数据结构获取时间差
 参数.一：pSt_TimeStart
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：开始时间
 参数.二：pSt_TimeEnd
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：结束时间
 参数.三：pInt_Time
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间差值
 参数.四：nType
  In/Out：In
  类型：整数型
  可空：Y
  意思：获取结果值类型,0:天数 1:小时 2:分钟 3:秒钟
 参数.五：bChange
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否支持交换计算,如果为真,那么将取最大的时间来减去最小时间,而不关心开始和结束
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_GetForStu(XENGINE_LIBTIMER *pSt_TimeStart, XENGINE_LIBTIMER *pSt_TimeEnd, __int64x *pInt_Timer, int nType = 0, bool bChange = false);
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_GetForStr
函数功能：通过字符串时间获取时间差
 参数.一：lpszTimeStart
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：开始时间
 参数.二：lpszTimeEnd
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：结束时间
 参数.三：pInt_Time
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间差值
 参数.四：nType
  In/Out：In
  类型：整数型
  可空：Y
  意思：获取结果值类型,0:天数 1:小时 2:分钟 3:秒钟
 参数.五：bChange
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否支持交换计算,如果为真,那么将取最大的时间来减去最小时间,而不关心开始和结束
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二只有天数,小时,分钟和秒才生效,其他值无效,下面的函数一样.
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_GetForStr(LPCXSTR lpszTimeStart, LPCXSTR lpszTimeEnd, __int64x *pInt_Timer, int nType = 0, bool bChange = false);
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_GetForTime
函数功能：通过时间变量获取时间差
 参数.一：nTimeStart
  In/Out：In
  类型：时间类型
  可空：N
  意思：开始时间
 参数.二：nTimeEnd
  In/Out：In
  类型：时间类型
  可空：N
  意思：结束时间
 参数.三：pInt_Time
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间差值
 参数.四：nType
  In/Out：In
  类型：整数型
  可空：Y
  意思：获取结果值类型,0:天数 1:小时 2:分钟 3:秒钟
 参数.五：bChange
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否支持交换计算,如果为真,那么将取最大的时间来减去最小时间,而不关心开始和结束
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_GetForTime(time_t nTimeStart, time_t nTimeEnd, __int64x *pInt_Timer, int nType = 0, bool bChange = false);
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_CalForStu
函数功能：通过时间结构获得两个时间的总值
 参数.一：pSt_TimeStart
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：开始时间
 参数.二：pSt_TimeEnd
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入结束时间,输出他们之间的总值
 参数.三：bAdd
  In/Out：In
  类型：逻辑型
  可空：N
  意思：是相加还是相减
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_CalForStu(XENGINE_LIBTIMER *pSt_TimeStart, XENGINE_LIBTIMER *pSt_TimeEnd, bool bAdd = true);
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_CalForStu
函数功能：通过字符串时间获得两个时间的总值
 参数.一：lpszTimeStart
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：开始时间
 参数.二：lpszTimeEnd
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：结束时间
 参数.三：pSt_Time
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出结果
 参数.四：bAdd
  In/Out：In
  类型：逻辑型
  可空：N
  意思：是相加还是相减
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_CalForStr(LPCXSTR lpszTimeStart, LPCXSTR lpszTimeEnd, XENGINE_LIBTIMER *pSt_Time, bool bAdd = true);
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_CalForStu
函数功能：通过时间类型获得两个时间的总值
 参数.一：nTimeStart
  In/Out：In
  类型：时间类型
  可空：N
  意思：开始时间
 参数.二：nTimeEnd
  In/Out：In
  类型：时间类型
  可空：N
  意思：结束时间
 参数.三：pSt_Time
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出结果
 参数.四：bAdd
  In/Out：In
  类型：逻辑型
  可空：N
  意思：是相加还是相减
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_CalForTime(time_t nTimeStart, time_t nTimeEnd, XENGINE_LIBTIMER *pSt_Time, bool bAdd = true);
/********************************************************************
函数名称：BaseLib_OperatorTimeSpan_GetForGmt
函数功能：通过时间类型获取GMT时间
 参数.一：pSt_Timer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出GMT时间
 参数.二：nTTime
  In/Out：In
  类型：时间类型
  可空：Y
  意思：输入要转换的时间,空为当前时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTimeSpan_GetForGmt(XENGINE_LIBTIMER *pSt_Timer, time_t nTTime = 0);
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：BaseLib_OperatorTTigger_Create
函数功能：创建一个触发计时器
 参数.一：pxhTimer
  In/Out：Out
  类型：触发器句柄
  可空：N
  意思：输出创建好的句柄
 参数.二：fpCall_TTimer
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：输入触发回调函数指针.为NULL表示只是一个获取时间间隔的函数
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTTigger_Create(XHANDLE* pxhTimer, CALLBACK_XENGINE_LIB_BASELIB_TIME_TRIGGER fpCall_TTimer = NULL, XPVOID lParam = NULL);
/********************************************************************
函数名称：BaseLib_OperatorTTigger_Set
函数功能：设置添加一个触发器
 参数.一：pxhTimer
  In/Out：In
  类型：触发器句柄
  可空：N
  意思：输入要操作的触发器
 参数.二：nIDEvent
  In/Out：In
  类型：整数型
  可空：N
  意思：输入触发器ID.这个ID不能重复
 参数.三：nMillTimer
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入间隔多久触发一次,单位毫秒
 参数.四：nCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入触发器触发次数.为-1表示一直触发,为0不触发
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTTigger_Set(XHANDLE pxhTimer, int nIDEvent, __int64x nMillTimer = 0, int nCount = 1);
/********************************************************************
函数名称：BaseLib_OperatorTTigger_Get
函数功能：获取一个触发器开始与当前结束时间间隔
 参数.一：pxhTimer
  In/Out：In
  类型：触发器句柄
  可空：N
  意思：输入要操作的触发器
 参数.二：nIDEvent
  In/Out：In
  类型：整数型
  可空：N
  意思：输入触发器ID
 参数.三：pInt_MillTimer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间间隔,毫秒,可以计算一段代码执行时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTTigger_Get(XHANDLE pxhTimer, int nIDEvent, __int64x* pInt_MillTimer);
/********************************************************************
函数名称：BaseLib_OperatorTTigger_Del
函数功能：删除一个触发器ID
 参数.一：pxhTimer
  In/Out：In
  类型：触发器句柄
  可空：N
  意思：输入要操作的触发器
 参数.二：nIDEvent
  In/Out：In
  类型：整数型
  可空：N
  意思：输入触发器ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorTTigger_Del(XHANDLE pxhTimer, int nIDEvent);
/********************************************************************
函数名称：BaseLib_OperatorTTigger_Destory
函数功能：销毁一个触发器
 参数.一：pxhTimer
  In/Out：In
  类型：触发器句柄
  可空：N
  意思：输入要操作的触发器
返回值
  类型：逻辑型
  意思：是否成功
备注：此操作将删除与之关联的所有ID
*********************************************************************/
extern "C" bool BaseLib_OperatorTTigger_Destory(XHANDLE pxhTimer);
/*********************************************************************************
*                          读写配置文件导出的函数                               *
*********************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorFile_ReadProfileFromFile
函数功能：读取配置文件中的内容并且导出为字符串
 参数.一：lpszFilePath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：配置文件路径
 参数.二：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要读取的关键字 : "[123]" = 123
 参数.三：lpszName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要读取的配置项目的值 Key = Value 中的Key
 参数.四：ptszValue
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的内容
返回值
  类型：整数型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" XLONG BaseLib_OperatorFile_ReadProfileFromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName, XCHAR* ptszValue);
extern "C" int BaseLib_OperatorFile_ReadIntFromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName);
extern "C" __int64x BaseLib_OperatorFile_ReadInt64FromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName);
/********************************************************************
函数名称：BaseLib_OperatorFile_WriteProfileFromFile
函数功能：写一个字符串到配置文件中
 参数.一：lpszFilePath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：配置文件路径
 参数.二：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要写的关键字
 参数.三：lpszName
  In/Out：IN
  类型：常量字符指针
  可空：N
  意思：要写的配置项目的值
 参数.四：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要写入的内容
返回值
  类型：逻辑型
  意思：是否写入成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorFile_WriteProfileFromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName, LPCXSTR lpszValue);
extern "C" bool BaseLib_OperatorFile_WriteInt64FromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName, __int64x nValue);
/********************************************************************
函数名称：BaseLib_OperatorFile_ReadProfileFromMemory
函数功能：从内存读取配置文件信息
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.三：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入配置文件关键字[key]的key
 参数.四：lpszName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入配置文件名称,name = value 的 name
 参数.五：ptszValue
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的配置内容,name = value 的 value
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorFile_ReadProfileFromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, XCHAR* ptszValue);
extern "C" bool BaseLib_OperatorFile_ReadIntFromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, int* pInt_Value);
extern "C" bool BaseLib_OperatorFile_ReadInt64FromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, __int64x * pInt_Value);
/********************************************************************
函数名称：BaseLib_OperatorFile_WriteProfileFromMemory
函数功能：写入配置文件信息到内存
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.三：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入配置文件关键字[key]的key
 参数.四：lpszName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入配置文件名称,name = value 的 name
 参数.五：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要写入的值name = value 的 value
 参数.六：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出内存地址
 参数.七：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的内存大小,输出输出内存大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorFile_WriteProfileFromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, LPCXSTR lpszValue, XCHAR * ptszMsgBuffer, int* pInt_MsgLen);
extern "C" bool BaseLib_OperatorFile_WriteInt64FromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, __int64x nValue, XCHAR * ptszMsgBuffer, int* pInt_MsgLen);
/************************************************************************/
/*                         内存释放函数                                 */
/************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorMemory_Malloc
函数功能：三级指针内存申请
 参数.一：pppszPoint
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出申请好的内存,内存会被初始化为0
 参数.二：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入列表个数
 参数.三：nSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入元素大小
返回值
  类型：逻辑型
  意思：是否成功
备注：用来处理一些特殊导出参数和输入参数.可作为list的代替
*********************************************************************/
extern "C" bool BaseLib_OperatorMemory_Malloc(VOID * **pppszPoint, size_t nCount, size_t nSize);
/********************************************************************
函数名称：BaseLib_OperatorMemory_Free
函数功能：释放三级指针内存
 参数.一：pppszPoint
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要操作的内存
 参数.二：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的元素个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorMemory_Free(VOID * **pppszPoint, size_t nCount);
/********************************************************************
函数名称：BaseLib_OperatorMemory_FreeCStyle
函数功能：释放内存
 参数.一：ppszPoint
  In/Out：In
  类型：字符指针
  可空：N
  意思：要释放的内存
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorMemory_FreeCStyle(VOID** ppszPoint);
/************************************************************************/
/*                         IP地址操作                                   */
/************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_SegAddr
函数功能：网络地址分割
 参数.一：ptszAddr
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入：要分解的IP+端口缓冲区，输出IP地址
 参数.二：pInt_Port
  In/Out：Out
  类型：整数型
  可空：Y
  意思：导出分解后的端口
返回值
  类型：逻辑型
  意思：是否分解成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_SegAddr(XCHAR* ptszAddr, int* pInt_Port = NULL);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_GetIPVer
函数功能：获得IP版本
 参数.一：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的地址
 参数.二：pInt_IPVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出IP地址版本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_GetIPVer(LPCXSTR lpszIPAddr, int* pInt_IPVer);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_GetIPV4Type
函数功能：获取IPV4地址类型
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入地址结构
 参数.二：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出地址类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_GetIPV4Type(XENGINE_LIBADDR * pSt_LibAddr, ENUM_XENGINE_BASELIB_IPADDR_TYPE * penIPType);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_GetIPV6Type
函数功能：获取IPV6地址类型
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入地址结构
 参数.二：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出地址类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_GetIPV6Type(XENGINE_LIBADDR * pSt_LibAddr, ENUM_XENGINE_BASELIB_IPADDR_TYPE * penIPType);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_IsIPV4Addr
函数功能：判断一个缓冲区是否为IP地址
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要判断的缓冲区
 参数.二：pSt_LibAddr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：导出IP分割的地址值
 参数.三：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：Y
  意思：导出此IP地址的分类
返回值
  类型：逻辑型
  意思：返回真表示是IP地址，返回假请获取错误码
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_IsIPV4Addr(LPCXSTR lpszMsgBuffer, XENGINE_LIBADDR* pSt_LibAddr = NULL, ENUM_XENGINE_BASELIB_IPV4_TYPE* penIPType = NULL);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_IsIPV6Addr
函数功能：是否为IPV6地址
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：pSt_LibAddr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出解析的地址结构
 参数.三：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：Y
  意思：输出IPV6地址类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_IsIPV6Addr(LPCXSTR lpszMsgBuffer, XENGINE_LIBADDR * pSt_LibAddr = NULL, ENUM_XENGINE_BASELIB_IPV6_TYPE * penIPType = NULL);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_ExpIPV6Addr
函数功能：扩展IPV6地址
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要扩展IP地址结构
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出扩展的IP地址
 参数.三：bFill
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否填充到4位数
 参数.四：bSymbol
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否添加:符号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_ExpIPV6Addr(XENGINE_LIBADDR* pSt_LibAddr, XCHAR* ptszIPAddr, bool bFill = false, bool bSymbol = true);
/********************************************************************
函数名称：BaseLib_OperatorIPAddr_ComIPV6Addr
函数功能：压缩IPV6地址
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要扩展IP地址结构
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出压缩的IP地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorIPAddr_ComIPV6Addr(XENGINE_LIBADDR* pSt_LibAddr, XCHAR* ptszIPAddr);
/************************************************************************/
/*                         版本号操作                                   */
/************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorVer_XNumberStr
函数功能：获取XEngine系统版本的字符串
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出版本字符串.格式:x.zz.yyy.zzzz
返回值
  类型：字符指针
  意思：返回版本字符串信息
备注：
*********************************************************************/
extern "C" XCHAR* BaseLib_OperatorVer_XNumberStr(XCHAR* ptszMsgBuffer = NULL);
/********************************************************************
函数名称：BaseLib_OperatorVer_XTypeStr
函数功能：获取发布版本的类型
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出版本类型,拥有:PT,BT,RC,LTS
返回值
  类型：字符指针
  意思：返回版本类型
备注：
*********************************************************************/
extern "C" XCHAR* BaseLib_OperatorVer_XTypeStr(XCHAR* ptszMsgBuffer = NULL);
/********************************************************************
函数名称：BaseLib_OperatorVer_XGetInt
函数功能：获取XEngine系统版本的整数
返回值
  类型：整数型
  意思：返回版本号
备注：
*********************************************************************/
extern "C" __int64x BaseLib_OperatorVer_XNumberInt();
/********************************************************************
函数名称：BaseLib_OperatorVer_XTypeInt
函数功能：获取XEngine系统类型的整数
返回值
  类型：整数型
  意思：返回版本类型
备注：
*********************************************************************/
extern "C" int BaseLib_OperatorVer_XTypeInt();
/********************************************************************
函数名称：BaseLib_OperatorVer_XGetStu
函数功能：获取XEngine系统版本的结构
 参数.一：pSt_LibVersion
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出版本结构
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorVer_XGetStu(XENGINE_LIBVERSION* pSt_LibVersion);
/************************************************************************/
/*                         版本号操作                                   */
/************************************************************************/
/********************************************************************
函数名称：BaseLib_OperatorEnv_Set
函数功能：设置环境变量
 参数.一：lpszENVName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入环境名称
 参数.二：lpszENVValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入环境变量的值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEnv_Set(LPCXSTR lpszENVName, LPCXSTR lpszENVValue);
/********************************************************************
函数名称：BaseLib_OperatorEnv_Get
函数功能：获取环境变量
 参数.一：lpszENVName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入环境名称
 参数.二：ptszENVValue
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：输出环境变量
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEnv_Get(LPCXSTR lpszENVName, XCHAR* ptszENVValue);
/********************************************************************
函数名称：BaseLib_OperatorEnv_Del
函数功能：删除环境变量
 参数.一：lpszENVName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入环境名称
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool BaseLib_OperatorEnv_Del(LPCXSTR lpszENVName);