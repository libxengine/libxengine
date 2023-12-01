#pragma once
/********************************************************************
//    Created:     2023/11/15  10:24:29
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_SDPProtocol\SDPProtocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_SDPProtocol
//    File Base:   SDPProtocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     SDP错误信息导出
//    History:
*********************************************************************/
/************************************************************************/
/*                     SDP打包器导出错误                                */
/************************************************************************/
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PACKET_PARAMENT 0x70E0000           //创建失败,参数错误
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PACKET_NOTFOUND 0x70E0001           //没有找到指定SDP会话
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PACKET_MUSTBE 0x70E0002             //必备条件为满足
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PACKET_MALLOC 0x70E0003             //申请内存失败
/************************************************************************/
/*                     SDP解析器导出错误                                */
/************************************************************************/
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PARSE_PARAMENT 0x70E1001            //创建失败,参数错误
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PARSE_MALLOC 0x70E1002              //申请内存失败
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PARSE_NOTFOUND 0x70E1003            //没有找到客户端
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PARSE_FAILED 0x70E1004              //处理失败
#define ERROR_STREAMMEDIA_SDPPROTOCOL_PARSE_PROTO 0x70E1022               //协议错误,不完整
