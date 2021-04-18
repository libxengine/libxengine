#pragma once
/********************************************************************
//	Created:	2014/7/20  15:38
//	File Name: 	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_Downloads\UPDataDl_Define.h
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_Downloads
//	File Base:	UPDataDl_Define
//	File Ext:	h
//  Project:    XyRySoft_NetEngine(网络通信引擎)
//	Author:		qyt 486179@qq.com
//	Purpose:	下载更新导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//文件名，下载大小，文件大小，文件下载百分比，总大小百分比，如果倒数第二个参数为100，那么表示全部下载完成
typedef void(CALLBACK *CALLBACK_XENGINE_UPDATA_DOWNLOAD_PARSER_PROGRESS)(LPCSTR lpszFileName,double nDownSize,double nFileSize,int nRate,int nAllRate,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                     更新下载器导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD UPDataDown_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     下载器导出函数                                   */
/************************************************************************/
/********************************************************************
函数名称：UPData_DlParser_Init
函数功能：更新下载器初始化并且开始下载
 参数.一：lpszDownloadPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要下载到的目录
 参数.二：pppSt_ListUPDataVer
  In/Out：In
  类型：三级指针
  可空：N
  意思：传递解析好的LIST列表,这个内存由调用者维护
 参数.三：nListCount
  In/Out：In
  类型：三级指针
  可空：N
  意思：列表个数
 参数.四：bIsAll
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否全部同时下载，不填，默认否，一个一个下载，否则就是全部同时下载,文件过多建议一个一个下
返回值
  类型：逻辑型
  意思：是否初始化成功
备注：
*********************************************************************/
extern "C" BOOL UPData_DlParser_Init(LPCSTR lpszDownloadPath, FILEPARSER_VERSIONINFO * **pppSt_ListUPDataVer, int nListCount,BOOL bIsAll = FALSE);
/********************************************************************
函数名称：UPData_DlParser_CBQuery
函数功能：设置查询回调函数
 参数.一：fpCall_DownloadProgress
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：回调函数地址，返回下载进度
 参数.二：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数参数
返回值
  类型：逻辑型
  意思：是否设置成功
备注：
*********************************************************************/
extern "C" BOOL UPData_DlParser_CBQuery(CALLBACK_XENGINE_UPDATA_DOWNLOAD_PARSER_PROGRESS fpCall_DownloadProgress,LPVOID lParam = NULL);
/********************************************************************
函数名称：UPData_DlParser_Close
函数功能：关闭更新，在更新完成后，需要关闭并且释放资源
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL UPData_DlParser_Close();
