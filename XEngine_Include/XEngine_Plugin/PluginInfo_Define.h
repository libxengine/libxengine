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
*                        设置函数导出定义                                          *
*********************************************************************************/
/********************************************************************
函数名称：PluginInfo_Set_Init
函数功能：初始化插件库管理
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_Set_Init();
/********************************************************************
函数名称：PluginInfo_Set_Add
函数功能：添加一个指定SO文件的函数重写一个函数
 参数.一：lpszSOFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要添加重写的库的文件路径
 参数.二：lpszSourceFunc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要重写的函数名称
 参数.三：lpszDestFunc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：重写成什么函数
返回值
  类型：逻辑型
  意思：是否添加成功
备注：暂时不支持
*********************************************************************/
extern "C" BOOL PluginInfo_Set_Add(LPCSTR lpszSOFile,LPCSTR lpszSourceFunc = NULL,LPCSTR lpszDestFunc = NULL);
/********************************************************************
函数名称：PluginInfo_Set_Destroy
函数功能：销毁插件管理模块库
返回值
  类型：逻辑型
  意思：是否销毁成功
备注：
*********************************************************************/
extern "C" BOOL PluginInfo_Set_Destroy();
/*********************************************************************************
*                        获取函数导出定义                                          *
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
