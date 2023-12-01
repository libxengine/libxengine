#pragma once
/********************************************************************
//	Created:	2019/8/21   15:53
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtspProtocol\RTSPProtocol_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtspProtocol
//	File Base:	RTSPProtocol_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	RTSP协议处理模块导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
///                           RTSP服务核心相关错误码
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                            RTSP协议包管理错误导出                    */
/************************************************************************/
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_PARAMENT 0x90D0000          //创建失败,参数错误
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_NOTFOUND 0x90D0001          //没有找到指定客户端
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_PROTOCOL 0x90D0002          //协议错误
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_NOURL 0x90D0003             //没有URL信息
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_NOSEQ 0x90D0004             //没有SEQ序列号
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_NOTSUPPORT 0x90D0005        //不支持的方法
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_BUFFER 0x90D0006            //验证缓冲区解析失败
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_USER 0x90D0007              //解析用户密码失败
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_GETMETHOD 0x90D0008         //获取方法失败
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_GETVERSION 0x90D0009        //获取版本失败
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_NOTRTSP 0x90D0010           //不是RTSP协议
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_GETCODE 0x90D0011           //获取状态码失败
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PARSE_GETMSG 0x90D0012            //获取状态消息失败
/************************************************************************/
/*                            RTSP协议包打包函数导出错误                */
/************************************************************************/
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PACKET_PARAMENT 0x90D1000         //选项打包函数失败,参数错误
#define ERROR_STREAMMEDIA_RTSPPROTOCOL_PACKET_NOTSUPPORT 0x90D1001       //不支持的值