#pragma once
/********************************************************************
//	Created:	2017/7/1   12:49
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_Compress\HelpCompress_Define.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_Compress
//	File Base:	HelpCompress_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:
//	History:
*********************************************************************/
typedef XPVOID XZIP;
//////////////////////////////////////////////////////////////////////////
//                  压缩解压缩导入定义
//////////////////////////////////////////////////////////////////////////
#define XENGINE_HELPCOMPONENTS_COMPRESS_FLAG_CREATE 0                   //重建一个ZIP文件
#define XENGINE_HELPCOMPONENTS_COMPRESS_FLAG_REWRITE 1                  //改写一个ZIP文件
#define XENGINE_HELPCOMPONENTS_COMPRESS_FLAG_ADDPEND 2                  //添加文件到新创建的压缩文件中
//////////////////////////////////////////////////////////////////////////
//                  解压数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_HelpCompress_ZLibInfo
{
    bool bIsFile;                                                         //真为文件,假为目录
    XLONG nCompressSize;                                                  //压缩后大小
    XLONG nUnCompressSize;                                                //压缩前大小
    XCHAR tszFileName[MAX_PATH];                                           //文件名
    XCHAR tszComment[MAX_PATH];                                            //文件注释
    XCHAR tszChangeTime[128];                                              //修改时间
    XCHAR tszCrc[32];                                                      //CRC效验和.32位以下机器必崩溃
}HELPCOMPRESS_ZLIBINFO, *LPHELPCOMPRESS_ZLIBINFO;
//////////////////////////////////////////////////////////////////////////
//                  解压缩导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG HelpCompress_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                  gzip解压缩算法库                                    */
/************************************************************************/
/********************************************************************
函数名称：HelpCompress_Algorithm_GZipCompress
函数功能：使用gzip压缩算法压缩内存中的数据
 参数.一：lpszSourceBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要压缩的缓冲区
 参数.二：dwSourceLen
  In/Out：In
  类型：双字
  可空：N
  意思：压缩的缓冲区长度
 参数.三：ptszDestBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：压缩后返回的缓冲区
 参数.四：pdwDestLen
  In/Out：Out
  类型：双字指针
  可空：N
  意思：压缩后返回的长度
返回值
  类型：逻辑型
  意思：是否压缩成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_Algorithm_GZipCompress(XBYTE *lpszSourceBuffer, XLONG dwSourceLen, XBYTE *ptszDestBuffer, XLONG *pdwDestLen);
/********************************************************************
函数名称：HelpCompress_Algorithm_GZipUnCompress
函数功能：使用gzip算法解压内存中的数据
 参数.一：lpszSourceBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解压的缓冲区
 参数.二：dwSourceLen
  In/Out：In
  类型：双字
  可空：N
  意思：解压的缓冲区长度
 参数.三：ptszDestBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：解压后返回的缓冲区
 参数.四：pdwDestLen
  In/Out：Out
  类型：双字指针
  可空：N
  意思：解压后返回的长度
返回值
  类型：逻辑型
  意思：是否解压成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_Algorithm_GZipUnCompress(XBYTE *lpszSourceBuffer, XLONG dwSourceLen, XBYTE *ptszDestBuffer, XLONG *pdwDestLen);
/************************************************************************/
/*                  内存缓冲区解压缩函数                                */
/************************************************************************/
/********************************************************************
函数名称：HelpCompress_Memory_Compress
函数功能：压缩一段缓冲区内存
 参数.一：lpszSourceBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要压缩的缓冲区
 参数.二：dwSourceLen
  In/Out：In
  类型：双字
  可空：N
  意思：压缩的缓冲区长度
 参数.三：ptszDestBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：压缩后返回的缓冲区
 参数.四：pdwDestLen
  In/Out：Out
  类型：双字指针
  可空：N
  意思：压缩后返回的长度
 参数.五：nLeave
  In/Out：In
  类型：整数型
  可空：N
  意思：压缩等级，0-9 越高压缩越小，速度也越慢
返回值
  类型：逻辑型
  意思：是否压缩成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_Memory_Compress(LPCXSTR lpszSourceBuffer, XLONG dwSourceLen, XCHAR *ptszDestBuffer, XLONG *pdwDestLen, int nLeave);
/********************************************************************
函数名称：HelpCompress_Memory_UnCompress
函数功能：解压一段缓冲区内存
 参数.一：lpszSourceBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解压的缓冲区
 参数.二：dwSourceLen
  In/Out：In
  类型：双字
  可空：N
  意思：解压的缓冲区长度
 参数.三：ptszDestBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：解压后返回的缓冲区
 参数.四：pdwDestLen
  In/Out：Out
  类型：双字指针
  可空：N
  意思：解压后返回的长度
返回值
  类型：逻辑型
  意思：是否解压成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_Memory_UnCompress(LPCXSTR lpszSourceBuffer, XLONG dwSourceLen, XCHAR *ptszDestBuffer, XLONG *pdwDestLen);
/************************************************************************/
/*                  文件解压缩函数                                      */
/************************************************************************/
/********************************************************************
函数名称：HelpCompress_File_Create
函数功能：打开或者创建一个压缩文件
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建的ZIP文件名称
 参数.二：dwOpenFlags
  In/Out：In
  类型：双字
  可空：Y
  意思：要创建的类型，默认为创建
返回值
  类型：压缩文件
  意思：返回打开或者创建成功的压缩句柄
备注：返回的句柄不支持解压缩,只能支持压缩函数
*********************************************************************/
extern "C" XZIP HelpCompress_File_Create(LPCXSTR lpszFileName, XLONG dwOpenFlags = XENGINE_HELPCOMPONENTS_COMPRESS_FLAG_CREATE);
/********************************************************************
函数名称：HelpCompress_File_OPen
函数功能：打开一个待解压的压缩文件
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建的ZIP文件名称
返回值
  类型：文件句柄
  意思：返回解压文件句柄
备注：
*********************************************************************/
extern "C" XZIP HelpCompress_File_OPen(LPCXSTR lpszFileName);
/********************************************************************
函数名称：HelpCompress_File_Add
函数功能：添加一个文件到ZIP压缩文件中
 参数.一：pxZip
  In/Out：In
  类型：压缩句柄
  可空：N
  意思：要添加到哪个压缩文件中
 参数.二：lpszFileStruct
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：压缩包中的文件结构 输入时 1/123/1.pic 就是这种结构 或者 1.pic 就是这种结构
 参数.三：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要加入的文件地址,如果为NULL,表示这是一个文件夹
 参数.四：nzipLeave
  In/Out：In
  类型：整数型
  可空：Y
  意思：压缩度，取值0 - 9 值越高压缩度越高，速度也越慢，默认为4
返回值
  类型：逻辑型
  意思：是否添加成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_File_Add(XZIP pxZip, LPCXSTR lpszFileStruct, LPCXSTR lpszFileName = NULL, int nzipLeave = 4);
/********************************************************************
函数名称：HelpCompress_File_GetNote
函数功能：获取文件注释
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：要获取的文件句柄
 参数.二：ptszBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：获取到的注释内容
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入：缓冲区长度，比如，1024，输出：注释内容长度
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_File_GetNote(XZIP pxZip, XCHAR *ptszBuffer, int nLen);
/********************************************************************
函数名称：HelpCompress_File_GetCount
函数功能：获取ZIP文件中的个数
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：要获取的文件句柄
 参数.二：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出获取到的文件个数
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool HelpCompress_File_GetCount(XZIP pxZip, int *pInt_Count);
/********************************************************************
函数名称：WinSdk_UnCompress_GoToZipFile
函数功能：跳转到一个指定的文件
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
 参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要跳转到哪个文件
返回值
  类型：逻辑型
  意思：是否跳转成功
备注：用于在你想要获取指定文件信息的时候，可以用这个函数
*********************************************************************/
extern "C" bool HelpCompress_File_GoFile(XZIP pxZip, LPCXSTR lpszFileName);
/********************************************************************
函数名称：WinSdk_UnCompress_GoZipFirstFile
函数功能：跳转到ZIP首文件
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
返回值
  类型：逻辑型
  意思：是否跳转成功
备注：用于在你想要获取指定文件信息的时候，可以用这个函数
*********************************************************************/
extern "C" bool HelpCompress_File_GoFirstFile(XZIP pxZip);
/********************************************************************
函数名称：WinSdk_UnCompress_GoZipNextFile
函数功能：跳转到ZIP下一个文件
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
返回值
  类型：逻辑型
  意思：是否跳转成功
备注：用于解压缩循环
*********************************************************************/
extern "C" bool HelpCompress_File_GoNextFile(XZIP pxZip);
/********************************************************************
函数名称：WinSdk_UnCompress_GetCurrentFileInfo
函数功能：获取当前文件信息
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
 参数.二：pSt_FileInfo
  In/Out：Out
  类型：结构体指针
  可空：N
  意思：获取到的文件信息
返回值
  类型：逻辑型
  意思：是否获取成功
备注：需要使用上面的跳转函数定位好后的文件才可以使用此函数
*********************************************************************/
extern "C" bool HelpCompress_File_GetInfo(XZIP pxZip, HELPCOMPRESS_ZLIBINFO *pSt_FileInfo);
/********************************************************************
函数名称：HelpCompress_File_WriteFile
函数功能：吧当前句柄位置的压缩文件数据写到指定位置
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要写到哪个地方
返回值
  类型：逻辑型
  意思：是否写入成功
备注：需要使用上面的跳转函数定位好后的文件才可以使用此函数
*********************************************************************/
extern "C" bool HelpCompress_File_WriteFile(XZIP pxZip, LPCXSTR lpszFile);
/********************************************************************
函数名称：HelpCompress_File_Close
函数功能：关闭文件句柄
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：HelpCompress_File_Create 使用此函数关闭
*********************************************************************/
extern "C" bool HelpCompress_File_Close(XZIP pxZip);
/********************************************************************
函数名称：HelpCompress_File_UNClose
函数功能：关闭文件句柄
 参数.一：pxZip
  In/Out：In
  类型：ZIP句柄
  可空：N
  意思：打开的ZIP文件的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：HelpCompress_File_OPen 通过此函数关闭
*********************************************************************/
extern "C" bool HelpCompress_File_UNClose(XZIP pxZip);
