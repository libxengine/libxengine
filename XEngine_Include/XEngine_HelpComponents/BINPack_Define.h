#pragma once
/********************************************************************
//	Created:	2017/6/23   21:50
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_BinPack\BINPack_Define.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_BinPack
//	File Base:	BINPack_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	二进制文件数据打包模块导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    导出数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_HelpComponents_BinPacket
{
    ULONGLONG nFileNumber;                                //文件总个数
    int nCountSize;                                       //文件总大小（不包含协议）
    int nPkgPass;                                         //文件设置的密码
}HELPCOMPONENTS_BINPACKET,*LPHELPCOMPONENTS_BINPACKET;
//////////////////////////////////////////////////////////////////////////
//                    导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" BOOL BINPack_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                    二进制打包工具                                    */
/************************************************************************/
/********************************************************************
函数名称：BINPack_Packet_Init
函数功能：初始化一个二进制打包管理器
 参数.一：pxhNet
  In/Out：Out
  类型：文件句柄
  可空：N
  意思：导出获取到的句柄
 参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：你要创建的二进制打包文件名
 参数.三：nBINPass
  In/Out：In
  类型：整数型
  可空：Y
  意思：打包密码，默认0没有设置密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BINPack_Packet_Init(XNETHANDLE *pxhFile, LPCSTR lpszFileName,int nBINPass = 0);
/********************************************************************
函数名称：BINPack_Packet_Push
函数功能：压入一个文件到二进制包中
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：输入你刚才初始化的网络句柄
 参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要打包的文文件,这个参数和第五个参数不能同时为NULL
 参数.三：lpCustomHdr
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：要写入的自定义头数据,可以不写入
 参数.四：nCusLenHdr
  In/Out：In
  类型：整数型
  可空：Y
  意思：要写入的自定义头数据长度
 参数.五：lpszMemBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果这个参数不为NULL,那么第二个参数必须为NULL,表示写内存数据为文件
 参数.六：nMemLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：内存数据大小
 参数.七：Disrupt
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否打乱原始数据,默认不打乱
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BINPack_Packet_Push(XNETHANDLE xhFile, LPCSTR lpszFileName = NULL, LPVOID lpCustomHdr = NULL, int nCusLenHdr = 0, LPCSTR lpszMemBuffer = NULL, int nMemLen = 0, BOOL bDisrupt = FALSE);
/********************************************************************
函数名称：BINPack_Packet_Close
函数功能：关闭一个二进制包管理器
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：要关闭的文件句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：如果打包完毕,需要调用此函数关闭
*********************************************************************/
extern "C" BOOL BINPack_Packet_Close(XNETHANDLE xhFile);
/********************************************************************
函数名称：BINPack_Packet_GetInfo
函数功能：获取一个打包的文件信息
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：要获取的文件句柄
 参数.二：pSt_BINPacket
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：是否在初始化成功后，关闭前使用此函数才有效！
*********************************************************************/
extern "C" BOOL BINPack_Packet_GetInfo(XNETHANDLE xhFile,HELPCOMPONENTS_BINPACKET *pSt_BINPacket);
/************************************************************************/
/*                    二进制解包工具                                    */
/************************************************************************/
/********************************************************************
函数名称：BINPack_UnPack_Init
函数功能：解包函数初始化
 参数.一：pxhFile
  In/Out：Out
  类型：文件句柄
  可空：N
  意思：导出初始化的文件句柄
 参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解压的文件
 参数.三：nBINPass
  In/Out：In
  类型：整数型
  可空：Y
  意思：解压密码，默认0没有设置密码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BINPack_UnPack_Init(XNETHANDLE *pxhFile, LPCSTR lpszFileName,int nBINPass = 0);
/********************************************************************
函数名称：BINPack_UnPack_Get
函数功能：从一个打包的二进制数据中获取一段数据
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：输入你刚才初始化的网络句柄
 参数.二：pszCustomHdr
  In/Out：Out
  类型：无类型指针
  可空：N
  意思：获取数据自定义头
 参数.三：pInt_CusLenHdr
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输入你提供自定义头的缓冲区长度,输出真实获取到的长度,没有自定义头这个参数会写成0
 参数.四：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：获取到的数据是否写成文件,如果为NULL,那么下一个参数不能为NULL
 参数.五：pszMemBuffer
  In/Out：In
  类型：字符指针
  可空：Y
  意思：获取到的文件导出到内存
 参数.六：pIntMemLen
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：输入你提供的大小,输出真实大小,不够将返回错误码
 参数.七：Disrupt
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：原始数据是否被打乱,默认没有打乱,如果打乱了,这个值必须为真
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL BINPack_UnPack_Get(XNETHANDLE xhFile, LPVOID pszCustomHdr, int *pInt_CusLenHdr, LPCSTR lpszFileName = NULL, CHAR *pszMemBuffer = NULL, int *pIntMemLen = NULL, BOOL bDisrupt = FALSE);
/********************************************************************
函数名称：BINPack_UnPack_Close
函数功能：关闭一个二进制包管理器
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：要关闭的文件句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：如果打包完毕,需要调用此函数关闭
*********************************************************************/
extern "C" BOOL BINPack_UnPack_Close(XNETHANDLE xhFile);
/********************************************************************
函数名称：BINPack_UnPack_GetInfo
函数功能：获取一个打包的文件信息
 参数.一：xhFile
  In/Out：In
  类型：文件句柄
  可空：N
  意思：要获取的文件句柄
 参数.二：pSt_BINPacket
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：是否在初始化成功后，关闭前使用此函数才有效！
*********************************************************************/
extern "C" BOOL BINPack_UnPack_GetInfo(XNETHANDLE xhFile,HELPCOMPONENTS_BINPACKET *pSt_BINPacket);
