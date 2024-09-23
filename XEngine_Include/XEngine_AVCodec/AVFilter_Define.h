#pragma once
/********************************************************************
//	Created:	2017/5/4   10:39
//	Filename: 	P:\NetEngine_Windows\NetEngine_SourceCode\NetEngien_AvCoder\NetEngine_AVHelp\AVHelp_Define.h
//	File Path:	P:\NetEngine_Windows\NetEngine_SourceCode\NetEngien_AvCoder\NetEngine_AVHelp
//	File Base:	AVHelp_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音视频编解码帮助模块导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
	XCHAR tszFilterName[64];                                              //滤镜名称
	int nSampleFmt;                                                       //采样格式
	int nSampleRate;                                                      //采样率
	int nNBSample;                                                        //样本数
	int nChannle;                                                         //通道个数
	int nIndex;                                                           //索引，从0开始传入，不可重复,混合器才有用
	bool bFilterEnable;                                                   //是否启用音频内滤镜
}AVFILTER_AUDIO_INFO, * LPAVFILTER_AUDIO_INFO;
typedef struct
{
	XCHAR tszFilterName[64];                                              //滤镜名称
	int nWidth;                                                           //宽
	int nHeight;                                                          //高
	int nFrame;                                                           //帧率
	int enAVPixForamt;                                                    //采样格式
	int nIndex;
}AVFILTER_VIDEO_INFO, * LPAVFILTER_VIDEO_INFO;
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AVFilter_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     音频滤镜导出函数                                 */
/************************************************************************/
/********************************************************************
函数名称：AVFilter_Audio_Init
函数功能：初始化过滤器
 参数.一：pxhToken
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的音频过滤器
 参数.二：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：转换后的目标过滤器,可以和原始的一样
 参数.三：pSt_AudioFilter
  In/Out：In
  类型：数据结构体指针
  可空：N
  意思：输入原始音频参数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二为目标格式,为字符串,参数通过:分割,有很多滤镜可以通过FFMPEG得到
	  比如音量volume=2.0 就是双倍音量.调整播放速度asetrate=44100*1.5,44100是采样率等等
*********************************************************************/
extern "C" bool AVFilter_Audio_Init(XNETHANDLE* pxhToken, LPCXSTR lpszFilterStr, AVFILTER_AUDIO_INFO* pSt_AudioFilter);
/********************************************************************
函数名称：AVFilter_Audio_Cvt
函数功能：进行一帧的转换
 参数.一：xhToken
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
  意思：转换后的数据缓冲区
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
extern "C" bool AVFilter_Audio_Cvt(XNETHANDLE xhToken, uint8_t* ptszSrcBuffer, int nSrcLen, uint8_t* ptszDstBuffer, int* pInt_DstLen);
/********************************************************************
函数名称：AVFilter_Audio_Destroy
函数功能：销毁一个过滤器资源
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Audio_Destroy(XNETHANDLE xhToken);
/********************************************************************
函数名称：AVFilter_Audio_MIXInit
函数功能：初始化音频混合器
 参数.一：pxhToken
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的音频过滤器
 参数.二：pppSt_ListFile
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要混合的音频文件和参数,内存由调用者维护
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要混合的音频文件和参数
 参数.四：lpszFilterName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入音频滤镜的输出滤镜别名
 参数.四：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入音频滤镜的输出滤镜字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：混合器能实现一个或者多个过滤器和音频文件附加混合
*********************************************************************/
extern "C" bool AVFilter_Audio_MIXInit(XNETHANDLE * pxhToken, AVFILTER_AUDIO_INFO * **pppSt_ListFile, int nListCount, LPCXSTR lpszFilterName, LPCXSTR lpszFilterStr);
/********************************************************************
函数名称：AVFilter_Audio_MIXSend
函数功能：进行一帧的混合
 参数.一：xhToken
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
extern "C" bool AVFilter_Audio_MIXSend(XNETHANDLE xhToken, int nIndex, uint8_t* ptszSrcBuffer, int nSrcLen);
/********************************************************************
函数名称：AVFilter_Audio_MIXRecv
函数功能：把混合的数据输出
 参数.一：xhToken
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
extern "C" bool AVFilter_Audio_MIXRecv(XNETHANDLE xhToken, uint8_t* ptszDstBuffer, int* pInt_DstLen);
/********************************************************************
函数名称：AVFilter_Audio_MIXDestroy
函数功能：销毁一个混合器资源
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Audio_MIXDestroy(XNETHANDLE xhToken);
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：AVFilter_Video_Init
函数功能：初始化过滤器
 参数.一：pxhToken
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的视频过滤器
 参数.二：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要为视频添加的过滤器字符串
 参数.三：pSt_VideoInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入原始YUV信息
返回值
  类型：逻辑型
  意思：是否成功
备注：过滤器可以自己设置,比如调整亮度和对比度,可以填写字符串:eq=brightness=1.5:contrast=1.2
*********************************************************************/
extern "C" bool AVFilter_Video_Init(XNETHANDLE* pxhToken, LPCXSTR lpszFilterStr, AVFILTER_VIDEO_INFO * pSt_VideoInfo);
/********************************************************************
函数名称：AVFilter_Video_Cvt
函数功能：转换一个原始帧
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：ptszAVBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：视频缓冲区
 参数.三：nAVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.四：ptszBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：导出添加过滤器后的YUV数据缓冲区
 参数.五：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出转换后缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Video_Cvt(XNETHANDLE xhToken, uint8_t* ptszAVBuffer, int nAVLen, uint8_t* ptszBuffer, int* pInt_Len);
/********************************************************************
函数名称：AVFilter_Video_Destroy
函数功能：销毁一个过滤器资源
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Video_Destroy(XNETHANDLE xhToken);
/********************************************************************
函数名称：AVFilter_Video_MIXInit
函数功能：多路视频混流器初始化
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：过滤器句柄
 参数.二：pppSt_VideoFilter
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入原始流信息
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入原始流个数
 参数.四：lpszFilterName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入过滤器输出名称
 参数.五：lpszFilterStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入过滤器字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Video_MIXInit(XNETHANDLE* pxhToken, AVFILTER_VIDEO_INFO*** pppSt_VideoFilter, int nListCount, LPCXSTR lpszFilterName, LPCXSTR lpszFilterStr);
/********************************************************************
函数名称：AVFilter_Video_MIXSend
函数功能：发送一个原始数据给滤镜
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：nIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的索引
 参数.三：ptszAVBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：视频缓冲区
 参数.四：nAVLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Video_MIXSend(XNETHANDLE xhToken, int nIndex, uint8_t* ptszAVBuffer, int nAVLen);
/********************************************************************
函数名称：AVFilter_Video_MIXRecv
函数功能：接受处理好的滤镜原始数据
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的过滤器句柄
 参数.二：ptszBuffer
  In/Out：In
  类型：无符号字符指针
  可空：N
  意思：导出添加过滤器后的数据缓冲区
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出转换后缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Video_MIXRecv(XNETHANDLE xhToken, uint8_t* ptszBuffer, int* pInt_Len);
/********************************************************************
函数名称：AVFilter_Video_MIXDestroy
函数功能：销毁一个混流器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的混流器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFilter_Video_MIXDestroy(XNETHANDLE xhToken);