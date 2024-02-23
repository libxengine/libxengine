#pragma once
/********************************************************************
//    Created:     2023/12/05  15:41:05
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFilter\AVFilter_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFilter
//    File Base:   AVFilter_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     媒体特效处理模块
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       音频错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_PARAMENT 0x80F0001             //参数错误
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_MALLOC 0x80F0002               //申请内存失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_CREATE 0x80F0003               //创建过滤器失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_PARSE 0x80F0004                //解析过滤器失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_CONFIG 0x80F0005               //确认配置失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_NOTFOUND 0x80F0006             //没有找到
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_FRAME 0x80F0007                //处理帧失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_ADDFRAME 0x80F0008             //投递帧失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_GETFRAME 0x80F0009             //获取帧失败
#define ERROR_XENGINE_AVCODEC_FILTER_AUDIO_LINK 0x80F000A                 //链接过滤器失败
//////////////////////////////////////////////////////////////////////////
//                       视频错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_PARAMENT 0x80F1001             //参数错误
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_MALLOC 0x80F1002               //申请内存失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_SRCCREATE 0x80F1003            //创建原始数据区域失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_DSTCREATE 0x80F1004            //创建目标数据区域失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_PARSE 0x80F1005                //设置失败,参数错误
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_CHECK 0x80F1006                //检查失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_NOTFOUND 0x80F1007             //查找失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_ADDFRAME 0x80F1008             //添加帧失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_GETFRAME 0x80F1009             //获取帧失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_LEN 0x80F1010                  //大小不正确
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_FAILED 0x80F1011               //处理失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_DSTLINK 0x80F1012              //原始特效链接失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_FILTER 0x80F1013               //滤镜创建失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_FILTERLINK 0x80F1014           //特效链接失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_OUTLINK 0x80F1015              //输出滤镜链接失败
#define ERROR_XENGINE_AVCODEC_FILTER_VIDEO_FMTLINK 0x80F1016              //输出格式滤镜链接失败