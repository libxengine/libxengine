#pragma once
/********************************************************************
//    Created:     2023/05/24  13:51:41
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_RTMPProtocol\RTMPProtocol_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_RTMPProtocol
//    File Base:   RTMPProtocol_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     RTMP协议模块定义
//    History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                               导出的定义
///////////////////////////////////////////////////////////////////////////////
//控制消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_SETCHUNK 0x01                 //设置CHUNK大小
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_ABORTMSG 0x02                 //中断消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_ACKMSG 0x03                   //应答消息,当收到对端消息字节数等于接收窗口大小时，接收端要回复一个应答消息（相当于ack）告知对端可以继续发送数据
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_WINDOWSIZE 0x05               //应答窗口大小,规定接收端接收多少数据后需要发送一个应答消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_BANDWIDTH 0x06                //设置流带宽
//消息类型
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_AFM0_INT64 0x00                       //64位整数
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_AFM0_BOOL 0x01                        //逻辑型
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_AFM0_STRING 0x02                      //字符串
//命令消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_CONNECT _X("connect")         //连接
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_PUBLISH _X("publish")         //发布流
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_RELEASE _X("releaseStream")   //发布流
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_FCPUBLISH _X("FCPublish")     //发布流
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_CREATE _X("createstream")     //创建流

#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_RESULT _X("_result")          //回复
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_ONSTATUS _X("onStatus")       //回复状态
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND_ONPUBLISH _X("onFCPublish")   //回复发布流
///////////////////////////////////////////////////////////////////////////////
//                               导出的枚举
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_CONNREQ = 0,
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_CONNACK = 1,
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_CONTROL = 2,
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_COMMAND = 3,
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_DATA = 4,
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_AUDIO = 5,
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE_VIDEO = 6
}ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE;
///////////////////////////////////////////////////////////////////////////////
//                               导出的数据结构
///////////////////////////////////////////////////////////////////////////////
//三次握手
typedef struct
{
	XUINT nTime;                      //这个字段包含一个 timestamp，用于本终端发送的所有后续块的时间起点。这个值可以是 0
	XUINT nZero;                      //这个字段必须都是 0。如果不是0，代表要使用复杂握手
	XCHAR tszRandomStr[1528];         //随机字符串
}XENGINE_RTMPCONNECT;
//自定义标准头
typedef struct
{
	ENUM_XENGINE_STREAMMEDIA_RTMP_PARSE_PKTTYPE enPKTType;
	XUINT nStreamID;
	XUINT nMSGLen;
	XUINT nTimeStamp;
	XSHOT nChunkType;                //头类型
	XBYTE byTimeExt;                 //时间戳扩展
	XBYTE byTypeID;
}XENGINE_RTMPHDR;
//控制命令
typedef struct
{
	XBYTE byControlID;          //消息控制ID
	XBYTE byVluExt;             //扩展字段XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_BANDWIDTH 有效,表示限制类型 0 硬限制,1 软限制,2 动态限制
	XUINT nValue32;             //消息值
}XENGINE_RTMPCONTROL;
//对象信息
typedef struct
{
	XBYTE byType;                  //类型,2为字符串,0为整数
	XSHOT nMLen;                   //大小
	XCHAR tszMsgBuffer[MAX_PATH];  //负载内容
}XENGINE_RTMPCMDOBJECT;
typedef struct
{
	XCHAR tszKeyBuffer[MAX_PATH];  
	XENGINE_RTMPCMDOBJECT st_CMDOBJect[MAX_PATH];
}XENGINE_RTMPCMDPROPERTY;
typedef struct
{
	XCHAR tszCMDName[MAX_PATH];
	__int64u nCMDId;
	//对象值
	int nObCount;
	int nProCount;
	XENGINE_RTMPCMDOBJECT** ppSt_CMDObject;
	XENGINE_RTMPCMDPROPERTY** ppSt_CMDProperty;
}XENGINE_RTMPCOMMAND;

typedef struct
{
	XCHAR tszDataName[MAX_PATH];
	XCHAR tszDataValue[MAX_PATH];
	//对象值
	int nCount;
	XENGINE_RTMPCMDPROPERTY** ppSt_CMDProperty;
}XENGINE_RTMPDATA;
//视频标签,1个字节,同FLV标签
typedef struct
{
	XBYTE byCodecID : 4;        //编码器ID,7;h264,12:h265
	XBYTE byFrameType : 4;      //帧类型:1关键帧,2其他

	XBYTE byAVCType;            //AVC帧类型,0,AVC sequence header,1 avc nalu,2avc end of sequence 
	XBYTE byCompositionTime[3]; //PTS和DTS的时间偏移值,单位毫秒,记作cts,若含 B 帧，则 PTS 和 DTS 不同，H264 视频帧 PTS = DTS + CTS
}XENGINE_RTMPVIDEO;
//音频标签,1个字节,同FLV标签
typedef struct
{
	XBYTE byAudioType : 1;  //0 - mono, 1 - stereo
	XBYTE byAudioSize : 1;  //0 - 8 bit, 1 - 16 bit
	XBYTE byAudioRate : 2;  //0 - 5.5 KHz, 1 - 11 KHz, 2 - 22 KHz, 3 - 44 KHz
	XBYTE byAudioFmt : 4;   //0 - raw, 1 - ADPCM, 2 - MP3, 4 - Nellymoser 16 KHz mono, 5 - Nellymoser 8 KHz mono, 10 - AAC, 11 - Speex

	XBYTE byPKTType;        //仅仅当AAC生效,0,aac sequence header,1 aac raw
}XENGINE_RTMPAUDIO;
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" XLONG RTMPProtocol_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
							 RMPT帮助导出函数
******************************************************************************/
/********************************************************************
函数名称：RTMPProtocol_Help_PKTConnect
函数功能：连接验证打包协议
 参数.一：pbyVersion
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出版本号
 参数.二：pSt_RTMPClient
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出客户端的连接信息
 参数.三：pSt_RTMPServer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出服务端的连接信息
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入解析大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTConnect(XBYTE * pbyVersion, XENGINE_RTMPCONNECT * pSt_RTMPClient, XENGINE_RTMPCONNECT * pSt_RTMPServer, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Help_PKTControl
函数功能：打包控制协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的协议缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：byTypeID
  In/Out：In
  类型：字符
  可空：N
  意思：输入要打包的控制命令ID
 参数.四：nValue
  In/Out：In
  类型：整数型
  可空：N
  意思：输入命令的值
 参数.五：byExtValue
  In/Out：In
  类型：字符
  可空：N
  意思：输入扩展信息,比如XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL_BANDWIDTH有扩展数据位
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTControl(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XBYTE byTypeID, int nValue, XBYTE byExtValue = 0);
/********************************************************************
函数名称：RTMPProtocol_Help_PKTCommand
函数功能：打包命令协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的协议缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：byChunkID
  In/Out：In
  类型：字符
  可空：N
  意思：输入要打包的命令ID
 参数.四：pSt_RTMPCommand
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要打包的命令
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTCommand(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XBYTE byChunkID, XENGINE_RTMPCOMMAND * pSt_RTMPCommand);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseConnver
函数功能：解析连接协议并且验证
 参数.一：pSt_RTMPServer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入服务端打包连接信息
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要判断的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseConnver(XENGINE_RTMPCONNECT * pSt_RTMPServer, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseControl
函数功能：解析控制协议
 参数.一：pSt_RTMPControl
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输出解析好的控制协议信息
 参数.二：byTypeID
  In/Out：In
  类型：字符指针
  可空：N
  意思：输入要解析的协议命令
 参数.三：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的数据
 参数.四：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseControl(XENGINE_RTMPCONTROL * pSt_RTMPControl, XBYTE byTypeID, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseCommand
函数功能：解析命令协议
 参数.一：pSt_RTMPCommand
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输出解析好的协议信息
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseCommand(XENGINE_RTMPCOMMAND* pSt_RTMPCommand, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseData
函数功能：解析数据协议
 参数.一：pSt_RTMPData
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输出解析好的协议信息
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseData(XENGINE_RTMPDATA* pSt_RTMPData, LPCXSTR lpszMsgBuffer, int nMsgLen);
/******************************************************************************
							 RTMP解析器导出函数
******************************************************************************/
/********************************************************************
函数名称：RTMPProtocol_Parse_Create
函数功能：创建一个RTMP解析器
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建成功的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Create(XNETHANDLE* pxhToken);
/********************************************************************
函数名称：RTMPProtocol_Parse_Destory
函数功能：销毁一个解析器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Destory(XNETHANDLE xhToken);
/********************************************************************
函数名称：RTMPProtocol_Parse_SetChunkSize
函数功能：对端CHUNK设置大小
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的解析器
 参数.二：nChunkSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入对端设置的CHUNK大小.没设置默认128
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数如果对端有发送CHUNK协议,必须调用设置
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_SetChunkSize(XNETHANDLE xhToken, int nChunkSize);
/********************************************************************
函数名称：RTMPProtocol_Parse_GetMetaInfo
函数功能：获取媒体信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的解析器
 参数.二：ptszSPSBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出媒体的SPS信息
 参数.三：ptszPPSBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出媒体的PPS信息
 参数.四：pInt_SPSLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出SPS大小
 参数.五：pInt_PPSLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出PPS大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_GetMetaInfo(XNETHANDLE xhToken, XCHAR* ptszSPSBuffer, XCHAR* ptszPPSBuffer, int* pInt_SPSLen, int* pInt_PPSLen);
/********************************************************************
函数名称：RTMPProtocol_Parse_Send
函数功能：发送一段RTMP数据给解析器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的解析器
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Send(XNETHANDLE xhToken, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Parse_Recv
函数功能：获得解析好的数据
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的解析器
 参数.二：pptszMsgBuffer
  In/Out：Out
  类型：指向指针的指针
  可空：N
  意思：输出获取到的负载编码数据,此内存需要用户手动释放
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出编码数据大小
 参数.四：pSt_RTMPHdr
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出RTMP协议头信息
 参数.五：pSt_FLVVideo
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：视频类型存在,表示视频信息
 参数.六：pSt_FLVAudio
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：音频类型存在,表示音频信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Recv(XNETHANDLE xhToken, XCHAR * *pptszMsgBuffer, int* pInt_MsgLen, XENGINE_RTMPHDR * pSt_RTMPHdr, XENGINE_RTMPVIDEO * pSt_RTMPVideo = NULL, XENGINE_RTMPAUDIO * pSt_RTMPAudio = NULL);