#pragma once
/********************************************************************
//	Created:	2017/5/4   12:25
//	Filename: 	P:\NetEngine_Windows\NetEngine_SourceCode\NetEngien_AvCoder\NetEngine_AVHelp\AVHelp_Error.h
//	File Path:	P:\NetEngine_Windows\NetEngine_SourceCode\NetEngien_AvCoder\NetEngine_AVHelp
//	File Base:	AVHelp_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音视频帮助模块导出错误定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       获取设备列表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVHELP_DEVICE_ENUM_CREATEINS 0x80C0030    //创建失败
#define ERROR_XENGINE_AVCODEC_AVHELP_DEVICE_ENUM_CLASS 0x80C0031        //枚举类别失败
#define ERROR_XENGINE_AVCODEC_AVHELP_DEVICE_ENUM_GETDES 0x80C0032       //获取描述失败
#define ERROR_XENGINE_AVCODEC_AVHELP_DEVICE_ENUM_GETNAME 0x80C0033      //获取名称失败
#define ERROR_XENGINE_AVCODEC_AVHELP_DEVICE_ENUM_GETPATH 0x80C0034      //获取设备路径失败
//////////////////////////////////////////////////////////////////////////
//                       媒体信息错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GET_PARAMENT 0x80C1001    //参数错误,无法继续
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GET_OPENFILE 0x80C1002    //打开文件失败,可能不是标准的音视频文件
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GET_FINDSTREAM 0x80C1003  //没有找到指定的媒体信息
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GET_ATTPIC 0x80C1004      //获取封面图片失败，提供的缓冲区太小
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_SET_PARAMENT 0x80C1010    //设置失败,参数错误
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_SET_OPENSRCFILE 0x80C1011 //打开原始文件失败
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_SET_FINDSTREAM 0x80C1012  //查找文件音视频流失败
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_SET_OPENDSTFILE 0x80C1013 //打开目标文件失败
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_SET_IOOPEN 0x80C1015      //打开文件IO失败
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_SET_WRITEHDR 0x80C1016    //写入视频头失败
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GETSTREAM_PARAMENT 0x80C1020     //获取流信息失败,参数错误
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GETSTREAM_OPENFILE 0x80C1021     //打开文件失败
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GETSTREAM_NOTSTREAM 0x80C1022    //没有找到可用流信息
#define ERROR_XENGINE_AVCODEC_AVHELP_METAINFO_GETSTREAM_NOTSUPPORT 0x80C1023   //不支持
//////////////////////////////////////////////////////////////////////////
//                       媒体解析错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVHELP_PARSE_PARAMENT 0x80C2001             //参数错误
#define ERROR_XENGINE_AVCODEC_AVHELP_PARSE_NOTFOUND 0x80C2002             //没有找到NALU单元
#define ERROR_XENGINE_AVCODEC_AVHELP_PARSE_NOTAAC 0x80C2031               //没有找到AAC头信息
#define ERROR_XENGINE_AVCODEC_AVHELP_PARSE_PROFILE 0x80C2032              //获取属性级别失败
#define ERROR_XENGINE_AVCODEC_AVHELP_PARSE_SAMPLE 0x80C2033               //获取采样率失败
//////////////////////////////////////////////////////////////////////////
//                       媒体封装错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_AVHELP_PACKET_PARAMENT 0x80C3001            //参数错误
#define ERROR_XENGINE_AVCODEC_AVHELP_PACKET_NOTSUPPORT 0x80C3002          //不支持的类型