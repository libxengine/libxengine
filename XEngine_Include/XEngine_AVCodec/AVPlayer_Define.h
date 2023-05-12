#pragma once
/********************************************************************
//	Created:	2018/10/8   15:53
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPlayer\AVPlayer_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPlayer
//	File Base:	AVPlayer_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	播放器导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AVPlayer_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     视频播放器导出函数                                  */
/************************************************************************/
/********************************************************************
函数名称：AVPlayer_Video_Create
函数功能：创建一个播放器窗口
 参数.一：lPWindowFrom
  In/Out：In
  类型：无类型指针
  可空：N
  意思：输入窗口句柄
 参数.二：lpszWindowName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入窗口名称
 参数.三：nWidth
  In/Out：In
  类型：整数型
  可空：Y
  意思：指定显示窗口宽度
 参数.四：nHeight
  In/Out：In
  类型：整数型
  可空：Y
  意思：指定显示窗口高度
 参数.五：nXPos
  In/Out：In
  类型：整数型
  可空：Y
  意思：窗口所在屏幕X的坐标
 参数.六：nYPos
  In/Out：In
  类型：整数型
  可空：Y
  意思：窗口所在屏幕Y的坐标
返回值
  类型：句柄型
  意思：成功返回创建的句柄,失败返回NULL
备注：lPWindowFrom参数可用的时候,最后两个参数将无效.lPWindowFrom可以附在指定窗口句柄
      lpszWindowName创建单独窗口的时候,你的父进程如果是窗口,那么将崩溃
*********************************************************************/
extern "C" XHANDLE AVPlayer_Video_Create(XPVOID lPWindowFrom, LPCXSTR lpszWindowName = NULL, int nWidth = 0, int nHeight = 0, int nXPos = 0, int nYPos = 0);
/********************************************************************
函数名称：AVPlayer_Video_Push
函数功能：压入一段YUV数据给播放器并且显示它
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要插入的到的播放器句柄
 参数.二：pszYUVData
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：YUV缓冲区
 参数.三：nLineSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入视频宽
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVPlayer_Video_Push(XHANDLE xhNet, uint8_t *pszYUVData, int nLineSize);
/********************************************************************
函数名称：AVPlayer_Video_PushData
函数功能：压入一段YUV数据给播放器并且显示它
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要插入的到的播放器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：功能同AVPlayer_Video_Push,只是YUV数据分开压入
*********************************************************************/
extern "C" bool AVPlayer_Video_PushData(XHANDLE xhNet, uint8_t* pszYData, int nYSize, uint8_t* pszUData, int nUSize, uint8_t* pszVData, int nVSize);
/********************************************************************
函数名称：AVPlayer_Video_SetWindows
函数功能：设置窗口大小
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的窗口
 参数.二：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输入调整的宽
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：输入调整的高
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVPlayer_Video_SetWindows(XHANDLE xhNet, int nWidth, int nHeight);
/********************************************************************
函数名称：AVPlayer_Video_Close
函数功能：关闭一个视频播放器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的播放器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVPlayer_Video_Close(XHANDLE xhNet);
/************************************************************************/
/*                     视频播放器导出函数                                  */
/********************************************************************
函数名称：AVPlayer_Audio_Create
函数功能：创建一个音频播放器
 参数.一：nSampleRate
  In/Out：In
  类型：整数型
  可空：N
  意思：音频数据的采样率。常用的有48000,44100等。
 参数.二：nSampleFmt
  In/Out：In
  类型：整数型
  可空：Y
  意思：音频数据的采样格式，参考AVCOLLECT_AUDIOSAMPLEFORMAT（目前支持S16和S32）
 参数.三：nChannel
  In/Out：In
  类型：整数型
  可空：Y
  意思：音频通道数量2为双通道
 参数.四：pInt_ASize
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输出音频缓冲缓冲区大小,可以根据这个值投递数据
返回值
  类型：句柄型
  意思：返回创建成功的句柄,错误返回NULL
备注：
*********************************************************************/
extern "C" XHANDLE AVPlayer_Audio_Create(int nSampleRate,int nSampleFmt,int nChannel = 2, int* pInt_ASize = NULL);
/********************************************************************
函数名称：AVPlayer_Audio_Push
函数功能：压入一段PCM音频数据给播放器并且播放它
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：播放器句柄
 参数.二：lpszPCMData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：PCM音频数据缓冲区
 参数.三：nPCMSize
  In/Out：In
  类型：整数型
  可空：N
  意思：音频数据缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：这个播放函数请放到线程中运行,否则会造成线程卡死
     你需要自己控制SLEEP时间和播放速率
*********************************************************************/
extern "C" bool AVPlayer_Audio_Push(XHANDLE xhNet,LPCXSTR lpszPCMData,int nPCMSize);
/********************************************************************
函数名称：AVPlayer_Audio_Close
函数功能：关闭一个音频播放器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的播放器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVPlayer_Audio_Close(XHANDLE xhNet);
/********************************************************************
函数名称：AVPlayer_Audio_Pause
函数功能：暂停或者继续播放音频
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：播放器句柄
 参数.二：bIsPlayer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真为继续，为假为暂停
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数将操作音频设备播放和暂停
*********************************************************************/
extern "C" bool AVPlayer_Audio_Pause(XHANDLE xhNet,bool bIsPlayer);
/********************************************************************
函数名称：AVPlayer_Audio_GetSize
函数功能：获取音频设备缓冲区剩余待播放的数据量
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：播放器句柄
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出剩余的播放数据大小（字节）
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVPlayer_Audio_GetSize(XHANDLE xhNet,int *pInt_Len);
/********************************************************************
函数名称：AVPlayer_Audio_Clear
函数功能：清空播放缓冲区剩余数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：播放器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVPlayer_Audio_Clear(XHANDLE xhNet);