#pragma once
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
    ENUM_AVCOLLECT_VIDEO_FMT_YUV411P
}ENUM_AVCOLLECT_VIDEOSAMPLEFORMAT;
//////////////////////////////////////////////////////////////////////////
//                     导出的回调函数
//////////////////////////////////////////////////////////////////////////
typedef void(CALLBACK *CALLBACK_XENGINE_AVCODER_AVCOLLECT_SCREENRECORD)(uint8_t *punStringY,int nYLen, uint8_t *punStringU, int nULen, uint8_t *punStringV, int nVLen,LPVOID lParam);
typedef void(CALLBACK *CALLBACK_XENGINE_AVCODER_AVCOLLECT_CAMERA)(uint8_t *punStringY, int nYLen, uint8_t *punStringU, int nULen, uint8_t *punStringV, int nVLen,LPVOID lParam);
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
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄指针
  可空：N
  意思：导出初始化成功的音频采集句柄
 参数.二：lpszSoundName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要采集的声音名称,如:麦克风 (USB2.0 MIC)或者声卡:virtual-audio-capturer
 参数.三：fpCall_AVHelpAudio
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：麦克风数据返回回调函数
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功
备注：回调函数导出的是PCM数据,你需要调用我们的编解码工具进行进一步处理
*********************************************************************/
extern "C" BOOL AVCollect_Audio_Init(XNETHANDLE *pxhNet, LPCSTR lpszSoundName, CALLBACK_XENGINE_AVCODER_AVCOLLECT_AUDIO fpCall_AVHelpAudio, LPVOID lParam = NULL);
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
extern "C" BOOL AVCollect_Audio_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVCollect_Audio_GetInfo
函数功能：获取音频流信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.一：pEnum_AVSampleFmt
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：导出音频格式编码
 参数.二：pInt_BitRate
  In/Out：Out
  类型：64位整数型指针
  可空：N
  意思：导出获取到的BIT码率
 参数.三：pInt_SampleRate
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的SAMPLE码率
 参数.四：pInt_Channels
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的音频通道数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Audio_GetInfo(XNETHANDLE xhNet, ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT *pEnum_AVSampleFmt, int64_t *pInt_BitRate, int *pInt_SampleRate, int *pInt_Channels);
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
extern "C" BOOL AVCollect_Audio_Destory(XNETHANDLE xhNet);
/************************************************************************/
/*                     摄像头录制导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：AVCollect_Camera_Init
函数功能：初始化摄像头录像函数
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄指针
  可空：N
  意思：导出初始化的摄像头句柄
 参数.二：fpCall_AVHelpCamera
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：摄像头数据返回回调函数
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功
备注：回调函数导出的是YUV 420P数据,你需要调用我们的编解码工具进行进一步处理
*********************************************************************/
extern "C" BOOL AVCollect_Camera_Init(XNETHANDLE *pxhNet, CALLBACK_XENGINE_AVCODER_AVCOLLECT_CAMERA fpCall_AVHelpCamera, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVCollect_Camera_Start
函数功能：启动摄像头录制
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
extern "C" BOOL AVCollect_Camera_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVCollect_Camera_GetInfo
函数功能：获取摄像头录制流的信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Width
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的宽度
 参数.三：pInt_Height
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的视频流高度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Camera_GetInfo(XNETHANDLE xhNet, int *pInt_Width, int *pInt_Height, int64_t * pInt_BitRate);
/********************************************************************
函数名称：AVCollect_Camera_Destory
函数功能：关闭摄像头录像功能
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
extern "C" BOOL AVCollect_Camera_Destory(XNETHANDLE xhNet);
/************************************************************************/
/*                     屏幕录制导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：AVCollect_Screen_Init
函数功能：初始化屏幕录像函数
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄指针
  可空：N
  意思：导出初始化成功的屏幕采集句柄
 参数.二：fpCall_AVHelpScreen
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：屏幕录像数据返回回调函数
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
 参数.四：lpszVideoSize
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要屏幕录像的分辨率大小,默认全屏,否者输入 1920x1080
 参数.五：nPosX
  In/Out：In
  类型：整数型
  可空：Y
  意思：要录制的屏幕X坐标
 参数.六：nPosY
  In/Out：In
  类型：整数型
  可空：Y
  意思：要录制的屏幕Y坐标
 参数.七：nFrameRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：帧率.每秒多少帧,默认25!
返回值
  类型：逻辑型
  意思：是否成功
备注：回调函数导出的是YUV 420P数据,你需要调用我们的编解码工具进行进一步处理
*********************************************************************/
extern "C" BOOL AVCollect_Screen_Init(XNETHANDLE *pxhNet, CALLBACK_XENGINE_AVCODER_AVCOLLECT_SCREENRECORD fpCall_AVHelpScreen, LPVOID lParam = NULL, LPCSTR lpszVideoSize = NULL, int nPosX = 0, int nPosY = 0, int nFrameRate = 0);
/********************************************************************
函数名称：AVCollect_Screen_Start
函数功能：启动屏幕录制
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
extern "C" BOOL AVCollect_Screen_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVCollect_Screen_GetInfo
函数功能：获取屏幕录制流的信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Width
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的宽度
 参数.三：pInt_Height
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的视频流高度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVCollect_Screen_GetInfo(XNETHANDLE xhNet, int *pInt_Width, int *pInt_Height, int64_t * pInt_BitRate);
/********************************************************************
函数名称：AVCollect_Screen_Destory
函数功能：关闭屏幕录像工具
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
extern "C" BOOL AVCollect_Screen_Destory(XNETHANDLE xhNet);
