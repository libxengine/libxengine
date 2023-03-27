﻿#pragma once
/********************************************************************
//	Created:	2019/4/11   12:00
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPacket\AVPacket_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPacket
//	File Base:	AVPacket_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音视频封包格式转换器错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
////                         文件格式转换器
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INIT_MALLOC 0x40F0002          //打开待转换的文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_NOTFOUND 0x40F0010       //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_OPENFILE 0x40F0011       //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_STREAMFIND 0x40F0012     //查找流失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_MALLOC 0x40F0013         //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_NOTFOUND 0x40F0020      //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_CREATE 0x40F0021        //创建失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_MALLOC 0x40F0022        //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_OPENFILE 0x40F0023      //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_NOTFOUND 0x40F0030       //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_MALLOC 0x40F0031         //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_NEWSTREAM 0x40F0032      //创建流失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_COPYARGS 0x40F0033       //拷贝参数失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_WRITEHDR 0x40F0034       //写视频头失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_CREATETHREAD 0x40F0035   //创建线程失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_OPEN 0x40F0036           //打开编码器失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_GETSTATUS_PARAMENT 0x40F0040   //获取状态失败,参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_GETSTATUS_NOTFOUND 0x40F0041   //没有找到指定的通道
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_SUSPEND_NOTFOUND 0x40F0050     //没有找到指定句柄
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_SEEK_NOTFOUND 0x40F0060        //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_SEEK_FAILED 0x40F0061          //定位失败
//////////////////////////////////////////////////////////////////////////
////                         封包管理器
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_INIT_MALLOC 0x40F1002       //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_INPUT_NOTFOUND 0x40F1010    //没有找到句柄
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_INPUT_OPEN 0x40F1011        //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_INPUT_NOT 0x40F1012         //查找流失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_INPUT_MALLOC 0x40F1013      //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_INPUT_OPENFILE 0x40F1014    //查找文件信息失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_OUTPUT_NOTFOUND 0x40F1020   //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_OUTPUT_CREATE 0x40F1021     //创建目标文件失败,可能不支持
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_OUTPUT_MALLOC 0x40F1022     //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_OUTPUT_OPENFILE 0x40F1023   //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_START_NOTFOUND 0x40F1030    //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_START_COPYARGS 0x40F1031    //获取参数失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_START_WRITEHDR 0x40F1032    //写入视频头失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_START_THREAD 0x40F1033      //创建线程失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_STATUS_PARAMENT 0x40F1040   //参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_STATUS_NOTFOUND 0x40F1041   //没有找到句柄
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_SUSPEND_NOTFOUND 0x40F1050  //没有找到句柄
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_INIT_MALLOC 0x40F1101       //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_INPUT_NOTFOUND 0x40F1110    //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_INPUT_OPENFILE 0x40F1111    //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_INPUT_NOTSTREAM 0x40F1112   //没有找到媒体流
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_INPUT_MALLOC 0x40F1113      //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OUTPUT_NOTFOUND 0x40F1120   //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OUTPUT_CREATE 0x40F1121    //创建音频输出流失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OUTPUT_OPEN 0x40F1122      //打开失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OUTPUT_MALLOC 0x40F1123    //申请音频内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OUTPUT_COPYARGS 0x40F1124  //拷贝参数失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OUTPUT_WRITEHDR 0x40F1125  //写入媒体头是失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_START_NOTFOUND 0x40F1130    //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_START_THREAD 0x40F1131      //创建线程失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_STATUS_PARAMENT 0x40F1140   //参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_STATUS_NOTFOUND 0x40F1141   //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_SUSPEND_NOTFOUND 0x40F1150  //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_GETLIST_PARAMENT 0x40F1160  //参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_GETLIST_NOTFOUND 0x40F1161  //没有找到
//////////////////////////////////////////////////////////////////////////
////                         媒体连接
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_MALLOC 0x40F2002            //申请内存
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_NOTFOUND 0x40F2003          //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_OPEN 0x40F2004              //打开失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_NOTSTREAM 0x40F2005         //没有流
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_CREATE 0x40F2006            //创建失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_COPYARGS 0x40F2007          //拷贝参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_WRITEHDR 0x40F2008          //写入媒体头失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_THREAD 0x40F2009            //创建线程失败