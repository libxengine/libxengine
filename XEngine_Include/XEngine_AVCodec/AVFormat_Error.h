#pragma once
/********************************************************************
//    Created:     2024/06/03  10:42:50
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFormat\AVFormat_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFormat
//    File Base:   AVFormat_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     音视频封包格式转换器错误导出
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
////                         解封装
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_PARAMENT 0x80D0000            //参数错误
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_MALLOC 0x80D0001              //申请内存失败
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_NOTFOUND 0x80D0002            //没有找到句柄
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_READ 0x80D0003                //读取媒体数据失败
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_OPENFILE 0x80D0004            //查找文件信息失败
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_CREATE 0x80D0005              //创建目标文件失败,可能不支持
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_NOTSUPPORT 0x80D0006          //不支持的类型
#define ERROR_XENGINE_AVCODEC_FORMAT_UNPACK_SEEK 0x80D0007                //移动媒体索引失败
//////////////////////////////////////////////////////////////////////////
////                         封包管理器
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_MALLOC 0x80D1001              //申请内存失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_NOTFOUND 0x80D1002            //没有找到句柄
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_READ 0x80D1003                //读取媒体数据失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_OPENFILE 0x80D1004            //查找文件信息失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_CREATE 0x80D1005              //创建目标文件失败,可能不支持
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_COPYARGS 0x80D1006            //获取参数失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_WRITEHDR 0x80D1007            //写入视频头失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_THREAD 0x80D1008              //创建线程失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_PARAMENT 0x80D1009            //参数错误
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_SEEK 0x80D1010                //移动媒体索引失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_WRITE 0x80D1011               //写入媒体数据失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_NOTSUPPORT 0x80D1012          //不支持