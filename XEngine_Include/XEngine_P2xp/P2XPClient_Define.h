#pragma once
/********************************************************************
//	Created:	2012/5/21  17:01
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_Client\NetClient_P2p\P2PPeerManage_Define.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_Client\NetClient_P2p
//	File Base:	P2PPeerManage_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		dowflyon
//	Purpose:	P2P节点管理器导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出回调函数
//////////////////////////////////////////////////////////////////////////
//命令通道回调函数
typedef void(*CALLBACK_NETENGINE_P2XP_CLIENT_RECV_CMD)(LPCSTR lpszMsgBuffer,int nMsgLen,XENGINE_PROTOCOLHDR *pSt_ProtocolHdr,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                     导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD P2XPClient_GetLastError(int *pInt_Sys = NULL);
/************************************************************************/
/*                     P2P传输管理器导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：P2XPClient_CMDTransmission_SetCallBack
函数功能：设置回调函数
 参数.一：fpCall_ClientRecvCmd
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：命令通道数据回调函数
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：命令通道回调函数参数
返回值
  类型：逻辑型
  意思：是否设置成功
备注：
*********************************************************************/
extern "C" BOOL P2XPClient_CMDTransmission_SetCallBack(CALLBACK_NETENGINE_P2XP_CLIENT_RECV_CMD fpCall_ClientRecvCmd, LPVOID lParam = NULL);
/********************************************************************
函数名称：P2XPClient_CMDTransmission_Create
函数功能：创建命令通道，用作于协议传输
 参数.一：lpszUserFlags
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：用户的标识符
 参数.二：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：P2P服务器地址,P2P引擎服务器
 参数.三：nCmdPort
  In/Out：In
  类型：整数型
  可空：N
  意思：服务器端口
 参数.四：bIsHb
  In/Out：In
  类型：逻辑型
  可空：N
  意思：是否启用心跳,如果服务器没有开启心跳服务可以不启用,否则必须启用
返回值
  类型：逻辑型
  意思：是否创建成功
备注：此必须要最先调用。命令通道只能创建一个,如果你有数据传输需求,需要调用分发数据模块接口
*********************************************************************/
extern "C" BOOL P2XPClient_CMDTransmission_Create(LPCSTR lpszUserFlags, LPCSTR lpszAddr, int nCmdPort, BOOL bIsHb = TRUE);
/********************************************************************
函数名称：P2XPClient_CMDTransmission_Send
函数功能：发送数据协议给服务器
 参数.一：lpszSendMsg
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送的数据缓冲区
 参数.二：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送数据的长度
返回值
  类型：逻辑型
  意思：是否发送成功
备注：
*********************************************************************/
extern "C" BOOL P2XPClient_CMDTransmission_Send(LPCSTR lpszSendMsg, int nLen);
/********************************************************************
函数名称：P2XPClient_CMDTransmission_Close
函数功能：关闭所有资源，停止P2P服务
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：此函数会关闭P2XP的协议端口，这个关闭你需要关闭其他所有P2XP相关的服务
*********************************************************************/
extern "C" BOOL P2XPClient_CMDTransmission_Close();
/************************************************************************/
/*                     P2P客户端信息导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：P2XPClinet_Help_GetInfo
函数功能：初始化客户端节点信息
 参数.一：pSt_ClientInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的数据信息结构
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL P2XPClinet_Help_GetInfo(XENGINE_P2XPPEER_PROTOCOL *pSt_ClientInfo);
/********************************************************************
函数名称：P2XPClinet_Help_GetType
函数功能：获取此电脑节点类型
 参数.一：pdwPeerType
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出此节点类型
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL P2XPClinet_Help_GetType(WORD *pdwPeerType);
/********************************************************************
函数名称：P2XPClient_Help_UDPHold
函数功能：UDP打洞函数
 参数.一：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入对方IP地址
 参数.二：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：输入对方端口
返回值
  类型：逻辑型
  意思：是否成功
备注：使用此函数后,对方可以使用这个IP和端口为本机器发送数据
*********************************************************************/
extern "C" BOOL P2XPClient_Help_UDPHold(LPCSTR lpszAddr, int nPort);
