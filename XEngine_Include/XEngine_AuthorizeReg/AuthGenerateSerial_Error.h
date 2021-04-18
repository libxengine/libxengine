#pragma once
/********************************************************************
//	Created:	2013/1/30  16:22
//	File Name: 	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthGenerateSerial\AuthGenerateSerial_Error.h
//	File Path:	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthGenerateSerial
//	File Base:	AuthGenerateSerial_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	生成充值卡错误导出表
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    时间生成卡导出错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_START_PARAMEN 0x30A0001      //参数不合适
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_START_NOTSUPPORT 0x30A0002   //不支持此生成类型
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GET_PARAMENT 0x30A0010       //参数错误
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GET_NONE 0x30A0011           //序列号已经获取完毕，容器里面没有序列号了
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GET_NULL 0x30A0012           //获取到表中有空的项目，已经移除
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GETTYPE_PARAMENT 0x30A0020   //参数错误
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GETTYPE_BUFFER 0x30A0021     //这个缓冲区有问题，获取卡类型失败
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GETTYPE_CUSTOM 0x30A0022     //获取自定义时间序列号的过期时间失败。
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GETTYPE_UNKNOW 0x30A0023     //获取类型失败，这个类型未知
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_GETCOUNT_PARAMENT 0x30A0030  //获取失败,参数错误
//////////////////////////////////////////////////////////////////////////
//                    扩展错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_EXT_MALLOC 0x30A1000         //申请内存失败
#define ERROR_AUTHORIZEREG_SERIAL_GENERATE_EX_NOTFOUND 0x30A1001        //没有找到
