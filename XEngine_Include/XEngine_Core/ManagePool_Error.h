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
#define ERROR_XCORE_MANAGEPOOL_SOCKET_PARAMENT 0x20B0000                 //参数错误，无法继续
#define ERROR_XCORE_MANAGEPOOL_SOCKET_NOTFOUNDINDEX 0x20B0001            //没有找到索引
#define ERROR_XCORE_MANAGEPOOL_SOCKET_NOTFOUNDSOCKET 0x20B0002           //没有找到指定的XSOCKET
#define ERROR_XCORE_MANAGEPOOL_SOCKET_NOTIDLESOCKET 0x20B0003            //没有空闲的套接字
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SOCKETISFAILED 0x20B0004           //套接字错误
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SOSND 0x20B0005                    //设置发送缓冲区失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SORCV 0x20B0006                    //设置接受缓冲区失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETTCPV4 0x20B0007                 //设置TCPV4版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETUDPV4 0x20B0008                 //设置UDPV4版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETTCPV6 0x20B0009                 //设置TCPV6版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETUDPV6 0x20B0010                 //设置UDPV6版本失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETRAWV4 0x20B0011                 //设置原始套接字失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETRAWV6 0x20B0012                 //设置原始套接字失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_NOTSUPPORT 0x20B0013               //不支持此选项
#define ERROR_XCORE_MANAGEPOOL_SOCKET_PARAMENTISNULL 0x20B0014           //参数错误，后面的参数全为空
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETSNDFAILED 0x20B0015             //设置发送超时失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SETRCVFAILED 0x20B0016             //设置接受超时失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_DELAY 0x20B0017                    //高级选项沾包处理设置失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_KEEPALIVE 0x20B0018                //保活计时器设置失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_REUSEADDR 0x20B0019                //地址重用设置失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SET 0x20B0020                      //设置发送延迟失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_STRUCTPOINT 0x20B0021              //结构体指针为空，无法继续
#define ERROR_XCORE_MANAGEPOOL_SOCKET_GET 0x20B0022                      //获取LINGER选项失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_SHUTDOWN 0x20B0023                 //卸载一个指定的套接字失败
#define ERROR_XCORE_MANAGEPOOL_SOCKET_CLOSE 0x20B0024                    //关闭一个套接字失败
/************************************************************************/
/*                  线程池导出错误列表                                  */
/************************************************************************/
#define ERROR_XCORE_MANAGEPOOL_THREAD_ISRUNNING 0x20B1000                 //已经运行，不需要再次运行
#define ERROR_XCORE_MANAGEPOOL_THREAD_PARAMENT 0x20B1001                  //创建线程池大小不合适，可能过大或者过小
#define ERROR_XCORE_MANAGEPOOL_THREAD_NOTRUN 0x20B1002                    //投递失败，没有运行
#define ERROR_XCORE_MANAGEPOOL_THREAD_NOTFOUND 0x20B1003                  //没有找
#define ERROR_XCORE_MANAGEPOOL_THREAD_MALLOC 0x20B1004                    //为线程申请空间失败
#define ERROR_XCORE_MANAGEPOOL_THREAD_CREATE 0x20B1005                    //创建新线程失败
#define ERROR_XCORE_MANAGEPOOL_THREAD_NOTFOUNDTASK 0x20B1006              //投递任务失败，没有找到线程
#define ERROR_XCORE_MANAGEPOOL_THREAD_NOTFOUNDTHREAD 0x20B1007            //没有找到线程池
#define ERROR_XCORE_MANAGEPOOL_THREAD_FULL 0x20B1008                      //投递线程失败,任务队列已经满了
#define ERROR_XCORE_MANAGEPOOL_THREAD_RANGE 0x20B1009                     //线程池大小范围不对
#define ERROR_XCORE_MANAGEPOOL_THREAD_SETPRIORITY 0x20B1010               //设置优化级失败
#define ERROR_XCORE_MANAGEPOOL_THREAD_SETPAFFINITY 0x20B1011              //设置CPU亲和性失败
/************************************************************************/
/*                  内存池导出错误列表                                  */
/************************************************************************/
#define ERROR_XCORE_MANAGEPOOL_MEMORY_MALLOC 0x20B2000                    //申请主结构内存失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_ALIGNMALLOC 0x20B2001               //申请内存对齐空间失败
#define ERROR_XCORE_MANAGEPOOL_MEMORY_MAXCOUNT 0x20B2002                  //最大内存个数
#define ERROR_XCORE_MANAGEPOOL_MEMORY_PARAMENT 0x20B2003                  //参数错误
#define ERROR_XCORE_MANAGEPOOL_MEMORY_NOTFOUND 0x20B2004                  //没有找到
//////////////////////////////////////////////////////////////////////////
//                       多线程池并发工具
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_MANAGEPOOL_TASK_PARAMENT 0x20B3001                   //参数错误
#define ERROR_XCORE_MANAGEPOOL_TASK_NOTFOUND 0x20B3002                   //没有找到
#define ERROR_XCORE_MANAGEPOOL_TASK_MALLOC 0x20B3003                     //申请内存失败
#define ERROR_XCORE_MANAGEPOOL_TASK_TIMEOUT 0x20B3004                    //超时
#define ERROR_XCORE_MANAGEPOOL_TASK_NOPACKET 0x20B3005                   //没有包
#define ERROR_XCORE_MANAGEPOOL_TASK_CLOSEWAIT 0x20B3006                  //关闭等待,无法继续