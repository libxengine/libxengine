#pragma once
/********************************************************************
//    Created:     2024/02/21  14:10:59
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_OPenSsl\SslClient_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_OPenSsl
//    File Base:   SslClient_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     客户端安全管理模块，导出定义
//    History:
*********************************************************************/
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
    XCHAR tszAlgorithm[64];                                                //服务端使用的加密算法
    XCHAR tszSubject[MAX_PATH];                                            //服务端的证书拥有者信息
    XCHAR tszIssuer[MAX_PATH];                                             //服务端的证书颁发者信息
}XCLIENT_SSLCERT_SRVINFO,*LPXCLIENT_SSLCERT_SRVINFO;
//////////////////////////////////////////////////////////////////////////
//                    函数导出定义
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG XClientSsl_GetLastError(int *pInt_ErrorCode = NULL);
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
 参数.二：bSSocket
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：使用系统套接字收发数据还是由你来调用函数收发数据
 参数.三：lpszCACertFile
  In/Out：In
  类型：整数型
  可空：Y
  意思：CA证书文件路径
 参数.四：lpszCertFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：客户端证书文件路径
 参数.五：lpszPrivateKey
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：客户端秘钥文件路径
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：证书文件三个参数要么全部为NULL,要么参数lpszCertFile为NULL那么参数一就是使用证书链
*********************************************************************/
extern "C" XHANDLE XClient_OPenSsl_InitEx(ENUM_XCLIENT_SSL_TYPE enSslProtocol = ENUM_XCLIENT_SSL_TYPE_SSL_VERSION, bool bSSocket = true, LPCXSTR lpszCACertFile = NULL, LPCXSTR lpszCertFile = NULL, LPCXSTR lpszPrivateKey = NULL);
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
extern "C" bool XClient_OPenSsl_ConnectEx(XHANDLE xhNet, XSOCKET hSocket, XCLIENT_SSLCERT_SRVINFO *pSt_SslInfo);
/********************************************************************
函数名称：XClient_OPenSsl_SendMsg
函数功能：SSL安全发送数据
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要发送的缓冲区数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入发送的长度
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出要发送的加密后的数据,如果使用自定义收发套接字
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出发送加密数据缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：最后两个参数可以参考服务器的函数说明,如果你是异步套接字,可能需要自定义收发数据套接字
      而不是由系统来处理收发
*********************************************************************/
extern "C" bool XClient_OPenSsl_SendMsgEx(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nLen, XCHAR * ptszMsgBuffer = NULL, int* pInt_MsgLen = NULL);
/********************************************************************
函数名称：XClient_OPenSsl_SendMemory
函数功能：发送数据到加密内存中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要加密的数据
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入数据大小
 参数.三：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：输出加密后的数据
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XClient_OPenSsl_SendMemoryEx(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nMsgLen, XCHAR** pptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：XClient_OPenSsl_RecvMsg
函数功能：读取SSL数据
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出接受到的数据
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入缓冲区大小,输出接受到的大小
 参数.三：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入你套接字接受的数据缓冲区,如果你使用自定义收发数据套接字模式
 参数.四：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入收到的数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XClient_OPenSsl_RecvMsgEx(XHANDLE xhNet, XCHAR *ptszMsgBuffer, int *pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：XClient_OPenSsl_RecvMemory
函数功能：读取数据到一段新的内存中
 参数.一：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：导出接受到的数据,这个数据需要释放内存
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出接受到的大小
 参数.三：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入你套接字接受的数据缓冲区,如果你使用自定义收发数据套接字模式
 参数.四：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入收到的数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool XClient_OPenSsl_RecvMemoryEx(XHANDLE xhNet, XCHAR** pptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/************************************************************************
函数名称：XClient_OPenSsl_Close
函数功能：关闭SSL客户端
返回值
  类型：逻辑型
  意思：是否成功关闭客户端
备注：
************************************************************************/
extern "C" bool XClient_OPenSsl_CloseEx(XHANDLE xhNet);