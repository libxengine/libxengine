#pragma once
/********************************************************************
//	Created:	2013/1/13  20:38
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_P2xp\NetEngine_P2XPDistribution\DistributionCache_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_P2xp\NetEngine_P2XPDistribution
//	File Base:	DistributionCache_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	P2XP数据分发服务，导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
///                          回调函数定义
//////////////////////////////////////////////////////////////////////////
//客户端数据回调函数-如果是TCP第一个参数是 一个客户端句柄,UDP客户端发送过来的地址
typedef void(CALLBACK *CALLBACK_NETENGINE_P2XP_DISTRIBUTION_IOCLIENT_EVENTS)(LPCSTR lpszAddr, LPCSTR lpszBufferMsg, int nLen, BOOL bIsTcp, LPVOID lParam);
//服务器数据回调函数,如果第二个参数为NULL,那么第三个参数0 表示客户端离开,1表示客户端进入,UDP没有客户离开和进入事件
typedef void(CALLBACK *CALLBACK_NETENGINE_P2XP_DISTRIBUTION_IOSERVICE_EVENTS)(LPCSTR lpszAddr, LPCSTR lpszBufferMsg, int nLen, BOOL bIsTcp, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
///                          导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD P2XPDistribution_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                    分发数据模块网络导出函数                          */
/************************************************************************/
/********************************************************************
函数名称：P2XPDistribution_IONetWork_Init
函数功能：初始化网络服务器
 参数.一：nTCPPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要绑定的TCP端口号
 参数.二：nUDPPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要绑定的UDP端口号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_Init(int nTCPPort, int nUDPPort);
/********************************************************************
函数名称：P2XPDistribution_IONetWork_SetCallBack
函数功能：设置客户端回调函数
 参数.一：fpCall_IOClient
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：客户端数据回调函数
 参数.二：fpCall_IOService
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：服务器数据回调函数
 参数.三：lPCient
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数参数
 参数.四：lPService
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数参数
返回值
  类型：逻辑型
  意思：是否设置成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_SetCallBack(CALLBACK_NETENGINE_P2XP_DISTRIBUTION_IOCLIENT_EVENTS fpCall_IOClient, CALLBACK_NETENGINE_P2XP_DISTRIBUTION_IOSERVICE_EVENTS fpCall_IOService, LPVOID lPCient = NULL, LPVOID lPService = NULL);
/********************************************************************
函数名称：P2XPDistribution_IONetWork_Create
函数功能：创建一个网络客户端并且链接到指定服务器
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出创建好的客户端句柄
 参数.二：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要链接的服务器地址
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：服务器端口号
 参数.四：bIsTcp
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：使用TCP还是UDP
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_Create(XNETHANDLE *pxhNet, LPCSTR lpszAddr, int nPort, BOOL bIsTcp = TRUE);
/********************************************************************
函数名称：P2XPDistribution_IONetWork_Close
函数功能：关闭一个指定的客户端
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的客户端的句柄
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_Close(XNETHANDLE xhNet);
/********************************************************************
函数名称：P2XPDistribution_IONetWork_SendClient
函数功能：发送客户端数据包
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要操作哪个客户端
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送的数据缓冲区
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送数据的长度
返回值
  类型：逻辑型
  意思：是否发送成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_SendClient(XNETHANDLE xhNet, LPCSTR lpszMsgBuffer, int nLen);
/********************************************************************
函数名称：P2XPDistribution_IONetWork_SendService
函数功能：服务器发送数据函数
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送给哪个客户端
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送的数据
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送的数据长度
 参数.四：bIsTcp
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：发送TCP还是UDP
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_SendService(LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nLen, BOOL bIsTcp = TRUE);
/********************************************************************
函数名称：P2XPDistribution_IONetWork_Destory
函数功能：销毁网络服务器
返回值
  类型：逻辑型
  意思：是否成功
备注：会同时销毁TCP和UDP服务
*********************************************************************/
extern "C" BOOL P2XPDistribution_IONetWork_Destory();
/************************************************************************/
/*                    文件数据配置接口导出函数                          */
/************************************************************************/
/********************************************************************
函数名称：P2XPDistribution_CacheFile_Init
函数功能：初始化文件缓存服务
 参数.一：pxhFile
  In/Out：Out
  类型：文件句柄
  可空：N
  意思：导出初始化成功的文件句柄
 参数.二：lpszFilePath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：设置接受文件保存的位置 末尾需要/(\\)结束
 参数.三：pSt_ProtoFile
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要写入文件的属性
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheFile_Init(XNETHANDLE *pxhFile, LPCSTR lpszPath, XENGINE_PROTOCOLFILE *pSt_ProtoFile);
/********************************************************************
函数名称：P2XPDistribution_CacheFile_Destory
函数功能：销毁文件缓存服务
 参数.一：pxhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：输入文件句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheFile_Destory(XNETHANDLE xhFile);
/********************************************************************
函数名称：P2XPDistribution_CacheFile_PostFile
函数功能：压入一段文件传输缓冲区
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：输入要操作的文件句柄
 参数.二：pbIsComplate
  In/Out：Out
  类型：逻辑型指针
  可空：N
  意思：导出这个文件是否组包完成
 参数.三：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：缓冲区
 参数.四：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区长度
 参数.五：nStartPos
  In/Out：In
  类型：整数型
  可空：Y
  意思：要移动的指针位置,默认不移动
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheFile_PostFile(XNETHANDLE xhFile, BOOL *pbIsComplate, LPCSTR lpszMsgBuffer, int nMsgLen, __int64x nStartPos = -1);
/********************************************************************
函数名称：P2XPDistribution_CacheFile_GetFile
函数功能：获取一个压入的文件缓冲区属性
 参数.一：xhFile
  In/Out：In
  类型：字符指针
  可空：N
  意思：输入要操作的文件句柄
 参数.二：pSt_ProtoFile
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出文件相应的属性
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheFile_GetFile(XNETHANDLE xhFile, XENGINE_PROTOCOLFILE *pSt_ProtoFile);
/************************************************************************/
/*                    数据数据配置接口导出函数                          */
/************************************************************************/
/********************************************************************
函数名称：P2XPDistribution_CacheStack_Init
函数功能：初始化一个数据缓冲栈服务
返回值
  类型：逻辑型
  意思：是否成功
备注：你可以使用或者可以不使用我们的函数
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheStack_Init();
/********************************************************************
函数名称：P2XPDistribution_CacheStack_Destory
函数功能：销毁一个缓冲栈服务
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheStack_Destory();
/********************************************************************
函数名称：P2XPDistribution_CacheStack_PostMsg
函数功能：提交一个数据到缓冲服务中
 参数.一：lpszClientCode
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交的缓冲区的唯一标识符
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要提交的缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区长度
返回值
  类型：逻辑型
  意思：是否成功
备注：这组函数是PacketPares_Ex_PostEx的封装.这个适合协议或者消息传输,不适合大数据封装
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheStack_PostMsg(LPCSTR lpszClientCode, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：P2XPDistribution_CacheStack_GetMsg
函数功能：获取一个组好包的数据
 参数.一：pszClientCode
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的一个完整数据包的标识符
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出组好包的缓冲区
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出包长度
 参数.四：pSt_ProtocolHdr
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出协议头
返回值
  类型：逻辑型
  意思：是否成功
备注：ptszMsgBuffer + XENGINE_PROTOCOLHDR = NETENGINE_PROTOCOLP2XP.你需要移动指针才是后续数据
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheStack_GetMsg(CHAR *pszClientCode, CHAR *ptszMsgBuffer, int *pInt_Len, XENGINE_PROTOCOLHDR *pSt_ProtocolHdr);
/********************************************************************
函数名称：P2XPDistribution_CacheStack_CloseMsg
函数功能：当这个标识符后续不在使用的时候才需要调用
 参数.一：lpszClientCode
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要关闭的标识符
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL P2XPDistribution_CacheStack_CloseMsg(LPCSTR lpszClientCode);
