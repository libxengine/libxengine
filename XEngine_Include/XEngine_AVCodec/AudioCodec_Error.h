#pragma once
/********************************************************************
//	Created:	2012/9/8  12:10
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngien_AvCoder\NetEngine_AudioCoder\NetEngine_AudioCoder\AudioCoder_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngien_AvCoder\NetEngine_AudioCoder\NetEngine_AudioCoder
//	File Base:	AudioCoder_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音频解码器 错误导出文件
//	History:
*********************************************************************/
/************************************************************************/
/*                       实时流编解码错误                                     */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_PARAMENT 0x80A0000     //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_FINDCODER 0x80A0001    //查找编码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_MALLOCCODEC 0x80A0002  //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_OPEN 0x80A0003         //打开编码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_MALLOCFRAME 0x80A0004  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_MALLOCPACKET 0x80A0005 //申请包内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_MALLOEBUFFER 0x80A0006 //已经初始化过了
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_NOTFOUND 0x80A0007    //没有找到句柄,无法继续
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_NOTREAD 0x80A0008     //编码器没有准备好
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_AUDIO 0x80A0009       //编码失败,这个包无法编码
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_NOFINISH 0x80A0010    //编码失败,无法处理的包
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE 0x80A0011    //重采样失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_MALLOC 0x80A0012      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_NOTSUPPORT 0x80A0013   //不支持的类型
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_PARSE 0x80A0014       //解析音频包失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ALLOC 0x80A0015      //初始化内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_INIT 0x80A0016       //初始化参数失败
/************************************************************************/
/*               音频帮助错误                                       */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_GETLIST_PARAMENT 0x80A1000      //参数错误
