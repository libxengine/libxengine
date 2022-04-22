#pragma once
/********************************************************************
//    Created:     2022/04/14  15:19:16
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageRecognition\ImageRecognition_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageRecognition
//    File Base:   ImageRecognition_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像识别导出函数
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                            导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD ImageRecognition_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                          图像识别帮助函数                            */
/************************************************************************/
/********************************************************************
函数名称：ImageRecognition_Help_QRDecodec
函数功能：QR二维码解析器
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入文件或者内存
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：如果为NULL,参数一表示文件路径,否则输入内存大小,并且输出二维码字符串大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出识别到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ImageRecognition_Help_QRDecodec(LPCSTR lpszMsgBuffer, int* pInt_MsgLen, CHAR* ptszMsgBuffer);
/********************************************************************
函数名称：ImageRecognition_Help_QRCamera
函数功能：识别摄像头的二维码
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出识别到的内容
 参数.二：nDeviceID
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入摄像头的索引,一个就填写0
 参数.三：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数会死锁直到识别或者超时
*********************************************************************/
extern "C" BOOL ImageRecognition_Help_QRCamera(CHAR* ptszMsgBuffer, int nDeviceID = 0, int nTimeout = 3);