#pragma once
/********************************************************************
//	Created:	2012/5/6  3:05
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_NetHelp\NetHelp_StressTesting\StressTesting_Define.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_NetHelp\NetHelp_StressTesting
//	File Base:	StressTesting_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		dowflyon
//	Purpose:	压力测试-函数导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                   枚举类型定义
//////////////////////////////////////////////////////////////////////////
//测试状态
typedef enum en_NetHelp_StressTest_Status
{
    ENUM_NETHELP_STRESSTEST_STATUS_START = 0,                //开始状态，回调nTestTime表示开始的时间进度
    ENUM_NETHELP_STRESSTEST_STATUS_PROCESS = 1,              //执行状态，回调nTestTime表示现在的时间进度
    ENUM_NETHELP_STRESSTEST_STATUS_COMPLATE = 2              //完成状态，回调nTestTime表示执行完测试花费时间
}ENUM_NETHELP_STRESSTEST_STATUS;
//////////////////////////////////////////////////////////////////////////
//                   回调函数导出定义
//////////////////////////////////////////////////////////////////////////
//连接测试回调，参数：测试句柄，测试的服务器地址，测试的端口，当前测试客户端编号，当前测试次数，测试状态，测试完成所花费时间（秒），自定义参数
typedef void(CALLBACK *CALLBACK_NETHELP_STRESSTEST_SOCKET_RECONNECT)(XNETHANDLE xhNet,LPCSTR lpszAddr,int nPort,int nClient,int nNumber,ENUM_NETHELP_STRESSTEST_STATUS enStatus,__int64 nTestTime,LPVOID lParam);
//数据包并发压力测试:测试句柄，测试的服务器地址，测试的端口，当前测试客户端编号，当前测试次数，接受的数据大小（如果bIsRecv为真），测试状态，测试完成所花费时间（秒），自定义参数
typedef void(CALLBACK *CALLBACK_NETHELP_STRESSTEST_SOCKET_DATAS)(XNETHANDLE xhNet,LPCSTR lpszAddr,int nPort,int nClient,int nNumber,int nMsgLen,ENUM_NETHELP_STRESSTEST_STATUS enStatus,__int64 nTestTime,LPVOID lParam);
//DDOS测试回调，参数：测试句柄，测试的服务器地址，测试的端口(ICMP为0)，当前测试客户端编号，当前测试次数，测试状态，测试完成所花费时间（秒），自定义参数
typedef void(CALLBACK *CALLBACK_NETHELP_STRESSTEST_SOCKET_DDOS)(XNETHANDLE xhNet,LPCSTR lpszAddr,int nPort,int nClient,int nNumber,ENUM_NETHELP_STRESSTEST_STATUS enStatus,__int64 nTestTime,LPVOID lParam);
//ARP测试回调，参数：测试句柄，测试MAC地址，测试的IP地址，当前测试客户端编号，当前测试次数，测试状态，测试完成所花费时间（秒），自定义参数
typedef void(CALLBACK *CALLBACK_NETHELP_STRESSTEST_SOCKET_ARP)(XNETHANDLE xhNet,LPCSTR lpszMACAddr,LPCSTR lpszIPAddr,int nClient,int nNumber,ENUM_NETHELP_STRESSTEST_STATUS enStatus,__int64 nTestTime,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                   结构体导出定义
//////////////////////////////////////////////////////////////////////////
//重复连接测试结构体
typedef struct tag_NetHelp_StressTest_ReConnect
{
    CHAR tszAddr[64];                                           //要测试的IP地址
    int nPort;                                                   //端口号码
    //单位毫秒：
    int nContWaitTime;                                           //连接后等待多长时间关闭
    int nCloseWaitContTime;                                      //关闭后等待多长时间连接
    int nConnectCount;                                           //要测试的客户端个数
    int nConnectTest;                                            //每个客户端测试的次数
}NETHELP_STRESSTEST_RECONNECT,*LPNETHELP_STRESSTEST_RECONNECT;
//数据包压力测试
typedef struct tag_NetHelp_StressTest_Datas
{
    CHAR tszAddr[64];                                                    //要测试的服务器地址
    int nPort;                                                            //要测试的端口号码
    int nClientCount;                                                     //要启动多少个客户测试服务器
    int nTestNumber;                                                      //每个客户端测试的次数
    int nWaitTime;                                                        //处理一次休息时间，毫秒
    BOOL bIsRecv;                                                         //每次发送一个包后是否需要等待回复
    int nMsgLen;                                                          //数据包大小，如果下面的值为NULL，那么这个值表示测试端允许发送的大小，否则表示下面的缓冲区大小
    //无论是自定义数据还是服务器填充，这个值的内存需要new出来，并且由模块内部delete，用户不需要删除
    CHAR *ptszMsgBuffer;                                                 //如果你的服务器有特殊数据测试，请填写这个参数，否则测试端将自定义数据发送
}NETHELP_STRESSTEST_DATAS,*LPNETHELP_STRESSTEST_DATAS;
//DDOS压力测试
typedef struct tag_NetHelp_StressTest_DDos
{
    CHAR tszAddr[64];                                                    //要测试的服务器地址
    int nPort;                                                            //要测试的端口号码
    int nClientCount;                                                     //要启动多少个客户测试服务器
    int nTestNumber;                                                      //每个客户端测试的次数
    int nWaitTime;                                                        //处理一次休息时间，毫秒
}NETHELP_STRESSTEST_DDOS,*LPNETHELP_STRESSTEST_DDOS;
//ARP测试结构体
typedef struct tag_NetHelp_StressTest_Arp
{
    CHAR tszMACSrc[64];                                         //原始MAC地址可以为空
    CHAR tszIPSrc[64];                                          //原始IP地址，可以为空
    CHAR tszMACDst[64];                                         //要测试的MAC地址
    CHAR tszIPDst[64];                                          //要测试的IP地址
    //单位毫秒：
    int nWaitTime;                                               //每次测试等待多少时间
    int nClientCount;                                            //要测试的客户端个数
    int nClientTest;                                             //每个客户端测试的次数
}NETHELP_STRESSTEST_ARP,*LPNETHELP_STRESSTEST_ARP;
//////////////////////////////////////////////////////////////////////////
//                   函数导出定义
//////////////////////////////////////////////////////////////////////////
//获取最后发生错误码
extern "C" DWORD StressTest_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                   数据压力测试                                       */
/************************************************************************/
/************************************************************************
函数名称：StressTest_TCPSocket_ShortConnect
函数功能：测试短连接
  参数.一：pxhNet
   In/Out：Out
   类型：句柄
   可空：N
   意思：导出创建成功的句柄
  参数.二：pSt_ReConnect
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：要测试的属性
  参数.三：fpCall_ReConnect
   In/Out：In/Out
   类型：回调函数
   可空：N
   意思：测试回调信息
  参数.四：lParam
   In/Out：In/Out
   类型：无类型指针
   可空：Y
   意思：回调函数自定义参数
  参数.五：pInt_Error
   In/Out：Out
   类型：整数型指针
   可空：Y
   意思：导出创建客户端失败的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：链接测试函数，链接一次后就关闭，一直重复测试服务器链接性能
************************************************************************/
extern "C" BOOL StressTest_TCPSocket_StartConnect(XNETHANDLE *pxhNet,NETHELP_STRESSTEST_RECONNECT *pSt_ReConnect,CALLBACK_NETHELP_STRESSTEST_SOCKET_RECONNECT fpCall_ReConnect,LPVOID lParam = NULL,int *pInt_Error = NULL);
/************************************************************************
函数名称：StressTest_TCPSocket_StopConnect
函数功能：停止短连接测试
  参数.一：xhNet
   In/Out：In
   类型：句柄
   可空：N
   意思：输入测试的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_TCPSocket_StopConnect(XNETHANDLE xhNet);
/************************************************************************
函数名称：StressTest_TCPSocket_StartDatas
函数功能：大数据包测试函数
  参数.一：pxhNet
   In/Out：Out
   类型：句柄
   可空：N
   意思：导出创建成功的句柄
  参数.二：pSt_SocketDatas
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：要测试的属性
  参数.三：fpCall_DataTest
   In/Out：In/Out
   类型：回调函数
   可空：N
   意思：测试回调信息
  参数.四：lParam
   In/Out：In/Out
   类型：无类型指针
   可空：Y
   意思：回调函数自定义参数
  参数.五：pInt_Error
   In/Out：Out
   类型：整数型指针
   可空：Y
   意思：导出创建客户端失败的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：数据包压力测试函数
************************************************************************/
extern "C" BOOL StressTest_TCPSocket_StartDatas(XNETHANDLE *pxhNet,NETHELP_STRESSTEST_DATAS *pSt_SocketDatas,CALLBACK_NETHELP_STRESSTEST_SOCKET_DATAS fpCall_DataTest,LPVOID lParam = NULL,int *pInt_Error = NULL);
/************************************************************************
函数名称：StressTest_TCPSocket_DatasStop
函数功能：停止大数据包测试
  参数.一：xhNet
   In/Out：In
   类型：句柄
   可空：N
   意思：输入测试的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_TCPSocket_StopDatas(XNETHANDLE xhNet);
/************************************************************************/
/*                   协议攻击测试                                       */
/************************************************************************/
/************************************************************************
函数名称：StressTest_DDos_ICMPStart
函数功能：ICMP包测试函数
  参数.一：pxhNet
   In/Out：Out
   类型：句柄
   可空：N
   意思：导出创建成功的句柄
  参数.二：pSt_StressDDos
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：要测试的属性
  参数.三：fpCall_DataTest
   In/Out：In/Out
   类型：回调函数
   可空：N
   意思：测试回调信息
  参数.四：lParam
   In/Out：In/Out
   类型：无类型指针
   可空：Y
   意思：回调函数自定义参数
  参数.五：pInt_Error
   In/Out：Out
   类型：整数型指针
   可空：Y
   意思：导出创建失败的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_DDos_ICMPStart(XNETHANDLE *pxhNet,NETHELP_STRESSTEST_DDOS *pSt_StressDDos,CALLBACK_NETHELP_STRESSTEST_SOCKET_DDOS fpCall_StressDDos,LPVOID lParam = NULL,int *pInt_Error = NULL);
/************************************************************************
函数名称：StressTest_DDos_ICMPStop
函数功能：停止ICMP测试
  参数.一：xhNet
   In/Out：In
   类型：句柄
   可空：N
   意思：输入测试的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_DDos_ICMPStop(XNETHANDLE xhNet);
/************************************************************************
函数名称：StressTest_DDos_SYNStart
函数功能：SYN包测试函数
  参数.一：pxhNet
   In/Out：Out
   类型：句柄
   可空：N
   意思：导出创建成功的句柄
  参数.二：lpszSrcAddr
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：原始发送地址，可伪造
  参数.三：nSrcPort
   In/Out：In
   类型：整数型
   可空：N
   意思：原始发送端口，可伪造
  参数.四：pSt_StressDDos
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：要测试的属性
  参数.五：fpCall_DataTest
   In/Out：In/Out
   类型：回调函数
   可空：N
   意思：测试回调信息
  参数.六：lParam
   In/Out：In/Out
   类型：无类型指针
   可空：Y
   意思：回调函数自定义参数
  参数.七：pInt_Error
   In/Out：Out
   类型：整数型指针
   可空：Y
   意思：导出创建失败的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_DDos_SYNStart(XNETHANDLE *pxhNet,LPCSTR lpszSrcAddr,int nSrcPort,NETHELP_STRESSTEST_DDOS *pSt_StressDDos,CALLBACK_NETHELP_STRESSTEST_SOCKET_DDOS fpCall_StressDDos,LPVOID lParam = NULL,int *pInt_Error = NULL);
/************************************************************************
函数名称：StressTest_DDos_SYNStop
函数功能：停止SYN测试
  参数.一：xhNet
   In/Out：In
   类型：句柄
   可空：N
   意思：输入测试的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_DDos_SYNStop(XNETHANDLE xhNet);
/************************************************************************/
/*                   ARP攻击测试                                       */
/************************************************************************/
/************************************************************************
函数名称：StressTest_ARPSocket_Start
函数功能：测试ARP协议
  参数.一：pxhNet
   In/Out：Out
   类型：句柄
   可空：N
   意思：导出创建成功的句柄
  参数.二：pSt_ReConnect
   In/Out：In
   类型：数据结构指针
   可空：N
   意思：要测试的属性
  参数.三：lpszDevName
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：要对哪个网卡进行操作
  参数.四：fpCall_ReConnect
   In/Out：In/Out
   类型：回调函数
   可空：N
   意思：测试回调信息
  参数.五：lParam
   In/Out：In/Out
   类型：无类型指针
   可空：Y
   意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_ARPSocket_Start(XNETHANDLE *pxhNet,NETHELP_STRESSTEST_ARP *pSt_ARPTest,LPCSTR lpszDevName,CALLBACK_NETHELP_STRESSTEST_SOCKET_ARP fpCall_ARPTest,LPVOID lParam = NULL);
/************************************************************************
函数名称：StressTest_ARPSocket_Stop
函数功能：停止ARP测试
  参数.一：xhNet
   In/Out：In
   类型：句柄
   可空：N
   意思：输入测试的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_ARPSocket_Stop(XNETHANDLE xhNet);
/************************************************************************
函数名称：StressTest_ARPSocket_Random
函数功能：生成随机的MAC地址和IP地址
  参数.一：ptszMACAddr
   In/Out：Out
   类型：字符指针
   可空：N
   意思：输出随机生成的MAC地址
  参数.二：ptszIPAddr
   In/Out：Out
   类型：字符指针
   可空：N
   意思：输出随机生成的IP地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
************************************************************************/
extern "C" BOOL StressTest_ARPSocket_Random(CHAR *ptszMACAddr,CHAR *ptszIPAddr);
