#pragma once
/********************************************************************
//	Created:	2019/1/29   11:04
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_Snmp\RfcSnmp_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_Snmp
//	File Base:	RfcSnmp_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	SNMP导出函数定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         导出的类型
//////////////////////////////////////////////////////////////////////////
#define NETENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V1 0x0001
#define NETENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V2 0x0011
#define NETENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V3 0x0101
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_RfcSnmp_VariableList
{
    TCHAR tszName[128];
    TCHAR tszValue[128];
}RFCSNMP_VARIABLELIST;
//////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD SnmpProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                         SNMP客户端导出函数                           */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_SnmpClient_Init
函数功能：初始化SNMP客户端
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出初始化成功的客户端句柄
 参数.二：lpszPeerAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的地址,可以是本地或者远程
 参数.三：lpsCommName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：共同体名称
 参数.四：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：用户名
 参数.五：lpszPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：密码
 参数.六：dwProtoType
  In/Out：In
  类型：双字
  可空：Y
  意思：客户端协议版本
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpClient_Init(XNETHANDLE *pxhNet, LPCTSTR lpszPeerAddr, LPCTSTR lpsCommName, LPCTSTR lpszUser = NULL, LPCTSTR lpszPass = NULL, DWORD dwProtoType = NETENGINE_RFCCOMPONENTS_SNMP_PROTOCOL_V1);
/********************************************************************
函数名称：RfcComponents_SnmpClient_PDUGet
函数功能：通过一个OID获取他的值
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：lpszOIDString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：OID唯一编码
 参数.三：pppSt_ListVar
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的信息
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出信息列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数三需要调用基础库的内存释放函数BaseLib_OperatorMemory_Free来释放内存
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpClient_PDUGet(XNETHANDLE xhNet, LPCSTR lpszOIDString, RFCSNMP_VARIABLELIST * **pppSt_ListVar, int* pInt_ListCount);
/********************************************************************
函数名称：RfcComponents_SnmpClient_PDUSet
函数功能：通过一个OID设置他的值
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的客户端
 参数.二：lpszOIDString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：OID唯一编码
 参数.三：cType
  In/Out：In
  类型：字符
  可空：N
  意思：输入要修改的类型
 参数.四：lpszValue
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要修改的值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpClient_PDUSet(XNETHANDLE xhNet, LPCTSTR lpszOIDString, TCHAR cType, LPCTSTR lpszValue);
/********************************************************************
函数名称：RfcComponents_SnmpClient_Close
函数功能：关闭一个SNMP客户端并且释放资源
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_SnmpClient_Close(XNETHANDLE xhNet);
