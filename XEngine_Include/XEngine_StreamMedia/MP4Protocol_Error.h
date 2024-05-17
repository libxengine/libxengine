#pragma once
/********************************************************************
//    Created:     2024/03/27  16:42:17
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_MP4Protocol\MP4Protocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_MP4Protocol
//    File Base:   MP4Protocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     MP4协议错误导出
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       MP4解析器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PARSE_PARAMENT 0x91B0001           //申请内存失败
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PARSE_MALLOC 0x91B0002             //内存申请失败
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PARSE_NOTFOUND 0x91B0003           //没有找到
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PARSE_EMPTY 0x91B0004              //队列为空
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PARSE_NOTCOMPLETE 0x91B0005        //未完整组包的数据
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PARSE_COMPLETE 0x91B0006           //数据解析已经完毕,不需要继续解析
//////////////////////////////////////////////////////////////////////////
//                       MP4组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PACKET_PARAMENT 0x91B1001          //申请内存失败
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PACKET_MALLOC 0x91B1002            //内存申请失败
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PACKET_NOTFOUND 0x91B1003          //没有找到
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PACKET_NOTSUPPORT 0x91B1004        //不支持
#define ERROR_STREAMMEDIA_MP4PROTOCOL_PACKET_EMPTY 0x91B1005             //列表为空