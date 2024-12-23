﻿#pragma once
/********************************************************************
//	Created:	    2017/03/15  11:06
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_WSFrame\WSFrame_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_WSFrame
//	File Base:	WSFrame_Error
//	File Ext:	    h
//  Project:     NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:     WEBSOCKET帧协议解析器导出错误
//	History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                      分析器错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CODEC_DEMSG_PARAMENT 0x71C0001          //解码失败，参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CODEC_ENMSG_PARAMENT 0x71C0010          //编码失败，参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CODEC_DEHDR_PARAMENT 0x71C0020          //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CODEC_DEHDR_LEN 0x71C0021               //解码头失败,长度不够
///////////////////////////////////////////////////////////////////////////////
//                      连接器错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CONNECTOR_HANDSHAKE_PARAMENT 0x71C1001  //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CONNECTOR_HANDSHAKE_TYPE 0x71C1002      //解析类型错误，不是WEBSOCKET
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CONNECTOR_CONNECT_PRARMENT 0x71C1010    //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CONNECTOR_VER_PRARMENT 0x71C1020        //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_CONNECTOR_VER_NOTMATCH 0x71C1021        //验证失败,需要断开连接
///////////////////////////////////////////////////////////////////////////////
//                      组包器错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_CREATE_MALLOCROOT 0x71C2001      //申请内存失败
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_CREATE_MALLOCNOTE 0x71C2002
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_CREATE_NOTPOOL 0x71C2003         //没有找到可用池
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_POST_PARAMENT 0x71C2010          //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_POST_MAXCOUNT 0x71C2011          //最大队列
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_POST_NOTFOUND 0x71C2012          //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_POST_MALLOC 0x71C2013            //申请内存失败
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_CLEAR_PARAMENT 0x71C2020         //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_CLEAR_NOTFOUND 0x71C2021         //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_DELETE_PARAMENT 0x71C2030        //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_DELETE_NOTFOUND 0x71C2031        //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_PARAMENT 0x71C2040           //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_IDNONE 0x71C2041             //没有客户端存在
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_NOTFOUND 0x71C2042           //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_BUSY 0x71C2043               //当前队列忙碌
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_ISNULL 0x71C2044             //当前队列为空
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_NOCOMPLETE 0x71C2045         //没有完成
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_ISLEAVEPKT 0x71C2046         //这是一个离开包
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_SMALL 0x71C2047              //提供的缓冲区太小
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_WAITEVENT_NOTFOUND 0x71C2060     //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_WAITEVENT_TIMEOUT 0x71C2061      //等待超时
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_WAITEVENT_NOPACKET 0x71C2062     //没有包
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_PUSH_MALLOCHDR 0x71C2070         //申请内存失败
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_PUSH_MALLOC 0x71C2071            //申请内存失败
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_SETLOGIN_PARAMENT 0x71C2080      //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_SETLOGIN_NOTFOUND 0x71C2081      //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GETLOGIN_PARAMENT 0x71C2090      //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GETLOGIN_NOTFOUND 0x71C2091      //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_ACTIVE_NOTFOUND 0x71C20C0        //激活失败,没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_EX_MALLOC 0x71C20D0              //申请内存失败
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_EX_NOTFOUND 0x71C20D1            //没有找到
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_MODE_PARAMENT 0x71C20E0          //参数错误
#define ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_MODE_NOTFOUND 0x71C20E1          //没有找到