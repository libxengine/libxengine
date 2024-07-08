#pragma once
/********************************************************************
//    Created:     2024/07/03  10:24:08
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFrame\AVFrame_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFrame
//    File Base:   AVFrame_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     导出的码流处理错误
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       码流错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_PARAMENT 0x801A0001         //参数错误
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_MALLOC 0x801A0002           //申请内存失败
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_FILTER 0x801A0003           //初始化过滤器失败
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_NOTFOUND 0x801A0004         //没有找到
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_COPY 0x801A0005             //拷贝参数失败
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_INIT 0x801A0006             //初始化失败
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_SEND 0x801A0007             //发送数据失败，数据错误
#define ERROR_XENGINE_AVCODEC_FRAME_BITSTREAM_RECV 0x801A0008             //获取数据失败
//////////////////////////////////////////////////////////////////////////
//                       媒体解析错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FRAME_FRAME_PARAMENT 0x801A1001             //参数错误
#define ERROR_XENGINE_AVCODEC_FRAME_FRAME_NOTFOUND 0x801A1002             //没有找到NALU单元
#define ERROR_XENGINE_AVCODEC_FRAME_FRAME_MALLOC 0x801A1003               //申请内存失败
#define ERROR_XENGINE_AVCODEC_FRAME_FRAME_INIT 0x801A1004                 //初始化解析器失败