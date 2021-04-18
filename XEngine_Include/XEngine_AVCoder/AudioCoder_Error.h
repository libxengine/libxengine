#pragma once
/********************************************************************
//	Created:	2012/9/8  12:10
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngien_AvCoder\NetEngine_AudioCoder\NetEngine_AudioCoder\AudioCoder_Error.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngien_AvCoder\NetEngine_AudioCoder\NetEngine_AudioCoder
//	File Base:	AudioCoder_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音频解码器 错误导出文件
//	History:
*********************************************************************/
/************************************************************************/
/*                       实时流编解码错误                                     */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_PARAMENT 0x40A0000     //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_FINDCODER 0x40A0001    //查找编码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOCCODEC 0x40A0002  //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_OPEN 0x40A0003         //打开编码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOCFRAME 0x40A0004  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOCPACKET 0x40A0005 //申请包内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENINIT_MALLOEBUFFER 0x40A0006 //已经初始化过了
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_PARAMENT 0x40A0010    //参数错误,编码失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_NOTFOUND 0x40A0011    //没有找到句柄,无法继续
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_NOTREAD 0x40A0012     //编码器没有准备好
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_AUDIO 0x40A0013       //编码失败,这个包无法编码
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_NOFINISH 0x40A0014    //编码失败,无法处理的包
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_RESAMPLE 0x40A0015    //重采样失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_ENCODEC_MALLOC 0x40A0016      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_PARAMENT 0x40A0020     //参数错误,解码器初始化失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_FINDCODER 0x40A0021    //查找指定解码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_MALLOCCODEC 0x40A0023  //申请解码器内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_OPEN 0x40A0024         //打开解码器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_MALLOCFRAME 0x40A0025  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_MALLOCPACKET 0x40A0026 //申请包内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DEINIT_NOTSUPPORT 0x40A0027   //不支持的类型
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_PARAMENT 0x40A0030    //参数错误,解码失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_NOTFOUND 0x40A0031    //没有找到指定句柄
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_PARSE 0x40A0032       //解析音频包失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_MALLOC 0x40A0033      //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_DECODEC_RESAMPLE 0x40A0034    //重采样失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_PARAMENT 0x40A0050   //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_NOTFOUND 0x40A0051   //没有找到句柄
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_ALLOC 0x40A0052      //初始化内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_INIT 0x40A0053       //初始化参数失败
#define ERROR_XENGINE_AVCODEC_AUDIO_STREAM_RESAMPLE_MALLOC 0x40A0054     //申请内存失败
/************************************************************************/
/*               音频帮助错误                                       */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_GETLIST_PARAMENT 0x40A1000      //参数错误
//过滤器
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_PARAMENT 0x40A1100  //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_MALLOC 0x40A1101    //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_ARGS 0x40A1102      //初始化要混合的原始音频文件失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_MIX 0x40A1103       //混合器初始化失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_SRC 0x40A1104       //初始化原始上下文失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_DST 0x40A1105       //初始化目标上下文失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_LINKMIX 0x40A1106   //关联混合器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_LINKSRC 0x40A1107   //关联原始音频失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_LINKDST 0x40A1108   //关联目标音频失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_INIT_CONFIG 0x40A1109    //确认配置失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_CVT_PARAMENT 0x40A1110   //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_CVT_NOTFOUND 0x40A1111   //没有找到句柄
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_CVT_FRAME 0x40A1112      //初始化音频帧失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_CVT_ADDFRAME 0x40A1112   //添加一帧过滤器到原始数据失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_FILTER_CVT_GETFRAME 0x40A1113   //获取失败
//混合器
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_PARAMENT 0x40A1201     //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_MALLOC 0x40A1202       //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_ARRAY 0x40A1203        //初始化原始音频信息失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_FRAME 0x40A1204        //初始化帧失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_SRC 0x40A1205          //初始化原始过滤器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_FMT 0x40A1206          //初始化格式化过滤器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_DST 0x40A1207          //初始化目标过滤器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_LINKSRC 0x40A1208      //连接原始过滤器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_LINKFMT 0x40A1209      //连接格式化过滤器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_LINKDST 0x40A120A      //连接目标过滤器失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INIT_CONFIG 0x40A120B       //确认配置参数失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INPUT_PARAMENT 0x40A1210    //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INPUT_NOTFOUND 0x40A1211    //没有找到
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INPUT_FRAME 0x40A1212       //混合一帧失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_INPUT_ADDFRAME 0x40A1213    //获取一帧失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_OUTPUT_PARAMENT 0x40A1220   //参数错误
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_OUTPUT_NOTFOUND 0x40A1221   //没有找到
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_OUTPUT_MALLOC 0x40A1222     //申请内存失败
#define ERROR_XENGINE_AVCODEC_AUDIO_HELP_MIX_OUTPUT_GETFRAME 0x40A1223   //获取一帧数据失败
