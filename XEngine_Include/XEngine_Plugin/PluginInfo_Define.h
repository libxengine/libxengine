#pragma once
/********************************************************************
//	Created:	2013/9/18   13:53
//	Filename: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginInfo/PluginInfo_Define.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginInfo/
//	File Base:	PluginInfo_Define
//	File Ext:	h
//  Project:    NetEngien_Linux(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:    插件信息模块导出定义
//	History:
*********************************************************************/
#pragma pack(push)
#pragma pack(2)
typedef struct tag_NetEnginePlugin_Version
{
    unsigned short int nCoreVersion:2;
    unsigned short int nMainVersion:2;
    unsigned short int nSubVersion:2;
    unsigned short int nFixVersion:2;
}NETENGINE_PLUGIN_VERSION,*LPNETENGINE_PLUGIN_VERSION;
#pragma pack(pop)
//////////////////////////////////////////////////////////////////////////
//                       导出函数实现
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD PluginInfo_GetLastError(int *pInt_SysError = NULL);
/*********************************************************************************
*                        设置函数导出定义                                        *
*********************************************************************************/
/********************************************************************
函数名称：PluginInfo_ListCreator_Init
函数功能：初始化插件库管理
 参数.一：pxhToken
  In/Out：Out
  类型：句柄指针
  可空：N
  意思：输出创建的句柄
 参数.二：
  In/Out：
  类型：
  可空：
  意思：
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListCreator_Init(XNETHANDLE* pxhToken);
/********************************************************************
函数名称：PluginInfo_ListCreator_AddModule
函数功能：添加一个指定SO文件到列表中
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的创建器
 参数.二：lpszSOFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要添加的路径
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListCreator_AddModule(XNETHANDLE xhToken, LPCSTR lpszSOFile);
/********************************************************************
函数名称：PluginInfo_ListCreator_AddFunction
函数功能：添加一个函数到指定模块中
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的创建器
 参数.二：lpszSOFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要为哪个模块添加
 参数.三：lpszFuncName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要添加的函数名称
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListCreator_AddFunction(XNETHANDLE xhToken, LPCSTR lpszSOFile, LPCSTR lpszFuncName);
/********************************************************************
函数名称：PluginInfo_ListCreator_Get
函数功能：获取列表缓冲区信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的创建器
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：输出缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListCreator_Get(XNETHANDLE xhToken, CHAR* ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：PluginInfo_ListCreator_WriteFile
函数功能：吧列表写到指定文件
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
 参数.二：lpszFileList
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要写到的地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListCreator_WriteFile(XNETHANDLE xhToken, LPCSTR lpszFileList);
/********************************************************************
函数名称：PluginInfo_ListCreator_Destroy
函数功能：销毁插件管理模块库
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListCreator_Destroy(XNETHANDLE xhToken);
/************************************************************************/
/*                       解析器导出定义                                 */
/************************************************************************/
/********************************************************************
函数名称：PluginInfo_ListParse_Init
函数功能：初始化解析器
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出句柄
 参数.二：lpszFileList
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的文件列表
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListParse_Init(XNETHANDLE* pxhToken, LPCSTR lpszFileList);
/********************************************************************
函数名称：PluginInfo_ListParse_ModuleCount
函数功能：获取模块个数
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的模块个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListParse_ModuleCount(XNETHANDLE xhToken, int* pInt_ListCount);
/********************************************************************
函数名称：PluginInfo_ListParse_FunctionCount
函数功能：获取指定模块函数个数
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszModuleName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获得的模块名称
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的模块个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListParse_FunctionCount(XNETHANDLE xhToken, LPCSTR lpszModuleName, int* pInt_ListCount);
/********************************************************************
函数名称：PluginInfo_ListParse_GetModule
函数功能：获得模块名称列表
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pppszListFile
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出模块文件列表.这个参数必须由用户释放内存
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListParse_GetModule(XNETHANDLE xhToken, CHAR*** pppszListFile, int* pInt_ListCount);
/********************************************************************
函数名称：PluginInfo_ListParse_GetFunction
函数功能：获得指定模块函数列表
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszModuleName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获取的模块名称
 参数.三：pppszListFile
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出函数列表.这个参数必须由用户释放内存
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_ListParse_GetFunction(XNETHANDLE xhToken, LPCSTR lpszModuleName, CHAR*** pppszListFunction, int* pInt_ListCount);
/********************************************************************
函数名称：PluginInfo_ListParse_Destroy
函数功能：销毁一个解析器
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
extern "C" BOOL PluginInfo_ListParse_Destroy(XNETHANDLE xhToken);
/*********************************************************************************
*                        获取函数导出定义                                        *
*********************************************************************************/
/********************************************************************
函数名称：PluginInfo_Get_VerSion
函数功能：获取中间件版本号
 参数.一：pInt_MainVersion
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出通信引擎核心版本号
 参数.二：pInt_SubVersion
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出通信引擎主版本号
 参数.三：pInt_FixVersion
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出通信引擎次版本号
 参数.四：pInt_SvnVersion
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出通信引擎修复版本号
返回值
  类型：逻辑型
  意思：是否获取版本号成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_Get_VerSion(int *pInt_CoreVersion,int *pInt_MainVersion,int *pInt_SubVersion,int *pInt_FixVersion);
/********************************************************************
函数名称：PluginInfo_Get_AllVerSion
函数功能：获取中间件版本号
 参数.一：pulVersion
  In/Out：Out
  类型：双字
  可空：Y
  意思：导出通信引擎主要版本号
 参数.二：pSt_Version
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：导出通信引擎主要版本
返回值
  类型：逻辑型
  意思：是否获取版本号成功
备注：每个字节位导出一个版本号，从 1 - 4，核心版本 主要版本 次要版本 修复版本
     两个参数不能同时为NULL，只使用一个参数表示导出此参数版本
*********************************************************************/
extern "C" BOOL PluginInfo_Get_AllVerSion(DWORD *pulVersion,LPNETENGINE_PLUGIN_VERSION pSt_Version = NULL);
