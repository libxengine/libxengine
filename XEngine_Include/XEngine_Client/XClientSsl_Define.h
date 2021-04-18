#pragma once
/********************************************************************
//    Created:     2021/04/04  15:23:57
//    File Name:   H:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_OPenSsl\XClientSsl_Define.h
//    File Path:   H:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_OPenSsl
//    File Base:   XClientSsl_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     客户端安全管理模块，导出定义
//    History:
*********************************************************************/
//VPN状态信息
typedef enum en_NetClient_VPNStatus
{
	ENUM_XCLIENT_VPNStatus_OpenPort = 0,
	ENUM_XCLIENT_VPNStatus_PortOpened,
	ENUM_XCLIENT_VPNStatus_ConnectDevice,
	ENUM_XCLIENT_VPNStatus_DeviceConnected,
	ENUM_XCLIENT_VPNStatus_AllDevicesConnected,
	ENUM_XCLIENT_VPNStatus_Authenticate,
	ENUM_XCLIENT_VPNStatus_AuthNotify,
	ENUM_XCLIENT_VPNStatus_AuthRetry,
	ENUM_XCLIENT_VPNStatus_AuthCallback,
	ENUM_XCLIENT_VPNStatus_AuthChangePassword,
	ENUM_XCLIENT_VPNStatus_AuthProject,
	ENUM_XCLIENT_VPNStatus_AuthLinkSpeed,
	ENUM_XCLIENT_VPNStatus_AuthAck,
	ENUM_XCLIENT_VPNStatus_ReAuthenticate,
	ENUM_XCLIENT_VPNStatus_Authenticated,
	ENUM_XCLIENT_VPNStatus_PrepareForCallback,
	ENUM_XCLIENT_VPNStatus_WaitForModemReset,
	ENUM_XCLIENT_VPNStatus_WaitForCallback,
	ENUM_XCLIENT_VPNStatus_Projected,
	ENUM_XCLIENT_VPNStatus_StartAuthentication,
	ENUM_XCLIENT_VPNStatus_CallbackComplete,
	ENUM_XCLIENT_VPNStatus_LogonNetwork,
	ENUM_XCLIENT_VPNStatus_SubEntryConnected,
	ENUM_XCLIENT_VPNStatus_SubEntryDisconnected,
	ENUM_XCLIENT_VPNStatus_ApplySettings,
	ENUM_XCLIENT_VPNStatus_Interactive = 0x1000,
	ENUM_XCLIENT_VPNStatus_RetryAuthentication,
	ENUM_XCLIENT_VPNStatus_CallbackSetByCaller,
	ENUM_XCLIENT_VPNStatus_PasswordExpired,
	ENUM_XCLIENT_VPNStatus_InvokeEapUI,
	ENUM_XCLIENT_VPNStatus_Connected = 0x2000,
	ENUM_XCLIENT_VPNStatus_Disconnected
}ENUM_NETCLIENT_VPNSTATUS;
//////////////////////////////////////////////////////////////////////////
//               数据类型导出定义
//////////////////////////////////////////////////////////////////////////
//SSL证书文件证书编码类型。调用者无需关心编码实现部分，只需要传递即可
#define XCLIENT_SSL_CERT_CODEC_PEM_FILE 1                                //PEM编码格式：BASE64
#define XCLIENT_SSL_CERT_CODEC_ASN1_FILE 2                               //ASN1编码格式：DER
//////////////////////////////////////////////////////////////////////////
//               数据结构导出定义
//////////////////////////////////////////////////////////////////////////
//SSL安全传输协议库,用于客户端
typedef enum 
{
    ENUM_XCLIENT_SSL_TYPE_SSL_VERSION = 1,                                   //同时支持SSL V2和V3版本的协议
    ENUM_XCLIENT_SSL_TYPE_TLS_VERSION,                                   //TLS协议
    ENUM_XCLIENT_SSL_TYPE_DTL_VERSION                                    //DTL协议
}ENUM_XCLIENT_SSL_TYPE,*LPENUM_XCLIENT_SSL_TYPE;
//服务器SSL信息
typedef struct 
{
    CHAR tszAlgorithm[64];                                                //服务端使用的加密算法
    CHAR tszSubject[MAX_PATH];                                            //服务端的证书拥有者信息
    CHAR tszIssuer[MAX_PATH];                                             //服务端的证书颁发者信息
}XCLIENT_SSLCERT_SRVINFO,*LPXCLIENT_SSLCERT_SRVINFO;
//VPN连接客户端结构参数
typedef struct 
{
	CHAR tszDescription[256];                                             //VPN描述
	CHAR tszServer[128];                                                  //服务器地址
	CHAR tszUserName[256];                                                //用户名
	CHAR tszPassword[256];                                                //密码
	CHAR tszDomain[16];                                                   //域
}XCLIENT_VPNPARAM, * LPXCLIENT_VPNPARAM;
//////////////////////////////////////////////////////////////////////////
//                    函数导出定义
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD XClientSsl_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                 VPN客户端操作函数                                    */
/************************************************************************/
#ifdef _WINDOWS
/********************************************************************
函数名称：XClient_VPN_Connect
函数功能：VPN连接函数
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出创建的VPN句柄
 参数.二：pSt_VPNParams
  In/Out：In
  类型：结构体指针
  可空：N
  意思：输入VPN的连接信息
返回值
  类型：逻辑型
  意思：是否连接成功
备注：
*********************************************************************/
extern "C" BOOL XClient_VPN_Connect(XNETHANDLE * pxhNet, XCLIENT_VPNPARAM * pSt_VPNParams);
/********************************************************************
函数名称：XClient_VPN_GetStatus
函数功能：查询一个VPN的状态
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要查询的VPN客户端句柄
 参数.二：pdwStatus
  In/Out：Out
  类型：双字
  可空：N
  意思：导出查询到的状态
返回值
  类型：逻辑型
  意思：是否查询成功
备注：
*********************************************************************/
extern "C" BOOL XClient_VPN_GetStatus(XNETHANDLE xhNet, DWORD * pdwStatus);
/********************************************************************
函数名称：XClient_VPN_Close
函数功能：关闭VPN连接
参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：VPN的句柄
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL XClient_VPN_Close(XNETHANDLE xhNet);
#endif
/************************************************************************/
/*                 SSL安全通信函数导出定义                              */
/************************************************************************/
/********************************************************************
函数名称：XClient_OPenSsl_Init
函数功能：初始化SSL连接属性
 参数.一：enSslProtocol
  In/Out：In
  类型：枚举型
  可空：Y
  意思：客户端要采用的密钥算法，默认为SSLV2和V3兼容版本
 参数.二：lpszCACertFile
  In/Out：In
  类型：整数型
  可空：Y
  意思：CA证书文件路径
 参数.三：lpszCertFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：客户端证书文件路径
 参数.四：lpszPrivateKey
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：客户端秘钥文件路径
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：证书文件三个参数要么全部为NULL,要么全部不为NULL,证书文件全为空也可以
      与我们的SSL服务器交换数据
*********************************************************************/
extern "C" BOOL XClient_OPenSsl_InitEx(XNETHANDLE *pxhNet, ENUM_XCLIENT_SSL_TYPE enSslProtocol = ENUM_XCLIENT_SSL_TYPE_SSL_VERSION, LPCSTR lpszCACertFile = NULL, LPCSTR lpszCertFile = NULL, LPCSTR lpszPrivateKey = NULL);
/********************************************************************
函数名称：XClient_OPenSsl_Connect
函数功能：连接到SSL服务
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：输入你已经创建好连接的套接字句柄
 参数.二：pSt_SslInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出获取到的服务器SSL证书信息
返回值
  类型：逻辑型
  意思：是否成功
备注：网络事件你需要自己处理
*********************************************************************/
extern "C" BOOL XClient_OPenSsl_ConnectEx(XNETHANDLE xhNet, SOCKET hSocket, XCLIENT_SSLCERT_SRVINFO *pSt_SslInfo);
/************************************************************************
函数名称：XClient_OPenSsl_Close
函数功能：关闭SSL客户端
返回值
  类型：逻辑型
  意思：是否成功关闭客户端
备注：
************************************************************************/
extern "C" BOOL XClient_OPenSsl_CloseEx(XNETHANDLE xhNet);
/************************************************************************
函数名称：XClient_OPenSsl_SendMsg
函数功能：SSL安全发送数据
  参数一：lpszMsgBuffer
   In/Out：In
   类型：字符指针
   可空：N
   意思：要发送的缓冲区数据
  参数二：pInt_Len
   In/Out：In/Out
   类型：整数型指针
   可空：N
   意思：输入发送的长度,输出发送成功的长度
返回值
  类型：逻辑型
  意思：是否成功发送
备注：你可以自己处理你的SOCKET句柄事件,当有事件可发(可接受)的时候,在调用此函数发送数据
      所以,你不能调用你的send函数来发送数据,只能通过此函数来发送,同样的,接受数据也是一样的
************************************************************************/
extern "C" BOOL XClient_OPenSsl_RecvMsgEx(XNETHANDLE xhNet, CHAR *ptszMsgBuffer, int *pInt_MsgLen);
/********************************************************************
函数名称：XClient_OPenSsl_RecvMsg
函数功能：读取SSL数据
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：导出接受到的数据
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入缓冲区大小,输出接受到的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：读取出来的数据是解密后的明文数据
*********************************************************************/
extern "C" BOOL XClient_OPenSsl_SendMsgEx(XNETHANDLE xhNet, LPCSTR lpszMsgBuffer, int nLen);
