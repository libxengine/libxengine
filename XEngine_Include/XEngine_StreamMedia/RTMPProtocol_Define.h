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
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONNREQ 0x20
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONNACK 0x21
//消息类型
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_SETCHUNK 0x01                 //设置CHUNK大小
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_ABORTMSG 0x02                 //中断消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_ACKMSG 0x03                   //应答消息,当收到对端消息字节数等于接收窗口大小时，接收端要回复一个应答消息（相当于ack）告知对端可以继续发送数据
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_CONTROL 0x04                  //控制消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_WINDOWSIZE 0x05               //应答窗口大小,规定接收端接收多少数据后需要发送一个应答消息
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_BANDWIDTH 0x06                //设置流带宽
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_AUDIO 0x08
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_VIDEO 0x09
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_DATA 0x12
#define XENGINE_STREAMMEDIA_RTMP_MSGTYPE_COMMAND 0x14
//消息类型
#define XENGINE_STREAMMEDIA_RTMP_PLTYPE_AFM0_INT64 0x00                       //64位整数
#define XENGINE_STREAMMEDIA_RTMP_PLTYPE_AFM0_BOOL 0x01                        //逻辑型
#define XENGINE_STREAMMEDIA_RTMP_PLTYPE_AFM0_STRING 0x02                      //字符串
#define XENGINE_STREAMMEDIA_RTMP_PLTYPE_AFM0_MAP 0x08                         //内嵌数据
//命令消息
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_CONNECT _X("connect")         //连接
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_PUBLISH _X("publish")         //发布流
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_RELEASE _X("releaseStream")   //发布流
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_FCPUBLISH _X("FCPublish")     //发布流
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_UNPUBLISH _X("FCUnpublish")   //停止流
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_CREATE _X("createStream")     //创建流
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_GETSTREAMLEN _X("getStreamLength")   //得到流大小
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_PLAY _X("play")   
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_BWDONE _X("onBWDone")         //信息结束
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_CHECK _X("_checkbw")     

#define XENGINE_STREAMMEDIA_RTMP_COMMAND_RESULT _X("_result")          //回复
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_ONSTATUS _X("onStatus")       //回复状态
#define XENGINE_STREAMMEDIA_RTMP_COMMAND_ONPUBLISH _X("onFCPublish")   //回复发布流
//控制消息
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_STREAMBEGIN 0                 //服务器发送此事件通知客户端流成功创建，并可用于通信。默认情况下，在从客户端成功收到应用程序连接命令后，此事件以ID 0来发送
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_STREAMEOF 1                   //服务器发送此事件通知客户端该流请求的数据回放结束。若不发出额外的命令，就没有更多的数据被发送了。客户端丢弃该流收到的消息
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_DRY 2                         //服务器发送此事件通知客户端，在流上没有更多的数据。如果服务器在一段时间内没有检测到任何的消息，它可以通知订阅的客户端流是结束的
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_SETBUFFERLENGTH 3             //客户端发送此事件通知服务器用于缓冲从流过来的任何数据的缓冲区大小（以毫秒为单位）。此事件在服务器开始处理流之前被发送
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_STREAMRECORD 4                //服务器发送此事件来通知客户端，需要录像
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_PINGREQEUST 6                 //服务器发送此事件来测试客户端是否是可到达的
#define XENGINE_STREAMMEDIA_RTMP_CONTROL_PINGRESPONSE 7                //客户端向服务器发送此事件响应ping请求
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
}XENGINE_RTMPPROTOCOLCONTROL;
typedef struct
{
	XSHOT nControlID;          //消息控制ID
	XUINT nValue32;            //消息值
	XUINT nExtVlu32;           //扩展消息值,SetBufferLength
}XENGINE_RTMPUSERCONTROL;
//对象信息
typedef struct
{
	XBYTE byType;                  //类型,2为字符串,0为整数
	XSHOT nMLen;                   //大小
	XCHAR tszMsgBuffer[1024];      //负载内容,超过1024将被忽略
}XENGINE_RTMPCMDOBJECT;
typedef struct
{
	XCHAR tszKeyBuffer[MAX_PATH];  
	XENGINE_RTMPCMDOBJECT st_CMDOBJect;
}XENGINE_RTMPCMDPROPERTY;
typedef struct
{
	XCHAR tszCMDName[MAX_PATH];
	double nCMDId;
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
typedef struct
{
	XCHAR tszVPSBuffer[MAX_PATH];
	XCHAR tszSPSBuffer[MAX_PATH];
	XCHAR tszPPSBuffer[MAX_PATH];
	int nVPSLen;
	int nSPSLen;
	int nPPSLen;
}XENGINE_RTMPVIDEOPARAM;
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
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包数据大小
 参数.三：pSt_RTMPClient
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的客户端数据,如果是C2请求,那么他也可以认为是服务器的数据
 参数.四：byVersion
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入打包的版本号,如果需要的话
 参数.五：pSt_RTMPServer
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入要打包的服务器数据,如果需要的话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTConnect(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XENGINE_RTMPCONNECT * pSt_RTMPClient, XBYTE byVersion = 0, XENGINE_RTMPCONNECT * pSt_RTMPServer = NULL);
/********************************************************************
函数名称：RTMPProtocol_Help_PKTProtocolControl
函数功能：打包协议控制数据包
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
extern "C" bool RTMPProtocol_Help_PKTProtocolControl(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XBYTE byTypeID, int nValue, XBYTE byExtValue = 0);
/********************************************************************
函数名称：RTMPProtocol_Help_PKTUserControl
函数功能：打包用户控制协议数据包
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
 参数.三：pSt_RTMPControl
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的控制命令
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTUserControl(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_RTMPUSERCONTROL* pSt_RTMPControl);
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
 参数.五：bWEnd
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否在中间写0x05的结束符
 参数.六：bWNull
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否在末尾写0x06的结束符
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTCommand(XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XBYTE byChunkID, XENGINE_RTMPCOMMAND * pSt_RTMPCommand, bool bWEnd = true, bool bWNull = true);
/********************************************************************
函数名称：RTMPProtocol_Help_PKTData
函数功能：打包数据协议
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
 参数.四：pppSt_PropertyList
  In/Out：In
  类型：三级指针
  可空：N
  意思：要打包的数据
 参数.五：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：打包数据个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_PKTData(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XBYTE byChunkID, XENGINE_RTMPCMDPROPERTY*** pppSt_PropertyList, int nListCount);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseConnect
函数功能：解析连接协议
 参数.一：pbyVersion
  In/Out：Out
  类型：字节型
  可空：N
  意思：输出版本号,可以为NULL,如果你知道你在做什么
 参数.二：pSt_RTMPServer
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析到的服务器数据,可以为NULL,如果你知道你在做什么
 参数.三：pSt_RTMPClient
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析到的客户端数据,可以为NULL,如果你知道你在做什么
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要解析的数据
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseConnect(XBYTE * pbyVersion, XENGINE_RTMPCONNECT * pSt_RTMPServer, XENGINE_RTMPCONNECT * pSt_RTMPClient, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseProtocolControl
函数功能：解析协议控制数据
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
extern "C" bool RTMPProtocol_Help_ParseProtocolControl(XENGINE_RTMPPROTOCOLCONTROL * pSt_RTMPControl, XBYTE byTypeID, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseUserControl
函数功能：解析用户控制数据包
 参数.一：pSt_RTMPControl
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输出解析好的控制协议信息
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
extern "C" bool RTMPProtocol_Help_ParseUserControl(XENGINE_RTMPUSERCONTROL* pSt_RTMPControl, LPCXSTR lpszMsgBuffer, int nMsgLen);
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
/********************************************************************
函数名称：RTMPProtocol_Help_ParseVideo
函数功能：解析视频标签数据
 参数.一：pSt_RTMPVideo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入视频信息
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出视频帧数据,根据类型,可以输出视频或者VPSPPSSPS等
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出视频帧大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的数据
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
 参数.六：pSt_RTMPVParam
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输出视频参数信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseVideo(XENGINE_RTMPVIDEO* pSt_RTMPVideo, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer, int nMsgLen, XENGINE_RTMPVIDEOPARAM * pSt_RTMPVParam = NULL);
/********************************************************************
函数名称：RTMPProtocol_Help_ParseAudio
函数功能：解析音频标签数据
 参数.一：pSt_RTMPAudio
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入音频信息
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出音频数据
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出音频帧大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的数据
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入处理数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Help_ParseAudio(XENGINE_RTMPAUDIO* pSt_RTMPAudio, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer, int nMsgLen);
/******************************************************************************
							 RTMP解析器导出函数
******************************************************************************/
/********************************************************************
函数名称：RTMPProtocol_Parse_Init
函数功能：初始化包解析工具
 参数.一：nPoolCount
  In/Out：In
  类型：整数型
  可空：N
  意思：创建的分布式任务池个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Init(int nPoolCount);
/********************************************************************
函数名称：RTMPProtocol_Parse_Destory
函数功能：销毁包队列解析器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Destory();
/********************************************************************
函数名称：RTMPProtocol_Parse_Insert
函数功能：插入一个用户到队列解析器
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要插入的ID
 参数.二：bServer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入创建的是客户端还是服务器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Insert(LPCXSTR lpszClientID, bool bServer = true);
/********************************************************************
函数名称：RTMPProtocol_Parse_Delete
函数功能：删除一个用户从解析器中
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RTMPProtocol_Parse_Send
函数功能：发送一段RTMP数据给解析器
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
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
extern "C" bool RTMPProtocol_Parse_Send(LPCXSTR lpszClientID, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RTMPProtocol_Parse_Recv
函数功能：获得解析好的数据
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
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
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Parse_Recv(LPCXSTR lpszClientID, XCHAR * *pptszMsgBuffer, int* pInt_MsgLen, XENGINE_RTMPHDR * pSt_RTMPHdr);
/********************************************************************
函数名称：RTMPProtocol_Parse_GetPool
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
extern "C" bool RTMPProtocol_Parse_GetPool(int nPoolIndex, XENGINE_MANAGEPOOL_TASKEVENT*** pppSt_ListAddr, int* pInt_ListCount);
/************************************************************************
函数名称：RTMPProtocol_Parse_WaitEvent
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
extern "C" bool RTMPProtocol_Parse_WaitEvent(int nPoolIndex, int nTimeOut = -1);
/********************************************************************
函数名称：RTMPProtocol_Parse_ActiveEvent
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
extern "C" bool RTMPProtocol_Parse_ActiveEvent(int nPoolIndex);
/******************************************************************************
							 RTMP打包器导出函数
******************************************************************************/
/********************************************************************
函数名称：RTMPProtocol_Packet_Insert
函数功能：插入一个客户端到封包器中
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
 参数.二：nChunkSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入CHUNK的包大小,超过需要分包
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_Insert(LPCXSTR lpszClientID, int nChunkSize = 16777215);
/********************************************************************
函数名称：RTMPProtocol_Packet_Delete
函数功能：删除一个客户端从封包器中
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
extern "C" bool RTMPProtocol_Packet_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：RTMPProtocol_Packet_SetTime
函数功能：设置时间戳
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
 参数.二：nVideoFrame
  In/Out：In
  类型：整数型
  可空：N
  意思：输入H264帧率
 参数.三：nAudioFrame
  In/Out：In
  类型：整数型
  可空：N
  意思：输入AAC音频采样率
返回值
  类型：逻辑型
  意思：是否成功
备注：仅适用于H264和AAC常规时间戳增量.时间戳为0将采用设置的参数计算
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_SetTime(LPCXSTR lpszClientID, int nVideoFrame, int nAudioFrame);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameAVScript
函数功能：打包音视频信息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.三：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：RTMP需要先推送此数据
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameAVScript(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO* pSt_AVInfo);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameAVCConfigure
函数功能：打包H264视频参数配置信息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.三：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息,视频数据结构必须填充SPS和PPS信息
返回值
  类型：逻辑型
  意思：是否成功
备注：在打包视频数据前,必须先打包AVC参数信息
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameAVCConfigure(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameHEVCConfigure
函数功能：打包H265视频参数配置信息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.三：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要处理的数据,需要包含SPS,PPS,VPS
返回值
  类型：逻辑型
  意思：是否成功
备注：在打包视频数据前,必须先打包AVC参数信息
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameHEVCConfigure(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameAACConfigure
函数功能：打包AAC音频参数配置信息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.三：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息,音频数据需要输入相应的参数,AAC的数据必须填充到音频缓冲区
返回值
  类型：逻辑型
  意思：是否成功
备注：在打包音频数据前,必须先打包AAC音频参数
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameAACConfigure(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO* pSt_AVInfo);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameCustom
函数功能：自定义数据封包
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的数据
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的数据的大小
 参数.六：nTimestamp
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入时间戳,-1将根据设置的时间戳参数自动计算
 参数.七：byTypeID
  In/Out：In
  类型：字符型
  可空：Y
  意思：负载类型,0x08是音频,09是视频
 参数.八：bChunk
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要CHUNK分片
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameCustom(LPCXSTR lpszClientID, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer, int nMsgLen, int nTimestamp = -1, XBYTE byTypeID = 9, bool bChunk = false);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameVideo
函数功能：打包一帧视频数据
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的数据,需要一个完整的NAL,不支持拆分包
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的数据的大小
 参数.六：nTimestamp
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入时间戳,-1将根据设置的时间戳参数自动计算
 参数.七：nFrameType
  In/Out：In
  类型：整数型
  可空：Y
  意思：帧类型,1为关键帧,否则为其他帧
 参数.八：bChunk
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要CHUNK分片
返回值
  类型：逻辑型
  意思：是否成功
备注：打包视频数据,视频数据开头必须是00 00 00 01(00 00 01)的完整NAL
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameVideo(LPCXSTR lpszClientID, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0, int nTimestamp = -1, int nFrameType = 0, bool bChunk = false);
/********************************************************************
函数名称：RTMPProtocol_Packet_FrameAudio
函数功能：打包一帧音频数据
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端ID
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的数据,需要一个完整的AAC包,不支持拆分包
 参数.五：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的数据的大小
 参数.六：nTimestamp
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入时间戳,-1将根据设置的时间戳参数自动计算
 参数.七：bChunk
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要CHUNK分片
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RTMPProtocol_Packet_FrameAudio(LPCXSTR lpszClientID, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0, int nTimestamp = -1, bool bChunk = false);