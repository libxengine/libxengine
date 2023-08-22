#pragma once
/********************************************************************
//	Created:	2014/1/27  11:47
//	File Name: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_NetHelp/NetEngine_APIHelp/APIHelp_Define.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_NetHelp/NetEngine_APIHelp/
//	File Base:	APIHelp_Define.h
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎) For Linux
//	Author:		dowflyon
//	Purpose:	导出的网络帮助API函数库
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出的类型定义
//////////////////////////////////////////////////////////////////////////
#define XHtons APIHelp_NetWork_htons
#define XNtohs APIHelp_NetWork_ntohs
#define XHtonl APIHelp_NetWork_htonl
#define XNtohl APIHelp_NetWork_ntohl
#define XHtonl64 APIHelp_NetWork_hl64ton
#define XNtohl64 APIHelp_NetWork_ntohl64
//////////////////////////////////////////////////////////////////////////
//                        导出的枚举型
//////////////////////////////////////////////////////////////////////////
//访问类型
typedef enum en_APIHelp_DomainType
{
    ENUM_APIHELP_DOMAIN_TYPE_UNKOW = 0,                                      //未知类型
    ENUM_APIHELP_DOMAIN_TYPE_HTTP = 1,                                       //HTTP访问
    ENUM_APIHELP_DOMAIN_TYPE_HTTPS = 2                                       //HTTPS访问
}ENUM_APIHELP_DOMAINTYPE, *LPENUM_APIHELP_DOMAINTYPE;
//////////////////////////////////////////////////////////////////////////
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
//URL地址信息
typedef struct tag_APIHelp_Domain
{
    int nPort;                                                           //端口
    XCHAR tszTopDomain[MAX_PATH];                                         //顶级域名
    XCHAR tszMainDomain[MAX_PATH];                                        //主域名
    XCHAR tszDomainName[MAX_PATH];                                        //域名名称
    XCHAR tszSubDomain[MAX_PATH];                                         //子域名
    XCHAR tszFullDomain[MAX_PATH];                                        //完整域名
}APIHELP_DOMAIN, *LPAPIHELP_DOMAIN;
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG APIHelp_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          URL解析器导出的函数                                   *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_Domain_GetInfo
函数功能：获取URL信息
 参数.一：lpszUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：URL地址
 参数.二：pSt_APIUrl
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出解析完毕的URL结构
 参数.三：penUrlType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：导出获取到的访问类型
 参数.四：ptszUrlPath
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出域名的后续URL路径
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_Domain_GetInfo(LPCXSTR lpszUrl, APIHELP_DOMAIN *pSt_APIUrl, ENUM_APIHELP_DOMAINTYPE *penUrlType, XCHAR *ptszUrlPath = NULL);
/********************************************************************
函数名称：APIHelp_Domain_IsEMailAddr
函数功能：判断字符串是否是合法的EMAIL地址
 参数.一：lpszEMailAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要判断的缓冲区
返回值
  类型：逻辑型
  意思：返回真表示是,假不是
备注：
*********************************************************************/
extern "C" bool APIHelp_Domain_IsEMailAddr(LPCXSTR lpszEMailAddr);
/*********************************************************************************
*                          字节序转换导出函数                                    *
*********************************************************************************/
/********************************************************************
函数名称：APIHelp_NetWork_htons
函数功能：16位主机字节转网络字节序
 参数.一：nValue16
  In/Out：In
  类型：无符号16位整数
  可空：N
  意思：要转换的主机字节序
返回值
  类型：无符号16位整数
  意思：返回网络字节序
备注：
*********************************************************************/
extern "C" XSHOT APIHelp_NetWork_htons(XSHOT nValue16);
/********************************************************************
函数名称：APIHelp_NetWork_ntohs
函数功能：16位网络字节转主机字节序
 参数.一：nValue16
  In/Out：In
  类型：无符号16位整数
  可空：N
  意思：要转换的网络字节序
返回值
  类型：无符号16位整数
  意思：返回主机字节序
备注：
*********************************************************************/
extern "C" XSHOT APIHelp_NetWork_ntohs(XSHOT nValue16);
/********************************************************************
函数名称：APIHelp_NetWork_htonl
函数功能：32位主机字节转网络字节序
 参数.一：nValue32
  In/Out：In
  类型：无符号32位整数
  可空：N
  意思：要转换的主机字节序
返回值
  类型：无符号32位整数
  意思：返回网络字节序
备注：
*********************************************************************/
extern "C" XUINT APIHelp_NetWork_htonl(XUINT nValue32);
/********************************************************************
函数名称：APIHelp_NetWork_ntohl
函数功能：32位网络字节转主机字节序
 参数.一：nValue32
  In/Out：In
  类型：无符号32位整数
  可空：N
  意思：要转换的网络字节序
返回值
  类型：无符号32位整数
  意思：返回主机字节序
备注：
*********************************************************************/
extern "C" XUINT APIHelp_NetWork_ntohl(XUINT nValue32);
/********************************************************************
函数名称：APIHelp_NetWork_hl64ton
函数功能：64位主机字节转网络字节序
 参数.一：ullHost
  In/Out：In
  类型：无符号64位整数
  可空：N
  意思：要转换的主机字节序
返回值
  类型：无符号64位整数
  意思：返回网络字节序
备注：
*********************************************************************/
extern "C" __int64u APIHelp_NetWork_hl64ton(__int64u ullHost);
/********************************************************************
函数名称：APIHelp_NetWork_ntohl64
函数功能：64位网络字节转主机字节序
 参数.一：ullNet
  In/Out：In
  类型：无符号64位整数
  可空：N
  意思：要转换的网络字节序
返回值
  类型：无符号64位整数
  意思：返回主机字节序
备注：
*********************************************************************/
extern "C" __int64u APIHelp_NetWork_ntohl64(__int64u ullNet);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW8
函数功能：对一个字符指针写入一个指定字符到指定位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：byValue
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW8(XBYTE * ptszDest, XBYTE byValue);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW16
函数功能：写入一个16位数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue16
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW16(XBYTE * ptszDest, XSHOT nValue16, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW24
函数功能：写入一个24位数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue24
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW24(XBYTE * ptszDest, XUINT nValue24, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW32
函数功能：写入一个32位数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue24
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：支持float类型,要转换float需要按照此方式传递值
      APIHelp_NetWork_IntToHexW64(ptszDest, nPos, *(XUINT*)&nValue32);
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW32(XBYTE * ptszDest, XUINT nValue32, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW40
函数功能：写入一个40位数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue40
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW40(XBYTE* ptszDest, __int64u nValue40, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW48
函数功能：写入一个48位(6个字节)数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue48
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW48(XBYTE* ptszDest, __int64u nValue48, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW56
函数功能：写入一个56位(7个字节)数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue56
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW56(XBYTE* ptszDest, __int64u nValue56, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToHexW64
函数功能：写入一个64位数据到指定字符指针位置
 参数.一：ptszDest
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入要操作的字符指针,输出结果
 参数.二：nValue24
  In/Out：In
  类型：字符
  可空：N
  意思：输入要写入的值
 参数.三：bEndian
  In/Out：In
  类型：字符
  可空：N
  意思：输入的值是否需要转大小端,默认不转(主机字节序)
返回值
  类型：逻辑型
  意思：是否成功
备注：支持double类型,要转换double需要按照此方式传递值
      APIHelp_NetWork_IntToHexW64(ptszDest, nPos, *(__int64u*)&nValue64);
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToHexW64(XBYTE * ptszDest, __int64u nValue64, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR8Hex
函数功能：读取一个字节从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pbyValue
  In/Out：Out
  类型：字符串
  可空：N
  意思：输出读取到的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR8Hex(LPCXSTR lpszMsgBuffer, XBYTE * pbyValue);
/********************************************************************
函数名称：APIHelp_NetWork_ToR16Hex
函数功能：读取双字从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue16
  In/Out：Out
  类型：短整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR16Hex(LPCXSTR lpszMsgBuffer, XSHOT * pnValue16, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR24Hex
函数功能：读取3个字节整数型从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue32
  In/Out：Out
  类型：整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR24Hex(LPCXSTR lpszMsgBuffer, XUINT * pnValue24, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR32Hex
函数功能：读取整数型从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue32
  In/Out：Out
  类型：整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：支持float类型获取,直接强制转换即可
      APIHelp_NetWork_ToR64Hex(lpszMsgBuffer, (__int64u*)&flValue, bEndian);
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR32Hex(LPCXSTR lpszMsgBuffer, XUINT * pnValue32, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR40Hex
函数功能：读取整数型从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue40
  In/Out：Out
  类型：整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR40Hex(LPCXSTR lpszMsgBuffer, __int64u* pnValue40, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR48Hex
函数功能：读取48位(6字节)整数型从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue48
  In/Out：Out
  类型：64位整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR48Hex(LPCXSTR lpszMsgBuffer, __int64u* pnValue48, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR56Hex
函数功能：读取56位(7字节)整数型从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue56
  In/Out：Out
  类型：64位整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR56Hex(LPCXSTR lpszMsgBuffer, __int64u* pnValue56, bool bEndian = false);
/********************************************************************
函数名称：APIHelp_NetWork_ToR64Hex
函数功能：读取64位整数型从字符串中
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的字符串
 参数.二：pnValue64
  In/Out：Out
  类型：64位整数型
  可空：N
  意思：输出读取到的数据
 参数.三：bEndian
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要网络字节序转换,默认否
返回值
  类型：逻辑型
  意思：是否成功
备注：支持float类型获取,直接强制转换即可
      APIHelp_NetWork_ToR64Hex(lpszMsgBuffer, (__int64u*)&dlValue, bEndian);
*********************************************************************/
extern "C" bool APIHelp_NetWork_ToR64Hex(LPCXSTR lpszMsgBuffer, __int64u * pnValue64, bool bEndian = false);