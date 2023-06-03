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
typedef enum en_AVCodec_AudioType
{
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_MP2 = 0x15000,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_MP3,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G711A = 65543,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G722 = 69660,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G723 = 0x15034,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G726 = 0x1100B,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_G729 = 86069,
    ENUM_XENGINE_AVCODEC_AUDIO_TYPE_AAC = 86018
}ENUM_AVCODEC_AUDIOTYPE; 
//////////////////////////////////////////////////////////////////////////
//                      导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    XBYTE* pbyMsgBuffer;                                                   //编码缓冲区
    int nMsgLen;                                                          //编解大小
}AVCODEC_AUDIO_MSGBUFFER, * LPAVCODEC_AUDIO_MSGBUFFER;
typedef struct
{
    int nCodecType;                                                       //编解码类型
    XCHAR tszCodecName[64];                                                //编解码名称
}AVCODEC_AUDIO_CODECLIST, *LPAVCODEC_AUDIO_CODECLIST;
typedef struct
{
    ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT enSampleFmt;                         //采样格式
    bool bKeyFrame;                                                       //是否是关键帧
    int nFrameTimes;                                                      //第几帧
    int nSampleRate;                                                      //采样率
    int nChannle;                                                         //通道个数
    int nNBSample;                                                        //采样个数
    __int64x nChannleLayout;                                               //通道层
}AVCODEC_AUDIO_INFO, *LPAVCODEC_AUDIO_INFO;
typedef struct
{
    XCHAR tszArgsName[MAX_PATH];                                           //要附加的音频过滤器名称，比如volume（设置音量）或tempo（播放速度）
    XCHAR tszArgsValue[MAX_PATH];                                          //名称的值，比如 volume音量大小.0.1-1
    int nSampleFmt;                                                       //采样格式
    int nSampleRate;                                                      //采样率
    int nNBSample;                                                        //样本数
    int nChannle;                                                         //通道个数
    int nIndex;                                                           //索引，从0开始传入，不可重复,混合器才有用
}AVCODEC_AUDIO_FILTER, *LPAVCODEC_AUDIO_FILTER;
//////////////////////////////////////////////////////////////////////////
//                      回调函数
//////////////////////////////////////////////////////////////////////////
typedef void(CALLBACK *CALLBACK_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC)(XNETHANDLE xhNet, uint8_t *pszBuffer, int nLen, AVCODEC_AUDIO_INFO *pSt_AudioInfo,XPVOID lParam);
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
 参数.二：nAvCoder
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要编码成的音频格式
 参数.三：nSampleRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：设置采样率
 参数.四：nChCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：设置音频编码通道个数
 参数.五：nBitRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：要编码的音频数据的平均码率
 参数.六：nRangeRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：编码器可变码率范围,设置后变为可变码率
 参数.七：nSampleFmt
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要编码成的音频采样格式
 参数.八：nFrameSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：部分编码格式需要指定一帧大小,比如G711...
       如果你不想输入指定编码大小的数据,可以使用重采样功能自动组包
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Stream_EnInit(XNETHANDLE * pxhNet, ENUM_AVCODEC_AUDIOTYPE nAvCoder = ENUM_XENGINE_AVCODEC_AUDIO_TYPE_MP2, int nSampleRate = 44100, int nChCount = 2, __int64x nBitRate = 64000, __int64x nRangeRate = 0, ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT nSampleFmt = ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S16, int nFrameSize = 0);
/********************************************************************
函数名称：AudioCodec_Stream_SetResample
函数功能：音频重采样启用并且设置
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入编码器句柄
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出每个BUFF区需要的大小
 参数.三：nSrcRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入原始音频数据码率
 参数.四：nDstRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入目标音频数据码率
 参数.五：enSrcSampleFmt
  In/Out：In
  类型：枚举型
  可空：Y
  意思：输入原始采样格式
 参数.六：enDstSampleFmt
  In/Out：In
  类型：枚举型
  可空：Y
  意思：输入目标采样格式
 参数.七：nSrcChannel
  In/Out：In
  类型：整数型
  可空：Y
  意思：源通道个数
 参数.八：nDstChannel
  In/Out：In
  类型：整数型
  可空：Y
  意思：目标通道个数
返回值
  类型：逻辑型
  意思：是否成功
备注：重采样主要为了采样格式转换,比如某些格式PCM为S16,要编码成AAC,需要转成FLTP
*********************************************************************/
extern "C" bool AudioCodec_Stream_SetResample(XNETHANDLE xhNet, int* pInt_Len, int nSrcRate = 11025, int nDstRate = 44100, ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT enSrcSampleFmt = ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_S16, ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT enDstSampleFmt = ENUM_AVCOLLECT_AUDIO_SAMPLE_FMT_FLTP, int nSrcChannel = 1, int nDstChannel = 2);
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
返回值
  类型：逻辑型
  意思：是否编码成功
备注：如果nLen为0,那么表示编码剩余缓冲区数据
      如果你没有启用重采样,你投递的pcm必须为单独一帧
*********************************************************************/
extern "C" bool AudioCodec_Stream_EnCodec(XNETHANDLE xhNet, uint8_t *ptszPCMBuffer, int nLen, AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer, int* pInt_ListCount);
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
 参数.三：fpCall_StreamFrame
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：每次解码一个数据会通过回调返回
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数参数
 参数.五：pSt_AudioInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：如果非封装类型的音频格式,需要自定义输入采样率,采样格式,通道
 参数.六：lpszAInfo
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：音频扩展信息,部分流可能需要此信息才能解码
 参数.七：nALen
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：音频扩展数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Stream_DeInit(XNETHANDLE * pxhNet, ENUM_AVCODEC_AUDIOTYPE nAvCodec, CALLBACK_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC fpCall_StreamFrame = NULL, XPVOID lParam = NULL, AVCODEC_AUDIO_INFO * pSt_AudioInfo = NULL, LPCXSTR lpszAInfo = NULL, int nALen = 0);
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
  可空：Y
  意思：如果你解码初始化没有设置回调函数,那么就这个参数将导出解码后的数据.并且你这个参数不能为NULL
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出消息个数
返回值
  类型：逻辑型
  意思：是否成功
备注：解码成功的数据通过回调函数返回
*********************************************************************/
extern "C" bool AudioCodec_Stream_DeCodec(XNETHANDLE xhNet, uint8_t *pszSourceBuffer, int nLen, AVCODEC_AUDIO_MSGBUFFER * **pppSt_ListMsgBuffer = NULL, int* pInt_ListCount = NULL);
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
备注：参数一和三必须调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool AudioCodec_Help_GetList(AVCODEC_AUDIO_CODECLIST * **pppSt_ListEncoder, int* pInt_EncoderCount, AVCODEC_AUDIO_CODECLIST * **pppSt_ListDecoder, int* pInt_DecoderCount);
/********************************************************************
函数名称：AudioCodec_Help_GetFrameSize
函数功能：获取一个音频帧的完整输入输出大小
 参数.一：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的大小
 参数.二：nChannel
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频通道个数
 参数.三：nSampleSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频采样大小,这里提供一个参考值,AAC:1024,MP3:1152
 参数.四：enAudioFmt
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频的采样格式
返回值
  类型：逻辑型
  意思：是否成功
备注：上面的输入参数都应该是由输入源提供出来的
      通过此参数你可以知道每次要读写多少大小才是一个完整的音频帧
*********************************************************************/
extern "C" bool AudioCodec_Help_GetFrameSize(int* pInt_Len, int nChannel, int nSampleSize, ENUM_AVCOLLECT_AUDIOSAMPLEFORMAT enAudioFmt);
/********************************************************************
函数名称：AudioCodec_Help_FilterInit
函数功能：初始化过滤器
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的音频过滤器
 参数.二：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：转换后的目标过滤器,可以和原始的一样
 参数.三：pStl_ListFile
  In/Out：In
  类型：LIST容器指针
  可空：N
  意思：输入要混合的音频文件和参数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二为目标拼音格式,为字符串,参数通过:分割,如下所示
     sample_rates=48000:sample_fmts=s16p:channel_layouts=stereo
*********************************************************************/
extern "C" bool AudioCodec_Help_FilterInit(XNETHANDLE *pxhNet, LPCXSTR lpszFilterStr, AVCODEC_AUDIO_FILTER *pSt_AudioFilter);
/********************************************************************
函数名称：AudioCodec_Help_FilterCvt
函数功能：进行一帧的转换
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：ptszSrcBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：要转换的数据缓冲区
 参数.三：nSrcLen
  In/Out：In
  类型：整数型
  可空：N
  意思：转换数据缓冲区大小
 参数.四：ptszDstBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：N
  意思：转换后的数据缓冲区 参数.八：nFrameSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：部分编码格式需要指定一帧大小,比如G711...
       如果你不想输入指定编码大小的数据,可以使用重采样功能自动组包
 参数.五：pInt_DstLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_FilterCvt(XNETHANDLE xhNet, uint8_t *ptszSrcBuffer, int nSrcLen, uint8_t *ptszDstBuffer, int *pInt_DstLen);
/********************************************************************
函数名称：VideoCodec_Help_FilterDestroy
函数功能：销毁一个过滤器资源
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
extern "C" bool AudioCodec_Help_FilterDestroy(XNETHANDLE xhNet);
/********************************************************************
函数名称：AudioCodec_Help_MixInit
函数功能：初始化混合器
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的音频过滤器
 参数.二：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要为音频添加的过滤器字符串
 参数.三：pppSt_ListFile
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要混合的音频文件和参数,内存由调用者维护
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要混合的音频文件和参数
返回值
  类型：逻辑型
  意思：是否成功
备注：混合器能实现一个或者多个过滤器和音频文件附加混合，参数的格式如下。表示采样率，格式，和通道
      sample_rates=48000:sample_fmts=s16p:channel_layouts=stereo。具体可以参考FFMPEG
*********************************************************************/
extern "C" bool AudioCodec_Help_MixInit(XNETHANDLE * pxhNet, LPCXSTR lpszFilterStr, AVCODEC_AUDIO_FILTER * **pppSt_ListFile, int nListCount);
/********************************************************************
函数名称：AudioCodec_Help_MixInput
函数功能：进行一帧的混合
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：nIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：要操作的索引混合文件索引
 参数.三：ptszSrcBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：输入要混合的原始数据
 参数.四：nSrcLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入混合数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：仅仅支持PCM数据,S16格式
*********************************************************************/
extern "C" bool AudioCodec_Help_MixInput(XNETHANDLE xhNet, int nIndex, uint8_t* ptszSrcBuffer, int nSrcLen);
/********************************************************************
函数名称：AudioCodec_Help_MixOutput
函数功能：把混合的数据输出
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：ptszDstBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：N
  意思：导出混合后的音频数据缓冲区
 参数.三：pInt_DstLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出混合后缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AudioCodec_Help_MixOutput(XNETHANDLE xhNet, uint8_t* ptszDstBuffer, int* pInt_DstLen);
/********************************************************************
函数名称：AudioCodec_Help_MixDestroy
函数功能：销毁一个混合器资源
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
extern "C" bool AudioCodec_Help_MixDestroy(XNETHANDLE xhNet);
