#pragma once
/********************************************************************
//	Created:	2019/8/27   15:06
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtpProtocol\RTPProtocol_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtpProtocol
//	File Base:	RTPProtocol_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	RTP协议处理模块头文件
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       导出的枚举型
//////////////////////////////////////////////////////////////////////////
//负载RTP包数据类型
typedef enum en_StreamMedia_RTPProtocol_PayloadType
{
    ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264 = 1,                    //负载类型为H264
    ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H265 = 2,                    //负载为H265
    ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_AAC = 10                     //负载类型为AAC
}ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE;
//NALU类型
typedef enum en_RTPProtocol_NaluType
{
    ENUM_RTPPROTOCOL_NALU_TYPE_RESERVED = 0,                              //保留
    ENUM_RTPPROTOCOL_NALU_TYPE_SINGLE_NALU = 1,                           //单个NAL单元包
    ENUM_RTPPROTOCOL_NALU_TYPE_AREA_A = 2,                                //片分区A
    ENUM_RTPPROTOCOL_NALU_TYPE_AREA_B = 3,                                //片分区B
    ENUM_RTPPROTOCOL_NALU_TYPE_AREA_C = 4,                                //片分区C
    ENUM_RTPPROTOCOL_NALU_TYPE_IDR = 5,                                   //IDR图像中的片
    ENUM_RTPPROTOCOL_NALU_TYPE_SEI = 6,                                   //补充增强信息单元（SEI）
    ENUM_RTPPROTOCOL_NALU_TYPE_SPS = 7,                                   //SPS
    ENUM_RTPPROTOCOL_NALU_TYPE_PPS = 8,                                   //PPS
    ENUM_RTPPROTOCOL_NALU_TYPE_DELIMI = 9,                                //分解符
    ENUM_RTPPROTOCOL_NALU_TYPE_SEQSTOP = 10,                              //序列结束
    ENUM_RTPPROTOCOL_NALU_TYPE_STREAMSTOP = 11,                           //码流结束
    ENUM_RTPPROTOCOL_NALU_TYPE_FILL = 12,                                 //填充
    ENUM_RTPPROTOCOL_NALU_TYPE_RESERV = 23,                               //保留
    //聚合包
    ENUM_RTPPROTOCOL_NALU_TYPE_STAP_A = 24,                               //单时间聚合包类型A
    ENUM_RTPPROTOCOL_NALU_TYPE_STAP_B = 25,                               //单时间聚合包类型B
    ENUM_RTPPROTOCOL_NALU_TYPE_MTAP_16 = 26,                              //多时间聚合包类型(MTAP)16位位移
    ENUM_RTPPROTOCOL_NALU_TYPE_MTAP_24 = 27,                              //多时间聚合包类型(MTAP)24位位移
    //分片单元
    ENUM_RTPPROTOCOL_NALU_TYPE_FU_A = 28,                                 //分片类型A-无DON
    ENUM_RTPPROTOCOL_NALU_TYPE_FU_B = 29                                  //分片类型B
}ENUM_RTPPROTOCOL_NALUTYPE;
//////////////////////////////////////////////////////////////////////////
//                       导出的数据结构
//////////////////////////////////////////////////////////////////////////
//RTP包
typedef struct tag_StreamMedia_RTPProtocol_Packet
{
    int nMsgLen;                                                          //包大小
    XCHAR tszMsgBuffer[2048];                                             //包缓冲区
}STREAMMEDIA_RTPPROTOCOL_PACKET;
//RTP协议
typedef struct tag_StreamMedia_RTPProtocol_Hdr
{
    ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayload;                   //RTP载荷媒体数据类型
    unsigned int unTimeStamp;                                             //媒体采样时间戳
    unsigned int nChannel;                                                //RTP包所属通道,TCP可用
}STREAMMEDIA_RTPPROTOCOL_HDR;
//RTP头扩展
typedef struct tag_RTPProtocol_RTPExtern
{
    XSHOT wRTPExProfile;                                                   //用户定义
    XSHOT wRTPExCount;                                                     //扩展个数
}RTPPROTOCOL_RTPEXTERN;
//////////////////////////////////////////////////////////////////////////
//                       导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG RTPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      打包函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTPProtocol_Packet_Init
函数功能：初始化RTP打包器
 参数.一：pxhSsrc
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出创建的RTP唯一标识符
 参数.二：enPayLoad
  In/Out：In
  类型：枚举型
  可空：Y
  意思：输入初始化的RTP包负载类型
 参数.三：bIsUDP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否负载的UDP,默认为是
 参数.四：nChannel
  In/Out：In
  类型：整数型
  可空：Y
  意思：TCP有效,表示RTP所使用的通道号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_Init(XNETHANDLE *pxhSsrc, ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayLoad = ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264, bool bIsUDP = true, int nChannel = 0);
/********************************************************************
函数名称：RTPProtocol_Packet_SetMode
函数功能：设置RTP模式
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的RPT会话
 参数.二：bIsUDP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否负载的UDP,默认为是
 参数.三：nChannel
  In/Out：In
  类型：整数型
  可空：Y
  意思：TCP有效,表示RTP所使用的通道号
 参数.四：enPayLoad
  In/Out：In
  类型：枚举型
  可空：Y
  意思：负载的RTP包数据类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_SetMode(XNETHANDLE xhSsrc, bool bIsUDP = true, int nChannel = 0, ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayLoad = ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264);
/********************************************************************
函数名称：RTPProtocol_Packet_SetInfo
函数功能：设置参数信息,不设置将无法正常使用
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的RTP包
 参数.二：nFrameRate
  In/Out：In
  类型：整数型
  可空：N
  意思：根据负载类型决定此参数,音频表示采样大小,视频表示帧率
 参数.三：nSampleRate
  In/Out：In
  类型：整数型
  可空：N
  意思：输入采样率
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_SetInfo(XNETHANDLE xhSsrc, int nSampleSize = 25, int nSampleRate = 90000);
/********************************************************************
函数名称：RTPProtocol_Packet_GetRTPTime
函数功能：计算一次RTP时间
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的RTP包
 参数.二：pInt_RTPTime
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出操作后的RTP时间戳
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_GetRTPTime(XNETHANDLE xhSsrc, unsigned int* pInt_RTPTime);
/********************************************************************
函数名称：RTPProtocol_Packet_Destory
函数功能：销毁一个RTP打包器
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要销毁的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_Destory(XNETHANDLE xhSsrc);
/********************************************************************
函数名称：RTPProtocol_Packet_Packet
函数功能：打包一帧数据
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要投递的缓冲区,缓冲区必须为一帧一帧数据.请确保数据的正确性
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要投递缓冲区的大小
 参数.四：pppSt_RTPPacket
  In/Out：Out
  类型：三级指针
  可空：N
  意思：当前NAL单元组装的RTP包,这个内存需要调用基础库的内存释放函数
 参数.五：pInt_PacketCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出RTP包个数
 参数.六：wProfile
  In/Out：In
  类型：无符号短整数型
  可空：Y
  意思：输入扩展头自定义标识符
 参数.七：pppnListExtern
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入扩展数据,这个内存由用户管理
 参数.八：nExternCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入扩展数据个数
返回值
  类型：逻辑型
  意思：是否成功
备注：支持264,265,AAC负载类型
      投递数据后会通过三级指针直接返回一个可发送的RTP包列表
      你可以使用AVHelp_Parse_Frame* 相关函数来解析帧
*********************************************************************/
extern "C" bool RTPProtocol_Packet_Packet(XNETHANDLE xhSsrc, LPCXSTR lpszMsgBuffer, int nMsgLen, STREAMMEDIA_RTPPROTOCOL_PACKET * **pppSt_RTPPacket, int* pInt_PacketCount, XSHOT wProfile = 0, uint32_t * **pppnListExtern = NULL, int nExternCount = 0);
/********************************************************************
函数名称：RTPProtocol_Packet_GetCount
函数功能：获取发送者统计信息
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
 参数.二：pInt_SendPkt
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：发送的包个数
 参数.三：pInt_SendByte
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：发送的数据大小
 参数.四：pInt_Time
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：最后一个发送的包的时间戳
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_GetCount(XNETHANDLE xhSsrc, unsigned int* pInt_SendPkt, unsigned int* pInt_SendByte, unsigned int* pInt_Time);
/************************************************************************/
/*                      打包函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTPProtocol_Parse_Init
函数功能：初始化RTP包解析器
 参数.一：pxhSsrc
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出创建的RTP唯一标识符
 参数.二：enPayLoad
  In/Out：In
  类型：枚举型
  可空：Y
  意思：负载类型
 参数.三：bIsUDP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：协议类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Init(XNETHANDLE *pxhToken, ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayLoad = ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264, bool bIsUDP = true);
/********************************************************************
函数名称：RTPProtocol_Parse_SetMode
函数功能：设置RTP模式
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的RPT会话
 参数.二：bIsUDP
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否负载的UDP,默认为是
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_SetMode(XNETHANDLE xhToken, bool bIsUDP = true);
/********************************************************************
函数名称：RTPProtocol_Parse_Destory
函数功能：销毁一个RTP解析器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要销毁的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Destory(XNETHANDLE xhToken);
/********************************************************************
函数名称：RTPProtocol_Parse_Send
函数功能：投递(发送)一段数据给RTP解析器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要投递的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要投递缓冲区的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：投递的缓冲区应该是一段UDP接受到的完成包,暂不支持沾包处理
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Send(XNETHANDLE xhToken, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTPProtocol_Parse_Recv
函数功能：获取一个完成的RTP包数据
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的数据
 参数.三：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出需要的大小
 参数.四：pSt_RTPHdr
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出RTP协议头信息
 参数.五：pSt_RTPExt
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出RTP扩展头信息
 参数.六：pppnListExtern
  In/Out：Out
  类型：三级指针
  可空：Y
  意思：输出扩展头的扩展信息
 参数.七：pInt_ExternCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出扩展头信息个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数六的内存需要调用基础库的内存释放函数BaseLib_OperatorMemory_Free进行释放内存
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Recv(XNETHANDLE xhToken, XCHAR *ptszMsgBuffer, int *pInt_MsgLen, STREAMMEDIA_RTPPROTOCOL_HDR *pSt_RTPHdr, RTPPROTOCOL_RTPEXTERN *pSt_RTPExt = NULL, uint32_t * **pppnListExtern = NULL, int* pInt_ExternCount = NULL);
/********************************************************************
函数名称：RTPProtocol_Parse_GetCount
函数功能：获取RTP接受统计
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_PktCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出接受到的包个数
 参数.三：pInt_ByteCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出接受到的字节
 参数.四：pInt_BaseTime
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出接受到的最后包的时间戳
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_GetCount(XNETHANDLE xhToken, unsigned int* pInt_PktCount, unsigned int* pInt_ByteCount, unsigned int* pInt_BaseTime);
/************************************************************************/
/*                      帮助函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTPProtocol_Help_GetRTPTime
函数功能：获取一个RTP生成时间
 参数.一：nTimeBase
  In/Out：In
  类型：无符号整数型
  可空：N
  意思：时间基数
 参数.二：pInt_TimeStamp
  In/Out：In
  类型：无符号整数型指针
  可空：N
  意思：导出获取到的时间戳
 参数.三：nFrameRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入音视频帧率
 参数.四：nSampleRate
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入采样率
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Help_GetRTPTime(unsigned int nTimeBase, unsigned int* pInt_TimeStamp, int nFrameRate = 25, int nSampleRate = 44100);
