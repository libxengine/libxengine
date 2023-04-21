#pragma once
/********************************************************************
//	Created:	    2017/03/15  11:06
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_WSFrame\WSFrame_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_WSFrame
//	File Base:	WSFrame_Define
//	File Ext:	    h
//  Project:     NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:     WEBSOCKET帧协议解析器导出定义
//	History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                               导出的数据结构
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
    ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE_CONTINUE = 0x00,
    ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE_TEXT = 0x01,
    ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE_BINARY = 0x02,
    ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE_CLOSE = 0x08,
    ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE_PING = 0x09,
    ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE_PONG = 0x0A
}ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE, *LPENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE;
//////////////////////////////////////////////////////////////////////////
//                       导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
    XCHAR tszClientAddr[64];                                              //客户端唯一ID信息
    int nPktCount;                                                        //客户端待处理数据个数
}RFCCOMPONENTS_WSPKT_CLIENT;
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" XLONG WSFrame_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
                                导出WS帧解析函数
******************************************************************************/
/********************************************************************
函数名称：RfcComponents_WSCodec_DecodeMsg
函数功能：解码一个封包
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解码的数据缓冲区
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要解码的大小,输出数据大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解码好的缓冲区
 参数.四：pen_OPCode
  In/Out：Out
  类型：枚举型指针
  可空：Y
  意思：输出数据负载类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSCodec_DecodeMsg(LPCXSTR lpszMsgBuffer, int* pInt_Len, XCHAR* ptszMsgBuffer, ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE* pen_OPCode = NULL);
/********************************************************************
函数名称：RfcComponents_WSCodec_EncodeMsg
函数功能：编码一个消息包
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要编码的数据缓冲区,如果打包的是协议,这个值填NULL,参数二填0
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出编码后的数据缓冲区
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要编码数据缓冲区大小，输出编码后的数据缓冲区大小
 参数.四：enOPCode
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入数据包负载类型
 参数.五：bMask
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：负载数据是否需要掩码操作,客户端需要,服务器不需要
返回值
  类型：逻辑型
  意思：是否处理成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSCodec_EncodeMsg(LPCXSTR lpszMsgBuffer, XCHAR* ptszMsgBuffer, int* pInt_Len, ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE enOPCode, bool bMask = false);
/******************************************************************************
                                导出WS连接器处理函数
******************************************************************************/
/********************************************************************
函数名称：RfcComponents_WSConnector_HandShake
函数功能：处理一段数据判断是否是websocket的连接信息数据
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入缓冲区的数据
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要处理的缓冲区大小,输出打好包的缓冲区大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的数据缓冲区
返回值
  类型：逻辑型
  意思：是否处理成功
备注：返回真，表示这个数据是websocket的连接数据。返回假表示不是websocket数据
      输出的参数缓冲区需要发送给客户端才能正确建立连接
*********************************************************************/
extern "C" bool RfcComponents_WSConnector_HandShake(LPCXSTR lpszMsgBuffer, int* pInt_Len, XCHAR * ptszMsgBuffer);
/********************************************************************
函数名称：RfcComponents_WSConnector_Connect
函数功能：客户端连接打包函数
 参数.一：ptszKeyBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出生成的唯一客户端唯一KEY
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出要发送请求的数据
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出发送数据的大小
 参数.四：lpszUrl
  In/Out：Out
  类型：常量字符指针
  可空：Y
  意思：输入资源请求路径
 参数.五：lpszHost
  In/Out：Out
  类型：常量字符指针
  可空：Y
  意思：输入主机地址端口,某些服务器需要,不输入会返回403错误
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSConnector_Connect(XCHAR* ptszKeyBuffer, XCHAR* ptszMsgBuffer, int* pInt_Len, LPCXSTR lpszUrl = "/", LPCXSTR lpszHost = NULL);
/********************************************************************
函数名称：RfcComponents_WSConnector_VerConnect
函数功能：验证连接信息
 参数.一：lpszKeyBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入连接创建的唯一KEY
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要验证的缓冲区
 参数.三：pInt_Pos
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出数据偏移地址(部分服务器在连接成功后会返回头+数据的方式,这个值可以让你确定数据起始位置)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSConnector_VerConnect(LPCXSTR lpszKeyBuffer, LPCXSTR lpszMsgBuffer, int* pInt_Pos = NULL);
/******************************************************************************
                                导出WS组包器处理函数
******************************************************************************/
/************************************************************************
函数名称：RfcComponents_WSPacket_Init
函数功能：初始化一个组包器
 参数.一：nPoolCount
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：初始化的任务池个数
 参数.二：ullMaxPacketCount
   In/Out：In
   类型：无符号四字
   可空：Y
   意思：最大允许组包器一共拥有多少个包存在，默认10W条
 参数.三：bIsClear
   In/Out：In
   类型：常量字符指针
   可空：Y
   意思：当组包器最大个数后，是清理包还是拒绝入包。默认为假，不入库
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：注意第三个参数，建议使用清理功能，因为不入库可能导致你的协议流数据乱，那么后面的数据可能不正常！
************************************************************************/
extern "C" XHANDLE RfcComponents_WSPacket_InitEx(int nPoolCount = 0, __int64u ullMaxPacketCount = 100000, bool bIsClear = false);
/********************************************************************
函数名称：RfcComponents_WSPacket_Destory
函数功能：销毁组包器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_DestoryEx(XHANDLE xhToken);
/********************************************************************
函数名称：RfcComponents_WSPacket_Create
函数功能：为一个指定的ID地址创建组包器
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要创建的ID
 参数.二：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要把这个客户端放在第几个任务池
返回值
  类型：逻辑型
  意思：是否成功
备注：请注意ID非常重要，如果ID不同那么组包是不起作用的，ID需要你自己分配
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_CreateEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, int nPoolIndex = -1);
/************************************************************************
函数名称：RfcComponents_WSPacket_InsertQueueEx
函数功能：投递组包函数
 参数.一：lpszClientAddr
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：组包ID，可以是任意字符串，当对方发送数据过来需要拆包组包的时候这个ID可以是IP+端口。
 参数.二：lpszPostMsg
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：要投递的数据缓冲区
 参数.三：nMsgLen
   In/Out：In
   类型；整数型
   可空：N
   意思：数据的大小
 参数.四：enPacket_Priority
   In/Out：In
   类型；枚举型
   可空：Y
   意思：数据包的优先级
返回值
  类型：逻辑型
  意思：是否投递成功
备注：
************************************************************************/
extern "C" bool RfcComponents_WSPacket_InsertQueueEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, LPCXSTR lpszPostMsg, int nMsgLen);
/************************************************************************
函数名称：RfcComponents_WSPacket_Clear
函数功能：清理缓冲区
  参数一：lpszClientAddr
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：要清理的组包ID
返回值
  类型：逻辑型
  意思：是否成功清楚缓冲表
备注：
************************************************************************/
extern "C" bool RfcComponents_WSPacket_ClearEx(XHANDLE xhToken, LPCXSTR lpszClientAddr);
/************************************************************************
函数名称：RfcComponents_WSPacket_Delete
函数功能：删除一个指定ID的组包器
  参数一：lpszClientAddr
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：要删除的ID
返回值
  类型：逻辑型
  意思：是否成功清楚缓冲表
备注：
************************************************************************/
extern "C" bool RfcComponents_WSPacket_DeleteEx(XHANDLE xhToken, LPCXSTR lpszClientAddr);
/************************************************************************
函数名称：RfcComponents_WSPacket_Get
函数功能：分解一个已经组好的包，并且导出
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取哪个指定ID的包
 参数.二：ptszPacket
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出后续的数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型；整数型指针
  可空：N
  意思：输入你的数据缓冲区大小，输出真实缓冲区后续数据大小
 参数.四：pSt_ProtocolHdr
  In/Out：In
  类型；数据结构指针
  可空：Y
  意思：是否导出协议头，默认不导出
 参数.五：bIsFree
  In/Out：In
  类型；逻辑型
  可空：Y
  意思：为真将释放获取到的包，为假不释放获取到的包的内存
 参数.五：bIsTry
  In/Out：In
  类型；逻辑型
  可空：Y
  意思：是否使用尝试获取包模式,如果使用此模式,没有完整的包将立即返回
返回值
  类型：逻辑型
  意思：是否获取成功
备注：返回ERROR_RFCCOMPONENTS_WEBSOCKET_PACKET_GET_SMALL 表示太小了，最后一个参数会被填充需要的缓冲区大小
************************************************************************/
extern "C" bool RfcComponents_WSPacket_GetEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XCHAR * ptszPacket, int* pInt_Len, ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE * pen_OPCode = NULL, bool bIsFree = true, bool bIsTry = true);
extern "C" bool RfcComponents_WSPacket_GetMemoryEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XCHAR * *pptszPacket, int* pInt_Len, ENUM_XENGINE_RFCOMPONENTS_WEBSOCKET_OPCODE * pen_OPCode = NULL, bool bIsFree = true, bool bIsTry = true);
/********************************************************************
函数名称：RfcComponents_WSPacket_GetPool
函数功能：获取对应池化客户端列表
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入池化索引
 参数.二：pppSt_ListClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出可用客户端数据列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型
  可空：Y
  意思：输出可用客户端列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_GetPoolEx(XHANDLE xhToken, int nPoolIndex, RFCCOMPONENTS_WSPKT_CLIENT * **pppSt_ListClient, int* pInt_ListCount);
/************************************************************************
函数名称：RfcComponents_WSPacket_GetCount
函数功能：获取当前有多少个可用完整包
返回值
  类型：四字
  意思：返回可用完整包个数
备注：
************************************************************************/
extern "C" __int64u RfcComponents_WSPacket_GetCountEx(XHANDLE xhToken);
/********************************************************************
函数名称：RfcComponents_WSPacket_SetLogin
函数功能：设置登录结果
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获取的客户端地址
 参数.二：bLogin
  In/Out：In
  类型：逻辑型
  可空：N
  意思：输入登录结果
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_SetLoginEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, bool bLogin = true);
/********************************************************************
函数名称：RfcComponents_WSPacket_GetLogin
函数功能：获取登录结果
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获取的客户端地址
 参数.二：pbLogin
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：输出是否设置登录
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_GetLoginEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, bool * pbLogin);
/********************************************************************
函数名称：RfcComponents_WSPacket_SetMode
函数功能：设置接受模式
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要设置的客户端
 参数.二：bFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入是否为文件接受模式
返回值
  类型：逻辑型
  意思：是否成功
备注：文件接受模式收到包后将直接导出
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_SetMode(XHANDLE xhToken, LPCXSTR lpszClientAddr, bool bFile = true);
/********************************************************************
函数名称：RfcComponents_WSPacket_GetMode
函数功能：获取接受模式
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获取的客户端
 参数.二：pbFile
  In/Out：In
  类型：逻辑型指针
  可空：Y
  意思：输出文件模式
返回值
  类型：逻辑型
  意思：是否成功
备注：文件接受模式收到包后将直接导出
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_GetMode(XHANDLE xhToken, LPCXSTR lpszClientAddr, bool* pbFile);
/************************************************************************
函数名称：RfcComponents_WSPacket_WaitEvent
函数功能：等待一个数据事件发生
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的任务池索引
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
extern "C" bool RfcComponents_WSPacket_WaitEventEx(XHANDLE xhToken, int nPoolIndex = -1, int nTimeOut = -1);
/********************************************************************
函数名称：RfcComponents_WSPacket_ActiveEvent
函数功能：手动触发一次事件
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的任务池索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool RfcComponents_WSPacket_ActiveEventEx(XHANDLE xhToken, int nPoolIndex = -1);
