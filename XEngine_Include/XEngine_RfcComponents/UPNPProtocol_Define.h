#pragma once
/********************************************************************
//	Created:	2020/04/01 14:43
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_UPnpProtocol
//	Filename: 	UPnpProtocol_Define.h
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	UPNP导出定义
//	History:
*********************************************************************/
typedef struct tag_UPnpProtocol_DeviceInfo
{
    CHAR tszDeivceType[128];                                             //设备类型
    CHAR tszFriendName[128];                                             //友好名
    CHAR tszManufacturer[64];                                            //制造商
    CHAR tszModeName[64];                                                //型号
}UPNPPROTOCOL_DEVICEINFO,*LPUPNPPROTOCOL_DEVICEINFO;
typedef struct tag_UPnpProtocol_MapList
{
    CHAR tszDescription[128];                                            //描述信息
    CHAR tszIntAddr[128];                                                //内部地址
    int nIntPort;                                                         //内部端口
    int nExtPort;                                                         //外部端口
    int nDuration;                                                        //过期时间
    int nIPProto;                                                         //协议类型
    BOOL bEnable;                                                         //是否启用
}UPNPPROTOCOL_MAPLIST, * LPUPNPPROTOCOL_MAPLIST;
//////////////////////////////////////////////////////////////////////////
//                导出函数定义
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD UPnpProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                UPNP客户端                                            */
/************************************************************************/
/********************************************************************
函数名称：UPnpProtocol_Client_Create
函数功能：创建UPNP客户端.控制节点
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建成功的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_Create(XNETHANDLE* pxhToken);
/********************************************************************
函数名称：UPnpProtocol_Client_Close
函数功能：关闭一个控制节点
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_Close(XNETHANDLE xhToken);
/********************************************************************
函数名称：UPnpProtocol_Client_MSearch
函数功能：搜索设备
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的控制节点
 参数.二：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入搜索时间,单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_MSearch(XNETHANDLE xhToken, int nTimeout = 5);
/********************************************************************
函数名称：UPnpProtocol_Client_GetCount
函数功能：获取找到几个设备
 参数.一：pInt_Count
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_GetCount(XNETHANDLE xhToken, int* pInt_Count);
/********************************************************************
函数名称：UPnpProtocol_Client_GetDeviceInfo
函数功能：获取设备信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：操作的UPNP句柄
 参数.二：pSt_DeviceInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的信息
 参数.三：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：获取的索引编号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_GetDeviceInfo(XNETHANDLE xhToken, UPNPPROTOCOL_DEVICEINFO* pSt_DeviceInfo, int nIndex = 0);
/********************************************************************
函数名称：UPnpProtocol_Client_GetCtrlInfo
函数功能：获取设备控制信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：操作的UPNP句柄
 参数.二：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要操作的设备索引
返回值
  类型：逻辑型
  意思：是否成功
备注：在操作一个设备前,必须获取控制信息,成功后才能进行操作,否则不能进行操作
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_GetCtrlInfo(XNETHANDLE xhToken, int nIndex = 0);
/********************************************************************
函数名称：UPnpProtocol_Client_GetExternalIPAddress
函数功能：获取外部IP地址
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的UPNP
 参数.二：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的IP地址
 参数.Y：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要操作的获取到的设备索引
返回值
  类型：逻辑型
  意思：是否成功
备注：UPnpProtocol_Client_GetWANIPConnect 是必须之前调用的
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_GetExternalIPAddress(XNETHANDLE xhToken, CHAR* ptszIPAddr, int nIndex = 0);
/********************************************************************
函数名称：UPnpProtocol_Client_GetMapping
函数功能：获取指定端口映射信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的UPNP控制端
 参数.二：In/Out
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输入端口和协议.输出其他值
 参数.三：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：要操作哪个设备
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_GetMapping(XNETHANDLE xhToken, UPNPPROTOCOL_MAPLIST* pSt_MapInfo, int nIndex = 0);
/********************************************************************
函数名称：UPnpProtocol_Client_AddMapping
函数功能：添加端口映射信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的UPNP控制端
 参数.二：pSt_MapInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输入要映射的信息
 参数.三：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：要操作哪个设备
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_AddMapping(XNETHANDLE xhToken, UPNPPROTOCOL_MAPLIST* pSt_MapInfo, int nIndex = 0);
/********************************************************************
函数名称：UPnpProtocol_Client_DelMapping
函数功能：删除端口映射信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的UPNP控制端
 参数.二：pSt_MapInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输入要删除的信息,协议和外部端口必填
 参数.三：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：要操作哪个设备
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL UPnpProtocol_Client_DelMapping(XNETHANDLE xhToken, UPNPPROTOCOL_MAPLIST* pSt_MapInfo, int nIndex = 0);
