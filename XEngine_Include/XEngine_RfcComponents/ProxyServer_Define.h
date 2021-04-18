#pragma once
/********************************************************************
//	Created:	2012/10/11  21:43
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_ProxyServer\RfcProxyServer_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_ProxyServer
//	File Base:	RfcProxyServer_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	代理服务器导出函数
//	History:
*********************************************************************/
typedef enum en_RfcComponents_ProxySocks_CBUser
{
    ENUM_RFCCOMPONENTS_PROXYSOCKS_CBUSER_TYPE_ANON_LOGIN = 1,         //有用户匿名登录
    ENUM_RFCCOMPONENTS_PROXYSOCKS_CBUSER_TYPE_NAMED_LOGIN = 2,        //有用户命名登录
    ENUM_RFCCOMPONENTS_PROXYSOCKS_CBUSER_TYPE_ANON_LEAVE = 3,         //有匿名用户离开
    ENUM_RFCCOMPONENTS_PROXYSOCKS_CBUSER_TYPE_NAMED_LEAVE = 4         //有命名用户离开
}ENUM_RFCCOMPONENTS_PROXYSOCKS_CBUSERTYPE;
//////////////////////////////////////////////////////////////////////
//                      回调函数定义
//////////////////////////////////////////////////////////////////////
//隧道协议回调函数，参数：客户端地址，数据，数据长度，是否是HTTP服务器发过来的数据，不要在回调函数里面处理数据，否则会影响转发效率
typedef void(CALLBACK *CALLBACK_NETENGINE_RFC_PROXY_TUNNEL_RECV)(LPCSTR lpszClientAddr,LPCSTR lpszMsgBuffer,int nMsgLen,BOOL bIsHttp,LPVOID lParam);
//RFCSOCKS5代理服务回调函数-用户登录处理函数,用户地址:用户名:密码,返回真表示允许登录,返回假表示不允许登录 lpszUserName和lpszUserPass等于NULL,表示
typedef BOOL(CALLBACK *CALLBACK_RFCCOMPONENTS_PROXYSOCKS_USER)(LPCSTR lpszClientAddr, LPCSTR lpszUserName, LPCSTR lpszUserPass, ENUM_RFCCOMPONENTS_PROXYSOCKS_CBUSERTYPE enStatus, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" BOOL ProxyServer_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     SOCK代理服务器导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_ProxySocks_Start
函数功能：启动SOCKS代理服务器
 参数.一：fpCall_SocksUser
  In/Out：In
  类型：回调函数
  可空：Y
  意思：是否设置用户密码验证,这个需要你自己处理用户登录情况,为NULL将设置匿名登录
 参数.二：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：用户验证回调函数参数
 参数.三：bIsAuth
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否启用登录验证,默认不启用
 参数.一：u_sLisPort
  In/Out：In
  类型：短整数型
  可空：Y
  意思：监听的端口，默认为1080
返回值
  类型：逻辑型
  意思：是否成功启动代理服务器
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_ProxySocks_Start(CALLBACK_RFCCOMPONENTS_PROXYSOCKS_USER fpCall_SocksUser, LPVOID lParam = NULL, BOOL bIsAuth = FALSE, u_short u_sLisPort = 1080);
/********************************************************************
函数名称：RfcComponents_ProxySocks_Stop
函数功能：停止代理服务器并且销毁资源
返回值
  类型：逻辑型
  意思：是否停止成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_ProxySocks_Stop();
/********************************************************************
函数名称：RfcComponents_ProxySocks_CloseClient
函数功能：关闭一个指定的客户端地址
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要关闭的客户端,通过回调函数第一个参数返回的地址
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_ProxySocks_CloseClient(LPCSTR lpszClientAddr);
/************************************************************************/
/*                     隧道代理服务错误                                    */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_ProxyTunnel_Start
函数功能：启动隧道代理服务器
 参数.一：nPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：要绑定的端口地址
 参数.二：pppSt_ListUser
  In/Out：In
  类型：三级指针
  可空：Y
  意思：用户名密码列表，格式 123123:abc，然后BASE64编码传递进来
        此参数内存由用户管理
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入用户密码列表个数
 参数.四：fpCall_TunnelRecv
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：接收到数据所触发的回调函数
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：接收数据回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功启动代理服务器
备注：隧道代理服务器模式需要HTTP1.1以后的版本支持，也支持其他支持隧道代理的客户端
     未来将支持控制转发数据选项
*********************************************************************/
extern "C" BOOL RfcComponents_ProxyTunnel_Start(int nPort = 10081, CHAR * **pppSt_ListUser = NULL, int nListCount = 0, CALLBACK_NETENGINE_RFC_PROXY_TUNNEL_RECV fpCall_TunnelRecv = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：RfcComponents_ProxyTunnel_Stop
函数功能：停止代理服务器并且销毁资源
返回值
  类型：逻辑型
  意思：是否停止成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_ProxyTunnel_Stop();
