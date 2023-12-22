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
//                            RTCP接受者处理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_PACKET_PARAMENT 0x90B0000         //参数错误
//////////////////////////////////////////////////////////////////////////
//                            RTCP发送者处理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_PARSE_PARAMENT 0x90B1000          //参数错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_PARSE_LEN 0x90B1001               //长度错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_PARSE_NOTRTCP 0x90B1002    //不是RTCP包
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_PARSE_NOTPKT 0x90B1003
