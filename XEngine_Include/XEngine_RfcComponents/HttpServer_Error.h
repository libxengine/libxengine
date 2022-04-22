﻿#pragma once
/********************************************************************
//	Created:	2019/12/18   9:55
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_HttpServer\HttpServer_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_HttpServer
//	File Base:	HttpServer_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	HTTP服务导出错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的简单HTTP服务错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_PARAMENT 0x121A0000     //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_EMPTY 0x121A0001        //没有客户端可以获取包
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_NOTFOUND 0x121A0002     //没有可以处理的包
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_SIZE 0x121A0003         //提供的缓冲区大小不够
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_NOTDATA 0x121A0004      //此客户端没有数据
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_HDRCOMPLATE 0x121A0005  //HTTP头还没组包完成
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETCLIENT_BODYCOMPLATE 0x121A0006 //组包还没完成
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PARSE_PARAMENT 0x121A0010         //解析参数失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PARSE_NOHTTPHDR 0x121A0011        //没有HTTP头，或者HTTP不标准，无法继续
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PARSE_NOTMETHOD 0x121A0012        //没有方法名
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PARSE_NOTURL 0x121A0013           //没有URI地址
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PARSE_NOTVER 0x121A0014           //没有HTTP版本号
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_SENDMSG_PARAMENT 0x121A0020       //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_INSERT_PARAMENT 0x121A0030        //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_INSERT_NOTFOUND 0x121A0031        //没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_INSERT_RECV 0x121A0032            //数据已经接受完毕,无法继续投递,文件模式无法在一个连接处理多个文件上传请求
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PUSH_NOTHTTP 0x121A0040           //不是HTTP标准协议
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PUSH_MALLOCHDR 0x121A0041         //申请临时HTTP头内存失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PUSH_MALLOCLIST 0x121A0042        //申请HTTP头字段内存失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PUSH_MALLOCBODY 0x121A0043        //申请HTTP数据内存失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_PUSH_MOREPKG 0x121A0044           //客户端的包大小超过服务器限制,无法继续后续包将被抛弃
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_CLOSE_PARAMENT 0x121A0050         //关闭客户端失败，参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_CLOSE_NOTFOUND 0x121A0051         //关闭客户端失败，没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_SENDMSG_LEN 0x121A0060            //发送失败，提供的缓冲区大小不够
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETRANDOM_PARAMENT 0x121A0070     //参数错误，获取失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETRANDOM_EMPTY 0x121A0071        //没有任何可用队列
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETLIST_PARAMENT 0x121A0080       //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETLIST_EMPTY 0x121A0081          //为空
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_CREATE_PARAMENT 0x121A0090        //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_CREATE_MALLOC 0x121A0091          //申请内存失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_CREATE_NOTPOOL 0x121A0092         //没有找到可用分布池
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETPOOL_PARAMENT 0x121A00A0       //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETPOOL_NOTENABLE 0x121A00A1      //没有启用
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_ETPOOL_NOTFOUND 0x121A00A2        //没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_WAITEVENT_NOTFOUND 0x121A00B0     //没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_WAITEVENT_NOPACKET 0x121A00B1     //没有数据包了
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_ACTIVEEVENT_NOTFOUND 0x121A00C0   //没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_SETRVMODE_PARAMENT 0x121A00D0     //参数错误,无法设置模式
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_SETRVMODE_NOTFOUND 0x121A00D1     //没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_SETRVMODE_NOTSUPPORT 0x121A00D2   //不支持的设置模式
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETRVMODE_PARAMENT 0x121A00E1     //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_GETRVMODE_NOTFOUND 0x121A00E2     //没有找到
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_EX_MALLOC 0x121A0100              //申请内存失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER_EX_NOTFOUND 0x121A0101            //没有找到
//////////////////////////////////////////////////////////////////////////HTTP2
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_CREATE_PARAMENT 0x121A3001       //参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_CREATE_NOTPOOL 0x121A3002        //没有找到任务池
#define ERROR_RFCCOMPONENTS_HTTP_SERVER2_CREATE_MALLOC 0x121A3003         //申请内存失败
#define ERROR_RFCCOMPONENTS_HTTP_SERVER2_INSERT_PARAMENT 0x121A3010       //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_SERVER2_INSERT_NOTFOUND 0x121A3011       //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETPOOL_PARAMENT 0x121A3020      //参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETPOOL_NOTFOUND 0x121A3021      //没有找到 
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETSTREAM_PARAMENT 0x121A3030    //参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETSTREAM_NOTFOUND 0x121A3031    //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETCLIENT_PARAMENT 0x121A3040    //参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETCLIENT_NOTFOUND 0x121A3041    //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETCLIENT_NOTSTREAM 0x121A3042   //没有流ID
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETCLIENT_NOTCOMPLATE 0x121A3043 //包还没有组好
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_GETCLIENT_EMPTY 0x121A3044       //包为空
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_WAITEVENT_NOTFOUND 0x121A3050    //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_WAITEVENT_NOPACKET 0x121A3051    //没有包
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_ACTIVEEVENT_NOTFOUND 0x121A3060  //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PKT_PARAMENT 0x121A3070          //参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PKT_FAILED 0x121A3071            //打包失败,内部错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PKT_MALLOC 0x121A3072            //申请内存失败
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PUSH_MALLOC 0x121A3080           //申请内存失败
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PUSH_NOTSUPPORT 0x121A3081       //不支持的包类型
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_INFO_PARAMENT 0x121A3090         //参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_INFO_NOTFOUND 0x121A3091         //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_INFO_ISNULL 0x121A3092           //为NULL
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_PARAMENT 0x121A30A0        //解析失败,参数错误
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_NOTFOUND 0x121A30A1        //没有找到
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_NOTSTREAM 0x121A30A2       //没有流
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_NOTMETHOD 0x121A30A3       //没有方法
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_NOTURL 0x121A30A4          //没有URL
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_NOTVER 0x121A30A5          //没有版本
#define ERROR_RFCCOMPONENTS_HTTP2_SERVER_PARSE_HTTP2 0x121A30A6           //HTTP2协议,无需升级
//////////////////////////////////////////////////////////////////////////
//                        导出的HTTP帮助处理函数错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETFILED_PARAMENT 0x121A1000        //获取字段内容失败，参数错误
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETFILED_NOTFOUND 0x121A1001        //没有找到指定的字段
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETURLAPI_PARAMENT 0x121A1010       //获取失败，参数错误
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETURLAPI_NOTTYPE 0x121A1011        //没有找到API类型
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETURLAPI_NOTNAME 0x121A1012        //没有找到API名称
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETURLAPI_NOTVER 0x121A1013         //没有找到API版本
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETAUTH_PARAMENT 0x121A1020         //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETAUTH_BUFFER 0x121A1021           //缓冲区错误,不是标准的密码区
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETAUTH_NOTSUPPORT 0x121A1022       //不支持的验证类型
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETPARAM_PARAMENT 0x121A1030        //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_HELP_GETPARAM_NOTFOUND 0x121A1031        //没有找到参数
//////////////////////////////////////////////////////////////////////////
//                        导出的HTTP配置文件管理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_HTTP_CONFIG_INIT_PARAMENT 0x121A2000          //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_CONFIG_INIT_OPENFILE 0x121A2001          //打开文件失败
#define ERROR_RFCCOMPONENTS_HTTP_CONFIG_INIT_NODATA 0x121A2002            //没有内容
#define ERROR_RFCCOMPONENTS_HTTP_CONFIG_GET_PARAMENT 0x121A2010           //参数错误
#define ERROR_RFCCOMPONENTS_HTTP_CONFIG_GET_NOTFOUND 0x121A2011           //没有找到
//////////////////////////////////////////////////////////////////////////
//                        导出的插件工具错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_REGPROCESS_PARAMENT 0x121A3001      //注册处理程序失败，参数错误
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_REGPROCESS_EXIST 0x121A3002         //注册处理程序失败，这个处理程序名称已经存在
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_CANCPROCESS_PARAMENT 0x121A3010     //注销处理程序失败，参数错误
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_HDPROCESS_PARAMENT 0x121A3020       //参数错误，处理失败
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_HDPROCESS_NOTEXIST 0x121A3021       //不存在的处理程序
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_HDPROCESS_EXEC 0x121A3023           //执行失败，可能不是一个标准的注册程序
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_HDPROCESS_HTTPCODE 0x121A3023       //获取HTTP状态码失败
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_INITMODULE_OPENDL 0x121A3030
#define ERROR_RFCCOMPONENTS_HTTP_EXEC_INITMODULE_FUNCTION 0x121A3031