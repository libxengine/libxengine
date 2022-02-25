#pragma once
/********************************************************************
//	Created:	2017/6/23   20:46
//	Filename: 	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_BinPack\BINPack_Error.h
//	File Path:	G:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_HelpComponents\HelpComponents_BinPack
//	File Base:	BINPack_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	二进制包管理器错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        二进制打包错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_INIT_PARAMENT 0x70A0001     //参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_INIT_CREATEFILE 0x70A0002   //打开文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_INIT_MALLOC 0x70A0003       //申请内存失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_PUSH_PARAMENT 0x70A0010     //参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_PUSH_NOTFOUND 0x70A0011     //没有找到
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_PUSH_MALLOC 0x70A0012       //申请内存失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_PUSH_GETSIZE 0x70A0013      //获取大小失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_PACKAGE_NOTFOUND 0x70A0020  //没有找到
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_PACKAGE_WRITEHDR 0x70A0021  //写入文件包头失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_PACKET_GET_NOTFOUND 0x70A0030      //获取信息失败,没有对应的内容
//////////////////////////////////////////////////////////////////////////
//                        二进制解包错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_INIT_PARAMENT 0x70A1000     //初始化失败,参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_INIT_OPENFILE 0x70A1001     //打开文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_INIT_READ 0x70A1002         //读取失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_INIT_SIZE 0x70A1003         //文件大小不对，不是正确的包
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_INIT_HDR 0x70A1004          //文件头不对，不是正确的打包文件
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_INIT_GETSIZE 0x70A1005      //获取大小错误
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_PARAMENT 0x70A1010      //获取失败,参数错误
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_NOTFOUND 0x70A1011      //获取失败,没有找到可用的句柄
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_SIZE 0x70A1012          //获取大小失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_HDR 0x70A1013           //获取头失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_CREATEFILE 0x70A1014    //创建文件失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_READ 0x70A1015          //读取数据失败
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_TAIL 0x70A1016          //尾部协议不匹配
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_CHECK 0x70A1017         //校验码错误无法继续
#define ERROR_XENGINE_HELPCOMPONENTS_BINPACK_UNPACK_GET_FAILED 0x70A1018        //获取失败
