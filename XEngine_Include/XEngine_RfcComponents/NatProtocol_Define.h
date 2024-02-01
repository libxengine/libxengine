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
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_CLASS_REQUEST 0x000                 //请求
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_CLASS_FLAGS 0x010                   //标志
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_CLASS_RESPONSE 0x100                //回复
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_CLASS_ERROR 0x110                   //错误
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_METHOD_ALLOCATE 0x003               //
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_METHOD_REFRESH 0x004                //
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_METHOD_SEND 0x006                   //
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_METHOD_DATA 0x007                   //
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_METHOD_CREATEPERMISSION 0x008       //创建会话权限,需要对端地址RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_XOR_PEER_ADDRESS
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_METHOD_CHANNELBIND 0x009            //

#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_MAPPED_ADDRESS 0x0001          //映射过的IP地址和端口
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_USERNAME 0x0006                //用于消息的完整性检查
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_PASSWORD 0x0007                //用在共享私密响应中 与USERNAME一起
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_MESSAGE_INTEGRITY 0x0008       //含STUN消息的HMAC-SHA1，它可以出现在捆绑请求或捆绑响应中；MESSAGE-INTEGRITY属性必须是任何STUN消息的最后一个属性
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_ERROR_CODE 0x0009              //出现在捆绑错误响应或共享私密错误响应中。它的响应号数值范围从100到699
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_UNKNOWN_ATTRIBUTES 0x000A      //只存在于其ERROR-CODE属性中的响应号为420的捆绑错误响应或共享私密错误响应中
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_CHANNEL_NUMBER 0x000C          //属性包含通道的号码。属性长4字节，包含16比特的无符号整数和2字节的RFFU字段，该字段必须设为0且在接收时被忽略
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_LIFETIME 0x000D                //属性表示服务器在没有收到refresh时维持一个allocation的持续时间。表示剩余多少秒终止
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_XOR_PEER_ADDRESS 0x0010        //指定从TURN服务器看到的对端的地址和端口，例如如果对端是在一个NAT后面，则为对端的server-reflexive传输地址
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_UDP 0x0011                     //UDP传输协议
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_DATA 0x0013                    //属性存在于所有的Send和Data indications消息中。如果属性的长度不上4字节的倍数，必须进行填充
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_XOR_RELAYED_ADDRESS 0x0016     //存在于所有的Allocate响应中。它指定了服务器分配给客户端的地址和端口
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_REQUESTED_ADDRESS_FAMILY 0x0017
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_EVEN_PORT 0x0018               //属性允许客户端请求在中继传输地址的端口为偶数，并且服务器可选的保留紧跟着的下一个端口号。属性的值长1字节
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_REQUESTED_TRANSPORT 0x0019     //客户端通过该属性为已分配的传输地址请求一个特定的传输协议。属性的值是4字节长度的
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_DONT_FRAGMENT 0x001A           //客户端使用该属性来请求服务器设置IP报头中的DF（不要分片）位，当中继应用数据到对端时。该属性没有值，因此属性长度字段为0
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_XOR_MAPPED_ADDRESS 0x0020
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_TIMER_VAL 0x0021               //
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_RESERVATION_TOKEN 0x0022       //属性包含一个token来唯一的标识一个中继传输地址已经被服务器保留。
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_PRIORITY 0x0024                //优先级
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_USER_CANDIDATE 0x0025          //
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_SERVERNAME 0x8022              //服务名称
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_FINGERPRINT 0x8028             //一种验证机制,必须在报尾
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_ICE_CONTROLLED 0x8029          //ICE的角色,请求方
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_ICE_CONTROLLING 0x802A         //ICE的角色,应答方
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_SERVERADDR 0x802B              //服务地址信息
//IP类型
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_IPV4 0x01   //IPv4
#define RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_IPV6 0x02   //IPv6
//////////////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////////////
typedef struct tag_RfcComponents_NatStun
{
	XCHAR tszServiceName[MAX_PATH];
	XSHOT wOPClass;
	XSHOT wOPMethod;
    XUINT unMagic;
	XBYTE byTokenStr[12];
}RFCCOMPONENTS_NATSTUN, * LPRFCCOMPONENTS_NATSTUN;
typedef struct
{
	XCHAR tszMsgBuffer[2048];
	XSHOT wAttr;
	XSHOT wLen;
}RFCCOMPONENTS_NATATTR;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG NatProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*              STUN客户端导出函数                                      */
/************************************************************************/
/********************************************************************
函数名称：NatProtocol_StunNat_Packet
函数功能：构建一个包
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
 参数.三：lpszTokenStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入事务ID,12个字节数据
 参数.四：nMsgClass
  In/Out：In
  类型：整数型
  可空：N
  意思：消息类型
 参数.五：nMsgMethod
  In/Out：In
  类型：整数型
  可空：N
  意思：消息方法
 参数.六：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要发送的数据包
返回值
  类型：逻辑型
  意思：是否成功
备注：STUN标准协议请求包构建函数,你需要自己使用套接字发送给STUN服务器
*********************************************************************/
extern "C" bool NatProtocol_StunNat_Packet(XCHAR * ptszMsgBuffer, int* pInt_Len, LPCXSTR lpszTokenStr, int nMsgClass, int nMsgMethod, LPCXSTR lpszMsgBuffer = NULL);
/********************************************************************
函数名称：NatProtocol_StunNat_Parse
函数功能：解析一个包
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
 参数.四：pppSt_ListAttr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析的属性列表
 参数.五：pInt_Count
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出解析的属性列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_Parse(LPCXSTR lpszMsgBuffer, int nMsgLen, RFCCOMPONENTS_NATSTUN * pSt_NatClient, RFCCOMPONENTS_NATATTR * **pppSt_ListAttr, int* pInt_Count);
/********************************************************************
函数名称：NatProtocol_StunNat_ParseError
函数功能：解析错误属性
 参数.一：pSt_NATAttr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入属性信息
 参数.二：pInt_ErrorCode
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出错误码
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出错误信息
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出错误信息长度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_ParseError(RFCCOMPONENTS_NATATTR* pSt_NATAttr, int* pInt_ErrorCode, XCHAR* ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：NatProtocol_StunNat_ParseAddr
函数功能：解析地址属性
 参数.一：pSt_NATAttr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入属性信息
 参数.二：pInt_IPVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出IP版本
 参数.三：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出IP地址
 参数.四：bXor
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否进行异或运算
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_ParseAddr(RFCCOMPONENTS_NATATTR* pSt_NATAttr, int* pInt_IPVer, XCHAR* ptszIPAddr, bool bXor = false);
/********************************************************************
函数名称：NatProtocol_StunNat_ParseUNAttr
函数功能：解析未知属性
 参数.一：pSt_NATAttr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入属性信息
 参数.二：pppwListAttr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出无法解析的属性列表
 参数.三：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_ParseUNAttr(RFCCOMPONENTS_NATATTR* pSt_NATAttr, XSHOT *** pppwListAttr, int* pInt_Count);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildAttr
函数功能：构建一个自定义属性包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出组好包的缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小,输出的值是 = 输入的值大小 + 当前属性值大小
 参数.三：wAttr
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要创建的属性类型
 参数.四：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入自定义属性数据
 参数.五：nLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入自定义数据真实大小
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数需要配合NatProtocol_StunNat_Packet来使用,因为他不带协议头
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildAttr(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT wAttr, LPCXSTR lpszValue = NULL, int nLen = 0);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildTransPort
函数功能：打包传输类型
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：byIPType
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入网络类型
返回值
  类型：逻辑型
  意思：是否成功
备注：基于NatProtocol_StunNat_BuildAttr封装
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildTransPort(XCHAR* ptszMsgBuffer, int* pInt_Len, XBYTE byIPType = RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_ATTR_UDP);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildLeftTime
函数功能：打包过期时间包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：nTimesecond
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间单位秒.
返回值
  类型：逻辑型
  意思：是否成功
备注：基于NatProtocol_StunNat_BuildAttr封装
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildLeftTime(XCHAR* ptszMsgBuffer, int* pInt_Len, int nTimesecond = 777);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildEventPort
函数功能：打包端口属性
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
返回值
  类型：逻辑型
  意思：是否成功
备注：基于NatProtocol_StunNat_BuildAttr封装
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildEventPort(XCHAR* ptszMsgBuffer, int* pInt_Len);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildAddrFamily
函数功能：打包地址信息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：byIPVer
  In/Out：In
  类型：字节型
  可空：Y
  意思：输入使用的IP地址版本
返回值
  类型：逻辑型
  意思：是否成功
备注：基于NatProtocol_StunNat_BuildAttr封装
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildAddrFamily(XCHAR* ptszMsgBuffer, int* pInt_Len, XBYTE byIPVer = RFCCOMPONENTS_NATCLIENT_PROTOCOL_STUN_IPV4);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildFinger
函数功能：构建一个属性校验计算的属性包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：lpszMSGBuffer
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要验证的缓冲区.所有属性,除开自身
 参数.四：nMSGLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入属性大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildFinger(XCHAR* ptszMsgBuffer, int* pInt_Len, LPCXSTR lpszMSGBuffer, int nMSGLen);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildMSGIntegrity
函数功能：消息完整性校验
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：lpszMSGBuffer
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要验证的缓冲区,除开自身
 参数.四：nMSGLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入消息属性大小
 参数.五：lpszMSGKey
  In/Out：In
  类型：整数型
  可空：Y
  意思：HMAC的KEY值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildMSGIntegrity(XCHAR* ptszMsgBuffer, int* pInt_Len, LPCXSTR lpszMSGBuffer, int nMSGLen, LPCXSTR lpszMSGKey);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildPriority
函数功能：构建一个优先级属性包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：nCandidateType
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入候选地址类型
 参数.四：nPriority
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入本地优先级
 参数.五：nOrder
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入传输地址顺序
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildPriority(XCHAR* ptszMsgBuffer, int* pInt_Len, int nCandidateType = 0, int nPriority = 100, int nOrder = 1);
/********************************************************************
函数名称：NatProtocol_StunNat_BuildMapAddress
函数功能：构建MAP地址映射属性
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的协议
 参数.二：pInt_Len
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出包大小
 参数.三：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要打包的IP地址
 参数.四：nPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要打包的端口
 参数.五：bXor
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要经过异或
 参数.六：byIPVer
  In/Out：In
  类型：字符型
  可空：Y
  意思：IP版本,默认V4,0x02IPV6.
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_StunNat_BuildMapAddress(XCHAR* ptszMsgBuffer, int* pInt_Len, LPCXSTR lpszIPAddr, int nPort, bool bXor = false, XBYTE byIPVer = 0x01);
/************************************************************************/
/*              TURN客户端导出函数                                      */
/************************************************************************/
/********************************************************************
函数名称：NatProtocol_TurnNat_Create
函数功能：创建TURN数据转发客户端
 参数.一：lpszSourceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始地址
 参数.二：lpszDestAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入目标地址
返回值
  类型：逻辑型
  意思：是否成功
备注：原始和目标地址可以不关注他顺序,只需要两个地址绑定对应即可
*********************************************************************/
extern "C" bool NatProtocol_TurnNat_Create(LPCXSTR lpszSourceAddr, LPCXSTR lpszDestAddr);
/********************************************************************
函数名称：NatProtocol_TurnNat_FindSource
函数功能：通过原始地址查找目标地址
 参数.一：lpszSourceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入查找地址
 参数.二：ptszDestAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出绑定的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_TurnNat_FindSource(LPCXSTR lpszSourceAddr, XCHAR* ptszDestAddr);
/********************************************************************
函数名称：NatProtocol_TurnNat_FindDest
函数功能：通过目标地址来查找对应的原始地址
 参数.一：lpszSourceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入查找地址
 参数.二：ptszDestAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出绑定的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_TurnNat_FindDest(LPCXSTR lpszSourceAddr, XCHAR* ptszDestAddr);
/********************************************************************
函数名称：NatProtocol_TurnNat_Close
函数功能：关闭绑定地址并且释放内存
 参数.一：lpszSourceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入关闭的地址,支持原始地址和目标地址
 参数.二：ptszDestAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出绑定的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool NatProtocol_TurnNat_Close(LPCXSTR lpszSourceAddr, XCHAR* ptszDestAddr = NULL);