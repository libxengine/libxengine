#pragma once
/********************************************************************
//	Created:	2017/5/26   10:25
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_BackManage\BackManage_Define.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_BackManage
//	File Base:	BackManage_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	后台管理服务导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    导出的回调函数
//////////////////////////////////////////////////////////////////////////
typedef void(*CALLBACK_NETENGINE_NETHELP_BACKMANAGE_NETEVENTS)(LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                    导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD BackManage_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                    导出的网络后台操作函数                            */
/************************************************************************/
/********************************************************************
函数名称：BackManage_Service_Init
函数功能：初始化后台服务器
 参数.一：lpszHttpUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入HTTP请求的URL地址 http://www.xyry.org:1390
 参数.二：nWaitTime
  In/Out：In
  类型：整数型
  可空：Y
  意思：每次HTTP请求发起时间,单位秒
 参数.三：lpCall_BackManage
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：后台服务事件回调,没有设置值将自动处理
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BackManage_Service_Init(LPCSTR lpszHttpUrl,int nWaitTime = 60,CALLBACK_NETENGINE_NETHELP_BACKMANAGE_NETEVENTS lpCall_BackManage = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：BackManage_Service_Destory
函数功能：销毁后台网络服务
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BackManage_Service_Destory();
/********************************************************************
函数名称：BackManage_Service_ProtocolParse
函数功能：解析一条协议
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入数据缓冲区大小
 参数.三：pInt_ProtoCode
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出处理的协议类型
返回值
  类型：逻辑型
  意思：是否解析执行成功
备注：
*********************************************************************/
extern "C" BOOL BackManage_Service_ProtocolParse(LPCSTR lpszMsgBuffer, int nMsgLen, int* pInt_ProtoCode = NULL);
/************************************************************************/
/*                    导出的系统信息获取函数                            */
/************************************************************************/
/********************************************************************
函数名称：BackManage_GetInfo_GetBuffer
函数功能：获取系统硬件信息
 参数.一：ptszHWInfo
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出硬件信息
 参数.二：ptszSWInfo
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出软件信息
 参数.三：pInt_HWInfo
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出硬件信息大小
 参数.四：pInt_SWLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出软件信息大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BackManage_GetInfo_GetBuffer(CHAR* ptszHWInfo, CHAR* ptszSWInfo, int* pInt_HWInfo, int* pInt_SWLen);
