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
////                         文件格式转换器
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_MALLOC 0x80D0002             //打开待转换的文件失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_NOTFOUND 0x80D0010           //没有找到
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_OPENFILE 0x80D0011           //打开文件失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_STREAMFIND 0x80D0012         //查找流失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_CREATE 0x80D0021             //创建失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_NEWSTREAM 0x80D0032          //创建流失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_COPYARGS 0x80D0033           //拷贝参数失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_WRITEHDR 0x80D0034           //写视频头失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_CREATETHREAD 0x80D0035       //创建线程失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_AVOPEN 0x80D0036             //打开编码器失败
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_PARAMENT 0x80D0040           //获取状态失败,参数错误
#define ERROR_XENGINE_AVCODEC_FORMAT_CONVERT_FAILED 0x80D0061             //定位失败
//////////////////////////////////////////////////////////////////////////
////                         封包管理器
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_MALLOC 0x80D1001              //申请内存失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_NOTFOUND 0x80D1002            //没有找到句柄
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_OPENFILE 0x80D1004            //查找文件信息失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_CREATE 0x80D1005              //创建目标文件失败,可能不支持
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_COPYARGS 0x80D1006            //获取参数失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_WRITEHDR 0x80D1007            //写入视频头失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_THREAD 0x80D1008              //创建线程失败
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_PARAMENT 0x80D1009            //参数错误
#define ERROR_XENGINE_AVCODEC_FORMAT_PACKET_SEEK 0x80D1010                //移动媒体索引失败
//////////////////////////////////////////////////////////////////////////
////                         媒体连接
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_MALLOC 0x80D2002            //申请内存
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_NOTFOUND 0x80D2003          //没有找到
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_OPEN 0x80D2004              //打开失败
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_NOTSTREAM 0x80D2005         //没有流
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_CREATE 0x80D2006            //创建失败
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_COPYARGS 0x80D2007          //拷贝参数错误
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_WRITEHDR 0x80D2008          //写入媒体头失败
#define ERROR_XENGINE_AVCODEC_FORMAT_LINK_THREAD 0x80D2009            //创建线程失败