#pragma once
/********************************************************************
//	Created:	2011/7/18  14:29
//	Filename: 	j:\U_DISK_Path\NetSocketEngine\CryptOpenSSL\OpenSSL_ErrorDefine.h
//	File Path:	j:\U_DISK_Path\NetSocketEngine\CryptOpenSSL
//	File Base:	OpenSSL_ErrorDefine
//	File Ext:	h
//  Project:    NetSocketEnginer(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	算法加解密组件错误导出定义
//	History:
*********************************************************************/
/************************************************************************/
/*         OPENSSL API导出函数                                          */
/************************************************************************/
//非对称加解密导出错误定义
#define ERROR_XENGINE_OPENSSL_API_CRYPT_ENCODEC_PARAMENT 0x10D0000  //参数错误
#define ERROR_XENGINE_OPENSSL_API_CRYPT_ENCODEC_NOTSUPPORT 0x10D0001//不支持的加解密方式
#define ERROR_XENGINE_OPENSSL_API_CRYPT_ENCODEC_MALLOC 0x10D0002    //申请空间失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_ENCODEC_INITCTX 0x10D0003   //初始化3DES算法容器失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_ENCODEC_UPDATE 0x10D0004    //更新3DES算法容器内的数据失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_ENCODEC_FINAL 0x10D0005     //完成3DES算法容器失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_DECODEC_PARAMENT 0x10D0011  //解密失败，参数错误
#define ERROR_XENGINE_OPENSSL_API_CRYPT_DECODEC_NOTSUPPORT 0x10D0012//不支持的解密方式
#define ERROR_XENGINE_OPENSSL_API_CRYPT_DECODEC_MALLOC 0x10D0013 //申请内存失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_DECODEC_INIT 0x10D0014   //初始化失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_DECODEC_UPDATE 0x10D0015 //更新解密数据失败
#define ERROR_XENGINE_OPENSSL_API_CRYPT_DECODEC_FINAL 0x10D0016  //完成解密失败
//消息摘要错误
#define ERROR_XENGINE_OPENSSL_API_DIGEST_PARAMENT 0x10D0020      //参数错误
#define ERROR_XENGINE_OPENSSL_API_DIGEST_INITMD 0x10D0021        //初始化消息摘要加密库失败
#define ERROR_XENGINE_OPENSSL_API_DIGEST_NOTFOUNDMD 0x10D0022    //没有找到加密库
#define ERROR_XENGINE_OPENSSL_API_DIGEST_UPDATE 0x10D0023        //更新待加密数据失败
#define ERROR_XENGINE_OPENSSL_API_DIGEST_FINAL 0x10D0024         //完成加密数据失败
#define ERROR_XENGINE_OPENSSL_API_DIGEST_OPENFILE 0x10D0025      //打开文件失败
//////////////////////////////////////////////////////////////////////////RSA
#define ERROR_XENGINE_OPENSSL_API_RSA_GENPARAMENT 0x10D0080      //参数错误
#define ERROR_XENGINE_OPENSSL_API_RSA_OPENKEY 0x10D0081          //打开文件失败
#define ERROR_XENGINE_OPENSSL_API_RSA_OPENPRIKEY 0x10D0082       //打开私钥文件句柄失败
#define ERROR_XENGINE_OPENSSL_API_RSA_READINFO 0x10D0083         //读取密钥信息失败
#define ERROR_XENGINE_OPENSSL_API_RSA_GENKEY 0x10D0084           //生成KEY错误
#define ERROR_XENGINE_OPENSSL_API_RSA_GENPRINEW 0x10D0085        //申请私钥空间失败
#define ERROR_XENGINE_OPENSSL_API_RSA_SETWORD 0x10D0086          //设置加密模式失败
#define ERROR_XENGINE_OPENSSL_API_RSA_GENPRIWRITE 0x10D0087      //写入私钥文件失败
#define ERROR_XENGINE_OPENSSL_API_RSA_GENPUBNEW 0x10D0088        //申请公钥空间失败
#define ERROR_XENGINE_OPENSSL_API_RSA_GENPUBWRITE 0x10D0089      //写入公钥文件失败
#define ERROR_XENGINE_OPENSSL_API_RSA_EN_PARAMENT 0x10D0090      //参数错误，无法继续
#define ERROR_XENGINE_OPENSSL_API_RSA_EN_OPENKEY 0x10D0091       //打开文件失败
#define ERROR_XENGINE_OPENSSL_API_RSA_EN_READKEY 0x10D0093       //读取KEY失败，可能不是正常的密钥文件
#define ERROR_XENGINE_OPENSSL_API_RSA_EN_MALLOC 0x10D0094        //申请空间失败
#define ERROR_XENGINE_OPENSSL_API_RSA_EN_CODEC 0x10D0095         //加密失败
#define ERROR_XENGINE_OPENSSL_API_RSA_DE_PARAMENT 0x10D00A0      //解密失败参数错误，无法继续
#define ERROR_XENGINE_OPENSSL_API_RSA_DE_OPENKEY 0x10D00A1       //打开文件失败
#define ERROR_XENGINE_OPENSSL_API_RSA_DE_READKEY 0x10D00A3       //读取KEY失败，可能不是正常的密钥文件
#define ERROR_XENGINE_OPENSSL_API_RSA_DE_MALLOC 0x10D00A4        //申请空间失败
#define ERROR_XENGINE_OPENSSL_API_RSA_DE_CODEC 0x10D00A5         //加密失败
/************************************************************************/
/*         证书与签名错误导出                                           */
/************************************************************************/
//数字签名错误导出
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_ENCODER_PARAMENT 0x10D1000      //签名错误，参数错误
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_ENCODER_NEWKEY 0x10D1001        //新建一个保存KEY空间失败
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_ENCODER_UPDATE 0x10D1002        //更新数据签名失败
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_ENCODER_FINAL 0x10D1003         //完成数据签名失败
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_VER_PARAMENT 0x10D1010          //参数错误
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_VER_NEWKEY 0x10D1011            //验证失败,申请KEY失败
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_VER_UPDATE 0x10D1012            //验证更新数据签名失败
#define ERROR_XENGINE_OPENSSL_CERT_SIGN_VER_FINAL 0x10D1013             //完成验证数据签名失败
//生成证书
#define ERROR_XENGINE_OPENSSL_CERT_MAKECACERT_PARAMENT 0x10D1100        //参数错误生成根证书失败
#define ERROR_XENGINE_OPENSSL_CERT_MAKECACERT_SETKEY 0x10D1101          //关联密钥失败
#define ERROR_XENGINE_OPENSSL_CERT_MAKECACERT_SIGN 0x10D1102            //签名失败
#define ERROR_XENGINE_OPENSSL_CERT_MAKECACERT_WRITECERT 0x10D1103       //写入证书文件失败
#define ERROR_XENGINE_OPENSSL_CERT_MAKECACERT_WRITEKEY 0x10D1104        //希尔证书密钥失败
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_PARAMENT 0x10D1110          //参数错误
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_MALLOC 0x10D1111            //申请内存失败
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_OPENKEY 0x10D1112           //打开私钥
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_READKEY 0x10D1113           //读取数据失败
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_CVTKEY 0x10D1114            //转换为KEY失败
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_SETKEY 0x10D1115            //设置关联失败
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_SIGN 0x10D1116              //签名失败
#define ERROR_XENGINE_OPENSSL_CERT_GEN_X509_VER 0x10D1117               //验证失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_PARAMENT 0x10D1120           //签名验证失败,参数错误
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_OPENCERT 0x10D1121           //打开证书失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_READCERT 0x10D1122           //读取证书失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_OPENKEY 0x10D1123            //打开私钥失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_READKEY 0x10D1124            //读取私钥失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_OPENREQ 0x10D1125            //打开请求文件失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_READREQ 0x10D1126            //读取请求文件失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_VERKEY 0x10D1127             //验证请求文件KEY失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_SIGN 0x10D1128               //签名失败
#define ERROR_XENGINE_OPENSSL_CERT_SINGVER_SAVE 0x10D1129               //保存证书失败
//X509证书验证
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_OPENROOT 0x10D1200         //打开验证证书失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_OPENUSER 0x10D1201         //打开用户证书失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_ROOTCVT 0x10D1202          //转换根证书失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_USERCVT 0x10D1203          //转换用户证书失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_NEWROOT 0x10D1204          //新建根证书内存存储位置失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_ADD 0x10D1205              //将根证书添加到存储位置失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_CAINIT 0x10D1206           //初始化证书失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_VER_ISFAILED 0x10D1207         //证书已经过期或者验证失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_GET_PARAMENT 0x10D1210         //参数错误
#define ERROR_XENGINE_OPENSSL_CERT_X0509_GET_OPENFILE 0x10D1211         //打开证书失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_GET_TOCER 0x10D1212            //解析CER格式失败
#define ERROR_XENGINE_OPENSSL_CERT_X0509_GET_TOSERIAL 0x10D1213         //解析序列号失败
//签名验证加解密算法
#define ERROR_XENGINE_OPENSSL_CERT_DISEST_MALLOC 0x10D1301              //申请内存失败
#define ERROR_XENGINE_OPENSSL_CERT_DISEST_OPEN 0x10D1302                //打开密钥失败
#define ERROR_XENGINE_OPENSSL_CERT_DISEST_GETRSA 0x10D1302              //获取密钥算法失败
#define ERROR_XENGINE_OPENSSL_CERT_DISEST_SET 0x10D1302                 //设置关联失败
#define ERROR_XENGINE_OPENSSL_CERT_DISEST_NOTSUPPORT 0x10D1302          //不支持的算法
#define ERROR_XENGINE_OPENSSL_CERT_DISEST_ISFAILED 0x10D1303            //加解密失败,无法继续
/************************************************************************/
/*           SSL安全传输库导出错误列表                                  */
/************************************************************************/
#define ERROR_XENGINE_OPENSSL_SERVER_INIT_UNKNOWPROTOCOL 0x10D2001     //无法识别的协议库
#define ERROR_XENGINE_OPENSSL_SERVER_INIT_NEWCTX 0x10D2002             //申请上下文加解密器失败
#define ERROR_XENGINE_OPENSSL_SERVER_INIT_SETSERVERCERT 0x10D2003      //设置服务器证书失败
#define ERROR_XENGINE_OPENSSL_SERVER_INIT_SETSRVPRIVATE 0x10D2004      //设置服务端私钥失败
#define ERROR_XENGINE_OPENSSL_SERVER_INIT_CHECKPRIVATEKEY 0x10D2005    //服务端私钥与证书不匹配，无法继续
#define ERROR_XENGINE_OPENSSL_SERVER_ACCEPT_PARAMENT 0x10D2010         //接受连接失败,参数错误
#define ERROR_XENGINE_OPENSSL_SERVER_ACCEPT_ISFAILED 0x10D2011         //接受连接失败,内部错误
#define ERROR_XENGINE_OPENSSL_SERVER_RECV_PARAMENT 0x10D2020           //参数错误
#define ERROR_XENGINE_OPENSSL_SERVER_RECV_NOTFOUND 0x10D2021           //接受数据失败,没有找到客户端
#define ERROR_XENGINE_OPENSSL_SERVER_RECV_ISFAILED 0x10D2022           //客户端接受数据失败,当做客户端离开处理
#define ERROR_XENGINE_OPENSSL_SERVER_SENDMSG_PARAMENT 0x10D2030        //参数错误，发送数据失败
#define ERROR_XENGINE_OPENSSL_SERVER_SENDMSG_NOTFOUND 0x10D2031        //发送消息没有找到指定的客户
#define ERROR_XENGINE_OPENSSL_SERVER_SENDMSG_ISFAILED 0x10D2032        //发送失败,当做客户端离开处理
/************************************************************************/
/*           编解码器导出错误列表                                       */
/************************************************************************/
#define ERROR_XENGINE_OPENSSL_API_CODEC_BASE64_PARAMENT 0x10D3000      //参数错误，有NULL参数
#define ERROR_XENGINE_OPENSSL_API_CODEC_BASE64_NEWBIO 0x10D3001        //申请新的算法空间失败
#define ERROR_XENGINE_OPENSSL_API_CODEC_BASE64_NEWMEM 0x10D3002        //申请内存失败
#define ERROR_XENGINE_OPENSSL_API_CODEC_BASE64_BIOPUSH 0x10D3003       //把数据压入空间失败
#define ERROR_XENGINE_OPENSSL_API_CODEC_BASE64_BIOWRITE 0x10D3004      //写入空间失败
#define ERROR_XENGINE_OPENSSL_API_CODEC_BASE64_BIOFLUSH 0x10D3005      //刷新失败
/************************************************************************/
/*           X加解密导出错误列表                                        */
/************************************************************************/
#define ERROR_XENGINE_OPENSSL_XCRYPTO_ENCODER_PARAMENT 0x10D4001        //参数错误
#define ERROR_XENGINE_OPENSSL_XCRYPTO_DECODER_PARAMENT 0x10D4010        //参数错误
#define ERROR_XENGINE_OPENSSL_XCRYPTO_DECODER_HDR 0x10D4011             //加密头不正确,不是X加解密
#define ERROR_XENGINE_OPENSSL_XCRYPTO_DECODER_TYPE 0x10D4012            //加解密类型不匹配
#define ERROR_XENGINE_OPENSSL_XCRYPTO_DECODER_CHECK 0x10D4013           //校验码验证失败,无法继续
/************************************************************************/
/*           加解密帮助函数错误码                                       */
/************************************************************************/
#define ERROR_XENGINE_OPENSSL_HELP_BASICENCODER_PARAMENT 0x10D5000       //参数错误
#define ERROR_XENGINE_OPENSSL_HELP_BASICDECODER_PARAMENT 0x10D5010       //参数错误
#define ERROR_XENGINE_OPENSSL_HELP_BASICDECODER_FORMAT 0x10D5011         //格式错误