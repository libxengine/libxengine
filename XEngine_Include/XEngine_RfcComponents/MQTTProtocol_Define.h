#pragma once
/********************************************************************
//    Created:     2022/11/02  10:19:11
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_MQTTProtocol\MQTTProtocol_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_MQTTProtocol
//    File Base:   MQTTProtocol_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     MQTT导出协议
//    History:
*********************************************************************/
//协议类型
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_RESERV 0             //保留
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_CONNECT 1            //客户端连接到服务器,payload需要
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_CONNACK 2            //服务器连接确认
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PUBLISH 3            //发布消息,payload需要
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PUBACK 4             //发布确认(QOS1)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PUBREC 5             //消息接受(QOS2 第一阶段)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PUBREL 6             //消息释放(QOS2 第二阶段)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PUBCOMP 7            //发布结束(QOS2 第三阶段)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_SUBSCRIBE 8          //客户端订阅请求,payload需要
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_SUBACK 9             //服务端确认订阅,payload需要
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_UNSUBSCRIBE 10       //客户端取消订阅,payload需要
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_UNSUBACK 11          //服务端确认取消,payload需要
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PINGREQ 12           //客户端发送心跳
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_PINGREP 13           //服务器回复心跳
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_DISCONN 14           //客户端断开连接
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_TYPE_AUTH 15              //客户端验证请求(V5.0)
//控制标识符,没有匹配的就填0
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_CONNECT 0            //保留
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_CONNACK 0            //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBLISH_DUP 8        //DUP,如果该值为1,表示重复的消息；否则该数据包就是第一次发布的消息
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBLISH_QOS2 4       //QOS,都为0表示QOS0,至多一次,如果此值为1,表示QoS2,只有一次
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBLISH_QOS1 2       //QOS,此值为真表示QOS1,至少一次,如果QOS2和QOS1都为真,那么表示非法
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBACK 0             //保留
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBREC 0             //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBREL 2             //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PUBEND 0             //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_SUBSCRIBE 2          //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_SUBACK 0             //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_UNSUBSCRIBE 2        //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_UNSUBACK 0           //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PINGREQ 0            //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_PINGREP 0            //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_DISCONN 0            //
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_FLAG_AUTH 0               //
//属性字段
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_PAYLOAD 0x01     //负载格式定义(BTYE)(PUBLISH,WILL PROPERTY)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_MSGEXPIRY 0x02   //消息过期时间(int)(PUBLISH,WILL PROPERTY)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_CONTENTTYPE 0x03 //UTF8编码字符串(PUBLISH,WILL PROPERTY)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REPTOPIC 0x08    //UTF8编码字符串(PUBLISH,WILL PROPERTY)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_BDATA 0x09       //二进制数据(PUBLISH,WILL PROPERTY)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_SUBID 0x0B       //订阅ID(变长整数)(PUBLISH,SUBCRIBE)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_SESEXPIRY 0x11   //会话过期时间(int)(CONNECT,CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_CLIENTID 0x12    //客户端标识符(UTF8编码字符串)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_KEEPALIVE 0x13   //服务器保活计时器(XSHOT)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_AUTHMETHOD 0x15  //验证方法(UTF8)(CONNECT,CONNACK,AUTH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_AUTHDATA 0x16    //验证数据(二进制)(CONNECT,CONNACK,AUTH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REQPROBLEM 0X17  //请求问题信息(XBYTE)(CONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_DELAY 0x18       //将要延迟的时间(int)(WILL PROPERTY)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REPPROBLEM 0x19  //请求回复的问题(XBYTE)(CONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REPINFO 0x1A     //响应信息(UTF8)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REFER 0x1C       //服务参考(UTF8)(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REASON 0x1F      //响应字符串(UTF8)(CONNACK,PUBACK,PUBREC,PUBREL,PUBCOMP,SUBACK,UNSUBACK,DISCONNECT,AUTH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_RECVMAX 0x21     //接受最大值(XSHOT)(CONNECT,CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_ALIASMAX 0x22    //主题最大值(XSHOT)(CONNECT,CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_TOPICALIAS 0x23  //主题名(XSHOT)(PUBLISH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_MAXQOS 0x24      //最大QOS(XBYTE)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_REVERAVAI 0x25   //保留可用(XBYTE)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_USER 0x26        //用户属性(UTF8)(CONNECT,CONNACK,PUBLISH,WILL PROPERTY,PUBACK,PUBREC,PUBREL,PUBCOMP,SUBCRIBE,SUBACK,UNSCRIBE,UNSUBACK,DISCONNECT,AUTH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_PACKMAX 0x27     //最大报文大小(int)(CONNECT,CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_WILDCARDSUBAVAI 0x28 //通配符可用(XBYTE)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_SUBIDAVAI 0X29   //订阅ID可用(XBYTE)(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_PROPERTY_SHAREDSUBAVAI 0x2A //共享订阅可用(XBYTE)(CONNACK)
//原因字,REASON值(大于0x80表示失败)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SUCCESS 0x00           //成功(CONNACK,PUBACK,PUBREL,PUBREC,PUBCOMP,SUBACK,UNSUBACK,AUTH,DISCONNECT,QOS0)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_QOS1 0x01              //SUBACK
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_QOS2 0x02              //SUBACK
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_DISCONNECT 0x04        //遗留消息断开(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_NOMATCHSUB 0x10        //没有匹配到订阅者(PUBACK,PUBREC)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_NOSUBEXIST 0x11        //没有订阅存在(UNSUBACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_CONTINUEAUTH 0x18      //继续验证(AUTH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_REAUTH 0x19            //重新验证(AUTH)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_UNSPECIFIED 0x80       //未指定错误(CONNACK,PUBACK,PUBREC,SUBACK,UNSUBACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_MALFORMEDPKT 0x81      //异常包(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_PROTOCOLERR 0x82       //协议错误(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_IMPERROR 0x83          //指定协议错误(CONNACK,PUBACK,PUBREC,SUBACK,UNSUBACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_UNSUPPORTVER 0x84      //不支持的协议版本(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_MSGIDVALID 0x85        //客户端ID不可用(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_USERPASS 0x86          //用户名密码错误(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_NOTAUTH 0x87           //没有经过验证(CONNACK,PUBACK,PUBREC,SUBACK,UNSUBACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SRVUNAVAIL 0x88        //服务不可用(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SRVBUSY 0x89           //服务器忙碌(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_BANNED 0x8A            //被禁用(CONNACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SRVSHUTDOWN 0x8B       //服务器没有开启(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_AUTHMETHOD 0x8C        //错误的验证方法(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_TIMEOUT 0x8D           //心跳超时(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_TOKEN 0x8E             //会话TOKEN错误(DISCONNNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_TOPICFILTER 0x8F       //主题过滤器错误(SUBACK,UNSUBACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_TOPICNAME 0x90         //主题名称错误(SUBACK,PUBACK,PUBREC,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_PKTIDUSED 0x91         //包ID使用中(PUBACK,PUBREC,SUBACK,UNSUBACK)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_PKTIDNOTFOUND 0x92     //包ID没有找到(PUBREL,PUBCOMP)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_MAXRECV 0x93           //数据大小超出逾期(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_TOPICALIAS 0x94        //主题别名错误(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_PKTLARGE 0x95          //包太大(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_MSGRATE 0x96           //发送频率过高(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_QUOTA 0x97             //超出配额(CONNACK,PUBACK,PUBREC,SUBACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_ADMIN 0x98             //管理模式已启用(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_PAYLOAD 0x99           //负载内容格式错误(CONNACK,PUBACK,PUBREC,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_RETAINNOTSUPPORT 0x9A  //预置保留位不支持(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_QOSNOTSUPPORT 0x9B     //QOS不支持(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_ANOTHERSRV 0x9C        //需要其他服务(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SRVMOVE 0x9D           //服务已被移动(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SHARESUBNOTSUPPORT 0x9E//共享订阅不支持(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_CONNECTRATE 0x9F       //连接频率过快(CONNACK,DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_MACCONNECT 0xA0        //最大连接次数(DISCONNECT)
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_SUBIDNOTSUPPORT 0xA1   //订阅ID不支持
#define XENGINE_RFCCOMPONENTS_MQTT_PROTOCOL_REASON_WILDCARDSUBNOTSUPPORT 0xA2 //通配符订阅不支持
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    XBYTE byMsgFlag : 4;                                                   //报头头标示
    XBYTE byMsgType : 4;                                                   //协议头类型
}MQTTPROTOCOL_FIXEDHEADER;
//可变头:will message 遗愿消息,表示非正常断开的离线消息
typedef struct
{
    XBYTE byProtoNameRes;                                               //协议名保留
    XBYTE byProtoNameLen;                                               //协议名长度
    XBYTE byProtoName[4];                                               //协议名(MQTT)
    XBYTE byProtoVer;                                                   //协议版本,3.1.1是4,5是0x05
    //是否存在用户标记,8个标志位
    XBYTE byFlagsReser : 1;                                             //保留
    XBYTE byFlagsClean : 1;                                             //为0，表示创建一个持久会话，在客户端断开连接时，会话仍然保持并保存离线消息，直到会话超时注销
                                                                       //为1，表示创建一个新的临时会话，在客户端断开时，会话自动销毁
    XBYTE byFlagsWill : 1;                                              //被设置为1，这意味着，如果连接请求被接受，服务端必须存储一个Will Message，并和网络连接关联起来。
                                                                       //之后在网络连接断开的时候必须发布Will Message，除非服务端收到DISCONNECT包删掉了Will Message
    XBYTE byFlagsQos : 2;                                               //QOS
    XBYTE byFlagsRetain : 1;                                            //表示Will Message在发布之后是否需要保留
    /*  如果Will Flag设置为0，那么Will Retain必须是0
        如果Will Flag设置为1：
        如果Will Retain设置为0，那么服务端必须发布Will Message，不必保存
        如果Will Retain设置为1，那么服务端必须发布Will Message，并保存*/
    XBYTE byFlagsPass : 1;                                              //用户密码,同上,User Name Flag设置为0，那么Password Flag必须设置为0
    XBYTE byFlagsUser : 1;                                              //用户名,设置为0，那么用户名不必出现在载荷中,设置为1，那么用户名必须出现在载荷中
    XSHOT wHBTime;                                                      //心跳时长,以秒为单位的时间间隔,0表示不启用
}MQTTPROTOCOL_HDRCONNNECT;
//订阅选项
typedef struct
{
    XBYTE byFlagsReser : 2;                                             //保留
    XBYTE byFlagsRetain1 : 2;                                           //在指定时间内发送消息
    XBYTE byFlagsRetain2 : 1;                                           //
    XBYTE byFlagsLocal : 1;                                             //非本地
    XBYTE byFlagsQos : 2;                                               //QOS
}MQTTPROTOCOL_HDRSUBSCRIBE;
//属性
typedef struct
{
    int nProLen;                                                        //值大小
	XBYTE byProFlag;                                                     //属性标记
    union
    {
        XCHAR tszValue[MAX_PATH];
        int nValue;
        XSHOT wValue;
        XBYTE byValue;
    }st_unValue;
}MQTTPROTOCOL_HDRPROPERTY;
//解析头
typedef struct  
{
    MQTTPROTOCOL_FIXEDHEADER st_FixedHdr;                                //固定头
    MQTTPROTOCOL_HDRCONNNECT st_HDRConnect;                              //可变头,只有CONNECT才有效
    MQTTPROTOCOL_HDRSUBSCRIBE st_HDRSubscribe;                           //只有订阅请求有效

    XCHAR tszTopicName[MAX_PATH];                                         //主题名称
    XCHAR tszClientID[MAX_PATH];
    XCHAR tszClientUser[MAX_PATH];                                        //客户端用户,连接头byFlagsUser和byFlagsPass为真有效
    XCHAR tszClientPass[MAX_PATH];                                        //客户端密码
    int nMsgLen;                                                         //数据总大小
    int nHdrLen;                                                         //协议头大小,负载内容(lpszMsgBuffer + nHdrLen) = (数据区大小)nMsgLen - nHdrLen
    XSHOT wMsgID;                                                        //消息ID
    XBYTE byReason;                                                       //回复包专属,操作结果
    int nPropertyCount;
	MQTTPROTOCOL_HDRPROPERTY** ppSt_HDRProperty;
}MQTTPROTOCOL_INFORMATION;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG MQTTProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     MQTT协议解析导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：MQTTProtocol_Parse_GetHdr
函数功能：获取协议头是否完整
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.三：pInt_DTLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出后续大小
 参数.四：pInt_HdrSize
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输入协议头大小(2字节头+变长负载长度)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MQTTProtocol_Parse_GetHdr(LPCXSTR lpszMsgBuffer, int nMsgLen, int* pInt_DTLen = NULL, int* pInt_HdrSize = NULL);
/********************************************************************
函数名称：MQTTProtocol_Parse_Header
函数功能：MQTT协议解析工具
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析的缓冲区大小
 参数.三：pSt_MQTTProtcol
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析好的缓冲区
返回值
  类型：逻辑型
  意思：是否成功
备注：如果有负载数据,需要自己移动指针
*********************************************************************/
extern "C" bool MQTTProtocol_Parse_Header(LPCXSTR lpszMsgBuffer, int nMsgLen, MQTTPROTOCOL_INFORMATION * pSt_MQTTProtcol);
/************************************************************************/
/*                     MQTT协议打包导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：MQTTProtocol_Packet_Header
函数功能：打包MQTT协议头
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的负载大小(负载数据大小)
 参数.四：byType
  In/Out：In
  类型：字节型
  可空：N
  意思：输入要打包的协议类型
 参数.五：byFlag
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入要打包的协议标识符
返回值
  类型：逻辑型
  意思：是否成功
备注：你应该先打包好负载的协议和数据后在来填充打包这个协议
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_Header(XCHAR* ptszMsgBuffer, int* pInt_Len, int nLen, XBYTE byType, XBYTE byFlag = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_REQConnect
函数功能：打包连接请求
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_HDRConnect
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的连接协议
 参数.四：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入要打包的属性
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的属性个数
 参数.七：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的用户名,如果pSt_HDRConnect->byFlagsUser = 1 必须设置
 参数.八：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要打包的密码,如果pSt_HDRConnect->byFlagsPass = 1 必须设置
返回值
  类型：逻辑型
  意思：是否成功
备注：pSt_HDRConnect你需要自己填充Flags的标记位和HBTime字段
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REQConnect(XCHAR* ptszMsgBuffer, int* pInt_Len, MQTTPROTOCOL_HDRCONNNECT* pSt_HDRConnect, LPCXSTR lpszClientID, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0, LPCXSTR lpszUser = NULL, LPCXSTR lpszPass = NULL);
/********************************************************************
函数名称：MQTTProtocol_Packet_REPConnect
函数功能：打包连接回复
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：byAcknowledge
  In/Out：In
  类型：字符型
  可空：Y
  意思：输入要打包的?
 参数.四：byReason
  In/Out：In
  类型：字符型
  可空：Y
  意思：返回的结果
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入要打包的属性
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的属性个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REPConnect(XCHAR* ptszMsgBuffer, int* pInt_Len, XBYTE byAcknowledge = 0, XBYTE byReason = 0, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_REQSubscribe
函数功能：打包订阅请求
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：wMsgID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入消息ID
 参数.四：lpszTopicName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入订阅的主题名
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入要打包的属性
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的属性个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REQSubscribe(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT wMsgID, LPCXSTR lpszTopicName, MQTTPROTOCOL_HDRSUBSCRIBE* pSt_HDROPtion, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_REQPublish
函数功能：打包请求消息发布协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：lpszTopicName
  In/Out：In
  类型：整数型
  可空：N
  意思：要打包的主题名
 参数.四：wMsgID
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的消息ID,如果QOS为0,那么此值不能填充
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入要打包的属性
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的属性个数
返回值
  类型：逻辑型
  意思：是否成功
备注：负载内容需要自己处理,比如打好包后,在缓冲区后跟上负载的内容即可
      memcpy(ptszMsgBuffer + pInt_Len,send message,message length);
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REQPublish(XCHAR* ptszMsgBuffer, int* pInt_Len, LPCXSTR lpszTopicName, XSHOT wMsgID = 0, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_REPPublish
函数功能：发布消息回复打包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：wMsgID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入消息ID
 参数.四：byReason
  In/Out：In
  类型：字节型
  可空：N
  意思：操作结果
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入属性列表
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：属性列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：QOS为2才有效,其他值不需要回复此包
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REPPublish(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT wMsgID, XBYTE byReason = 0, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_REQUNSubscribe
函数功能：打包请求取消订阅消息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：wMsgID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入消息ID
 参数.四：lpszTopicName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要取消订阅的主题
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入属性列表
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：属性列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REQUNSubscribe(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT wMsgID, LPCXSTR lpszTopicName, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_REPComm
函数功能：通用回复打包协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：wMsgID
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入消息ID
 参数.四：byReason
  In/Out：In
  类型：字符型
  可空：Y
  意思：要回复的结果
 参数.五：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入属性列表
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：属性列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：除非单独列举了回复函数,否则都通过此函数打包回复
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_REPComm(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT wMsgID = 0, XBYTE byReason = 0, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);
/********************************************************************
函数名称：MQTTProtocol_Packet_DisConnect
函数功能：打包断开连接协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：byReason
  In/Out：In
  类型：字符型
  可空：N
  意思：要回复的结果
 参数.四：pppSt_HDRProperty
  In/Out：In
  类型：三级指针
  可空：Y
  意思：输入属性列表
 参数.五：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：属性列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：除非单独列举了回复函数,否则都通过此函数打包回复
*********************************************************************/
extern "C" bool MQTTProtocol_Packet_DisConnect(XCHAR* ptszMsgBuffer, int* pInt_Len, XBYTE byReason = 0, MQTTPROTOCOL_HDRPROPERTY*** pppSt_HDRProperty = NULL, int nListCount = 0);