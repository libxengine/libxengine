#pragma once
/********************************************************************
//	Created:	2012/5/6  3:05
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_NetHelp\NetHelp_StressTesting\StressTesting_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_NetHelp\NetHelp_StressTesting
//	File Base:	StressTesting_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		dowflyon
//	Purpose:	压力测试开发包错误导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                TCPSOCKET测试导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_CONNECT_PARAMRT 0x90B0001      //参数错误
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_CONNECT_MALLOC 0x90B0002       //申请内存失败
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_CONNECT_THREAD 0x90B0003       //创建线程失败
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_CONNECT_NOTFOUND 0x90B0004     //没有找到
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_DATAS_PARAMRT 0x90B0010        //参数错误
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_DATAS_MALLOC 0x90B0011         //申请内存失败
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_DATAS_THREAD 0x90B0012         //创建线程失败
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_DATAS_NOTFOUND 0x90B0013       //没有找到
//////////////////////////////////////////////////////////////////////////
//                UDPSOCKET测试导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_STRESSTEST_UDPSOCKET_DATAS_PARAMRT 0x90B1000        //参数错误
#define ERROR_NETHELP_STRESSTEST_UDPSOCKET_DATAS_MALLOC 0x90B1001         //申请内存失败
#define ERROR_NETHELP_STRESSTEST_UDPSOCKET_DATAS_THREAD 0x90B1002         //创建线程失败
#define ERROR_NETHELP_STRESSTEST_UDPSOCKET_DATAS_NOTFOUND 0x90B1003       //没有找到