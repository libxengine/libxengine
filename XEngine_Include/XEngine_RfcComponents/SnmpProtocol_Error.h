#pragma once
/********************************************************************
//    Created:     2021/09/01  15:01:45
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_SnmpProtocol\SnmpProtocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_SnmpProtocol
//    File Base:   SnmpProtocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     SNMP导出错误码
//    History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                      SNMP帮助类错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_SNMP_HELP_STRTOOID_PARAMENT 0x71A0000             //请求参数错误
#define ERROR_RFCCOMPONENTS_SNMP_HELP_STRTOOID_NOTROOT 0x71A0001              //没有头节点
#define ERROR_RFCCOMPONENTS_SNMP_HELP_STRTOOID_NOTORG 0x71A0002               //没有组织对象
///////////////////////////////////////////////////////////////////////////////
//                      SNMP打包类错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_SNMP_PACKET_PROTOCOL_PARAMENT 0x71A1001           //请求参数错误
///////////////////////////////////////////////////////////////////////////////
//                      SNMP解析类错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_SNMP_PARSE_PROTOCOL_PARAMENT 0x71A2001            //请求参数错误
#define ERROR_RFCCOMPONENTS_SNMP_PARSE_PROTOCOL_FAILED 0x71A2002              //协议不正确