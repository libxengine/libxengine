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
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_PARAMENT 0x90A1001             //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_MALLOC 0x90A1002               //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_NOTFOUND 0x90A1003             //查找失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_FILE 0x90A1004                 //操作文件失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_NOTSUB 0x90A1005               //没有找到流
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_WRITE 0x90A1006                //写入数据失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_SINGLE 0x90A1007               //单一流文件,请使用解析函数
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_LINE 0x90A1008                 //数据行读取失败,可能不是标准的M3U8
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_FAILED 0x90A1009               //文件不是M3U8标准文件
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDR 0x90A1010                 //获取流媒体地址失败,可能文件损坏
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_TIME 0x90A1011                 //时间戳获取失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_END 0x90A1012                  //M3U8列表结束
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