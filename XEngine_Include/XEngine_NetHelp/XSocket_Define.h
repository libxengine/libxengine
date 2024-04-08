#pragma once
/********************************************************************
//    Created:     2024/02/21  11:19:19
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_XSocket\XSocket_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_XSocket
//    File Base:   XSocket_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     获取网络信息导出函数定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         导出的定义
//////////////////////////////////////////////////////////////////////////
//网络端口占用者信息
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_TCP 0x0C01               //TCP
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_UDP 0x0C02               //UDP
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_RAW 0x0C03               //RAW
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_UNIX 0x0C04              //UNIX
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_ICMP 0x0C05              //ICMP
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_IP 0x0C016               //IP
#define NETHELP_XSOCKET_API_NETSTATE_PROTOCOL_UNKNOW 0x0C0F            //无法识别的协议类
//网络状态信息
#define NETHELP_XSOCKET_API_NETSTATE_NET_CLOSED 0x0C20                 //网络关闭
#define NETHELP_XSOCKET_API_NETSTATE_NET_LISTEN 0x0C21                 //监听
#define NETHELP_XSOCKET_API_NETSTATE_NET_SYNSENT 0x0C22                //再收到和发送一个连接请求后等待对方对连接请求的确认
#define NETHELP_XSOCKET_API_NETSTATE_NET_SYNRECEIVED 0x0C24
#define NETHELP_XSOCKET_API_NETSTATE_NET_ESTABLISHED 0x0C25            //代表一个打开的连接
#define NETHELP_XSOCKET_API_NETSTATE_NET_FINWAIT1 0x0C26               //等待远程TCP连接中断请求，或先前的连接中断请求的确认
#define NETHELP_XSOCKET_API_NETSTATE_NET_FINWAIT2 0x0C27               //从远程TCP等待连接中断请求
#define NETHELP_XSOCKET_API_NETSTATE_NET_CLOSEWAIT 0x0C28              //等待从本地用户发来的连接中断请求
#define NETHELP_XSOCKET_API_NETSTATE_NET_CLOSING 0x0C29                //等待远程TCP对连接中断的确认
#define NETHELP_XSOCKET_API_NETSTATE_NET_LASTACK 0x0C2A                //等待原来的发向远程TCP的连接中断请求的确认
#define NETHELP_XSOCKET_API_NETSTATE_NET_TIMEWAIT 0x0C2B               //等待足够的时间以确保远程TCP接收到连接中断请求的确认
//网络连接类型定义,通过 penConnectType & XENGINE_NETXAPI_SOCKET_CONNECTTYPE 来确定
typedef enum 
{
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_DISCONNECTED = 0,              //无网络连接
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV4_NOTRAFFIC = 0x1,          //连接到IPV4但是没有流量
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV6_NOTRAFFIC = 0x2,          //连接到IPV6但是没有流量
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV4_SUBNET = 0x10,            //使用 IPv4 协议连接到本地子网。
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV4_LOCALNETWORK = 0x20,      //使用 IPv4 协议连接到路由网络。
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV4_INTERNET = 0x40,          //使用 IPv4 协议连接到 Internet。
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV6_SUBNET = 0x100,           //使用 IPv6 协议连接到本地子网。
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV6_LOCALNETWORK = 0x200,     //使用 IPv6 协议连接到本地网络。
	ENUM_NETHELP_XSOCKET_API_CONNECTTYPE_IPV6_INTERNET = 0x400          //使用 IPv6 协议连接到 Internet。
}ENUM_NETHELP_XSOCKET_API_CONNECTTYPE;
typedef enum
{
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_UNKNOW = 0,
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_ETH = 1,                          //以太网
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_PPP = 2,                          //PPP连接
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_LOOP = 3,                         //回环地址
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_ATM = 4,                          //ATM
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_WIRELESS = 5,                     //无线
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_TOKEN = 6,                        //令牌网络
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_TUNNEL = 7,                       //隧道网络
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_VIRTUAL = 10,                     //虚拟网卡
	ENUM_NETHELP_XSOCKET_API_CARDTYPE_BLUE = 11                         //蓝牙
}ENUM_NETHELP_XSOCKET_API_CARDTYPE;
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
//抓包信息结构
typedef struct 
{
    XCHAR tszSourceAddr[32];                                               //源地址
    XCHAR tszDestAddr[32];                                                 //目标地址,IP协议有效
    int nSourcePort;                                                       //源端口
    int nDestPort;                                                         //目的端口

    int nHdrLen;                                                          //协议大小
    int nMsgLen;                                                          //数据大小

    int nIPProtoType;                                                     //IP或者ARP操作协议类型
    XBYTE uFlags;                                                         //最终操作标记,TCP(FIN,PST等)
}XSOCKET_PROTOCOLINFO;
/************************************************************************/
/*                      网络套接字函数导出结构                          */
/************************************************************************/
//网络信息状态查询
typedef struct
{
	XCHAR tszAppName[128];                                                 //应用程序名称
	XCHAR tszUserName[32];                                                 //应用程序所属用户
	XLONG dwProVersion;                                                   //协议版本
	XLONG dwProtocol;                                                     //协议类型
	XLONG dwNetState;                                                     //网络状态，UDP无效
	int nPid;                                                             //应用程序PID
}XSOCKET_NETSTATE;
//TCP进程连接列表
typedef struct
{
	XCHAR tszLoaclAddr[128];                                               //本地地址
	XCHAR tszRemoteAddr[128];                                              //远程地址
	XLONG dwStatus;                                                       //进程网络状态
	XSHOT usProto;                                                       //网络连接类型
}XSOCKET_NETTABLE;
typedef struct
{
	XCHAR tszIFName[128];                                                 //网卡名称
	XCHAR tszIPAddr[128];                                                 //网卡IP地址
	XCHAR tszMacAddr[128];                                                //网卡MAC地址
	XCHAR tszBroadAddr[128];                                              //网卡的广播地址
	XCHAR tszDnsAddr[128];                                                //网卡DNS地址
	ENUM_NETHELP_XSOCKET_API_CARDTYPE enCardType;                     //网卡类型
}XSOCKET_CARDINFO;
//////////////////////////////////////////////////////////////////////////
//                        导出回调
//////////////////////////////////////////////////////////////////////////
//声明回调函数，参数:抓抱器句柄，导出的信息，上层主协议(IP,ARP等),下层子协议,完整数据包(+nHdrLen 就是数据),自定义参数
typedef void(CALLBACK* CALLBACK_XSOCKET_SNIFFER_DATAPACKET)(XHANDLE xhToken, XSOCKET_PROTOCOLINFO* pSt_ProtoInfo, LPCXSTR lpszMsgBuffer, XPVOID lParam);
//////////////////////////////////////////////////////////////////////
//                        导出函数
//////////////////////////////////////////////////////////////////////
/************************************************************************
函数名称：XSocket_GetLastError
函数功能：获取最后发生的错误
返回值
  类型：双字
  意思：错误码
备注：
************************************************************************/
extern "C" XLONG XSocket_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                     网络嗅探器函数导出                                  */
/************************************************************************/
/********************************************************************
函数名称：XSocket_Sniffer_Start
函数功能：启动一个网络抓包器
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出网络监听句柄
 参数.二：lpszDevName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要监听哪个网卡
 参数.三：fpCall_NetXSniffer
  In/Out：Out
  类型：回调函数
  可空：N
  意思：设置回调函数地址
 参数.四：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数在LINUX下需要ROOT权限
*********************************************************************/
extern "C" XHANDLE XSocket_Sniffer_Start(LPCXSTR lpszDevName, CALLBACK_XSOCKET_SNIFFER_DATAPACKET fpCall_NetXSniffer, XPVOID lParam = NULL);
/********************************************************************
函数名称：XSocket_Sniffer_Stop
函数功能：停止网络嗅探器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要释放的嗅探器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XSocket_Sniffer_Stop(XHANDLE xhNet);
/********************************************************************
函数名称：XSocket_Sniffer_Filter
函数功能：设置网络嗅探过滤器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入嗅探器句柄
 参数.二：bTCP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：启用TCP
 参数.三：bUDP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：启用UDP
 参数.四：bICMP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：启用ICMP
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XSocket_Sniffer_Filter(XHANDLE xhNet, bool bTCP = true, bool bUDP = true, bool bICMP = true);
/************************************************************************/
/*                       网络套接字函数导出接口                         */
/************************************************************************/
/********************************************************************
函数名称：XSocket_Api_IsPortOccupation
函数功能：端口是否被使用
 参数.一：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要检查的端口号码
 参数.二：nProto
  In/Out：In
  类型：整数型
  可空：Y
  意思：协议类型，要查找端口的所属协议
返回值
  类型：逻辑型
  意思：是否被使用，假为没有
备注：
*********************************************************************/
extern "C" bool XSocket_Api_IsPortOccupation(int nPort, int nProto);
/********************************************************************
函数名称：XSocket_Api_GetPortState
函数功能：获取本地端口状态
 参数.一：uPort
  In/Out：In
  类型：双字
  可空：N
  意思：要检查的端口号
 参数.二：pSt_NetState
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出占用信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XSocket_Api_GetPortState(int uPort, XSOCKET_NETSTATE * pSt_NetState);
/********************************************************************
函数名称：XSocket_Api_DomainToAddr
函数功能：名称转地址列表
 参数.一：lpszDomain
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入一个标准的名称
 参数.二：pppszListAddr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的地址列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否转换成功
备注：
*********************************************************************/
extern "C" bool XSocket_Api_DomainToAddr(LPCXSTR lpszDomain, XCHAR * **pppszListAddr, int* pInt_ListCount);
/********************************************************************
函数名称：XSocket_Api_GetNetConnectType
函数功能：获取网络连接类型
 参数.一：penConnectType
  In/Out：Out
  类型：枚举型
  可空：N
  意思：导出网络连接方式
返回值
  类型：逻辑型
  意思：获取是否成功,返回假,参数也可能会导出内容
备注：
*********************************************************************/
extern "C" bool XSocket_Api_GetNetConnectType(ENUM_NETHELP_XSOCKET_API_CONNECTTYPE * penConnectType);
/********************************************************************
函数名称：XSocket_Api_NetList
函数功能：获取网络连接列表
 参数.一：pppSt_ListTCPProcess
  In/Out：Out
  类型：指向数据结构指针的指针的指针
  可空：N
  意思：输出网络进程列表TCP连接,此内存必须手动释放
 参数.二：pppSt_ListUDPProcess
  In/Out：Out
  类型：指向数据结构指针的指针的指针
  可空：N
  意思：输出网络进程列表UDP连接,此内存必须手动释放
 参数.三：pInt_TCPCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出TCP连接个数
 参数.四：pInt_UDPCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出UDP连接个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一和二必须使用基础库的BaseLib_OperatorMemory_Free释放内存
*********************************************************************/
extern "C" bool XSocket_Api_NetList(XSOCKET_NETTABLE * **pppSt_ListTCPProcess, XSOCKET_NETTABLE * **pppSt_ListUDPProcess, int* pInt_TCPCount, int* pInt_UDPCount);
/********************************************************************
函数名称：XSocket_Api_GetAddress
函数功能：获取套接字的IP地址
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：输入要操作的套接字
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出IP:PORT
 参数.三：bLocal
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是获取本地还是远程,默认本地
 参数.四：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入IP版本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XSocket_Api_GetAddress(XSOCKET hSocket, XCHAR* ptszIPAddr, bool bLocal = true, int nIPVer = 2);
/********************************************************************
函数名称：XSocket_Api_GetCardInfo
函数功能：获取网卡信息
 参数.一：pppSt_ListIFInfo
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的网卡信息列表
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的列表个数
 参数.三：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：获取的IP地址版本,0为所有,否则2或AF_INET6
返回值
  类型：逻辑型
  意思：是否成功
备注：需要BaseLib_OperatorMemory_Free释放参数一内存
*********************************************************************/
extern "C" bool XSocket_Api_GetCardInfo(XSOCKET_CARDINFO*** pppSt_ListIFInfo, int* pInt_ListCount, int nIPVer = 0);