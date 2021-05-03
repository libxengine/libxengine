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
typedef enum en_NetEngine_AvCoder_VideoFrameType
{
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_NONE = 0,                      //没有定义
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_I,                             //I帧
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_P,                             //P帧，预测
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_B,                             //B帧
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_S,
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_SI,
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_SP,
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_BI,
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_SEI = 100,
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_SPS = 101,
    ENUM_NETENGINE_AVCODER_VIDEO_FRAMETYPE_PPS = 102
}NETENGINE_AVCODER_VIDEOFRAMETYPE, *LPNETENGINE_AVCODER_VIDEOFRAMETYPE;
//想要获得更多编解码器编号,请通过函数VideoCodec_Help_GetList获得
typedef enum en_AvCoder_VedioType
{
    ENUM_ENTENGINE_AVCODEC_VEDIO_TYPE_H264 = 27,
    ENUM_ENTENGINE_AVCODEC_VEDIO_TYPE_H265 = 173
}ENUM_AVCODEC_VEDIOTYPE, *LPENUM_AVCODEC_VEDIOTYPE;
//硬件编解码器
typedef enum en_AVCodec_HWDevice
{
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NONE = 0,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_VDPAU,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_CUDA,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_VAAPI,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_DXVA2,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_QSV,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_VIDEOTOOLBOX,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_D3D11VA,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_DRM,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_OPENCL,
    ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_MEDIACODEC,
}ENUM_NETENGINE_AVCODEC_HWDEVICE;
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    NETENGINE_AVCODER_VIDEOFRAMETYPE en_FrameType;                        //帧的类型

    int nWidth;                                                           //视频宽度
    int nHeight;                                                          //视频高度
    BOOL bKeyFrame;                                                       //是否是关键帧

    __int64x nPts;                                                         //时间戳
    int nRate;                                                            //码率
    int nFrameTimes;                                                      //第几帧
}AVCODEC_VIDEO_INFO,*LPAVCODEC_VIDEO_INFO;
typedef struct
{
    int nCodecType;                                                       //编解码类型
    CHAR tszCodecName[64];                                                //编解码名称
}AVCODEC_VIDEO_CODECLIST, *LPAVCODEC_VIDEO_CODECLIST;
//硬件编解码支持
typedef struct
{
    ENUM_NETENGINE_AVCODEC_HWDEVICE enHWDevice;                           //编解码类型
    CHAR tszHWName[64];                                                   //编解码名称
}AVCODEC_VIDEO_HWCODEC, *LPAVCODEC_VIDEO_HWCODEC;
//////////////////////////////////////////////////////////////////////////
typedef void(CALLBACK *CALLBACK_NETENGINE_AVCODER_VIDEO_STREAM_DECODEC)(XNETHANDLE xhVideo, uint8_t *pszYBuffer, uint8_t *pszUBuffer, uint8_t *pszVBuffer, int nYLen, int nULen, int nVLen, AVCODEC_VIDEO_INFO *pSt_VideoInfo, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                        导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD VideoCoder_GetLastError(int *pInt_SysError = NULL);
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
 参数.二：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：图像宽度
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：图像高度
 参数.四：nAvCoder
  In/Out：In
  类型：枚举型
  可空：N
  意思：选择一个编码器
 参数.五：nBitRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：码率,nRangeRate没有设置表示平均码率ABR
 参数.六：nRangeRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：可变码率范围,如果设置了,那么表示可变码率(VBR)
 参数.七：nFrameRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：视频每秒帧率
 参数.八：nBFrame
  In/Out：In
  类型：整数型
  可空：Y
  意思：B帧间隔,直播流可以关闭减少延迟
 参数.九：enHWDevice
  In/Out：In
  类型：枚举型
  可空：Y
  意思：选择硬件编码器,默认不启用
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：
*********************************************************************/
extern "C" BOOL VideoCodec_Stream_EnInit(XNETHANDLE * pxhNet, int nWidth, int nHeight, ENUM_AVCODEC_VEDIOTYPE nAvCodec, __int64x nBitRate = 500000, __int64x nRangeRate = 0, int nFrameRate = 24, int nBFrame = 0, ENUM_NETENGINE_AVCODEC_HWDEVICE enHWDevice = ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NONE);
/********************************************************************
函数名称：VideoCodec_Stream_EnCodec
函数功能：编码图像
 参数.一：ptszYBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：YUV中的数据缓冲区
 参数.二：ptszYBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：YUV中的数据缓冲区
 参数.三：ptszUBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：YUV中的数据缓冲区
 参数.四：ptszVBuffer
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：YUV中的数据缓冲区
 参数.五：nYLen
  In/Out：In
  类型：整数型
  可空：N
  意思：YUV中的数据缓冲区长度
 参数.六：nULen
  In/Out：In
  类型：整数型
  可空：N
  意思：YUV中的数据缓冲区长度
 参数.七：nVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：YUV中的数据缓冲区长度
 参数.八：ptszBuffer
  In/Out：Out
  类型：字节指针
  可空：N
  意思：导出编码好的数据
 参数.九：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要编码数据长度，输出编码好的数据长度
 参数.十：bKeyFrame
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否编码成关键帧
返回值
  类型：逻辑型
  意思：是否编码成功
备注：U和V参数为NULL,那么Y参数必须传递一整个YUV,nYLen也是YUV大小
      读取一整个YUV的方式是 YUV = 长 * 宽 * 3 / 2
*********************************************************************/
extern "C" BOOL VideoCodec_Stream_EnCodec(XNETHANDLE xhNet, uint8_t *ptszYBuffer, uint8_t *ptszUBuffer, uint8_t *ptszVBuffer, int nYLen, int nULen, int nVLen, uint8_t *ptszBuffer, int *pInt_Len, BOOL bKeyFrame = FALSE);
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
 参数.三：fpCall_StreamFrame
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：解码的时候返回的数据,每调用一次解码函数可能会返回多次PCM数据,所以需要回调来处理
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：解码器回调函数的参数
 参数.五：bCallYuv
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：导出回调数据的方式
 参数.六：enHWDevice
  In/Out：In
  类型：枚举型
  可空：Y
  意思：选择硬件解码器,默认不启用,如果启用将只有Y数据生效
返回值
  类型：逻辑型
  意思：是否成功
备注：bCallYuv为真表示pszYBuffer包含一个完整的YUV,nYLen是完成的大小
      U和V的值是NULL,长度是0,否则的话,他们将分开回调给你
*********************************************************************/
extern "C" BOOL VideoCodec_Stream_DeInit(XNETHANDLE *pxhNet, ENUM_AVCODEC_VEDIOTYPE nAvCodec, CALLBACK_NETENGINE_AVCODER_VIDEO_STREAM_DECODEC fpCall_StreamFrame, LPVOID lParam = NULL, BOOL bCallYuv = TRUE, ENUM_NETENGINE_AVCODEC_HWDEVICE enHWDevice = ENUM_AVCODEC_HWDEVICE_HWDEVICE_TYPE_NONE);
/********************************************************************
函数名称：VideoCodec_Stream_DeCodec
函数功能：解码一个视频帧
 参数.一：pszSourceBuffer
  In/Out：In
  类型：无符号整数指针
  可空：N
  意思：要解码的数据缓冲区地址
 参数.二：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要解码的缓冲区长度
返回值
  类型：逻辑型
  意思：是否成功
备注：解码好的数据通过回调函数返回
*********************************************************************/
extern "C" BOOL VideoCodec_Stream_DeCodec(XNETHANDLE xhNet, uint8_t *pszSourceBuffer, int nLen);
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
  可空：N
  意思：获取到的视频宽度
 参数.三：pInt_Height
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：获取到的视频高度
返回值
  类型：逻辑型
  意思：是否成功
备注：解码用的,只有调用解码后才可以调用这个函数获取
*********************************************************************/
extern "C" BOOL VideoCodec_Stream_GetInfo(XNETHANDLE xhNet, int *pInt_Width, int *pInt_Height);
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
extern "C" BOOL VideoCodec_Stream_Destroy(XNETHANDLE xhNet);
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
备注：参数一和三必须使用基础库的BaseLib_OperatorMemory_Free函数释放内存
*********************************************************************/
extern "C" BOOL VideoCodec_Help_GetList(AVCODEC_VIDEO_CODECLIST * **pppSt_ListEncoder, int* pInt_EncoderCount, AVCODEC_VIDEO_CODECLIST * **pppSt_ListDecoder, int* pInt_DecoderCount);
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
extern "C" BOOL VideoCodec_Help_GetHWCodec(AVCODEC_VIDEO_HWCODEC * **pppSt_ListHWCodec, int* pInt_HWCount);
/********************************************************************
函数名称：VideoCodec_Help_CvtInit
函数功能：初始化转换器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄指针
  可空：N
  意思：导出初始化成功的句柄
 参数.二：nSrcPixFmt
  In/Out：In
  类型：整数型
  可空：N
  意思：输入原始数据格式
 参数.三：nSrcWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输入原始图像宽
 参数.四：nSrcHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：输入原始图像高
 参数.五：nDstPixFmt
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标数据格式
 参数.六：nDstWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标图像宽
 参数.七：nDstHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：输入目标图像高
返回值
  类型：逻辑型
  意思：是否成功
备注：要进行数据转换必须使用此函数进行初始化,只支持原始图像YUV格式转换
*********************************************************************/
extern "C" BOOL VideoCodec_Help_CvtInit(XNETHANDLE *pxhNet, int nSrcPixFmt, int nSrcWidth, int nSrcHeight, int nDstPixFmt, int nDstWidth, int nDstHeight);
/********************************************************************
函数名称：VideoCodec_Help_CvtFmt
函数功能：开始转换一帧数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入转换器句柄
 参数.二：lpszSrcBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始图像数据
 参数.三：ptszDstBuffer
  In/Out：Out
  类型：无符号整数型指针
  可空：N
  意思：导出转换好的数据
 参数.四：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入接受缓冲区大小,输出实际获取到的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：每次解码成功返回的YUV数据都可以进行一次数据转换
*********************************************************************/
extern "C" BOOL VideoCodec_Help_CvtFmt(XNETHANDLE xhNet, LPCSTR lpszSrcBuffer, uint8_t *ptszDstBuffer, int *pInt_Len);
/********************************************************************
函数名称：VideoCodec_Help_CvtDestory
函数功能：销毁一个转换器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要销毁的转换器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL VideoCodec_Help_CvtDestory(XNETHANDLE xhNet);
/********************************************************************
函数名称：VideoCodec_Help_FilterInit
函数功能：初始化过滤器
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的视频过滤器
 参数.二：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要为视频添加的过滤器字符串
 参数.三：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：视频宽度
 参数.四：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：视频高度
 参数.五：en_AVPixForamt
  In/Out：In
  类型：枚举型
  可空：Y
  意思：YUV格式,默认420P
 参数.六：nTimeDen
  In/Out：In
  类型：整数型
  可空：Y
  意思：每秒帧率,默认每秒25帧
返回值
  类型：逻辑型
  意思：是否成功
备注：过滤器只能添加YUV原始数据,过滤器字符串格式使用ffmpeg标准格式.比如添加一段文字
      drawtext=fontfile=Arial.ttf:fontcolor=green:fontsize=30:x=100:y=10:text='www.xyry.org'
      添加一个图片,图片和字库必须让程序找到,否则会失败
      movie=test.png[wm];[in][wm]overlay=10:10,scale=1920:1080[out]
*********************************************************************/
extern "C" BOOL VideoCodec_Help_FilterInit(XNETHANDLE *pxhNet, LPCSTR lpszFilterStr, int nWidth, int nHeight, ENUM_AVCOLLECT_VIDEOSAMPLEFORMAT en_AVPixForamt = ENUM_AVCOLLECT_VIDEO_FMT_YUV420P, int nTimeDen = 25);
/********************************************************************
函数名称：VideoCodec_Help_FilterCvt
函数功能：转换一个原始YUV帧
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：ptszYBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：YUV中的Y
 参数.三：ptszUBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：YUV中的U
 参数.四：ptszVBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：YUV中的V
 参数.五：nYLen
  In/Out：In
  类型：整数型
  可空：N
  意思：Y缓冲区大小
 参数.六：nULen
  In/Out：In
  类型：整数型
  可空：N
  意思：U缓冲区大小
 参数.七：nVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：V缓冲区大小
 参数.八：ptszBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：导出添加过滤器后的YUV数据缓冲区
 参数.九：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出YUV转换后缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：如果YUV是存在一个缓冲区,那么传递给ptszYBuffer和nYLen,其他设置NULL和0即可
*********************************************************************/
extern "C" BOOL VideoCodec_Help_FilterCvt(XNETHANDLE xhNet, uint8_t *ptszYBuffer, uint8_t *ptszUBuffer, uint8_t *ptszVBuffer, int nYLen, int nULen, int nVLen, uint8_t *ptszBuffer, int *pInt_Len);
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
extern "C" BOOL VideoCodec_Help_FilterDestroy(XNETHANDLE xhNet);
