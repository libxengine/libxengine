#pragma once
/********************************************************************
//	Created:	2018/9/15   10:53
//	Filename: 	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVCollect\AVCollect_Error.h
//	File Path:	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVCollect
//	File Base:	AVCollect_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	采集器导出错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        视频采集错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_PARAMENT 0x80B0001          //参数错误,初始化失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_MALLOCAVFMT 0x80B0002       //申请音视频内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_OPENDEVICE 0x80B0003        //打开设备失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_FINDSTREAM 0x80B0004        //查找AV流失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_NOTFOUNDVEDIO 0x80B0005     //查找视频流失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_MALLOCCODEC 0x80B0006       //申请编解码器内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_FINDCODEC 0x80B0007         //查找编解码器失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_OPENCODEC 0x80B0008         //打开编解码器失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_MALLOCFRAME 0x80B0009       //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_MALLOC 0x80B0010            //初始化失败,申请内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_CREATETHREAD 0x80B0011      //创建线程失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_NOTFOUND 0x80B0012          //没有找到句柄
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_ISCALL 0x80B0013            //设置为回调,无法继续
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_EAGAIN 0x80B0014            //没准备好,请继续重试
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_READ 0x80B0015              //读取数据失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_DATA 0x80B0016              //数据错误,不是视频编码
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_VIDEO_MORE 0x80B0017              //需要更多数据
//////////////////////////////////////////////////////////////////////////
//                        声音录制错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_PARAMENT 0x80B2001          //参数错误,初始化失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_MALLOC 0x80B2002            //申请内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_MALLOCAVFMT 0x80B2003       //申请音视频内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_OPENDEVICE 0x80B2004        //打开设备失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_FINDSTREAM 0x80B2005        //查找AV流失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_NOTFOUNDVEDIO 0x80B2006     //查找视频流失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_MALLOCCODEC 0x80B2007       //申请编解码器内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_FINDCODEC 0x80B2008         //查找编解码器失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_OPENCODEC 0x80B2009         //打开编解码器失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_MALLOCFRAME 0x80B2010       //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_MALLOPACKET 0x80B2011       //申请包内存失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_CREATETHREAD 0x80B2012      //创建线程失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_NOTFOUND 0x80B2013          //没有找到句柄
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_EAGAIN 0x80B2014            //数据没有准备好,重试
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_READ 0x80B2015              //读取数据失败
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_DATA 0x80B2016              //数据错误,可能不是音频数据
#define ERROR_XENGINE_AVCODEC_AVCOLLECT_AUDIO_MORE 0x80B2017              //需要更多数据