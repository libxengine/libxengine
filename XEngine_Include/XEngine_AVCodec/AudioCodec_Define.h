#pragma once
/********************************************************************
//	Created:	2012/9/8  12:07
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngien_AvCoder\NetEngine_AudioCoder\NetEngine_AudioCoder\AudioCoder_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngien_AvCoder\NetEngine_AudioCoder\NetEngine_AudioCoder
//	File Base:	AudioCoder_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音频解码器导出定义文件
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      音频编码方式
//////////////////////////////////////////////////////////////////////////
typedef enum 
{
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_MP2 = 0x15000,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_MP3,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G711A = 65543,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G722 = 69660,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G723 = 0x15034,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G726 = 0x1100B,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G729 = 86069,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_AAC = 86018,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_OPUS = 86076
}ENUM_AVCODEC_AUDIOTYPE;
typedef enum
{
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_NONE = -1,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_U8,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_S16,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_S32,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_FLT,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_DBL,

	ENUM_AVCODEC_AUDIO_SAMPLEFMT_U8P,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_S16P,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_S32P,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_FLTP,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_DBLP,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_S64,
	ENUM_AVCODEC_AUDIO_SAMPLEFMT_S64P,

	ENUM_AVCODEC_AUDIO_SAMPLEFMT_NB
}ENUM_AVCODEC_AUDIO_SAMPLEFMT;
//////////////////////////////////////////////////////////////////////////
//                      导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    AVCODEC_AUDIO_INFO st_AudioInfo;
    __int64u nPTSValue;                                                   //PTS时间戳
    __int64u nDTSValue;                                                   //DTS时间戳
    int nMsgLen;                                                          //编解大小
    XBYTE* ptszMsgBuffer;                                                 //编码缓冲区.此函数需要用户手动释放内存,BaseLib_Memory_FreeCStyle
}AVCODEC_AUDIO_MSGBUFFER, * LPAVCODEC_AUDIO_MSGBUFFER;
typedef struct
{
    int nCodecType;                                                       //编解码类型
    XCHAR tszCodecName[64];                                               //编解码名称
}AVCODEC_AUDIO_CODECLIST, *LPAVCODEC_AUDIO_CODECLIST;
//////////////////////////////////////////////////////////////////////////
//                      导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AudioCodec_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*               音频编解码实时流导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：AudioCodec_Stream_EnInit
函数功能：初始化流编解码器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出初始化成功的音频编码句柄
 参数.二：pSt_AudioInfo
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要编码成的音频格式
 参数.三：nRateMin
  In/Out：In
  类型：整数型
  可空：Y
  意思：编码器可变码率最小值,设置后变为可变码率
 参数.四：nRateMax
  In/Out：In
  类型：整数型
  可空：Y
  意思：编码器可变码率最大值,设置后变为可变码率
 参数.五：nRateLevel
  In/Out：In
  类型：整数型
  可空：Y
  意思：编码器码率等级,AAC支持,0为固定,1-5质量等级
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：部分编码格式需要指定一帧大小,比如G711...
*********************************************************************/
extern "C" bool AudioCodec_Stream_EnInit(XNETHANDLE * pxhNet, AVCODEC_AUDIO_INFO * pSt_AudioInfo, __int64x nRateMin = 0, __int64x nRateMax = 0, int nRateLevel = -1);
/********************************************************************
函数名称：AudioCodec_Stream_GetSize
函数功能：获取编码一帧数据需要的大小
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的编码器
 参数.二：pInt_Size
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出编码一帧数据需要的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Stream_GetSize(XNETHANDLE xhNet, int* pInt_Size);
/********************************************************************
函数名称：AudioCodec_Stream_GetAVCodec
函数功能：获取编解码信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的流
 参数.二：pSt_AVParameter
  In/Out：Out
  类型：二级指针
  可空：Y
  意思：输出获取的编解码参数信息,AVCodecParameters类型.此参数需要释放内存
 参数.三：pSt_AVTimeBase
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出时间基
返回值
  类型：逻辑型
  意思：是否成功
备注：pSt_AVParameter通过BaseLib_Memory_FreeCStyle释放内存
*********************************************************************/
extern "C" bool AudioCodec_Stream_GetAVCodec(XNETHANDLE xhNet, XHANDLE* pSt_AVParameter = NULL, AVCODEC_TIMEBASE* pSt_AVTimeBase = NULL);
/********************************************************************
函数名称：AudioCodec_Stream_EnCodec
函数功能：编码音频
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入编码器句柄
 参数.二：ptszPCMBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：要编码的音频数据
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要编码的数据缓冲区长度
 参数.四：pppSt_ListMsgBuffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出编码好的数据队列,需要调用AudioCodec_Stream_Free释放内存
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：打出获取到的队列个数
 参数.六：nPTS
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入自定义PTS.如果为0,自动计算PTS
返回值
  类型：逻辑型
  意思：是否编码成功
备注：如果nLen为0,那么表示编码剩余缓冲区数据
      如果你没有启用重采样,你投递的pcm必须为单独一帧
*********************************************************************/
extern "C" bool AudioCodec_Stream_EnCodec(XNETHANDLE xhNet, uint8_t *ptszPCMBuffer, int nLen, AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer, int* pInt_ListCount, __int64u nPTS = 0);
/********************************************************************
函数名称：AudioCodec_Stream_DeInit
函数功能：初始化解码器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出初始化成功的解码器句柄
 参数.二：nAvCodec
  In/Out：In
  类型：枚举型
  可空：N
  意思：要使用哪个解码器
 参数.三：pSt_AudioInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：如果非封装类型的音频格式,需要自定义输入采样率,采样格式,通道
 参数.四：pSt_AVCodecParameter
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：原始的音频编解码参数信息,某些时候解码失败,可以使用此方法可以配置解码器更有效果
		此参数与pSt_AudioInfo冲突,不能同时设置
 参数.五：enSampleFmt
  In/Out：In
  类型：枚举型
  可空：Y
  意思：请求指定输出的音频format格式,如果不支持返回失败,默认不指定
返回值
  类型：逻辑型
  意思：是否成功
备注：pSt_AudioInfo可填充音频扩展信息,部分流可能需要此信息才能解码
      如果解码出来的数据不是S16格式,那么必须通过重采样转换成S16格式
*********************************************************************/
extern "C" bool AudioCodec_Stream_DeInit(XNETHANDLE * pxhNet, ENUM_AVCODEC_AUDIOTYPE nAvCodec, AVCODEC_AUDIO_INFO* pSt_AudioInfo = NULL, XHANDLE pSt_AVCodecParameter = NULL, ENUM_AVCODEC_AUDIO_SAMPLEFMT enSampleFmt = ENUM_AVCODEC_AUDIO_SAMPLEFMT_NONE);
/********************************************************************
函数名称：AudioCodec_Stream_GetInfo
函数功能：获取音频流信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的编解码器
 参数.二：pInt_Channels
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出音频通道个数
 参数.三：pInt_SampleRate
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出采样率
 参数.四：pInt_SampleSize
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出采样大小
 参数.五：pInt_Format
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出音频采样格式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Stream_GetInfo(XNETHANDLE xhNet, int* pInt_Channels = NULL, int* pInt_SampleRate = NULL, int* pInt_SampleSize = NULL, int* pInt_Format = NULL);
/********************************************************************
函数名称：AudioCodec_Stream_GetTime
函数功能：获取音频流信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的编解码器
 参数.二：pInt_TimeDen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间分母
 参数.三：pInt_TimeNum
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间分子
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Stream_GetTime(XNETHANDLE xhNet, int* pInt_TimeDen, int* pInt_TimeNum);
/********************************************************************
函数名称：AudioCodec_Stream_DeCodec
函数功能：解码音频数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：解码器句柄
 参数.二：pszSourceBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：要解码的数据缓冲区
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要解码的数据缓冲区大小
 参数.四：pppSt_ListMsgBuffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解码后的音频数据列表
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：解码成功的数据通过回调函数返回
*********************************************************************/
extern "C" bool AudioCodec_Stream_DeCodec(XNETHANDLE xhNet, uint8_t *pszSourceBuffer, int nLen, AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer, int* pInt_ListCount);
/********************************************************************
函数名称：AudioCodec_Stream_Free
函数功能：释放编解码器缓冲区内存数据
 参数.一：pppSt_ListMsgBuffer
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要释放的内存
 参数.二：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要处理的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：无论是编码还是解码,只要你使用了的导出缓冲区模式,就必须释放内存
*********************************************************************/
extern "C" bool AudioCodec_Stream_Free(AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer, int nListCount);
/********************************************************************
函数名称：AudioCodec_Stream_Destroy
函数功能：销毁一个音频编解码器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：编解码器句柄
返回值
  类型：逻辑型
  意思：是否销毁成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Stream_Destroy(XNETHANDLE xhNet);
/************************************************************************/
/*               音频帮助函数导出                                       */
/************************************************************************/
/********************************************************************
函数名称：AudioCodec_Help_GetList
函数功能：获得当前版本支持的音频编解码器
 参数.一：pppSt_ListEncoder
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的编码器
 参数.二：pInt_EncoderCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到编码器个数
 参数.三：pppSt_ListDecoder
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的支持的解码器
 参数.四：pInt_DecoderCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的解码器个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一和三必须调用基础库的BaseLib_Memory_Free函数进行内存释放
*********************************************************************/
extern "C" bool AudioCodec_Help_GetList(AVCODEC_AUDIO_CODECLIST * **pppSt_ListEncoder, int* pInt_EncoderCount, AVCODEC_AUDIO_CODECLIST * **pppSt_ListDecoder, int* pInt_DecoderCount);
/********************************************************************
函数名称：AudioCodec_Help_GetFmtList
函数功能：获取编码器支持的输出输入格式
 参数.一：enACodecType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入音频编码器
 参数.二：pppenListSamples
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出支持的音频格式
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出支持的格式个数
 参数.四：bEncoder
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输出编码器还是解码器支持的采样格式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_GetFmtList(ENUM_AVCODEC_AUDIOTYPE enACodecType, ENUM_AVCODEC_AUDIO_SAMPLEFMT*** pppenListSamples, int* pInt_ListCount, bool bEncoder = true);
/********************************************************************
函数名称：AudioCodec_Help_GetFrameSize
函数功能：获取一个音频帧的完整输入输出大小
 参数.一：nChannel
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频通道个数
 参数.二：nSampleSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频采样大小,这里提供一个参考值,AAC:1024,MP3:1152
 参数.三：enAudioFmt
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频的采样格式
返回值
  类型：整数型
  意思：返回每帧所需内存大小
备注：上面的输入参数都应该是由输入源提供出来的
      通过此参数你可以知道每次要读写多少大小才是一个完整的音频帧
*********************************************************************/
extern "C" int AudioCodec_Help_GetFrameSize(int nChannel, int nSampleSize, ENUM_AVCODEC_AUDIO_SAMPLEFMT enAudioFmt);
/********************************************************************
函数名称：AudioCodec_Help_FifoInit
函数功能：音频数据输入输出队列初始化
 参数.一：nFormat
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频的采样格式
 参数.二：nChannels
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频的通道
 参数.三：nFrameSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频的采样大小
返回值
  类型：逻辑型
  意思：是否成功
备注：此功能一般音频都需要,如果你的解码后的音频不是标准采样大小,那么需要此功能队列
      比如nFrameSize的MP2,MP4是1152,AAC的nFrameSize是1024.那么此队列可以帮助你处理
*********************************************************************/
extern "C" XHANDLE AudioCodec_Help_FifoInit(int nFormat, int nChannels, int nFrameSize = 1024);
/********************************************************************
函数名称：AudioCodec_Help_FifoSend
函数功能：发送一个音频数据给音频队列
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的队列
 参数.二：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要投递的缓冲区
 参数.三：nNBSample
  In/Out：In
  类型：整数型
  可空：N
  意思：输入投递的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_FifoSend(XHANDLE xhToken, LPCXSTR lpszMSGBuffer, int nNBSample);
/********************************************************************
函数名称：AudioCodec_Help_FifoRecv
函数功能：从音频队列得到一帧
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的队列
 参数.二：pbyMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的数据
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.四：pInt_Pts
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出当前音频的PTS
 参数.五：bIsTail
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否是末尾数据
 参数.六：bFillSilence
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要填充末尾数据的为标准大小的静音数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_FifoRecv(XHANDLE xhToken, XBYTE* pbyMSGBuffer, int* pInt_MSGLen, __int64x* pInt_Pts = NULL, bool bIsTail = false, bool bFillSilence = false);
/********************************************************************
函数名称：AudioCodec_Help_FifoClose
函数功能：清理关闭队列
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的队列
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_FifoClose(XHANDLE xhToken);