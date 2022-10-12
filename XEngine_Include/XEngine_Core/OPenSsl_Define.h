#pragma once
/********************************************************************
//	Created:	2011/7/18  20:53
//	Filename: 	j:\U_DISK_Path\NetSocketEngine\CryptOpenSSL\OpenSSL_OutDefine.h
//	File Path:	j:\U_DISK_Path\NetSocketEngine\CryptOpenSSL
//	File Base:	OpenSSL_OutDefine
//	File Ext:	h
//      Project:        NetSocketEnginer(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	网络通信引擎PKI开发组件导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                   导入定义
//////////////////////////////////////////////////////////////////////////
//SSL证书文件证书编码类型
#define XENGINE_OPENSSL_OPENSSL_PEM_FILE 1                              //PEM编码格式：BASE64。调用者无需关心编码实现部分，只需要传递即可
#define XENGINE_OPENSSL_OPENSSL_ASN1_FILE 2                             //ASN1编码格式：DER
//////////////////////////////////////////////////////////////////////////
//        数据类型定义
//////////////////////////////////////////////////////////////////////////
//摘要算法库
typedef enum en_XEngine_OpenSsl_Digest
{
    XENGINE_OPENSSL_API_DIGEST_MD4 = 1,                                 //MD4摘要算法
    XENGINE_OPENSSL_API_DIGEST_MD5,                                     //MD5摘要算法
    XENGINE_OPENSSL_API_DIGEST_SHA1,                                    //SHA1摘要算法
    XENGINE_OPENSSL_API_DIGEST_SHA256,                                  //SHA256摘要算法
    XENGINE_OPENSSL_API_DIGEST_SHA512,                                  //SHA512摘要算法
    XENGINE_OPENSSL_API_DIGEST_RIPEMD160,                               //RIPEMD160摘要算法
    XENGINE_OPENSSL_API_DIGEST_SM3                                      //国标SM3
}ENUM_XENGINE_OPENSSL_DIGEST,*LPENUM_XENGINE_OPENSSL_DIGEST;
//非对称加解密库
typedef enum en_XEngine_OpenSsl_Crypt
{
    XENGINE_OPENSSL_API_CRYPT_AES = 1,                                  //AES加解密
    XENGINE_OPENSSL_API_CRYPT_DES = 2,                                  //DES加解密
    XENGINE_OPENSSL_API_CRYPT_3DES = 3,                                 //3DES加解密算法
    XENGINE_OPENSSL_API_CRYPT_RC4 = 4,                                  //RC4加解密
    XENGINE_OPENSSL_API_CRYPT_SM3 = 10,                                 //GBSM3算法
    //下面的定义在CENTOS下暂时不支持
    XENGINE_OPENSSL_API_CRYPT_SMCBC = 11,                               //GBSM4_CBC算法
    XENGINE_OPENSSL_API_CRYPT_SMCFB = 12,                               //同
    XENGINE_OPENSSL_API_CRYPT_SMCFB128 = 13,                            //同
    XENGINE_OPENSSL_API_CRYPT_SMCTR = 14                                //同属GBSM4算法类
}ENUM_XENGINE_OPENSSL_CRYPT,*LPENUM_XENGINE_OPENSSL_CRYPT;
//SSL安全传输协议库,用于服务器
typedef enum en_XEngine_OpenSsl_Protocol
{
    XENGINE_OPENSSL_PROTOCOL_SSL_SERVER,                                //同时支持SSL V2和V3版本的协议
    XENGINE_OPENSSL_PROTOCOL_TLS_SERVER,                                //TLS V1 V2协议
    XENGINE_OPENSSL_PROTOCOL_DTL_SERVER                                 //DTL V1 V2协议
}ENUM_XENGINE_OPENSSL_PROTOCOL,*LPENUM_XENGINE_OPENSSL_PROTOCOL;
//证书查询内部结构体
typedef struct tag_NetEngine_OpenSsl_X509CCInl
{
    CHAR tszCountryName[128];                                            //国家
    CHAR tszProvinceName[128];                                           //省
    CHAR tszLocalityName[128];                                           //地区
    CHAR tszOrganizationName[128];                                       //组织
    CHAR tszOrgUnitName[128];                                            //单位
    CHAR tszCommonName[128];                                             //通用名
    CHAR tszEmailAddress[128];                                           //电子邮件
    struct
    {
        CHAR tszName[128];                                               //名字
        CHAR tszTitle[128];                                              //头衔
        CHAR tszDesCription[128];                                        //描述
    }st_ExtInfo;                                                         //可空信息
}OPENSSL_X509CCINL,*LPOPENSSL_X509CCINL;
//查询证书信息函数输入结构体，输出结构体
typedef struct tag_OpenSSL_X509CCInfo
{
    int nCertType;                                                        //证书类型,1用于加密,2用于签名
    long lVersion;                                                        //保存证书版本
    time_t nTimeStart;                                                    //证书生效时间
    time_t nTimeEnd;                                                      //证书过期时间
    CHAR tszSerialNumber[64];                                             //证书序列号
    CHAR tszAlgorithm[64];                                                //签名算法
    CHAR tszPubKey[1024];                                                 //证书的公钥
    CHAR tszPriKey[1024];                                                 //证书的私钥

    OPENSSL_X509CCINL st_Issuer;                                          //证书颁发者信息
    OPENSSL_X509CCINL st_SubJect;                                         //证书拥有者信息
}OPENSSL_X509CCINFO,*LPOPENSSL_X509CCINFO;
//查询证书信息函数输入结构体，输出结构体
typedef struct
{
    CHAR tszExtName[256];                                                 //名称
    CHAR tszExtValue[256];                                                //值
}OPENSSL_X509EXT, *LPOPENSSL_X509EXT;
//////////////////////////////////////////////////////////////////////////
//               函数导出定义
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD OPenSsl_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*               数据编码算法导出函数                                      */
/************************************************************************/
/********************************************************************
函数名称：OPenSsl_Codec_UrlEnCodec
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
extern "C" void OPenSsl_Codec_UrlEnCodec(LPCSTR lpszSource,int nLen,CHAR *ptszDest);
/********************************************************************
函数名称：OPenSsl_Codec_UrlDeCodec
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
extern "C" void OPenSsl_Codec_UrlDeCodec(LPCSTR lpszSource,int nLen,CHAR *ptszDest);
/********************************************************************
函数名称：OPenSsl_Codec_Base64
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
extern "C" BOOL OPenSsl_Codec_Base64(LPCSTR lpszSource,CHAR *ptszDest,int *pInt_Len,BOOL bIsEnCodec = TRUE, BOOL bIsLine = FALSE);
/********************************************************************
函数名称：OPenSsl_Codec_CRC32Codec
函数功能：CRC32公开算法文件获取源码
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
 参数.三：ptszBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出编码好的数据
返回值
  类型：逻辑型
  意思：是否编码成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Codec_CRC32Codec(LPCSTR lpszSource,int nSize,CHAR *ptszBuffer);
/********************************************************************
函数名称：OPenSsl_Codec_2BytesToBCD
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
extern "C" void OPenSsl_Codec_2BytesToBCD(LPCSTR lpszSource,UCHAR &chBCD);
/********************************************************************
函数名称：OPenSsl_Codec_BCDTo2Bytes
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
extern "C" void OPenSsl_Codec_BCDTo2Bytes(UCHAR chBCD,CHAR *ptszDest);
/********************************************************************
函数名称：OPenSsl_Codec_BCDToInt
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
extern "C" int OPenSsl_Codec_BCDToInt(UCHAR chBCD);
/********************************************************************
函数名称：OPenSsl_Codec_IntToBCD
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
extern "C" UCHAR OPenSsl_Codec_IntToBCD(UCHAR uszInt);
/************************************************************************/
/*               OPENSSL加解密算法API                                   */
/************************************************************************/
/************************************************************************
函数名称：OPenSsl_Api_CryptEncodec
函数功能：非对称加密
 参数一：lpszEnCodecString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待加密的数据
 参数二：ptszOutCodec
  In/Out：In/Out
  类型：无符号字符指针
  可空：N
  意思：加密后的字符指针，请不要尝试做任何编码转换。编码转换肯定认不出这个数据内容
 参数三：pInt_StrLen
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
extern "C" BOOL OPenSsl_Api_CryptEncodec(LPCSTR lpszEnCodecString,UCHAR *ptszOutCodec,int *pInt_StrLen,LPCSTR lpszKey,ENUM_XENGINE_OPENSSL_CRYPT en_CryptType = XENGINE_OPENSSL_API_CRYPT_3DES);
/************************************************************************
函数名称：OPenSsl_Api_CryptDecodec
函数功能：非对称解密函数
 参数一：lpszDeCodecString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待解密的加密数据
 参数二：ptszOutCodec
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：解密后的数据，初始化足够的大小。返回解密后的数据
 参数三：pInt_StrLen
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
extern "C" BOOL OPenSsl_Api_CryptDecodec(const UCHAR *lpszDeCodecString,CHAR *ptszOutCodec,int *pInt_StrLen,LPCSTR lpszKey,ENUM_XENGINE_OPENSSL_CRYPT en_CryptType = XENGINE_OPENSSL_API_CRYPT_3DES);
/************************************************************************
函数名称：OPenSsl_Api_Digest
函数功能：信息摘要算法实现函数
 参数一：lpszMD_Value
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要加密的数据
 参数二：ptszStr_Value
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
extern "C" BOOL OPenSsl_Api_Digest(LPCSTR lpszMD_Value,UCHAR *ptszStr_Value,int *pInt_Len,BOOL bIsFile = FALSE,DWORD dwDigestLib = XENGINE_OPENSSL_API_DIGEST_MD5);
/********************************************************************
函数名称：OPenSsl_Api_RsaGenerater
函数功能：生成RSA公钥和私钥文件
 参数.一：lpszPubFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要保存的公钥文件路径
 参数.二：lpszPriFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要保存的私钥文件路径，如果这个文件存在，将为其在增加一个公钥。
 参数.三：lpszPriPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要加密的私钥密码,可以不加密
返回值
  类型：逻辑型
  意思：是否生成成功
备注：RSA的私钥和公钥都可以用来加解密，但是他们的加解密的KEY要对称公钥加密-私钥解密 或者 私钥加密-公钥解密
*********************************************************************/
extern "C" BOOL OPenSsl_Api_RsaGenerater(LPCSTR lpszPubFile,LPCSTR lpszPriFile, LPCSTR lpszPriPass = NULL);
/********************************************************************
函数名称：OPenSsl_Api_RsaEnCodec
函数功能：RSAKEY加密数据
 参数.一：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：KEY文件路径
 参数.二：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要加密的原始数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：原始数据长度，输出加密后的数据长度
 参数.四：ptszDest
  In/Out：Out
  类型：无符号字符指针
  可空：N
  意思：输出加密后的数据
 参数.五：bKeyType
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真表示使用公钥加密，为假表示使用私钥加密
 参数.六：lpszPriPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果私钥加过密,那么必须输入私钥密码
返回值
  类型：逻辑型
  意思：是否加密成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Api_RsaEnCodec(LPCSTR lpszKeyFile,LPCSTR lpszSource,int *pInt_Len,UCHAR *ptszDest,BOOL bKeyType = TRUE, LPCSTR lpszPriPass = NULL);
/********************************************************************
函数名称：OPenSsl_Api_RsaDeCodec
函数功能：使用RSAKEY解密数据
 参数.一：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：KEY文件路径
 参数.二：puszSource
  In/Out：In
  类型：常量无符号字符指针
  可空：N
  意思：要解密的原始数据
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：原始数据长度，输出解密后的数据长度
 参数.四：ptszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解密后的数据
 参数.五：bKeyType
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真表示使用公钥解密，为假表示使用私钥解密
 参数.六：lpszPriPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果私钥加过密,那么必须输入私钥密码
返回值
  类型：逻辑型
  意思：是否解密成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Api_RsaDeCodec(LPCSTR lpszKeyFile,const UCHAR *puszDest,int *pInt_Len,CHAR *ptszDest,BOOL bKeyType = TRUE, LPCSTR lpszPriPass = NULL);
/************************************************************************/
/*                 证书操作导出函数                                     */
/************************************************************************/
/********************************************************************
函数名称：OPenSsl_Cert_SignEncoder
函数功能：签名数据
 参数.一：lpszSignSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要签名的数据
 参数.二：ptszSignDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入足够大缓冲区，输出验证后的内容
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入，签名数据大小，输出，签名后的数据大小
 参数.四：dwDigestLib
  In/Out：In
  类型：双字
  可空：Y
  意思：为空取MD5，摘要算法
返回值
  类型：逻辑型
  意思：是否签名成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Cert_SignEncoder(LPCSTR lpszKeyFile, LPCSTR lpszKeyPass, LPCSTR lpszSignSource, CHAR *ptszSignDest, int *pInt_Len, DWORD dwDigestLib = XENGINE_OPENSSL_API_DIGEST_MD5);
/********************************************************************
函数名称：OPenSsl_Cert_DignVerifly
函数功能：验证签名
 参数.一：lpszSignSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要验证的数据
 参数.二：ptszSignDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入足够大缓冲区，输出验证后的内容
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入，验证数据大小，输出，验证后的数据大小
 参数.四：dwDigestLib
  In/Out：In
  类型：双字
  可空：Y
  意思：为空取MD5，摘要算法
返回值
  类型：逻辑型
  意思：为真为验证成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Cert_SignVerifly(LPCSTR lpszKeyFile, LPCSTR lpszKeyPass, LPCSTR lpszSignSource, int nSrcLen, LPCSTR lpszSignDest, int nDstLen, DWORD dwDigestLib = XENGINE_OPENSSL_API_DIGEST_MD5);
/********************************************************************
函数名称：OPenSsl_Cert_MakeCACert
函数功能：制作一个CA证书,用于签发证书请求文件
 参数.一：lpszCertFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要生成的CA根证书保存目录
 参数.二：lpszKeyFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要生成的CA根证书的密钥目录
 参数.三：lpszKeyPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要生成证书私钥密码,如果不想设置密码,传递NULL
 参数.四：nBits
  In/Out：In
  类型：整数型
  可空：N
  意思：RSA长度.1024 2048
 参数.五：nlSerial
  In/Out：In
  类型：长整数型
  可空：N
  意思：密钥序列号
 参数.六：nlTimeSecond
  In/Out：In
  类型：长整数型
  可空：N
  意思：跟证书时间
 参数.七：pSt_X509CerInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要写入的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Cert_MakeCACert(LPCSTR lpszCertFile, LPCSTR lpszKeyFile, LPCSTR lpszKeyPass, int nBits, long nlSerial, long nlTimeSecond, OPENSSL_X509CCINL *pSt_X509CerInfo);
/********************************************************************
函数名称：OPenSsl_Cert_X509GenRequest
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
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Cert_X509GenRequest(LPCSTR lpszDstFile, OPENSSL_X509CCINL *pSt_X509CerInfo, LPCSTR lpszRSAKey, LPCSTR lpszKeyPass = NULL);
/********************************************************************
函数名称：OPenSsl_Cert_X509SignVer
函数功能：对一个证书请求文件进行签名验证
 参数.一：lpszCACert
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：CA根证书目录
 参数.二：lpszCAKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：CA根证书的密钥目录
 参数.三：lpszCAPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：证书的私钥密码,如果没有传递NULL
 参数.四：lpszREQFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：生成的请求文件路径
 参数.五：lpszREQPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：请求的文件密钥,如果没有传递NULL
 参数.六：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：签发后的证书保存路径
 参数.七：nlSerial
  In/Out：In
  类型：长整数型
  可空：N
  意思：密钥序列号
 参数.八：nlTimeSecond
  In/Out：In
  类型：长整数型
  可空：N
  意思：跟证书时间,单位秒
 参数.九：pppSt_ListExt
  In/Out：In
  类型：三级指针
  可空：Y
  意思：证书附加信息,这个内存应该由调用者申请释放
 参数.十：nListCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入整数信息个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Cert_X509SignVer(LPCSTR lpszCACert, LPCSTR lpszCAKey, LPCSTR lpszCAPass, LPCSTR lpszREQFile, LPCSTR lpszREQPass, LPCSTR lpszDstFile, long nlSerial, long nlTimeSecond, OPENSSL_X509EXT * **pppSt_ListExt = NULL, int nListCount = 0);
/********************************************************************
函数名称：OPenSsl_Cert_X509Verifly
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
返回值
  类型：逻辑型
  意思：证书是否验证成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Cert_X509Verifly(LPCSTR lpszCARoot, LPCSTR lpszCAUser);
/********************************************************************
函数名称：OPenSsl_Cert_GetCerInfomachine
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
extern "C" BOOL OPenSsl_Cert_GetCerInfomachine(LPCSTR lpszCerFile, LPOPENSSL_X509CCINFO pSt_X509CCInfo);
/************************************************************************/
/*                 SSL安全传输认证函数                                  */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：OPenSsl_Server_Init
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
 参数.四：enProtocol
  In/Out：In
  类型：枚举型
  可空：Y
  意思：默认支持SSL_V2和V3版本自动切换。枚举型里面的成员，协议类型
 参数.五：dwCoderType
  In/Out：In
  类型：双字
  可空：Y
  意思：编码类型，默认PEM编码
 参数.六：bVerPeer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：强制客户端使用证书,默认不需要
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：启用这个服务器，你可以使用安全的传输模式，你发送和接受到的数据都是明文，底层我们已经为你做好了加解密工作
*********************************************************************/
extern "C" XHANDLE OPenSsl_Server_InitEx(LPCSTR lpszCACert, LPCSTR lpszServerCert, LPCSTR lpszServerKey, BOOL bVerPeer = FALSE, BOOL bSSocket = TRUE, ENUM_XENGINE_OPENSSL_PROTOCOL enProtocol = XENGINE_OPENSSL_PROTOCOL_SSL_SERVER, DWORD dwCoderType = XENGINE_OPENSSL_OPENSSL_PEM_FILE);
/********************************************************************
函数名称：OPenSsl_Server_Accept
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
 参数.三：ptszSslSubJect
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端拥有的证书信息
 参数.四：ptszSslIssuer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端发布的整数型
 参数.五：ptszSslAlgorithm
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端拥有的加密算法
返回值
  类型：逻辑型
  意思：是否成功
备注：如果后面三个参数没有导出值,说明客户端没有使用证书连接
*********************************************************************/
extern "C" BOOL OPenSsl_Server_AcceptEx(XHANDLE xhToken, SOCKET hSocket, LPCSTR lpszClientAddr, CHAR * ptszSslSubJect = NULL, CHAR * ptszSslIssuer = NULL, CHAR * ptszSslAlgorithm = NULL);
/********************************************************************
函数名称：OPenSsl_Server_RecvMsgEx
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
  意思：如果bSSocket为FALSE,你RECV的数据需要投递给最后两个参数
 参数.五：nMsgLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小,输出接收到的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：如果使用自定义发送接受,那么后两个参数是你套接字接受的数据解码才能得到参数二和三
*********************************************************************/
extern "C" BOOL OPenSsl_Server_RecvMsgEx(XHANDLE xhToken, LPCSTR lpszClientAddr, CHAR * ptszMsgBuffer, int* pInt_MsgLen, LPCSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：OPenSsl_Server_RecvMemory
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
  意思：如果bSSocket为FALSE,你RECV的数据需要投递给最后两个参数
 参数.五：nMsgLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入提供的缓冲区大小,输出接收到的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：意思同OPenSsl_Server_Recv
*********************************************************************/
extern "C" BOOL OPenSsl_Server_RecvMemoryEx(XHANDLE xhToken, LPCSTR lpszClientAddr, CHAR** pptszMsgBuffer, int* pInt_MsgLen, LPCSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
/********************************************************************
函数名称：OPenSsl_Server_SendMsg
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
返回值
  类型：逻辑型
  意思：是否成功
备注：如果使用自定义发送接受,那么后两个参数才是导出要发送的数据,否则将直接发送
*********************************************************************/
extern "C" BOOL OPenSsl_Server_SendMsgEx(XHANDLE xhToken, LPCSTR lpszClientAddr,LPCSTR lpszMsgBuffer,int nLen, CHAR * ptszMsgBuffer = NULL, int* pInt_MsgLen = NULL);
/********************************************************************
函数名称：OPenSsl_Server_SendMemory
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
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_Server_SendMemoryEx(XHANDLE xhToken, LPCSTR lpszClientAddr, LPCSTR lpszMsgBuffer, int nLen, CHAR** pptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：OPenSsl_Server_GetSocket
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
extern "C" BOOL OPenSsl_Server_GetSocketEx(XHANDLE xhToken, LPCSTR lpszClientAddr, SOCKET* phSocket);
/************************************************************************
函数名称：OPenSsl_Server_CloseClient
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
extern "C" BOOL OPenSsl_Server_CloseClientEx(XHANDLE xhToken, LPCSTR lpszClientAddr);
/************************************************************************
函数名称：OPenSsl_Server_Stop
函数功能：关闭SSL服务器
返回值
  类型：逻辑型
  意思：是否成功关闭并且销毁SSL服务数据
备注：
************************************************************************/
extern "C" BOOL OPenSsl_Server_StopEx(XHANDLE xhToken);
/************************************************************************/
/*                       X加解密                                        */
/************************************************************************/
/********************************************************************
函数名称：OPenSsl_XCrypto_Encoder
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
  可空：Y
  意思：输出加密好的缓冲区,如果此参数为NULL,参数二将被设置为需要的大小
 参数.四：lpszKeys
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要加密的密码,如果为空表示这个数据不需要单独的密码加密
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_XCrypto_Encoder(LPCSTR lpszMsgBuffer, int* pInt_MsgLen, UCHAR* ptszMsgBuffer = NULL, LPCSTR lpszKeys = NULL);
/********************************************************************
函数名称：OPenSsl_XCrypto_Decoder
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
 参数.三：ptszDest
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出解密好的缓冲区,如果此参数为NULL,参数二将被设置为需要的大小
 参数.四：lpszKeys
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要解密的密码,如果为空表示这个数据没有密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL OPenSsl_XCrypto_Decoder(LPCSTR lpszMsgBuffer, int* pInt_MsgLen, CHAR* ptszMsgBuffer = NULL, LPCSTR lpszKeys = NULL);
/************************************************************************/
/*                       加解密帮助函数                                 */
/************************************************************************/
/********************************************************************
函数名称：OPenSsl_Help_BasicEncoder
函数功能：HTTP基本验证加密函数
 参数.一：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入用户名
 参数.二：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入密码
 参数.三：ptszMsgBuffer
  In/Out：In
  类型：字符指针
  可空：N
  意思：输出加密后的缓冲区
 参数.四：bADD
  In/Out：In
  类型：是否添加验证算法类型
  可空：N
  意思：输出加密后的缓冲区
返回值
  类型：逻辑型
  意思：是否成功
备注：格式:Basic BASE64
*********************************************************************/
extern "C" BOOL OPenSsl_Help_BasicEncoder(LPCSTR lpszUser, LPCSTR lpszPass, CHAR* ptszMsgBuffer, BOOL bADD = TRUE);
/********************************************************************
函数名称：OPenSsl_Help_BasicDecoder
函数功能：HTTP基本验证解密函数
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解密的缓冲区
 参数.二：ptszUser
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出用户名
 参数.三：ptszPass
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出密码
返回值
  类型：逻辑型
  意思：是否成功
备注：RfcComponents_HttpHelp_GetAuthInfo 返回的内容
      格式:Basic BASE64
*********************************************************************/
extern "C" BOOL OPenSsl_Help_BasicDecoder(LPCSTR lpszMsgBuffer, CHAR* ptszUser, CHAR* ptszPass);
/********************************************************************
函数名称：OPenSsl_Help_Digest
函数功能：摘要计算函数
 参数.一：ptszResponseStr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出计算后的RESPONSE字符串
 参数.二：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入用户名
 参数.三：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入密码
 参数.四：lpszRealm
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入作用域,服务器发送的
 参数.五：lpszMethod
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的方法
 参数.六：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的URL地址
 参数.七：lpszNonce
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：服务器生成并且发送的
 参数.八：lpszCNonce
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：客户端生成的随机字符串
 参数.九：lpszNC
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：验证的次数,建议为NULL.
返回值
  类型：逻辑型
  意思：是否成功
备注：信息摘要支持QOP=AUTH 算法MD5的验证模式
*********************************************************************/
extern "C" BOOL OPenSsl_Help_Digest(CHAR* ptszResponseStr, LPCSTR lpszUser, LPCSTR lpszPass, LPCSTR lpszRealm, LPCSTR lpszMethod, LPCSTR lpszUrl, LPCSTR lpszNonce, LPCSTR lpszCNonce, LPCSTR lpszNC = NULL);