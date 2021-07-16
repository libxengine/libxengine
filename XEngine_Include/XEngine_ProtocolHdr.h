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
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XRPC = 10,                    //XRPC协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_HEARTBEAT = 0x1A,             //心跳协议
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_CHUNKED = 0x1B,               //CHUNKED包模式，使用此模式协议头的unPacketSize字段Post将无效
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_LEAVE = 0x1C,                 //离开包，投递了这个包后后续包都将被抛弃
	ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_USER = 100                    //用户包,用户自定义包开始为101开始100以内为协议内部保留
}ENUM_XNETENGINE_XCOMM_PROTOCOL;
/**************************************************************************
						  操作码定义,不能超过0xFFFF大小
**************************************************************************/
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_ISOK 0x0001                 //通用成功
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_ISFAILED 0x0002             //通用失败
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_LEAVE 0x000A                //离开包
//日志协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_XLOG_PUSH 0x1001            //日志推送的消息
//网络验证服务子协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQDEL 0x2001          //删除用户
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPDEL 0x2002
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQREGISTER 0x2003     //注册
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPREGISTER 0x2004
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQLOGIN 0x2005        //登陆
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPLOGIN 0x2006
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQPAY 0x2007          //充值
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPPAY 0x2008
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQGETPASS 0x2009      //找回密码
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPGETPASS 0x200A
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQGETTIME 0x200B      //获取剩余时间
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPGETTIME 0x200C
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQTRYVER 0x200D       //临时验证协议请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPTRYVER 0x200E
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQGETUSER 0x2010      //获取用户信息请求协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPGETUSER 0x2011
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQSETUSER 0x2012      //设置用户信息请求协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REPSETUSER 0x2013
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_NOTIFYMSG 0x2FF0       //数据
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_TIMEDOUT 0x2FFF        //通知客户端时间到期
//流媒体协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_REQXPUSH 0x3001         //请求推送
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_REPXPUSH 0x3002         //回复请求,如果TOKEN值存在,回复会改变协议头的TOKEN字段,你需要自己判断
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_REQXPULL 0x3003         //请求拉流
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_REPXPULL 0x3004         //拉流回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_CTRLPLAY 0x3010         //开始播放
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_CTRLPAUSE 0x3011        //暂停播放
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_STATPUSH 0x3101         //推流端状态推送协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_SMS_STATPULL 0x3101         //拉流端状态推送协议
//存储服务协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_STORAGE_TRANSMISSION 0x4000 //文件传输
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_STORAGE_REQUPDATE 0x4001    //上传文件请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_STORAGE_REPUPDATE 0x4002    //上传文件请求确认
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_STORAGE_REQDOWN 0x4003      //下载文件请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_STORAGE_REPDOWN 0x4004      //下载文件确认
//后台服务协议
//---使用0x5xxx..参考后台控制服务
//P2XP协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_P2XP_REQLANLIST 0x6001      //同步列表协议,同步本地局域网IP中的客户端
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_P2XP_REPLANLIST 0x6002      //同步列表回复确认协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_P2XP_REQWLANLIST 0x6003     //同步列表协议,同步同一外网IP中局域网
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_P2XP_REPWLANLIST 0x6004     //同步万维网IP确认协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_P2XP_REQCONNECT 0x6005      //请求用户连接到网络服务
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_P2XP_REPCONNECT 0x6006      //确认连接协议
//消息队列协议
//---使用0x7xxx..参考消息队列服务
//消息分发服务
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_REQDOMAINQUERY 0x8001   //查询当前网络中的域
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_REPDOMAINQUERY 0x8002   //回复查询域信息
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_REQTOPICQUERY 0x8003    //主题请求是否存在
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_REPTOPICQUERY 0x8004    //回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_DELETEDOMAIN 0x8005     //域ID被删除
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_DELETETOPIC 0x8006      //主题被删除
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_DDS_PUBLISHCREATE 0x8007    //一个发布者被创建
//UDX通信协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_TRANSMISSION 0x9000     //数据通信协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_RETREQ 0x9001           //请求重传
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_RETREP 0x9002           //重传错误
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_NOTIFYWINDOW 0x9101     //滑动窗口大小通知
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_NOTIFYCLOSE 0x9102      //通道关闭通知
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_UDX_NOTIFYACK 0x9103        //序列确认通知
//XRPC协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_XRPC_REQFUNCALL 0xA001      //函数调用请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_XRPC_REPFUNCALL 0xA002      //函数调用回复
//心跳协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_HB_SYN 0xA001               //客户端同步请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_HB_ACK 0xA002               //服务器心跳回复请求
//CHUNK包模式
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_CHUNKED_START 0xB001        //开始传输CHUNK包
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_CHUNKED_PROCESS 0xB002      //进行中的CHUNK包
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_CHUNKED_END 0xB003          //结束CHUNK包
///////////////////////////////////////////////////////////////////////////
//                          导出的枚举
///////////////////////////////////////////////////////////////////////////
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
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_STRING = 1,                   //文本或者字符串
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_BIN = 2,                      //二进制
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_JSON = 3,                     //JSON
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_BSON = 4,                     //BSON
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_XML = 5,                      //XML
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_SYSTEM = 6,                   //系统保留
	ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE_USER = 10                     //用户使用
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
}XENGINE_PROTOCOLHEARTBEAT, * LPXENGINE_PROTOCOLHEARTBEAT;
//////////////////////////////////////////////////////////////////////////文件传输头文件,可用于P2XP文件传输和组包管理模块文件传输
typedef struct tag_XEngine_ProtocolFile
{
	CHAR tszFilePath[MAX_PATH];                                           //文件路径
	CHAR tszFileName[MAX_PATH];                                           //文件名称,文件传输的时候才需要,其他时候不需要
	CHAR tszFileHash[MAX_PATH];                                           //文件HASH值,MD5或者HASH1 256等...不能超过260字节大小
	CHAR tszFileUser[128];                                                //文件所属用户
	CHAR tszFileTime[64];                                                 //文件创建时间，如果这个参数不填,那么服务器将会设置为接受到的文件时间
	__int64x nFileSize;                                                   //文件大小
}XENGINE_PROTOCOLFILE, * LPXENGINE_PROTOCOLFILE;
//////////////////////////////////////////////////////////////////////////P2XP扩展协议
//连接信息
typedef struct tag_XEngine_P2XPPeer_Protocol
{
	CHAR tszUserName[64];                                                 //用户信息
	CHAR tszPrivateAddr[32];                                              //私有本地地址，内网地址
	CHAR tszPublicAddr[32];                                               //外网地址
	CHAR tszConnectAddr[32];                                              //链接地址
	CHAR tszUserLocation[32];                                             //位置信息
	CHAR tszUserArea[20];                                                 //用户ISP
	WORD dwConnectType;                                                   //连接类型
	WORD dwPeerType;                                                      //节点类型
}XENGINE_P2XPPEER_PROTOCOL, * LPXENGINE_P2XPPEER_PROTOCOL;
//P2XP通道连接命令
typedef struct tag_XEngine_P2XPIO_Protocol
{
	CHAR tszSourceUser[32];                                               //请求连接的用户
	CHAR tszDestUser[32];                                                 //要连接的用户
	CHAR tszConnectAddr[32];                                              //连接的IP地址
	int nDestPort;                                                        //要连接的端口
	BOOL bIsTcp;                                                          //连接类型TCP,否则为UDP
}XENGINE_P2XPIO_PROTOCOL, * LPXENGINE_P2XPIO_PROTOCOL;
//////////////////////////////////////////////////////////////////////////
//消息队列服务协议
typedef struct tag_XEngine_ProtocolXmq
{
	CHAR tszMQKey[256];                                                   //此消息的KEY，不能为空
	__int64x nSerial;                                                     //包序列号
	int nKeepTime;                                                        //保存时间，单位秒，如果为0，获取一次后被抛弃。-1 永久存在，如果有多个永久存在的包nSerial必须有值
	int nGetTimer;                                                        //可以获取的次数
}XENGINE_PROTOCOL_XMQ, * LPXENGINE_PROTOCOL_XMQ;
//数据分发服务子协议
typedef struct tag_XEngine_ProtocolXdds
{
	CHAR tszTopic[MAX_PATH];                                              //主题
	CHAR tszDDSAddr[64];                                                  //分发地址
	BOOL bCreater;                                                        //是否是创建者
	BOOL bTcp;                                                            //是否启用TCP，默认UDP
	int nPort;                                                            //端口
}XENGINE_PROTOCOL_XDDS, * LPXENGINE_PROTOCOL_XDDS;
//////////////////////////////////////////////////////////////////////////
//网络注册协议
typedef struct tag_XEngine_Protocol_UserReg
{
	CHAR tszUserName[64];                                                 //用户名
	CHAR tszUserPass[64];                                                 //密码
	CHAR tszEMailAddr[64];                                                //电子邮件地址
	CHAR tszLoginTime[64];                                                //登录时间
	CHAR tszCreateTime[64];                                               //注册时间
	__int64x nQQNumber;                                                   //QQ号
	__int64x nPhoneNumber;                                                //电话号码
	__int64x nIDNumber;                                                   //身份证号
	int nUserLevel;                                                       //用户等级
	int nUserState;                                                       //是否在线
}XENGINE_PROTOCOL_USERREG, * LPXENGINE_PROTOCOL_USERREG;
//网络验证协议
typedef struct tag_XEngine_Protocol_Auth
{
	CHAR tszUserName[64];                                             //用户名
	CHAR tszUserPass[64];                                             //密码
	ENUM_PROTOCOLCLIENT_TYPE enClientType;                            //用户类型
	ENUM_PROTOCOLDEVICE_TYPE enDeviceType;                            //设备类型
}XENGINE_PROTOCOL_USERAUTH, * LPXENGINE_PROTOCOL_USERAUTH;
//网络日志协议
typedef struct tag_XEngine_XLog_Protocol
{
	CHAR tszFuncName[64];                                             //函数名称
	CHAR tszLogTimer[64];                                             //日志时间
	int nLogLine;                                                     //代码行数
	int nLogLeave;                                                    //日志级别
	int nLogLen;                                                      //打印的日志长度
}XENGINE_XLOG_PROTOCOL, * LPXENGINE_XLOG_PROTOCOL;
//流媒体控制
typedef struct tag_XEngine_SMSProtocol
{
	XNETHANDLE xhXTPTime;                                             //同步时间戳
	ULONGLONG nPacketCount;                                           //当前推送(接受)数据大小
	ULONGLONG nPacketHandle;                                          //已处理(已发送)数据大小
	ULONGLONG nPacketLeft;                                            //剩余数据大小
}XENGINE_SMSPROTOCOL, * LPXENGINE_SMSPROTOCOL;
//音视频参数协议
typedef struct tag_XEngine_AVProtocol
{
	CHAR tszPktName[4];                                              //封装格式,如果没有,可以为NULL,封装格式为后缀.比如:mkv flv mp4
	BYTE byPktFlag;                                                   //数据包封装格式,发送的音视频流后续格式,0:无协议裸流数据,1:标准协议头,2:扩展协议头
	//视频信息
	struct
	{
		BOOL bEnable;                                                 //是否启用
		int nWidth;                                                   //视频宽
		int nHeight;                                                  //视频高
		int enAvCodec;                                                //使用的编码器
		int nBitRate;                                                 //码率
		int nFrameRate;                                               //帧率
		int nVLen;                                                    //SPSPPS大小,为0将交由模块处理
		CHAR tszVInfo[256];                                          //SPS与PPS,你可以通过AVHelp_MetaInfo_Get264Hdr来处理,在SPS和PPS前面添加起始字节后一起拷贝到这里面
	}st_PushVideo;
	//音频信息
	struct
	{
		BOOL bEnable;                                                 //是否启用
		int nChannel;                                                 //通道个数
		int nBitRate;                                                 //码率
		int nSampleRate;                                              //采样率.44100 ...
		int nSampleFmt;                                               //采样格式,S16 S32...
		int enAvCodec;                                                //编码器
	}st_PushAudio;
}XENGINE_AVPROTOCOL, * LPXENGINE_AVPROTOCOL;
#pragma pack(pop)
