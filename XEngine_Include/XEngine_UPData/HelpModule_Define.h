#pragma once
/********************************************************************
//	Created:	2014/7/25  17:53
//	File Name: 	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_HelpModule\HelpModule_Define.h
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_HelpModule
//	File Base:	HelpModule_Define
//	File Ext:	h
//  Project:    XyRySoft_NetEngine(网络通信引擎)
//	Author:		qyt 486179@qq.com
//	Purpose:	更新帮助模块导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                           导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD UPHelpModule_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                           帮助函数导出                               */
/************************************************************************/
/********************************************************************
函数名称：HelpModule_Api_Install
函数功能：安装更新包
 参数.一：lpszLocalFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：本地文件列表路径
 参数.二：lpszRemoteJson
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：远程获取到的JSON更新列表
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入JSON缓冲区大小
 参数.四：pppSt_ListUPDataVer
  In/Out：In
  类型：三级指针
  可空：N
  意思：解析好的更新的文件列表,这个内存由调用者维护
 参数.五：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入文件列表个数
 参数.六：lpszDlPath
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：下载到的目录，如果为NULL，表明当前目录
返回值
  类型：逻辑型
  意思：是否安装成功
备注：此函数会先把要更新的文件拷贝到指定位置并且删除下载好的临时文件,然后设置本地文件列表
      的信息为最新版本信息,然后执行你需要执行的文件和删除你需要删除的文件.部分操作可能需要权限才能执行
      比如:你需要安装到C盘的文件的你需要提供权限才能成功执行此函数
*********************************************************************/
extern "C" BOOL HelpModule_Api_Install(LPCSTR lpszLocalFile, LPCSTR lpszRemoteJson, int nMsgLen, FILEPARSER_VERSIONINFO * **pppSt_ListUPDataVer, int nListCount, LPCSTR lpszDlPath = NULL);
/********************************************************************
函数名称：HelpModule_Api_BuildVer
函数功能：构建应用更新文件
 参数.一：lpszPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要构建哪个目录中的所有文件列表
 参数.二：lpszLocalFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：构建好的更新数据结构保存到哪个地方
 参数.三：nFileVer
  In/Out：In
  类型：整数型
  可空：Y
  意思：构建的当前版本号，如果为0，那么会采用当前年月日为版本
 参数.四：bSubDir
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否包含子目录，是否把子目录下的所有文件都构建成更新包
 参数.五：lpszUPFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：构建要更新的数据结构列表，可以不使用，自己编写更新的JSON
 参数.六：lpszDlUrl
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：第五个参数有值，这个参数必须有值，这个将设置更新的下载地址，使用
           http://www.xxx.com/UPFile/ 表示，我们会自动填充后面的文件名和路径
 参数.七：lpszCfgPath
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果不为NULL,指定所有模块配置文件目录
返回值
  类型：逻辑型
  意思：是否构建成功
备注：次函数可以帮助你快速构建一个可更新的文件列表，方便你快速使用我们的更新SDK
*********************************************************************/
extern "C" BOOL HelpModule_Api_BuildVer(LPCSTR lpszPath, LPCSTR lpszLocalFile, __int64 nFileVer = 0, BOOL bSubDir = TRUE, LPCSTR lpszUPFile = NULL, LPCSTR lpszDlUrl = NULL,LPCSTR lpszCfgPath = NULL);
