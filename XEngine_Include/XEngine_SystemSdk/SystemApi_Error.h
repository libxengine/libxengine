#pragma once
/********************************************************************
//	Created:	2011/10/17   12:26
//	Filename: 	NetSocketEngine/NetLinuxSdk/LinuxSdk/LinuxSdk_Error.h
//	File Path:	NetSocketEngine/NetLinuxSdk/LinuxSdk/
//	File Base:	LinuxSdk
//	File Ext:	h
//  Project:    血与荣誉网络通信引擎 For Linux
//	Author:		dowflyon
//	Purpose:	LinuxSdk导出错误定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出错误定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*           文件操作SDK导出错误                                           */
/************************************************************************/
//枚举文件与文件夹
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ISDIR_PARAMENT 0x40A0001           //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ISDIR_NOTEXIST 0x40A0002           //文件夹不存在
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ISDIR_NOTDIR 0x40A0003             //不是文件夹
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SAVETOBUF_PARAMENT 0x40A0010       //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SAVETOBUF_CREATE 0x40A0011         //创建文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_PARAMENT 0x40A0020            //枚举文件失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_OPENDIR 0x40A0021             //枚举文件失败，打开目录错误
//创建多级目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_CREATEFOLDER_PARMENT 0x40A0030     //创建目录失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_CREATEFOLDER_MKDIR 0x40A0031       //内部发生了一个错误
//删除多级目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_PARMENT 0x40A0040     //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_ISNOTPATH 0x40A0041   //参数错误，不是一个目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_OPENDIR 0x40A0042     //打开目录失败，可能权限问题
//稀疏文件操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_PARAMENT 0x40A0050      //参数错误,创建稀疏文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_CREATE 0x40A0051        //创建错误,内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_SET 0x40A0502           //设置为稀疏文件失败
//文件拷贝
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_PARAMENT 0x40A0070        //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_EXIST 0x40A0071           //文件存在
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_OPENFILE 0x40A0072        //打开文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_CREATEFILE 0x40A0073      //创建文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_WRITEFILE 0x40A0074       //写入文件失败
/************************************************************************/
/*                        系统SDK错误表                                 */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETVER_PARAMENT 0x40A1001        //获取失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETVER_ISFAILED 0x40A1002        //获取失败，系统错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETVER_UNKNOW 0x40A1003          //无法识别的系统版本
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_MEM_PARAMENT 0x40A1010           //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_MEM_GETSYSINFO 0x40A1011         //获取系统信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CPU_PARAMENT 0x40A1020           //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETUPTIME_PARAMENT 0x40A1030     //获取系统启动时间失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETUPTIME_GETLOCLTIME 0x40A1032  //获取本地时间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETCOUNT_PARAMENT 0x40A1040      //获取全局个数失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETCOUNT_GETINFO 0x40A1041       //获取全局个数失败，获取信息内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SHUTDOWN_NOTSUPPORT 0x40A1050    //不支持的操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SHUTDOWN_EXEC 0x40A1051          //执行失败，内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_PARAMENT 0x40A1060      //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_SIGN 0x40A1061          //信号处理异常
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_CREATE 0x40A1062        //创建进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CPU_GETCPUFILE 0x40A10F0         //获取CPU状态文件信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CPU_ISNULL 0x40A10F1             //为空，无法继续
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_PARAMENT 0x40A1060      //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_FAILED 0x40A1061        //执行命令失败,可能不存在或者程序返回错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_IDLETIME_GETLASTINPUT 0x40A10B0  //获取系统空闲时间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_IDLETIME_ISFAILED 0x40A10B1      //获取时间信息失败
/************************************************************************/
/*                        硬件SDK                                        */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_PARAMENT 0x40A2001    //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_GETDISKSPACE 0x40A2002//获取硬盘空间大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_NOTSUPPORT 0x40A2003  //不支持此返回大小类型
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_GETOTHER 0x40A2004    //获取其他信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKCOUNT_PARAMENT 0x40A2010   //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKCOUNT_MALLOC 0x40A2011     //申请内存失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKCOUNT_GETMEMORY 0x40A2012  //获取内存大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_CPUINFO_PARAMENT 0x40A2020     //获取CPU信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_PARAMENT 0x160D2030      //参数错误,获取序列号失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_COMMAND 0x160D2031       //执行命令失败
/************************************************************************/
/*                        进程线程错误表                                  */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PARAMENT 0x40A3000              //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_OPEN 0x40A3001                  //打开失败,权限错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GET 0x40A3002                   //获取失败,内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PROCESSFIRST 0x40A3003          //跳转进程过程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_OPENPROCESS 0x40A3004           //打开进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETMEM 0x40A3005                //获取进程内存信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_USERINFO 0x40A3006              //获取所属用户失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_NOTFOUND 0x40A3007              //没有找到进程
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_MALLOC 0x40A3008                //申请内存失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETTOKEN 0x40A3009              //获取令牌失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETUSER 0x40A3010               //获取进程关联用户失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETTIME 0x40A3011               //获取时间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_FMTSYSTIME 0x40A3012            //格式化时间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETPRIORITY 0x40A3013           //获取优先级失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_SETPRIORITY 0x40A3014           //设置优先级失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_SETPARAMENT 0x40A3015           //设置优先级失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_ENUMPROCESS 0x40A3016           //结束进程失败,枚举进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_TERMINATE 0x40A3017             //结束失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_ISFAILED 0x40A3018              //内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_EXEC 0x40A3019                  //执行指定文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_SET 0x40A3020                   //设置失败