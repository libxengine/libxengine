#pragma once
/********************************************************************
//	Created:	2013/9/17   15:41
//	Filename: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginCore/PluginCore_Define.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_Plugin/NetEngine_PluginCore/
//	File Base:	PluginCore_Define
//	File Ext:	h
//  Project:    NetEngien_Linux(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:    插件核心导出定义
//	History:
*********************************************************************/
/*你的模块插件需要实现以下函数
初始化的时候会自动调用
BOOL PluginCore_Init(LPVOID lParam = NULL);
卸载的时候会自动调用
BOOL PluginCore_UnInit();
自己调用
BOOL PluginCore_Call(LPVOID lPAaram = NULL,LPVOID lPBaram = NULL);
执行函数PluginCore_Call失败的时候获取的错误码
DWORD PluginCore_GetLastError();
*/
typedef void(CALLBACK* CALLBACK_NETENGINE_PLUGINCORE_SEARCH_FILE)(LPCSTR lpszFile,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                       导出函数定义
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD PluginCore_GetLastError(int *pInt_SysError = NULL);
/*********************************************************************************
*                        插件搜索器导出函数定义                                     *
*********************************************************************************/
/********************************************************************
函数名称：PluginCore_Search_Start
函数功能：开始搜索插件
 参数.一：lpszPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：插件主目录
 参数.二：fpCall_PluginFile
  In/Out：In
  类型：回调函数
  可空：N
  意思：插件文件路径和名称
 参数.三：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：上层用户自定义参数
返回值
  类型：逻辑型
  意思：是否轮训完毕
备注：插件必须是以.xpl为后缀名，比如 XyRyNet_Plus.xpl，通过回调函数来获取插件名然后传递给插件框架让其初始化即可。
*********************************************************************/
extern "C" BOOL PluginCore_Search_Start(LPCSTR lpszPath,CALLBACK_NETENGINE_PLUGINCORE_SEARCH_FILE fpCall_PluginFile,LPVOID lParam = NULL);
/********************************************************************
函数名称：PluginCore_Search_Stop
函数功能：停止插件搜索
返回值
  类型：逻辑型
  意思：是否停止成功
备注：
*********************************************************************/
extern "C" BOOL PluginCore_Search_Stop();
/*********************************************************************************
*                        插件框架导出函数定义                                       *
*********************************************************************************/
/********************************************************************
函数名称：PluginCore_FrameWork_Init
函数功能：初始化插件核心系统
返回值
  类型：逻辑型
  意思：是否成功初始化
备注：
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_Init();
/********************************************************************
函数名称：PluginCore_FrameWork_Push
函数功能：添加一个标准的插件到插件框架中
 参数.一：pxhModule
  In/Out：Out
  类型：模块句柄
  可空：N
  意思：导出一个加载成功的模块句柄
 参数.二：lpszPluginFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：插件模块路径
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：自定义输入输出参数
返回值
  类型：逻辑型
  意思：是否成功添加
备注：
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_Push(XNETHANDLE *pxhNet, LPCSTR lpszPluginFile,LPVOID lParam = NULL);
/********************************************************************
函数名称：PluginCore_FrameWork_Exec
函数功能：执行插件功能
 参数.一：xhModule
  In/Out：In
  类型：插件句柄
  可空：Y
  意思：要执行的插件句柄，为空执行全部
 参数.二：lPAaram
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：可作为输入输出参数
 参数.三：lPBaram
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：可作为输入输出参数
返回值
  类型：逻辑型
  意思：是否执行成功
备注：参数要么传递NULL，要么传递值，由用户来判断参数是否可用
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_Exec(XNETHANDLE xhModule = 0,LPVOID lPAaram = NULL,LPVOID lPBaram = NULL);
/********************************************************************
函数名称：PluginCore_FrameWork_ExecFunc
函数功能：执行一个插件的自定义函数
 参数.一：xhModule
  In/Out：In
  类型：插件句柄
  可空：N
  意思：要执行的插件句柄
 参数.二：lpszFunc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的函数名称
 参数.三：lPAaram
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：可作为输入输出参数
 参数.四：lPBaram
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：可作为输入输出参数
返回值
  类型：逻辑型
  意思：是否执行成功
备注：设置为自动执行的函数不能调用此函数来执行
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_ExecFunc(XNETHANDLE xhModule,LPCSTR lpszFunc,LPVOID lPAaram = NULL,LPVOID lPBaram = NULL);
/********************************************************************
函数名称：PluginCore_FrameWork_Destroy
函数功能：销毁插件核心并且清理资源
返回值
  类型：逻辑型
  意思：是否成功销毁
备注：
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_Destroy();
/********************************************************************
函数名称：PluginCore_FrameWork_AddFunc
函数功能：添加一个自定义函数名到你的模块中
 参数.一：xhModule
  In/Out：In
  类型：插件句柄
  可空：N
  意思：要添加的模块句柄
 参数.二：lpszFunc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：调用的函数名称
 参数.三：nTimer
  In/Out：In
  类型：整数型
  可空：Y
  意思：调用此函数的间隔时间和次数，默认为0，不启用
 参数.四：bTimer
  In/Out：In
  类型：整数型
  可空：Y
  意思：为真表示以间隔时间操作，为假表示执行次数
返回值
  类型：逻辑型
  意思：是否成功执行PING
备注：自动执行函数不支持参数，但是lpszFunc函数必须带两个参数
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_AddFunc(XNETHANDLE xhModule, LPCSTR lpszFunc, int nTimer = 0, BOOL bTimer = TRUE);
/********************************************************************
函数名称：PluginCore_FrameWork_Del
函数功能：删除一个指定的插件
 参数.一：xhModule
  In/Out：In
  类型：插件句柄
  可空：N
  意思：要删除的指定的插件句柄
返回值
  类型：逻辑型
  意思：是否删除成功
备注：
*********************************************************************/
extern "C" BOOL PluginCore_FrameWork_Del(XNETHANDLE xhModule);

