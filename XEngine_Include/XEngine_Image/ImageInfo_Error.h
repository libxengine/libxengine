#pragma once
/********************************************************************
//    Created:     2022/04/18  11:17:08
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation\ImageInfo_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation
//    File Base:   ImageInfo_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像信息错误导出
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      图像属性修改错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT 0x012B0001          //参数错误
#define ERROR_XENGINE_IMAGE_INFORMATION_SET_OPEN 0x012B0002              //打开文件失败
#define ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE 0x012B0003             //写到文件失败
#define ERROR_XENGINE_IMAGE_INFORMATION_SET_MALLOC 0x012B0004            //申请内存
//////////////////////////////////////////////////////////////////////////
//                      图像属性获取错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_IMAGE_INFORMATION_GET_PARAMENT 0x012B1001          //参数错误
#define ERROR_XENGINE_IMAGE_INFORMATION_GET_OPEN 0x012B1002              //打开文件失败