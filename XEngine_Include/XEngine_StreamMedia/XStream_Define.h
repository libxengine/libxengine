﻿#pragma once
/********************************************************************
//	Created:	2020/07/29  11:14:10
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XClient\XClient_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XClient
//	File Base:	XClient_Define
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	流媒体客户端导出函数
                File文件推流适用于文件,如果是文件建议使用此模式,他会自动处理推流速度
                Codec编码推流适用于第三方设备过来的数据
                Stream原始推流适用于采集的原始数据
//	History:
*********************************************************************/
typedef enum 
{
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_UNKNOWN = -1, 
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_VIDEO,
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_AUDIO,
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_DATA,      
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_SUBTITLE,
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_ATTACHMENT,   
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE_NB
}ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE;
///////////////////////////////////////////////////////////////////////////////
//                               导出的数据结构
///////////////////////////////////////////////////////////////////////////////
typedef struct  
{
    XENGINE_PROTOCOL_AVINFO st_MediaStream;
    ENUM_STREAMMEIDA_XCLIENT_STREAM_TYPE enStreamType;
    XBOOL bEnable;               //是否使用此流,默认启用
    int nStreamIndex;           //流索引
    int nOutIndex;              //系统内部使用
}STREAMMEDIA_PULLSTREAM;
///////////////////////////////////////////////////////////////////////////////
//                               导出的回调函数
///////////////////////////////////////////////////////////////////////////////
typedef void(*CALLBACK_XENGINE_STREAMMEDIA_XCLIENT_AVINFO)(uint8_t* puszMsgBuffer, int nSize, int nAVType, __int64x nPts, __int64x nDts, __int64x nDuration, double dlTime, XPVOID lParam);
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" XLONG StreamClient_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
                             导出实时流推送函数
******************************************************************************/
/********************************************************************
函数名称：XClient_StreamPush_Init
函数功能：初始化一个实时流推送服务器
 参数.一：lpszPushUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：推送的URL地址,播放也是这个地址
 参数.二：pSt_AVProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入音视频媒体信息
 参数.三：lpszProtocolStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要推流的数据格式,支持rtsp,rtmp
 参数.四：bDelay
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用内部延迟,正常来说,采集效率应该正好适配发送速率,不需要采用内部延迟
        除非你的程序采集效率过快
返回值
  类型：句柄
  意思：返回初始化后的句柄
备注：
*********************************************************************/
extern "C" XHANDLE XClient_StreamPush_Init(LPCXSTR lpszPushUrl, XENGINE_PROTOCOL_AVINFO * pSt_AVProtocol, LPCXSTR lpszProtocolStr = ("flv"), XBOOL bDelay = FALSE);
/********************************************************************
函数名称：XClient_StreamPush_PushVideo
函数功能：推送一个视频数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入初始化的推流句柄
 参数.二：punYBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：yuv中的y数据
 参数.三：nYLen
  In/Out：In
  类型：整数型
  可空：N
  意思：y数据大小
 参数.四：punUBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：yuv中的u数据
 参数.五：nULen
  In/Out：In
  类型：整数型
  可空：N
  意思：u数据大小
 参数.七：punVBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：yuv中的v数据
 参数.八：nVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：punYBuffer 可以作用于yuv数据集合,那么u和v 都需要设置为NULL,并且
      nYLen是YUV的总大小
*********************************************************************/
extern "C" XBOOL XClient_StreamPush_PushVideo(XHANDLE xhNet, uint8_t* punYBuffer, int nYLen, uint8_t* punUBuffer, int nULen, uint8_t* punVBuffer, int nVLen);
/********************************************************************
函数名称：XClient_StreamPush_PushAudio
函数功能：推送音频数据到流中
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的RTMP客户端
 参数.二：ptszPCMBuffer
  In/Out：In
  类型：字符指针
  可空：N
  意思：输入要推送的数据
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_StreamPush_PushAudio(XHANDLE xhNet, uint8_t* ptszPCMBuffer, int nLen);
/********************************************************************
函数名称：XClient_StreamPush_Close
函数功能：关闭一个实时推流通道
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的通道句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" XBOOL XClient_StreamPush_Close(XHANDLE xhNet);
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：XClient_CodecPush_Init
函数功能：初始化一个实时流推送服务器
 参数.一：lpszPushUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：推送的URL地址,播放地址需要根据流媒体服务决定
 参数.二：pSt_AVProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入音视频媒体信息
 参数.三：lpszProtocolStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要推流的数据格式,支持rtsp,flv
返回值
  类型：句柄
  意思：返回初始化后的句柄
备注：pSt_AVProtocol的视频tszVInfo信息必须填充,音频仅支持AAC
      如果tszVInfo 没有填充,那么需要在XClient_CodecPush_WriteHdr的参数二填充,否则无法使用
      也可以推本地文件,比如写HLS.那么参数一就是本地文件地址,参数三是HLS
*********************************************************************/
extern "C" XHANDLE XClient_CodecPush_Init(LPCXSTR lpszPushUrl, XENGINE_PROTOCOL_AVINFO* pSt_AVProtocol, LPCXSTR lpszProtocolStr = ("flv"));
/********************************************************************
函数名称：XClient_CodecPush_WriteHdr
函数功能：写入头信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pSt_AVProtocol
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：写入媒体头,如果你初始化已经填充好此参数,那么可以忽略
返回值
  类型：逻辑型
  意思：是否成功
备注：初始化后必须调用
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_WriteHdr(XHANDLE xhNet, XENGINE_PROTOCOL_AVINFO * pSt_AVProtocol = NULL);
/********************************************************************
函数名称：XClient_CodecPush_WriteTail
函数功能：写入媒体尾,某些时候需要
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：如果你是写本地文件,那么需要此函数
      请注意:此函数会关闭输出句柄,调用此函数后不能继续write操作
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_WriteTail(XHANDLE xhNet);
/********************************************************************
函数名称：XClient_CodecPush_PushVideo
函数功能：推送一个视频数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入初始化的推流句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：bThread初始化参数为FALSE,那么你必须一帧一帧的投递
      bThread为真,如果投递数据过快,可能会返回错误,因为内部缓冲区还没处理完毕.所以投递速度不能过快
      如果返回的错误码为:ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHVIDEO_MAXBUFFER
      表示缓冲区投递过快,如果你尝试了几次都是这个问题,可能是你投递的缓冲区不正确导致的,你需要查找自身原因
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_PushVideo(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：XClient_CodecPush_PushAudio
函数功能：推送一个音频数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入初始化的推流句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：bThread初始化参数为FALSE,那么你必须一帧一帧的投递
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_PushAudio(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：XClient_CodecPush_Close
函数功能：关闭一个实时推流通道
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的通道句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_Close(XHANDLE xhNet);
/********************************************************************
函数名称：XClient_CodecPush_GetAVExt
函数功能：获取音视频扩展信息是否写入成功
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pbVInfo
  In/Out：Out
  类型：逻辑型
  可空：Y
  意思：输出视频信息是否写入成功
 参数.三：pbAInfo
  In/Out：Out
  类型：逻辑型
  可空：Y
  意思：输出音频信息是否写入成功
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_GetAVExt(XHANDLE xhNet, XBOOL* pbVInfo = NULL, XBOOL* pbAInfo = NULL);
/********************************************************************
函数名称：XClient_CodecPush_OPen
函数功能：打开文件
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要写到的文件
返回值
  类型：逻辑型
  意思：是否成功
备注：只有XClient_CodecPush_WriteTail后才能调用此函数.重新写媒体到新文件
*********************************************************************/
extern "C" XBOOL XClient_CodecPush_OPen(XHANDLE xhNet, LPCXSTR lpszFile);
/******************************************************************************
                             导出实时流拉流函数
******************************************************************************/
/********************************************************************
函数名称：XClient_StreamPull_Init
函数功能：初始化一个实时流拉取服务
 参数.一：lpszStreamUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的URL地址
 参数.二：pppSt_PullStream
  In/Out：In/Out
  类型：三级指针
  可空：N
  意思：输出流列表
 参数.三：pInt_StreamCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出流个数
 参数.四：fpCall_PullStream
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：导出当前流的每一帧的信息
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
 参数.六：bTCP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否使用TCP,RTSP有用
 参数.七：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位微妙
返回值
  类型：句柄
  意思：返回初始化成功的句柄
备注：支持RTMP RTSP HTTP协议流拉取
*********************************************************************/
extern "C" XHANDLE XClient_StreamPull_Init(LPCXSTR lpszStreamUrl, STREAMMEDIA_PULLSTREAM * **pppSt_PullStream, int* pInt_StreamCount, CALLBACK_XENGINE_STREAMMEDIA_XCLIENT_AVINFO fpCall_PullStream = NULL, XPVOID lParam = NULL, XBOOL bTCP = TRUE, int nTimeout = 2000000);
/********************************************************************
函数名称：XClient_StreamPull_PushStream
函数功能：拉取的流转到指定服务器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszPushAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要推流到的流地址
 参数.三：pppSt_PullStream
  In/Out：In/Out
  类型：三级指针
  可空：N
  意思：输入要使用的流ID
 参数.四：nStreamCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要使用的流ID个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_StreamPull_PushStream(XHANDLE xhToken, LPCXSTR lpszPushAddr, STREAMMEDIA_PULLSTREAM * **pppSt_PullStream, int nStreamCount);
/********************************************************************
函数名称：XClient_StreamPull_Start
函数功能：开始拉流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的流句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_StreamPull_Start(XHANDLE xhNet);
/********************************************************************
函数名称：XClient_StreamPull_GetStream
函数功能：获取流数据,主动模式
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的编码数据
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的数据大小
 参数.四：pInt_CodecType
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：数据类型,音频或者视频
 参数.五：pInt_Pts
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出PTS
 参数.六：pInt_Dts
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出DTS
 参数.七：pInt_Duration
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出Duration
 参数.八：pdlTime
  In/Out：Out
  类型：双精度浮点型
  可空：Y
  意思：导出获取到的时间
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数不能和XClient_StreamPull_Start同时启用,只能选一个
*********************************************************************/
extern "C" XBOOL XClient_StreamPull_GetStream(XHANDLE xhNet, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, int* pInt_CodecType, __int64x * pInt_Pts = NULL, __int64x * pInt_Dts = NULL, __int64x * pInt_Duration = NULL, double* pdlTime = NULL);
/********************************************************************
函数名称：XClient_StreamPull_GetStatus
函数功能：获取拉流状态
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的拉流句柄
 参数.二：pbPull
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：导出是否正在拉流
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_StreamPull_GetStatus(XHANDLE xhNet, XBOOL* pbPull);
/********************************************************************
函数名称：XClient_StreamPull_Suspend
函数功能：暂停或者继续
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的流句柄
 参数.二：bSuspend
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真暂停,为假继续
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_StreamPull_Suspend(XHANDLE xhNet, XBOOL bSuspend = TRUE);
/********************************************************************
函数名称：XClient_StreamPull_Close
函数功能：关闭一个拉取流流通道
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的通道句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" XBOOL XClient_StreamPull_Close(XHANDLE xhNet);
/******************************************************************************
                             导出实时流推送函数
******************************************************************************/
/********************************************************************
函数名称：XClient_FilePush_Init
函数功能：推送数据到服务器
 参数.一：bVideo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用视频
 参数.二：bAudio
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用音频
 参数.三：bSleep
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否由系统计算休眠.默认真
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE XClient_FilePush_Init(XBOOL bVideo = TRUE, XBOOL bAudio = FALSE, XBOOL bSleep = TRUE);
/********************************************************************
函数名称：XClient_FilePush_Push
函数功能：推送一段内存数据给推流器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入数据大小
 参数.四：nAVType
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入媒体类型0视频,1音频
返回值
  类型：逻辑型
  意思：是否成功
备注：如果想自己推送数据而不是使用文件,那么这个函数初始化完成后就应该调用
*********************************************************************/
extern "C" XBOOL XClient_FilePush_Push(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nMsgLen, int nAVType = 0);
/********************************************************************
函数名称：XClient_FilePush_Input
函数功能：初始化输入设置
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszVideoFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入视频文件路径,如果为NULL,可以使用内存
 参数.三：lpszAudioFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入音频文件路径,如果为NULL,可以使用内存
返回值
  类型：逻辑型
  意思：是否成功
备注：如果文件为NULL,那么通过XClient_FilePush_Push 推送数据
*********************************************************************/
extern "C" XBOOL XClient_FilePush_Input(XHANDLE xhNet, LPCXSTR lpszVideoFile = NULL, LPCXSTR lpszAudioFile = NULL);
/********************************************************************
函数名称：XClient_FilePush_Output
函数功能：设置输出流消息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszStreamUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入数据流地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_FilePush_Output(XHANDLE xhNet, LPCXSTR lpszStreamUrl);
/********************************************************************
函数名称：XClient_FilePush_Start
函数功能：启动推流器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_FilePush_Start(XHANDLE xhNet);
/********************************************************************
函数名称：XClient_FilePush_GetStatus
函数功能：获取一个通道的传输状态
 参数.一：xhNet
  In/Out：In
  类型：通道句柄
  可空：N
  意思：要获取的通道状态的句柄
 参数.二：pbPush
  In/Out：Out
  类型：逻辑指针
  可空：N
  意思：导出是否正在传输,真是,假否
 参数.三：pInt_VideoIndex
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出已经发送的视频帧个数
 参数.四：pInt_AudioIndex
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出已经发送的音频帧个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XBOOL XClient_FilePush_GetStatus(XHANDLE xhNet, XBOOL* pbPush, int* pInt_VideoIndex = NULL, int* pInt_AudioIndex = NULL);
/********************************************************************
函数名称：XClient_FilePush_Close
函数功能：关闭一个文件推流通道
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的通道句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" XBOOL XClient_FilePush_Close(XHANDLE xhNet);