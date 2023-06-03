#pragma once
/********************************************************************
//    Created:     2023/05/15  14:21:00
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_FLVProtocol\FLVProtocol_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_StreamMedia\StreamMedia_FLVProtocol
//    File Base:   FLVProtocol_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     FLV协议模块定义
//    History:
*********************************************************************/
typedef struct
{
	XCHAR tszKeyStr[MAX_PATH];
	XCHAR tszVluStr[MAX_PATH];
}XENGINE_FLVAVINFO;
//视频标签,5个字节
typedef struct
{
	XBYTE byCodecID : 4;        //编码器ID,7;h264,12:h265
	XBYTE byFrameType : 4;      //帧类型:1关键帧,2其他

	XBYTE byAVCType;            //AVC帧类型,0,AVC sequence header,1 avc nalu,2avc end of sequence 
	XBYTE byCompositionTime[3]; //PTS和DTS的时间偏移值,单位毫秒,记作cts,若含 B 帧，则 PTS 和 DTS 不同，H264 视频帧 PTS = DTS + CTS
}XENGINE_FLVVIDEO;
//音频标签,2个字节
typedef struct
{
	XBYTE byAudioType : 1;  //0 - mono, 1 - stereo
	XBYTE byAudioSize : 1;  //0 - 8 bit, 1 - 16 bit
	XBYTE byAudioRate : 2;  //0 - 5.5 KHz, 1 - 11 KHz, 2 - 22 KHz, 3 - 44 KHz
	XBYTE byAudioFmt : 4;   //0 - raw, 1 - ADPCM, 2 - MP3, 4 - Nellymoser 16 KHz mono, 5 - Nellymoser 8 KHz mono, 10 - AAC, 11 - Speex

	XBYTE byPKTType;        //仅仅当AAC生效,0,aac sequence header,1 aac raw
}XENGINE_FLVAUDIO;
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" XLONG FLVProtocol_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
                             FLV解析器导出函数
******************************************************************************/
/********************************************************************
函数名称：FLVProtocol_Parse_Create
函数功能：创建一个FLV解析器
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
extern "C" bool FLVProtocol_Parse_Create(XNETHANDLE* pxhToken);
/********************************************************************
函数名称：FLVProtocol_Parse_Destory
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
extern "C" bool FLVProtocol_Parse_Destory(XNETHANDLE xhToken);
/********************************************************************
函数名称：FLVProtocol_Parse_Send
函数功能：发送一段flv数据给解析器
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
extern "C" bool FLVProtocol_Parse_Send(XNETHANDLE xhToken, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：FLVProtocol_Parse_Recv
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
 参数.四：pInt_AVType
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体类型,0视频,1音频
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
extern "C" bool FLVProtocol_Parse_Recv(XNETHANDLE xhToken, XCHAR * *pptszMsgBuffer, int* pInt_MsgLen, int* pInt_AVType, XENGINE_FLVVIDEO * pSt_FLVVideo = NULL, XENGINE_FLVAUDIO * pSt_FLVAudio = NULL);
/********************************************************************
函数名称：FLVProtocol_Parse_GetMetaInfo
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
extern "C" bool FLVProtocol_Parse_GetMetaInfo(XNETHANDLE xhToken, XCHAR* ptszSPSBuffer, XCHAR* ptszPPSBuffer, int* pInt_SPSLen, int* pInt_PPSLen);
/********************************************************************
函数名称：FLVProtocol_Parse_GetScriptInfo
函数功能：获取FLV扩展的音视频信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的解析器
 参数.二：pppSt_FLVInfoList
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的信息列表(内存需要释放)
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：Script标签信息
*********************************************************************/
extern "C" bool FLVProtocol_Parse_GetScriptInfo(XNETHANDLE xhToken, XENGINE_FLVAVINFO*** pppSt_FLVInfoList, int* pInt_ListCount);
/******************************************************************************
							 FLV打包器导出函数
******************************************************************************/
/********************************************************************
函数名称：FLVProtocol_Packet_Create
函数功能：创建一个FLV封包复用工具
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出创建后的句柄
 参数.二：bVideo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用视频
 参数.三：bAudio
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用音频
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FLVProtocol_Packet_Create(XNETHANDLE * pxhToken, bool bVideo = true, bool bAudio = true);
/********************************************************************
函数名称：FLVProtocol_Packet_Destory
函数功能：销毁封包器
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
extern "C" bool FLVProtocol_Packet_Destory(XNETHANDLE xhToken);
/********************************************************************
函数名称：FLVProtocol_Packet_FrameHdr
函数功能：打包FLV头
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
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
返回值
  类型：逻辑型
  意思：是否成功
备注：1.先打包FLV头
*********************************************************************/
extern "C" bool FLVProtocol_Packet_FrameHdr(XNETHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：FLVProtocol_Packet_FrameScript
函数功能：打包脚本标签数据
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
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
 参数.四：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息,要设置音频或者视频,你需要填充相应的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：2.在打包脚本TAG
*********************************************************************/
extern "C" bool FLVProtocol_Packet_FrameScript(XNETHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：FLVProtocol_Packet_FrameAVCConfigure
函数功能：打包H264视频参数配置信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
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
 参数.四：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息,视频数据结构必须填充SPS和PPS信息
返回值
  类型：逻辑型
  意思：是否成功
备注：3.在打包视频参数信息
*********************************************************************/
extern "C" bool FLVProtocol_Packet_FrameAVCConfigure(XNETHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：FLVProtocol_Packet_FrameAACConfigure
函数功能：打包AAC音频参数配置信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
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
 参数.四：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的信息,音频数据需要输入相应的参数,AAC的数据必须填充到音频缓冲区
返回值
  类型：逻辑型
  意思：是否成功
备注：3.如果需要打包音频,也可以设置此参数
*********************************************************************/
extern "C" bool FLVProtocol_Packet_FrameAACConfigure(XNETHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_AVINFO * pSt_AVInfo);
/********************************************************************
函数名称：FLVProtocol_Packet_FrameVideo
函数功能：打包一帧视频数据
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
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
 参数.四：nTimestamp
  In/Out：In
  类型：整数型
  可空：N
  意思：输入时间戳
 参数.五：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的数据,需要一个完整的NAL,不支持拆分包
 参数.六：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的数据的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：4.打包视频数据,视频数据开头必须是00 00 00 01(00 00 01)的完整NAL
*********************************************************************/
extern "C" bool FLVProtocol_Packet_FrameVideo(XNETHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, int nTimestamp, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：FLVProtocol_Packet_FrameAudio
函数功能：打包一帧音频数据
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
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
 参数.四：nTimestamp
  In/Out：In
  类型：整数型
  可空：N
  意思：输入时间戳
 参数.五：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的数据,需要一个完整的AAC包,不支持拆分包
 参数.六：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的数据的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：4.打包音频数据
*********************************************************************/
extern "C" bool FLVProtocol_Packet_FrameAudio(XNETHANDLE xhToken, XCHAR * ptszMsgBuffer, int* pInt_MsgLen, int nTimestamp, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0);