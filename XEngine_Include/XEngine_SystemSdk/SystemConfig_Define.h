#pragma once
/********************************************************************
//    Created:     2024/11/19  15:17:49
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_SystemSdk\XEngine_SystemConfig\SystemConfig_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_SystemSdk\XEngine_SystemConfig
//    File Base:   SystemConfig_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     导出定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出函数定义机器s
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG SystemConfig_GetLastError(int *pInt_SysError = XNULL);
/*********************************************************************************
*                          读写配置文件导出的函数                               *
*********************************************************************************/
/********************************************************************
函数名称：SystemConfig_File_ReadProfileFromFile
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
extern "C" size_t SystemConfig_File_ReadProfileFromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName, XCHAR* ptszValue);
extern "C" int SystemConfig_File_ReadIntFromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName);
extern "C" __int64x SystemConfig_File_ReadInt64FromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName);
/********************************************************************
函数名称：SystemConfig_File_WriteProfileFromFile
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
extern "C" bool SystemConfig_File_WriteProfileFromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName, LPCXSTR lpszValue);
extern "C" bool SystemConfig_File_WriteInt64FromFile(LPCXSTR lpszFilePath, LPCXSTR lpszKey, LPCXSTR lpszName, __int64x nValue);
/********************************************************************
函数名称：SystemConfig_File_ReadProfileFromMemory
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
extern "C" bool SystemConfig_File_ReadProfileFromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, XCHAR* ptszValue);
extern "C" bool SystemConfig_File_ReadIntFromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, int* pInt_Value);
extern "C" bool SystemConfig_File_ReadInt64FromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, __int64x* pInt_Value);
/********************************************************************
函数名称：SystemConfig_File_WriteProfileFromMemory
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
extern "C" bool SystemConfig_File_WriteProfileFromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, LPCXSTR lpszValue, XCHAR* ptszMsgBuffer, int* pInt_MsgLen);
extern "C" bool SystemConfig_File_WriteInt64FromMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszKey, LPCXSTR lpszName, __int64x nValue, XCHAR* ptszMsgBuffer, int* pInt_MsgLen);
/*********************************************************************************
*                          读写注册表导出的函数                                  *
*********************************************************************************/
/********************************************************************
函数名称：SystemConfig_Register_Read
函数功能：读取注册表内容
 参数.一：byType
  In/Out：In
  类型：注册表类型
  可空：N
  意思：0:HKEY_CLASSES_ROOT,1:HKEY_CURRENT_USER,2:HKEY_LOCAL_MACHINE,3:HKEY_USERS
 参数.二：lpszKeyPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册表路径
 参数.三：lpszKeyQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册表项目
 参数.四：pInt_Type
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：获取到的类型.参考MSDN注册表值类型
 参数.五：pInt_Size
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出内容大小
 参数.六：ptszValue
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool SystemConfig_Register_Read(XBYTE byType, LPCXSTR lpszKeyPath, LPCXSTR lpszKeyQuery, int* pInt_Type, int* pInt_Size, XBYTE* ptszValue);
/********************************************************************
函数名称：SystemConfig_Register_Write
函数功能：写入注册表内容
 参数.一：byType
  In/Out：In
  类型：注册表类型
  可空：N
  意思：0:HKEY_CLASSES_ROOT,1:HKEY_CURRENT_USER,2:HKEY_LOCAL_MACHINE,3:HKEY_USERS
 参数.二：lpszKeyPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册表路径
 参数.三：lpszKeyQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册表项目
 参数.四：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入写入的内容
 参数.五：nSize
  In/Out：Out
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.六：nType
  In/Out：In
  类型：整数型
  可空：N
  意思：输入类型.参考MSDN注册表值类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool SystemConfig_Register_Write(XBYTE byType, LPCXSTR lpszKeyPath, LPCXSTR lpszKeyQuery, LPCXBTR lpszValue, int nSize, int nType);