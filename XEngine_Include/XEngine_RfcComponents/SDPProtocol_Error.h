﻿#pragma once
/********************************************************************
//	Created:	2019/12/23   15:41
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SDPProtocol\SDPProtocol_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SDPProtocol
//	File Base:	SDPProtocol_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	SDP错误信息导出
//	History:
*********************************************************************/
/************************************************************************/
/*                     SDP打包器导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SDP_PACKET_CREATE_PARAMENT 0x121B0000         //创建失败,参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_GETPACKET_PARAMENT 0x121B0010      //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_GETPACKET_NOTFOUND 0x121B0011      //没有找到指定SDP会话
#define ERROR_RFCCOMPONENTS_SDP_PACKET_GETPACKET_MUSTBE 0x121B0012        //必备条件为满足
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OWNER_PARAMENT 0x121B0020          //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OWNER_NOTFOUND 0x121B0021          //没有找到句柄
#define ERROR_RFCCOMPONENTS_SDP_PACKET_SESSION_PARAMENT 0x121B0030        //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_SESSION_NOTFOUND 0x121B0031        //客户端句柄没有找到
#define ERROR_RFCCOMPONENTS_SDP_PACKET_KEEPTIME_NOTFOUND 0x121B0040       //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PACKET_ADDMEDIA_PARAMENT 0x121B0050       //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_ADDMEDIA_NOTFOUND 0x121B0051       //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PACKET_ATTRAUDIO_PARAMENT 0x121B0060      //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_ATTRAUDIO_NOTFOUND 0x121B0061      //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PACKET_ATTRVIDEO_PARAMENT 0x121B0070      //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PACKET_ATTRVIDEO_NOTFOUND 0x121B0071      //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTNAME_PARAMENT 0x121B0080
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTNAME_NOTFOUND 0x121B0081
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTCONTACT_PARAMENT 0x121B0090
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTCONTACT_NOTFOUND 0x121B0091
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTBAND_NOTFOUND 0x121B00A0
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTRANGE_NOTFOUND 0x121B00B0
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTADDATTR_PARAMENT 0x121B00C0
#define ERROR_RFCCOMPONENTS_SDP_PACKET_OPTADDATTR_NOTFOUND 0x121B00C1
/************************************************************************/
/*                     SDP解析器导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CREATE_PARAMENT 0x121B1001          //创建失败,参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_VERSION_PARAMENT 0x121B1010         //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_VERSION_NOTFOUND 0x121B1011         //没有找到客户端
#define ERROR_RFCCOMPONENTS_SDP_PARSE_VERSION_FAILED 0x121B1012           //没有找到版本号
#define ERROR_RFCCOMPONENTS_SDP_PARSE_OWNER_PARAMENT 0x121B1020           //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_OWNER_NOTFOUND 0x121B1021           //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_OWNER_PROTO 0x121B1022              //协议错误,不完整
#define ERROR_RFCCOMPONENTS_SDP_PARSE_OWNER_FAILED 0x121B1023             //没有找到OWNER协议
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONNECT_PARAMENT 0x121B1030         //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONNECT_NOTFOUND 0x121B1031         //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONNECT_PROTO 0x121B1032            //协议错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONNECT_FAILED 0x121B1033           //没有找到此协议字段
#define ERROR_RFCCOMPONENTS_SDP_PARSE_SESSION_PARAMENT 0x121B1040         //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_SESSION_NOTFOUND 0x121B1041         //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_SESSION_FAILED 0x121B1042           //协议字段不存在
#define ERROR_RFCCOMPONENTS_SDP_PARSE_TIME_PARAMENT 0x121B1050            //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_TIME_NOTFOUND 0x121B1051            //没有找到客户端
#define ERROR_RFCCOMPONENTS_SDP_PARSE_TIME_PROTO 0x121B1052               //协议字段不存在
#define ERROR_RFCCOMPONENTS_SDP_PARSE_TIME_FAILED 0x121B1053              //协议字段不存在
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETVIDEO_PARAMENT 0x121B1060        //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETVIDEO_NOTFOUND 0x121B1061        //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETVIDEO_PROTO 0x121B1062           //协议错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETVIDEO_FAILED 0x121B1063          //此协议字段不存在
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETAUDIO_PARAMENT 0x121B1070        //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETAUDIO_NOTFOUND 0x121B1071        //没有找到句柄
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETAUDIO_PROTO 0x121B1072           //协议不正确
#define ERROR_RFCCOMPONENTS_SDP_PARSE_GETAUDIO_FAILED 0x121B1073          //协议字段不存在
#define ERROR_RFCCOMPONENTS_SDP_PARSE_MEDIANAME_PARAMENT 0x121B1080       //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_MEDIANAME_NOTFOUND 0x121B1081       //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_MEDIANAME_FAILED 0x121B1082         //没有这个协议字段
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONTACT_PARAMENT 0x121B1090         //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONTACT_NOTFOUND 0x121B1091         //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_CONTACT_FAILED 0x121B1092           //没有这个协议字段
#define ERROR_RFCCOMPONENTS_SDP_PARSE_BANDWIDTH_PARAMENT 0x121B10A0       //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_BANDWIDTH_NOTFOUND 0x121B10A1       //没有找到
#define ERROR_RFCCOMPONENTS_SDP_PARSE_BANDWIDTH_FAILED 0x121B10A2         //协议字段不存在
#define ERROR_RFCCOMPONENTS_SDP_PARSE_ATTR_PARAMENT 0x121B10B0            //参数错误
#define ERROR_RFCCOMPONENTS_SDP_PARSE_ATTR_NOTFOUND 0x121B10B1            //没有找到句柄
#define ERROR_RFCCOMPONENTS_SDP_PARSE_ATTR_FAILED 0x121B10B2              //没有找到属性字段
