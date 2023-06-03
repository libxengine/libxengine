#pragma once
/********************************************************************
//    Created:     2023/05/24  13:51:15
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_RTMPProtocol\RTMPProtocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_RTMPProtocol
//    File Base:   RTMPProtocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     RTMP协议错误导出
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       RTMP解析器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_PARSE_PARAMENT 0x90F0001           //申请内存失败
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_PARSE_MALLOC 0x90F0002             //内存申请失败
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_PARSE_NOTFOUND 0x90F0003           //没有找到
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_PARSE_EMPTY 0x90F0004              //队列为空
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_PARSE_NOTCOMPLETE 0x90F0005        //未完整组包的数据
//////////////////////////////////////////////////////////////////////////
//                       RTMP打包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_HELP_PARAMENT 0x90F1000           //参数错误
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_HELP_NOTMATCH 0x90F1001           //不匹配
#define ERROR_STREAMMEDIA_RTMPPROTOCOL_HELP_NOTFOUND 0x90F1002           //没有找到