﻿#pragma once
/********************************************************************
//	Created:	2013/12/3   09:52
//	Filename: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_HelpComponents/HelpComponents_Packets/Packets_Error.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_HelpComponents/HelpComponents_Packets/
//	File Base:	Packets_Error
//	File Ext:	h
//  Project:    NetEngine_Linux(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	组包拆包SDK导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       组包错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_PARAMENT 0x50E0001        //投递包失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_MAXCOUNT 0x50E0002        //最大包个数，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_NOTFOUND 0x50E0003        //投递失败,没有找到客户端ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_MALLOC 0x50E0004          //申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_PUSH_MALLOCHDR 0x50E0011       //申请协议头内存失败了
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_PUSH_NOTMATCH 0x50E0012        //协议不匹配，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_PUSH_MALLOC 0x50E0013          //申请数据缓冲区失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CREATE_MALLOCROOT 0x50E0020    //申请根内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CREATE_MALLOCNOTE 0x50E0021    //申请节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CLEAR_PARAMENT 0x50E0030       //清理失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CLEAR_NOTFOUND 0x50E0032       //清理失败，没有找到ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_DELETE_PARAMENT 0x50E0040      //删除失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_DELETE_NOTFOUND 0x50E0042      //删除失败，没有找到ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_PARAMENT 0x50E0051         //分解包失败，获取失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_IDNONE 0x50E0053           //没有任何ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_NOTFOUND 0x50E0054         //没有找到此ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_ISNULL 0x50E0055           //这个ID没有任何数据包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_NOCOMPLETE 0x50E0056       //不是一个完成的包，需要等待组建
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_ISLEAVEPKT 0x50E0057       //这个包是一个离开包，需要删除
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_PKTNULL 0x50E0058          //有数据长度但是无数据，可能内部有问题
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_SMALL 0x50E0059            //给出的缓冲区长度太小！无法满足
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_BUSY 0x50E005A             //无法获取锁,这个包正在被操作
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_WAITEVENT_NOTFOUND 0x50E0070   //没有找到指定池
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_WAITEVENT_NOPACKET 0x50E0071   //没有包,错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_WAITEVENT_TIMEOUT 0x50E0072    //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_PARAMENT 0x50E0080   //参数凑无,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_NONE 0x50E0081       //获取失败,没有可用包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_ISLEAVEPKT 0x50E0082 //是一个离开包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_SMALL 0x50E0083      //提供的缓冲区大小不足够
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_BUILDCHUNK_MALLOC 0x50E0090    //构建CHUNK申请内存失败
//////////////////////////////////////////////////////////////////////////
//                       扩展组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_EX_MALLOC 0x50E1001
#define ERROR_HELPCOMPONENTS_PACKETS_EX_NOTFOUND 0x50E1002
//////////////////////////////////////////////////////////////////////////
//                       包处理帮助错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_HELP_PARAMENT 0x50E2001              //参数错误，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_HELP_LEN 0x50E2002                   //长度有问题
#define ERROR_HELPCOMPONENTS_PACKETS_HELP_NOTMATCH 0x50E2003              //没有找到匹配的协议定义
//////////////////////////////////////////////////////////////////////////
//                       扩展协议组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_PARAMENT 0x50E4001        //投递包失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_MAXCOUNT 0x50E4002        //最大包个数，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_NOTFOUND 0x50E4003        //投递失败,没有找到客户端ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_MALLOC 0x50E4004          //申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_PUSH_NOTMATCH 0x50E4012        //协议不匹配，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_PUSH_MALLOC 0x50E4013          //申请数据缓冲区失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_CREATE_MALLOCROOT 0x50E4020    //申请根内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_CREATE_MALLOCNOTE 0x50E4021    //申请节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_CREATE_NOTPOOL 0x50E4022       //没有可用池
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_PARAMENT 0x50E4051         //分解包失败，获取失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_IDNONE 0x50E4053           //没有任何ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_NOTFOUND 0x50E4054         //没有找到此ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_ISNULL 0x50E4055           //这个ID没有任何数据包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_NOCOMPLETE 0x50E4056       //不是一个完成的包，需要等待组建
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_PKTNULL 0x50E4057          //有数据长度但是无数据，可能内部有问题
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_SMALL 0x50E4058            //给出的缓冲区长度太小！无法满足
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_BUSY 0x50E4059             //无法获取锁,这个包正在被操作
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_WAITEVENT_NOPACKET 0x50E4071   //没有包,错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_WAITEVENT_TIMEOUT 0x50E4072    //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_WAITEVENT_NOTFOUND 0x50E4073   //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETSINGLE_PARAMENT 0x50E4080   //参数凑无,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETSINGLE_NONE 0x50E4081       //获取失败,没有可用包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETSINGLE_SMALL 0x50E4082      //提供的缓冲区大小不足够
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_BUILD_TAIL 0x50E4090           //协议尾部不正确，包已经被抛弃
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_BUILD_CHECK 0x50E4091          //校验码不正确
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_PARAMENT 0x50E40A0      //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_NONE 0x50E40A1          //获取失败，队列没有任何数据
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_NOTFOUND 0x50E40A2      //没有找到ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_BUSY 0x50E40A3          //队列忙碌，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_ISNULL 0x50E40A4        //这个ID没有数据
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_NOCOMPLETE 0x50E40A5    //没有组好包，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_SMALL 0x50E40A6         //缓冲区太小
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_ACTIVE_NOTFOUND 0x50E40C0      //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_BUILDCHUNK_MALLOC 0x50E40D0
//////////////////////////////////////////////////////////////////////////
//                       自定义协议组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_CREATE_MALLOCROOT 0x50E5002   //申请根节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_CREATE_MALLOCNOTE 0x50E5003   //申请节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_POST_PARAMENT 0x50E5010       //参数错误,投递数据失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_POST_MAXCOUNT 0x50E5011       //达到最大队列大小
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_POST_NOTFOUND 0x50E5012       //没有找到指定队列
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_PARAMENT 0x50E5020        //参数错误,获取失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_IDNONE 0x50E5021          //空的队列
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_NOTFOUND 0x50E5022        //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_BUSY 0x50E5023            //指定队列忙碌中
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_ISNULL 0x50E5024          //指定队列为空
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_NOCOMPLETE 0x50E5025      //没有完成的包
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_SMALL 0x50E5026           //提供的缓冲区过小
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_WAITEVENT_NOTFOUND 0x50E5050  //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_WAITEVENT_TIMEOUT 0x50E5051   //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_WAITEVENT_NOPACKET 0x50E5052  //没有包,错误的激活行为
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_ACTIVE_NOTFOUND 0x50E5060     //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_PUSH_MAXSIZE 0x50E5070        //包大小超过系统内部限制
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_PUSH_MALLOC 0x50E5071         //申请内存失败
//////////////////////////////////////////////////////////////////////////
//                       缓存队列错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_POST_PARAMENT 0x50E6001        //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_POST_MAXCOUNT 0x50E6002        //最大队列
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_POST_MALLOC 0x50E6003          //申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_GET_PARAMENT 0x50E6010         //获取失败,参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_GET_EMPTY 0x50E6011            //空的队列
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_EVENT_TIMEOUT 0x50E6020        //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_CACHE_EVENT_NOPACKET 0x50E6021       //没有数据