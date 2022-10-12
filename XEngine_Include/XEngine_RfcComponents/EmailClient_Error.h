#pragma once
/********************************************************************
//	Created:	2013/1/3  19:07
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_EmailClient\EmailClient_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_EmailClient
//	File Base:	EmailClient_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	电子邮件客户端导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的错误码
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      SMTP电子邮件客户端错误码                        */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_INIT_PARAMENT 0x120A0001            //参数错误
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_INIT_INITLIB 0x120A0002             //初始化邮件客户端库失败，内部错误
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_INIT_MALLOC 0x120A0003              //申请空间失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_SERVICEADDR 0x120A0010       //设置选项失败，设置服务器地址失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_ADDCERT 0x120A0011           //添加证书失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_CLOSESSLPEER 0x120A0012      //关闭SSL节点失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_CLOSESSLHOST 0x120A0013      //关闭主机验证失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_ENCRYPTED 0x120A0014         //设置安全传输失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_SETSSLDEFAULT 0x120A0015     //设置SSL默认信息失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_SSLCACHE 0x120A0016          //设置SSL缓存失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_USERNAME 0x120A0017          //设置用户名失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_PASSWORD 0x120A0018          //设置密码失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_FROM 0x120A0019              //设置回复地址失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_UPLOAD 0x120A001A            //设置发送消息类型失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETOPT_DEBUGINFO 0x120A001B         //设置调试信息失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SEND_NOTFOUNDCLIENT 0x120A0032      //没有找到指定的邮件客户端
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SEND_START 0x120A0034               //发送失败，内部错误
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SEND_CREATETHREAD 0x120A0035        //创建线程失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETTEXT_READFUNC 0x120A0040         //设置读取函数失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETTEXT_READPARAMENT 0x120A0041     //设置读取函数参数失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETCALL_PARAMENT 0x120A0050         //参数错误，无法设置
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_SMTP_SETCALL_NOTFOUND 0x120A0051         //没有找到客户端
/************************************************************************/
/*                      POP3电子邮件客户端错误码                        */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETCALL_PARAMENT 0x120A1001         //设置回调失败，参数错误
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETCALL_NOTFOUND 0x120A1002         //查找客户端失败,没找到
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_INIT_PARAMENT 0x120A1010            //初始化失败，参数错误
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_INIT_MALLOC 0x120A1011              //申请内存失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_INIT_INITLIB 0x120A1012             //初始化网络协议库失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_CLOSEHEADER 0x120A1021       //关闭头失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_SERVICEURL 0x120A1022        //设置服务器地址失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_USERPASS 0x120A1023          //设置用户名密码失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_WRITEFUNC 0x120A1024         //设置写函数失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_WRITEPARAMENT 0x120A1025     //设置参数失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_ADDCERT 0x120A1026           //设置证书失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_CLOSESSLPEER 0x120A1027      //关闭SSL节点失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_CLOSESSLHOST 0x120A1028      //关闭SSL主机失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_ENCRYPTED 0x120A1029         //设置SSL会话自动错误处理失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_SSLDEFAULT 0x120A102A        //设置SSL默认处理协议失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_SSLCACHE 0x120A102B          //设置SSL缓存失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_SETOPT_DEBUGINFO 0x120A102C         //设置调试信息失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_OPEN_CACHEFILE 0x120A1030           //打开缓存文件失败，可能权限不足，可能文件路径有问题
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_RECV_NOTFOUND 0x120A1040            //没有找到客户端
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_RECV_ISFAILED 0x120A1041            //接受失败，获取邮件个数失败
#define ERROR_RFCCOMPONENTS_EMAILCLIENT_POP3_RECV_CREATETHREAD 0x120A1042        //创建线程失败
