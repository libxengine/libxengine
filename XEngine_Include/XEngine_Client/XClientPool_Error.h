#pragma once
/********************************************************************
//	Created:	2020/11/06  17:18:38
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Client\NetClient_Pool\ClientPool_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Client\NetClient_Pool
//	File Base:	ClientPool_Error
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	连接池错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    连接池错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGIEN_CLIENT_POOL_CONNECTPOOL_OPEN_PARAMENT 0x50C0001     //设置套接字失败,参数错误
#define ERROR_XENGIEN_CLIENT_POOL_CONNECTPOOL_OPEN_MALLOC 0x50C0002       //申请内存失败
#define ERROR_XENGIEN_CLIENT_POOL_CONNECTPOOL_OPEN_CONNECT 0x50C0003      //连接服务失败
#define ERROR_XENGIEN_CLIENT_POOL_CONNECTPOOL_SEND_PARAMENT 0x50C0010     //参数错误
#define ERROR_XENGIEN_CLIENT_POOL_CONNECTPOOL_SEND_NOTFOUND 0x50C0011     //没有找到
#define ERROR_XENGIEN_CLIENT_POOL_CONNECTPOOL_SEND_FAILED 0x50C0012       //发送失败,内部错误
