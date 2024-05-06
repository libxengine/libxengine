#pragma once
/********************************************************************
//    Created:     2017/07/09  16:36:47
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_ProtocolHdr.h
//    File Path:   D:\XEngine\XEngine_SourceCode
//    File Base:   XEngine_ProtocolHdr
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     公用协议头文件
//    History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////
//                          导出的数据定义
///////////////////////////////////////////////////////////////////////////
/*************************************************************************
						 协议头
*************************************************************************/
#define XENGIEN_COMMUNICATION_PACKET_PROTOCOL_HEADER 0x11               //固定填充头部
#define XENGIEN_COMMUNICATION_PACKET_PROTOCOL_TAIL 0xFF                 //固定填充尾部
/*********************************************************************
												操作类型定义
*********************************************************************/
typedef enum en_XEngine_XComm_Protocol
{
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_NORMAL = 0,                   //普通协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XLOG = 1,                     //网络日志协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_AUTH = 2,                     //网络验证服务协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_SMS = 3,                      //流媒体协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_STORAGE = 4,                  //存储服务协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_BACK = 5,                     //后台协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_P2XP = 6,                     //P2XP协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XMQ = 7,                      //消息队列服务
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_UDX = 8,                      //UDX协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_HEARTBEAT = 0x1A,             //心跳协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_CHUNKED = 0x1B,               //CHUNKED包模式，使用此模式协议头的unPacketSize字段Post将无效
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_LEAVE = 0x1C,                 //离开包，投递了这个包后后续包都将被抛弃
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_USER = 100                    //用户包,用户自定义包开始为101开始100以内为协议内部保留
}ENUM_XXENGINE_XCOMM_PROTOCOL;
//客户端类型
#ifndef _MSC_BUILD
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
static LPCXSTR lpszXClientType[4] = { "UNKNOW","USER","SERVICE","PROXY" };
typedef enum en_ProtocolClient_Type
{
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_UNKNOW = 0,
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_USER = 1,
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_SERVICE = 2,
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_PROXY = 3
}ENUM_PROTOCOLCLIENT_TYPE, * LPENUM_PROTOCOLCLIENT_TYPE;
//客户端设备类型
static LPCXSTR lpszXDevType[40] = { "UNKNOW"
                                  ,"PC-WINDOWS","PC-LINUX","PC-UNIX","PC-MACOS","PC","PC","PC","PC","PC"
								  ,"PAD-SURFACE","PAD-ANDROID","PAD-IPAD","PAD","PAD","PAD","PAD","PAD","PAD","PAD"
								  ,"MOBILE-ANDROID","MOBILE-IOS","MOBILE-EMBEDDED","MOBILE","MOBILE","MOBILE","MOBILE","MOBILE","MOBILE","MOBILE"
								  ,"WEB-IE","WEB-EDGE","WEB-CHROME","WEB-FIREFOX","WEB-SAFARI","WEB-OPERA","WEB-RESTFUL","WEB-LIKEGG","WEB" ,"WEB" };
typedef enum en_ProtocolDevice_Type
{
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_UNKNOW = 0,
	//1-9 PC客户端平台
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PC_WINDOWS = 1,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PC_LINUX = 2,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PC_UNIX = 3,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PC_MACOS = 4,
	//10-19 平板电脑
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PAD_SURFACE = 10,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PAD_ANDROID = 11,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PAD_IPAD = 12,
	//20-29 移动平台
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_MOBILE_ANDROID = 20,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_MOBILE_IOS = 21,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_MOBILE_EMBEDDED = 22,
	//30-39 前端网页
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_IE = 30,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_EDGE = 31,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_CHROME = 32,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_FIREFOX = 33,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_SAFARI = 34,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_OPERA = 35,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_RESTFUL = 36,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB_LIKEGG = 39,
	//其他
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_OTHER = 99,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_ALL = 100
}ENUM_PROTOCOLDEVICE_TYPE, * LPENUM_PROTOCOLDEVICE_TYPE;
//负载类型
static LPCXSTR lpszXLoadType[10] = { "UNKNOW","BIN","JSON","BSON","XML","STRING","ZIP","PIC","VIDEO","AUDIO" };
typedef enum en_XEngine_ProtocolHdr_Payload_Type
{
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_UNKNOW = 0,                   //未定义,或者没有后续
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_BIN = 1,                      //二进制
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_JSON = 2,                     //JSON
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_BSON = 3,                     //BSON
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_XML = 4,                      //XML
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_STRING = 5,                   //文本或者字符串
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_ZIP = 6,                      //压缩文件
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_PIC = 7,                      //图片
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_VIDEO = 8,                    //视频
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_AUDIO = 9,                    //音频
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_SYSTEM = 99,                  //系统保留
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_USER = 100                    //用户使用
}ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE;
//加密类型
static LPCXSTR lpszXCryptoType[5] = { "UNKNOW","AES","DES","RSA","XCRYPT" };
typedef enum en_XEngine_ProtocolHdr_Crypto_Type
{
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_UNKNOW = 0,                    //没有加密
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_AES = 1,                       //AES
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_DES = 2,                       //DES
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_RSA = 3,                       //RSA
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_XCRYPT = 4,                    //X加解密
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_SYSTEM = 5,                    //系统保留
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_USER = 10                      //用户使用
}ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE;
//权限级别
static LPCXSTR lpszXLevelType[21] = { "BAN","ROOT","ADMIN","REVIEW","OB","4","5","6","7","8","9","SVIP","VIP","12","13","14","15","16","17","18","USER" };
typedef enum en_XEngine_ProtocolHdr_Level_Type
{
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_BAN = -1,                       //封禁
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_ROOT = 0,                       //超级用户
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_ADMIN = 1,                      //管理员
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_REVIEW = 2,                     //审查
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_OB = 3,                         //观察者
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_SVIP = 10,                      //超级VIP
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_VIP = 11,                       //VIP
	ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE_USER = 20,                      //普通用户
}ENUM_XENGINE_PROTOCOLHDR_LEVEL_TYPE;
#ifndef _MSC_BUILD
#pragma GCC diagnostic pop
#endif
/**************************************************************************
						  操作码定义,不能超过0xFFFF大小
**************************************************************************/
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_ISOK 0x0001                 //通用成功
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_ISFAILED 0x0002             //通用失败
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_LEAVE 0x000A                //离开包
//日志协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_XLOG_PUSH 0x1001            //日志推送的消息
//网络验证服务子协议
//---使用0x2xxx..参考网络验证服务
//流媒体协议
//---使用0x3xxx..参考流媒体服务
//存储服务协议
//---使用0x4xxx..参考存储服务
//后台服务协议
//---使用0x5xxx..参考后台控制服务
//P2XP协议
//---使用0x6xxx..参考存储服务
//消息队列协议
//---使用0x7xxx..参考消息队列服务
//消息分发服务
//---使用0x8xxx..参考消息队列服务
//UDX通信协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_TRANSMISSION 0x9000     //数据通信协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_LOGINREQ 0x9001         //请求登录
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_LOGINREP 0x9002         //登录回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_RETREQ 0x9003           //请求重传
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_RETREP 0x9004           //重传错误
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_NOTIFYWINDOW 0x9101     //滑动窗口大小通知
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_NOTIFYCLOSE 0x9102      //通道关闭通知
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_NOTIFYACK 0x9103        //序列确认通知
//心跳协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_HB_SYN 0xA001               //客户端同步请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_HB_ACK 0xA002               //服务器心跳回复请求
//CHUNK包模式
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_CHUNKED_START 0xB001        //开始传输CHUNK包
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_CHUNKED_PROCESS 0xB002      //进行中的CHUNK包
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_CHUNKED_END 0xB003          //结束CHUNK包
///////////////////////////////////////////////////////////////////////////
//                          导出的数据结构
///////////////////////////////////////////////////////////////////////////
#pragma pack(push)
#pragma pack(1)
//////////////////////////////////////////////////////////////////////////协议头
typedef struct tag_XEngine_ProtocolHdr
{
	XSHOT wHeader;                                                        //协议头头部 固定的赋值
	XNETHANDLE xhToken;                                                   //唯一标识符
	XUINT unOperatorType;                                                 //操作类型
	XUINT unOperatorCode;                                                 //操作码
	XUINT unPacketSize;                                                   //数据包大小，后续包的大小，不是长度，而是内存大小
	XBYTE byVersion;                                                      //协议版本
	XBYTE byIsReply;                                                      //是否需要回复包 0 否，1是
	XSHOT wReserve : 12;                                                  //自定义数据位或者保留
	XSHOT wCrypto : 4;                                                    //加解密标志位
	XSHOT wPacketSerial;                                                  //包序列号
	XSHOT wTail;                                                          //协议头尾部 固定的赋值
}XENGINE_PROTOCOLHDR, * LPXENGINE_PROTOCOLHDR;
//扩展协议
typedef struct tag_XEngine_ProtocolHdrEx
{
	XBYTE byHeader;                                                       //协议头头部 固定的赋值
	XBYTE byVersion : 4;                                                  //协议头版本号标志
	XBYTE byPayload : 4;                                                  //后续数据包负载类型
	XNETHANDLE xhToken;                                                   //唯一标识符
	XNETHANDLE xhXTPTime;                                                 //时间戳
	XSHOT unOperatorType;                                                 //操作类型
	XSHOT unOperatorCode;                                                 //操作码
	XUINT unPacketCrypt : 4;                                              //加密标志,0没有加密,其他值表示加密，加密类型自定义
	XUINT unPacketCount : 10;                                             //0不分包,> 0 分包个数
	XUINT unPacketSerial : 8;                                             //包序列号,只有分包的时候这个值才有效，其他时候请填充0
	XUINT unPacketSize : 10;                                              //数据包大小，后续包的大小，不包括协议头和协议尾
	XBYTE byReserve;                                                      //自定义数据位或者保留
	XBYTE byIsReply;                                                      //是否需要回复包 0 否，1是
}XENGINE_PROTOCOLHDREX, * LPXENGINE_PROTOCOLHDREX;
typedef struct tag_XEngine_ProtocolTailEx
{
	XBYTE byCheckSum;                                                     //数据校验码,数据区校验
	XBYTE byTail;                                                         //协议头尾部 固定的赋值
}XENGINE_PROTOCOLTAILEX, * LPXENGINE_PROTOCOLTAILEX;
//////////////////////////////////////////////////////////////////////////心跳包
typedef struct tag_XNegine_Protocol_HeartBeat
{
	XCHAR tszMachineAddr[128];                                            //机器IP地址
	__int64x nMachineCode;                                                //机器编号
	__int64x nTimer;                                                      //心跳时间 time(NULL)
	struct
	{
		XSHOT nCpuUsage;                                                  //CPU占用率
		XSHOT nMemoryUsage;                                               //内存占用率
		XSHOT nNetUsage;                                                  //网络占用率
		XSHOT nDiskUsage;                                                 //硬盘占用率
		XSHOT nGraphUsage;                                                //显卡占用率
	}st_HBComputerInfo;
}XENGINE_PROTOCOL_HEARTBEAT, * LPXENGINE_PROTOCOL_HEARTBEAT;
//////////////////////////////////////////////////////////////////////////
//网络注册协议
typedef struct tag_XEngine_Protocol_UserInfo
{
	XCHAR tszUserName[64];                                                 //用户名
	XCHAR tszUserPass[64];                                                 //密码
	XCHAR tszEMailAddr[64];                                                //电子邮件地址
	XCHAR tszLoginTime[64];                                                //登录时间
	XCHAR tszCreateTime[64];                                               //注册时间
	__int64x nPhoneNumber;                                                //电话号码
	__int64x nIDNumber;                                                   //身份证号
	int nUserLevel;                                                       //用户等级
	int nUserState;                                                       //是否在线
}XENGINE_PROTOCOL_USERINFO, * LPXENGINE_PROTOCOL_USERINFO;
//网络验证协议
typedef struct tag_XEngine_Protocol_Auth
{
	XCHAR tszUserName[64];                                             //用户名
	XCHAR tszUserPass[64];                                             //密码
	XCHAR tszDCode[8];                                                 //动态码,最大8位
	ENUM_PROTOCOLCLIENT_TYPE enClientType;                             //用户类型
	ENUM_PROTOCOLDEVICE_TYPE enDeviceType;                             //设备类型
}XENGINE_PROTOCOL_USERAUTH, * LPXENGINE_PROTOCOL_USERAUTH;
//网络日志协议
typedef struct tag_XEngine_Protocol_XLog
{
	XCHAR tszFileName[MAX_PATH];                                       //文件名
	XCHAR tszFuncName[64];                                             //函数名称
	XCHAR tszLogTimer[64];                                             //日志时间
	int nLogLine;                                                      //代码行数
	int nLogLevel;                                                     //日志级别
}XENGINE_PROTOCOL_XLOG, * LPXENGINE_PROTOCOL_XLOG;
//音视频参数协议
typedef struct
{
	bool bEnable;                                                 //是否启用
	__int64x nBitRate;                                            //码率
	__int64u nFrameNumber;                                        //第几帧
	int nFrameType;                                               //帧类型
	int enAVCodec;                                                //编码器
	int nChannel;                                                 //通道个数
	int nSampleRate;                                              //采样率.44100 ...
	int nSampleFmt;                                               //采样格式,S16 S32...
	int nFrameSize;                                               //采样大小
	int nALen;                                                    //大小
	XCHAR tszAInfo[256];                                          //推流扩展编码信息
}AVCODEC_AUDIO_INFO, * LPAVCODEC_AUDIO_INFO;
typedef struct
{
	bool bEnable;                                                 //是否启用
	__int64u nBitRate;                                            //码率
	__int64u nFrameNumber;                                        //第几帧
	int nFrameType;                                               //帧类型
	int enAVCodec;                                                //使用的编码器
	int nBFrame;                                                  //B帧间隔,0不启用
	int nWidth;                                                   //视频宽
	int nHeight;                                                  //视频高
	int nFormat;                                                  //视频格式
	int nFrameRate;                                               //帧率
	int nVLen;                                                    //SPSPPS大小,为0将交由模块处理
	XCHAR tszVInfo[1024];                                         //SPS与PPS,你可以通过AVHelp_MetaInfo_Get264Hdr来处理,在SPS和PPS前面添加起始字节后一起拷贝到这里面
}AVCODEC_VIDEO_INFO, * LPAVCODEC_VIDEO_INFO;
typedef struct tag_XEngine_AVProtocol
{
	AVCODEC_VIDEO_INFO st_VideoInfo;                              //视频信息
	AVCODEC_AUDIO_INFO st_AudioInfo;                              //音频信息
	XCHAR tszPktName[32];                                         //封装格式,如果没有,可以为NULL,封装格式为后缀.比如:mkv flv mp4
	XBYTE byPktFlag;                                              //数据包封装格式,发送的音视频流后续格式,0:无协议裸流数据,1:标准协议头,2:扩展协议头
	double dlTime;                                                //视频时长,当是文件才有效
	__int64x nSize;                                               //文件大小,当是文件才有效
}XENGINE_PROTOCOL_AVINFO, * LPXENGINE_PROTOCOL_AVINFO;
#pragma pack(pop)