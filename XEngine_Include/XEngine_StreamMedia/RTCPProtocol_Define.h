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
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_SR = 200,                    //发送端报告
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_RR = 201,                    //接收端报告
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_SDES = 202,                  //源点描述
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_BYE = 203,                   //结束传输
    ENUM_STREAMMEDIA_RTCPPROTOCOL_PACKET_TYPE_APP = 204                    //特定应用
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
typedef struct tag_StreamMedia_RTCPProtocol_RecvInfo
{
    uint32_t xhSsrc;                                                      //接受报告者SSRC
    uint32_t nLostPacket;                                                 //丢包个数
    uint32_t nLostRate;                                                   //丢包率
    uint32_t nSRTime;                                                     //上一个报文接受时间
    uint32_t nSeqNumber;                                                  //最后接受包序列号
    struct
    {
        ENUM_STREAMMEDIA_RTCPPROTOCOL_SDESTYPE enSdesType;
        int nLen;
        XCHAR tszText[256];
    }st_SdesInfo;
}STREAMMEDIA_RTCPPROTOCOL_RECVINFO;
//////////////////////////////////////////////////////////////////////////
//                       导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG RTCPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      发送者函数导出                                  */
/************************************************************************/
/********************************************************************
函数名称：RTCPProtocol_Sender_Packet
函数功能：发送者报告包
 参数.一：xhSsrc
  In/Out：In
  类型：整数型
  可空：N
  意思：发送源标志SSRC
 参数.二：lpszCName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入本机名称
 参数.三：nRecvCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入接收到的RTP包个数
 参数.四：nSendCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入发送的包个数
 参数.五：nSendByte
  In/Out：In
  类型：整数型
  可空：N
  意思：输入发送的总字节
 参数.六：nRTPTime
  In/Out：In
  类型：整数型
  可空：N
  意思：输入RTP包时间
 参数.七：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.八：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Sender_Packet(uint32_t xhSsrc, LPCXSTR lpszCName, int nRecvCount, int nSendCount, int nSendByte, uint32_t nRTPTime, XCHAR *ptszMsgBuffer, int *pInt_MsgLen);
/********************************************************************
函数名称：RTCPProtocol_Sender_Parse
函数功能：发送者报告解析服务
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：n
  意思：要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要解析缓冲区大小
 参数.三：pxhSsrc
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的SSRC
 参数.四：pInt_SRCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的接受RTP包个数
 参数.五：pInt_NTPMswTime
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出NTP的MSW时间
 参数.六：pInt_NTPLswTime
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出NTP的LSW时间
 参数.七：pInt_PktCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的发送包个数
 参数.八：pInt_ByteCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的发送字节数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Sender_Parse(LPCXSTR lpszMsgBuffer, int nMsgLen, uint32_t *pxhSsrc, int *pInt_SRCount = NULL, uint32_t *pInt_NTPMswTime = NULL, uint32_t *pInt_NTPLswTime = NULL, uint32_t *pInt_PktCount = NULL, uint32_t *pInt_ByteCount = NULL);
/********************************************************************
函数名称：RTCPProtocol_Sender_PktGoodbye
函数功能：离开打包函数
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：输入SSRC
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Sender_PktGoodbye(uint32_t xhSsrc, XCHAR *ptszMsgBuffer, int *pInt_MsgLen);
/************************************************************************/
/*                      接受者函数导出                                  */
/************************************************************************/
/********************************************************************
函数名称：RTCPProtocol_Recver_Packet
函数功能：接受者服务打包函数
 参数.一：pSt_RecvInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Recver_Packet(STREAMMEDIA_RTCPPROTOCOL_RECVINFO *pSt_RecvInfo, XCHAR *ptszMsgBuffer, int *pInt_MsgLen);
/********************************************************************
函数名称：RTCPProtocol_Recver_PktGoodbye
函数功能：打包一个接受者离开包
 参数.一：xhSsrc
  In/Out：In
  类型：句柄
  可空：N
  意思：SSRC
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Recver_PktGoodbye(uint32_t xhSsrc, XCHAR *ptszMsgBuffer, int *pInt_MsgLen);
/********************************************************************
函数名称：RTCPProtocol_Recver_Parse
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
 参数.三：pppSt_ListRecvInfo
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析到的接受者报告数据
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出报告个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数三必须调用基础库的内存释放函数进行内存释放
*********************************************************************/
extern "C" bool RTCPProtocol_Recver_Parse(LPCXSTR lpszMsgBuffer, int nMsgLen, STREAMMEDIA_RTCPPROTOCOL_RECVINFO * **pppSt_ListRecvInfo, int* pInt_ListCount);
/************************************************************************/
/*                      帮助器函数导出                                  */
/************************************************************************/
/********************************************************************
函数名称：RTCPProtocol_Helper_GetNTPTime
函数功能：获取RTP时间
 参数.一：punNTPMsw
  In/Out：Out
  类型：无符号整数型指针
  可空：N
  意思：输出NTP的MSW时间
 参数.二：punNTPLsw
  In/Out：Out
  类型：无符号整数型指针
  可空：N
  意思：输出NTP的LSW时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Helper_GetNTPTime(uint32_t *punNTPMsw, uint32_t *punNTPLsw);
/********************************************************************
函数名称：RTCPProtocol_Helper_PktType
函数功能：获取一个包的类型,或者检查一个包是否是RTCP包
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要检查的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区大小
 参数.三：pen_Payload
  In/Out：In
  类型：枚举型指针
  可空：Y
  意思：输出RTCP包负载类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTCPProtocol_Helper_PktType(LPCXSTR lpszMsgBuffer, int nMsgLen, ENUM_STREAMMEDIA_RTCPPROTOCOL_PAYLOADTYPE *pen_Payload = NULL);
/********************************************************************
函数名称：RTCPProtocol_Helper_CalLen
函数功能：计算长度函数
 参数.一：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要计算的大小
 参数.二：bCal
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是计算还是还原
返回值
  类型：整数型
  意思：输出计算后的大小
备注：
*********************************************************************/
extern "C" XSHOT RTCPProtocol_Helper_CalLen(int nMsgLen, bool bCal = true);
