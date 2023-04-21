#pragma once
/********************************************************************
//    Created:     2023/01/06  10:18:18
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIClient\APIClient_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIClient
//    File Base:   APIClient_Error
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     导出的网络客户端错误码
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        HTTP客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_PARAMENT 0x60A0000           //参数错误 
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_MALLOC 0x60A0001             //申请内存失败
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_INIT 0x60A0002               //初始化失败
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_NOTFOUND 0x60A0003           //没有找到
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_PERFORM 0x60A0004            //执行失败
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_GETCODE 0x60A0005            //获取的CODE不正确
//////////////////////////////////////////////////////////////////////////
//                        EMail客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_PARAMENT 0x60A1001           //参数错误
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_INITLIB 0x60A1002            //初始化邮件客户端库失败，内部错误
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_MALLOC 0x60A1003             //申请空间失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_FROM 0x60A1004               //设置发送from失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_UPLOAD 0x60A1005             //设置上传模式失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_PROCESS 0x60A1006            //处理失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SERVER 0x60A1007             //设置服务器失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_ADDCERT 0x60A1018            //添加证书失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_CLOSESSLPEER 0x60A1009       //关闭SSL认证失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_CLOSESSLHOST 0x60A1010       //关闭主机认证失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SSLSUPPORT 0x60A1011         //启用SSL支持失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SSLDEFAULT 0x60A1012         //设置SSL默认信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SSLCACHE 0x60A1013           //设置SSL缓存失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_USERNAME 0x60A1014           //设置用户名失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_PASSWORD 0x60A1015           //设置密码失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_WRITEFUNC 0x60A1016          //设置写入函数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_WRITEDATA 0x60A1017          //设置写入信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_READFUNC 0x60A1018           //设置读取函数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_READDATA 0x60A1019           //设置读取信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_DEBUGINFO 0x60A1020          //设置DEBUG信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_NOTFOUND 0x60A1021           //没有找到
//////////////////////////////////////////////////////////////////////////
//                        文件上传下载客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_PARAMENT 0x60A2001          //创建HTTP下载参数错误
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_MALLOC 0x60A2002            //申请空间失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_INIT 0x60A2003              //初始化下载引擎失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_OPENFILE 0x60A2004          //打开文件失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_CREATETHREAD 0x60A2005      //创建下载线程失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_URLADDR 0x60A2006           //设置下载地址失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_CONNTIMEDOUT 0x60A2007      //设置连接超时失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_RWTIMEDOUT 0x60A2008        //设置读写超时失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_WRITEFUNC 0x60A2009         //设置写操作函数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_WRITEPARAMENT 0x60A2010     //设置写操作函数参数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_UPLOAD 0x60A2011            //上传设置失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_READFUNC 0x60A2012          //读取函数设置失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_READPARAMENT 0x60A2013      //读取参数设置失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_SETSIZE 0x60A2014           //设置大小错误
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_PASV 0x60A2015              //设置失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_METHOD 0x60A2016            //方法设置失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_SETPROGRESS 0x60A2017       //设置过程失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_PROGRESSFUNC 0x60A2018      //设置过程函数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_PROGRESSPARAMENT 0x60A2019  //设置过程函数参数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_SETRANGE 0x60A2020          //设置文件写入位置失败，文件续传出现错误
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_NOTFOUND 0x60A2021          //暂停失败，没有找到任务
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_NOTDOWNLOADING 0x60A2022    //暂停失败，找到任务，但是任务没有下载
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_ISSUSPENDED 0x60A2023       //暂停失败，任务已经是暂停中
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_PAUSEALL 0x60A2024          //暂停下载失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_ISDOWNLOADING 0x60A2025     //已经在下载中，无法恢复下载
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_NOTSUSPENDED 0x60A2026      //不是暂停状态，状态错误，无法恢复
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_UNPAUSEALL 0x60A2027        //恢复下载失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_SETURL 0x60A2028            //设置URL失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_NOTHEADER 0x60A2029         //设置头失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_NOTBODY 0x60A2030           //设置内容失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_EXEC 0x60A2031              //执行失败，内部错误
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_LENGTH 0x60A2032            //获取长度失败，内部错误
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_MAXRECV 0x60A2033           //设置最大接受速度失败
#define ERROR_XENGINE_NETHELP_APICLIENT_FILE_MAXRSEND 0x60A2034          //设置最大发送速度失败