#pragma once
/********************************************************************
//	Created:	2020/07/10   10:47
//	Filename: 	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XStream\XStream_Error.h
//	File Path:	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XStream
//	File Base:	XStream_Error
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	X流媒体协议导出错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       XPUSH流推送服务导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_INIT_PARAMENT 0x140F0000    //初始化失败,参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_INIT_MALLOC 0x140F0001      //申请内存失败
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_INIT_THREAD 0x140F0002      //初始化线程失败
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_HDR_NOTFOUND 0x140F0010     //没有找到句柄
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_HDR_ERROR 0x140F0011        //失败,不是标准的协议
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_HDR_NOTOK 0x140F0012        //服务器返回了一个错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_PKG_PARAMENT 0x140F0020     //参数错误,投递包失败
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_PKG_NOTFOUND 0x140F0021     //投递失败,没有找到句柄
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_PKG_PAUSE 0x140F0022        //对方请求暂停推送,无法投递数据
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_GETSPEED_PARAMENT 0x140F0030//参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_GETSPEED_NOTFOUND 0x140F0031//没有找到客户端
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_STATUS_PARAMENT 0x140F0040  //参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPUSH_STATUS_NOTFOUND 0x140F0041  //没有找到
//////////////////////////////////////////////////////////////////////////
//                       XPULL拉流导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_INIT_PARAMENT 0x140F1001    //参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_INIT_MALLOC 0x140F1002      //申请内存失败
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_HDR_NOTFOUND 0x140F1011     //没有找到
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_HDR_ERROR 0x140F1020        //协议错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_HDR_NOCOMPLETE 0x140F1021   //没有完成,流ID不存在
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_STATUS_PARAMENT 0x140F1030  //参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_STATUS_NOTFOUND 0x140F1031  //没有找到
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_PLAY_NOTFOUND 0x140F1040    //参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_PLAY_NOTINIT 0x140F1041     //没有找到
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_GET_PARAMENT 0x140F1040     //参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_GET_NOTFOUND 0x140F1041     //没有找到
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_GETAV_PARAMENT 0x140F1050   //参数错误
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_GETAV_NOTFOUND 0x140F1051   //没有找到指定句柄
#define ERROR_STREAMMEDIA_XSTREAM_CLIENTPULL_GETAV_NOTINIT 0x140F1052    //没有初始化
