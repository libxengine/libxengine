#pragma once
/********************************************************************
//	Created:	2019/1/29   14:44
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_Snmp\RfcSnmp_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_Snmp
//	File Base:	RfcSnmp_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	SNMP导出错误码
//	History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                      SNMP客户端错误
///////////////////////////////////////////////////////////////////////////////
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_INIT_PARAMENT 0x120E0001               //参数错误
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_INIT_AUTH 0x120E0002                   //验证失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_INIT_OPEN 0x120E0003                   //打开SNMP设备失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUGET_PARAMENT 0x120E0010             //参数错误获取失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUGET_NOTFOUND 0x120E0011             //没有找到指定客户端
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUGET_PARSE 0x120E0012                //解析失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUGET_VAR 0x120E0013                  //设置参数变量失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUGET_REP 0x120E0014                  //获取结果失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUSET_PARAMENT 0x120E0020             //参数错误,设置失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUSET_NOTFOUND 0x120E0021             //没有找到
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUSET_PARSE 0x120E0022                //设置参数失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUSET_VAR 0x120E0023                  //设置值失败
#define ERROR_RFCCOMPONENTS_SNMP_CLIENT_PDUSET_REP 0x120E0024                  //请求失败
