#pragma once
/********************************************************************
//    Created:     2023/05/16  11:02:49
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_FLVProtocol\FLVProtocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_FLVProtocol
//    File Base:   FLVProtocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     FLV协议错误导出
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       FLV解析器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PARSE_PARAMENT 0x91A0001            //申请内存失败
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PARSE_MALLOC 0x90B0002              //内存申请失败
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PARSE_NOTFOUND 0x90B0003            //没有找到
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PARSE_EMPTY 0x90B0004               //队列为空
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PARSE_NOTCOMPLETE 0x90B0005         //未完整组包的数据
//////////////////////////////////////////////////////////////////////////
//                       FLV打包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PACKET_PARAMENT 0x90B1000           //参数错误
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PACKET_MALLOC 0x90B1001             //申请内存失败
#define ERROR_STREAMMEDIA_FLVPROTOCOL_PACKET_NOTFOUND 0x90B1002           //没有找到