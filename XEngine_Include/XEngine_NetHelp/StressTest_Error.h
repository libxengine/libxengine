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
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_CONNECT_PARAMRT 0x100D0001      //参数错误
#define ERROR_NETHELP_STRESSTEST_TCPSOCKET_DATAS_PARAMRT 0x100D0010        //参数错误
#define ERROR_NETHELP_STRESSTEST_UDPSOCKET_DATAS_PARAMRT 0x100D1000        //参数错误
//////////////////////////////////////////////////////////////////////////
//                 恶性攻击错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_STRESSTEST_DDOS_ICMP_PARAMRT 0x100D1001             //参数错误
#define ERROR_NETHELP_STRESSTEST_DDOS_SYN_PARAMRT 0x100D2001              //参数错误
//////////////////////////////////////////////////////////////////////////
//                 ARP攻击错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_STRESSTEST_ARPTEST_START_PARAMRT 0x100D2001         //开始失败，参数错误
#define ERROR_NETHELP_STRESSTEST_ARPTEST_RANDOM_PARAMRT 0x100D2010        //生成失败，参数错误
