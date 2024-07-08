#pragma once
/********************************************************************
//    Created:     2024/07/03  10:26:23
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFrame\AVFrame_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFrame
//    File Base:   AVFrame_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     码流帧数据处理导出函数
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的数据结构
//////////////////////////////////////////////////////////////////////////
//帧信息
typedef struct
{
	XBYTE* ptszMsgBuffer;                                                 //获取到的缓冲区,需要通过free释放内存
	int nMsgLen;                                                          //缓冲区大小
}AVFRAME_PARSEDATA;
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AVFrame_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     码流导出函数                                     */
/************************************************************************/
/********************************************************************
函数名称：AVFrame_BITStream_Init
函数功能：初始化一个BIT流转码工具
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出初始化后的流转码句柄
 参数.二：lpszBStreamStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要创建的BITSTREAM码流工具名称,比如:h264_mp4toannexb
返回值
  类型：逻辑型
  意思：是否成功
备注：用于在解封包编码的时候,有些音视频数据不是常规格式需要转义
*********************************************************************/
extern "C" bool AVFrame_BITStream_Init(XNETHANDLE* pxhToken, LPCXSTR lpszBStreamStr);
/********************************************************************
函数名称：AVFrame_BITStream_Stop
函数功能：关闭一个转换器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" bool AVFrame_BITStream_Stop(XNETHANDLE xhToken);
/********************************************************************
函数名称：AVFrame_BITStream_Parameter
函数功能：配置参数
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的转换器
 参数.二：pSt_AVSrcParameters
  In/Out：In
  类型：句柄
  可空：N
  意思：输入原始流参数.通过GetAVCodec得到
 参数.三：pSt_AVDstParameters
  In/Out：In
  类型：句柄
  可空：N
  意思：输入目标流参数,比如要把mp4的h264转义为annexb的h264
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFrame_BITStream_Parameter(XNETHANDLE xhNet, XHANDLE pSt_AVSrcParameters, XHANDLE pSt_AVDstParameters);
/********************************************************************
函数名称：AVFrame_BITStream_Convert
函数功能：转换数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的转换器
 参数.二：lpszMSGBuffer
  In/Out：In
  类型：字符指针
  可空：N
  意思：输入要转换的缓冲区
 参数.三：nMSGLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要转换的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFrame_BITStream_Convert(XNETHANDLE xhNet, uint8_t* lpszMSGBuffer, int nMSGLen);
/************************************************************************/
/*                     帧分析导出函数                                   */
/************************************************************************/
/********************************************************************
函数名称：AVFrame_Frame_ParseInit
函数功能：初始化帧分离器
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出初始化后的句柄
 参数.二：nCodecID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入编码ID,H264,AAC等
返回值
  类型：逻辑型
  意思：是否成功
备注：解析出来的数据是带头的,比如H264 00 00 00 01.
*********************************************************************/
extern "C" bool AVFrame_Frame_ParseInit(XNETHANDLE* pxhToken, int nCodecID);
/********************************************************************
函数名称：AVFrame_Frame_ParseGet
函数功能：解析并且获取一帧
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入操作句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.四：pppSt_Frame
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析好的缓冲区队列
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出队列个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFrame_Frame_ParseGet(XNETHANDLE xhToken, LPCXSTR lpszMsgBuffer, int nMsgLen, AVFRAME_PARSEDATA*** pppSt_Frame, int* pInt_ListCount);
/********************************************************************
函数名称：AVFrame_Frame_ParseClose
函数功能：关闭帧解析器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFrame_Frame_ParseClose(XNETHANDLE xhToken);