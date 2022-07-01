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
//                   回调函数导出定义
//////////////////////////////////////////////////////////////////////////
//套接字测试回调:测试句柄，测试的服务器地址，测试的端口，当前测试客户端编号，当前测试次数，接受的数据大小（如果bIsRecv为真），自定义参数
typedef void(CALLBACK* CALLBACK_XENGINE_NETHELP_STRESSTEST_SOCKET)(XNETHANDLE xhToken, LPCSTR lpszAddr, int nPort, int nClient, int nNumber, int nMsgLen, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                   结构体导出定义
//////////////////////////////////////////////////////////////////////////
//重复连接测试结构体
typedef struct tag_NetHelp_StressTest_ReConnect
{
    CHAR tszAddr[64];                                                     //要测试的IP地址
    int nPort;                                                            //端口号码
    //单位毫秒：
    int nContWaitTime;                                                    //连接后等待多长时间关闭
    int nCloseWaitContTime;                                               //关闭后等待多长时间连接
    int nConnectCount;                                                    //要测试的客户端个数
    int nConnectTest;                                                     //每个客户端测试的次数
}NETHELP_STRESSTEST_RECONNECT, * LPNETHELP_STRESSTEST_RECONNECT;
//数据包压力测试
typedef struct tag_NetHelp_StressTest_Datas
{
    SOCKET hSocket;                                                       //套接字句柄
    CHAR tszAddr[64];                                                     //要测试的服务器地址
    int nPort;                                                            //要测试的端口号码
    int nClientCount;                                                     //要启动多少个客户测试服务器
    int nTestNumber;                                                      //每个客户端测试的次数
    int nWaitTime;                                                        //处理一次休息时间，毫秒
    BOOL bIsRecv;                                                         //每次发送一个包后是否需要等待回复
    int nMsgLen;                                                          //数据包大小，如果下面的值为NULL，那么这个值表示测试端允许发送的大小，否则表示下面的缓冲区大小
    //无论是自定义数据还是服务器填充，这个值的内存需要new出来，并且由模块内部delete，用户不需要删除
    CHAR* ptszMsgBuffer;                                                 //如果你的服务器有特殊数据测试，请填写这个参数，否则测试端将自定义数据发送,内存需要由用户管理
}NETHELP_STRESSTEST_DATAS, * LPNETHELP_STRESSTEST_DATAS;
//////////////////////////////////////////////////////////////////////////
//                   函数导出定义
//////////////////////////////////////////////////////////////////////////
//获取最后发生错误码
extern "C" DWORD StressTest_GetLastError(int* pInt_SysError = NULL);
/************************************************************************/
/*                   TCP压力测试                                        */
/************************************************************************/
/********************************************************************
函数名称：StressTest_TCPSocket_StartConnect
函数功能：测试连接
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
返回值
  类型：逻辑型
  意思：是否成功
备注：链接测试函数，链接一次后就关闭，一直重复测试服务器链接性能
*********************************************************************/
extern "C" BOOL StressTest_TCPSocket_StartConnect(XNETHANDLE * pxhNet, NETHELP_STRESSTEST_RECONNECT * pSt_ReConnect, CALLBACK_XENGINE_NETHELP_STRESSTEST_SOCKET fpCall_ReConnect, LPVOID lParam = NULL);
/********************************************************************
函数名称：StressTest_TCPSocket_GetConnect
 参数.一：获取状态
  In/Out：In
  类型：句柄
  可空：N
  意思：输入操作的句柄
 参数.二：pbRun
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：输出是否在运行
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL StressTest_TCPSocket_GetConnect(XNETHANDLE xhNet, BOOL * pbRun);
/********************************************************************
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
*********************************************************************/
extern "C" BOOL StressTest_TCPSocket_StopConnect(XNETHANDLE xhNet);
/********************************************************************
函数名称：StressTest_TCPSocket_StartDatas
函数功能：数据包测试函数
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出创建成功的句柄
 参数.二：nThreadCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入启动的测试线程个数,总测试客户端必须能被此参数整除
 参数.三：pSt_SocketDatas
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要测试的属性
 参数.四：fpCall_DataTest
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
*********************************************************************/
extern "C" BOOL StressTest_TCPSocket_StartDatas(XNETHANDLE * pxhNet, int nThreadCount, NETHELP_STRESSTEST_DATAS * pSt_SocketDatas, CALLBACK_XENGINE_NETHELP_STRESSTEST_SOCKET fpCall_DataTest, LPVOID lParam = NULL);
/********************************************************************
函数名称：StressTest_TCPSocket_GetDatas
 参数.一：获取状态
  In/Out：In
  类型：句柄
  可空：N
  意思：输入操作的句柄
 参数.二：pbRun
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：输出是否在运行
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL StressTest_TCPSocket_GetDatas(XNETHANDLE xhNet, BOOL * pbRun);
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
/*                   UDP压力测试                                        */
/************************************************************************/
/********************************************************************
函数名称：StressTest_UDPSocket_StartDatas
函数功能：数据包测试函数
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出创建成功的句柄
 参数.二：nThreadCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入允许的线程个数,测试个数必须被线程个数整除
 参数.三：pSt_SocketDatas
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要测试的属性
 参数.四：fpCall_DataTest
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：测试回调信息
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：N
  意思：回调函数自定义参数
 参数.六：pSt_SocketDatas
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要测试的属性
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL StressTest_UDPSocket_StartDatas(XNETHANDLE * pxhNet, int nThreadCount, NETHELP_STRESSTEST_DATAS * pSt_SocketDatas, CALLBACK_XENGINE_NETHELP_STRESSTEST_SOCKET fpCall_DataTest, LPVOID lParam = NULL);
/********************************************************************
函数名称：StressTest_UDPSocket_GetDatas
 参数.一：获取状态
  In/Out：In
  类型：句柄
  可空：N
  意思：输入操作的句柄
 参数.二：pbRun
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：输出是否在运行
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL StressTest_UDPSocket_GetDatas(XNETHANDLE xhNet, BOOL* pbRun);
/********************************************************************
函数名称：StressTest_UDPSocket_StopDatas
函数功能：停止数据包测试
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入测试的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL StressTest_UDPSocket_StopDatas(XNETHANDLE xhNet);