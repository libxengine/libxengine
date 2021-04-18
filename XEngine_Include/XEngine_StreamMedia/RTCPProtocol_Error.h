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
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_RECVER_PACKET_PARAMENT 0x140E0000  //参数错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_RECVER_PKTGOODBYE_PARAMENT 0x140E0010
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_RECVER_PARSE_PARAMENT 0x140E0020   //参数错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_RECVER_PARSE_LEN 0x140E0021        //传递的数据大小不正确
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_RECVER_PARSE_NOTRTCP 0x140E0022    //传递的数据不是RTCP包
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_RECVER_PARSE_NOTPKT 0x140E0023     //接受者没有报告自己的信息
//////////////////////////////////////////////////////////////////////////
//                            RTCP发送者处理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_SENDER_PACKET_PARAMENT 0x140E1000  //参数错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_SENDER_PARSE_PARAMENT 0x140E1010
//////////////////////////////////////////////////////////////////////////
//                            RTCP帮助处理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_HELPER_NTPTIME_PARAMENT 0x140E2001 //参数错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_HELPER_PKTTYPE_PARAMENT 0x140E2010 //获取包类型失败,参数错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_HELPER_PKTTYPE_LEN 0x140E2011      //获取包类型失败,大小错误
#define ERROR_STREAMMEDIA_RTCPPROTOCOL_HELPER_PKTTYPE_NOTRTCP 0x140E2012  //不是一个标准的RTCP包,或者不支持的类型
