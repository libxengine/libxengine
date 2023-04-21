#pragma once
/********************************************************************
//	Created:	2019/12/19   15:33
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SDPProtocol\SDPProtocol_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SDPProtocol
//	File Base:	SDPProtocol_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	SDP协议模块导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    XCHAR tszCodecName[64];                                                //编码名册好难过,H264 H265 MPEG4-GENERIC(AAC)
    int nCodecNumber;                                                     //编码器编号,同媒体信息编码器编号
    int nSampleRate;                                                      //采样率
    int nChannel;                                                         //通道个数,音频才需要
}RFCCOMPONENTS_SDPPROTOCOL_RTPMAP;
typedef struct
{
    int nTrackID;                                                         //通道编号,用于表示媒体通道
    RFCCOMPONENTS_SDPPROTOCOL_RTPMAP st_RTPMap;
    //音频媒体信息,如果为NULL,表示没有音频传输
    struct
    {
        XCHAR tszMode[64];                                                 //编码器,AAC-hbr
        int nProfileID;                                                   //profile-level-id,复杂度类型
        int nConfig;                                                      //音频配置,具体参考定义比如AAC的ADTS
        //打包的时候不需要下面的值,采用默认
        int nSizeLen;                                                     //表示本段音频数据占用的字节数
        int nIndexLen;                                                    //表示本段的序号, 通常0开始
        int nDeltaLen;                                                    //表示本段序号与上一段序号的差值
    }st_FmtpAudio;
}RFCCOMPONENTS_SDPPROTOCOL_MEDIAAUDIO;
typedef struct
{
    int nTrackID;                                                         //通道编号,用于表示媒体通道
    RFCCOMPONENTS_SDPPROTOCOL_RTPMAP st_RTPMap;
    //视频媒体信息,如果为NULL,表示没有视频传输
    struct
    {
        XCHAR tszSPSBase[128];                                             //经过BASE64编码的SPS信息
        XCHAR tszPPSBase[128];                                             //经过BASE64编码的PPS信息
        XCHAR tszLeaveId[128];                                             //H.264的sps的第1个字节之后的3个字节(不包括第一个字节).如果是H265,表示VPS信息

        int nFrameXSize;                                                  //帧大小,可为0
        int nFrameYSize;                                                  //帧大小,可为0
        int nFrameRate;                                                   //帧率,可为0
        union
        {
            //H264参数
            struct
            {
                int nPacketMode;                                          //值为 1 时RTP打包H.264的NALU单元必须使用非交错(non-interleaved)封包模式.
            };
            //H265参数
            struct
            {
                XCHAR tszICStr[128];
                int nProSpace;
                int nProID;
                int nFlags;
                int nLevelID;
            };
        };
    }st_FmtpVideo;
}RFCCOMPONENTS_SDPPROTOCOL_MEDIAVIDEO;
typedef struct
{
    RFCCOMPONENTS_SDPPROTOCOL_MEDIAVIDEO st_MediaVideo;
    XCHAR tszAVType[128];
    int nCodec;
    int nCodecNumber;
}RFCCOMPONENTS_SDPPROTOCOL_AVVIDEO;
typedef struct
{
    RFCCOMPONENTS_SDPPROTOCOL_MEDIAAUDIO st_MediaAudio;
    XCHAR tszAVType[128];
    int nCodec;
    int nCodecNumber;
}RFCCOMPONENTS_SDPPROTOCOL_AVAUDIO;
//属性
typedef struct
{
    XCHAR tszAttrKey[128];                                               //某些情况下可能没有KEY,只有值
    XCHAR tszAttrValue[128];
}RFCCOMPONENTS_SDPPROTOCOL_ATTR;
//////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG SDPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                         SDP打包器导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SDPPacket_Create
函数功能：创建一个SDP会话
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建的SDP句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_Create(XNETHANDLE *pxhToken);
/********************************************************************
函数名称：RfcComponents_SDPPacket_Destory
函数功能：销毁SDP包管理器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_Destory(XNETHANDLE xhToken);
/********************************************************************
函数名称：RfcComponents_SDPPacket_GetPacket
函数功能：获取组包器当前组包完整内容
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出SDP协议缓冲区
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出SDP缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_GetPacket(XNETHANDLE xhToken, XCHAR *ptszMsgBuffer, int *pInt_Len);
/********************************************************************
函数名称：RfcComponents_SDPPacket_Owner
函数功能：设置会话标识源
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入用户名
 参数.三：nSessionID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入会话ID,此会话ID将会与会话版本关联,建议使用NTP时间
 参数.四：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：单播地址
 参数.五：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：IP版本,可支持IPV4,或者V6,默认V4
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数必须调用
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_Owner(XNETHANDLE xhToken, LPCXSTR lpszUserName, __int64x nSessionID, LPCXSTR lpszAddr, int nIPVer = 2);
/********************************************************************
函数名称：RfcComponents_SDPPacket_Session
函数功能：设置会话名称
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszSessionName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入会话名称
 参数.三：bVideo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：会话是音频函数视频
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数必须调用
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_Session(XNETHANDLE xhToken, LPCXSTR lpszSessionName, bool bVideo = true);
/********************************************************************
函数名称：RfcComponents_SDPPacket_KeepTime
函数功能：设置包活时间
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszTimeStart
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入NTP开始时间
 参数.二：lpszTimeEnd
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入NTP结束时间
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数必须调用
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_KeepTime(XNETHANDLE xhToken, LPCXSTR lpszTimeStart = NULL, LPCXSTR lpszTimeEnd = NULL);
/********************************************************************
函数名称：RfcComponents_SDPPacket_AddMedia
函数功能：添加媒体信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszAVType
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入媒体类型,audio or video
 参数.三：nCodec
  In/Out：In
  类型：整数型
  可空：N
  意思：媒体编码,比如H264就填写96
返回值
  类型：逻辑型
  意思：是否成功
备注：可选,可添加多个
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_AddMedia(XNETHANDLE xhToken, LPCXSTR lpszAVType, int nCodec);
/********************************************************************
函数名称：RfcComponents_SDPPacket_AttrAudio
函数功能：添加音频属性信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：pSt_SDPMedia
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入音频信息
返回值
  类型：逻辑型
  意思：是否成功
备注：可选,可添加多个,一般的添加完媒体后就需要添加音视频属性,然后在添加媒体在添加属性,这样循环
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_AttrAudio(XNETHANDLE xhToken, RFCCOMPONENTS_SDPPROTOCOL_MEDIAAUDIO *pSt_SDPMedia);
/********************************************************************
函数名称：RfcComponents_SDPPacket_AttrVideo
函数功能：添加视频属性信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：pSt_SDPMedia
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入视频信息
返回值
  类型：逻辑型
  意思：是否成功
备注：可选,可添加多个,一般的添加完媒体后就需要添加音视频属性,然后在添加媒体在添加属性,这样循环
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_AttrVideo(XNETHANDLE xhToken, RFCCOMPONENTS_SDPPROTOCOL_MEDIAVIDEO *pSt_SDPMedia);
//////////////////////////////////////////////////////////////////////////以下是可选函数
/********************************************************************
函数名称：RfcComponents_SDPPacket_OptionalMediaName
函数功能：添加一个媒体名称
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszMediaName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入媒体名称
返回值
  类型：逻辑型
  意思：是否成功
备注：此参数只可使用一次
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_OptionalMediaName(XNETHANDLE xhToken, LPCXSTR lpszMediaName);
/********************************************************************
函数名称：RfcComponents_SDPPacket_OptionalContact
函数功能：联系方式
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszEmailAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入联系人电子邮件
 参数.三：lpszPhoneNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入联系人的电话
返回值
  类型：逻辑型
  意思：是否成功
备注：可选函数,此参数仅允许调用一次
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_OptionalContact(XNETHANDLE xhToken, LPCXSTR lpszEmailAddr = NULL, LPCXSTR lpszPhoneNumber = NULL);
/********************************************************************
函数名称：RfcComponents_SDPPacket_OptionalBandwidth
函数功能：配置SDP带宽信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：nValue
  In/Out：In
  类型：整数型
  可空：N
  意思：带宽值,BITS
 参数.三：nType
  In/Out：In
  类型：整数型
  可空：Y
  意思：如果为0,表示此单一会话占用带宽,如果为其他值,表示所有会话占用带宽
返回值
  类型：逻辑型
  意思：是否成功
备注：可选函数,此参数仅允许调用一次
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_OptionalBandwidth(XNETHANDLE xhToken, int nValue, int nType = 0);
/********************************************************************
函数名称：RfcComponents_SDPPacket_OptionalRange
函数功能：播放时间范围选项
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszTimeStart
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入媒体开始时间
 参数.三：lpszTimeEnd
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入媒体结束时间,直播流一般不填写
返回值
  类型：逻辑型
  意思：是否成功
备注：可选函数,此参数仅允许调用一次
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_OptionalRange(XNETHANDLE xhToken, LPCXSTR lpszTimeStart = NULL, LPCXSTR lpszTimeEnd = NULL);
/********************************************************************
函数名称：RfcComponents_SDPPacket_OptionalAddAttr
函数功能：添加自定义属性
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP会话
 参数.二：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要添加的属性
 参数.三：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要添加的属性对应值,如果此参数为空,表示添加专有属性
返回值
  类型：逻辑型
  意思：是否成功
备注：可选函数,可添加多次
*********************************************************************/
extern "C" bool RfcComponents_SDPPacket_OptionalAddAttr(XNETHANDLE xhToken, LPCXSTR lpszKey, LPCXSTR lpszValue = NULL);
/************************************************************************/
/*                         SDP解析器导出函数                            */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SDPParse_Create
函数功能：创建一个SDP协议解析器
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出创建成功的句柄
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_Create(XNETHANDLE *pxhToken, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：RfcComponents_SDPParse_Destory
函数功能：销毁一个SDP协议解析器
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_Destory(XNETHANDLE xhToken);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetVersion
函数功能：获取版本
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pInt_Version
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出SDP版本号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetVersion(XNETHANDLE xhToken, int *pInt_Version);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetOwner
函数功能：获取源描述
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：ptszUserName
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的用户名
 参数.三：pInt_SessionID
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：会话ID
 参数.四：pInt_SessionVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：会话版本
 参数.五：pInt_IPVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：IP版本
 参数.六：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出单播地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetOwner(XNETHANDLE xhToken, XCHAR *ptszUserName, __int64x *pInt_SessionID, __int64x *pInt_SessionVer, int *pInt_IPVer, XCHAR *ptszIPAddr);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetConnect
函数功能：获取连接信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pInt_IPVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出IP版本
 参数.三：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出连接地址
 参数.四：pInt_TTL
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出TTL
 参数.五：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出地址个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetConnect(XNETHANDLE xhToken, int *pInt_IPVer, XCHAR *ptszIPAddr, int *pInt_TTL = NULL, int *pInt_Count = NULL);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetSession
函数功能：获取会话名称
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：ptszSessionValue
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出会话信息
 参数.三：ptszSessionName
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出会话名称
 参数.四：pbVideo
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：导出是视频还是音频会话
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetSession(XNETHANDLE xhToken, XCHAR* ptszSessionValue, XCHAR* ptszSessionName, bool* pbVideo);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetTime
函数功能：获取会话时间
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pInt_TimeStart
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出NTP开始时间
 参数.三：pInt_TimeEnd
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出NTP结束时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetTime(XNETHANDLE xhToken, __int64x* pInt_TimeStart, __int64x* pInt_TimeEnd);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetMediaVideo
函数功能：获取视频媒体信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pppSt_ListMedia
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的与视频相关的媒体信息
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetMediaVideo(XNETHANDLE xhToken, RFCCOMPONENTS_SDPPROTOCOL_AVVIDEO * **pppSt_ListMedia, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_SDPParse_GetMediaAudio
函数功能：获取音频媒体信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pppSt_ListMedia
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的与音频相关的媒体信息
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_GetMediaAudio(XNETHANDLE xhToken, RFCCOMPONENTS_SDPPROTOCOL_AVAUDIO * **pppSt_ListMedia, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_SDPParse_OptionalMediaName
函数功能：获取可选的媒体名称信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：ptszMediaName
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的媒体名称
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_OptionalMediaName(XNETHANDLE xhToken, XCHAR *ptszMediaName);
/********************************************************************
函数名称：RfcComponents_SDPParse_OptionalContact
函数功能：获取可选的联系方式
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：ptszEmailAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的电子邮件
 参数.三：ptszPhoneNumber
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出获取到的电话号码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_OptionalContact(XNETHANDLE xhToken, XCHAR *ptszEmailAddr = NULL, XCHAR *ptszPhoneNumber = NULL);
/********************************************************************
函数名称：RfcComponents_SDPParse_OptionalBandwidth
函数功能：获取可选的带宽信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pInt_Value
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的带宽值
 参数.三：pInt_Type
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的带宽类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_OptionalBandwidth(XNETHANDLE xhToken, int *pInt_Value, int *pInt_Type);
/********************************************************************
函数名称：RfcComponents_SDPParse_OptionalAttr
函数功能：获取可选附加属性字段
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的SDP
 参数.二：pppSt_ListAttr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的属性列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出媒体列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool RfcComponents_SDPParse_OptionalAttr(XNETHANDLE xhToken, RFCCOMPONENTS_SDPPROTOCOL_ATTR * **pppSt_ListAttr, int* pInt_ListCount);
