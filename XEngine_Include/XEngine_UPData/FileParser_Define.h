#pragma once
/********************************************************************
//	Created:	2014/7/18  14:46
//	File Name: 	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_FileParser\FileParser_Define.h
//	File Path:	F:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_UPData\UPData_FileParser
//	File Base:	FileParser_Define
//	File Ext:	h
//  Project:    XyRySoft_NetEngine(网络通信引擎)
//	Author:		qyt 486179@qq.com
//	Purpose:	更新组件，文件解析器导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                导出的数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_FileParser_VersionInfo
{
    CHAR tszModulePath[MAX_PATH];                                         //模块路径,新增加的必须拥有此值
    CHAR tszModuleName[MAX_PATH];                                         //模块名称
    CHAR tszModuleDownload[MAX_PATH];                                     //模块下载地址
    CHAR tszModuleCode[MAX_PATH];                                         //远程模块标识符
    __int64 nModuleVersion;                                               //文件版本号
    BOOL bIsRun;                                                          //安装完成是否运行
    struct
    {
        __int64 nModuleVersion;
        CHAR tszMoudelPath[MAX_PATH];
        CHAR tszMoudelName[MAX_PATH];
        CHAR tszMoudelCode[MAX_PATH];
    }st_LocalVersion;
}FILEPARSER_VERSIONINFO,*LPFILEPARSER_VERSIONINFO;
//////////////////////////////////////////////////////////////////////////
//                导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD UPFileParser_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                文件解析器导出函数                                    */
/************************************************************************/
/********************************************************************
函数名称：FileParser_ReadVer_GetUPVersion
函数功能：获取新版本信息
 参数.一：lpszWebHost
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：网页主机名称
 参数.二：ptszUPMsg
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的最新更新信息
 参数.三：pInt_Len
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入缓冲区大小,输出获取到的大小
返回值
  类型：逻辑型
  意思：返回真表示有新版本，否则返回假并且重置错误码
备注：APIHelp_HttpRequest_Get错误会存在
*********************************************************************/
extern "C" BOOL FileParser_ReadVer_GetUPVersion(LPCSTR lpszWebHost, CHAR *ptszUPMsg, int *pInt_Len);
/********************************************************************
函数名称：FileParser_ReadVer_GetDescription
函数功能：获取更新内容描述
 参数.一：lpszJsonMsg
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：通过获取到的新版本JSON信息来获取更新内容
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入JSON缓冲区大小
 参数.三：ptszUPDes
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出获取到的更新描述
 参数.四：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入，缓冲区大小，输出获取到的内容缓冲区大小
返回值
  类型：逻辑型
  意思：是否获取成功
备注：错误为ERROR_XENGINE_UPDATA_FILEPARSER_READVER_GETDES_LEN最后一个参数将设置为需要的大小
*********************************************************************/
extern "C" BOOL FileParser_ReadVer_GetDescription(LPCSTR lpszJsonMsg, int nMsgLen, CHAR *ptszUPDes, int *pInt_Len);
/************************************************************************/
/*                文件匹配器导出函数                                    */
/************************************************************************/
/********************************************************************
函数名称：FileParser_Match_Start
函数功能：开始匹配新版本
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：本地文件版本信息路径
 参数.二：lpszJsonMsg
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要解析的JSON内存缓冲区
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入JSON缓冲区大小
 参数.四：pppSt_ListUPDataVer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出要更新的文件信息结构
 参数.五：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：文件列表个数
 参数.六：pInt_LocalVer
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的本地版本号
 参数.七：pInt_NewVer
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出获取到的最新版本号
返回值
  类型：逻辑型
  意思：是否有新版本
备注：参数pppSt_ListUPDataVer必须调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" BOOL FileParser_Match_Start(LPCSTR lpszFileName, LPCSTR lpszJsonMsg, int nMsgLen, FILEPARSER_VERSIONINFO * **pppSt_ListUPDataVer, int* pInt_ListCount, __int64 *pInt_LocalVer = NULL, __int64 *pInt_NewVer = NULL);
