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
//                        导出的枚举型
//////////////////////////////////////////////////////////////////////////
//访问类型
typedef enum en_APIHelp_DomainType
{
    ENUM_NETHELP_APIADDR_DOMAIN_TYPE_UNKOW = 0,                                      //未知类型
    ENUM_NETHELP_APIADDR_DOMAIN_TYPE_HTTP = 1,                                       //HTTP访问
    ENUM_NETHELP_APIADDR_DOMAIN_TYPE_HTTPS = 2                                       //HTTPS访问
}ENUM_NETHELP_APIADDR_DOMAIN_TYPE, *LPENUM_NETHELP_APIADDR_DOMAIN_TYPE;
//IPV4范围分类
typedef enum
{
	ENUM_NETHELP_APIADDR_IPV4_TYPE_UNKNOW = 0,
	ENUM_NETHELP_APIADDR_IPV4_TYPE_A = 1,
	ENUM_NETHELP_APIADDR_IPV4_TYPE_B = 2,
	ENUM_NETHELP_APIADDR_IPV4_TYPE_C = 3,
	ENUM_NETHELP_APIADDR_IPV4_TYPE_D = 4,
	ENUM_NETHELP_APIADDR_IPV4_TYPE_E = 5
}ENUM_NETHELP_APIADDR_IPV4_TYPE, * LPENUM_NETHELP_APIADDR_IPV4_TYPE;
//IPV6地址类型
typedef enum
{
	ENUM_NETHELP_APIADDR_IPV6_TYPE_UNKNOW = 0,
	ENUM_NETHELP_APIADDR_IPV6_TYPE_NOAMAL = 1,                           //常规地址
	ENUM_NETHELP_APIADDR_IPV6_TYPE_ABBREVIATION = 2,                     //经过压缩的地址
	ENUM_NETHELP_APIADDR_IPV6_TYPE_MAPPING = 3,                          //IPV4映射地址
	ENUM_NETHELP_APIADDR_IPV6_TYPE_COMPATBLE = 4                         //IPV4兼容地址
}ENUM_NETHELP_APIADDR_IPV6_TYPE, * LPENUM_NETHELP_APIADDR_IPV6_TYPE;
//IP地址类型
typedef enum
{
	ENUM_NETHELP_APIADDR_IP_TYPE_UNKNOW = 0,
	ENUM_NETHELP_APIADDR_IP_TYPE_LOOP = 1,                           //回环地址
	ENUM_NETHELP_APIADDR_IP_TYPE_UNICAST = 2,                        //单播地址
	ENUM_NETHELP_APIADDR_IP_TYPE_GROUPCAST = 3,                      //组播地址
	ENUM_NETHELP_APIADDR_IP_TYPE_BROADCAST = 4,                      //广播地址,IPV6本地链路,用于邻里发现
	ENUM_NETHELP_APIADDR_IP_TYPE_LAN = 5,                            //内网地址,IPV6表示私有地址,不参与全球通信
}ENUM_NETHELP_APIADDR_IP_TYPE, * LPENUM_NETHELP_APIADDR_IP_TYPE;
//////////////////////////////////////////////////////////////////////////
//                        导出的数据结构
//////////////////////////////////////////////////////////////////////////
//URL地址信息
typedef struct 
{
    int nPort;                                                           //端口
    XCHAR tszTopDomain[XPATH_MAX];                                         //顶级域名
    XCHAR tszMainDomain[XPATH_MAX];                                        //主域名
    XCHAR tszDomainName[XPATH_MAX];                                        //域名名称
    XCHAR tszSubDomain[XPATH_MAX];                                         //子域名
    XCHAR tszFullDomain[XPATH_MAX];                                        //完整域名
}APIADDR_DOMAIN, *LPAPIADDR_DOMAIN;
//地址结构体,支持IPV4和IPV6.如果是IPV4,那么只有1-4成员有效,如果是IPV6,所有都有效,并且是16进制表示
//如果是IPV6压缩模式,那么根据有值的内容确定压缩位置,比如FF01::1,有值的就是IP1,IP3,IP2为空表示中间压缩
typedef struct
{
	int nIPAddr1;
	int nIPAddr2;
	int nIPAddr3;
	int nIPAddr4;
	int nIPAddr5;
	int nIPAddr6;
	int nIPAddr7;
	int nIPAddr8;
	int nIPVer;                                                                  //IP版本,AF_INET(2) AF_INET6(23)
}APIADDR_IPADDR, * LPAPIADDR_IPADDR;
//////////////////////////////////////////////////////////////////////////
//                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG APIAddr_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                          URL解析器导出的函数                                   *
*********************************************************************************/
/********************************************************************
函数名称：APIAddr_Domain_GetInfo
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
extern "C" bool APIAddr_Domain_GetInfo(LPCXSTR lpszUrl, APIADDR_DOMAIN *pSt_APIUrl, ENUM_NETHELP_APIADDR_DOMAIN_TYPE *penUrlType, XCHAR *ptszUrlPath = NULL);
/********************************************************************
函数名称：APIAddr_Domain_GetField
函数功能：获取一个URL的分段信息
 参数.一：lpszUrlStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要分割的URL字符串
 参数.二：ptszProtocolStr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出协议名称,比如http https udp 等等
 参数.三：ptszDomainStr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出域名地址
 参数.四：pInt_Port
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出端口号,如果有的话
 参数.五：ptszExternStr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出后续扩展地址
返回值
  类型：逻辑型
  意思：是否成功
备注：srt://app.xyry.org:5610/live/qyt就会变成 srt app.xyry.org 5610 /live/qyt
*********************************************************************/
extern "C" bool APIAddr_Domain_GetField(LPCXSTR lpszUrlStr, XCHAR* ptszProtocolStr, XCHAR* ptszDomainStr, int* pInt_Port = NULL, XCHAR* ptszExternStr = NULL);
/*********************************************************************************
*                          电子邮件解析器导出的函数                              *
*********************************************************************************/
/********************************************************************
函数名称：APIAddr_EMail_IsEMailAddr
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
extern "C" bool APIAddr_EMail_IsEMailAddr(LPCXSTR lpszEMailAddr);
/********************************************************************
函数名称：APIAddr_EMail_GetName
函数功能：获取电子邮件的名称和域名
 参数.一：lpszEMailAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的电子邮件地址
 参数.二：ptszNameStr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出邮件名称
 参数.三：ptszDomainStr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出邮件域名
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_EMail_GetName(LPCXSTR lpszEMailAddr, XCHAR* ptszNameStr = NULL, XCHAR* ptszDomainStr = NULL);
/************************************************************************/
/*                         IP地址操作                                   */
/************************************************************************/
/********************************************************************
函数名称：APIAddr_IPAddr_SegAddr
函数功能：网络地址分割
 参数.一：ptszAddr
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入：要分解的IP+端口缓冲区，输出IP地址
 参数.二：pInt_Port
  In/Out：Out
  类型：整数型
  可空：Y
  意思：导出分解后的端口
返回值
  类型：逻辑型
  意思：是否分解成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_SegAddr(XCHAR* ptszAddr, int* pInt_Port = NULL);
/********************************************************************
函数名称：APIAddr_IPAddr_GetIPVer
函数功能：获得IP版本
 参数.一：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的地址
 参数.二：pInt_IPVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出IP地址版本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_GetIPVer(LPCXSTR lpszIPAddr, int* pInt_IPVer);
/********************************************************************
函数名称：APIAddr_IPAddr_GetIPV4Type
函数功能：获取IPV4地址类型
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入地址结构
 参数.二：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出地址类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_GetIPV4Type(APIADDR_IPADDR* pSt_LibAddr, ENUM_NETHELP_APIADDR_IP_TYPE* penIPType);
/********************************************************************
函数名称：APIAddr_IPAddr_GetIPV6Type
函数功能：获取IPV6地址类型
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入地址结构
 参数.二：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出地址类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_GetIPV6Type(APIADDR_IPADDR* pSt_LibAddr, ENUM_NETHELP_APIADDR_IP_TYPE* penIPType);
/********************************************************************
函数名称：APIAddr_IPAddr_IsIPV4Addr
函数功能：判断一个缓冲区是否为IP地址
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要判断的缓冲区
 参数.二：pSt_LibAddr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：导出IP分割的地址值
 参数.三：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：Y
  意思：导出此IP地址的分类
返回值
  类型：逻辑型
  意思：返回真表示是IP地址，返回假请获取错误码
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_IsIPV4Addr(LPCXSTR lpszMsgBuffer, APIADDR_IPADDR* pSt_LibAddr = NULL, ENUM_NETHELP_APIADDR_IPV4_TYPE* penIPType = NULL);
/********************************************************************
函数名称：APIAddr_IPAddr_IsIPV6Addr
函数功能：是否为IPV6地址
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：pSt_LibAddr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出解析的地址结构
 参数.三：penIPType
  In/Out：Out
  类型：枚举型指针
  可空：Y
  意思：输出IPV6地址类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_IsIPV6Addr(LPCXSTR lpszMsgBuffer, APIADDR_IPADDR* pSt_LibAddr = NULL, ENUM_NETHELP_APIADDR_IPV6_TYPE* penIPType = NULL);
/********************************************************************
函数名称：APIAddr_IPAddr_ExpIPV6Addr
函数功能：扩展IPV6地址
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要扩展IP地址结构
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出扩展的IP地址
 参数.三：bFill
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否填充到4位数
 参数.四：bSymbol
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否添加:符号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_ExpIPV6Addr(APIADDR_IPADDR* pSt_LibAddr, XCHAR* ptszIPAddr, bool bFill = false, bool bSymbol = true);
/********************************************************************
函数名称：APIAddr_IPAddr_ComIPV6Addr
函数功能：压缩IPV6地址
 参数.一：pSt_LibAddr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要扩展IP地址结构
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出压缩的IP地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_ComIPV6Addr(APIADDR_IPADDR* pSt_LibAddr, XCHAR* ptszIPAddr);
/********************************************************************
函数名称：APIAddr_IPAddr_IPConvertInt
函数功能：IP字符串转整数
 参数.一：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要转换的字符串
 参数.二：pInt_IPAddr
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出转换后的数据,如果是ipv6,需要提供int[4]的大小数组整数
 参数.三：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入IP版本,默认IPV4
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_IPConvertInt(LPCXSTR lpszIPAddr, XUINT* pInt_IPAddr, int nIPVer = 2);
/********************************************************************
函数名称：APIAddr_IPAddr_IPConvertStr
函数功能：IP证书转字符串
 参数.一：pInt_IPAddr
  In/Out：In
  类型：整数型指针
  可空：N
  意思：要转换的IP地址,IPV6需要int[4]
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出转换后的数据
 参数.三：nIPVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入IP版本,默认IPV4
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIAddr_IPAddr_IPConvertStr(XUINT* pInt_IPAddr, XCHAR* ptszIPAddr, int nIPVer = 2);