#pragma once
/********************************************************************
//    Created:     2024/02/21  10:00:12
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_APIHelp\APIClient_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_APIHelp
//    File Base:   APIClient_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     网络客户端集合导出错误
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        HTTP客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_PARAMENT 0x30D0000           //参数错误 
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_MALLOC 0x30D0001             //申请内存失败
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_INIT 0x30D0002               //初始化失败
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_NOTFOUND 0x30D0003           //没有找到
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_PERFORM 0x30D0004            //执行失败
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_GETCODE 0x30D0005            //获取的CODE不正确
#define ERROR_XENGINE_XCLIENT_APIHELP_HTTP_THREAD 0x30D0006             //创建线程失败
//////////////////////////////////////////////////////////////////////////
//                        EMail客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_PARAMENT 0x30D1001           //参数错误
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_INITLIB 0x30D1002            //初始化邮件客户端库失败，内部错误
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_MALLOC 0x30D1003             //申请空间失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_FROM 0x30D1004               //设置发送from失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_UPLOAD 0x30D1005             //设置上传模式失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_PROCESS 0x30D1006            //处理失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_SERVER 0x30D1007             //设置服务器失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_ADDCERT 0x30D1018            //添加证书失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_CLOSESSLPEER 0x30D1009       //关闭SSL认证失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_CLOSESSLHOST 0x30D1010       //关闭主机认证失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_SSLSUPPORT 0x30D1011         //启用SSL支持失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_SSLDEFAULT 0x30D1012         //设置SSL默认信息失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_SSLCACHE 0x30D1013           //设置SSL缓存失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_USERNAME 0x30D1014           //设置用户名失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_PASSWORD 0x30D1015           //设置密码失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_WRITEFUNC 0x30D1016          //设置写入函数失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_WRITEDATA 0x30D1017          //设置写入信息失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_READFUNC 0x30D1018           //设置读取函数失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_READDATA 0x30D1019           //设置读取信息失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_DEBUGINFO 0x30D1020          //设置DEBUG信息失败
#define ERROR_XENGINE_XCLIENT_APIHELP_EMAIL_NOTFOUND 0x30D1021           //没有找到
//////////////////////////////////////////////////////////////////////////
//                        文件上传下载客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_PARAMENT 0x30D2001          //创建HTTP下载参数错误
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_MALLOC 0x30D2002            //申请空间失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_INIT 0x30D2003              //初始化下载引擎失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_OPENFILE 0x30D2004          //打开文件失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_CREATETHREAD 0x30D2005      //创建下载线程失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_URLADDR 0x30D2006           //设置下载地址失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_CONNTIMEDOUT 0x30D2007      //设置连接超时失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_RWTIMEDOUT 0x30D2008        //设置读写超时失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_WRITEFUNC 0x30D2009         //设置写操作函数失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_WRITEPARAMENT 0x30D2010     //设置写操作函数参数失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_UPLOAD 0x30D2011            //上传设置失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_READFUNC 0x30D2012          //读取函数设置失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_READPARAMENT 0x30D2013      //读取参数设置失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_SETSIZE 0x30D2014           //设置大小错误
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_PASV 0x30D2015              //设置失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_METHOD 0x30D2016            //方法设置失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_SETPROGRESS 0x30D2017       //设置过程失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_PROGRESSFUNC 0x30D2018      //设置过程函数失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_PROGRESSPARAMENT 0x30D2019  //设置过程函数参数失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_SETRANGE 0x30D2020          //设置文件写入位置失败，文件续传出现错误
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_NOTFOUND 0x30D2021          //暂停失败，没有找到任务
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_NOTDOWNLOADING 0x30D2022    //暂停失败，找到任务，但是任务没有下载
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_ISSUSPENDED 0x30D2023       //暂停失败，任务已经是暂停中
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_PAUSEALL 0x30D2024          //暂停下载失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_ISDOWNLOADING 0x30D2025     //已经在下载中，无法恢复下载
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_NOTSUSPENDED 0x30D2026      //不是暂停状态，状态错误，无法恢复
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_UNPAUSEALL 0x30D2027        //恢复下载失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_SETURL 0x30D2028            //设置URL失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_NOTHEADER 0x30D2029         //设置头失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_NOTBODY 0x30D2030           //设置内容失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_EXEC 0x30D2031              //执行失败，内部错误
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_LENGTH 0x30D2032            //获取长度失败，内部错误
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_MAXRECV 0x30D2033           //设置最大接受速度失败
#define ERROR_XENGINE_XCLIENT_APIHELP_FILE_MAXRSEND 0x30D2034          //设置最大发送速度失败