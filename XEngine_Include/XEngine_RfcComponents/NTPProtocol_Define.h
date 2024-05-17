#pragma once
/********************************************************************
//    Created:     2024/03/29  17:05:06
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_NTPProtocol\NTPProtocol_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_NTPProtocol
//    File Base:   NTPProtocol_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     NTP导出协议
//    History:
*********************************************************************/
typedef struct
{
	XUINT nTimeSecond;                  //秒数
	XUINT nTimeFractions;               //小数点
}NTPPROTOCOL_TIMEINFO;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG NTPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     NTP协议打包导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：NTPProtocol_Packet_REQHeader
函数功能：NTP协议请求头封装函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_RefTime
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入参考时间戳,最近一次同步的时间戳
 参数.四：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入机器ID,比如IP地址
 参数.五：byPollTime
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入轮训时间,秒
 参数.六：byRequestType
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入请求打包类型,默认客户端打包
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数一般用于客户端打包请求
*********************************************************************/
extern "C" bool NTPProtocol_Packet_REQHeader(XCHAR* ptszMsgBuffer, int* pInt_Len, NTPPROTOCOL_TIMEINFO* pSt_RefTime = NULL, LPCXSTR lpszClientID = NULL, XBYTE byPollTime = 0, XBYTE byRequestType = 3);
/********************************************************************
函数名称：NTPProtocol_Packet_REPHeader
函数功能：NTP协议请求头封装函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_RefTime
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入参考时间戳,最近一次同步的时间戳
 参数.四：pSt_RecvTime
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入解析数据导出的接受解析时间戳
 参数.五：pSt_OriginTime
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入客户端发送的传输时间戳
 参数.六：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入机器ID,比如IP地址
 参数.七：byPollTime
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入轮训时间,秒
 参数.八：byRequestType
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入请求打包类型,默认服务端打包
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数一般用于服务器响应请求
*********************************************************************/
extern "C" bool NTPProtocol_Packet_REPHeader(XCHAR* ptszMsgBuffer, int* pInt_Len, NTPPROTOCOL_TIMEINFO* pSt_RefTime = NULL, NTPPROTOCOL_TIMEINFO* pSt_RecvTime = NULL, NTPPROTOCOL_TIMEINFO* pSt_OriginTime = NULL, LPCXSTR lpszClientID = NULL, XBYTE byPollTime = 0, XBYTE byRequestType = 4);
/********************************************************************
函数名称：NTPProtocol_Packet_TimeConvert
函数功能：本地时间转NTP时间戳
 参数.一：pSt_TimeInfo
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：输入要转换的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：如果pSt_TimeInfo的秒为0,那么将获取系统当前时间
*********************************************************************/
extern "C" bool NTPProtocol_Packet_TimeConvert(NTPPROTOCOL_TIMEINFO* pSt_TimeInfo);
/************************************************************************/
/*                     NTP协议解析导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：NTPProtocol_Parse_Header
函数功能：NTP协议解析
 参数.一：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMSGLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入解析的大小
 参数.三：pSt_RefTime
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出解析获取到的参考时钟
 参数四：pSt_RecvTime
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出解析处理时钟,接受时钟
 参数.五：pSt_OriginTime
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出原始时钟
 参数.六：pSt_TrsTimestamp
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出传输时钟
 参数.七：pInt_TimePoll
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出参考的轮训时间
 参数.八：pInt_TimePrecision
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出时钟精度,单位纳秒
 参数.九：ptszIDAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出服务器IP地址信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NTPProtocol_Parse_Header(LPCXSTR lpszMSGBuffer, int nMSGLen, NTPPROTOCOL_TIMEINFO * pSt_RefTime = NULL, NTPPROTOCOL_TIMEINFO * pSt_RecvTime = NULL, NTPPROTOCOL_TIMEINFO * pSt_OriginTime = NULL, NTPPROTOCOL_TIMEINFO * pSt_TrsTimestamp = NULL, int* pInt_TimePoll = NULL, int* pInt_TimePrecision = NULL, XCHAR * ptszIDAddr = NULL);
/********************************************************************
函数名称：NTPProtocol_Parse_TimeInfo
函数功能：NTP协议解析
 参数.一：pSt_RecvTime
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出解析处理时钟,接受时钟
 参数.二：pSt_OriginTime
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出原始时钟
 参数.三：pSt_TrsTimestamp
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出传输时钟
 参数.四：pInt_TimeOffset
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出时间偏移,单位微妙,正数代表你的系统时钟慢了,需要加上此微秒值
		负数代表你的系统快了,需要减少此微秒值设置你的系统时钟
 参数.五：pInt_TimeDelay
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出往返延迟,如果没有原始时间,这个值为0,单位微妙
返回值
  类型：逻辑型
  意思：是否成功
备注：内部有计时器,如果有调试断点,数据将不正确
*********************************************************************/
extern "C" bool NTPProtocol_Parse_TimeInfo(NTPPROTOCOL_TIMEINFO* pSt_RecvTime, NTPPROTOCOL_TIMEINFO* pSt_OriginTime, NTPPROTOCOL_TIMEINFO* pSt_TrsTimestamp, __int64x* pInt_TimeOffset, __int64x* pInt_TimeDelay);