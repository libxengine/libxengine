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
//RTCP包类型
typedef enum en_StreamMedia_RTCPProtocol_PacketType
{
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_FIR = 192,                   //关键帧请求
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_NACK = 193,                  //丢包重传
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_SMPTETC = 194,               //RFC5484
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_IJ = 195,                    //RFC5450
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_SR = 200,                    //发送端报告
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_RR = 201,                    //接收端报告
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_SDES = 202,                  //源点描述
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_BYE = 203,                   //结束传输
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_APP = 204,                   //特定应用
	ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_RTPFB = 205,                 //传输和编码相关的反馈
	ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_PSFB = 206,                  //编解码器（或负载）的问题和调整
	ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_XR = 207                     //扩展报告消息
}ENUM_STREAMMEDIA_RTCPPROTOCOL_PAYLOADTYPE;
//RTCP描述包类型
typedef enum en_StreamMedia_RTCPProtocol_SdesType
{
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_CNAME = 1,                     //CNAME,计算机名
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_NAME = 2,                      //用户名
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_EMAIL = 3,                     //电子邮件地址
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_PHONE = 4,                     //电话号码
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_LOCAL = 5,                     //地址位置
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_TOOL = 6,                      //应用名称或者版本
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_NOTE = 7,                      //通知
    ENUM_STREAMMEDIA_RTCPPROTOCOL_SDES_TYPE_PRIV = 8                       //自定义扩展
}ENUM_STREAMMEDIA_RTCPPROTOCOL_SDESTYPE;
//////////////////////////////////////////////////////////////////////////
//                       导出的结构体
//////////////////////////////////////////////////////////////////////////
#pragma pack(push)
#pragma pack(1)
//RTCP报告协议头,8个字节
typedef struct 
{
	XBYTE byRtcpCount : 5;            //接收或发送报告计数器
	XBYTE byRtcpPadding : 1;          //载荷之后填充数据，用于要求固定长度RTP包场景，一般不用，设置为0
	XBYTE byRtcpVersion : 2;          //当前版本设为2

	XBYTE byPT;                       //包类型,使用ENUM_STREAMMEDIA_RTCPPROTOCOL_PAYLOADTYPE
	XSHOT wLen;                       //长度域,其中存放的是该SR包以32比特为单位的总长度减一
	uint32_t unSsrc;                  //用于标识同步信源,因为每个包都有
}RTCPPROTOCOL_RTCPHDR;
/*发送者信息,20字节长,在每个发送者报告包中出现。它概括了从此发送者发出的数据传输情况
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
header |V=2|P|    RC   |   PT=SR=200   |             length            |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                         SSRC of sender                        |
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
sender |              NTP timestamp, most significant word             |
info   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |             NTP timestamp, least significant word             |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                         RTP timestamp                         |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                     sender's packet count                     |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                      sender's octet count                     |
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
report |                 SSRC_1 (SSRC of first source)                 |
block  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  1    | fraction lost |       cumulative number of packets lost       |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |           extended highest sequence number received           |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                      interarrival jitter                      |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                         last SR (LSR)                         |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                   delay since last SR (DLSR)                  |
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
report |                 SSRC_2 (SSRC of second source)                |
block  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  2    :                               ...                             :
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
       |                  profile-specific extensions                  |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
typedef struct
{
    uint32_t ullNTPMsbTime;          //表示发送此报告时以挂钟时间测量的时间点。 结合来自各个接收器的接收报告中返回的时间戳，它可用于估计往返于接收器的往返传播时间
    uint32_t ullNTPLsbTime;
    uint32_t unRTPTime;              //RTP时间戳,与以上的NTP时间标志对应同一时刻。与数据包中的 RTP 时间戳具有相同的单位和偏移量
    uint32_t unPktCount;             //发送的报文数,从开始传输到此SR包产生时该发送者发送的 RTP 数据包总数
    uint32_t unByteCount;            //发送的字节文数,从开始传输到此 SR 包产生时该发送者在 RTP 数据包发送的字节总数(不包括头和填充)。
}RTCPPROTOCOL_RTCPSENDER;
/*零到多个接收报告块,块数等于从上一个报告以来该发送者侦听到的其它源（不包括自身）的数目。每个接收报告块传输从某个同步源来的数据包的接收统计信息
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
header |V=2|P|    RC   |   PT=RR=201   |             length            |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                     SSRC of packet sender                     |
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
report |                 SSRC_1 (SSRC of first source)                 |
block  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  1    | fraction lost |       cumulative number of packets lost       |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |           extended highest sequence number received           |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                      interarrival jitter                      |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                         last SR (LSR)                         |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       |                   delay since last SR (DLSR)                  |
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
report |                 SSRC_2 (SSRC of second source)                |
block  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  2    :                               ...                             :
       +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
       |                  profile-specific extensions                  |
       +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
typedef struct
{
    uint32_t unSsrc;                 //在此接收报告块中信息所属源的 SSRC 标识符
    uint32_t unLostPacket : 24;      //丢包数,从源 SSRC_n 发到本源的 RTP 数据包的丢包总数=期望接收的包数－实际接收的包数,如果是16777215 表示-1
    uint32_t unLostRate : 8;         //丢包率,自从前一 SR 包或 RR 包发送以来，从 SSRC_n 传来的 RTP 数据包的丢失比例=损失包数／期望接收的包数
    uint32_t unExtCountHigh : 16;    //接收到的扩展的最高序列号,高 16 比特用相应的序列号周期计数器扩展该序列号
    uint32_t unExtCountLow : 16;     //低 16 比特包含从源 SSRC_n 来的最高接收序列号
    uint32_t unIntJitter;            //到达间隔抖动
    uint32_t unLastSr;               //上一SR报文,接收到的来自源 SSRC_n 的最新 RTCP 发送者报告(SR)的 64 位 NTP 时间标志的中间 32 位
    uint32_t unDelaySr;              //自上一SR的时间,是从收到来自 SSRC_n 的 SR 包到发送此接收报告块之间的延时，以 1/65536 秒为单位。若还未收到来自 SSRC_n 的 SR 包，该域值为零
}RTCPPROTOCOL_RTCPRECVER;
//描述信息
typedef struct
{
	XCHAR tszMSGBuffer[MAX_PATH];
	uint32_t nMLen;
	uint32_t xhSsrc;
	ENUM_STREAMMEDIA_RTCPPROTOCOL_SDESTYPE enSDESType;
}STREAMMEDIA_RTCPPROTOCOL_SDESINFO;
#pragma pack(pop)
//////////////////////////////////////////////////////////////////////////
//                       导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG RTCPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      协议打包类导出                                  */
/************************************************************************/	
/********************************************************************
函数名称：RTCPProtocol_Packet_Sender
函数功能：发送者报告包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：xhSsrc
  In/Out：In
  类型：整数型
  可空：N
  意思：发送源标志SSRC
 参数.四：pSt_SendInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要发送的发送者报告信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Packet_Sender(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, uint32_t xhSsrc, RTCPPROTOCOL_RTCPSENDER * pSt_SendInfo);
/********************************************************************
函数名称：RTCPProtocol_Packet_Recver
函数功能：接受者服务打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：xhSsrc
  In/Out：In
  类型：整数型
  可空：N
  意思：SSRC标识符
 参数.四：pSt_RecvInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Packet_Recver(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, uint32_t xhSsrc, RTCPPROTOCOL_RTCPRECVER * pSt_RecvInfo);
/********************************************************************
函数名称：RTCPProtocol_Packet_Sdeser
函数功能：描述信息打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pppSt_SDESList
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要打包的描述列表
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Packet_Sdeser(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, STREAMMEDIA_RTCPPROTOCOL_SDESINFO * **pppSt_SDESList, int nListCount);
/********************************************************************
函数名称：RTCPProtocol_Packet_Goodbye
函数功能：打包结束消息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出缓冲区大小
 参数.三：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：SSRC
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Packet_Goodbye(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, uint32_t xhSsrc);
/********************************************************************
函数名称：RTCPProtocol_Packet_App
函数功能：APP特定消息打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出缓冲区大小
 参数.三：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：SSRC
 参数.四：byName
  In/Out：In
  类型：字符数组
  可空：N
  意思：打包的应用名称
 参数.五：lpszDatas
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要打包的数据
 参数.六：nDLen
  In/Out：In
  类型：字符数组
  可空：N
  意思：打包的数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Packet_App(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, uint32_t xhSsrc, XBYTE byName[4], LPCXSTR lpszDatas, int nDLen);
/************************************************************************/
/*                      协议解析类导出                                  */
/************************************************************************/
/********************************************************************
函数名称：RTCPProtocol_Parse_Header
函数功能：解析RTCP头
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的大小
 参数.三：pSt_RTCPHdr
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析好的RTCP协议头
返回值
  类型：逻辑型
  意思：是否成功
备注：只有解析出头,才知道后面要处理什么
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_Header(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPHDR* pSt_RTCPHdr);
/********************************************************************
函数名称：RTCPProtocol_Parse_Recver
函数功能：接受者报告协议解析
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pSt_RTCPHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入解析的头信息
 参数.四：pppSt_ListRecvInfo
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析到的接受者报告数据
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出报告个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_Recver(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPHDR* pSt_RTCPHdr, RTCPPROTOCOL_RTCPRECVER * **pppSt_ListRecvInfo, int* pInt_ListCount);
/********************************************************************
函数名称：RTCPProtocol_Parse_Sender
函数功能：发送者报告解析服务
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pSt_SendInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出解析的发送者消息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_Sender(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPSENDER * pSt_SendInfo);
/********************************************************************
函数名称：RTCPProtocol_Parse_Sdeser
函数功能：描述消息解析
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pSt_RTCPHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入解析的头信息
 参数.四：pppSt_ListSdeser
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析到的数据列表
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出报告个数
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数协议头必须移动-4个字节回去,需要多传递4个字节
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_Sdeser(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPHDR* pSt_RTCPHdr, STREAMMEDIA_RTCPPROTOCOL_SDESINFO * **pppSt_ListSdeser, int* pInt_ListCount);
/********************************************************************
函数名称：RTCPProtocol_Parse_RtpFB
函数功能：RTP反驳消息
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pSt_RTCPHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入解析的头信息
 参数.四：pInt_MediaSource
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体源标识符
 参数.五：pppSt_ListIDStatus
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出包状态列表
 参数.六：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出个数
返回值
  类型：逻辑型
  意思：是否成功
备注：根据pSt_RTCPHdr->byRtcpCount的类型来确定输出参数的意义
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_RtpFB(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPHDR* pSt_RTCPHdr, XUINT* pInt_MediaSource, XENGINE_KEYVALUE*** pppSt_ListIDStatus, int* pInt_ListCount);
/********************************************************************
函数名称：RTCPProtocol_Parse_PsFB
函数功能：指定负载反驳消息
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pSt_RTCPHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入解析的头信息
 参数.四：pInt_MediaSource
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体源标识符
 参数.五：pbFlags
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出标识符,比如类型为1表示需要关键帧
返回值
  类型：逻辑型
  意思：是否成功
备注：根据pSt_RTCPHdr->byRtcpCount的类型来确定输出参数的意义
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_PsFB(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPHDR* pSt_RTCPHdr, XUINT* pInt_MediaSource, XBYTE* pbFlags);
/********************************************************************
函数名称：RTCPProtocol_Parse_Xr
函数功能：消息扩展报告
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pSt_RTCPHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入解析的头信息
 参数.四：pInt_MediaSource
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体源标识符
返回值
  类型：逻辑型
  意思：是否成功
备注：根据pSt_RTCPHdr->byRtcpCount的类型来确定输出参数的意义
*********************************************************************/
extern "C" bool RTCPProtocol_Parse_Xr(LPCXSTR lpszMsgBuffer, int nMsgLen, RTCPPROTOCOL_RTCPHDR* pSt_RTCPHdr, XUINT* pInt_MediaSource);