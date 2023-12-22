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
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_PARAMENT 0x80A0000     //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_FINDCODER 0x80A0001    //查找编码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOCCODEC 0x80A0002  //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_OPEN 0x80A0003         //打开编码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOCFRAME 0x80A0004  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOCPACKET 0x80A0005 //申请包内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOEBUFFER 0x80A0006 //已经初始化过了
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_PARAMENT 0x80A0010    //参数错误,编码失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_NOTFOUND 0x80A0011    //没有找到句柄,无法继续
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_NOTREAD 0x80A0012     //编码器没有准备好
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_AUDIO 0x80A0013       //编码失败,这个包无法编码
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_NOFINISH 0x80A0014    //编码失败,无法处理的包
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_RESAMPLE 0x80A0015    //重采样失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_MALLOC 0x80A0016      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_PARAMENT 0x80A0020     //参数错误,解码器初始化失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_FINDCODER 0x80A0021    //查找指定解码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_MALLOCCODEC 0x80A0023  //申请解码器内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_OPEN 0x80A0024         //打开解码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_MALLOCFRAME 0x80A0025  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_MALLOCPACKET 0x80A0026 //申请包内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_NOTSUPPORT 0x80A0027   //不支持的类型
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_PARAMENT 0x80A0030    //参数错误,解码失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_NOTFOUND 0x80A0031    //没有找到指定句柄
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_PARSE 0x80A0032       //解析音频包失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_MALLOC 0x80A0033      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_RESAMPLE 0x80A0034    //重采样失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_PARAMENT 0x80A0050   //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_NOTFOUND 0x80A0051   //没有找到句柄
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_ALLOC 0x80A0052      //初始化内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_INIT 0x80A0053       //初始化参数失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_MALLOC 0x80A0054     //申请内存失败
/************************************************************************/
/*               音频帮助错误                                       */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_GETLIST_PARAMENT 0x80A1000      //参数错误
