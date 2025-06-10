#pragma once
/********************************************************************
//    Created:     2024/02/21  14:08:37
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_Stream\StreamClient_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_Stream
//    File Base:   StreamClient_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     流媒体客户端导出错误
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       实时流推送服务导出错误
//////////////////////////////////////////////////////////////////////////
//原始流推送
#define ERROR_XCLIENT_STREAM_LIVEPUSH_PARAMENT 0x30C0001                  //参数错误
#define ERROR_XCLIENT_STREAM_LIVEPUSH_NOTFOUND 0x30C0002                  //没有找到
#define ERROR_XCLIENT_STREAM_LIVEPUSH_MALLOC 0x30C0003                    //申请内存失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_CONNECTRTMP 0x30C0004               //连接RTMP服务器失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_OPENSTREAM 0x30C0005                //打开流失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_COPYSTREAM 0x30C0006                //拷贝流信息失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_WRITEHDR 0x30C0007                  //写入音视频头失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_WRITETAIL 0x30C0008                 //写入音视频尾失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_SEND 0x30C0009                      //发送给编码器失败,不是标准的数据
#define ERROR_XCLIENT_STREAM_LIVEPUSH_RECV 0x30C0010                      //接受编码数据失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_WRITE 0x30C0011                     //推送数据给服务器失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_FINDENCODEC 0x30C0012               //查找解码器失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_ALLOC 0x30C0013                     //申请上下文失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_NEWSTREAM 0x30C0014                 //新建流失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_OPENCODEC 0x30C0015                 //打开编码器失败
#define ERROR_XCLIENT_STREAM_LIVEPUSH_FILL 0x30C0016                      //填充缓冲区失败
///裸码流推流
#define ERROR_XCLIENT_STREAM_CODECPUSH_PARAMENT 0x30C0101                 //参数错误
#define ERROR_XCLIENT_STREAM_CODECPUSH_MALLOC 0x30C0102                   //申请内存失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_OUTPUT 0x30C0103                   //初始化输出格式失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_CONNECT 0x30C0104                  //连接到流媒体服务失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_NOTFOUND 0x30C0105                 //没有找到
#define ERROR_XCLIENT_STREAM_CODECPUSH_OPEN 0x30C0106                     //打开失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_COPYARGS 0x30C0107                 //拷贝参数失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_WRITEHDR 0x30C0108                 //写入头失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_WRITETAIL 0x30C0109                //写入尾部失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_CLOSE 0x30C0110                    //推流端被关闭
#define ERROR_XCLIENT_STREAM_CODECPUSH_FINDENCODEC 0x30C0111              //查找编解码失败
#define ERROR_XCLIENT_STREAM_CODECPUSH_ALLOC 0x30C0112                    //申请编解码内存失败
//////////////////////////////////////////////////////////////////////////
//                       流获取服务导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCLIENT_STREAM_STREAMPULL_PARAMENT 0x30C2001                //参数错误,初始化失败
#define ERROR_XCLIENT_STREAM_STREAMPULL_MALLOC 0x30C2002                  //申请内存失败
#define ERROR_XCLIENT_STREAM_STREAMPULL_OPENSTREAM 0x30C2003              //打开流失败
#define ERROR_XCLIENT_STREAM_STREAMPULL_FINDSTREAM 0x30C2004              //查找流失败
#define ERROR_XCLIENT_STREAM_STREAMPULL_FILTER 0x30C2005                  //初始化分离器失败
#define ERROR_XCLIENT_STREAM_STREAMPULL_CREATE 0x30C2006                  //创建线程失败
#define ERROR_XCLIENT_STREAM_STREAMPULL_NOTFOUND 0x30C2007                //没有找到
#define ERROR_XCLIENT_STREAM_STREAMPULL_CALLSET 0x30C2008                 //设置回调模式
#define ERROR_XCLIENT_STREAM_STREAMPULL_FAILED 0x30C2009                  //读取失败