﻿#pragma once
/********************************************************************
//    Created:     2024/10/28  14:55:03
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Core\XEngine_Cryption\Cryption_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Core\XEngine_Cryption
//    File Base:   Cryption_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     加解密秘钥算法库导出定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                   导入定义
//////////////////////////////////////////////////////////////////////////
//SSL证书文件证书编码类型
#define XENGINE_CRYPTION_CERTTYPE_PEM_FILE 1                              //PEM编码格式：BASE64。调用者无需关心编码实现部分，只需要传递即可
#define XENGINE_CRYPTION_CERTTYPE_ASN1_FILE 2                             //ASN1编码格式：DER
//SSL传输恶意
#define XENGINE_CRYPTION_PROTOCOL_DTL 0
#define XENGINE_CRYPTION_PROTOCOL_TLS 1
//////////////////////////////////////////////////////////////////////////
//        数据类型定义
//////////////////////////////////////////////////////////////////////////
//摘要算法库
typedef enum
{
    ENUM_XENGINE_CRYPTION_DIGEST_MD4 = 1,                                 //MD4摘要算法
    ENUM_XENGINE_CRYPTION_DIGEST_MD5,                                     //MD5摘要算法
    ENUM_XENGINE_CRYPTION_DIGEST_SHA1,                                    //SHA1摘要算法
    ENUM_XENGINE_CRYPTION_DIGEST_SHA256,                                  //SHA256摘要算法
    ENUM_XENGINE_CRYPTION_DIGEST_SHA512,                                  //SHA512摘要算法
    ENUM_XENGINE_CRYPTION_DIGEST_RIPEMD160,                               //RIPEMD160摘要算法
    ENUM_XENGINE_CRYPTION_DIGEST_SM3                                      //国标SM3
}ENUM_XENGINE_CRYPTION_DIGEST, * LPENUM_XENGINE_CRYPTION_DIGEST;
//非对称加解密库
typedef enum
{
    ENUM_XENGINE_CRYPTION_SYMMETRIC_AES = 1,                                  //AES加解密
    ENUM_XENGINE_CRYPTION_SYMMETRIC_DES = 2,                                  //DES加解密
    ENUM_XENGINE_CRYPTION_SYMMETRIC_3DES = 3,                                 //3DES加解密算法
    ENUM_XENGINE_CRYPTION_SYMMETRIC_RC4 = 4,                                  //RC4加解密
    ENUM_XENGINE_CRYPTION_SYMMETRIC_SM3 = 10,                                 //GBSM3算法
    //下面的定义在CENTOS下暂时不支持
    ENUM_XENGINE_CRYPTION_SYMMETRIC_SMCBC = 11,                               //GBSM4_CBC算法
    ENUM_XENGINE_CRYPTION_SYMMETRIC_SMCFB = 12,                               //同
    ENUM_XENGINE_CRYPTION_SYMMETRIC_SMCFB128 = 13,                            //同
    ENUM_XENGINE_CRYPTION_SYMMETRIC_SMCTR = 14                                //同属GBSM4算法类
}ENUM_XENGINE_CRYPTION_SYMMETRIC, * LPENUM_XENGINE_CRYPTION_SYMMETRIC;
//证书查询内部结构体
typedef struct
{
    XCHAR tszCountryName[128];                                            //国家
    XCHAR tszProvinceName[128];                                           //省
    XCHAR tszLocalityName[128];                                           //地区
    XCHAR tszOrganizationName[128];                                       //组织
    XCHAR tszOrgUnitName[128];                                            //单位
    XCHAR tszCommonName[128];                                             //通用名
    XCHAR tszEmailAddress[128];                                           //电子邮件
    struct
    {
        XCHAR tszName[128];                                               //名字
        XCHAR tszTitle[128];                                              //头衔
        XCHAR tszDesCription[128];                                        //描述
    }st_ExtInfo;                                                         //可空信息
}XCRYPTION_X509ATTR, * LPXCRYPTION_X509ATTR;
//查询证书信息函数输入结构体，输出结构体
typedef struct
{
    int nCertType;                                                        //证书类型,1用于加密,2用于签名
    long lVersion;                                                        //保存证书版本
    time_t nTimeStart;                                                    //证书生效时间
    time_t nTimeEnd;                                                      //证书过期时间
    XCHAR tszSerialNumber[64];                                            //证书序列号
    XCHAR tszAlgorithm[64];                                               //签名算法
    XCHAR tszPubKey[1024];                                                //证书的公钥
    XCHAR tszPriKey[1024];                                                //证书的私钥

    XCRYPTION_X509ATTR st_Issuer;                                          //证书颁发者信息
    XCRYPTION_X509ATTR st_SubJect;                                         //证书拥有者信息
}XCRYPTION_X509INFO, * LPXCRYPTION_X509INFO;
//////////////////////////////////////////////////////////////////////////
//               函数导出定义
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG Cryption_GetLastError(int* pInt_ErrorCode = NULL);
/************************************************************************/
/*               数据编码算法导出函数                                      */
/************************************************************************/
/********************************************************************
函数名称：Cryption_Codec_UrlEnCodec
函数功能：URL编码
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要编码的URL字符串
 参数.二：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入原始字符串长度
 参数.三：pszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出编码后的字符串
返回值
  类型：无
  意思：
备注：如果是传送HTTP服务器的字符串需要根据服务器类型做编码转换,比如LINUX是UTF8,然后在进行URL编码
*********************************************************************/
extern "C" void Cryption_Codec_UrlEnCodec(LPCXSTR lpszSource, int nLen, XCHAR* ptszDest);
/********************************************************************
函数名称：Cryption_Codec_UrlDeCodec
函数功能：URL解码
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解码的URL字符串
 参数.二：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入原始字符串长度
 参数.三：pszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出解码后的字符串
返回值
  类型：无
  意思：
备注:
*********************************************************************/
extern "C" void Cryption_Codec_UrlDeCodec(LPCXSTR lpszSource, int nLen, XCHAR* ptszDest);
/********************************************************************
函数名称：Cryption_Codec_Base64
函数功能：BASE64编解码
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要编解码的原始数据
 参数.二：ptszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出编解码后的数据
 参数.三：pInt_Len
  In/Out：In
  类型：整数型指针
  可空：N
  意思：输入：原始数据大小，输出：编解码后的数据大小
 参数.四：bIsEnCodec
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：要编码还是解码，默认编码
 参数.五：bIsLine
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：编码的数据是否启用换行,默认不启用
返回值
  类型：逻辑型
  意思：是否编解码成功
备注：
*********************************************************************/
extern "C" bool Cryption_Codec_Base64(LPCXSTR lpszSource, XCHAR* ptszDest, int* pInt_Len, bool bIsEnCodec = true, bool bIsLine = false);
/********************************************************************
函数名称：Cryption_Codec_CRC32Codec
函数功能：CRC32压缩标准算法模块,内部做了异或操作
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入一段要编码的数据
 参数.二：nSize
  In/Out：In
  类型：整数型
  可空：N
  意思：编码数据大小
返回值
  类型：整数型
  意思：返回CRC32编码值
备注：
*********************************************************************/
extern "C" XUINT Cryption_Codec_CRC32Codec(LPCXSTR lpszSource, int nSize);
/********************************************************************
函数名称：Cryption_Codec_CRC32Codec2
函数功能：CRC32压缩网络处理算法,只做了初始化操作
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入一段要编码的数据
 参数.二：nSize
  In/Out：In
  类型：整数型
  可空：N
  意思：编码数据大小
返回值
  类型：整数型
  意思：返回CRC32编码值
备注：
*********************************************************************/
extern "C" XUINT Cryption_Codec_CRC32Codec2(LPCXSTR lpszSource, int nSize);
/********************************************************************
函数名称：Cryption_Codec_2BytesToBCD
函数功能：两个字符转BCD编码
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入一段要编码的数据
 参数.二：chBCD
  In/Out：Out
  类型：无符号字符
  可空：N
  意思：输出编码好的数据
返回值
  类型：无
  意思：
备注：
*********************************************************************/
extern "C" void Cryption_Codec_2BytesToBCD(LPCXSTR lpszSource, XBYTE& chBCD);
/********************************************************************
函数名称：Cryption_Codec_BCDTo2Bytes
函数功能：BCD编码转字符
 参数.一：chBCD
  In/Out：In
  类型：无符号字符
  可空：N
  意思：输入要解码的BCD字符
 参数.二：ptszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解码后的字符串
返回值
  类型：无
  意思：
备注：
*********************************************************************/
extern "C" void Cryption_Codec_BCDTo2Bytes(XBYTE chBCD, XCHAR* ptszDest);
/********************************************************************
函数名称：Cryption_Codec_BCDToInt
函数功能：BCD编码转整数型
 参数.一：chBCD
  In/Out：In
  类型：无符号字符
  可空：N
  意思：输入要解码的BCD字符
返回值
  类型：整数型
  意思：输出解码数据
备注：
*********************************************************************/
extern "C" int Cryption_Codec_BCDToInt(XBYTE chBCD);
/********************************************************************
函数名称：Cryption_Codec_IntToBCD
函数功能：将00-99的整数存放成1个字节的BCD
 参数.一：uszInt
  In/Out：In
  类型：无符号字符
  可空：N
  意思：输入要编码的整数
返回值
  类型：无符号字符
  意思：输出编码数据
备注：
*********************************************************************/
extern "C" XBYTE Cryption_Codec_IntToBCD(XBYTE uszInt);
/************************************************************************/
/*               OPENSSL加解密算法API                                   */
/************************************************************************/
/************************************************************************
函数名称：Cryption_Api_CryptEncodec
函数功能：非对称加密
 参数一：lpszSourceData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待加密的数据
 参数二：ptszDestData
  In/Out：In/Out
  类型：无符号字符指针
  可空：N
  意思：加密后的字符指针，请不要尝试做任何编码转换。编码转换肯定认不出这个数据内容
 参数三：pInt_MsgLen
  In/Out：In/Out
  类型：整数指针
  可空：N
  意思：输入待加密的字符串大小，输出加密后的数据长度
 参数四：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：表明要加密的KEY密钥。32位无符号，必须是8的倍数 要么8位要么16位
 参数五：en_CryptType
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要使用哪种方式加密，默认为3DES
 返回值
  类型：逻辑型
  意思：是否加密成功
备注：
************************************************************************/
extern "C" bool Cryption_Api_CryptEncodec(LPCXSTR lpszSourceData, XBYTE* ptszDestData, int* pInt_Len, LPCXSTR lpszKey, ENUM_XENGINE_CRYPTION_SYMMETRIC en_CryptType = ENUM_XENGINE_CRYPTION_SYMMETRIC_3DES);
/************************************************************************
函数名称：Cryption_Api_CryptDecodec
函数功能：非对称解密函数
 参数一：lpszSourceData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待解密的加密数据
 参数二：ptszDestData
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：解密后的数据，初始化足够的大小。返回解密后的数据
 参数三：pInt_Len
  In/Out：In/Out
  类型：整数指针
  可空：N
  意思：输入带解密的字符串空间大小，输出解密后数据长度
 参数四：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：解密KEY的值，32位值
 参数五：en_CryptType
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要使用哪个加解密库
返回值
  类型：逻辑型
  意思：是否成功解密
备注：
************************************************************************/
extern "C" bool Cryption_Api_CryptDecodec(const XBYTE* lpszSourceData, XCHAR* ptszDestData, int* pInt_Len, LPCXSTR lpszKey, ENUM_XENGINE_CRYPTION_SYMMETRIC en_CryptType = ENUM_XENGINE_CRYPTION_SYMMETRIC_3DES);
/************************************************************************
函数名称：Cryption_Api_Digest
函数功能：信息摘要算法实现函数
 参数一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要加密的数据
 参数二：ptszMsgBuffer
  In/Out：In/Out
  类型：无符号字符指针
  可空：N
  意思：输入一个足够的大的内存，输出加密后的数据
 参数三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入待加密的数据大小，输出加密后的数据大小,文件方式这个参数可以为NULL
 参数四：bIsFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：文件还是缓冲区,默认缓冲区
 参数五：dwDigestLib
  In/Out：In
  类型：双字
  可空：Y
  意思：加密方式，默认为MD5
返回值
  类型：逻辑型
  意思：是否加密成功
备注：
************************************************************************/
extern "C" bool Cryption_Api_Digest(LPCXSTR lpszMsgBuffer, XBYTE* ptszMsgBuffer, int* pInt_Len, bool bIsFile = false, XLONG dwDigestLib = ENUM_XENGINE_CRYPTION_DIGEST_MD5);
/********************************************************************
函数名称：Cryption_Api_HMac
函数功能：HMAC数据计算函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要计算的缓冲区数据
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出计算后的数据
 参数.三：pInt_MSGLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要计算的缓冲区大小,输出计算后的摘要信息大小
 参数.四：lpszKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入散列数据秘钥
 参数.五：enDigest
  In/Out：In
  类型：枚举型
  可空：Y
  意思：输入要选择计算的算法,默认SHA1
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Api_HMac(LPCXSTR lpszMsgBuffer, XBYTE* ptszMsgBuffer, int* pInt_MSGLen, LPCXSTR lpszKey, ENUM_XENGINE_CRYPTION_DIGEST enDigest = ENUM_XENGINE_CRYPTION_DIGEST_SHA1);
/********************************************************************
函数名称：Cryption_Api_RSAFileCreate
函数功能：创建一个RSA私钥文件
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入创建的文件路径
 参数.二：lpszPassStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入文件秘钥
 参数.三：nBitSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入秘钥大小
 参数.四：bRSA
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：RSA还是ecdsa秘钥算法
返回值
  类型：逻辑型
  意思：是否成功
备注：密码可以为NULL,不输入
      RSA的私钥和公钥都可以用来加解密，但是他们的加解密的KEY要对称公钥加密-私钥解密
*********************************************************************/
extern "C" bool Cryption_Api_RSAFileCreate(LPCXSTR lpszFile, LPCXSTR lpszPassStr = NULL, int nBitSize = 2048, bool bRSA = true);
/********************************************************************
函数名称：Cryption_Api_RSAMemoryCreate
函数功能：RSA私钥内存创建函数
 参数.一：ptszRSABuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出创建的私钥缓冲区
 参数.二：pInt_RSALen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出私钥大小
 参数.三：lpszPassStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入文件秘钥
 参数.四：nBitSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入秘钥大小
 参数.五：bRSA
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：RSA还是ecdsa秘钥算法
返回值
  类型：逻辑型
  意思：是否成功
备注：密码可以为NULL,不输入
*********************************************************************/
extern "C" bool Cryption_Api_RSAMemoryCreate(XCHAR* ptszRSABuffer, int* pInt_RSALen, LPCXSTR lpszPassStr = NULL, int nBitSize = 2048, bool bRSA = true);
/********************************************************************
函数名称：Cryption_Api_RSAPubFile
函数功能：通过私钥文件创建公钥文件函数
 参数.一：lpszPriFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：读取私钥文件路径
 参数.二：lpszPubFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：写入公钥文件路径
 参数.三：lpszPassStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：私钥的密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Api_RSAPubFile(LPCXSTR lpszPriFile, LPCXSTR lpszPubFile, LPCXSTR lpszPassStr = NULL);
/********************************************************************
函数名称：Cryption_Api_RSAPubMemory
函数功能：公钥数据生成到内存函数
 参数.一：ptszPubBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出的公钥数据
 参数.二：pInt_PLen
  In/Out：In
  类型：整数型指针
  可空：N
  意思：输出的公钥数据大小
 参数.三：lpszPriBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入私钥内存缓冲区
 参数.四：nPLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入私钥内存大小
 参数.五：lpszPassStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：私钥的密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Api_RSAPubMemory(XCHAR* ptszPubBuffer, int* pInt_PLen, LPCXSTR lpszPriBuffer, int nPLen, LPCXSTR lpszPassStr = NULL);
/********************************************************************
函数名称：Cryption_Api_RSAEncodec
函数功能：RSAKEY加密数据
 参数.一：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：KEY文件路径
 参数.二：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要加密的原始数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：原始数据长度，输出加密后的数据长度
 参数.四：ptszMSGBuffer
  In/Out：Out
  类型：无符号字符指针
  可空：N
  意思：输出加密后的数据
 参数.五：bKeyType
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真表示使用公钥加密，为假表示使用私钥加密
 参数.六：bKeyFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入的KEY文件是文件还是内存缓冲区,默认文件
 参数.七：lpszPriPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果私钥加过密,那么必须输入私钥密码
返回值
  类型：逻辑型
  意思：是否加密成功
备注：
*********************************************************************/
extern "C" bool Cryption_Api_RSAEncodec(LPCXSTR lpszKeyFile, LPCXSTR lpszMSGBuffer, int* pInt_Len, XBYTE* ptszMSGBuffer, bool bKeyType = true, bool bKeyFile = true, LPCXSTR lpszPriPass = NULL);
/********************************************************************
函数名称：Cryption_Api_RSADecodec
函数功能：使用RSAKEY解密数据
 参数.一：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：KEY文件路径
 参数.二：lpszMSGBuffer
  In/Out：In
  类型：常量无符号字符指针
  可空：N
  意思：要解密的原始数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：原始数据长度，输出解密后的数据长度
 参数.四：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解密后的数据
 参数.五：bKeyType
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真表示使用公钥解密，为假表示使用私钥解密
 参数.六：bKeyFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入的KEY文件是文件还是内存缓冲区,默认文件
 参数.七：lpszPriPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果私钥加过密,那么必须输入私钥密码
返回值
  类型：逻辑型
  意思：是否解密成功
备注：
*********************************************************************/
extern "C" bool Cryption_Api_RSADecodec(LPCXSTR lpszKeyFile, LPCXSTR lpszMSGBuffer, int* pInt_Len, XCHAR* ptszMSGBuffer, bool bKeyType = true, bool bKeyFile = true, LPCXSTR lpszPriPass = NULL);
/************************************************************************/
/*                 证书操作导出函数                                     */
/************************************************************************/
/********************************************************************
函数名称：Cryption_Cert_SignEncoder
函数功能：签名数据并且加密
 参数.一：lpszSourceData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待签名的原始数据
 参数.二：ptszDestData
  In/Out：Out
  类型：字符指针
  可空：N
  意思：数据签名后的数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入原始数据大小,输出签名后数据大小
 参数.四：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：验证使用私钥签名,传递私钥文件路径
 参数.五：lpszKeyPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：密钥的密码,如果没有传递NULL
返回值
  类型：逻辑型
  意思：是否成功
备注：用于对一段数据进行签名
*********************************************************************/
extern "C" bool Cryption_Cert_SignEncoder(LPCXSTR lpszSourceData, int nSrcLen, XCHAR* ptszDestData, int* pInt_Len, LPCXSTR lpszKeyFile, LPCXSTR lpszKeyPass = NULL);
/********************************************************************
函数名称：Cryption_Cert_SignVerifly
函数功能：验证签名
 参数.一：lpszSourceData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待验证的签名数据
 参数.二：nSrcLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入签名数据大小
 参数.三：lpszDestData
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要验证的原始数据
 参数.四：nDstLen
  In/Out：In
  类型：整数型
  可空：N
  意思：原始数据大小
 参数.五：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：验证使用公钥验证,传递公钥文件路径
 参数.七：lpszKeyPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：密码
返回值
  类型：逻辑型
  意思：为真为验证成功
备注：用于验证签名的数据与原始数据是否相同,不是解密
*********************************************************************/
extern "C" bool Cryption_Cert_SignVerifly(LPCXSTR lpszSourceData, int nSrcLen, LPCXSTR lpszDestData, int nDstLen, LPCXSTR lpszKeyFile, LPCXSTR lpszKeyPass = NULL);
/********************************************************************
函数名称：Cryption_Cert_Convert
函数功能：证书转换
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的原始文件
 参数.二：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的目标文件
 参数.三：bDer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：真为PEM转DER,假DER转PEM
 参数.四：lpszPassStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入PEM密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Cert_Convert(LPCXSTR lpszSrcFile, LPCXSTR lpszDstFile, bool bDer = true, LPCXSTR lpszPassStr = NULL);
/********************************************************************
函数名称：Cryption_Cert_MakeCACert
函数功能：制作一个CA证书,用于签发证书请求文件
 参数.一：lpszCertFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要生成的CA根证书保存目录
 参数.二：nlSerial
  In/Out：In
  类型：长整数型
  可空：N
  意思：密钥序列号
 参数.三：nlTimeSecond
  In/Out：In
  类型：长整数型
  可空：N
  意思：跟证书时间
 参数.四：pSt_X509CerInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要写入的信息
 参数.五：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：你的私钥文件路径,你需要先生成一个RSA私钥,通过此函数读取
 参数.六：lpszKeyPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：私钥密码,如果没有,传递NULL
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Cert_MakeCACert(LPCXSTR lpszCertFile, long nlSerial, long nlTimeSecond, XCRYPTION_X509ATTR* pSt_X509CerInfo, LPCXSTR lpszKeyFile, LPCXSTR lpszKeyPass = NULL);
/********************************************************************
函数名称：Cryption_Cert_X509Create
函数功能：根据密钥生成证书请求文件
 参数.一：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入生成成功的文件保存路径
 参数.二：pSt_X509CerInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入主题信息
 参数.三：lpszRSAKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入私钥文件路径
 参数.四：lpszKeyPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入私钥文件密码,如果没有密码,传递NULL
 参数.五：bRequest
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：创建的证书是否是请求类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Cert_X509Create(LPCXSTR lpszDstFile, XCRYPTION_X509ATTR* pSt_X509CerInfo, LPCXSTR lpszRSAKey, LPCXSTR lpszKeyPass = NULL, bool bRequest = true);
/********************************************************************
函数名称：Cryption_Cert_X509Sign
函数功能：对一个证书请求文件进行签名验证
 参数.一：lpszCACert
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：CA根证书目录
 参数.二：lpszREQFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：生成的请求文件路径
 参数.三：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：签发后的证书保存路径
 参数.四：nlTimeSecond
  In/Out：In
  类型：长整数型
  可空：N
  意思：跟证书时间,单位秒
 参数.五：lpszCAKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：CA根证书的密钥目录
 参数.六：lpszREQPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：请求的文件密钥,如果没有传递NULL
 参数.七：lpszCAPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：证书的私钥密码,如果没有传递NULL
 参数.八：pppSt_ListExt
  In/Out：In
  类型：三级指针
  可空：Y
  意思：证书附加信息,这个内存应该由调用者申请释放
 参数.九：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入整数信息个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Cert_X509Sign(LPCXSTR lpszCACert, LPCXSTR lpszREQFile, LPCXSTR lpszDstFile, long nlTimeSecond, LPCXSTR lpszCAKey, LPCXSTR lpszREQPass = NULL, LPCXSTR lpszCAPass = NULL, XENGINE_KEYVALUE*** pppSt_ListExt = NULL, int nListCount = 0);
/********************************************************************
函数名称：Cryption_Cert_X509Verifly
函数功能：验证证书是否正确
 参数.一：lpszCARoot
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：根证书保存路径
 参数.二：lpszCAUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：个人证书路径
 参数.三：nCertType
  In/Out：In
  类型：整数型
  可空：Y
  意思：证书类型,PEM还是DER
返回值
  类型：逻辑型
  意思：证书是否验证成功
备注：
*********************************************************************/
extern "C" bool Cryption_Cert_X509Verifly(LPCXSTR lpszCARoot, LPCXSTR lpszCAUser, int nCertType = XENGINE_CRYPTION_CERTTYPE_PEM_FILE);
/********************************************************************
函数名称：Cryption_Cert_GetCerInfomachine
函数功能：获取个人证书信息
 参数.一：lpszCerFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要查询的证书路径
 参数.二：pSt_X509CCInfo
  In/Out：In
  类型：结构体指针
  可空：N
  意思：输出个人证书所查询到的信息
返回值
  类型：逻辑型
  意思：是否查询成功
备注：
*********************************************************************/
extern "C" bool Cryption_Cert_GetCerInfomachine(LPCXSTR lpszCerFile, LPXCRYPTION_X509INFO pSt_X509CCInfo);
/************************************************************************/
/*                 SSL安全传输认证函数                                  */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：Cryption_Server_Init
函数功能：初始化SSL上下文环境
 参数.一：lpszCACert
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：CA签名的证书,此参数可以输入NULL
 参数.二：lpszServerCert
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：服务端证书,此参数为NULL那么参数一的意思表示使用证书链
 参数.三：lpszServerKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：服务器端私钥
 参数.四：bVerPeer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：强制客户端使用证书,默认不需要
 参数.五：bSSocket
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：使用本模块来处理数据收发还是由用户来处理,真为系统
 参数.六：enProtocol
  In/Out：In
  类型：枚举型
  可空：Y
  意思：支持TLS和DTL自适应协议
 参数.七：dwCoderType
  In/Out：In
  类型：双字
  可空：Y
  意思：编码类型，默认PEM编码
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：启用这个服务器，你可以使用安全的传输模式，你发送和接受到的数据都是明文，底层我们已经为你做好了加解密工作
      如果你想自己处理SSL收发.那么bSSocket要为假,UDP的bSSocket必须为系统处理
*********************************************************************/
extern "C" XHANDLE Cryption_Server_InitEx(LPCXSTR lpszCACert, LPCXSTR lpszServerCert, LPCXSTR lpszServerKey, bool bVerPeer = false, bool bSSocket = true, XSHOT enProtocol = XENGINE_CRYPTION_PROTOCOL_TLS, XLONG dwCoderType = XENGINE_CRYPTION_CERTTYPE_PEM_FILE);
/********************************************************************
函数名称：Cryption_Server_Config
函数功能：启用协议配置
 参数.一：lpszConfigStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要启用的配置字符串
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Server_ConfigEx(XHANDLE xhToken, LPCXSTR lpszConfigStr = _X("SRTP_AES128_CM_SHA1_80"));
/********************************************************************
函数名称：Cryption_Server_Accept
函数功能：接受一个SSL连接
 参数.一：hSocket
  In/Out：In
  类型：网络套接字
  可空：N
  意思：输入你的ACCEPT返回的套接字句柄
 参数.二：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入你的客户端地址的信息IP:PORT
 参数.三：ptszClientAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：得到客户端地址信息,如果lpszClientAddr为NULL,那么此参数有效
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Server_AcceptEx(XHANDLE xhToken, XSOCKET hSocket, LPCXSTR lpszClientAddr, XCHAR* ptszClientAddr = NULL);
/********************************************************************
函数名称：Cryption_Server_AcceptMemory
函数功能：内存处理的接受链接方法
 参数.一：hSocket
  In/Out：In
  类型：网络套接字
  可空：N
  意思：输入你的ACCEPT返回的套接字句柄
 参数.二：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入你的客户端地址的信息IP:PORT
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出如果有需要发送数据的缓冲区
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出发送数据大小
 参数.五：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入接受到的缓冲区数据,用于链接处理
 参数.六：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入接受到的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：对于SSL链接,可能需要处理多次才能正确建立连接,一般情况不推荐使用此函数
*********************************************************************/
extern "C" bool Cryption_Server_AcceptMemoryEx(XHANDLE xhToken, XSOCKET hSocket, LPCXSTR lpszClientAddr, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：Cryption_Server_GetSSLInfo
函数功能：获取客户端SSL证书算法信息
 参数.一：ptszSslSubJect
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端拥有的证书信息
 参数.二：ptszSslIssuer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端发布的整数型
 参数.三：ptszSslAlgorithm
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端拥有的加密算法
返回值
  类型：逻辑型
  意思：是否成功
备注：如果客户端没有使用证书密钥,那么会返回失败
*********************************************************************/
extern "C" bool Cryption_Server_GetSSLInfoEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XCHAR* ptszSslSubJect = NULL, XCHAR* ptszSslIssuer = NULL, XCHAR* ptszSslAlgorithm = NULL);
/********************************************************************
函数名称：Cryption_Server_GetKey
函数功能：获取指定加密类型的密钥信息
 参数.一：lpszClientAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出本地发送KEY数据密钥
 参数.二：ptszKEYBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出密钥缓冲区
 参数.三：lpszKeyTStr
  In/Out：Out
  类型：常量字符指针
  可空：Y
  意思：输入密钥获取类型字符串
 参数.四：nKeySize
  In/Out：In
  类型：整数型
  可空：Y
  意思：根据密钥不同加密算法不同大小也不一样,DTSL-AES128的大小是30字节
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Server_GetKeyEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XBYTE* ptszKEYBuffer, LPCXSTR lpszKeyTStr = _X("EXTRACTOR-dtls_srtp"), int nKeySize = 30);
/********************************************************************
函数名称：Cryption_Server_RecvMsgEx
函数功能：接受一条SSL数据
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端地址
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出接受到的数据缓冲区
 参数.三：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小(必须比参数五大),输出缓冲区大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果bSSocket为false,你RECV的数据需要投递给最后两个参数
 参数.五：nMsgLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小,输出接收到的缓冲区大小
 参数.六：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：如果使用自定义发送接受,那么后两个参数是你套接字接受的数据解码才能得到参数二和三
*********************************************************************/
extern "C" bool Cryption_Server_RecvMsgEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Server_RecvMemory
函数功能：读取数据到内存缓冲区
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端地址
 参数.二：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：输出接受到的数据缓冲区,这个内存需要手动释放
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果bSSocket为false,你RECV的数据需要投递给最后两个参数
 参数.五：nMsgLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小,输出接收到的缓冲区大小
 参数.六：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：意思同Cryption_Server_Recv
*********************************************************************/
extern "C" bool Cryption_Server_RecvMemoryEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XCHAR** pptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Server_SendMsg
函数功能：发送安全数据
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送给谁
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送的消息
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送消息大小
 参数.四：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：如果使用了自定义发送数据,输出要发送的数据缓冲区
 参数.五：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小,提供的缓冲区大小,必须比参数三大
 参数.六：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：如果使用自定义发送接受,那么后两个参数才是导出要发送的数据,否则将直接发送
*********************************************************************/
extern "C" bool Cryption_Server_SendMsgEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, LPCXSTR lpszMsgBuffer, int nLen, XCHAR* ptszMsgBuffer = NULL, int* pInt_MsgLen = NULL, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Server_SendMemory
函数功能：发送一段数据到加密内存中
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送给谁
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：发送的消息
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：发送消息大小
 参数.四：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：输出要发送的数据缓冲区
 参数.五：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.六：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Server_SendMemoryEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, LPCXSTR lpszMsgBuffer, int nLen, XCHAR** pptszMsgBuffer, int* pInt_MsgLen, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Server_GetSocket
函数功能：获得客户端对应套接字
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：phSocket
  In/Out：Out
  类型：套接字句柄
  可空：N
  意思：输出套接字
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Server_GetSocketEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XSOCKET* phSocket);
/********************************************************************
函数名称：Cryption_Server_IsAccept
函数功能：指定客户端是否链接成功
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：pbConnect
  In/Out：Out
  类型：逻辑型
  可空：Y
  意思：输出是否链接成功
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Server_IsAcceptEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, bool* pbConnect = NULL);
/************************************************************************
函数名称：Cryption_Server_CloseClient
函数功能：主动关闭一个客户
  参数一：lpszClientAddr
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：客户端地址
返回值
  类型：逻辑型
  意思：是否成功释放相关资源
备注：
************************************************************************/
extern "C" bool Cryption_Server_CloseClientEx(XHANDLE xhToken, LPCXSTR lpszClientAddr);
/************************************************************************
函数名称：Cryption_Server_Stop
函数功能：关闭SSL服务器
返回值
  类型：逻辑型
  意思：是否成功关闭并且销毁SSL服务数据
备注：
************************************************************************/
extern "C" bool Cryption_Server_StopEx(XHANDLE xhToken);
/************************************************************************/
/*                 SSL客户端导出定义                                    */
/************************************************************************/
/********************************************************************
函数名称：Cryption_Client_Init
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
 参数.六：nCertType
  In/Out：In
  类型：整数型
  可空：Y
  意思：1为PEM,2为ANS1
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：证书文件三个参数要么全部为NULL,要么参数lpszCertFile为NULL那么参数一就是使用证书链
*********************************************************************/
extern "C" XHANDLE Cryption_Client_InitEx(XSHOT enProtocol = XENGINE_CRYPTION_PROTOCOL_TLS, bool bSSocket = true, LPCXSTR lpszCACertFile = NULL, LPCXSTR lpszCertFile = NULL, LPCXSTR lpszPrivateKey = NULL, XSHOT nCertType = 1);
/********************************************************************
函数名称：Cryption_Client_Config
函数功能：启用协议配置
 参数.一：lpszConfigStr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要启用的配置字符串,默认是SRTP_AES128_CM_SHA1_80
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Client_ConfigEx(XHANDLE xhNet, LPCXSTR lpszConfigStr = NULL);
/********************************************************************
函数名称：Cryption_Client_Connect
函数功能：连接到SSL服务
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：输入你已经创建好连接的套接字句柄
 参数.二：ptszSslSubJect
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出证书主体名称
 参数.三：ptszSslIssuer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出证书发行者名称
 参数.四：ptszSslAlgorithm
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出加密算法
返回值
  类型：逻辑型
  意思：是否成功
备注：网络事件你需要自己处理
*********************************************************************/
extern "C" bool Cryption_Client_ConnectEx(XHANDLE xhNet, XSOCKET hSocket, XCHAR* ptszSslSubJect = NULL, XCHAR* ptszSslIssuer = NULL, XCHAR* ptszSslAlgorithm = NULL);
/********************************************************************
函数名称：Cryption_Client_GetKey
函数功能：目前支持DTSL的AES KEY获取
 参数.一：ptszKEYBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出密钥缓冲区
 参数.二：lpszKeyTStr
  In/Out：Out
  类型：常量字符指针
  可空：Y
  意思：输入密钥获取类型字符串
 参数.三：nKeySize
  In/Out：In
  类型：整数型
  可空：Y
  意思：根据密钥不同加密算法不同大小也不一样,DTSL-AES128的大小是30字节
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Client_GetKeyEx(XHANDLE xhNet, XBYTE* ptszKEYBuffer, LPCXSTR lpszKeyTStr = _X("EXTRACTOR-dtls_srtp"), int nKeySize = 30);
/********************************************************************
函数名称：Cryption_Client_SendMsg
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
 参数.五：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：最后两个参数可以参考服务器的函数说明,如果你是异步套接字,可能需要自定义收发数据套接字
      而不是由系统来处理收发
*********************************************************************/
extern "C" bool Cryption_Client_SendMsgEx(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nLen, XCHAR* ptszMsgBuffer = NULL, int* pInt_MsgLen = NULL, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Client_SendMemory
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
 参数.五：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Client_SendMemoryEx(XHANDLE xhNet, LPCXSTR lpszMsgBuffer, int nMsgLen, XCHAR** pptszMsgBuffer, int* pInt_MsgLen, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Client_RecvMsg
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
 参数.五：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Client_RecvMsgEx(XHANDLE xhNet, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0, int nTimeout = 0);
/********************************************************************
函数名称：Cryption_Client_RecvMemory
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
 参数.五：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入超时时间,单位毫秒,0不启用
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Cryption_Client_RecvMemoryEx(XHANDLE xhNet, XCHAR** pptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0, int nTimeout = 0);
/************************************************************************
函数名称：Cryption_Client_Close
函数功能：关闭SSL客户端
返回值
  类型：逻辑型
  意思：是否成功关闭客户端
备注：
************************************************************************/
extern "C" bool Cryption_Client_CloseEx(XHANDLE xhNet);
/************************************************************************/
/*                       X加解密                                        */
/************************************************************************/
/********************************************************************
函数名称：Cryption_XCrypto_Encoder
函数功能：X加密函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要加密的缓冲区
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要加密缓冲区大小,输出加密后的缓冲区大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出加密好的缓冲区
 参数.四：lpszKeys
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要加密的密码,如果为空表示这个数据不需要单独的密码加密
 参数.五：bXEngineHdr
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否包含XEngine的协议头,方便用于区分加密信息,可以不带就设置否
返回值
  类型：逻辑型
  意思：是否成功
备注：bXEngineHdr为false,大小输入多少就是多少
*********************************************************************/
extern "C" bool Cryption_XCrypto_Encoder(LPCXSTR lpszMsgBuffer, int* pInt_MsgLen, XBYTE* ptszMsgBuffer, LPCXSTR lpszKeys = NULL, bool bXEngineHdr = true);
/********************************************************************
函数名称：Cryption_XCrypto_Decoder
函数功能：X解密函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解密的缓冲区
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入要解密缓冲区大小,输出解密后的缓冲区大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解密好的缓冲区
 参数.四：lpszKeys
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要解密的密码,如果为空表示这个数据没有密码
 参数.五：bXEngineHdr
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否包含XEngine的协议头,方便用于区分加密信息,可以不带就设置否
返回值
  类型：逻辑型
  意思：是否成功
备注：bXEngineHdr为false,大小输入多少就是多少
*********************************************************************/
extern "C" bool Cryption_XCrypto_Decoder(LPCXSTR lpszMsgBuffer, int* pInt_MsgLen, XCHAR* ptszMsgBuffer, LPCXSTR lpszKeys = NULL, bool bXEngineHdr = true);