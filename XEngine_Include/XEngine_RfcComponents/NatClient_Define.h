#pragma once
/********************************************************************
//	Created:	2019/2/26   9:56
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_NatClient\NatClient_Define.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_NatClient
//	File Base:	NatClient_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	NAT客户端导出函数定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////////////
//                         导出的定义
//////////////////////////////////////////////////////////////////////////////////
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_BINDREQ 0x0001                      //捆绑请求
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_BINDREP 0x0101                      //捆绑响应
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_BINDERR 0x0111                      //捆绑错误响应
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_SECREQ 0x0002                       //共享私密请求
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_SECREP 0x0102                       //共享私密响应
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_SECERR 0x0112                       //共享私密错误响应

#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_MAPPED_ADDRESSREQ 0x0001       //映射过的IP地址和端口
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_MAPPED_ADDRESSREP 0x0002       //响应的目的地址
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_CHANGE_REQUEST 0x0003          //客户使用32位的CHANGE-REQUEST属性来请求服务器使用不同的地址或端口号来发送响应。
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_SOURCE_ADDRESS 0x0004          //出现在捆绑响应中，它表示服务器发送响应的源IP地址和端口
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_CHANGED_ADDRESS 0x0005         //如果捆绑请求的CHANGE-REQUEST属性中的IP端口标志设置了，则CHANGED-ADDRESS属性表示响应发出的IP地址和端口号。
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_USERNAME 0x0006                //用于消息的完整性检查
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_PASSWORD 0x0007                //用在共享私密响应中 与USERNAME一起
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_MESSAGE_INTEGRITY 0x0008       //含STUN消息的HMAC-SHA1，它可以出现在捆绑请求或捆绑响应中；MESSAGE-INTEGRITY属性必须是任何STUN消息的最后一个属性
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_ERROR_CODE 0x0009              //出现在捆绑错误响应或共享私密错误响应中。它的响应号数值范围从100到699
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_UNKNOWN_ATTRIBUTES 0x000A      //只存在于其ERROR-CODE属性中的响应号为420的捆绑错误响应或共享私密错误响应中
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_REFLECTED_FROM 0x000B          //只存在于其对应的捆绑请求包含RESPONSE-ADDRESS属性的捆绑响应中,属性包含请求发出的源IP地址，它的目的是提供跟踪能力
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_XOR_MAPPED_ADDRESS 0x0020
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_SERVERNAME 0x8022
//////////////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////////////
typedef struct tag_RfcComponents_NatStun
{
    CHAR tszUser[128];
    CHAR tszPass[128];
    CHAR tszServerVer[128];
    UINT xhToken[4];
    UINT nCode;
    struct
    {
        CHAR tszIPAddr[128];
        int nPort;
        int nFamily;
    }st_MappedAddr;
    struct
    {
        CHAR tszIPAddr[128];
        int nPort;
        int nFamily;
    }st_SrcAddr;
    struct
    {
        CHAR tszIPAddr[128];
        int nPort;
        int nFamily;
    }st_ChangeAddr;
}RFCCOMPONENTS_NATSTUN, * LPRFCCOMPONENTS_NATSTUN;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" DWORD NatClient_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*              STUN客户端导出函数                                      */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_StunNat_Request
函数功能：构建一个请求包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出组好的STUN协议请求缓冲区
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入 第四个参数的缓冲区大小(如果有的话),输出组好包的数据大小
 参数.三：nMsgType
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要传递的协议包类型
 参数.四：pInt_Token
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出创建的TOKEN = UINT[4]
 参数.五：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要发送的数据包
返回值
  类型：逻辑型
  意思：是否成功
备注：STUN标准协议请求包构建函数,你需要自己使用UDP套接字发送给STUN服务器
*********************************************************************/
extern "C" BOOL RfcComponents_StunNat_Request(CHAR * ptszMsgBuffer, int* pInt_Len, int nMsgType, UINT * pInt_Token = NULL, LPCSTR lpszMsgBuffer = NULL);
/********************************************************************
函数名称：RfcComponents_StunNat_Response
函数功能：解析一个回复包
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
 参数.三：pSt_NatClient
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析成功的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_StunNat_Response(LPCSTR lpszMsgBuffer, int nMsgLen, RFCCOMPONENTS_NATSTUN* pSt_NatClient);
/********************************************************************
函数名称：RfcComponents_StunNat_BuildAttr
函数功能：构建一个属性包
 参数.一：wAttr
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要创建的属性类型
 参数.二：wLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入属性后续大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出组好包的缓冲区
 参数.四：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入自定义属性数据
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数需要配合RfcComponents_StunNat_Request 来使用,因为他不带协议头
*********************************************************************/
extern "C" BOOL RfcComponents_StunNat_BuildAttr(WORD wAttr, WORD wLen, CHAR* ptszMsgBuffer, int* pInt_Len, LPCSTR lpszValue = NULL);
