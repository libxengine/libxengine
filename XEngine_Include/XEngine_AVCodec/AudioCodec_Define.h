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
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G726 = 0x1100B,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G729 = 86069,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_AAC = 86018,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_AC3 = 86019,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_FLAC = 86028,
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
    AVCODEC_TIMESTAMP st_TimeStamp;                                       //时间戳
    XENGINE_MSGBUFFER st_MSGBuffer;                                       //编码缓冲区.单独使用AudioCodec_Stream_FreeBuffer,列表使用AudioCodec_Stream_Free
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
 参数.一：pSt_AudioInfo
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要编码成的音频格式
 参数.二：bHDRGlobal
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否写全局头,对于AAC不设置将会有ADTS头(适合裸流),设置将是raw(适合mp4等封装格式)
        mp2,mp3等格式没有多大作用
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
返回值
  类型：句柄
  意思：输出初始化成功的句柄
备注：部分编码格式需要指定一帧大小,比如G711...
*********************************************************************/
extern "C" XHANDLE AudioCodec_Stream_EnInit(AVCODEC_AUDIO_INFO * pSt_AudioInfo, bool bHDRGlobal = true, __int64x nRateMin = 0, __int64x nRateMax = 0);
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
extern "C" bool AudioCodec_Stream_GetSize(XHANDLE xhNet, int* pInt_Size);
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
  可空：N
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
extern "C" bool AudioCodec_Stream_GetAVCodec(XHANDLE xhNet, XHANDLE* pSt_AVParameter, AVCODEC_TIMEBASE* pSt_AVTimeBase = NULL);
/********************************************************************
函数名称：AudioCodec_Stream_EnCodec
函数功能：编码音频
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入编码器句柄
 参数.二：pSt_MSGBuffer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要编码的音频数据
 参数.三：pppSt_ListMsgBuffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出编码好的数据队列,需要调用AudioCodec_Stream_Free释放内存
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：打出获取到的队列个数
返回值
  类型：逻辑型
  意思：是否编码成功
备注：如果pSt_MSGBuffer为NULL,那么表示编码剩余缓冲区数据,你投递的pcm必须为单独一帧
*********************************************************************/
extern "C" bool AudioCodec_Stream_EnCodec(XHANDLE xhNet, AVCODEC_AUDIO_MSGBUFFER* pSt_MSGBuffer, AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer, int* pInt_ListCount);
/********************************************************************
函数名称：AudioCodec_Stream_DeInit
函数功能：初始化解码器
 参数.一：nAvCodec
  In/Out：In
  类型：枚举型
  可空：N
  意思：要使用哪个解码器
 参数.二：pSt_AVCodecParameter
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：原始的音频编解码参数信息,某些时候解码失败,可以使用此方法可以配置解码器更有效果
		如果解码器和封包格式参数不匹配,这个值会被修改为解码器参数
 参数.三：pSt_AVTimeBase
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：设置解码器的时间基,某些封包数据需要设置,因为关系到时钟同步,如果有最好设置
 参数.四：enSampleFmt
  In/Out：In
  类型：枚举型
  可空：Y
  意思：请求指定输出的音频format格式,如果不支持返回失败,默认不指定
返回值
  类型：句柄
  意思：输出初始化成功的句柄
备注：pSt_AudioInfo可填充音频扩展信息,部分流可能需要此信息才能解码
*********************************************************************/
extern "C" XHANDLE AudioCodec_Stream_DeInit(ENUM_AVCODEC_AUDIOTYPE nAvCodec, XHANDLE pSt_AVCodecParameter = NULL, AVCODEC_TIMEBASE* pSt_AVTimeBase = NULL, ENUM_AVCODEC_AUDIO_SAMPLEFMT enSampleFmt = ENUM_AVCODEC_AUDIO_SAMPLEFMT_NONE);
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
extern "C" bool AudioCodec_Stream_GetInfo(XHANDLE xhNet, int* pInt_Channels = NULL, int* pInt_SampleRate = NULL, int* pInt_SampleSize = NULL, int* pInt_Format = NULL);
/********************************************************************
函数名称：AudioCodec_Stream_DeCodec
函数功能：解码音频数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：解码器句柄
 参数.二：pSt_MSGBuffer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要解码的数据缓冲区,时间戳可以为0或者提供
 参数.三：pppSt_ListMsgBuffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解码后的音频数据列表
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：解码成功的数据通过回调函数返回
*********************************************************************/
extern "C" bool AudioCodec_Stream_DeCodec(XHANDLE xhNet, AVCODEC_AUDIO_MSGBUFFER* pSt_MSGBuffer, AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer, int* pInt_ListCount);
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
extern "C" bool AudioCodec_Stream_Destroy(XHANDLE xhNet);
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
函数名称：AudioCodec_Help_GetRateList
函数功能：获取编码器支持的输出输入采样率
 参数.一：enACodecType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入音频编码器
 参数.二：pppenListRate
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出支持的音频采样率
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出支持的格式个数
 参数.四：bEncoder
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输出编码器还是解码器支持的采样率
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_GetRateList(ENUM_AVCODEC_AUDIOTYPE enACodecType, int*** pppenListRate, int* pInt_ListCount, bool bEncoder = true);
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
函数名称：AudioCodec_Help_GetChList
函数功能：获取音频编解码器支持的通道类型
 参数.一：enACodecType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入音频编码器
 参数.二：ppptszListChannels
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出支持的音频通道
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出支持的格式个数
 参数.四：bEncoder
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输出编码器还是解码器支持的通道格式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_GetChList(ENUM_AVCODEC_AUDIOTYPE enACodecType, XCHAR*** ppptszListChannels, int* pInt_ListCount, bool bEncoder = true);
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
函数名称：AudioCodec_Help_GetSampleSize
函数功能：获取音频编码器的采样大小
 参数.一：enAudioCodec
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入音频编码器
返回值
  类型：整数型
  意思：返回采样大小,0或者1没有限制
备注：某些音频编码器有固定的采样大小,比如AAC是1024,MP3是1152
      通过此函数可以获取到对应的采样大小
*********************************************************************/
extern "C" int AudioCodec_Help_GetSampleSize(ENUM_AVCODEC_AUDIOTYPE enAudioCodec);
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
      推荐使用滤镜处理更简单:,asetnsamples=n=1024:p=1
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
 参数.二：pSt_MSGBuffer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要投递的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：支持各种format格式
*********************************************************************/
extern "C" bool AudioCodec_Help_FifoSend(XHANDLE xhToken, AVCODEC_AUDIO_MSGBUFFER* pSt_MSGBuffer);
/********************************************************************
函数名称：AudioCodec_Help_FifoRecv
函数功能：从音频队列得到一帧
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的队列
 参数.二：pSt_MSGBuffer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出获取到的数据,需要专用函数释放内存
 参数.三：bIsTail
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否是末尾数据
返回值
  类型：逻辑型
  意思：是否成功
备注：将会设置数据区的st_TimeStamp,这个值作为参考,一般编码的时候也会有自己的输出
*********************************************************************/
extern "C" bool AudioCodec_Help_FifoRecv(XHANDLE xhToken, AVCODEC_AUDIO_MSGBUFFER* pSt_MSGBuffer, bool bIsTail = false);
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
/********************************************************************
函数名称：AudioCodec_Help_Malloc
函数功能：申请音频专用内存
 参数.一：pSt_MSGBuffer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要初始化使用的音频数据结构
返回值
  类型：逻辑型
  意思：是否成功
备注：需要填充音频参数的采样格式,采样大小,通道等参数
	  申请的内存需要使用BaseLib_Memory_MSGFree函数释放内部ptszMSGArray内存
*********************************************************************/
extern "C" bool AudioCodec_Help_Malloc(AVCODEC_AUDIO_MSGBUFFER* pSt_MSGBuffer);