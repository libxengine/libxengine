#pragma once
/********************************************************************
//	Created:	2012/1/21  17:26
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_ManagePool\ManagePool_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_ManagePool
//	File Base:	ManagePool_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	池管理器错误导出列表
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                  导出错误列表
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                  连接池导出错误列表                                  */
/************************************************************************/
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_PARAMENTTOOBIG 0x20B0000          //参数太大
#define ERROR_XCORE_MANAGEPOOL_SOCKET_RETIDLE_NOTFOUNDINDEX 0x20B0010          //没有找到索引
#define ERROR_XCORE_MANAGEPOOL_SOCKET_RETIDLE_NOTFOUNDSOCKET 0x20B0011         //没有找到指定的XSOCKET
#define ERROR_XCORE_MANAGEPOOL_SOCKET_GETIDLE_NOTIDLESOCKET 0x20B0020          //没有空闲的套接字
#define ERROR_XCORE_MANAGEPOOL_SOCKET_GETIDLE_NOTFOUNDINDEX 0x20B0021          //查找索引失败，无法继续
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_BUFSIZE_SOCKETISFAILED 0x20B00   //套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_BUFSIZE_SOSND 0x20B0031          //设置发送缓冲区失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_BUFSIZE_SORCV 0x20B0032          //设置接受缓冲区失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_BUFSIZE_PARAMENT 0x20B0033       //参数错误，无法继续
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_SETTCPV4 0x20B0040                //设置TCPV4版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_SETUDPV4 0x20B0041                //设置UDPV4版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_SETTCPV6 0x20B0042                //设置TCPV6版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_SETUDPV6 0x20B0043                //设置UDPV6版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_SETRAWV4 0x20B0044                //设置原始套接字失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_SETRAWV6 0x20B0045                //设置原始套接字失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CREATE_NOTSUPPORT 0x20B0046              //不支持此选项
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_TIMEOUT_SOCKETISFAILED 0x20B0050 //超时设置失败套接字句柄错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_TIMEOUT_PARAMENTISNULL 0x20B0051 //参数错误，后面的参数全为空
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_TIMEOUT_SETSNDFAILED 0x20B0052   //设置发送超时失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_TIMEOUT_SETRCVFAILED 0x20B0053   //设置接受超时失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_HIGH_SOCKETISFAILED 0x20B0060    //套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_HIGH_PARAMENTISNULL 0x20B0061    //参数全是NULL
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_HIGH_DELAY 0x20B0062             //高级选项沾包处理设置失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_HIGH_KEEPALIVE 0x20B0063         //保活计时器设置失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_HIGH_REUSEADDR 0x20B0064         //地址重用设置失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_LINGER_SOCKETISFAILED 0x20B0070  //套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_LINGER_PARAMENTISNULL 0x20B0071  //参数错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_SNDLINGER_SET 0x20B0080          //设置发送延迟失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_SET_STRUCTPOINT 0x20B0081            //结构体指针为空，无法继续
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_HIGH_SOCKETISFAILED 0x20B0090    //获取高级选项失败，套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_HIGH_PARAMENTISNULL 0x20B0091    //参数错误，全为NULL。没有任何意义
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_HIGH_DELAY 0x20B0092             //获取沾包处理是否开启失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_HIGH_KEEPALIVE 0x20B0093         //获取保活计时器状态失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_HIGH_REUSEADDR 0x20B0094         //获取地址重用状态失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_LINGER_SOCKETISFAILED 0x20B00A0  //套接字句柄错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_LINGER_PARAMENTISNULL 0x20B00A1  //参数为空，没有意义
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_SNDLINGER_GET 0x20B00B0          //获取LINGER选项失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_STRUCTPOINT 0x20B00B1            //获取失败，参数结构体指针为NULL
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_BUFSIZE_SOCKETISFAILED 0x20B00C0 //获取缓冲区大小失败，套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_BUFSIZE_PARAMENT 0x20B00C1       //获取失败，参数全为NULL
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_BUFSIZE_SOSND 0x20B00C2          //获取发送缓冲区大小失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_BUFSIZE_SORCV 0x20B00C3          //获取接受缓冲区大小失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_TIMEOUT_SOCKETISFAILED 0x20B00D  //获取超时时间失败，套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_TIMEOUT_PARAMENTISNULL 0x20B00D  //参数错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_TIMEOUT_SETSNDFAILED 0x20B00D2   //获取发送超时时间失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_TIMEOUT_SETRCVFAILED 0x20B00D3   //获取接受超时时间失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_OPT_GET_ERRORCODE_GET 0x20B00E0          //获取错误码失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SIZE_PARAMENT 0x20B00F0                  //参数错误，太大
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SIZE_NOTFOUNDINDEX 0x20B00F1             //没有找到索引
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CLOSE_SHUTDOWN 0x20B00F2                 //卸载一个指定的套接字失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CLOSE_CLOSE 0x20B00F3                    //关闭一个套接字失败
/************************************************************************/
/*                  线程池导出错误列表                                  */
/************************************************************************/
#define ERROR_XCORE_MANAGEPOOL_THREAD_CREATE_ISRUNNING 0x20B1000               //已经运行，不需要再次运行
#define ERROR_XCORE_MANAGEPOOL_THREAD_CREATE_PARAMENT 0x20B1001                //创建线程池大小不合适，可能过大或者过小

#define ERROR_XCORE_MANAGEPOOL_THREAD_POSTWORK_NOTRUN 0x20B1010                //投递失败，没有运行
#define ERROR_XCORE_MANAGEPOOL_THREAD_POSTWORK_PARAMENT 0x20B1011              //参数错误，无法继续，为NULL

#define ERROR_XCORE_MANAGEPOOL_THREAD_POSTWORK_NOTFOUNDBUSYMAP 0x20B1014       //没有找到相关的忙碌线程表

#define ERROR_XCORE_MANAGEPOOL_THREAD_INSERTTHREAD_MALLOC 0x20B1030            //为线程申请空间失败
#define ERROR_XCORE_MANAGEPOOL_THREAD_INSERTTHREAD_CREATE 0x20B1031            //创建新线程失败
#define ERROR_XCORE_MANAGEPOOL_THREAD_GET_PARAMENT 0x20B1040                   //获取失败，参数为NULL
#define ERROR_XCORE_MANAGEPOOL_THREAD_SET_PARAMENT 0x20B1060                   //设置失败，参数不合理
#define ERROR_XCORE_MANAGEPOOL_THREAD_EX_CREATE_MALLOC 0x20B1070               //申请内存失败
#define ERROR_XCORE_MANAGEPOOL_THREAD_EX_NOTFOUND 0x20B1071                    //没有找到
#define ERROR_XCORE_MANAGEPOOL_THREAD_POSTWITHCOUNT_NOTFOUNDTASK 0x20B1090     //投递任务失败，没有找到线程
#define ERROR_XCORE_MANAGEPOOL_THREAD_POSTWITHCOUNT_NOTFOUNDTHREAD 0x20B1091   //没有找到线程池
#define ERROR_XCORE_MANAGEPOOL_THREAD_POSTCOMPETE_FULL 0x20B10A0               //投递线程失败,任务队列已经满了
//无队列线程池
#define ERROR_XCORE_MANAGEPOOL_THREADNQ_CREATE_PARAMENT 0x20B1100              //创建失败,参数错误
#define ERROR_XCORE_MANAGEPOOL_THREADNQ_CREATE_RANGE 0x20B1101                 //线程池大小范围不对
#define ERROR_XCORE_MANAGEPOOL_THREADNQ_CREATE_MALLOC 0x20B1102                //申请内存失败
#define ERROR_XCORE_MANAGEPOOL_THREADNQ_CREATE_THREAD 0x20B1103                //创建线程失败
/************************************************************************/
/*                  内存池导出错误列表                                  */
/************************************************************************/
#define ERROR_XCORE_MANAGEPOOL_MEMORY_CREATE_MAINMALLOC 0x20B2000              //申请主结构内存失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_CREATE_LARGELISTMALLOC 0x20B2001         //申请大内存结构链表失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_CREATE_CHUNKLISTMALLOC 0x20B2002         //申请小块结构链表内存失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_CREATE_LARGEMALLOC 0x20B2003             //申请大内存失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_CREATE_CHUNKMALLOC 0x20B2004             //申请块内存失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_ALIGN_MALLOC 0x20B2010                   //申请内存对齐空间失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_LARGE_MALLOC 0x20B2020                   //申请大内存失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_CHUNK_MALLOC 0x20B2030                   //申请块内存失败

