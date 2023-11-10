#pragma once
/********************************************************************
//	     此项目文件基本属性如下
//  Created:	2011/02/26   15:04
// 	FileName: 	/LinuxNetEngine/NetSocketEngine/NetEngine_LinuxApi/NetEngine_ProcSdk/ProcFile_Error.h
//	File Path:	/LinuxNetEngine/NetSocketEngine/NetEngine_LinuxApi/NetEngine_ProcSdk/
//	File Base:	ProcFile_Error
//	File Ext:	h
//	Author:		dowflyon
//  Project:    NetSocketEngine (网络通信引擎)
//	PurPose:	PROC文件系统导出错误
//  History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                            导出的错误码
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                进程信息获取错误码                                       */
/************************************************************************/
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_STATREAD_PARAMENT 0x40B0001             //参数错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_STATREAD_OPEN 0x40B0002                 //获取信息错误内部错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_STATREAD_GETDATA 0x40B0003              //获取PID错误
//进程CPU内存错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READCPU_PARAMENT 0x40B0010              //读取CPU信息参数错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READCPU_OPEN 0x40B0011                  //打开信息文件失败
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READCPU_GET 0x40B0012                   //获取信息文件失败
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READMEMORY_PARAMENT 0x40B0040           //参数错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READMEMORY_OPEN 0x40B0041               //打开文件失败
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READMEMORY_NOTFOUNDPID 0x40B0042        //没有找到PID
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READMEMORY_GETINFO 0x40B0043            //内部错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READMEMORY_GETSTRING 0x40B0044          //获取字符串错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_READMEMORY_FMTSTRUCT 0x40B0045          //格式化数据结构错误
//网络流量错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_NETDEVREAD_NOTFOUNDPID 0x40B0052        //没有找到指定PID
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_NETDEVREAD_GETINFO 0x40B0053            //获取信息失败
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_NETDEVREAD_FORMATSTRUCT 0x40B0054       //格式化数据结构错误
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_NETDEVREAD_NOTFOUND 0x40B0055           //没有找到指定ID的网络流量信息
#define ERROR_SYSTEMSDK_PROCFILE_PROCESS_NETDEVREAD_GETLINE 0x40B0056            //获取数据失败
/************************************************************************/
/*                系统信息获取导出错误                                     */
/************************************************************************/
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_CPUSTAT_PARAMENT 0x40B1001            //参数错误
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_CPUSTAT_OPENFILE 0x40B1002            //打开文件失败
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_CPUSTAT_NOTDATA 0x40B1003
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_HELPSTAT_PARAMENT 0x40B1010            //参数错误
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_HELPSTAT_MALLOC 0x40B1011              //申请空间失败
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_HELPSTAT_CPUPARAMENT 0x40B1012         //CPU参数错误
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_NETDEV_PARAMENT 0x40B1020              //参数错误
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_NETDEV_OPENFILE 0x40B1021              //打开设备文件失败
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_NETDEV_READ 0x40B1022                  //读取数据失败
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_NETDEV_NOTFOUND 0x40B1023              //没有找到指定的设备网卡名称
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_NETDEV_NOTSUPPORT 0x40B1024            //不支持，可能系统版本不支持，清联系我们
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_UPTIME_PARAMENT 0x40B1030              //参数错误
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_UPTIME_OPENFILE 0x40B1031              //打开失败
#define ERROR_SYSTEMSDK_PROCSYSTEM_SYSTEM_UPTIME_READ 0x40B1032                  //读取失败
/************************************************************************/
/*                硬件信息导出错误                                         */
/************************************************************************/
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_DISKINFO_PARAMENT 0x40B2000     //参数错误，无法继续
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_DISKINFO_OPEN 0x40B2001         //打开文件系统失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_DISKINFO_NULL 0x40B2002         //没有数据，可能不支持的系统版本
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_PARAMENT 0x40B2010      //参数错误，无法继续
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_OPEN 0x40B2011          //打开文件失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_ISNULL 0x40B2012        //没有数据，可能不支持的系统版本
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETVENDOR 0x40B2013     //获取供应商名称失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETNAME 0x40B2014       //获取家族号失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETBREAK 0x40B2015      //跳过一行失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETFAMILY 0x40B2016     //获取家族号失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETHARDCODE 0x40B2017   //获取硬件码失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETCPUMHZ 0x40B2018     //获取CPU速度失败
#define ERROR_SYSTEMSDK_PROCFILE_HARDWARE_CPUINFO_GETCACHE 0x40B2019      //获取缓存大小失败
