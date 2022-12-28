#pragma once
/********************************************************************
//    Created:     2022/12/13  13:15:09
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_SSDPProtocol\SSDPProtocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_SSDPProtocol
//    File Base:   SSDPProtocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     SSDP协议导出错误
//    History:
*********************************************************************/
/************************************************************************/
/*                     SSDP协议解析导出错误                             */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PARSE_PARAMENT 0x120F0001       //参数错误
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PARSE_NOTMETHOD 0x120F0002      //没有方法
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PARSE_NOTURL 0x120F0003         //没有URI
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PARSE_NOTVER 0x120F0004         //没有版本
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PARSE_NOHTTPHDR 0x120F0005      //没有HTTP协议字段
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PARSE_NOTFOUND 0x120F0006       //没有找到
/************************************************************************/
/*                     SSDP协议打包导出错误                             */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_PACKET_NOTFOUND 0x120F0010      //参数错误
/************************************************************************/
/*                     SSDP协议帮助导出错误                             */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SSDP_PROTOCOL_HELP_PARAMENT 0x120F0020       //参数错误