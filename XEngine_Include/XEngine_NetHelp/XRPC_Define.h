#pragma once
/********************************************************************
//	Created:	2020/5/10   18:13
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_XRpc\XRPC_Define.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_NetHelp\NetHelp_XRpc
//	File Base:	XRPC_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:  	qyt
//	Purpose:	XRPC导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的枚举型
//////////////////////////////////////////////////////////////////////////
//IP范围分类
typedef enum en_NetHelp_XRpc_ParameteType
{
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_UNKNOW = 0,                           //未知类型,请求端可以为0,不指定
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_VOID = 1,                             //无类型,使用此类型作为返回值,服务器将不返回任何东西
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_BOOL = 2,                             //逻辑型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_INT = 3,                              //整数型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_UINT = 4,                             //无符号整数型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_LONGINT = 5,                          //长整数型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_ULONG = 6,                            //无符号长整数型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_FLOAT = 7,                            //浮点型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_DOUBLE = 8,                           //双精度浮点型
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_STRING = 9,                           //字符串
    ENUM_NETHELP_XRPC_PARAMETE_TYPE_BIN = 10                              //二进制数据
}ENUM_NETHELP_XRPC_PARAMETE_TYPE, * LPENUM_NETHELP_XRPC_PARAMETE_TYPE;
//////////////////////////////////////////////////////////////////////////
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_NetHelp_XRpcParamete
{
    ENUM_NETHELP_XRPC_PARAMETE_TYPE enXRPC_ParameteType;                  //参数类型
    int nParameteLen;                                                     //参数大小,数值相关类型这个值可以为0
    LPVOID lParameteValue;                                                //自定义参数值
}NETHELP_XRPCPARAMETE, * LPNETHELP_XRPCPARAMETE;
//////////////////////////////////////////////////////////////////////////
//                        导出的回调函数
//////////////////////////////////////////////////////////////////////////
//客户端函数调用返回结果回调函数,参数:客户端句柄,函数名称,返回值类型,返回值,自定义参数
typedef void(CALLBACK* CALLBACK_NETENGINE_NETHELP_XRPC_CLIENT_FUNCCALL)(XNETHANDLE xhToken, LPCSTR lpszFuncName, ENUM_NETHELP_XRPC_PARAMETE_TYPE nRtnType, NETHELP_XRPCPARAMETE* pSt_XRPCParamete, LPVOID lParam);
//服务器函数被调用,参数:客户端地址,函数名称,请求返回的类型,请求的参数,参数个数,自定义参数(这个参数内存由系统管理)
typedef void(CALLBACK* CALLBACK_NETENGINE_NETHELP_XRPC_CORE_FUNCCALL)(LPCSTR lpszClientAddr, LPCSTR lpszFuncName, ENUM_NETHELP_XRPC_PARAMETE_TYPE nRtnType, NETHELP_XRPCPARAMETE*** pppSt_ListParamete, int nListCount, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD XRpc_GetLastError(int* pInt_SysError = NULL);
/*********************************************************************************
*                          XRPC协议导出的函数                                    *
*********************************************************************************/
/********************************************************************
函数名称：XRPCProtocol_Client_ReqFuncCall
函数功能：打包远程调用函数协议
 参数.一：lpszFuncName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入函数名称
 参数.二：enRtnType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入返回值类型
 参数.三：pppSt_ListParamete
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入参数
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入参数个数
 参数.五：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的数据
 参数.六：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入:提供缓冲区大小 输出:打包的数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：pppSt_ListParamete内存由用户申请和释放
*********************************************************************/
extern "C" BOOL XRPCProtocol_Client_ReqFuncCall(LPCSTR lpszFuncName, ENUM_NETHELP_XRPC_PARAMETE_TYPE enRtnType, NETHELP_XRPCPARAMETE * **pppSt_ListParamete, int nListCount, CHAR* ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：XRPCProtocol_Client_RepFuncCall
函数功能：客户端返回数据解析函数
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
 参数.三：ptszFuncName
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出服务器返回的函数名称
 参数.四：pSt_ReturnValue
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出返回的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XRPCProtocol_Client_RepFuncCall(LPCSTR lpszMsgBuffer, int nMsgLen, CHAR* ptszFuncName, NETHELP_XRPCPARAMETE* pSt_ReturnValue);
/********************************************************************
函数名称：XRPCProtocol_Core_ParseFuncCall
函数功能：服务器解析函数调用
 参数.一：lpszFuncName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区,这个缓冲区不包含协议头
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要解析缓冲区大小
 参数.三：ptszFuncName
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出这个请求的函数名称
 参数.四：penRtnType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出返回值类型
 参数.五：pppSt_ListParamete
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出解析出来的参数
 参数.六：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出参数个数
返回值
  类型：逻辑型
  意思：是否成功
备注：必须使用帮助函数的内存释放函数进行释放内存
*********************************************************************/
extern "C" BOOL XRPCProtocol_Core_ParseFuncCall(LPCSTR lpszMsgBuffer, int nMsgLen, CHAR * ptszFuncName, ENUM_NETHELP_XRPC_PARAMETE_TYPE * penRtnType, NETHELP_XRPCPARAMETE * **pppSt_ListParamete, int* pInt_ListCount);
/********************************************************************
函数名称：XRPCProtocol_Core_RepFuncCall
函数功能：好
 参数.一：lpszFuncName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要返回的函数名
 参数.二：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入返回内容
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入返回内容大小
 参数.四：enXRPC_ParamType
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要返回的类型
 参数.五：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：打好包的数据
 参数.六：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出获取到的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XRPCProtocol_Core_RepFuncCall(LPCSTR lpszFuncName, LPCSTR lpszValue, int nMsgLen, ENUM_NETHELP_XRPC_PARAMETE_TYPE enXRPC_ParamType, CHAR* ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：XRPCProtocol_Core_Packet
函数功能：打包函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要打包的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的数据大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的数据
 参数.四：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打好包的数据大小
 参数.五：bRequest
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是请求还是回复打包
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XRPCProtocol_Core_Packet(LPCTSTR lpszMsgBuffer, int nMsgLen, TCHAR* ptszMsgBuffer, int* pInt_Len, BOOL bRequest = TRUE);
/*********************************************************************************
*                          XRPC客户导出的函数                                    *
*********************************************************************************/
/********************************************************************
函数名称：NetHelp_XRPCClient_Connect
函数功能：连接一个XRPC服务器并且初始化
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建成功的句柄
 参数.二：lpszServerAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要连接的服务器地址
 参数.三：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：服务器端口
 参数.四：fpCall_FuncCall
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：设置函数返回的回调地址,如果为NULL,将使用同步模式
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCClient_Connect(XNETHANDLE* pxhToken, LPCSTR lpszServerAddr, int nPort, CALLBACK_NETENGINE_NETHELP_XRPC_CLIENT_FUNCCALL fpCall_FuncCall = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：NetHelp_XRPCClient_Close
函数功能：关闭一个客户端
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCClient_Close(XNETHANDLE xhToken);
/********************************************************************
函数名称：NetHelp_XRPCClient_ReqFuncCall
函数功能：远程函数调用函数
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszFuncName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要调用的函数
 参数.三：enRtnType
  In/Out：In/Out
  类型：枚举型指针
  可空：N
  意思：输入要返回的类型
 参数.四：pppSt_ListParamete
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入函数参数
 参数.五：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入参数个数
 参数.六：pSt_XRPCParamete
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出获取到的数据,如果返回的值是UNKNOW或者VOID,表示没有返回值,那么可以为NULL
返回值
  类型：逻辑型
  意思：是否成功
备注：pppSt_ListParamete内存由用户申请和释放
*********************************************************************/
extern "C" BOOL NetHelp_XRPCClient_ReqFuncCall(XNETHANDLE xhToken, LPCSTR lpszFuncName, ENUM_NETHELP_XRPC_PARAMETE_TYPE enRtnType, NETHELP_XRPCPARAMETE * **pppSt_ListParamete, int nListCount, NETHELP_XRPCPARAMETE* pSt_XRPCParamete = NULL);
/*********************************************************************************
*                          XRPC服务导出的函数                                    *
*********************************************************************************/
/********************************************************************
函数名称：NetHelp_XRPCCore_Init
函数功能：吃石化XRPC服务
 参数.一：nStreamPort
  In/Out：In
  类型：整数型
  可空：N
  意思：输入XENGINE协议通信端口
 参数.二：nThreads
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入内部业务线程处理数量
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCCore_Init(int nStreamPort, int nThreads = 4);
/********************************************************************
函数名称：NetHelp_XRPCCore_SetCallback
函数功能：设置回调函数
 参数.一：fpCall_FuncCall
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：设置回调函数地址,用于告诉上层有函数调用被触发
 参数.二：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：输入回调函数参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCCore_SetCallback(CALLBACK_NETENGINE_NETHELP_XRPC_CORE_FUNCCALL fpCall_FuncCall, LPVOID lParam = NULL);
/********************************************************************
函数名称：NetHelp_XRPCCore_SendMsg
函数功能：发送数据给指定客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送给哪个客户端
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要发送的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要发送的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCCore_SendMsg(LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：NetHelp_XRPCCore_Destory
函数功能：销毁XRPC服务
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCCore_Destory();
/********************************************************************
函数名称：NetHelp_XRPCCore_CloseClient
函数功能：关闭一个指定客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要关闭的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCCore_CloseClient(LPCSTR lpszClientAddr);
/*********************************************************************************
*                          XRPC帮助导出的函数                                    *
*********************************************************************************/
/********************************************************************
函数名称：NetHelp_XRPCHelp_Malloc
函数功能：初始化容器内部VALUE内存
 参数.一：pppSt_ListParamete
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出申请好初始化的列表
 参数.二：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要申请的个数
 参数.三：nSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入每个元素大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetHelp_XRPCHelp_Malloc(NETHELP_XRPCPARAMETE * **pppSt_ListParamete, int nCount, int nSize = 1024);
/********************************************************************
函数名称：NetHelp_XRPCHelp_Free
函数功能：释放容器中的VALUE元素内存
 参数.一：pppSt_ListParamete
  In/Out：In
  类型：三级指针
  可空：N
  意思：要释放的容器
 参数.二：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：要释放的列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：只支持释放malloc的内存释放
*********************************************************************/
extern "C" BOOL NetHelp_XRPCHelp_Free(NETHELP_XRPCPARAMETE * **pppSt_ListParamete, int nListCount);
