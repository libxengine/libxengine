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
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_PARAMENT 0x40A0001                 //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_NOTEXIST 0x40A0002                 //不存在
//枚举文件与文件夹
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SAVETOBUF_PARAMENT 0x40A0010       //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SAVETOBUF_CREATE 0x40A0011         //创建文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_PARAMENT 0x40A0020            //枚举文件失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_NOFILE 0x40A0021              //没有文件
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_OPENDIR 0x40A0022             //打开文件夹失败
//创建多级目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_CREATEFOLDER_PARMENT 0x40A0030     //创建目录失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_CREATEFOLDER_MKDIR 0x40A0031       //内部发生了一个错误
//删除多级目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_PARMENT 0x40A0040     //参数错误
//稀疏文件操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_PARAMENT 0x40A0050      //参数错误,创建稀疏文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_CREATE 0x40A0051        //创建错误,内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_SET 0x40A0502           //设置为稀疏文件失败
//文件拷贝
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_PARAMENT 0x40A0070        //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_EXIST 0x40A0071           //文件存在
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_COPYFILE_WRITEFILE 0x40A0072       //写入文件失败
/************************************************************************/
/*                        系统SDK错误表                                 */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_PARAMENT 0x40A1001               //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CREATE 0x40A1002                 //创建失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CONNECT 0x40A1003                //链接失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_QUERY 0x40A1004                  //查询失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_FAILED 0x40A1005                 //内部函数处理失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_OPEN 0x40A1006                   //打开失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_PROCESS 0x40A1007                //获取进程信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETINFO 0x40A1008                //获取系统信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SNAPSHOT 0x40A1009               //获取系统快照失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_NOTSUPPORT 0x40A1010             //不支持此操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SIGN 0x40A1011                   //信号处理失败
/************************************************************************/
/*                        硬件SDK                                        */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_PARAMENT 0x40A2001             //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_GETDISKSPACE 0x40A2002         //获取硬盘空间大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_NOTSUPPORT 0x40A2003           //不支持此返回大小类型
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_GETOTHER 0x40A2004             //获取其他信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_MALLOC 0x40A2005               //申请内存失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_GETMEMORY 0x40A2006            //获取内存大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_FAILED 0x40A2007               //处理失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_COMMAND 0x40A2008             //执行命令失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_OPENFILE 0x40A2009             //打开文件失败
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