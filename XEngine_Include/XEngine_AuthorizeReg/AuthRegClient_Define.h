#pragma once
/********************************************************************
//	Created:	2013/2/1  20:50
//	File Name: 	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegClient\AuthRegClient_Define.h
//	File Path:	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegClient
//	File Base:	AuthRegClient_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	验证服务组件，客户端导出定义。要验证的软件全部由此来操作！
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         回调函数
//////////////////////////////////////////////////////////////////////////
//句柄,是否经过验证(否表示验证超时后者没有验证,时间信息,自定义参数)
typedef void(CALLBACK *CALLBACK_XENGINE_AUTHREG_CLIENT_NETWORD_TIMER)(XNETHANDLE xhNet, BOOL bIsAuth, AUTHREG_PROTOCOL_TIME *pSt_AuthTime, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                         导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AuthRegClient_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                          网络客户端协议导出函数                      */
/************************************************************************/
/********************************************************************
函数名称：AuthRegClient_Protocol_Send
函数功能：填充发送数据协议
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送的缓冲区内容
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出填充好的要发送的缓冲区
 参数.三：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入发送缓冲区内容大小，输出组好包的缓冲区大小
 参数.四：en_AuthProtocol
  In/Out：In
  类型：枚举型
  可空：Y
  意思：协议类型，默认为登陆
 参数.五：byCrypto
  In/Out：In
  类型：字符型
  可空：Y
  意思：是否使用了加密.0没有使用,其他值表示使用的加密类型
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数自带协议头并且填充，剩下的你需要传递要操作的协议数据，比如登录就传递登录协议结构体
*********************************************************************/
extern "C" BOOL AuthRegClient_Protocol_Send(LPCSTR lpszMsgBuffer, CHAR *ptszMsgBuffer, int *pInt_MsgLen, UINT en_AuthProtocol = XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_AUTH_REQLOGIN, BYTE byCrypto = 0);
/********************************************************************
函数名称：AuthRegClient_Protocol_Recv
函数功能：协议处理函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要处理的缓冲区
 参数.二：pInt_AuthProtocol
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出这条数据所属协议类型
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出后续内容大小
 参数.四：pbCrypto
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：导出加密类型
 参数.五：pInt_Error
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出错误码，如果有的话
返回值
  类型：逻辑型
  意思：是否处理成功
备注：输入的数据最好是一个完整的包
*********************************************************************/
extern "C" BOOL AuthRegClient_Protocol_Recv(LPCSTR lpszMsgBuffer, UINT *pInt_AuthProtocol = NULL, int *pInt_MsgLen = NULL, BYTE * pbCrypto = NULL, int *pInt_Error = NULL);
/************************************************************************/
/*                          管理客户端处理导出函数                      */
/************************************************************************/
/********************************************************************
函数名称：AuthRegClient_Manage_Init
函数功能：初始化一个管理客户端
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出初始化成功的客户端句柄
 参数.二：fpCall_NetTimer
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：输入要处理的回调函数地址
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：客户端管理器,通过这几组函数可以方便管理客户端超时
*********************************************************************/
extern "C" BOOL AuthRegClient_Manage_Init(XNETHANDLE *pxhNet, CALLBACK_XENGINE_AUTHREG_CLIENT_NETWORD_TIMER fpCall_NetTimer = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AuthRegClient_Manage_TimeSet
函数功能：设置指定用户的时间信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_AuthTime
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要插入的时间信息
返回值
  类型：逻辑型
  意思：是否成功
备注：初始化成功后,需要请求一次获取时间协议然后把值填入这个函数,客户端管理器才生效
*********************************************************************/
extern "C" BOOL AuthRegClient_Manage_TimeSet(XNETHANDLE xhNet, AUTHREG_PROTOCOL_TIME *pSt_AuthTime);
/********************************************************************
函数名称：AuthRegClient_Manage_TimeGet
函数功能：从一个客户端管理器中获取时间信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：pSt_AuthTime
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的时间信息
返回值
  类型：逻辑型
  意思：是否成功
备注：如果是ERROR_AUTHORIZEREG_CLIENT_NETWORK_TIMEGET_NOTAUTH和ERROR_AUTHORIZEREG_CLIENT_NETWORK_TIMEGET_TIMEOUT
      错误码,那么表示验证超时或者没有验证, 这个时候你需要关闭客户端提醒用户充值
*********************************************************************/
extern "C" BOOL AuthRegClient_Manage_TimeGet(XNETHANDLE xhNet, AUTHREG_PROTOCOL_TIME *pSt_AuthTime);
/********************************************************************
函数名称：AuthRegClient_Manage_Destory
函数功能：从一个管理器中销毁一个客户端
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegClient_Manage_Destory(XNETHANDLE xhNet);
