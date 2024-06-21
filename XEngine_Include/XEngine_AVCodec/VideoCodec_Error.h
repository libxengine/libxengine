#pragma once
/********************************************************************
//	Created:	2018/8/31   10:18
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_VideoCoder\VideoCoder_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_VideoCoder
//	File Base:	VideoCoder_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	视频编解码器导出错误定义
//	History:
*********************************************************************/
/************************************************************************/
/*                       实时流编解码错误                               */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_PARAMENT 0x80F0000     //初始化失败,参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_FINDCODER 0x80F0001    //查找编码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_MALLOCCODEC 0x80F0002  //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_OPEN 0x80F0003         //打开编码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_MALLOCFRAME 0x80F0004  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_MALLOCPACKET 0x80F0005 //申请PAKCET内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_NOTFOUND 0x80F0006    //没有找到句柄
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_VIDEO 0x80F0007       //编码视频失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_NOFINISH 0x80F0008    //没有完成
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_MALLOC 0x80F0009      //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_HWCONFIG 0x80F0010     //配置失败,可能你的电脑不支持硬件编解码
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_HWCREATE 0x80F0011     //创建硬件编解码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_PARSE 0x80F0012       //解析失败,可能不是一个完整的视频包
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_FAILED 0x80F0013      //解码数据有问题无法继续
/************************************************************************/
/*                       帮助函数错误                                   */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_GETLIST_PARAMENT 0x80F1000     //参数错误,获取失败