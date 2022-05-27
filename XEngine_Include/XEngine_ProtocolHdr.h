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
//P2XP节点类型
#define XENGINE_P2XP_PEER_TYPE_NORMAL 0xA1 << 0x01                      //普通节点
#define XENGINE_P2XP_PEER_TYPE_SUPER 0xA1 << 0x02                       //超级节点
#define XENGINE_P2XP_PEER_TYPE_ROUTING 0xA1 << 0x03                     //路由节点
#define XENGINE_P2XP_PEER_TYPE_SERVERS 0xA1 << 0x04                     //服务器节点，可以有多个。用于服务器无法使用的时候
#define XENGINE_P2XP_PEER_TYPE_ENGINE 0xA1 << 0x05                      //引擎节点，仅此一个
#define XENGINE_P2XP_PEER_TYPE_DATATRAN 0xA1 << 0x06                    //数据传输节点
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
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_BACKSERVICE = 5,              //后台服务协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_P2XP = 6,                     //P2XP协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XMQ = 7,                      //消息队列服务
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XDDS = 8,                     //消息分发服务
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_UDX = 9,                      //UDX协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_HEARTBEAT = 0x1A,             //心跳协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_CHUNKED = 0x1B,               //CHUNKED包模式，使用此模式协议头的unPacketSize字段Post将无效
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_LEAVE = 0x1C,                 //离开包，投递了这个包后后续包都将被抛弃
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_USER = 100                    //用户包,用户自定义包开始为101开始100以内为协议内部保留
}ENUM_XNETENGINE_XCOMM_PROTOCOL;
//客户端类型
typedef enum en_ProtocolClient_Type
{
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_USER = 10,
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_SERVICE,
	ENUM_PROTOCOL_FOR_SERVICE_TYPE_PROXY
}ENUM_PROTOCOLCLIENT_TYPE, * LPENUM_PROTOCOLCLIENT_TYPE;
//客户端设备类型
typedef enum en_ProtocolDevice_Type
{
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_PC = 20,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_SURFACE = 21,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_ANDROID = 22,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_IPAD = 23,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_IOS = 24,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_WEB = 25,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_EMBEDDED = 26,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_OTHER = 99,
	ENUM_PROTOCOL_FOR_DEVICE_TYPE_ALL = 100
}ENUM_PROTOCOLDEVICE_TYPE, * LPENUM_PROTOCOLDEVICE_TYPE;
//节点传输类型
typedef enum en_P2XPPeer_TransmissionType
{
	ENUM_NETENGINE_P2XPPEER_TRANSMISSIONTYPE_STRAIGHT = 0,                //直链
	ENUM_NETENGINE_P2XPPEER_TRANSMISSIONTYPE_PROXY = 1,                   //服务代理
	ENUM_NETENGINE_P2XPPEER_TRANSMISSIONTYPE_HOLES = 2                    //打洞
}ENUM_P2XPPEER_TRANSMISSIONTYPE;
//负载类型
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
typedef enum en_XEngine_ProtocolHdr_Crypto_Type
{
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_UNKNOW = 0,                    //没有加密
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_AES = 1,                       //AES
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_DES = 2,                       //DES
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_RSA = 3,                       //RSA
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_XCRYPT = 4,                    //X加解密
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_SYSTEM = 5,                    //系统保留
	ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE_USER = 6                       //用户使用
}ENUM_XENGINE_PROTOCOLHDR_CRYPTO_TYPE;
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
	WORD wHeader;                                                         //协议头头部 固定的赋值
	XNETHANDLE xhToken;                                                   //唯一标识符
	UINT unOperatorType;                                                  //操作类型
	UINT unOperatorCode;                                                  //操作码
	UINT unPacketSize;                                                    //数据包大小，后续包的大小，不是长度，而是内存大小
	BYTE byVersion;                                                       //协议版本
	BYTE byIsReply;                                                       //是否需要回复包 0 否，1是
	SHOT wReserve : 12;                                                   //自定义数据位或者保留
	SHOT wCrypto : 4;                                                     //加解密标志位
	WORD wPacketSerial;                                                   //包序列号
	WORD wTail;                                                           //协议头尾部 固定的赋值
}XENGINE_PROTOCOLHDR, * LPXENGINE_PROTOCOLHDR;
//扩展协议
typedef struct tag_XEngine_ProtocolHdrEx
{
	WORD wHeader : 8;                                                     //协议头头部 固定的赋值
	WORD wVersion : 4;                                                    //协议头版本号标志
	WORD wPayload : 4;                                                    //后续数据包负载类型
	XNETHANDLE xhToken;                                                   //唯一标识符
	XNETHANDLE xhXTPTime;                                                 //时间戳
	UINT unOperatorType : 16;                                             //操作类型
	UINT unOperatorCode : 16;                                             //操作码
	UINT unPacketCrypt : 4;                                               //加密标志,0没有加密,其他值表示加密，加密类型自定义
	UINT unPacketCount : 10;                                              //0不分包,> 0 分包个数
	UINT unPacketSerial : 8;                                              //包序列号,只有分包的时候这个值才有效，其他时候请填充0
	UINT unPacketSize : 10;                                               //数据包大小，后续包的大小，不包括协议头和协议尾
	WORD wReserve : 8;                                                    //自定义数据位或者保留
	WORD wIsReply : 8;                                                    //是否需要回复包 0 否，1是
}XENGINE_PROTOCOLHDREX, * LPXENGINE_PROTOCOLHDREX;
typedef struct tag_XEngine_ProtocolTailEx
{
	WORD wCheckSum : 8;                                                   //数据校验码,数据区校验
	WORD wTail : 8;                                                       //协议头尾部 固定的赋值
}XENGINE_PROTOCOLTAILEX, * LPXENGINE_PROTOCOLTAILEX;
//////////////////////////////////////////////////////////////////////////心跳包
typedef struct tag_XNegine_Protocol_HeartBeat
{
	CHAR tszMachineAddr[32];                                             //机器IP地址
	int nMachineCode;                                                     //服务编号
	__int64x nTimer;                                                       //心跳时间 time(NULL)
	struct
	{
		int nCpuUsage;                                                    //CPU占用率
		int nMemoryUsage;                                                 //内存占用率
		int nNetUsage;                                                    //网络占用率
		int nDiskUsage;                                                   //硬盘占用率
		int nGraphUsage;                                                  //显卡占用率
	}st_HBComputerInfo;
}XENGINE_PROTOCOL_HEARTBEAT, * LPXENGINE_PROTOCOL_HEARTBEAT;
//////////////////////////////////////////////////////////////////////////
//网络注册协议
typedef struct tag_XEngine_Protocol_UserInfo
{
	CHAR tszUserName[64];                                                 //用户名
	CHAR tszUserPass[64];                                                 //密码
	CHAR tszEMailAddr[64];                                                //电子邮件地址
	CHAR tszLoginTime[64];                                                //登录时间
	CHAR tszCreateTime[64];                                               //注册时间
	__int64x nPhoneNumber;                                                //电话号码
	__int64x nIDNumber;                                                   //身份证号
	int nUserLevel;                                                       //用户等级
	int nUserState;                                                       //是否在线
}XENGINE_PROTOCOL_USERINFO, * LPXENGINE_PROTOCOL_USERINFO;
//网络验证协议
typedef struct tag_XEngine_Protocol_Auth
{
	CHAR tszUserName[64];                                             //用户名
	CHAR tszUserPass[64];                                             //密码
	ENUM_PROTOCOLCLIENT_TYPE enClientType;                            //用户类型
	ENUM_PROTOCOLDEVICE_TYPE enDeviceType;                            //设备类型
}XENGINE_PROTOCOL_USERAUTH, * LPXENGINE_PROTOCOL_USERAUTH;
//网络日志协议
typedef struct tag_XEngine_Protocol_XLog
{
	CHAR tszFuncName[64];                                             //函数名称
	CHAR tszLogTimer[64];                                             //日志时间
	int nLogLine;                                                     //代码行数
	int nLogLeave;                                                    //日志级别
	int nLogLen;                                                      //打印的日志长度
}XENGINE_PROTOCOL_XLOG, * LPXENGINE_PROTOCOL_XLOG;
//音视频参数协议
typedef struct tag_XEngine_AVProtocol
{
	CHAR tszPktName[4];                                               //封装格式,如果没有,可以为NULL,封装格式为后缀.比如:mkv flv mp4
	BYTE byPktFlag;                                                   //数据包封装格式,发送的音视频流后续格式,0:无协议裸流数据,1:标准协议头,2:扩展协议头
	//视频信息
	struct
	{
		BOOL bEnable;                                                 //是否启用
		__int64x nBitRate;                                            //码率
		int enAVCodec;                                                //使用的编码器
		int nWidth;                                                   //视频宽
		int nHeight;                                                  //视频高
		int nFrameRate;                                               //帧率
		int nVLen;                                                    //SPSPPS大小,为0将交由模块处理
		CHAR tszVInfo[256];                                           //SPS与PPS,你可以通过AVHelp_MetaInfo_Get264Hdr来处理,在SPS和PPS前面添加起始字节后一起拷贝到这里面
	}st_VideoInfo;
	//音频信息
	struct
	{
		BOOL bEnable;                                                 //是否启用
		__int64x nBitRate;                                            //码率
		int enAVCodec;                                                //编码器
		int nChannel;                                                 //通道个数
		int nSampleRate;                                              //采样率.44100 ...
		int nSampleFmt;                                               //采样格式,S16 S32...
		int nFrameSize;                                               //采样大小
		int nALen;                                                    //大小
		CHAR tszAInfo[256];                                           //推流扩展编码信息
	}st_AudioInfo;
}XENGINE_PROTOCOL_AVINFO, * LPXENGINE_PROTOCOL_AVINFO;
#pragma pack(pop)
