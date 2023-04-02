﻿#pragma once
/********************************************************************
//	Created:	2011/10/08   11:34
//	Filename: 	NetSocketEngine/NetEngine_Client/NetClient_Socket/NetClient_Socket_Define.h
//	File Path:	NetSocketEngine/NetEngine_Client/NetClient_Socket/
//	File Base:	NetClient_Socket_Define
//	File Ext:	h
//  Project:    血与荣誉网络通信引擎 For Linux
//	Author:		dowflyon
//	Purpose:	网络客户端
//	History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                               导出的事件类型
///////////////////////////////////////////////////////////////////////////////
typedef enum en_NetEngine_NetClient_TcpEvents
{
    ENUM_XENGINE_XCLIENT_SOCKET_TCP_EVENT_RECV = 1,
    ENUM_XENGINE_XCLIENT_SOCKET_TCP_EVENT_CLOSE = 2,                  //如果没有设置自动重连,会自动释放资源
    ENUM_XENGINE_XCLIENT_SOCKET_TCP_EVENT_CONNECT = 3,                //已连接
    ENUM_XENGINE_XCLIENT_SOCKET_TCP_EVENT_CONNING = 4                 //连接失败,继续尝试连接
}ENUM_NETCLIENT_TCPEVENTS, * LPENUM_NETCLIENT_TCPEVENTS;
//////////////////////////////////////////////////////////////////////
//                      导出的数据结构
//////////////////////////////////////////////////////////////////////
//UDX配置信息
typedef struct
{
    XBOOL bEnableLogin;                                                //是否启用登录离开模式
    XBOOL bEnableReorder;                                              //是否启用乱序重组
    XBOOL bEnableRryTime;                                              //是否启用重传超时
    XBOOL bEnableLost;                                                 //是否允许最小丢包,如果不允许,丢包后将强制断开
    XBOOL bEnableMtap;                                                 //是否启用聚合包发送数据,启用后将允许低延迟发送,不启用将无延迟发送
    int nWindowSize;                                                  //是否启用滑动窗口,0为不启用,大于0表示启用字节大小
}XCLIENT_UDXCONFIG, * LPXCLIENT_UDXCONFIG;
//////////////////////////////////////////////////////////////////////
//                      回调函数定义
//////////////////////////////////////////////////////////////////////
//TCP
typedef void(CALLBACK* CALLBACK_XCLIENT_SOCKET_TCP_SELECT_EVENTS)(XHANDLE xhToken, XNETHANDLE xhClient, XSOCKET hSocket, ENUM_NETCLIENT_TCPEVENTS enTCPClientEvents, LPCXSTR lpszMsgBuffer, int nLen, XPVOID lParam);
//////////////////////////////////////////////////////////////////////
//                      导出函数定义
//////////////////////////////////////////////////////////////////////
extern "C" XLONG XClient_GetLastError(int* pInt_SysError = NULL);
/************************************************************************/
/*                    套接字操作导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：XClient_OPTSocket_IOSelect
函数功能：IO选择模型轮训核心函数
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：套轮训的套接字
 参数.二：bRead
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：可读标志
 参数.三：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间，默认100毫秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_OPTSocket_IOSelect(XSOCKET hSocket, XBOOL bRead = TRUE, int nTimeout = 100);
/********************************************************************
函数名称：XClient_OPTSocket_IOBlock
函数功能：设置阻塞模型
 参数.一：hSocket
  In/Out：In
  类型：XSOCKET句柄
  可空：N
  意思：要设置的XSOCKET
 参数.二：bSet
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：设置阻塞还是设置为非阻塞，默认阻塞
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_OPTSocket_IOBlock(XSOCKET hSocket, XBOOL bSet = TRUE);
/********************************************************************
函数名称：XClient_OPTSocket_Send
函数功能：发送数据到一个指定的套接字接口上
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要发送的套接字
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：表示要发送的数据大小
 参数.四：nTimeout
  In/Out：In
  类型：整数型
  可空：N
  意思：表示超时时间,单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_OPTSocket_Send(XSOCKET hSocket, LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszAddr = NULL, int nPort = 0, int nTimeout = 3, int nIPVer = 2);
/************************************************************************/
/*                    TCP客户端导出函数选择模型                             */
/************************************************************************/
/********************************************************************
函数名称：XClient_TCPSelect_Create
函数功能：创建一个客户端
 参数.一：phSocket
  In/Out：Out
  类型：套接字句柄
  可空：N
  意思：创建成功的套接字
 参数.二：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要连接到的服务器
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要连接到的端口
 参数.四：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：链接超时时间,单位秒
 参数.五：lpszBindAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要指定的网卡地址
 参数.六：nBindPort
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要指定的端口
 参数.七：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要使用的IP版本
返回值
  类型：逻辑型
  意思：是否成功创建
备注：此模型套接字客户端 可以创建多个客户端，但是无安全属性，无线程管理，无多客户端自动管理
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_Create(XSOCKET * phSocket, LPCXSTR lpszAddr, int nPort, int nTimeout = 0, LPCXSTR lpszBindAddr = NULL, int nBindPort = 0, int nIPVer = 2);
/********************************************************************
函数名称：XClient_TCPSelect_SendMsg
函数功能：发送数据
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要发送的套接字
 参数.二：lpszSendMsg
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要发送的数据
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送数据的长度
返回值
  类型：逻辑型
  意思：是否发送成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_SendMsg(XSOCKET hSocket, LPCXSTR lpszSendMsg, int nLen);
/********************************************************************
函数名称：XClient_TCPSelect_RecvMsg
函数功能：接受数据
 参数.一：hSocket
  In/Out：In
  类型：套接字
  可空：N
  意思：要对哪个套接字进行接受数据操作
 参数.二：pTszRecvMsg
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出接受到的数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：表示要接受的大小，输出，实际接受到的大小
返回值
  类型：逻辑型
  意思：是否接受到数据
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_RecvMsg(XSOCKET hSocket, XCHAR * pTszRecvMsg, int* pInt_Len);
/********************************************************************
函数名称：XClient_TCPSelect_RecvPkt
函数功能：接受一个完整包
 参数.一：hSocket
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端句柄
 参数.二：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：输出获取到的协议头后的缓冲区,这个内存需要手动释放
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出后续缓冲区大小
 参数.四：pSt_ProtocolHdr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出协议头
 参数.五：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入获取包超时时间,单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数无法处理多个包在一个缓冲区,也无法处理分片包头
      这个函数只能针对XEngine标准头
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_RecvPkt(XSOCKET hSocket, XCHAR * *pptszMsgBuffer, int* pInt_Len, XENGINE_PROTOCOLHDR * pSt_ProtocolHdr, int nTimeout = 2);
/********************************************************************
函数名称：XClient_TCPSelect_Close
函数功能：关闭客户端
 参数.一：hSocket
  In/Out：In
  类型：套接字
  可空：N
  意思：要关闭的套接字，可以为空
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_Close(XSOCKET hSocket);
//扩展客户端函数集
/************************************************************************
函数名称：XClient_TCPSelect_StartEx
函数功能：客户端创建函数
 参数.一：fpCall_NETEvent
   In/Out：In/Out
   类型：回调函数
   可空：N
   意思：事件触发器回调函数
 参数.二：lParam
   In/Out：In/Out
   类型：无类型指针
   可空：Y
   意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否启动成功
备注：回调函数不设置请主动调用recv 来接受数据
************************************************************************/
extern "C" XHANDLE XClient_TCPSelect_StartEx(CALLBACK_XCLIENT_SOCKET_TCP_SELECT_EVENTS fpCall_NETEvent, XPVOID lParam = NULL);
/********************************************************************
函数名称：XClient_TCPSelect_HBStartEx
函数功能：启动一个客户端心跳
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入创建好的客户端句柄
 参数.二：nTimeCheck
  In/Out：In
  类型：整数型
  可空：Y
  意思：心跳发送间隔时间,单位秒
 参数.三：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：自定义心跳数据包,为空发送我们定义的数据心跳结构
 参数.四：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：自定义心跳包大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_HBStartEx(XHANDLE xhToken, int nTimeCheck = 5, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：XClient_TCPSelect_InsertEx
函数功能：插入一个客户端
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pxhClient
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建后的客户端句柄
 参数.三：lpszServerAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入服务器地址
 参数.四：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：输入服务器端口
 参数.五：bAutoConnect
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否自动连接
 参数.六：bHBSend
  In/Out：In
  类型：整数型
  可空：Y
  意思：心跳是否需要发送数据,如果为否,那么不发送心跳包
 参数.七：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间
 参数.八：nBindPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入绑定端口
 参数.九：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：IP版本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_InsertEx(XHANDLE xhToken, XNETHANDLE * pxhClient, LPCXSTR lpszServerAddr, int nPort, XBOOL bAutoConnect = FALSE, XBOOL bHBSend = FALSE, int nTimeout = 2, int nBindPort = 0, int nIPVer = 2);
/********************************************************************
函数名称：XClient_TCPSelect_DeleteEx
函数功能：删除一个客户端
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：xhClient
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_DeleteEx(XHANDLE xhToken, XNETHANDLE xhClient);
/********************************************************************
函数名称：XClient_TCPSelect_SendEx
函数功能：发送指定客户端数据到服务器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：xhClient
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
 参数.三：lpszMsgBuffer
  In/Out：In
   类型：常量字符指针
   可空：N
   意思：要发送的数据
 参数.四：nMsgLen
  In/Out：In
   类型：整数型
   可空：N
   意思：输入要发送的数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_SendEx(XHANDLE xhToken, XNETHANDLE xhClient, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：XClient_TCPSelect_RecvEx
函数功能：接受指定客户端数据。回调模式此函数不可用
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：xhClient
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
 参数.三：ptszMsgBuffer
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输出接受到的数据
 参数.四：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要接受的数据大小，输出实际接受到的数据大小
 参数.五：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位毫秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_RecvEx(XHANDLE xhToken, XNETHANDLE xhClient, XCHAR * ptszMsgBuffer, int* pInt_Len, int nTimeOut = 0);
/************************************************************************
函数名称：XClient_TCPSelect_IsConnectEx
函数功能：是否连接成功
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：xhClient
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
返回值
  类型：逻辑型
  意思：是否连接成功
备注：
************************************************************************/
extern "C" XBOOL XClient_TCPSelect_IsConnectEx(XHANDLE xhToken, XNETHANDLE xhClient);
/********************************************************************
函数名称：XClient_TCPSelect_GetClientEx
函数功能：获取客户端列表
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
 参数.二：pppxhClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出客户端列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出客户端列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_GetClientEx(XHANDLE xhToken, XNETHANDLE * **pppxhClient, int* pInt_ListCount);
/********************************************************************
函数名称：XClient_TCPSelect_GetSocketForClientEx
函数功能：通过客户端句柄得到套接字句柄
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
 参数.二：xhClient
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要匹配的句柄
 参数.三：phSocket
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出获取到的套接字
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_GetSocketForClientEx(XHANDLE xhToken, XNETHANDLE xhClient, XSOCKET * phSocket);
/********************************************************************
函数名称：XClient_TCPSelect_GetClientForSocketEx
函数功能：通过套接字句柄得到客户端句柄
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的客户端
 参数.二：hSocket
  In/Out：In
  类型：句柄
  可空：N
  意思：输入套接字句柄
 参数.三：pxhClient
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出获取到的客户端句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_GetClientForSocketEx(XHANDLE xhToken, XSOCKET hSocket, XNETHANDLE * pxhClient);
/************************************************************************
函数名称：XClient_TCPSelect_StopEx
函数功能：停止一个指定客户端
  参数一：xhToken
   In/Out：In
   类型：网络句柄
   可空：Y
   意思：要操作哪个客户端
返回值
  类型：逻辑型
  意思：是否停止成功
备注：如果为0，那么将停止全部客户端连接
************************************************************************/
extern "C" XBOOL XClient_TCPSelect_StopEx(XHANDLE xhToken);
/********************************************************************
函数名称：XClient_TCPSelect_SetCallbackEx
函数功能：设置回调函数模式
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要设置哪个客户端
 参数.二：xhClient
  In/Out：In
  类型：句柄
  可空：N
  意思：要设置的客户端句柄
 参数.三：bIsCall
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：设置为回调模式还是非回调模式
返回值
  类型：逻辑型
  意思：是否成功
备注：如果设置为回调模式,将通过回调函数接受数据,否则由用户主动调用recv接受
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_SetCallbackEx(XHANDLE xhToken, XNETHANDLE xhClient, XBOOL bIsCall = FALSE);
/********************************************************************
函数名称：XClient_TCPSelect_GetFlowEx
函数功能：获取流量信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要获取的客户端
 参数.二：pInt_SendPkt
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出发送的包个数
 参数.三：pInt_SendByte
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出发送的大小
 参数.四：pInt_RecvPkt
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出接受的包个数
 参数.五：pInt_RecvByte
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出接受的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_TCPSelect_GetFlowEx(XHANDLE xhToken, __int64u * pInt_SendPkt = NULL, __int64u * pInt_SendByte = NULL, __int64u * pInt_RecvPkt = NULL, __int64u * pInt_RecvByte = NULL);
/************************************************************************/
/*                    UDP SELECT客户端导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：XClient_UDPSelect_Create
函数功能：创建UDP客户端
 参数.一：phSocket
  In/Out：Out
  类型：套接字句柄
  可空：N
  意思：导出设置成功的套接字句柄
 参数.二：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要使用的IP协议版本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDPSelect_Create(XSOCKET * phSocket, int nIPVer = 2);
/********************************************************************
函数名称：XClient_UDPSelect_Connect
函数功能：UDP连接函数,设置后send数据不需要在填写对端地址了
 参数.一：hSocket
  In/Out：In
  类型：套接字
  可空：N
  意思：输入要操作的套接字句柄
 参数.二：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：服务端IP地址
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：服务端端口,同参数二
 参数.四：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要使用的IP协议版本
返回值
  类型：逻辑型
  意思：是否成功
备注：注意:如要要XClient_UDPSelect_Bind,必须Bind后在调用此函数
*********************************************************************/
extern "C" XBOOL XClient_UDPSelect_Connect(XSOCKET hSocket, LPCXSTR lpszIPAddr, int nPort, int nIPVer = 2);
/********************************************************************
函数名称：XClient_UDPSelect_SendMsg
函数功能：发送消息
 参数.一：hSocket
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的UDP客户端
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要发送的数据长度，不能超过MTU
 参数.四：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要发送的服务器地址,如果为空,将采用默认地址发送
 参数.五：nPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：要发送到的端口,如果参数lpszAddr有值,这个参数为0,那么lpszAddr参数视为ip:port形式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDPSelect_SendMsg(XSOCKET hSocket, LPCXSTR lpszMsgBuffer, int nMsgLen, LPCXSTR lpszAddr = NULL, int nPort = 0);
/********************************************************************
函数名称：XClient_UDPSelect_RecvMsg
函数功能：接受数据
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要操作的UDP客户端
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：接受到的数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入，要接受的数据大小，输出成功接受的数据大小
 参数.四：ptszAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出对方的地址+端口信息
 参数.五：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要使用的IP版本,V4或者V6
返回值
  类型：逻辑型
  意思：是否成功接受数据
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDPSelect_RecvMsg(XSOCKET hSocket, XCHAR * ptszMsgBuffer, int* pInt_Len, XCHAR * ptszAddr = NULL, int nIPVer = 2);
/********************************************************************
函数名称：XClient_UDPSelect_RecvPkt
函数功能：接受一个完整包
 参数.一：hSocket
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端句柄
 参数.二：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：输出获取到的协议头后的缓冲区,这个内存需要手动释放
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出后续缓冲区大小
 参数.四：pSt_ProtocolHdr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出协议头
 参数.五：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入获取包超时时间,单位秒
 参数.六：ptszAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出对方地址
 参数.七：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要使用的IP版本,V4或者V6
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数无法处理多个包在一个缓冲区,也无法处理分片包头
      这个函数只能针对XEngine标准头
*********************************************************************/
extern "C" XBOOL XClient_UDPSelect_RecvPkt(XSOCKET hSocket, XCHAR * *pptszMsgBuffer, int* pInt_Len, XENGINE_PROTOCOLHDR * pSt_ProtocolHdr, int nTimeout = 2, XCHAR * ptszAddr = NULL, int nIPVer = 2);
/********************************************************************
函数名称：XClient_UDPSelect_Bind
函数功能：绑定端口
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要操作的UDP客户端
 参数.二：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要绑定的端口
 参数.三：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要绑定的网卡IP地址
 参数.四：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要使用的IP版本,V4或者V6
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDPSelect_Bind(XSOCKET hSocket, int nPort, LPCXSTR lpszAddr = NULL, int nIPVer = 2);
/************************************************************************
函数名称：XClient_UDPSelect_Close
函数功能：关闭UDP客户端
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要操作的UDP客户端
返回值
  类型：逻辑型
  意思：是否成功关闭客户端
备注：
************************************************************************/
extern "C" XBOOL XClient_UDPSelect_Close(XSOCKET hSocket);
/************************************************************************/
/*                    UDX客户端导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：XClient_UDXSocket_Init
函数功能：初始化UDX客户端
 参数.一：pSt_UDXConfig
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：设置UDX的选项
 参数.二：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：服务器地址
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：服务器端口
 参数.四：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：要设置的IP协议版本
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：
*********************************************************************/
extern "C" XHANDLE XClient_UDXSocket_InitEx(XCLIENT_UDXCONFIG * pSt_UDXConfig, LPCXSTR lpszIPAddr, int nPort, int nIPVer = 2);
/********************************************************************
函数名称：XClient_UDXSocket_Send
函数功能：发送数据函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要发送的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要发送的数据大小
 参数.三：wSerial
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入自定义序列号,0表示系统自动分配,分片包不支持
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDXSocket_SendEx(XHANDLE xhToken, LPCXSTR lpszMsgBuffer, int nMsgLen, XSHOT wSerial = 0);
/********************************************************************
函数名称：XClient_UDXSocket_Recv
函数功能：获取数据
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDXSocket_RecvEx(XHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：XClient_UDXSocket_Destroy
函数功能：销毁UDX资源
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UDXSocket_DestroyEx(XHANDLE xhToken);
/************************************************************************/
/*                    UNIX客户端导出函数                                  */
/************************************************************************/
/********************************************************************
函数名称：XClient_UnixDomain_Connect
函数功能：连接到指定UNIX域地址
 参数.一：lpszUnixName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：流式(TCP)输入目标套接字文件地址,UDP输入本地要绑定的套接字地址
 参数.二：phSocket
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出连接成功后的操作句柄
 参数.三：bStream
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：使用流式还是消息类型,WINDOWS目前只能流式
 参数.四：lpszUnixServer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：消息套接字(UDP)需要设置服务器套接字文件地址
返回值
  类型：逻辑型
  意思：是否成功
备注：WINDOWS不支持消息类型
      第一个参数的名称应该是你的服务器设置的地址
************************************** *******************************/
extern "C" XBOOL XClient_UnixDomain_Connect(LPCXSTR lpszUnixName, XSOCKET * phSocket, XBOOL bStream = TRUE, LPCXSTR lpszUnixServer = NULL);
/********************************************************************
函数名称：XClient_UnixDomain_SendMsg
函数功能：发送数据
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要发送的套接字
 参数.二：lpszSendMsg
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要发送的数据
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送数据的长度
返回值
  类型：逻辑型
  意思：是否发送成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UnixDomain_SendMsg(XSOCKET hSocket, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：XClient_UnixDomain_RecvMsg
函数功能：接受数据
 参数.一：hSocket
  In/Out：In
  类型：套接字
  可空：N
  意思：要对哪个套接字进行接受数据操作
 参数.二：pTszRecvMsg
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出接受到的数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：表示要接受的大小，输出，实际接受到的大小
 参数.四：bIOSelect
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否允许判断数据是否可读，如果没有数据可读，将返回错误，否则一直等待
返回值
  类型：逻辑型
  意思：是否接受到数据
备注：
*********************************************************************/
extern "C" XBOOL XClient_UnixDomain_RecvMsg(XSOCKET hSocket, XCHAR * ptszMsgBuffer, int* pInt_Len, XBOOL bIOSelect = TRUE);
/********************************************************************
函数名称：XClient_UnixDomain_Close
函数功能：关闭客户端
 参数.一：hSocket
  In/Out：In
  类型：套接字
  可空：N
  意思：要关闭的套接字，可以为空
 参数.二：lpszUnixServer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果是消息类型,需要输入你绑定的本地UNIX套接字路径
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_UnixDomain_Close(XSOCKET hSocket, LPCXSTR lpszUnixServer = NULL);
