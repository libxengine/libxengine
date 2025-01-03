﻿#pragma once
/********************************************************************
//    Created:     2024/10/28  14:55:28
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Core\XEngine_Cryption\Cryption_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Core\XEngine_Cryption
//    File Base:   Cryption_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     加解密秘钥算法库导出错误
//    History:
*********************************************************************/
/************************************************************************/
/*         OPENSSL API导出函数                                          */
/************************************************************************/
#define ERROR_XENGINE_CRYPTION_API_PARAMENT 0x20D0000             //参数错误
#define ERROR_XENGINE_CRYPTION_API_GENKEY 0x20D0001               //生成KEY错误
#define ERROR_XENGINE_CRYPTION_API_SETWORD 0x20D0002              //设置加密模式失败
#define ERROR_XENGINE_CRYPTION_API_CREATE 0x20D0003               //创建RSA失败
#define ERROR_XENGINE_CRYPTION_API_WRITE 0x20D0004                //写入文件失败
#define ERROR_XENGINE_CRYPTION_API_OPENKEY 0x20D0005              //打开文件失败
#define ERROR_XENGINE_CRYPTION_API_READKEY 0x20D0006              //读取密钥失败
#define ERROR_XENGINE_CRYPTION_API_READINFO 0x20D0007             //读取密钥信息失败
#define ERROR_XENGINE_CRYPTION_API_INIT 0x20D0008                 //初始化加解密库失败
#define ERROR_XENGINE_CRYPTION_API_ENCODEC 0x20D0009              //加密失败
#define ERROR_XENGINE_CRYPTION_API_DECODEC 0x20D0010              //解密失败
#define ERROR_XENGINE_CRYPTION_API_NOTSUPPORT 0x20D0011           //不支持
#define ERROR_XENGINE_CRYPTION_API_UPDATE 0x20D0012               //更新加解密数据失败
#define ERROR_XENGINE_CRYPTION_API_FINAL 0x20D0013                //完成加解密数据失败
#define ERROR_XENGINE_CRYPTION_API_OPENFILE 0x20D0014             //打开文件失败
/************************************************************************/
/*         证书与签名错误导出                                           */
/************************************************************************/
//数字签名错误导出
#define ERROR_XENGINE_CRYPTION_CERT_SIGN_PARAMENT 0x20D1000              //签名错误，参数错误
#define ERROR_XENGINE_CRYPTION_CERT_SIGN_OPENFILE 0x20D1001              //打开文件失败
#define ERROR_XENGINE_CRYPTION_CERT_SIGN_READKEY 0x20D1002               //读取KEY失败
#define ERROR_XENGINE_CRYPTION_CERT_SIGN_INIT 0x20D1003                  //初始化失败
#define ERROR_XENGINE_CRYPTION_CERT_SIGN_UPDATE 0x20D1004                //更新签名失败
#define ERROR_XENGINE_CRYPTION_CERT_SIGN_FAILED 0x20D1005                //完整签名失败
#define ERROR_XENGINE_CRYPTION_CERT_VERIFY_PARAMENT 0x20D1010            //参数错误
#define ERROR_XENGINE_CRYPTION_CERT_VERIFY_OPENFILE 0x20D1011            //验证失败,打开文件失败
#define ERROR_XENGINE_CRYPTION_CERT_VERIFY_READKEY 0x20D1012             //读取CDKEY信息失败
#define ERROR_XENGINE_CRYPTION_CERT_VERIFY_INIT 0x20D1013                //初始化验证系统失败
#define ERROR_XENGINE_CRYPTION_CERT_VERIFY_UPDATE 0x20D1014              //更新验证失败
#define ERROR_XENGINE_CRYPTION_CERT_VERIFY_FAILED 0x20D1015              //验证失败,不是相同数据
//生成证书
#define ERROR_XENGINE_CRYPTION_CERT_MAKECACERT_PARAMENT 0x20D1020        //参数错误生成根证书失败
#define ERROR_XENGINE_CRYPTION_CERT_MAKECACERT_OPENFILE 0x20D1021        //打开密钥失败
#define ERROR_XENGINE_CRYPTION_CERT_MAKECACERT_READKEY 0x20D1022         //读取密钥失败
#define ERROR_XENGINE_CRYPTION_CERT_MAKECACERT_SETKEY 0x20D1023          //关联密钥失败
#define ERROR_XENGINE_CRYPTION_CERT_MAKECACERT_SIGN 0x20D1024            //签名失败
#define ERROR_XENGINE_CRYPTION_CERT_MAKECACERT_WRITECERT 0x20D1025       //写入证书文件失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_PARAMENT 0x20D1030              //参数错误
#define ERROR_XENGINE_CRYPTION_CERT_X509_MALLOC 0x20D1031                //申请内存失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_OPENKEY 0x20D1032               //打开私钥
#define ERROR_XENGINE_CRYPTION_CERT_X509_READKEY 0x20D1033               //读取数据失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_SETKEY 0x20D1034                //设置关联失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_SIGN 0x20D1035                  //签名失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_VER 0x20D1036                   //验证失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_OPENREQ 0x20D1037               //打开请求文件失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_READREQ 0x20D1038               //读取请求文件失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_VERKEY 0x20D1039                //验证请求文件KEY失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_SAVE 0x20D103A                  //保存证书失败
//X509证书验证
#define ERROR_XENGINE_CRYPTION_CERT_X509_OPENROOT 0x20D1200              //打开验证证书失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_OPENUSER 0x20D1201              //打开用户证书失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_ROOTCVT 0x20D1202               //转换根证书失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_USERCVT 0x20D1203               //转换用户证书失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_NEWROOT 0x20D1204               //新建根证书内存存储位置失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_ADD 0x20D1205                   //将根证书添加到存储位置失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_CAINIT 0x20D1206                //初始化证书失败
#define ERROR_XENGINE_CRYPTION_CERT_X509_VERIFY 0x20D1207                //证书已经过期或者验证失败
//签名验证加解密算法
#define ERROR_XENGINE_CRYPTION_CERT_DISEST_MALLOC 0x20D1301              //申请内存失败
#define ERROR_XENGINE_CRYPTION_CERT_DISEST_OPEN 0x20D1302                //打开密钥失败
#define ERROR_XENGINE_CRYPTION_CERT_DISEST_GETRSA 0x20D1302              //获取密钥算法失败
#define ERROR_XENGINE_CRYPTION_CERT_DISEST_NOTSUPPORT 0x20D1302          //不支持的算法
#define ERROR_XENGINE_CRYPTION_CERT_DISEST_ISFAILED 0x20D1303            //加解密失败,无法继续

#define ERROR_XENGINE_CRYPTION_CERT_CONVERT_PARAMENT 0x20D1401            //参数错误
#define ERROR_XENGINE_CRYPTION_CERT_CONVERT_READ 0x20D1402                //读取失败
#define ERROR_XENGINE_CRYPTION_CERT_CONVERT_X509 0x20D1403                //解码失败
#define ERROR_XENGINE_CRYPTION_CERT_CONVERT_WRITE 0x20D1404               //写入失败
#define ERROR_XENGINE_CRYPTION_CERT_CONVERT_FAILED 0x20D1405              //转换失败
/************************************************************************/
/*           SSL安全传输库导出错误列表                                  */
/************************************************************************/
#define ERROR_XENGINE_CRYPTION_SERVER_PARAMENT 0x20D2000                   //参数错误
#define ERROR_XENGINE_CRYPTION_SERVER_NOTSUPPORT 0x20D2001                 //不支持的选项
#define ERROR_XENGINE_CRYPTION_SERVER_NEWCTX 0x20D2002                     //申请上下文加解密器失败
#define ERROR_XENGINE_CRYPTION_SERVER_SETSERVERCERT 0x20D2003              //设置服务器证书失败
#define ERROR_XENGINE_CRYPTION_SERVER_SETSRVPRIVATE 0x20D2004              //设置服务端私钥失败
#define ERROR_XENGINE_CRYPTION_SERVER_CHECKPRIVATEKEY 0x20D2005            //服务端私钥与证书不匹配，无法继续
#define ERROR_XENGINE_CRYPTION_SERVER_ISFAILED 0x20D2006                   //接受连接失败,内部错误
#define ERROR_XENGINE_CRYPTION_SERVER_MALLOC 0x20D2007                     //申请内存失败
#define ERROR_XENGINE_CRYPTION_SERVER_MAP 0x20D2008                        //关联设置失败
#define ERROR_XENGINE_CRYPTION_SERVER_NOTFOUND 0x20D2009                   //接受数据失败,没有找到客户端
#define ERROR_XENGINE_CRYPTION_SERVER_MORE 0x20D2010                       //处理失败,需要更多数据
#define ERROR_XENGINE_CRYPTION_SERVER_NOTDATA 0x20D2011                    //没有数据了
#define ERROR_XENGINE_CRYPTION_SERVER_LEN 0x20D2012                        //提供的大小不正确
/************************************************************************/
/*           编解码器导出错误列表                                       */
/************************************************************************/
#define ERROR_XENGINE_CRYPTION_API_CODEC_BASE64_PARAMENT 0x20D3000      //参数错误，有NULL参数
#define ERROR_XENGINE_CRYPTION_API_CODEC_BASE64_NEWBIO 0x20D3001        //申请新的算法空间失败
#define ERROR_XENGINE_CRYPTION_API_CODEC_BASE64_NEWMEM 0x20D3002        //申请内存失败
#define ERROR_XENGINE_CRYPTION_API_CODEC_BASE64_BIOPUSH 0x20D3003       //把数据压入空间失败
#define ERROR_XENGINE_CRYPTION_API_CODEC_BASE64_BIOWRITE 0x20D3004      //写入空间失败
#define ERROR_XENGINE_CRYPTION_API_CODEC_BASE64_BIOFLUSH 0x20D3005      //刷新失败
/************************************************************************/
/*           X加解密导出错误列表                                        */
/************************************************************************/
#define ERROR_XENGINE_CRYPTION_XCRYPTO_ENCODER_PARAMENT 0x20D4001        //参数错误
#define ERROR_XENGINE_CRYPTION_XCRYPTO_DECODER_PARAMENT 0x20D4010        //参数错误
#define ERROR_XENGINE_CRYPTION_XCRYPTO_DECODER_HDR 0x20D4011             //加密头不正确,不是X加解密
#define ERROR_XENGINE_CRYPTION_XCRYPTO_DECODER_TYPE 0x20D4012            //加解密类型不匹配
#define ERROR_XENGINE_CRYPTION_XCRYPTO_DECODER_CHECK 0x20D4013           //校验码验证失败,无法继续
/************************************************************************/
/*           加解密帮助函数错误码                                       */
/************************************************************************/
#define ERROR_XENGINE_CRYPTION_HELP_BASICENCODER_PARAMENT 0x20D5000       //参数错误
#define ERROR_XENGINE_CRYPTION_HELP_BASICDECODER_PARAMENT 0x20D5010       //参数错误
#define ERROR_XENGINE_CRYPTION_HELP_BASICDECODER_FORMAT 0x20D5011         //格式错误
/************************************************************************/
/*           SSL客户端导出错误                                          */
/************************************************************************/
#define ERROR_XENGINE_CRYPTION_CLIENT_NOTSUPPORT 0x20D5000               //不支持的类型
#define ERROR_XENGINE_CRYPTION_CLIENT_CACERTLOAD 0x20D5001               //证书加载失败
#define ERROR_XENGINE_CRYPTION_CLIENT_CERTFILELOAD 0x20D5002             //证书文件错误
#define ERROR_XENGINE_CRYPTION_CLIENT_KEYFILELOAD 0x20D5003              //秘钥错误
#define ERROR_XENGINE_CRYPTION_CLIENT_NOTMATCH 0x20D5004                 //不匹配的证书
#define ERROR_XENGINE_CRYPTION_CLIENT_FAILED 0x20D5005                   //操作失败
#define ERROR_XENGINE_CRYPTION_CLIENT_PARAMENT 0x20D5006                 //参数错误
#define ERROR_XENGINE_CRYPTION_CLIENT_CREATESSL 0x20D5007                //新建SSL失败
#define ERROR_XENGINE_CRYPTION_CLIENT_SETMAP 0x20D5008                   //关联失败
#define ERROR_XENGINE_CRYPTION_CLIENT_SSLCONNECT 0x20D5009               //连接失败
#define ERROR_XENGINE_CRYPTION_CLIENT_GETSUBJECT 0x20D5010               //获取内容失败
#define ERROR_XENGINE_CRYPTION_CLIENT_GETISSUER 0x20D5011                //获取内容失败
#define ERROR_XENGINE_CRYPTION_CLIENT_GETALGORITHM 0x20D5012             //获取算法失败
#define ERROR_XENGINE_CRYPTION_CLIENT_WRITE 0x20D5013                    //写入数据失败
#define ERROR_XENGINE_CRYPTION_CLIENT_MALLOC 0x20D5014                   //申请内存失败
#define ERROR_XENGINE_CRYPTION_CLIENT_CLOSE 0x20D5015                    //连接关闭
#define ERROR_XENGINE_CRYPTION_CLIENT_NOTFOUND 0x20D5016                 //没有找到