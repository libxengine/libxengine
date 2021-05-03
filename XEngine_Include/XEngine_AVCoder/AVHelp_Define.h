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
    CHAR tszKey[128];                                                    //获取到的键值,当作为设备列表获取时,这个表示缩写名称
    CHAR tszValue[256];                                                  //获取到的键值对应信息,当作为设备列表获取时,这个表示完整名称
}AVHELP_METAINFO;
typedef struct
{
    CHAR tszPacketName[64];                                               //封装格式名称
    __int64x nStartTime;                                                   //数据开始时间
    __int64x nCountTime;                                                   //音视频文件总播放时间
    int nNBStream;                                                        //流个数
    struct
    {
        CHAR tszCodecName[64];                                            //编码器名称
        __int64x nFrameCount;                                              //总帧数
        __int64x nBitRate;                                                 //码率
        int nCodecId;                                                     //编码器类型,音视频编解码定义的ENUM_AVCODEC_AUDIOTYPE和ENUM_AVCODEC_VEDIOTYPE
        int nFormat;                                                      //采样格式,音频AVCOLLECT_AUDIOSAMPLEFORMAT,视频AVCOLLECT_VIDEOSAMPLEFORMAT
        int nFrameRate;                                                   //帧率
        int nWidth;                                                       //图像宽度
        int nHeight;                                                      //图像高度
    }st_VideoMeta;
    struct
    {
        CHAR tszCodecName[64];
        __int64x nBitRate;
        int nCodecId;
        int nFormat;
        int nSampleRate;                                                  //采样率
        int nFrameSize;                                                   //大小
        int nChannel;                                                     //通道个数
        int nChannelLayout;                                               //通道层
    }st_AudioMeta;
}AVHELP_METADATA;
//设备信息
typedef struct
{
    int nCardNumber;                                                      //所属采集卡编号，编号从0开始
    int nDeviceNumber;                                                    //所属设备编号
    CHAR tszName[64];                                                    //设备名称
}AVHELP_DEVICEINFO;
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AVHelp_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     设备列表获取                                     */
/************************************************************************/
/********************************************************************
函数名称：AVHelp_Device_DeviceList
函数功能：枚举设备列表
 参数.一：pppStl_ListDevice
  In/Out：Out
  类型：指向指针的指针的指针
  可空：N
  意思：输出设备列表信息,需要用户手动释放内存
 参数.二：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
 参数.三：lpszInputName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要查找的设备类型,默认DSHOW
返回值
  类型：逻辑型
  意思：是否成功
备注：pppListDevice内存释放请调用BaseLib_OperatorMemory<AVHELP_METAINFO>
      的BaseLib_OperatorMemory_Free函数
*********************************************************************/
extern "C" BOOL AVHelp_Device_DeviceList(AVHELP_METAINFO * **pppStl_ListDevice, int* pInt_Count, LPCSTR lpszInputName = NULL);
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
extern "C" BOOL AVHelp_Device_EnumDevice(AVHELP_DEVICEINFO * **pppszAudioList, AVHELP_DEVICEINFO * **pppszVideoList, int* pInt_AudioCount, int* pInt_VideoCount);
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
extern "C" BOOL AVHelp_MetaInfo_Get(LPCSTR lpszFile, AVHELP_METADATA * pSt_MetaData, AVHELP_METAINFO * **pppSt_ListMetaInfo, int* pInt_ListCount, CHAR * ptszPICBuffer = NULL, int* pInt_PICLen = NULL);
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
extern "C" BOOL AVHelp_MetaInfo_Set(LPCSTR lpszSrcFile, LPCSTR lpszDstFile, AVHELP_METAINFO * **pppSt_ListMetaInfo, int nListCount);
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
extern "C" BOOL AVHelp_MetaInfo_GetStream(LPCSTR lpszFile, int *pInt_ACount, int *pInt_VCount);
/********************************************************************
函数名称：AVHelp_MetaInfo_Get264Hdr
函数功能：获取一个视频的SPS和PPS信息
 参数.一：lpszMemory
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
 参数.三：puszSPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的SPS缓冲区
 参数.四：puszPPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的PPS缓冲区
 参数.五：puszSEIBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的SEI缓冲区
 参数.六：puszIDLeave
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出SDP需要用的ID级别配置信息,这个缓冲区大小固定为3
 参数.七：pInt_SPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出SPS缓冲区大小
 参数.八：pInt_PPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出PPS缓冲区大小
 参数.九：pInt_SEILen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出SEI缓冲区大小
 参数.十：pInt_FixLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出起始字节个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVHelp_MetaInfo_Get264Hdr(LPCSTR lpszMemory, int nMsgLen, UCHAR * puszSPSBuffer = NULL, UCHAR * puszPPSBuffer = NULL, UCHAR * puszSEIBuffer = NULL, UCHAR * puszIDLeave = NULL, int* pInt_SPSLen = NULL, int* pInt_PPSLen = NULL, int* pInt_SEILen = NULL, int* pInt_FixLen = NULL);
/********************************************************************
函数名称：AVHelp_MetaInfo_Get265Hdr
函数功能：获取一个265视频的信息
 参数.一：lpszMemory
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
 参数.三：puszVPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的VPS缓冲区
 参数.四：puszSPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的SPS缓冲区
 参数.五：puszPPSBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：Y
  意思：导出获取到的PPS缓冲区
 参数.六：pInt_VPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出VPS缓冲区大小
 参数.七：pInt_SPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出SPS缓冲区大小
 参数.八：pInt_PPSLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出PPS缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVHelp_MetaInfo_Get265Hdr(LPCSTR lpszMemory, int nMsgLen, UCHAR * puszVPSBuffer = NULL, UCHAR * puszSPSBuffer = NULL, UCHAR * puszPPSBuffer = NULL, int* pInt_VPSLen = NULL, int* pInt_SPSLen = NULL, int* pInt_PPSLen = NULL);
/********************************************************************
函数名称：AVHelp_MetaInfo_Get265Paraset
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
extern "C" BOOL AVHelp_MetaInfo_Get265Paraset(UCHAR* lpszVPSBuffer, int nMsgLen, int* pInt_ProSpace = NULL, int* pInt_ProID = NULL, int* pInt_Flags = NULL, int* pInt_LevelID = NULL, CHAR* ptszICStr = NULL);
/********************************************************************
函数名称：AVHelp_MetaInfo_GetAACInfo
函数功能：获取AAC常规信息
 参数.一：lpszMemory
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
  可空：N
  意思：导出AAC音频通道
 参数.四：pInt_Sample
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出采样率
 参数.五：pInt_Profile
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出级别
 参数.六：pInt_Config
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出SDPconfig值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVHelp_MetaInfo_GetAACInfo(const UCHAR * lpszMemory, int nMsgLen, int* pInt_Channel, int* pInt_Sample, int* pInt_Profile, int* pInt_Config);
/********************************************************************
函数名称：AVHelp_MetaInfo_GetID3Info
函数功能：获取IDR3编码的头长度
 参数.一：lpszMemory
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入内存缓冲区
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供缓冲区的大小,输出获取到的ID3编码长度
返回值
  类型：逻辑型
  意思：是否成功
备注：ID3V2编码头信息,比如MP3就是采用的此头
*********************************************************************/
extern "C" BOOL AVHelp_MetaInfo_GetID3Info(LPCSTR lpszMemory, int* pInt_Len);
/********************************************************************
函数名称：AVHelp_MetaInfo_AACPacket
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
extern "C" BOOL AVHelp_MetaInfo_AACPacket(BYTE* pbyMsgBuffer, int nSampleRate, int nChannel, int nPKTLen);
