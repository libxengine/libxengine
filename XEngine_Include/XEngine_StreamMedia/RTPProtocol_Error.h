#pragma once
/********************************************************************
//	Created:	2019/8/27   17:23
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtpProtocol\RTPProtocol_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtpProtocol
//	File Base:	RTPProtocol_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	RTP协议模块导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                            RTP打包处理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_PARAMENT 0x90C0001          //已经存在的源标识符
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_MALLOC 0x90C0002            //申请内存失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_NOTFOUND 0x90C0003          //没有找到指定句柄
//////////////////////////////////////////////////////////////////////////
//                            RTP解析器导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_PARAMENT 0x90C1001           //参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_MALLOC 0x90C1002             //申请内存失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_NOTFOUND 0x90C1003           //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_EMPTY 0x90C1004              //队列为空,没有解析好的RTP数据包
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_NOTPACKET 0x90C1005          //没有找到可用包,可能分片包还没接受完成
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_LEN 0x90C1006                //提供的缓冲区不够
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_NOTSUPPORT 0x90C1007         //不支持的类型解
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_FLAGS 0x90C1008              //压入数据报错误,标志错误,不是RTP包