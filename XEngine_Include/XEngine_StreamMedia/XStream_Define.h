#pragma once
/********************************************************************
//	Created:	2020/07/10   10:57
//	Filename: 	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XStream\XStream_Define.h
//	File Path:	H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XStream
//	File Base:	XStream_Define
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	X流媒体协议导出定义
//	History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" DWORD XStream_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
                                 导出X实时流推送函数
******************************************************************************/
/********************************************************************
函数名称：XStream_ClientPush_Init
函数功能：初始化一个流媒体推送客户端
 参数.一：pxhToken
  In/Out：Out
  类型：网络句柄指针
  可空：N
  意思：导出一个新的推送客户端句柄
 参数.二：lpszServiceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要连接到哪个流媒体服务器
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要连接的端口
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPush_Init(XNETHANDLE * pxhToken, LPCSTR lpszServiceAddr, int nPort);
/********************************************************************
函数名称：XStream_ClientPush_PushHdr
函数功能：投递一个协议头
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要给哪个客户端投递协议头
 参数.二：pSt_AVProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要投递的音视频参数协议
返回值
  类型：逻辑型
  意思：是否成功
备注：在发送包之前调用,否则将出错
*********************************************************************/
extern "C" BOOL XStream_ClientPush_PushHdr(XNETHANDLE xhToken, XENGINE_PROTOCOL_AVINFO * pSt_AVProtocol);
/********************************************************************
函数名称：XStream_ClientPush_PushStatus
函数功能：推送一个状态信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的推流端
 参数.二：pSt_SMSProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要推流的信息,推流数据大小和时间戳字段可为0
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPush_PushStatus(XNETHANDLE xhToken, XENGINE_PROTOCOL_SMS * pSt_SMSProtocol);
/********************************************************************
函数名称：XStream_ClientPush_PushPkg
函数功能：投递编码好的H264数据
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要给哪个客户端投递编码的数据
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要投递数据的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要投递数据的长度
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要自己计算每秒发送间隔
*********************************************************************/
extern "C" BOOL XStream_ClientPush_PushPkg(XNETHANDLE xhToken, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：XStream_ClientPush_GetSpeed
函数功能：获取推送速度
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的推流器
 参数.二：pInt_MillSleep
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的等待时间,毫秒
 参数.三：pSt_SMSProtocol
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出获取到的服务器发送的处理信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPush_GetSpeed(XNETHANDLE xhToken, int* pInt_MillSleep, XENGINE_PROTOCOL_SMS* pSt_SMSProtocol = NULL);
/********************************************************************
函数名称：XStream_ClientPush_Close
函数功能：关闭一个客户端
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的客户端句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPush_Close(XNETHANDLE xhToken);
/******************************************************************************
                                 导出X实时流拉流函数
******************************************************************************/
/********************************************************************
函数名称：XStream_ClientPull_Init
函数功能：初始化一个流媒体拉流客户端
 参数.一：pxhToken
  In/Out：Out
  类型：网络句柄指针
  可空：N
  意思：导出一个新的拉流客户端句柄
 参数.二：lpszServiceAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要连接到哪个流媒体服务器
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要连接的端口
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPull_Init(XNETHANDLE* pxhToken, LPCSTR lpszServiceAddr, int nPort);
/********************************************************************
函数名称：XStream_ClientPull_PushHdr
函数功能：投递一个协议头
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要给哪个客户端投递协议头
 参数.二：xhStreamID
  In/Out：In
  类型：句柄
  可空：N
  意思：流ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPull_PushHdr(XNETHANDLE xhToken, XNETHANDLE xhStreamID);
/********************************************************************
函数名称：XStream_ClientPull_PushStatus
函数功能：推送状态协议
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pSt_SMSProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入客户端当前处理状态,时间戳和接受数据大小字段可为空
返回值
  类型：逻辑型
  意思：是否成功
备注：每隔1-5秒钟,拉流端需要推送一个获取数据的状态信息给服务器
*********************************************************************/
extern "C" BOOL XStream_ClientPull_PushStatus(XNETHANDLE xhToken, XENGINE_PROTOCOL_SMS* pSt_SMSProtocol);
/********************************************************************
函数名称：XStream_ClientPull_Play
函数功能：开始播放
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要播放的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPull_Play(XNETHANDLE xhToken);
/********************************************************************
函数名称：XStream_ClientPull_Pause
函数功能：暂停播放
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要暂停的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPull_Pause(XNETHANDLE xhToken);
/********************************************************************
函数名称：XStream_ClientPull_Get
函数功能：获取音视频数据
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要操作的客户端
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出缓冲区大小
 参数.四：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间
返回值
  类型：逻辑型
  意思：是否成功
备注：建议使用组包模块来把获取到的数据投递进去组包
*********************************************************************/
extern "C" BOOL XStream_ClientPull_Get(XNETHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nTimeout = 1);
/********************************************************************
函数名称：XStream_ClientPull_GetAVParament
函数功能：获取音视频参数信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pSt_AVParament
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出获取到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPull_GetAVParament(XNETHANDLE xhToken, XENGINE_PROTOCOL_AVINFO* pSt_AVParament);
/********************************************************************
函数名称：XStream_ClientPull_Close
函数功能：关闭一个客户端
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的客户端句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStream_ClientPull_Close(XNETHANDLE xhToken);
