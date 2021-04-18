#pragma once
/********************************************************************
//	Created:	2020/5/10   18:31
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_XRpc\XRPC_Error.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_XRpc
//	File Base:	XRPC_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:  	qyt
//	Purpose:	导出的错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的协议错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_REQFUNC_PARAMENT 0xA0D0001  //参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PKTFUNC_MALLOC 0xA0D0010    //申请内存失败
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PKTFUNC_NOTSUPPORT 0xA0D0011//不支持的参数类型
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PKTFUNC_SIZE 0xA0D0012      //提供的大小不合适
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PARSEFUNC_PARAMENT 0xA0D0100//参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PARSEFUNC_JSON 0xA0D0101    //JSON解析失败
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PARSEFUNC_MALLOC 0xA0D0102  //申请内存失败
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PARSEFUNC_NOTSUPPPORT 0xA0D0103 //不支持的类型
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_REPFUNC_PARAMENT 0xA0D0110  //参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_REPFUNC_MALLOC 0xA0D0111    //申请内存失败
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_REPFUNC_SIZE 0xA0D0112      //大小错误不合适
#define ERROR_NETENGINE_NETHELP_XRPC_PROTOCOL_PACKET_PARAMENT 0xA0D0120   //打包失败,参数错误
//////////////////////////////////////////////////////////////////////////
//                        导出的客户端错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_CONNECT_PARAMENT 0xA0D1001    //连接失败,参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_CONNECT_MALLOC 0xA0D1002      //申请内存失败
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_CONNECT_THREAD 0xA0D1003      //创建线程失败
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_FUNCCALL_PARAMENT 0xA0D1010   //请求函数调用失败,参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_FUNCCALL_NOTFOUND 0xA0D1011   //没有找到这个句柄
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_FUNCCALL_MALLOC 0xA0D1012     //申请内存失败
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_FUNCCALL_RECV 0xA0D1013       //接受数据失败,服务器返回数据错误
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_HANDLE_PARAMENT 0xA0D1020     //处理协议失败,参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_HANDLE_PROTOCOL 0xA0D1021     //协议错误,不是标准的协议
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_HANDLE_NOTXRPC 0xA0D1022      //不是XRPC协议,无法处理
#define ERROR_NETENGINE_NETHELP_XRPC_CLIENT_HANDLE_FUNCNAME 0xA0D1023     //函数名称错误,无法继续
//////////////////////////////////////////////////////////////////////////
//                        导出的服务端错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_XRPC_CORE_INIT_THREADSTREAM 0xA0D2001     //初始化失败,创建流线程失败
#define ERROR_NETENGINE_NETHELP_XRPC_CORE_INIT_THREADHTTP 0xA0D2002       //创建HTTP处理线程失败
#define ERROR_NETENGINE_NETHELP_XRPC_CORE_SETCB_PARAMENT 0xA0D2010        //参数错误,设置失败
#define ERROR_NETENGINE_NETHELP_XRPC_CORE_SEND_PARAMENT 0xA0D2020         //参数错误,发送失败
//////////////////////////////////////////////////////////////////////////
//                        导出的帮助错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETENGINE_NETHELP_XRPC_HELP_MALLOC_PARAMENT 0xA0D3001       //参数错误
#define ERROR_NETENGINE_NETHELP_XRPC_HELP_MALLOC_FAILED 0xA0D3002         //申请内存失败
#define ERROR_NETENGINE_NETHELP_XRPC_HELP_FREE_PARAMENT 0xA0D3010         //释放失败,参数错误
