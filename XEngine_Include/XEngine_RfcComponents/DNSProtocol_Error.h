#pragma once
/********************************************************************
//    Created:     2025/07/04  17:11:07
//    File Name:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_DNSProtocol\DNSProtocol_Error.h
//    File Path:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_DNSProtocol
//    File Base:   DNSProtocol_Error
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     DNS导出错误
//    History:
*********************************************************************/
/************************************************************************/
/*                     DNS协议打包错误                                  */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_DNS_PROTOCOL_PACKET_PARAMENT 0x71C0000        //参数错误
/************************************************************************/
/*                     DNS协议解析错误                                  */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_DNS_PROTOCOL_PARSE_PARAMENT 0x71C1000         //参数错误
#define ERROR_RFCCOMPONENTS_DNS_PROTOCOL_PARSE_SERVICE 0x71C1001          //服务错误
/************************************************************************/
/*                     DNS协议帮助错误                                  */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_DNS_PROTOCOL_HELP_PARAMENT 0x71C2000          //参数错误
#define ERROR_RFCCOMPONENTS_DNS_PROTOCOL_HELP_NOTIP 0x71C2001             //不是IP地址