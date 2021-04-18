#pragma once
/********************************************************************
//	Created:	2018/10/8   15:18
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPlayer\AVPlayer_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPlayer
//	File Base:	AVPlayer_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音视频播放器导出错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        视频播放导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_CREATE_PARAMENT 0x40E0001  //参数错误
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_CREATE_MALLOC 0x40E0002    //申请内存失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_CREATE_WINDOW 0x40E0003    //创建窗口失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_CREATE_RENDER 0x40E0004    //创建画面渲染器失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_CREATE_TEXTURE 0x40E0005   //创建纹理失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_CREATE_THREAD 0x40E0006    //创建线程失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_PUSH_NOTFOUND 0x40E0011    //没有找到
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_PUSH_UPDATA 0x40E0012      //更新数据失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_PUSH_CLEAR 0x40E0013       //清理失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_PUSH_COPY 0x40E0014        //拷贝到显示缓冲区失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_PUSH_MALLOC 0x40E0015      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_VIDEO_PLAYTIME_NOTFOUND 0x40E0020//没有找到指定句柄
//////////////////////////////////////////////////////////////////////////
//                        音频播放导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_CREATE_PARAMENT 0x40E1000  //参数错误，创建失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_CREATE_MALLOC 0x40E1001    //申请内存失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_CREATE_FMTNOTSUPPORT 0x40E1002 //不支持的采样格式
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_CREATE_OPENAUDIO 0x40E1003 //打开音频设备失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_CREATE_THREAD 0x40E1004    //创建线程失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_PUSH_NOTFOUND 0x40E1020    //没有找到指定句柄
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_PUSH_MALLOC 0x40E1021      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_PAUSE_NOTFOUND 0x40E1030   //没有找到
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_GETSIZE_PARAMENT 0x40E1040 //参数错误
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_GETSIZE_NOTFOUND 0x40E1041 //没有找到
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_CLEAR_NOTFOUND 0x40E1050   //没有找到句柄
#define ERROR_XENGINE_AVCODEC_AVPLAYER_AUDIO_PLAYTIME_NOTFOUND 0x40E1060//没有找到句柄
