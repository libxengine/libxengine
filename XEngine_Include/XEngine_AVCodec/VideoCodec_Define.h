#pragma once
/********************************************************************
//	Created:	2012/8/9  21:24
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngien_FFMpeg\FFMpeg_DeCodec\FFMpeg_DeCodec_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngien_FFMpeg\FFMpeg_DeCodec
//	File Base:	FFMpeg_DeCodec_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	视频解码器导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//帧类型
typedef enum 
{
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_NONE = 0,                      //没有定义
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_I,                             //I帧
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_P,                             //P帧，预测
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_B,                             //B帧
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_S,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_SI,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_SP,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_BI,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_SEI = 100,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_SPS = 101,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_PPS = 102,
    ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_VPS = 103,
	ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_AUD = 104,
	ENUM_XENGINE_AVCODEC_VIDEO_FRAMETYPE_FILL = 105
}XENGINE_AVCODEC_VIDEOFRAMETYPE, *LPXENGINE_AVCODEC_VIDEOFRAMETYPE;
//像素格式
typedef enum
{
    ENUM_AVCODEC_VIDEO_SAMPLEFMT_NONE = -1,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_YUV420P,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_YUYV422,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_RGB24,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_BGR24,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_YUV422P,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_YUV444P,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_YUV410P,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_YUV411P,
	ENUM_AVCODEC_VIDEO_SAMPLEFMT_BGR0 = 121
}ENUM_AVCODEC_VIDEO_SAMPLEFMT;
//想要获得更多编解码器编号,请通过函数VideoCodec_Help_GetList获得
typedef enum en_AvCoder_VedioType
{
	ENUM_XENGINE_AVCODEC_VIDEO_TYPE_RAWVIDEO = 13,
	ENUM_XENGINE_AVCODEC_VIDEO_TYPE_H264 = 27,
    ENUM_XENGINE_AVCODEC_VIDEO_TYPE_AVS = 87,
	ENUM_XENGINE_AVCODEC_VIDEO_TYPE_H265 = 173,
	ENUM_XENGINE_AVCODEC_VIDEO_TYPE_AVS2 = 192,          //仅X64支持
	//ENUM_XENGINE_AVCODEC_VIDEO_TYPE_AVS3 = 194
}ENUM_AVCODEC_VIDEOTYPE, * LPENUM_AVCODEC_VIDEOTYPE;
//硬件编解码器
typedef enum en_AVCodec_HWDevice
{
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NONE = 0,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_AMD,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NVIDIA,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_INTEL,
}ENUM_XENGINE_AVCODEC_HWDEVICE;
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    int nCodecType;                                                       //编解码类型
    XCHAR tszCodecName[64];                                                //编解码名称
}AVCODEC_VIDEO_CODECLIST, *LPAVCODEC_VIDEO_CODECLIST;
//硬件编解码支持
typedef struct
{
    ENUM_XENGINE_AVCODEC_HWDEVICE enHWDevice;                           //编解码类型
    XCHAR tszHWName[64];                                                   //编解码名称
}AVCODEC_VIDEO_HWCODEC, *LPAVCODEC_VIDEO_HWCODEC;
//编解码缓冲区
typedef struct
{
    AVCODEC_VIDEO_INFO st_VideoInfo;                                      //解码器生效
    AVCODEC_TIMESTAMP st_TimeStamp;                                       //时间戳
	int nAVLen;                                                           //编解大小
    //下面的内存由系统内部申请,通过用户调用函数BaseLib_Memory_FreeCStyle释放
	XBYTE* ptszAVBuffer;                                                  //编码缓冲区
}AVCODEC_VIDEO_MSGBUFFER, * LPAVCODEC_VIDEO_MSGBUFFER;
//////////////////////////////////////////////////////////////////////////
//                        导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG VideoCodec_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                        实时流编解码器导出函数                        */
/************************************************************************/
/********************************************************************
函数名称：VideoCodec_Stream_EnInit
函数功能：初始化流编解码器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出初始化成功的句柄
 参数.二：pSt_VideoInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入视频信息,必须输入宽高,编码器ID,码率,帧率
 参数.三：pppSt_KEYValue
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入自定义编码器参数列表
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入参数列表个数
 参数.五：nRateMin
  In/Out：In
  类型：整数型
  可空：Y
  意思：最小码率,默认是ABR,平均码率,设置后为可变码率VBR,如果Min和Max码率一样为CBR固定码率
 参数.六：nRateMax
  In/Out：In
  类型：整数型
  可空：Y
  意思：最大码率
 参数.七：enHWDevice
  In/Out：In
  类型：枚举型
  可空：Y
  意思：选择硬件编码器,默认不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Stream_EnInit(XNETHANDLE * pxhNet, AVCODEC_VIDEO_INFO * pSt_VideoInfo, XENGINE_KEYVALUE*** pppSt_KEYValue = NULL, int nListCount = 0, __int64x nRateMin = 0, __int64x nRateMax = 0, ENUM_XENGINE_AVCODEC_HWDEVICE enHWDevice = ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NONE);
/********************************************************************
函数名称：VideoCodec_Stream_EnCodec
函数功能：编码图像
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的编码器句柄
 参数.二：ptszAVBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：原始帧的数据缓冲区
 参数.三：nAVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：数据缓冲区大小
 参数.四：pppSt_MSGBuffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出编码好的数据结构
 参数.五：pInt_ListCount
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输出编码的个数
 参数.六：nPTS
  In/Out：In
  类型：整数型
  可空：Y
  意思：自定义PTS
 参数.七：nDTS
  In/Out：In
  类型：整数型
  可空：Y
  意思：自定义DTS,有B帧的情况需要
 参数.八：bKeyFrame
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否编码成关键帧
返回值
  类型：逻辑型
  意思：是否编码成功
备注：nYLen = 0,表示发送结束帧
*********************************************************************/
extern "C" bool VideoCodec_Stream_EnCodec(XNETHANDLE xhNet, uint8_t* ptszAVBuffer, int nAVLen, AVCODEC_VIDEO_MSGBUFFER*** pppSt_MSGBuffer, int* pInt_ListCount, __int64u nPTS = 0, __int64u nDTS = 0, bool bKeyFrame = false);
/********************************************************************
函数名称：VideoCodec_Stream_DeInit
函数功能：初始化解码器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出解码器句柄
 参数.二：nAvCodec
  In/Out：In
  类型：枚举型
  可空：N
  意思：初始化解码器的类型
 参数.三：lpszVInfo
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：解码器附加信息,某些流可能需要附加SPS PPS等信息才能解码
 参数.四：nVLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：附加媒体信息大小
 参数.五：pSt_AVParameter
  In/Out：In
  类型：句柄
  可空：Y
  意思：指定解码器参数,用于一些特别的解码媒体格式解码
 参数.六：pSt_AVTimeBase
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入媒体封包时间基,用于时钟同步
 参数.七：enHWDevice
  In/Out：In
  类型：枚举型
  可空：Y
  意思：选择硬件解码器,默认不启用,如果启用将只有Y数据生效
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Stream_DeInit(XNETHANDLE *pxhNet, ENUM_AVCODEC_VIDEOTYPE nAvCodec, LPCXSTR lpszVInfo = NULL, int nVLen = 0, XHANDLE pSt_AVParameter = NULL, AVCODEC_TIMEBASE* pSt_AVTimeBase = NULL, ENUM_XENGINE_AVCODEC_HWDEVICE enHWDevice = ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NONE);
/********************************************************************
函数名称：VideoCodec_Stream_DeCodec
函数功能：解码一个视频帧
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要处理的解码器
 参数.二：ptszAVBuffer
  In/Out：In
  类型：无符号整数指针
  可空：N
  意思：要解码的数据缓冲区地址,必须为一个完整的帧
 参数.三：nAVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要解码的缓冲区长度
 参数.四：pppSt_MSGBuffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解码的数据列表,
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数,
返回值
  类型：逻辑型
  意思：是否成功
备注：如果ptszAVBuffer为NULL,nLen为0表示发送结束帧
*********************************************************************/
extern "C" bool VideoCodec_Stream_DeCodec(XNETHANDLE xhNet, uint8_t* ptszAVBuffer, int nAVLen, AVCODEC_VIDEO_MSGBUFFER * **pppSt_MSGBuffer, int* pInt_ListCount);
/********************************************************************
函数名称：VideoCodec_Stream_GetInfo
函数功能：获取视频信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入编解码器的句柄
 参数.二：pInt_Width
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：获取到的视频宽度
 参数.三：pInt_Height
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：获取到的视频高度
 参数.四：pInt_Format
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：获取到的视频采样格式
返回值
  类型：逻辑型
  意思：是否成功
备注：初始化成功后才可以使用此函数
*********************************************************************/
extern "C" bool VideoCodec_Stream_GetInfo(XNETHANDLE xhNet, int* pInt_Width = NULL, int* pInt_Height = NULL, int* pInt_Format = NULL);
/********************************************************************
函数名称：VideoCodec_Stream_GetAVCodec
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
extern "C" bool VideoCodec_Stream_GetAVCodec(XNETHANDLE xhNet, XHANDLE* pSt_AVParameter = NULL, AVCODEC_TIMEBASE* pSt_AVTimeBase = NULL);
/********************************************************************
函数名称：VideoCodec_Stream_Destroy
函数功能：销毁一个流编码器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要销毁的编解码器句柄
返回值
  类型：逻辑型
  意思：是否销毁成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Stream_Destroy(XNETHANDLE xhNet);
/************************************************************************/
/*                        视频帮助函数导出                              */
/************************************************************************/
/********************************************************************
函数名称：VideoCodec_Help_GetList
函数功能：获得当前版本支持的视频编解码器
 参数.一：pStl_ListEncoder
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的编码器
 参数.二：pInt_EncoderCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出编码器个数
 参数.三：pStl_ListDecoder
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的解码器
 参数.四：pInt_DecoderCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出解码器个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一和三必须使用基础库的BaseLib_Memory_Free函数释放内存
*********************************************************************/
extern "C" bool VideoCodec_Help_GetList(AVCODEC_VIDEO_CODECLIST * **pppSt_ListEncoder, int* pInt_EncoderCount, AVCODEC_VIDEO_CODECLIST * **pppSt_ListDecoder, int* pInt_DecoderCount);
/********************************************************************
函数名称：VideoCodec_Help_GetFmtList
函数功能：获取编解码器支持的输出输入格式
 参数.一：enVCodecType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入视频编码器
 参数.二：pppenListPixs
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出支持的视频格式
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出支持的格式个数
 参数.四：bEncoder
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输出编码器还是解码支持的采样格式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Help_GetFmtList(ENUM_AVCODEC_VIDEOTYPE enVCodecType, ENUM_AVCODEC_VIDEO_SAMPLEFMT*** pppenListPixs, int* pInt_ListCount, bool bEncoder = true);
/********************************************************************
函数名称：VideoCodec_Help_GetRateList
函数功能：获取编解码器支持的帧率
 参数.一：enVCodecType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入视频编码器
 参数.二：pppSt_TimeList
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出支持的视频帧率
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出支持的个数
 参数.四：bEncoder
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输出编码器还是解码支持的帧率
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Help_GetRateList(ENUM_AVCODEC_VIDEOTYPE enVCodecType, AVCODEC_TIMEBASE*** pppSt_TimeList, int* pInt_ListCount, bool bEncoder = true);
/********************************************************************
函数名称：VideoCodec_Help_GetHWCodec
函数功能：获取硬件编解码支持名称列表
 参数.一：pStl_ListHWCodec
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的名称
 参数.二：pInt_HWCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出名称个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Help_GetHWCodec(AVCODEC_VIDEO_HWCODEC * **pppSt_ListHWCodec, int* pInt_HWCount);
/********************************************************************
函数名称：VideoCodec_Help_FrameSize
函数功能：获得原始视频每帧大小
 参数.一：nPIXFormat
  In/Out：In
  类型：整数型
  可空：N
  意思：输入视频像素格式
 参数.二：nPIXFormat
  In/Out：In
  类型：整数型
  可空：N
  意思：视频的宽度
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：视频的高度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" int VideoCodec_Help_FrameSize(int nPIXFormat, int nWidth, int nHeight);
/********************************************************************
函数名称：VideoCodec_Help_FrameSeparate
函数功能：分离原始帧数据
 参数.一：nPIXFormat
  In/Out：In
  类型：整数型
  可空：N
  意思：视频采样格式
 参数.二：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：视频的宽
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：视频的高
 参数.四：ptszMSGBuffer
  In/Out：In
  类型：字符指针
  可空：N
  意思：输入要分离的数据
 参数.五：st_MSGBuffers
  In/Out：Out
  类型：数据结构数组
  可空：N
  意思：输出分离的数据
 参数.六：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：分离的数据个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Help_FrameSeparate(int nPIXFormat, int nWidth, int nHeight, uint8_t* ptszMSGBuffer, AVCODEC_VIDEO_MSGBUFFER st_MSGBuffers[4], int* pInt_ListCount);
/********************************************************************
函数名称：VideoCodec_Help_FrameMerge
函数功能：原始帧合并
 参数.一：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出合并的数据缓冲区
 参数.二：pInt_MSGSize
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出合并大小
 参数.三：nPIXFormat
  In/Out：In
  类型：整数型
  可空：N
  意思：视频采样格式
 参数.二：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：视频的宽
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：视频的高
 参数.四：st_MSGBuffers
  In/Out：Out
  类型：数据结构数组
  可空：N
  意思：输出分离的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool VideoCodec_Help_FrameMerge(uint8_t* ptszMSGBuffer, int* pInt_MSGSize, int nPIXFormat, AVCODEC_VIDEO_MSGBUFFER st_MSGBuffers[4]);