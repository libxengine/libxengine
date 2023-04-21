#pragma once
/********************************************************************
//    Created:     2022/11/02  11:26:59
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_MQTTProtocol\MQTTProtocol_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_MQTTProtocol
//    File Base:   MQTTProtocol_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     导出错误
//    History:
*********************************************************************/
/************************************************************************/
/*                     MQTT协议解析导出错误                             */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_MQTT_PROTOCOL_PACKET_PARAMENT 0x70B0000      //参数错误
/************************************************************************/
/*                     MQTT协议打包导出错误                             */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_MQTT_PROTOCOL_PARSE_PARAMENT 0x70B1000       //参数错误
#define ERROR_RFCCOMPONENTS_MQTT_PROTOCOL_PARSE_NOTSUPPORT 0x70B1001     //协议不支持
#define ERROR_RFCCOMPONENTS_MQTT_PROTOCOL_PARSE_FLAG 0x70B1002           //标志位不正确
#define ERROR_RFCCOMPONENTS_MQTT_PROTOCOL_PARSE_HDRSIZE 0x70B1003        //头大小不正确
#define ERROR_RFCCOMPONENTS_MQTT_PROTOCOL_PARSE_LENSIZE 0x70B1004        //长度大小字段不够