#pragma once
/********************************************************************
//    Created:     2025/07/04  17:11:31
//    File Name:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_DNSProtocol\DNSProtocol_Define.h
//    File Path:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_DNSProtocol
//    File Base:   DNSProtocol_Define
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     DNS导出协议
//    History:
*********************************************************************/
//查询类型
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_A 1         //A记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_NS 2        //NS记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_CNAME 5     //CNAME记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_SOA 6       //SOA记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_PTR 12      //PTR记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_MX 15       //MX记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_TXT 16      //TXT记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_AAAA 28     //AAAA记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_SRV 33      //SRV记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_ANY 255     //ANY记录
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_TYPE_NULL 0      //NULL记录
//查询类别
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_CLASS_IN 0x01    //网络地址,通用
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_CLASS_CH 0x02    //CS计算器系统
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_CLASS_HS 0x03    //Hesiod 名字服务协议
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_CLASS_ANY 0xFF   //任意类型
//DNS协议状态
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_STATUS_OK 0x00          //成功
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_STATUS_FORMAT 0x01      //报文格式错误
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_STATUS_SERVFAIL 0x02    //服务器失败
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_STATUS_NXDOMAIN 0x03    //域名不存在
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_STATUS_NOTIMP 0x04      //未实现
#define XENGINE_DNSPROTOCOL_QUERY_QUESTION_STATUS_REFUSED 0x05      //拒绝服务
//////////////////////////////////////////////////////////////////////////////////
//                         导出的结构
//////////////////////////////////////////////////////////////////////////////////
//查询内容
typedef struct
{
	XSHOT nNameType;                  //查询类型
	XSHOT nNameClass;                 //查询类别
}DNSPROTCOCOL_QUERYADDR;
typedef struct  
{
	XCHAR tszNameStr[128];               //查询的名称,也可能是别名
	XCHAR tszAddrStr[128];               //地址,也可能是CNAME.响应才有
	DNSPROTCOCOL_QUERYADDR st_QueryInfo;
	//响应独有
	int nTTL;                     //生存时间
}XENGINE_DNSPROTOCOL;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG DNSProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     DNS协议打包导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：DNSProtocol_Packet_REQHeader
函数功能：打包DNS请求协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的数据
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型
  可空：N
  意思：输出打包的大小
 参数.三：nRequestID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求ID
 参数.四：lpszQueryAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的查询地址
 参数.五：nQueryType
  In/Out：In
  类型：整数型
  可空：N
  意思：输入请求查询的类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DNSProtocol_Packet_REQHeader(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT nRequestID, LPCXSTR lpszQueryAddr, int nQueryType);
/********************************************************************
函数名称：DNSProtocol_Packet_REPHeader
函数功能：DNS请求响应打包协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nRequestID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入打包的消息ID
 参数.四：pSt_DNSRequest
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：打包的请求
 参数.五：pppSt_DNSAnswer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入响应消息列表
 参数.六：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：响应消息列表个数
 参数.七：bCompress
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否压缩
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数一般用于服务器响应请求
*********************************************************************/
extern "C" bool DNSProtocol_Packet_REPHeader(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT nRequestID, XENGINE_DNSPROTOCOL* pSt_DNSRequest, XENGINE_DNSPROTOCOL*** pppSt_DNSAnswer, int nListCount, bool bCompress = true);
/********************************************************************
函数名称：DNSProtocol_Packet_Error
函数功能：DNS打包错误响应协议
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：nRequestID
  In/Out：In
  类型：整数型
  可空：N
  意思：输入打包的消息ID
 参数.四：pSt_DNSRequest
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：打包的请求
 参数.五：pppSt_DNSAnswer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入响应消息列表
 参数.六：nError
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的错误码
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数一般用于服务器响应请求
*********************************************************************/
extern "C" bool DNSProtocol_Packet_Error(XCHAR* ptszMsgBuffer, int* pInt_Len, XSHOT nRequestID, XENGINE_DNSPROTOCOL* pSt_DNSRequest, XSHOT nError);
/************************************************************************/
/*                     DNS协议解析导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：DNSProtocol_Parse_Header
函数功能：DNS协议解析函数
 参数.一：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMSGLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入解析的大小
 参数.三：pInt_RequestID
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出消息ID
 参数四：pSt_DNSRequest
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出请求的消息
 参数.五：pppSt_DNSAnswer
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出响应的消息列表
 参数.六：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出响应的数量
返回值
  类型：逻辑型
  意思：是否成功
备注：ERROR_RFCCOMPONENTS_DNS_PROTOCOL_PARSE_SERVICE 错误会设置pInt_SysError获取错误函数的值
*********************************************************************/
extern "C" bool DNSProtocol_Parse_Header(LPCXSTR lpszMSGBuffer, int nMSGLen, int* pInt_RequestID, XENGINE_DNSPROTOCOL* pSt_DNSRequest, XENGINE_DNSPROTOCOL*** pppSt_DNSAnswer = NULL, int* pInt_ListCount = NULL);
/************************************************************************/
/*                     DNS协议帮助导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：DNSProtocol_Help_PTRStr
函数功能：PTR字符串解析
 参数.一：lpszMSGBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：ptszIPAddr
  In/Out：In
  类型：字符指针
  可空：N
  意思：输出解析到的IP地址
 参数.三：pInt_IPVer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DNSProtocol_Help_PTRStr(LPCXSTR lpszMSGBuffer, XCHAR* ptszIPAddr, int* pInt_IPVer);