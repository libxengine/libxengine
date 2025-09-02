#pragma once
/********************************************************************
//    Created:     2024/06/03  10:42:44
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFormat\AVFormat_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_AVCodec\XEngine_AVFormat
//    File Base:   AVFormat_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     音视频文件封装模块导出函数
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      枚举类型
//////////////////////////////////////////////////////////////////////////
typedef enum
{
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_UNKNOWN = -1,
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_VIDEO,
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_AUDIO,
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_DATA,
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_SUBTITLE,
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_ATTACHMENT,
	ENUM_AVFORMAT_STREAM_MEDIA_TYPE_NB
}ENUM_AVFORMAT_STREAM_MEDIA_TYPE;
//////////////////////////////////////////////////////////////////////////
//                      回调函数
//////////////////////////////////////////////////////////////////////////
//读写回调,参数:自定义参数,缓冲区,缓冲区大小
typedef int(*CALLBACK_XENGINE_AVCODEC_AVFORMAT_PACKETRW)(XPVOID lParam, uint8_t* puszMsgBuffer, int nSize);
//转换器回调函数,参数:句柄,当前转换帧类型(-1未指定,0VIDEO,1AUDIO)(UNPack表示当前流索引),当前转换帧编号,当前转换时间,自定义参数
typedef void(XCALLBACK *CALLBACK_XENGINE_AVCODEC_AVFORMAT_NOTIFY)(XHANDLE xhNet, int nCvtType, __int64x nCvtFrame, double dlTime, XPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                      数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
	int nAVCodecType;                                                     //媒体类型
	int nAVCodecID;                                                       //媒体ID
	int nAVFormat;                                                        //格式
	int nAVIndex;                                                         //流索引
}AVCODEC_STREAMINFO;
typedef struct
{
	XCHAR tszFileName[XPATH_MAX];                                           //文件地址,要获取list后设置这个值,写到文件是哪儿,如果是回调,表示写的媒体格式
	double dlAVTimeStart;                                                 //提取媒体开始时间,如果不需要设置为0
	double dlAVTimeEnd;                                                   //提取媒体结束时间
	int nAVIndex;                                                         //流索引
	CALLBACK_XENGINE_AVCODEC_AVFORMAT_PACKETRW fpCall_Write;              //回调函数,写文件回调,如果为NULL 不通过数据回调
	XPVOID lParam;                                                        //自定义参数
}AVCODEC_FORMATINFO;
typedef struct
{
	int64_t nPTSValue;
	int64_t nDTSValue;
	int64_t nDuration;
}AVCODEC_PACKETINFO;
//////////////////////////////////////////////////////////////////////////
//                      导出函数声明
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AVFormat_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                      音视频文件封装器导出函数                        */
/************************************************************************/
/********************************************************************
函数名称：AVFormat_Packet_Init
函数功能：初始化一个打包器
返回值
  类型：句柄型
  意思：成功返回句柄,失败返回NULL
备注：
*********************************************************************/
extern "C" XHANDLE AVFormat_Packet_Init();
/********************************************************************
函数名称：AVFormat_Packet_Output
函数功能：打开输出文件信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的打包器
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要操作的文件
 参数.三：lpszPktName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入负载格式,如果不清楚可以设置为NULL
 参数.四：pppSt_KEYValue
  In/Out：In
  类型：三级指针
  可空：Y
  意思：自定义参数列表
 参数.五：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：参数列表个数
 参数.六：fpCall_FileWrite
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：内存会写数据回调,如果不想输出到文件,可以使用此回调
 参数.七：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：如果使用了回调函数,那么第三个参数的意思为输出的格式,比如:flv.mp4
	  可以设置输出到文件,也可以输出内存,还可以支持输出流(rtmp,udp,flv等)
*********************************************************************/
extern "C" bool AVFormat_Packet_Output(XHANDLE xhNet, LPCXSTR lpszFile = NULL, LPCXSTR lpszPktName = NULL, XENGINE_KEYVALUE*** pppSt_KEYValue = NULL, int nListCount = 0, CALLBACK_XENGINE_AVCODEC_AVFORMAT_PACKETRW fpCall_FileWrite = NULL, XPVOID lParam = NULL);
/********************************************************************
函数名称：AVFormat_Packet_Start
函数功能：开始进行打包
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的打包器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_Packet_Start(XHANDLE xhNet);
/********************************************************************
函数名称：AVFormat_Packet_Stop
函数功能：关闭一个音视频封装器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" bool AVFormat_Packet_Stop(XHANDLE xhNet);
/********************************************************************
函数名称：AVFormat_Packet_TimeBase
函数功能：设置原始视频时间基
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的媒体包
 参数.二：nAVIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的媒体流索引
 参数.三：pSt_TimeBase
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入原始流时间基
返回值
  类型：逻辑型
  意思：是否成功
备注：如果不清楚原始时间基,可以设置为帧率
*********************************************************************/
extern "C" bool AVFormat_Packet_TimeBase(XHANDLE xhNet, int nAVIndex, AVCODEC_TIMEBASE* pSt_TimeBase);
/********************************************************************
函数名称：AVFormat_Packet_AVCreate
函数功能：自定义结构创建流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的媒体包
 参数.二：pSt_AVProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入创建的流信息
返回值
  类型：逻辑型
  意思：是否成功
备注：一个一个创建最好.否则视频流先创建index = 0,音频流后创建index = 1
*********************************************************************/
extern "C" bool AVFormat_Packet_AVCreate(XHANDLE xhNet, XENGINE_PROTOCOL_AVINFO* pSt_AVProtocol);
/********************************************************************
函数名称：AVFormat_Packet_StreamCreate
函数功能：创建一个流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的流句柄
 参数.二：pSt_AVParameter
  In/Out：In
  类型：句柄
  可空：N
  意思：输入获取到的音视频参数:AVCodecParameters
返回值
  类型：逻辑型
  意思：是否成功
备注：使用此函数创建的流,需要使用AVFormat_Packet_StreamWrite写
*********************************************************************/
extern "C" bool AVFormat_Packet_StreamCreate(XHANDLE xhNet, XHANDLE pSt_AVParameter);
/********************************************************************
函数名称：AVFormat_Packet_StreamWrite
函数功能：写入媒体数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
 参数.二：nAVIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：数据的媒体索引
 参数.三：lpszMSGBuffer
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：输入要写的媒体数据
 参数.四：nMSGLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入媒体数据大小
 参数.五：pSt_PacketInfo
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入数据的媒体包信息
 参数.六：pdlAVTime
  In/Out：In
  类型：浮点型指针
  可空：Y
  意思：输出打包的媒体时间
 参数.七：bWait
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入是否使用系统等待
 参数.八：bChanged
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：这次输入是否是新的流(流切换)
返回值
  类型：逻辑型
  意思：是否成功
备注：切换流会导致pts时间戳变换,bChanged必须设置为真,否则会导致输出的流时间戳不连续
*********************************************************************/
extern "C" bool AVFormat_Packet_StreamWrite(XHANDLE xhNet, int nAVIndex, LPCXBTR lpszMSGBuffer, int nMSGLen, AVCODEC_PACKETINFO* pSt_PacketInfo = NULL, double* pdlAVTime = NULL, bool bWait = false, bool bChanged = false);
/********************************************************************
函数名称：AVFormat_Packet_SetLastPTS
函数功能：设置当前写的包为末尾包
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的封包器
 参数.二：nAVIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要操作的流索引,-1 表示自动获取.
 参数.三：nPTS
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入流的PTS
 参数.四：nDTS
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入流的DTS
 参数.五：nDUR
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入流的Duration
返回值
  类型：逻辑型
  意思：是否成功
备注：合并多个媒体需要设置,要不然用户自己设置.
	  -1 系统会先+ 在转换,否则将会转换后再+
*********************************************************************/
extern "C" bool AVFormat_Packet_SetLastPTS(XHANDLE xhNet, int nAVIndex = -1, int64_t nPTS = 0, int64_t nDTS = 0, int64_t nDUR = 0);
/************************************************************************/
/*                      音视频文件解封装器导出函数                      */
/************************************************************************/
/********************************************************************
函数名称：AVFormat_UNPack_Init
函数功能：初始化一个文件解封包器
返回值
  类型：句柄型
  意思：成功返回句柄,失败返回NULL
备注：
*********************************************************************/
extern "C" XHANDLE AVFormat_UNPack_Init();
/********************************************************************
函数名称：AVFormat_UNPack_Input
函数功能：设置输入数据流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解封包的文件
 参数.三：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入读取网络超时时间,单位微妙,仅网络地址有效
 参数.四：fpCall_FileRead
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：如果此值不为NULL,表示从内存读取数据
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：lpszFile可以设置是文件地址,也可以是网络地址
*********************************************************************/
extern "C" bool AVFormat_UNPack_Input(XHANDLE xhNet, LPCXSTR lpszFile, int nTimeout = 0, CALLBACK_XENGINE_AVCODEC_AVFORMAT_PACKETRW fpCall_FileRead = NULL, XPVOID lParam = NULL);
/********************************************************************
函数名称：AVFormat_UNPack_Read
函数功能：读取媒体数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
 参数.二：pInt_AVIndex
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出读取到的数据的媒体索引
 参数.三：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出读取到的媒体数据
 参数.四：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.五：pSt_AVPacket
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出包信息
 参数.六：pdlAVTime
  In/Out：Out
  类型：浮点型指针
  可空：Y
  意思：输出当前读取的帧的时间
返回值
  类型：逻辑型
  意思：是否成功
备注：与AVFormat_UNPack_Start函数互斥,不能同时使用
*********************************************************************/
extern "C" bool AVFormat_UNPack_Read(XHANDLE xhNet, int* pInt_AVIndex, XBYTE* ptszMSGBuffer, int* pInt_MSGLen, AVCODEC_PACKETINFO* pSt_AVPacket = NULL, double* pdlAVTime = NULL);
/********************************************************************
函数名称：AVFormat_UNPack_Seek
函数功能：移动当前媒体索引位置
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的媒体
 参数.二：nStreamIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的媒体的索引
 参数.三：dlTime
  In/Out：In
  类型：浮点型
  可空：N
  意思：输入移动的时间戳
返回值
  类型：逻辑型
  意思：是否成功
备注：建议先暂停在移动位置
*********************************************************************/
extern "C" bool AVFormat_UNPack_Seek(XHANDLE xhNet, int nStreamIndex, double dlTime);
/********************************************************************
函数名称：AVFormat_UNPack_Stop
函数功能：关闭一个音视频解封装器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" bool AVFormat_UNPack_Stop(XHANDLE xhNet);
/********************************************************************
函数名称：AVFormat_UNPack_GetStream
函数功能：获取流信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的流
 参数.二：pppSt_ListFile
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出可用的媒体信息列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出可用的流个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_UNPack_GetStream(XHANDLE xhNet, AVCODEC_STREAMINFO*** pppSt_ListFile, int* pInt_ListCount);
/********************************************************************
函数名称：AVFormat_UNPack_GetAVInfo
函数功能：获取音视频参数信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的流
 参数.二：nAVIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入索引
 参数.三：pSt_AVInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出获取到的媒体信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_UNPack_GetAVInfo(XHANDLE xhNet, int nAVIndex, XENGINE_PROTOCOL_AVINFO* pSt_AVInfo);
/********************************************************************
函数名称：AVFormat_UNPack_GetTime
函数功能：获取时间信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的流
 参数.二：nAVIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入索引,-1表示获取封包时间>-1获取流时间
 参数.三：pdlTime
  In/Out：Out
  类型：浮点型
  可空：Y
  意思：输出媒体总时长
 参数.四：pSt_AVTime
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出媒体时间基
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_UNPack_GetTime(XHANDLE xhNet, int nAVIndex, double* pdlTime = NULL, AVCODEC_TIMEBASE* pSt_AVTime = NULL);
/********************************************************************
函数名称：AVFormat_UNPack_GetStartTime
函数功能：获取媒体流开始时间
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的流
 参数.二：pdlTime
  In/Out：Out
  类型：浮点型
  可空：N
  意思：输出开始时间,比如0.12 秒开始
 参数.三：nAVIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入索引,-1为媒体索引,>=0表示流索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_UNPack_GetStartTime(XHANDLE xhNet, double* pdlTime, int nAVIndex = -1);
/********************************************************************
函数名称：AVFormat_UNPack_GetRate
函数功能：获取媒体文件码流信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的流
 参数.二：pInt_BitRate
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出码率
 参数.三：nAVIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：-1表示总码率,否则可以指定要获取码率的流索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_UNPack_GetRate(XHANDLE xhNet, __int64x* pInt_BitRate, int nAVIndex = -1);
/********************************************************************
函数名称：AVFormat_UNPack_GetAVCodec
函数功能：获取流信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的流
 参数.二：nAVIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的索引
 参数.三：pSt_AVParameter
  In/Out：Out
  类型：二级指针
  可空：Y
  意思：输出获取的编解码参数信息,AVCodecParameters类型.此参数需要释放内存
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVFormat_UNPack_GetAVCodec(XHANDLE xhNet, int nAVIndex, XHANDLE* pSt_AVParameter = NULL);