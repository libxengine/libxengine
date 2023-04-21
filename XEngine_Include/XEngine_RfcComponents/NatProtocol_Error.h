#pragma once
/********************************************************************
//	Created:	2019/2/26   9:57
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_NatClient\NatClient_Error.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_NatClient
//	File Base:	NatClient_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	NAT客户端导出错误定义
//	History:
*********************************************************************/
/************************************************************************/
/*                      STUN客户端协议导出错误码                        */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_REQUEST_PARAMENT 0x70C0000    //参数错误
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_RESPONSE_PARAMENT 0x70C0010   //回复处理失败,参数错误
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_RESPONSE_NOTSTUNMSG 0x70C0011 //不是标准的STUN协议
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_RESPONSE_EMPTY 0x70C0012      //属性为空
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_BUILDATTR_PARAMENT 0x70C0020  //参数错误
/************************************************************************/
/*                      TURN转发协议导出错误码                          */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_PARAMENT 0x70C1000            //参数错误
#define ERROR_RFCCOMPONENTS_NATCLIENT_STUN_NOTFOUND 0x70C1001            //没有找到