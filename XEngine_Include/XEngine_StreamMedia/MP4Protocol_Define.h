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
//                               导出的枚举型
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_FREE = 0,          //没有实际意义
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_FTYP = 1,          //用来指出当前文件遵循的规范
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MDAT = 2,          //音视频数据
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MOOV = 3,          //媒体的metadata信息，有且仅有一个,但可能包含多个BOX,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_UUID = 4,          //自定义类型
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MVHD = 30,         //FULLBOX.mp4文件的整体信息，比如创建时间、文件时长
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_TRAK = 31,         //媒体流信息
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_TKHD = 311,        //FULLBOX.流的元数据
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_EDTS = 312,        //可选,适用于存储的编辑列表
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_ELST = 3121,       //FULLBOX.这个Box包含了一个或多个编辑条目
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MDIA = 313,        //媒体信息，一般有多个
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MDHD = 3131,       //FULLBOX,媒体数据轨道相关的基本信息
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_HDLR = 3132,       //FULLBOX.声明当前track的类型，以及对应的处理器
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MINF = 3133,       //minf包含音视频相关的采样等信息
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_VMHD = 31331,      //FULLBOX.专门用于视频轨道
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_SMHD = 31332,      //专门用于音频轨道
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_HMHD = 31333,      //用于提示轨道.保存有关网络传输提示信息。仅在媒体承载网络流标准信息的轨道中存在
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_NMHD = 31334,      //FULLBOX,通常出现在无特定类型媒体数据的轨道中
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_DINF = 31335,      //定义了媒体数据实际存储的位置，可以是当前文件内也可以是外部文件
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STBL = 31336,      //是解析媒体数据非常关键的Box。它包含了媒体轨道的样本表
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STSD = 313361,     //FULLBOX.包含了描述样本格式的具体信息，例如对于视频轨道会包含编解码器信息，对于音频轨道会包含声道数、采样率等信息
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STTS = 313362,     //包含了样本的时间信息，用于映射样本和时间。主要描述了每个样本的持续时间，以及每个样本在媒体流中的顺序
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STSC = 313363,     //描述了样本与块（chunks）的映射关系。块是媒体数据的物理存储单元，包含一个或多个样本。stsc Box 定义了哪些样本属于哪个块
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STSZ = 313364,     //给出了每个样本的大小。对于所有样本都是同样大小的媒体数据，只需一个全局字段；如果不同样本有不同大小，则需要为每个样本分别指定
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STCO = 313365,     //描述了每个块在媒体流中的位置。对于小文件，stco足够使用，它的偏移量是32位的。对于大文件，需要使用co64，它的偏移量是64位的
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STSS = 313366,     //对于视频来说，这个Box包含关键帧（同步样本）的索引，允许直接定位到关键帧，主要用于快进等操作
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_CTTS = 313367,     //仅视频文件特有，存在于B帧编码的文件当中，用于说明样本的解码时间和表现（显示）时间的偏移量
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_SDTP = 313368,     //特殊BOX.每一个sample定义了specific sample dependency关系
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_AVC1 = 3133611,    //视频通道
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_MP4A = 3133612     //音频通道
}ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE;
//ESDS的TAG标签类型
typedef enum
{
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_FORBIDDEN = 0, 
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_OBJECTDESCR = 0x01,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_INITIALOBJECTDESCR = 0x02,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_DESCR = 0x03,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_DECODERCONFIGDESCR = 0x04,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_DECSPECIFICINFO = 0x05,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_SLCONFIGDESCR = 0x06,
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG_EXTSLCONFIGDESCR = 0x064
}ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_ESDS_TAG;
///////////////////////////////////////////////////////////////////////////////
//                               导出的数据结构
///////////////////////////////////////////////////////////////////////////////
typedef struct
{
	__int64u nHDRSize;
	ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE enHType;
	XSHOT nUType;      //自定义类型
	XBYTE byVersion;   //FULL存在
	XBYTE byFlags[3];  //FULL存在
}XENGINE_MP4HDR;
typedef struct
{
	XCHAR tszMajorBrand[8];               //主要兼容
	int nVersion;                         //版本
	int nListCount;                       //兼容列表 
	XCHAR **pptszListbrand;               //兼容性规范描述.4个字节
}XENGINE_HDRFTYP;
typedef struct
{
	__int64x nCreateTime;                 //创建的时间,从1904年1月1日开始的秒数,VERSION是0,4个字节,1,8个字节
	__int64x nModifyTime;                 //修改的时间,同上
	__int64x nDuration;                   //媒体时间
	int nTimeScale;                       //时间刻度,1000就是毫秒
	int nRate;                            //播放速度（[16.16]）,高16位、低16位分别代表整数部分、小数部分,比如65536 = 0001 0000.就是1.0 正常速度
	int nNTrackID;                        //下一个Track的ID号，确保该值大于任何当前Track的ID号
	XSHOT nVolume;                        //声音大小（[8.8]）
}XENGINE_HDRMVHD;
typedef struct
{
	__int64x nCreateTime;                 //创建的时间,从1904年1月1日开始的秒数,VERSION是0,4个字节,1,8个字节
	__int64x nModifyTime;                 //修改的时间,同上
	__int64x nDuration;                   //媒体时间
	int nTrackID;                         //轨道ID
	int nWidth;                           //视频宽
	int nHeight;                          //视频高
	XSHOT nLayer;                         //用于指定视频层次，决定轨道的前后关系。
	XSHOT nGroup;                         //轨道的组号，轨道可以归属于一组中，相同组的轨道会被同时考虑
	XSHOT nVolume;                        //音量
}XENGINE_HDRTKHD;
//////////////////////////////////////////////////////////////////////////TRACK
typedef struct
{
	__int64x nCreateTime;                 //创建的时间,从1904年1月1日开始的秒数,VERSION是0,4个字节,1,8个字节
	__int64x nModifyTime;                 //修改的时间,同上
	__int64x nDuration;                   //媒体时间
	int nTimeScale;                       //时间刻度
	XSHOT nLanguage;                      //语言编码
}XENGINE_HDRMDHD;
typedef struct
{
	XCHAR tszHandlerName[MAX_PATH];       //处理器名称
	XCHAR tszHandlerType[8];              //4个字节处理器:vide 视频,soun 音频,hint 轨道
}XENGINE_HDRHDLR;
typedef struct
{
	XSHOT nGraphicsMode;                  //定义视频合成模式，通常是0（表示复制，即直接显示视频数据）
	//颜色数据
	XSHOT nColorR;
	XSHOT nColorG;
	XSHOT nColorB;
	//一个固定点数，用于设置立体声平衡，通常置为0。左声道全左 (-1.0) 至右声道全右 (1.0) 都可以表示。对于单声道音频，这个字段通常被设置为0
	XSHOT nBalance;        
}XENGINE_HDRVMSMHD;

typedef struct
{
	XCHAR tszSPSBuffer[MAX_PATH];
	XCHAR tszPPSBuffer[MAX_PATH];
	XCHAR tszCompressorName[32];          //包含了视频压缩器的名称，可以为空
	int nHorizontalResolution;            //视频图像的水平分辨率,通常以像素/英寸为单位
	int nVerticalResolution;              //视频图像的垂直分辨率
	XSHOT nWidth;                         //宽
	XSHOT nHeight;                        //高
	XSHOT nFrameCount;                    //表明每个样本的帧数量，对于视频通常为1
	XSHOT nDepth;                         //图像深度，通常为0x0018，表明图像是彩色的
	XBYTE byConfigurationVersion;         //表明配置记录的版本，通常为1
	XBYTE byAVCProfileIndication;         //表明该轨道采用的是哪个AVC profile
	XBYTE byProfileCompatibility;         //与特定的Profile具有兼容性的标志
	XBYTE byAVCLevelIndication;           //表示轨道符合哪个AVC level
	XBYTE byLengthSizeMinusOne;           //使用的NALU长度标识字段的长度除以256后减去1的值（通常为3，表示长度使用4字节表示）
	XBYTE byNumOfSequenceParameterSets;   //表明后续SPS集合的数量
	XSHOT nSequenceParameterSetLength;    //后续SPS数据的长度
	XBYTE byNumOfPictureParameterSets;    //表明后续PPS集合的数量
	XSHOT nPictureParameterSetLength;     //后续PPS数据的长度
}XENGINE_HDRSTSDVIDEO;
typedef struct
{
	XCHAR tszDecodeInfo[MAX_PATH];        //解码器信息
	XCHAR tszControlInfo[MAX_PATH];       //流控制信息
	XCHAR tszURLFlags[MAX_PATH];          //URL地址
	int nMaxBitrate;                      //最大比特率
	int nAvgBitrate;                      //平均比特率
	int nSampleRate;                      //音频的采样率，采用固定小数点数表示，高16位为整数部分，低16位为小数部分
	XSHOT nChannle;                       //描述音频通道数量，例如，1代表单声道，2代表立体声
	XSHOT nSampleSize;                    //描述每个音频样本的位深度，例如，8位或16位等

	XSHOT nESID;                          //ESID
	XSHOT nDependID;                      //依赖ID
	XSHOT nORCTime;                       //ORC时间戳
	XBYTE byObjectType;                   //类型,比如0x40是AAC编码
}XENGINE_HDRSTSDAUDIO;
typedef struct
{
	XCHAR tszFormatStr[8];                //4个字节BOX类型
	XSHOT nRefIndex;                      //示这个样本应该用哪一个dref（Data Reference Box）中的条目来解码
}XENGINE_HDRSTSDTITLE;
typedef struct
{
	int nCount;                           //BOX数量
}XENGINE_HDRSTSD;
typedef struct
{
	XBYTE byIsLeading : 2;              //表示当前sample与解码顺序的关系
	XBYTE bySampleDependsOn : 2;        //表示当前sample是否依赖其他sample
	XBYTE bySampleIsDependentOn : 2;    //说明其他sample是否依赖该sample
	XBYTE bySampleHasRedundancy : 2;    //说明是否存在冗余sample可以替换当前sample
}XENGINE_HDRSDTP;
typedef struct
{
	//stts表示具有相同持续时间的连续样本的数量,表示有多少样本拥有下一个字段所指定的时间偏移量
	//ctts表示有多少样本拥有下一个字段所指定的时间偏移量
	//stsc表示当前入口描述的首个块的编号，从1开始计数
	//stsz描述每个样本的大小
	//stco标示块开始的位置（从文件开始处的偏移量)
	int nSampleCount;                     
	//stts表示每个样本持续的时间，单位为媒体的时间尺度
	//ctts对应样本的时间偏移量（composition time offset），如果版本0，则为无符号整数，如果版本1，则为有符号整数。时间偏移量修正了样本的解码时间，以指明它们应该在视频播放的哪个时间点被展示
	//stsc指定每个块所包含的样本数量
	int nSampleTime;
	//stsc这个字段通常与stsd Box中样本描述的索引相关联。如果所有样本都使用相同的样本描述，则此字段通常为1
	int nSampleIndex;
}XENGINE_HDRSAMPLENFO;
//支持STTS,CTTS
typedef struct
{
	int nCount;
	int nSize;              //如果是STSZ.>0 pppSt_ListStts有值,否则表示后面的样本个数都是相同值
	XENGINE_HDRSAMPLENFO*** pppSt_ListStts;
}XENGINE_HDRSAMPLE;
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" XLONG MP4Protocol_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
							 MP4解析器导出函数
******************************************************************************/
/********************************************************************
函数名称：MP4Protocol_Parse_Init
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
extern "C" bool MP4Protocol_Parse_Init(int nPoolCount);
/********************************************************************
函数名称：MP4Protocol_Parse_Destory
函数功能：销毁包队列解析器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_Destory();
/********************************************************************
函数名称：MP4Protocol_Parse_Insert
函数功能：插入一个用户到队列解析器
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要插入的ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_Insert(LPCXSTR lpszClientID);
/********************************************************************
函数名称：MP4Protocol_Parse_Delete
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
extern "C" bool MP4Protocol_Parse_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：MP4Protocol_Parse_Send
函数功能：发送一段数据给解析器
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
extern "C" bool MP4Protocol_Parse_Send(LPCXSTR lpszClientID, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：MP4Protocol_Parse_Recv
函数功能：获取当前数据信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：pSt_RTMPHdr
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出RTMP协议头信息
 参数.三：pInt_FilePos
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出当前数据处理位置,方便用户fseek操作文件或者内存
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数只获取当前解析到的BOX数据包协议数据,如果想获得负载数据,需要调用MP4Protocol_Parse_Get
	  此函数只是指明了模块解析到哪一步了,他不能回溯
	  由于MP4的文件特殊性,你需要对文件指针进行移动操作
*********************************************************************/
extern "C" bool MP4Protocol_Parse_Recv(LPCXSTR lpszClientID, XENGINE_MP4HDR* pSt_MP4Hdr, __int64u * pInt_FilePos = NULL);
/********************************************************************
函数名称：MP4Protocol_Parse_GetFTyp
函数功能：获取FTYP头协议类型的信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：pSt_HDRFtyp
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出MP4头信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetFTyp(LPCXSTR lpszClientID, XENGINE_HDRFTYP * pSt_HDRFtyp);
/********************************************************************
函数名称：MP4Protocol_Parse_GetMVhd
函数功能：获取MP4的媒体信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：pSt_HDRMvhd
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetMVhd(LPCXSTR lpszClientID, XENGINE_HDRMVHD* pSt_HDRMvhd);
/********************************************************************
函数名称：MP4Protocol_Parse_GetTrack
函数功能：获取MP4的TRACK列表
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：pInt_TrackList
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：提供一个int[10] 的整数数组,输出拥有的TRACKID列表
返回值
  类型：逻辑型
  意思：是否成功
备注：trackid >= 0,初始化所有列表-1
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetTrack(LPCXSTR lpszClientID, int* pInt_TrackList);
/********************************************************************
函数名称：MP4Protocol_Parse_GetTrackInfo
函数功能：获取TRACK信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：nTrackID
  In/Out：Out
  类型：整数型
  可空：N
  意思：输入要获得的TRACK_ID
 参数.三：pSt_HDRtkhd
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出元数据信息
 参数.四：pSt_HDRmdhd
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出媒体轨道信息
 参数.五：pSt_HDRhdlr
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出媒体类型和处理器
 参数.六：pSt_HDRvsmhd
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：音视频轨道信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetTrackInfo(LPCXSTR lpszClientID, int nTrackID, XENGINE_HDRTKHD* pSt_HDRtkhd = NULL, XENGINE_HDRMDHD* pSt_HDRmdhd = NULL, XENGINE_HDRHDLR* pSt_HDRhdlr = NULL, XENGINE_HDRVMSMHD* pSt_HDRvsmhd = NULL);
/********************************************************************
函数名称：MP4Protocol_Parse_GetTrackList
函数功能：获取媒体数据信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：nTrackID
  In/Out：Out
  类型：整数型
  可空：N
  意思：输入要获得的TRACK_ID
 参数.三：pppSt_TrackList
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的指定TRACK媒体信息列表数据
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
 参数.五：enHType
  In/Out：Out
  类型：枚举型
  可空：N
  意思：输入要获取的媒体信息.支持以下数据列表
		ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STTS,ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_CTTS
		ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STSC,ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STSZ
		ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE_STCO
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetTrackList(LPCXSTR lpszClientID, int nTrackID, XENGINE_HDRSAMPLENFO*** pppSt_TrackList, int* pInt_ListCount, ENUM_XENGINE_STREAMMEDIA_MP4PROTCOL_HTYPE enHType);
/********************************************************************
函数名称：MP4Protocol_Parse_GetTrackKey
函数功能：获取视频轨道的关键帧数据列表
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：nTrackID
  In/Out：Out
  类型：整数型
  可空：N
  意思：输入要获得的TRACK_ID
 参数.三：pppInt_KeyList
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的指定列表数据
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetTrackKey(LPCXSTR lpszClientID, int nTrackID, int*** pppInt_KeyList, int* pInt_ListCount);
/********************************************************************
函数名称：MP4Protocol_Parse_GetTrackSDtp
函数功能：输出采样数据关联信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的ID
 参数.二：nTrackID
  In/Out：Out
  类型：整数型
  可空：N
  意思：输入要获得的TRACK_ID
 参数.三：pppSt_SDTPList
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的指定列表数据
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Parse_GetTrackSDtp(LPCXSTR lpszClientID, int nTrackID, XENGINE_HDRSDTP*** pppSt_SDTPList, int* pInt_ListCount);
/********************************************************************
函数名称：MP4Protocol_Parse_GetPool
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
extern "C" bool MP4Protocol_Parse_GetPool(int nPoolIndex, XENGINE_MANAGEPOOL_TASKEVENT*** pppSt_ListAddr, int* pInt_ListCount);
/************************************************************************
函数名称：MP4Protocol_Parse_WaitEvent
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
extern "C" bool MP4Protocol_Parse_WaitEvent(int nPoolIndex, int nTimeOut = -1);
/********************************************************************
函数名称：MP4Protocol_Parse_ActiveEvent
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
extern "C" bool MP4Protocol_Parse_ActiveEvent(int nPoolIndex);
/******************************************************************************
							 MP4打包器导出函数
******************************************************************************/
/********************************************************************
函数名称：MP4Protocol_Packet_Insert
函数功能：插入一个客户端到封包器中
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
extern "C" bool MP4Protocol_Packet_Insert(LPCXSTR lpszClientID);
/********************************************************************
函数名称：MP4Protocol_Packet_Delete
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
extern "C" bool MP4Protocol_Packet_Delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：MP4Protocol_Packet_HDRBox
函数功能：封装一个通用的BOX头
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出封装好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：lpszHDRStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入协议头类型,比如:FTYP.4个字节
 参数.五：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入负载数据
 参数.六：nMSGLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入负载数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_HDRBox(LPCXSTR lpszClientID, XCHAR * ptszMSGBuffer, int* pInt_MSGLen, LPCXSTR lpszHDRStr, LPCXSTR lpszMSGBuffer = NULL, int nMSGLen = 0);
/********************************************************************
函数名称：MP4Protocol_Packet_FTyp
函数功能：封装一个FTYP头
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出封装好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：第一个头数据
*********************************************************************/
extern "C" bool MP4Protocol_Packet_FTyp(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：MP4Protocol_Packet_MVhd
函数功能：打包MVHD的BOX头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：nTimeDuration
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入媒体播放时长,代表媒体最大时长
 参数.五：nTimeScale
  In/Out：In
  类型：整数型
  可空：N
  意思：输入时长刻度,默认1000毫秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_MVhd(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, int nTimeDuration = 0, int nTimeScale = 1000);
/********************************************************************
函数名称：MP4Protocol_Packet_TKhd
函数功能：打包TKHD的BOX头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：nVolum
  In/Out：In
  类型：整数型
  可空：Y
  意思：如果是音频轨道,此值需要输入值,比如0x0100,代表正常音量,否则为0
 参数.五：nWidth
  In/Out：In
  类型：整数型
  可空：Y
  意思：如果是视频轨道,这个参数需要输入值,代表宽,否则为0
 参数.六：nHeight
  In/Out：In
  类型：整数型
  可空：Y
  意思：如果是视频轨道,这个参数需要输入值,代表高,否则为0
 参数.七：nTimeDuration
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入媒体播放时长
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_TKhd(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, int nVolum = 0, int nWidth = 0, int nHeight = 0, int nTimeDuration = 0);
/********************************************************************
函数名称：MP4Protocol_Packet_MDhd
函数功能：打包MDHD的BOX头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：nLanguage
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入语言,ISO-639-2/T标准代码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_MDhd(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, XSHOT nLanguage = 21956);
/********************************************************************
函数名称：MP4Protocol_Packet_HDlr
函数功能：打包HDLR的BOX头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：byType
  In/Out：In
  类型：字符型
  可空：Y
  意思：类型,0视频,1音频,2提示,3元数据,4文本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_HDlr(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, XBYTE byType = 0);
/********************************************************************
函数名称：MP4Protocol_Packet_VMhd
函数功能：打包MINF的VMHD头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_VMhd(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：MP4Protocol_Packet_SMhd
函数功能：打包MINF的SMHD头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：nVolum
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入声音平衡值,0表示左右,-1左边,1右边
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_SMhd(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, short int nVolum = 0);
/********************************************************************
函数名称：MP4Protocol_Packet_DInf
函数功能：打包MINF的DINF头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_DInf(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：MP4Protocol_Packet_STsd
函数功能：打包STBL的STSD头协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：pSt_AVInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入音视频数据信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_STsd(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, XENGINE_PROTOCOL_AVINFO* pSt_AVInfo);
/********************************************************************
函数名称：MP4Protocol_Packet_STts
函数功能：打包STTS显示时间戳
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
 参数.四：bVideo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：数据是视频还是音频
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_STts(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, bool bVideo = true);
/********************************************************************
函数名称：MP4Protocol_Packet_CTts
函数功能：CTTS打包,仅视频可用,代表DTS解码时间戳
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
返回值
  类型：逻辑型
  意思：是否成功
备注：一般B帧存在才有
*********************************************************************/
extern "C" bool MP4Protocol_Packet_CTts(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：MP4Protocol_Packet_STss
函数功能：STSS打包,仅视频可用,代表关键帧在哪一个索引
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_STss(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：MP4Protocol_Packet_STsc
函数功能：STSC打包,默认打包,每个采样代表每个帧
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
返回值
  类型：逻辑型
  意思：是否成功
备注：音视频数据都一样
*********************************************************************/
extern "C" bool MP4Protocol_Packet_STsc(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen);
/********************************************************************
函数名称：MP4Protocol_Packet_STsz
函数功能：打包STSZ每帧数据大小
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
 参数.四：bVideo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：数据是视频还是音频
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_STsz(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, bool bVideo = true);
/********************************************************************
函数名称：MP4Protocol_Packet_STco
函数功能：打包STCO数据偏移起始地址
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
 参数.四：bVideo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：数据是视频还是音频
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_STco(LPCXSTR lpszClientID, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, bool bVideo = true);
/********************************************************************
函数名称：MP4Protocol_Packet_FrameVideo
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
 参数.六：nOffset
  In/Out：In
  类型：整数型
  可空：Y
  意思：文件偏移位置,根据你写入的文件指针输入内容.当前文件指针位置
 参数.七：nFrameType
  In/Out：In
  类型：整数型
  可空：Y
  意思：帧类型,1为关键帧,否则为其他帧
 参数.八：nPTSVlaue
  In/Out：In
  类型：整数型
  可空：Y
  意思：PTS显示时间戳,表示一帧显示时间,比如25帧.这个值就是 1000 / 25 = 40
 参数.九：nDTSVlaue
  In/Out：In
  类型：整数型
  可空：Y
  意思：DTS解码时间戳,只有在B帧存在才需要填写此值,表示解码的偏移时间,支持正负偏移
返回值
  类型：逻辑型
  意思：是否成功
备注：打包视频数据,视频数据开头必须是00 00 00 01(00 00 01)的完整NAL
*********************************************************************/
extern "C" bool MP4Protocol_Packet_FrameVideo(LPCXSTR lpszClientID, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMSGBuffer, int nMsgLen, __int64x nOffset, int nFrameType = 0, int nPTSVlaue = 0, int nDTSVlaue = 0);
/********************************************************************
函数名称：MP4Protocol_Packet_FrameAudio
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
 参数.六：nOffset
  In/Out：In
  类型：整数型
  可空：Y
  意思：文件偏移位置,根据你写入的文件指针输入内容.当前文件指针位置
 参数.七：nPTSVlaue
  In/Out：In
  类型：整数型
  可空：Y
  意思：PTS显示时间戳,表示一帧采样大小,比如1024
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MP4Protocol_Packet_FrameAudio(LPCXSTR lpszClientID, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMSGBuffer, int nMsgLen, __int64x nOffset, int nPTSVlaue = 0);