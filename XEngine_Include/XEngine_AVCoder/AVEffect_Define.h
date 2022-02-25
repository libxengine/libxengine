#pragma once
/********************************************************************
//    Created:     2021/10/09  13:17:29
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_AVCoder\XEngine_AVEffect\AVEffect_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_AVCoder\XEngine_AVEffect
//    File Base:   AVEffect_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     特效模块导出文件
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AVEffect_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      视频特效导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：AVEffect_Video_Rotation90
函数功能：YUV420P翻转函数
 参数.一：pszSource
  In/Out：In
  类型：无符号字符型
  可空：N
  意思：输入一个完整的YUV数据
 参数.二：pszDest
  In/Out：Out
  类型：无符号字符型
  可空：N
  意思：输出转换后的数据
 参数.三：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输出视频宽
 参数.四：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：输入视频高
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVEffect_Video_Rotation90(uint8_t* pszSource, uint8_t* pszDest, int nWidth, int nHeight);
extern "C" BOOL AVEffect_Video_Rotation180(uint8_t* pszSource, uint8_t* pszDest, int nWidth, int nHeight);
extern "C" BOOL AVEffect_Video_Rotation270(uint8_t* pszSource, uint8_t* pszDest, int nWidth, int nHeight);