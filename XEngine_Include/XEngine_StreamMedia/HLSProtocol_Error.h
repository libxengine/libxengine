#pragma once
/********************************************************************
//	Created:	2020/08/14  15:52:38
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_HLSProtocol\HLSProtocol_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_HLSProtocol
//	File Base:	HLSProtocol_Error
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	HLS切片打包模块导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       M3U8文件处理导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CREATE_PARAMENT 0x90A1001//参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CREATE_MALLOC 0x90A1002  //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_PARAMENT 0x90A1010 //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_NOTFOUND 0x90A1011 //查找失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_MALLOC 0x90A1012   //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_CREATEFILE 0x90A1013//创建文件失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDFILE_PARAMENT 0x90A1020   //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDFILE_NOTFOUND 0x90A1021   //没有找到句柄
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDFILE_NOTSUB 0x90A1022     //没有找到流
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CLEAR_CREATEFILE 0x90A10A0   //创建文件失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CLEAR_WRITE 0x90A10A1        //写入数据失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_DELETE_NOTROOT 0x90A10B0     //没有主句柄
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_DELETE_NOTSUB 0x90A10B1      //没有子句柄
//////////////////////////////////////////////////////////////////////////
//                       TS文件处理导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_PARAMENT 0x90A0000               //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_MALLOC 0x90A0001                 //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_NOTFOUND 0x90A0002               //没有找到
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_NOTMATCH 0x90A0003               //协议不匹配
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_ISEMPTY 0x90A0004                //空的队列
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_NOTCOMPLETE 0x90A0005            //没有组包完成
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_PATID 0x90A0006                  //PATID不正确
#define ERROR_STREAMMEDIA_HLSPROTOCOL_TS_PMTID 0x90A0007                  //PMTID不正确