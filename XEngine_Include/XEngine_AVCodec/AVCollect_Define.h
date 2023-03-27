﻿#pragma once
/********************************************************************
//	Created:	2018/9/15   10:53
//	Filename: 	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVCollect\AVCollect_Define.h
//	File Path:	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVCollect
//	File Base:	AVCollect_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	采集器导出定义
//	History:
*********************************************************************/
typedef enum
{
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_NONE = -1,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_U8,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S16,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S32,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_FLT,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_DBL,

    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_U8P,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S16P,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S32P,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_FLTP,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_DBLP,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S64,
    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S64P,

    ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_NB
}ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT;
typedef enum
{
    ENUM_AVCOLLECT_VIDEO_FMT_NONE = -1,
    ENUM_AVCOLLECT_VIDEO_FMT_YUV420P,
    ENUM_AVCOLLECT_VIDEO_FMT_YUYV422,
    ENUM_AVCOLLECT_VIDEO_FMT_RGB24,
    ENUM_AVCOLLECT_VIDEO_FMT_BGR24,
    ENUM_AVCOLLECT_VIDEO_FMT_YUV422P,
    ENUM_AVCOLLECT_VIDEO_FMT_YUV444P,
    ENUM_AVCOLLECT_VIDEO_FMT_YUV410P,
    ENUM_AVCOLLECT_VIDEO_FMT_YUV411P,
    ENUM_AVCOLLECT_VIDEO_FMT_BGR0 = 121
}ENUM_AVCOLLECT_VIDEOSAMPLEFORMAT;
//////////////////////////////////////////////////////////////////////////
//                     导出的回调函数
//////////////////////////////////////////////////////////////////////////
typedef struct  
{
    CHAR tszVideoDev[64];                                                 //视频设备,可以为屏幕和摄像头等,Linux:/dev/video0 Macos:0:1 Windows:video=screen-capture-recorder
    CHAR tszVideoSize[10];                                                //采集的分辨率1920x1080,部分采集设备不支持调整分辨率
    int nPosX;                                                            //采集的坐标
    int nPosY;                                                            //采集的坐标
    int nFrameRate;                                                       //帧率
}AVCOLLECT_SCREENINFO;
//////////////////////////////////////////////////////////////////////////
//                     导出的回调函数
//////////////////////////////////////////////////////////////////////////
typedef void(CALLBACK *CALLBACK_XENGINE_AVCODER_AVCOLLECT_VIDEO)(uint8_t *punStringY,int nYLen, uint8_t *punStringU, int nULen, uint8_t *punStringV, int nVLen,LPVOID lParam);
typedef void(CALLBACK *CALLBACK_XENGINE_AVCODER_AVCOLLECT_AUDIO)(uint8_t *punStringAudio,int nVLen, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AVCollect_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     声音录制导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：AVCollect_Audio_Init
函数功能：初始化音频采集器
 参数.一：lpszSoundName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要采集的声音名称,如:麦克风 (USB2.0 MIC)或者声卡:virtual-audio-capturer
 参数.二：fpCall_AVHelpAudio
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：麦克风数据返回回调函数
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：句柄
  意思：返回创建成功的句柄,错误返回NULL
备注：回调函数导出的是PCM数据,你需要调用我们的编解码工具进行进一步处理
*********************************************************************/
extern "C" XHANDLE AVCollect_Audio_Init(LPCSTR lpszSoundName, CALLBACK_XENGINE_AVCODER_AVCOLLECT_AUDIO fpCall_AVHelpAudio, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVCollect_Audio_Start
函数功能：启动声音获取功能
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Audio_Start(XHANDLE xhNet);
/********************************************************************
函数名称：AVCollect_Audio_GetInfo
函数功能：获取音频流信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pSt_AVInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出音频信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Audio_GetInfo(XHANDLE xhNet, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：AVCollect_Audio_Destory
函数功能：关闭声音录制功能
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Audio_Destory(XHANDLE xhNet);
/************************************************************************/
/*                     视频采集导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：AVCollect_Video_Init
函数功能：初始化视频采集函数,支持屏幕和摄像头
 参数.一：pSt_AVVideo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入屏幕采集信息
 参数.二：fpCall_AVHelpScreen
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：视频信息采集回调
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：句柄型
  意思：成功返回采集器句柄,错误返回NULL
备注：回调函数导出的是YUV 420P数据,你需要调用我们的编解码工具进行进一步处理
*********************************************************************/
extern "C" XHANDLE AVCollect_Video_Init(AVCOLLECT_SCREENINFO * pSt_AVScreen, CALLBACK_XENGINE_AVCODER_AVCOLLECT_VIDEO fpCall_AVVideo, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVCollect_Video_Start
函数功能：启动录制
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Video_Start(XHANDLE xhNet);
/********************************************************************
函数名称：AVCollect_Video_GetInfo
函数功能：获取录制流的信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pSt_AVInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的视频信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Video_GetInfo(XHANDLE xhNet, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：AVCollect_Video_Destory
函数功能：关闭采集器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Video_Destory(XHANDLE xhNet);