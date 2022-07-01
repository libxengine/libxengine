#pragma once
/********************************************************************
//    Created:     2021/09/01  15:01:39
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_SnmpProtocol\SnmpProtocol_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_SnmpProtocol
//    File Base:   SnmpProtocol_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     SNMP导出函数定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         导出的类型
//////////////////////////////////////////////////////////////////////////
//协议版本
#define XENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V1 0
#define XENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V2 1                          //V2C协议
#define XENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V3 2                          //暂时不支持
//操作类型
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_BOOLEAN 0x01                       //逻辑型
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_INTEGER 0x02                       //整数
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_BIT_STRING 0x03                    //位字符串
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_OCTET_STRING 0x04                  //字符串
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_NULL 0x05                          //NULL
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_OID 0x06                           //对象标识符
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_SEQUENCE 0x30                      //序列
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_COUNTER 0x41
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_GAUGE 0x42
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_TIME_TICKS 0x43
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_NO_SUCH_OBJECT 0x80
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_NO_SUCH_INSTANCE 0x81
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_END_OF_MIB_VIEW 0x82
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_GET 0xA0                           //获取请求
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_GETNEXT 0xA1                       //获取下一条信息
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_RESPONSE 0xA2                      //获取回复
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_SET 0xA3                           //设置请求
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_SNMP_GETBULK	0xA5                  
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_SNMP_INFORM 0xA6
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_SNMP_TRAP 0xA7
#define XENGINE_SNMP_PROTOCOL_BER_TYPE_SNMP_REPORT 0xA8
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    struct  
    {
		struct
		{
			CHAR tszUsername[64];
			CHAR tszPassword[64];
			int nAuthType;
		}st_AuthVer;                                                      //暂时不支持V3验证协议
		struct
		{
            DWORD dwMsgID;                                                //消息ID
            WORD wMsgSize;                                                //消息允许负载大小
            BYTE byMsgFlag;                                               //消息标志
            BYTE byModel;                                                 //安全模式
		}st_MsgGlobal;                                                    //消息全局信息,这个请求需要用户填充,获取由系统填充
        struct  
        {
            CHAR tszUsername[64];                                        //引擎负载用户
            CHAR tszEngineID[64];                                        //引擎ID
            int nEngineTime;                                              //引擎时间
            BYTE byEngineBoots;                                           //引擎重启次数
            BYTE byEngineAuthParam;                                       //引擎安全参数
            BYTE byEnginePrivacyParam;                                    //隐私参数
        }st_Engine;
    }st_ProtocolV3;                                                       //V3需要
    struct
    {
        CHAR tszOIDStr[MAX_PATH];                                        //用户设置
        CHAR tszTetStr[MAX_PATH];                                        //SET有效
        int nOLen;                                                        //设置用户,获取系统
        int nTLen;
    }st_BindVar;
    struct
    {
        DWORD dwSerial;                                                   //序列号,用户设置
        BYTE byStatus;                                                    //系统填充
        BYTE byIndex;                                                     //系统填充
    }st_PacketInfo;
    CHAR tszCommname[MAX_PATH];                                           //用户填充,V1 2无效
    BYTE byVersion;                                                       //用户填充
    BYTE byOPCode;                                                        //设置用户填充,获得系统填充
    BYTE byFlags;                                                         //变化标志位,普通0,填充1,用户不关心
}RFCSNMP_PROTOCOL;
#pragma pack(push)
#pragma pack(1)
typedef struct
{
    BYTE byMsgType;                               //消息类型
    BYTE byMsgLen;                                //消息总大小
    //BYTE* pbyMsgData;                             //值
}SNMPPROTOCOL_HEADER;
typedef struct
{
	BYTE byMsgType;                               //消息类型
    BYTE byMsgOP;                                 //消息操作
	BYTE byMsgLen;                                //消息总大小
}SNMPPROTOCOL_HEADERV2;
#pragma pack(pop)
//////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD SnmpProtocol_GetLastError(int* pInt_SysError = NULL);
/************************************************************************/
/*                         SNMP协议打包导出函数                         */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SnmpPacket_Protocol
函数功能：SNMP协议打包函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_SNMPProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入SNMP协议信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpPacket_Protocol(CHAR * ptszMsgBuffer, int* pInt_MsgLen, RFCSNMP_PROTOCOL * pSt_SNMPProtocol);
/************************************************************************/
/*                         SNMP协议解析导出函数                         */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SnmpParse_Protocol
函数功能：SNMP协议解析函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_SNMPProtocol
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输出解析到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpParse_Protocol(LPCSTR lpszMsgBuffer, int nMsgLen, RFCSNMP_PROTOCOL * pSt_SNMPProtocol);
/************************************************************************/
/*                         SNMP帮助导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SnmpHelp_OIDPacket
函数功能：字符串转OID
 参数.一：lpszOIDString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的字符串
 参数.二：ptszOIDBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的内容
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpHelp_StrToOID(LPCSTR lpszOIDString, CHAR * ptszOIDBuffer, int* pInt_Len);
/********************************************************************
函数名称：RfcComponents_SnmpHelp_OIDNumber
函数功能：转换OID的值
 参数.一：lpszOIDNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的OID值
 参数.二：ptszOIDBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的值
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpHelp_OIDPKTLen(LPCSTR lpszOIDNumber, CHAR * ptszOIDBuffer, int* pInt_Len);
/********************************************************************
函数名称：RfcComponents_SnmpHelp_OIDToStr
函数功能：OID转字符串
 参数.一：lpszOIDHex
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：OID缓冲区
 参数.二：nOLen
  In/Out：In
  类型：整数型
  可空：N
  意思：OID缓冲区大小
 参数.三：ptszOIDBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出OID转换后的缓冲区
 参数.四：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpHelp_OIDToStr(LPCSTR lpszOIDHex, int nOLen, CHAR * ptszOIDBuffer, int* pInt_Len);