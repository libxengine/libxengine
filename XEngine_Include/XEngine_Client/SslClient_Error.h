#pragma once
/********************************************************************
//    Created:     2024/02/21  14:11:05
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_OPenSsl\SslClient_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Client\XClient_OPenSsl
//    File Base:   SslClient_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     安全加解密支持客户端模块错误定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     SSL客户端操作处理导出错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_PARAMENT 0x30B0000         //参数错误
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_NOTSUPPORT 0x30B0001       //不支持
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_CACERTLOAD 0x30B0002       //加载CA签名证书失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_CERTFILELOAD 0x30B0003     //加载自己的证书失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_KEYFILELOAD 0x30B0004      //加载密钥失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_NOTMATCH 0x30B0005         //证书和密钥不匹配，无法继续
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_CREATESSL 0x30B0006        //新建SSL失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_SETMAP 0x30B0007           //设置关联句柄失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_SSLCONNECT 0x30B0008       //打开SSL安全连接通道失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_GETSUBJECT 0x30B0009       //获取服务器证书拥有者信息失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_GETISSUER 0x30B0010        //获取服务器证书颁发者信息失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_GETALGORITHM 0x30B0011     //获取服务器使用的加密算法失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_MALLOC 0x30B0012           //申请内存失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_WRITE 0x30B0013            //发送数据失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_FAILED 0x30B0014           //接受数据失败
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_CLOSE 0x30B0015            //服务器关闭
#define ERROR_XENGINE_XCLIENT_SSLCLIENT_OPENSSL_NOTFOUND 0x30B0016         //没有找到指定句柄