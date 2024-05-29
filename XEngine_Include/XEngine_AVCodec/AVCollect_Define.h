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
    ENUM_AVCOLLECT_VIDEO_FMT_YUV411P,
    ENUM_AVCOLLECT_VIDEO_FMT_BGR0 = 121
}ENUM_AVCOLLECT_VIDEOSAMPLEFORMAT;
//////////////////////////////////////////////////////////////////////////
//                     导出的回调函数
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    XCHAR tszVideoSize[10];                                               //采集的分辨率1920x1080,部分采集设备不支持调整分辨率
    int nPosX;                                                            //采集的坐标
    int nPosY;                                                            //采集的坐标
    int nFrameRate;                                                       //帧率
}AVCOLLECT_SCREENINFO;
typedef struct
{
    __int64x nPTS;
    __int64x nDTS;
    __int64x nDuration;
}AVCOLLECT_TIMEINFO;
//////////////////////////////////////////////////////////////////////////
//                     导出的回调函数
//////////////////////////////////////////////////////////////////////////
typedef void(CALLBACK* CALLBACK_XENGINE_AVCODEC_AVCOLLECT_VIDEO)(uint8_t* punStringY, int nYLen, uint8_t* punStringU, int nULen, uint8_t* punStringV, int nVLen, AVCOLLECT_TIMEINFO* pSt_TimeInfo, XPVOID lParam);
typedef void(CALLBACK* CALLBACK_XENGINE_AVCODEC_AVCOLLECT_AUDIO)(uint8_t* punStringAudio, int nVLen, AVCOLLECT_TIMEINFO* pSt_TimeInfo, XPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AVCollect_GetLastError(int* pInt_SysError = NULL);
/************************************************************************/
/*                     声音录制导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：AVCollect_Audio_Init
函数功能：初始化音频采集器
 参数.一：lpszCaptureType
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：采集使用的驱动,Linux:alsa Macos:avfoundation Windows:dshow
 参数.二：lpszCaptureName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：采集器使用的设备名称,hw:0,1 表示，表示第1张采集卡的第2个设备,又比如使用麦克风:audio=%s
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
      参数一和二必须是UTF8字符集编码
*********************************************************************/
extern "C" XHANDLE AVCollect_Audio_Init(LPCXSTR lpszCaptureType, LPCXSTR lpszCaptureName, CALLBACK_XENGINE_AVCODEC_AVCOLLECT_AUDIO fpCall_AVHelpAudio, XPVOID lParam = NULL);
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
extern "C" bool AVCollect_Audio_Start(XHANDLE xhNet);
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
extern "C" bool AVCollect_Audio_GetInfo(XHANDLE xhNet, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：AVCollect_Audio_GetTimeBase
函数功能：获取时间基
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Num
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出分子
 参数.三：pInt_Den
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出分母
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Audio_GetTimeBase(XHANDLE xhNet, int* pInt_Num, int* pInt_Den);
/********************************************************************
函数名称：AVCollect_Audio_Read
函数功能：主动读取一段数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的采集器
 参数.二：ptszMsgBuffer
  In/Out：In
  类型：字符指针
  可空：N
  意思：输出读取到的数据
 参数.三：pInt_MsgLen
  In/Out：In
  类型：整数型指针
  可空：N
  意思：输出数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Audio_Read(XHANDLE xhNet, XBYTE * ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：AVCollect_Audio_SetCall
函数功能：设置音频采集回调模式
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的采集器
 参数.二：bIsCall
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：设置采集模式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Audio_SetCall(XHANDLE xhNet, bool bIsCall = true);
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
extern "C" bool AVCollect_Audio_Destory(XHANDLE xhNet);
/************************************************************************/
/*                     视频采集导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：AVCollect_Video_Init
函数功能：初始化视频采集函数,支持屏幕和摄像头
 参数.一：lpszCaptureType
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：采集使用的驱动,Linux:video4linux2(x11grab) Macos:avfoundation Windows:dshow
 参数.二：lpszCaptureName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：采集器使用的设备名称,Linux:0 Macos:0:1 Windows:video=screen-capture-recorder
 参数.三：pSt_AVVideo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入屏幕采集信息
 参数.四：fpCall_AVHelpScreen
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：视频信息采集回调
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功
备注：回调函数导出的是YUV420P(mac:yuyv422)数据,你需要调用我们的编解码工具进行进一步处理
      参数一和二必须是UTF8字符集编码
*********************************************************************/
extern "C" XHANDLE AVCollect_Video_Init(LPCXSTR lpszCaptureType, LPCXSTR lpszCaptureName, AVCOLLECT_SCREENINFO * pSt_AVScreen, CALLBACK_XENGINE_AVCODEC_AVCOLLECT_VIDEO fpCall_AVVideo, XPVOID lParam = NULL);
/********************************************************************
函数名称：AVCollect_Video_Start
函数功能：启动录制
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：bYUVPacket
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输出的数据是否为一个YUV包,默认分开
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Video_Start(XHANDLE xhNet, bool bYUVPacket = false);
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
extern "C" bool AVCollect_Video_GetInfo(XHANDLE xhNet, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：AVCollect_Video_GetTimeBase
函数功能：获取时间基
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Num
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出分子
 参数.三：pInt_Den
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出分母
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Video_GetTimeBase(XHANDLE xhNet, int* pInt_Num, int* pInt_Den);
/********************************************************************
函数名称：AVCollect_Video_Read
函数功能：主动读取一个采集的视频信息数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的采集器
 参数.二：ptszYBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出视频YUV的Y缓冲区
 参数.三：pInt_YLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出Y缓冲区大小
 参数.四：ptszUBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出视频YUV的U缓冲区
 参数.五：pInt_ULen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出U缓冲区大小
 参数.六：ptszVBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出视频YUV的V缓冲区
 参数.七：pInt_VLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出V缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Video_Read(XHANDLE xhNet, XBYTE * ptszYBuffer, int* pInt_YLen, XBYTE * ptszUBuffer, int* pInt_ULen, XBYTE * ptszVBuffer, int* pInt_VLen);
/********************************************************************
函数名称：AVCollect_Video_SetCall
函数功能：设置采集数据模式
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的采集器
 参数.二：bIsCall
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：设置采集模式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVCollect_Video_SetCall(XHANDLE xhNet, bool bIsCall = true);
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
extern "C" bool AVCollect_Video_Destory(XHANDLE xhNet);
