#pragma once
/********************************************************************
//	Created:	2017/5/4   10:39
//	Filename: 	P:\NetEngine_Windows\NetEngine_SourceCode\NetEngien_AvCoder\NetEngine_AVHelp\AVHelp_Define.h
//	File Path:	P:\NetEngine_Windows\NetEngine_SourceCode\NetEngien_AvCoder\NetEngine_AVHelp
//	File Base:	AVHelp_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音视频编解码帮助模块导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_AVHelp_MetaInfo
{
    XCHAR tszKey[128];                                                    //获取到的键值,当作为设备列表获取时,这个表示缩写名称
    XCHAR tszValue[256];                                                  //获取到的键值对应信息,当作为设备列表获取时,这个表示完整名称
}AVHELP_METAINFO;
typedef struct
{
    XCHAR tszPacketName[64];                                              //封装格式名称
    __int64x nStartTime;                                                  //数据开始时间
    __int64x nCountTime;                                                  //音视频文件总播放时间
    int nNBStream;                                                        //流个数
    XENGINE_PROTOCOL_AVINFO** ppSt_AVList;
}AVHELP_METADATA;
//设备信息
typedef struct
{
    AVHELP_METAINFO st_MetaInfo;                                          //设备名称
    int nDeviceInout;                                                     //设备是输入还是输出,0输入,1输出
    int nDeviceType;                                                      //设备类型
}AVHELP_DEVICEINFO;
//帧信息
typedef struct 
{
	XBYTE *ptszMsgBuffer;                                                 //获取到的缓冲区,需要通过free释放内存
	int nMsgLen;                                                          //缓冲区大小
}AVHELP_FRAMEDATA;
//SPS信息
typedef struct
{
    XBYTE byProfileID;                                                    //档次,基本:baseline(66),主要:baseline(77),扩展:extended(88),High:100
    XBYTE byLevelID;                                                      //码流级别,比如30 = 3.0 31 = 3.1 41 = 4.1
    int nFrameWidth;                                                      //图像宽
    int nFrameHeigth;                                                     //图像高
    int nFrameFPS;                                                        //这个值可能不对
}AFHELP_FRAMESPS;
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AVHelp_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     设备列表获取                                     */
/************************************************************************/
/********************************************************************
函数名称：AVHelp_Device_EnumDevice
函数功能：枚举可用设备
 参数.一：pppszAudioList
  In/Out：Out
  类型：指向指针的指针的指针
  可空：Y
  意思：输出音频设备列表,需要手动释放内存
 参数.二：pppszVideoList
  In/Out：Out
  类型：指向指针的指针的指针
  可空：Y
  意思：输出视频设备列表,需要手动释放内存
 参数.三：pInt_AudioCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出音频设备列表个数
 参数.四：pInt_VideoCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出视频设备列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数使用了COM,需要调用下面的函数初始化和反初始化才能使用
      内存释放请调用BaseLib_OperatorMemory<AVHELP_METAINFO>
      的BaseLib_OperatorMemory_Free函数
*********************************************************************/
extern "C" bool AVHelp_Device_EnumDevice(AVHELP_DEVICEINFO * **pppszAudioList, AVHELP_DEVICEINFO * **pppszVideoList, int* pInt_AudioCount, int* pInt_VideoCount);
/************************************************************************/
/*                     媒体信息接口                                     */
/************************************************************************/
/********************************************************************
函数名称：AVHelp_MetaInfo_Get
函数功能：获取ID3V2的媒体信息
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的文件路径
 参数.二：pSt_MetaData
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的媒体数据信息
 参数.三：pppSt_ListMetaInfo
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的参数信息
 参数.四：pInt_ListCount
  In/Out：In/Out
  类型：字符指针
  可空：Y
  意思：导出获取到的参数个数
 参数.五：ptszPICBuffer
  In/Out：In/Out
  类型：字符指针
  可空：Y
  意思：导出媒体文件的封面图片，如果有的话,为NULL不导出
 参数.六：pInt_PICLen
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小，输出获取到的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：参数三必须调用基础库的内存释放函数BaseLib_OperatorMemory_Free
*********************************************************************/
extern "C" bool AVHelp_MetaInfo_Get(LPCXSTR lpszFile, AVHELP_METADATA * pSt_MetaData, AVHELP_METAINFO * **pppSt_ListMetaInfo, int* pInt_ListCount, XCHAR * ptszPICBuffer = NULL, int* pInt_PICLen = NULL);
/********************************************************************
函数名称：AVHelp_MetaInfo_Set
函数功能：设置媒体信息
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要设置的原始音视频文件
 参数.二：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：设置后保存的音视频文件
 参数.三：pppSt_ListMetaInfo
  In/Out：In
  类型：三级指针
  可空：N
  意思：要设置的值列表,此内存由调用者管理
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：要设置的参数个数
返回值
  类型：逻辑型
  意思：是否成功
备注：AVHELP_METAINFO的值会自动转为UTF8
*********************************************************************/
extern "C" bool AVHelp_MetaInfo_Set(LPCXSTR lpszSrcFile, LPCXSTR lpszDstFile, AVHELP_METAINFO * **pppSt_ListMetaInfo, int nListCount);
/********************************************************************
函数名称：AVHelp_MetaInfo_GetStream
函数功能：获取流信息
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的音视频文件地址
 参数.二：pInt_ACount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出可用的音频流个数
 参数.三：pInt_VCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出可用的视频流个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_MetaInfo_GetStream(LPCXSTR lpszFile, int *pInt_ACount, int *pInt_VCount);
/************************************************************************/
/*                     媒体解析器                                       */
/************************************************************************/
/********************************************************************
函数名称：AVHelp_Parse_NaluHdr
函数功能：解析NALU单元,支持H264和H265
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入数据大小
 参数.三：pInt_NaluLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出使用的大小
 参数.四：pInt_FixLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出起始字节码个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_NaluHdr(LPCXSTR lpszMsgBuffer, int nMsgLen, int* pInt_NaluLen, int* pInt_FixLen = NULL);
/********************************************************************
函数名称：AVHelp_Parse_NaluType
函数功能：获取NALU单元的类型
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.二：enVideoType
  In/Out：In
  类型：枚举型
  可空：Y
  意思：输入视频类型
 参数.三：pen_FrameType
  In/Out：Out
  类型：枚举型
  可空：Y
  意思：输出帧类型
 参数.四：pInt_StartCode
  In/Out：Out
  类型：整数型
  可空：Y
  意思：输出帧的起始码个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_NaluType(LPCXSTR lpszMsgBuffer, ENUM_AVCODEC_VIDEOTYPE enVideoType, XENGINE_AVCODEC_VIDEOFRAMETYPE * pen_FrameType = NULL, int* pInt_StartCode = NULL);
/********************************************************************
函数名称：AVHelp_Parse_VideoHdr
函数功能：获取一个视频的SPS和PPS信息
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
 参数.三：enVideoType
  In/Out：Out
  类型：枚举型
  可空：Y
  意思：输入要解析的视频是264还是265
 参数.四：puszVPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的VPS缓冲区
 参数.五：puszSPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的SPS缓冲区
 参数.六：puszPPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的PPS缓冲区
 参数.七：puszSEIBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的SEI缓冲区
 参数.八：pInt_VPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出VPS缓冲区大小
 参数.九：pInt_SPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出SPS缓冲区大小
 参数.十：pInt_PPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出PPS缓冲区大小
 参数.十一：pInt_SEILen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出SEI缓冲区大小
 参数.十二：pInt_Pos
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出解析到的数据位置
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_VideoHdr(LPCXSTR lpszMsgBuffer, int nMsgLen, ENUM_AVCODEC_VIDEOTYPE enVideoType, XBYTE * puszVPSBuffer = NULL, XBYTE * puszSPSBuffer = NULL, XBYTE * puszPPSBuffer = NULL, XBYTE * puszSEIBuffer = NULL, int* pInt_VPSLen = NULL, int* pInt_SPSLen = NULL, int* pInt_PPSLen = NULL, int* pInt_SEILen = NULL, int* pInt_Pos = NULL);
/********************************************************************
函数名称：AVHelp_Parse_VPSInfo
函数功能：获取H265参数集
 参数.一：lpszVPSBuffer
  In/Out：In
  类型：字符指针
  可空：N
  意思：输入要解析的数据,提供VPS信息
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.三：pInt_ProSpace
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出通用配置空间信息
 参数.四：pInt_ProID
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出ID信息
 参数.五：pInt_Flags
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出通用层标志信息
 参数.六：pInt_LevelID
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出级别ID信息
 参数.七：ptszICStr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出操作约束信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_VPSInfo(XBYTE* lpszVPSBuffer, int nMsgLen, int* pInt_ProSpace = NULL, int* pInt_ProID = NULL, int* pInt_Flags = NULL, int* pInt_LevelID = NULL, XCHAR* ptszICStr = NULL);
/********************************************************************
函数名称：AVHelp_Parse_SPSInfo
函数功能：SPS信息解析
 参数.一：lpszSPSBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的大小
 参数.三：pSt_SPSInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析后的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_SPSInfo(LPCXSTR lpszSPSBuffer, int nMsgLen, AFHELP_FRAMESPS* pSt_SPSInfo);
/********************************************************************
函数名称：AVHelp_Parse_AACInfo
函数功能：获取AAC音频常规信息
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
 参数.三：pInt_Channel
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出AAC音频通道
 参数.四：pInt_Sample
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出采样率
 参数.五：pInt_Profile
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出级别
 参数.六：pInt_Config
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出SDPconfig值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_AACInfo(const XBYTE* lpszMsgBuffer, int nMsgLen, int* pInt_Channel = NULL, int* pInt_Sample = NULL, int* pInt_Profile = NULL, int* pInt_Config = NULL);
/********************************************************************
函数名称：AVHelp_Parse_GetVolume
函数功能：获得音频的音量分贝值
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入PCM缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入音频大小
 参数.三：pInt_Volume
  In/Out：Out
  类型：双精度浮点型指针
  可空：N
  意思：输出音量
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_GetVolume(LPCXSTR lpszMsgBuffer, int nMsgLen, double* pInt_Volume);
/********************************************************************
函数名称：AVHelp_Parse_Fix264or265Enum
函数功能：删除缓冲区中多余的仿真元素
 参数.一：ptszMSGBuffer
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要修复的缓冲区,输出修复后的缓冲区
 参数.二：pInt_MSGLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲大小,删除获取到的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_Fix264or265Enum(XBYTE* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：AVHelp_Parse_FrameInit
函数功能：初始化帧分离器
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出初始化后的句柄
 参数.二：nCodecID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入编码ID,H264,AAC等
返回值
  类型：逻辑型
  意思：是否成功
备注：解析出来的数据是带头的,比如H264 00 00 00 01.
*********************************************************************/
extern "C" bool AVHelp_Parse_FrameInit(XNETHANDLE* pxhToken, int nCodecID);
/********************************************************************
函数名称：AVHelp_Parse_FrameGet
函数功能：解析并且获取一帧
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入操作句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.四：pppSt_Frame
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析好的缓冲区队列
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出队列个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Parse_FrameGet(XNETHANDLE xhToken, LPCXSTR lpszMsgBuffer, int nMsgLen, AVHELP_FRAMEDATA * **pppSt_Frame, int* pInt_ListCount);
/********************************************************************
函数名称：AVHelp_Parse_FrameClose
函数功能：关闭帧解析器
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
extern "C" bool AVHelp_Parse_FrameClose(XNETHANDLE xhToken);
/************************************************************************/
/*                     媒体打包器                                       */
/************************************************************************/
/********************************************************************
函数名称：AVHelp_Packet_AACHdr
函数功能：AAC头封装
 参数.一：pbyMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出封装好的AAC ADTS头
 参数.二：nSampleRate
  In/Out：In
  类型：整数型
  可空：N
  意思：输入采样率
 参数.三：nChannel
  In/Out：In
  类型：整数型
  可空：N
  意思：输入通道个数
 参数.四：nPKTLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入AAC包大小
返回值
  类型：逻辑型
  意思：是否成功
备注：导出的数据大小固定为7字节
*********************************************************************/
extern "C" bool AVHelp_Packet_AACHdr(XBYTE* pbyMsgBuffer, int nSampleRate, int nChannel, int nPKTLen);
/********************************************************************
函数名称：AVHelp_Packet_H26XFormat
函数功能：H264,265封装格式处理
 参数.一：ptszMSGBuffer
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要处理的缓冲区,输出输出成功的缓冲区
 参数.二：nMSGLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.三：byType
  In/Out：In
  类型：字符型
  可空：Y
  意思：0x00表示AVCC,0x01表示AnnexB
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AVHelp_Packet_H26XFormat(XCHAR* ptszMSGBuffer, int nMSGLen, XBYTE byType = 0x00);