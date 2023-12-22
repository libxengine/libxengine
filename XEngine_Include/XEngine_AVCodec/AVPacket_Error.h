#pragma once
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
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INIT_MALLOC 0x80D0002          //打开待转换的文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_NOTFOUND 0x80D0010       //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_OPENFILE 0x80D0011       //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_STREAMFIND 0x80D0012     //查找流失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_INPUT_MALLOC 0x80D0013         //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_NOTFOUND 0x80D0020      //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_CREATE 0x80D0021        //创建失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_MALLOC 0x80D0022        //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_OUTPUT_OPENFILE 0x80D0023      //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_NOTFOUND 0x80D0030       //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_MALLOC 0x80D0031         //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_NEWSTREAM 0x80D0032      //创建流失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_COPYARGS 0x80D0033       //拷贝参数失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_WRITEHDR 0x80D0034       //写视频头失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_CREATETHREAD 0x80D0035   //创建线程失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_START_OPEN 0x80D0036           //打开编码器失败
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_GETSTATUS_PARAMENT 0x80D0040   //获取状态失败,参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_GETSTATUS_NOTFOUND 0x80D0041   //没有找到指定的通道
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_SUSPEND_NOTFOUND 0x80D0050     //没有找到指定句柄
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_SEEK_NOTFOUND 0x80D0060        //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_CONVERT_SEEK_FAILED 0x80D0061          //定位失败
//////////////////////////////////////////////////////////////////////////
////                         封包管理器
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_MALLOC 0x80D1001       //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_NOTFOUND 0x80D1002     //没有找到句柄
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_OPEN 0x80D1003         //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_NOT 0x80D1004          //查找流失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_OPENFILE 0x80D1005     //查找文件信息失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_CREATE 0x80D1006       //创建目标文件失败,可能不支持
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_COPYARGS 0x80D1007     //获取参数失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_WRITEHDR 0x80D1008     //写入视频头失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_THREAD 0x80D1009       //创建线程失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEPACKET_PARAMENT 0x80D1010     //参数错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_MALLOC 0x80D1101       //申请内存失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_NOTFOUND 0x80D1101     //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_OPENFILE 0x80D1102     //打开文件失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_NOTSTREAM 0x80D1103    //没有找到媒体流
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_CREATE 0x80D1104       //创建音频输出流失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_COPYARGS 0x80D1105     //拷贝参数失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_WRITEHDR 0x80D1106     //写入媒体头是失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_THREAD 0x80D1107       //创建线程失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_PARAMENT 0x80D1108     //参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_FILEUNPACK_SEEK 0x80D1109         //移动媒体索引失败
//////////////////////////////////////////////////////////////////////////
////                         媒体连接
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_MALLOC 0x80D2002            //申请内存
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_NOTFOUND 0x80D2003          //没有找到
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_OPEN 0x80D2004              //打开失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_NOTSTREAM 0x80D2005         //没有流
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_CREATE 0x80D2006            //创建失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_COPYARGS 0x80D2007          //拷贝参数错误
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_WRITEHDR 0x80D2008          //写入媒体头失败
#define ERROR_XENGINE_AVCODEC_PACKET_FILELINK_THREAD 0x80D2009            //创建线程失败