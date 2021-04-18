#pragma once
/********************************************************************
//	Created:	2020/10/24  16:41:28
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Client\NetClient_Pool\ClientPool_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Client\NetClient_Pool
//	File Base:	ClientPool_Define
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	客户端池模块导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////
//                      回调函数定义
//////////////////////////////////////////////////////////////////////
//客户端池数据回调函数,导出参数:句柄,地址,数据,长度,自定义参数
typedef void(CALLBACK* CALLBACK_XCLIENT_POOL_CONNECT_RECV)(XNETHANDLE xhToken, int nIndex, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                      导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD XClientPool_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      导出的连接池函数                                */
/************************************************************************/
/********************************************************************
函数名称：XClient_PoolConnect_OPen
函数功能：打开一个连接池
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建的连接池句柄
 参数.二：lpszServiceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要连接的服务器地址
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要连接的服务器端口
 参数.四：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要创建的个数
 参数.五：fpCall_PoolRecv
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：输入数据接受回调
 参数.六：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
 参数.七：bTCP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是TCP还是UDP
 参数.八：nIPVer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：IP版本,V4还是V6
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XClient_PoolConnect_OPen(XNETHANDLE* pxhToken, LPCSTR lpszServiceAddr, int nPort, int nCount, CALLBACK_XCLIENT_POOL_CONNECT_RECV fpCall_PoolRecv, LPVOID lParam = NULL, BOOL bTCP = TRUE, int nIPVer = 2);
/********************************************************************
函数名称：XClient_PoolConnect_Send
函数功能：发送数据
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的连接池
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要发送的大小
 参数.四：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要操作的客户端池索引,-1可以不指定
 参数.五：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要发送到的地址,UDP必须指定
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XClient_PoolConnect_Send(XNETHANDLE xhToken, LPCSTR lpszMsgBuffer, int nMsgLen, int nIndex = -1, LPCSTR lpszClientAddr = NULL);
/********************************************************************
函数名称：XClient_PoolConnect_Close
函数功能：关闭连接池
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XClient_PoolConnect_Close(XNETHANDLE xhToken);
