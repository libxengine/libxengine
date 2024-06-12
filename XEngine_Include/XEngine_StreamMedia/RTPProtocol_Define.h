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
函数名称：RTPProtocol_Packet_Insert
函数功能：插入一个客户端到RTP包管理器中
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
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
extern "C" bool RTPProtocol_Packet_Insert(LPCXSTR lpszClientID, ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayLoad = ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264, bool bIsUDP = true, int nChannel = 0);
/********************************************************************
函数名称：RTPProtocol_Packet_Delete
函数功能：从RTP包管理器中删除一个客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RTPProtocol_Packet_SetMode
函数功能：设置RTP模式
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
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
extern "C" bool RTPProtocol_Packet_SetMode(LPCXSTR lpszClientID, bool bIsUDP = true, int nChannel = 0, ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayLoad = ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264);
/********************************************************************
函数名称：RTPProtocol_Packet_SetPType
函数功能：单独设置PAYLOAD负载类型
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：nPType
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要设置的类型
返回值
  类型：逻辑型
  意思：是否成功
备注：某些RTP通信的H264负载类型是不一样的,可以通过此函数单独设置
*********************************************************************/
extern "C" bool RTPProtocol_Packet_SetPType(LPCXSTR lpszClientID, int nPType);
/********************************************************************
函数名称：RTPProtocol_Packet_SetTime
函数功能：设置RTP时间戳,由系统自动计算
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
 参数.二：nFrameRate
  In/Out：In
  类型：整数型
  可空：N
  意思：根据负载类型决定此参数,音频表示采样大小,视频表示帧率
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_SetTime(LPCXSTR lpszClientID, int nFrameRate);
/********************************************************************
函数名称：RTPProtocol_Packet_GetTime
函数功能：获取当前RTP时间戳
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
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
extern "C" bool RTPProtocol_Packet_GetTime(LPCXSTR lpszClientID, unsigned int* pInt_RTPTime);
/********************************************************************
函数名称：RTPProtocol_Packet_GetCSeq
函数功能：获取当前CSEQ
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
 参数.二：pInt_CSeqeue
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出包序列号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_GetCSeq(LPCXSTR lpszClientID, unsigned int* pInt_CSeqeue);
/********************************************************************
函数名称：RTPProtocol_Packet_SSRCSet
函数功能：设置RTP包的SSRC唯一标识符
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：nSSRCValue
  In/Out：In
  类型：整数型
  可空：N
  意思：输入SSRC值
返回值
  类型：逻辑型
  意思：是否成功
备注：如果不设置,将默认使用lpszClientID的值
*********************************************************************/
extern "C" bool RTPProtocol_Packet_SSRCSet(LPCXSTR lpszClientID, unsigned int nSSRCValue);
/********************************************************************
函数名称：RTPProtocol_Packet_SSRCGet
函数功能：获取RTP的SSRC标识符
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：pInt_nSSRCValue
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出SSRC值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Packet_SSRCGet(LPCXSTR lpszClientID, unsigned int* pInt_nSSRCValue);
/********************************************************************
函数名称：RTPProtocol_Packet_Packet
函数功能：打包一帧数据
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
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
extern "C" bool RTPProtocol_Packet_Packet(LPCXSTR lpszClientID, LPCXSTR lpszMsgBuffer, int nMsgLen, STREAMMEDIA_RTPPROTOCOL_PACKET * **pppSt_RTPPacket, int* pInt_PacketCount, XSHOT wProfile = 0, uint32_t * **pppnListExtern = NULL, int nExternCount = 0);
/********************************************************************
函数名称：RTPProtocol_Packet_GetCount
函数功能：获取发送者统计信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端句柄
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
extern "C" bool RTPProtocol_Packet_GetCount(LPCXSTR lpszClientID, unsigned int* pInt_SendPkt, unsigned int* pInt_SendByte, unsigned int* pInt_Time);
/************************************************************************/
/*                      打包函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：RTPProtocol_Parse_Init
函数功能：初始化RTP包解析器
 参数.一：nPoolCount
  In/Out：In
  类型：整数型
  可空：N
  意思：可用分布式事件队列个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Init(int nPoolCount);
/********************************************************************
函数名称：RTPProtocol_Parse_Destory
函数功能：销毁一个RTP解析器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Destory();
/********************************************************************
函数名称：RTPProtocol_Parse_Insert
函数功能：插入一个客户端到包解析器中
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
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
extern "C" bool RTPProtocol_Parse_Insert(LPCXSTR lpszClientID, ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOADTYPE enPayLoad = ENUM_STREAMMEDIA_RTPPROTOCOL_PAYLOAD_TYPE_H264, bool bIsUDP = true);
/********************************************************************
函数名称：RTPProtocol_Parse_Delete
函数功能：删除一个RTP客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RTPProtocol_Parse_Send
函数功能：投递(发送)一段数据给RTP解析器
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
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
extern "C" bool RTPProtocol_Parse_Send(LPCXSTR lpszClientID, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTPProtocol_Parse_Recv
函数功能：获取一个完成的RTP包数据
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
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
extern "C" bool RTPProtocol_Parse_Recv(LPCXSTR lpszClientID, XCHAR *ptszMsgBuffer, int *pInt_MsgLen, STREAMMEDIA_RTPPROTOCOL_HDR *pSt_RTPHdr, RTPPROTOCOL_RTPEXTERN *pSt_RTPExt = NULL, uint32_t * **pppnListExtern = NULL, int* pInt_ExternCount = NULL);
/********************************************************************
函数名称：RTPProtocol_Parse_GetCount
函数功能：获取RTP接受统计
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
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
extern "C" bool RTPProtocol_Parse_GetCount(LPCXSTR lpszClientID, unsigned int* pInt_PktCount, unsigned int* pInt_ByteCount, unsigned int* pInt_BaseTime);
/********************************************************************
函数名称：RTPProtocol_Parse_GetPool
函数功能：通过任务池获取可处理的列表
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要处理的索引
 参数.二：pppSt_ListAddr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出待处理的列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：指数型指针
  可空：N
  意思：导出列表的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_GetPool(int nPoolIndex, XENGINE_MANAGEPOOL_TASKEVENT*** pppSt_ListAddr, int* pInt_ListCount);
/************************************************************************
函数名称：RTPProtocol_Parse_WaitEvent
函数功能：等待一个数据事件发生
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布式池索引
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位毫秒 -1 不超时,0立即返回 > 0等待事件
返回值
  类型：逻辑型
  意思：是否等待成功
备注：
************************************************************************/
extern "C" bool RTPProtocol_Parse_WaitEvent(int nPoolIndex, int nTimeOut = -1);
/********************************************************************
函数名称：RTPProtocol_Parse_ActiveEvent
函数功能：手动触发一次事件
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布池索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTPProtocol_Parse_ActiveEvent(int nPoolIndex);