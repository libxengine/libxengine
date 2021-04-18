#pragma once
/********************************************************************
//	Created:	2013/2/1  18:35
//	File Name: 	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegClient\AuthRegClient_Error.h
//	File Path:	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegClient
//	File Base:	AuthRegClient_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	验证客户端导出错误
//	History:
//  Notic:      自动清理资源的错误你不需要在调用 关闭客户端函数来清理资源
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        网络客户端验证协议导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_AUTHORIZEREG_CLIENT_PROTOCOL_SEND_PARAMENT 0x30B0001        //参数错误，无法继续
#define ERROR_AUTHORIZEREG_CLIENT_PROTOCOL_RECV_PARAMENT 0x30B0010        //参数错误，无法继续
#define ERROR_AUTHORIZEREG_CLIENT_PROTOCOL_RECV_NOTPROTOCOL 0x30B0011     //不是验证协议
#define ERROR_AUTHORIZEREG_CLIENT_PROTOCOL_RECV_NOTSUCCESS 0x30B0012      //服务器返回了一个错误的处理协议
#define ERROR_AUTHORIZEREG_CLIENT_PROTOCOL_RECV_NOTSUPPORT 0x30B0013      //不支持的协议类型
//////////////////////////////////////////////////////////////////////////
//                        客户端管理导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_INIT_PARAMENT 0x30B1001         //参数错误,初始化失败
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_INIT_MALLOC 0x30B1002           //申请内存失败
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_INIT_THREAD 0x30B1003           //创建线程失败
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEINSERT_PARAMENT 0x30B1010   //参数错误,插入时间信息失败
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEINSERT_NOTFOUND 0x30B1011   //没有找到指定客户端
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEINSERT_TIMEOUT 0x30B1012    //插入的时间结构已经没有剩余时间,毫无意义的插入
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEGET_PARAMENT 0x30B1020      //参数错误
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEGET_NOTFOUND 0x30B1021      //没有找到,获取失败
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEGET_NOTAUTH 0x30B1022       //还没有获取到验证的时间信息
#define ERROR_AUTHORIZEREG_CLIENT_MANAGE_TIMEGET_TIMEOUT 0x30B1022       //这个客户端已经超时了,请销毁它!
