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
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_PARAMENT 0x90C0000           //参数错误 
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_MALLOC 0x90C0001             //申请内存失败
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_INIT 0x90C0002               //初始化失败
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_NOTFOUND 0x90C0003           //没有找到
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_PERFORM 0x90C0004            //执行失败
#define ERROR_XENGINE_NETHELP_APICLIENT_HTTP_GETCODE 0x90C0005            //获取的CODE不正确
//////////////////////////////////////////////////////////////////////////
//                        EMail客户端请求错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_PARAMENT 0x90C1001           //参数错误
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_INITLIB 0x90C1002            //初始化邮件客户端库失败，内部错误
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_MALLOC 0x90C1003             //申请空间失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_FROM 0x90C1004               //设置发送from失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_UPLOAD 0x90C1005             //设置上传模式失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_PROCESS 0x90C1006            //处理失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SERVER 0x90C1007             //设置服务器失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_ADDCERT 0x90C1018            //添加证书失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_CLOSESSLPEER 0x90C1009       //关闭SSL认证失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_CLOSESSLHOST 0x90C1010       //关闭主机认证失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SSLSUPPORT 0x90C1011         //启用SSL支持失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SSLDEFAULT 0x90C1012         //设置SSL默认信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_SSLCACHE 0x90C1013           //设置SSL缓存失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_USERNAME 0x90C1014           //设置用户名失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_PASSWORD 0x90C1015           //设置密码失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_WRITEFUNC 0x90C1016          //设置写入函数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_WRITEDATA 0x90C1017          //设置写入信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_READFUNC 0x90C1018           //设置读取函数失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_READDATA 0x90C1019           //设置读取信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_DEBUGINFO 0x90C1020          //设置DEBUG信息失败
#define ERROR_XENGINE_NETHELP_APICLIENT_EMAIL_NOTFOUND 0x90C1021