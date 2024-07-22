#pragma once
/********************************************************************
//    Created:     2024/06/19  15:19:31
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_BaseLib\XEngine_BaseSafe\BaseSafe_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_BaseLib\XEngine_BaseSafe
//    File Base:   BaseSafe_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     基础安全库
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的类型定义
//////////////////////////////////////////////////////////////////////////
#define _xstrcpy BaseSafe_String_Strcopy
#define _xstrcat BaseSafe_String_Strcat
#define _xmemcpy BaseSafe_Memory_Memcopy
#define _xmemmove BaseSafe_Memory_Memmove
//////////////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG BaseSafe_GetLastError(int *pInt_SysError = NULL);
/*********************************************************************************
*                         字符串安全操作                                         *
*********************************************************************************/
/********************************************************************
函数名称：BaseSafe_String_Strcopy
函数功能：安全拷贝字符串函数
 参数.一：ptszDestStr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出拷贝的字符串
 参数.二：lpszSourceStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要拷贝的字符串
 参数.三：nDestSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标缓冲区最大大小
返回值
  类型：整数型
  意思：拷贝大小
备注：如果他们刚好一样大,那么会丢失最后一个字符,因为最后一个字符会被设置为字符串结束
*********************************************************************/
extern "C" size_t BaseSafe_String_Strcopy(XCHAR* ptszDestStr, LPCXSTR lpszSourceStr, size_t nDestSize);
/********************************************************************
函数名称：BaseSafe_String_Strcat
函数功能：安全的字符串追加函数
 参数.一：ptszMSGBuffer
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要追加的字符串,输出追加后的字符串
 参数.二：nMSGSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标缓冲区最大大小
 参数.三：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要追加的字符串
返回值
  类型：整数型
  意思：拷贝大小
备注：如果他们刚好一样大,那么会丢失最后一个字符,因为最后一个字符会被设置为字符串结束
*********************************************************************/
extern "C" size_t BaseSafe_String_Strcat(XCHAR* ptszMSGBuffer, size_t nMSGSize, LPCXSTR lpszMSGBuffer);
/*********************************************************************************
*                         内存安全操作                                           *
*********************************************************************************/
/********************************************************************
函数名称：BaseSafe_Memory_Memcopy
函数功能：安全的内存拷贝函数
 参数.一：ptszDestByte
  In/Out：Out
  类型：无类型指针
  可空：N
  意思：目标内存
 参数.三：nDestSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标缓冲区最大大小
 参数.二：lpszSourceByte
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要拷贝的内存
 参数.三：nDestSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要拷贝的缓冲区最大大小
返回值
  类型：逻辑型
  意思：是否拷贝成功
备注：
*********************************************************************/
extern "C" bool BaseSafe_Memory_Memcopy(void* ptszDestByte, size_t nDestSize, LPCXBTR lpszSourceByte, size_t nSourceSize);
/********************************************************************
函数名称：BaseSafe_Memory_Memmove
函数功能：安全的内存重叠区域处理拷贝函数
 参数.一：ptszDestByte
  In/Out：Out
  类型：字符指针
  可空：N
  意思：无类型指针
 参数.三：nDestSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标缓冲区最大大小
 参数.二：lpszSourceByte
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要拷贝的内存
 参数.三：nDestSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要拷贝的缓冲区最大大小
返回值
  类型：逻辑型
  意思：是否拷贝成功
备注：
*********************************************************************/
extern "C" bool BaseSafe_Memory_Memmove(void* ptszDestByte, size_t nDestSize, LPCXBTR lpszSourceByte, size_t nSourceSize);