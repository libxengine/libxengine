#pragma once
/********************************************************************
//	Created:	2012/1/8  12:15
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_Protocol\Protocol_Define.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_Protocol
//	File Base:	Protocol_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	协议模块导出函数定义
//	History:
*********************************************************************/
/************************************************************************/
/*                      原始套接字编程数据结构参数                      */
/************************************************************************/
typedef struct tag_Protocol_RawSocket_NetParam
{
	XCHAR tszSrcMac[8];                                                    //原始MAC地址(ARP协议需要)
	XCHAR tszDstMac[8];                                                    //目的MAC地址
	XCHAR tszSrcAddr[64];                                                  //原始地址
	XCHAR tszDstAddr[64];                                                  //目标地址
	int nSPort;                                                           //原端口
	int nDPort;                                                           //目标端口
	int nIDProfile;                                                       //IP头标志,可为空
	int nIPProto;                                                         //响应的协议类型
	XSHOT usTTL;                                                         //TTL节点
	XSHOT usLen;                                                         //负载数据包大小，如果没有填入0,解析返回代表协议大小,只需要移动后就是数据了
	//负载协议
	struct
	{
		int nWinSize;                                                     //滑动窗口大小
		int nSequeue;                                                     //当前序列号
		int nAck;                                                         //确认号
		uint8_t nFlag;                                                    //协议子类型
	}st_TCPHdr;
	struct
	{
		int nSequeue;                                                     //包序列号
		uint8_t nFlag;                                                    //协议子类型
	}st_ICMPHdr;
	struct
	{
		uint16_t nFlag;                                                   //协议子类型
	}st_ARPHdr;
}PROTOCOL_RAWSOCKET_NETPARAM, * LPPROTOCOL_RAWSOCKET_NETPARAM;
//////////////////////////////////////////////////////////////////////////
//                              回调函数定义
//////////////////////////////////////////////////////////////////////////
//ICMP 路由过程函数回调,返回假将直接强制退出循环,并且没有错误信息
typedef bool(CALLBACK* CALLBACK_XENGINE_XENGINE_PROTOCOL_ICMP_TRACEROUTE)(LPCXSTR lpszSource, LPCXSTR lpszDestAddr, LPCXSTR lpszRecvAddr, int nTTL, XENGINE_VALTIME st_VALTime, XPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                               导出函数定义
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG Protocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     ICMP协议导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：Protocol_Icmp_Ping
函数功能：PING协议实现
 参数.一：lpszSourceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入发送的原始地址
 参数.二：lpszDestAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送的目标地址
 参数.三：pSt_VALTime
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出PING所消耗的时间
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数需要管理员权限
*********************************************************************/
extern "C" bool Protocol_Icmp_Ping(LPCXSTR lpszSourceAddr, LPCXSTR lpszDestAddr, XENGINE_VALTIME * pSt_VALTime);
/********************************************************************
函数名称：Protocol_Icmp_Traceroute
函数功能：路由节点查询
 参数.一：lpszSourceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查询的原始地址
 参数.二：lpszDestAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查询的目标地址
 参数.三：fpCall_ICMPTracer
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：输入回调函数地址
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数需要管理员权限,并且在部分系统下需要关闭防火墙,不然无法接收到差错包
*********************************************************************/
extern "C" bool Protocol_Icmp_Traceroute(LPCXSTR lpszSourceAddr, LPCXSTR lpszDestAddr, CALLBACK_XENGINE_XENGINE_PROTOCOL_ICMP_TRACEROUTE fpCall_ICMPTracer, XPVOID lParam = NULL);
//////////////////////////////////////////////////////////////////////////
//                        原始套机字接口定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************
函数名称：Protocol_ICMPRaw_Init
函数功能：初始化一个ICMP原始套接字
 参数.一：phSocket
   In/Out：Out
   类型：套机字句柄
   可空：N
   意思：导出初始化成功的套接字句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要自己CLOSE，你需要调用sendto和recvfrom来发送和接受数据
************************************************************************/
extern "C" bool Protocol_ICMPRaw_Init(XSOCKET * phSocket);
/********************************************************************
函数名称：Protocol_ICMPRaw_Packet
函数功能：ICMP协议打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_RAWSocket
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入ICMP协议参数
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入后续数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Protocol_ICMPRaw_Packet(XCHAR * ptszMsgBuffer, int* pInt_Len, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket, LPCXSTR lpszMsgBuffer = NULL);
/********************************************************************
函数名称：Protocol_ICMPRaw_Parse
函数功能：ICMP协议解析函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：pSt_RAWSocket
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析后的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Protocol_ICMPRaw_Parse(LPCXSTR lpszMsgBuffer, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket);
/********************************************************************
函数名称：Protocol_TCPRaw_Init
函数功能：初始化一个TCP原始套接字
 参数.一：phSdSocket
  In/Out：Out
  类型：套机字句柄
  可空：N
  意思：导出发送者套接字句柄
 参数.二：phRvSocket
  In/Out：Out
  类型：套机字句柄
  可空：N
  意思：导出接受者套接字句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要自己CLOSE，你需要调用sendto和recvfrom来发送和接受数据
*********************************************************************/
extern "C" bool Protocol_TCPRaw_Init(XSOCKET * phSDSocket, XSOCKET * phRVSocket);
/************************************************************************
函数名称：Protocol_TCPRaw_Packet
函数功能：组包一个TCP头
 参数.一：ptszMsgBuffer
   In/Out：Out
   类型：字符指针
   可空：N
   意思：导出组好包的TCP头数据
 参数.二：pInt_Len
   In/Out：Out
   类型：整数型指针
   可空：N
   意思：输出真实缓冲区大小
 参数.三：pSt_RAWSocket
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：输入发送的TCP参数
 参数.四：lpszMsgBuffer
   In/Out：In
   类型：常量字符指针
   可空：Y
   意思：输入要打包的后续数据缓冲区
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" bool Protocol_TCPRaw_Packet(XCHAR * ptszMsgBuffer, int* pInt_Len, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket, LPCXSTR lpszMsgBuffer = NULL);
/************************************************************************
函数名称：Protocol_TCPRaw_Parse
函数功能：解析一段数据包
 参数.一：lpszMsgBuffer
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：导出组好包的TCP头数据
 参数.二：pInt_Len
   In/Out：Out
   类型：整数型指针
   可空：N
   意思：输出真实缓冲区大小
 参数.三：pSt_RAWSocket
   In/Out：Out
   类型：数据结构指针
   可空：N
   意思：输出获取到的协议数据
 参数.四：bAllowIcmp
   In/Out：In
   类型：逻辑型
   可空：Y
   意思：是否允许ICMP差错报文输出,如果允许将获得ICMP协议错误数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" bool Protocol_TCPRaw_Parse(LPCXSTR lpszMsgBuffer, int nMsgLen, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket, bool bAllowIcmp = true);
/********************************************************************
函数名称：Protocol_UDPRaw_Init
函数功能：初始化一个UDP原始套接字
 参数.一：phSdSocket
  In/Out：Out
  类型：套机字句柄
  可空：N
  意思：导出发送者套接字句柄
 参数.二：phRvSocket
  In/Out：Out
  类型：套机字句柄
  可空：N
  意思：导出接受者套接字句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要自己CLOSE，你需要调用sendto和recvfrom来发送和接受数据
*********************************************************************/
extern "C" bool Protocol_UDPRaw_Init(XSOCKET * phSdSocket, XSOCKET * phRvSocket);
/************************************************************************
函数名称：Protocol_UDPRaw_Packet
函数功能：组包一个UDP头
 参数.一：ptszMsgBuffer
   In/Out：Out
   类型：字符指针
   可空：N
   意思：导出组好包的协议头数据
 参数.二：pInt_Len
   In/Out：Out
   类型：整数型指针
   可空：N
   意思：输出真实缓冲区大小
 参数.三：pSt_RAWSocket
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：输入发送的协议参数
 参数.四：lpszMsgBuffer
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：输入要打包的后续数据缓冲区
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" bool Protocol_UDPRaw_Packet(XCHAR * ptszMsgBuffer, int* pInt_Len, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket, LPCXSTR lpszMsgBuffer = ("XEngine_Tracert"));
/********************************************************************
函数名称：Protocol_UDPRaw_Parse
函数功能：解析UDP函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：pSt_RAWSocket
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析后的信息
 参数.三：bAllowIcmp
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输出解析后的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Protocol_UDPRaw_Parse(LPCXSTR lpszMsgBuffer, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket, bool bAllowIcmp = true);
#ifndef __IOS__
/************************************************************************
函数名称：Protocol_ARPRaw_Init
函数功能：初始化一个ARP原始套接字
 参数.一：phSocket
   In/Out：Out
   类型：套机字句柄
   可空：N
   意思：导出初始化成功的套接字句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要自己CLOSE，你需要调用sendto和recvfrom来发送和接受数据
************************************************************************/
extern "C" bool Protocol_ARPRaw_Init(XSOCKET * phSocket);
/********************************************************************
函数名称：Protocol_ARPRaw_Packet
函数功能：ARP协议打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_RAWSocket
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入ARP协议参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Protocol_ARPRaw_Packet(XCHAR * ptszMsgBuffer, int* pInt_Len, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket);
/********************************************************************
函数名称：Protocol_ARPRaw_Parse
函数功能：解析ARP协议
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：pSt_RAWSocket
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析后的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Protocol_ARPRaw_Parse(LPCXSTR lpszMsgBuffer, PROTOCOL_RAWSOCKET_NETPARAM * pSt_RAWSocket);
#endif