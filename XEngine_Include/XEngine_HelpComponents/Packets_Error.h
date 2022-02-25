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
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_PARAMENT 0x70D0001        //投递包失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_MAXCOUNT 0x70D0002        //最大包个数，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_NOTFOUND 0x70D0003        //投递失败,没有找到客户端ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_POST_MALLOC 0x70D0004          //申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_PUSH_MALLOCHDR 0x70D0011       //申请协议头内存失败了
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_PUSH_NOTMATCH 0x70D0012        //协议不匹配，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_PUSH_MALLOC 0x70D0013          //申请数据缓冲区失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CREATE_MALLOCROOT 0x70D0020    //申请根内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CREATE_MALLOCNOTE 0x70D0021    //申请节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CREATE_NOTPOOL 0x70D0022       //没有找到分布池索引
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CLEAR_PARAMENT 0x70D0030       //清理失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_CLEAR_NOTFOUND 0x70D0032       //清理失败，没有找到ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_DELETE_PARAMENT 0x70D0040      //删除失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_DELETE_NOTFOUND 0x70D0042      //删除失败，没有找到ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_PARAMENT 0x70D0051         //分解包失败，获取失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_IDNONE 0x70D0053           //没有任何ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_NOTFOUND 0x70D0054         //没有找到此ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_ISNULL 0x70D0055           //这个ID没有任何数据包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_NOCOMPLETE 0x70D0056       //不是一个完成的包，需要等待组建
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_ISLEAVEPKT 0x70D0057       //这个包是一个离开包，需要删除
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_PKTNULL 0x70D0058          //有数据长度但是无数据，可能内部有问题
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_SMALL 0x70D0059            //给出的缓冲区长度太小！无法满足
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GET_BUSY 0x70D005A             //无法获取锁,这个包正在被操作
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETRONDOM_PARAMENT 0x70D0060   //参数错误,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETRONDOM_ISNULL 0x70D0061     //没有可用包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_WAITEVENT_NOTFOUND 0x70D0070   //没有找到指定池
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_WAITEVENT_NOPACKET 0x70D0071   //没有包,错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_WAITEVENT_TIMEOUT 0x70D0072    //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_PARAMENT 0x70D0080   //参数凑无,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_NONE 0x70D0081       //获取失败,没有可用包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_ISLEAVEPKT 0x70D0082 //是一个离开包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETSINGLE_SMALL 0x70D0083      //提供的缓冲区大小不足够
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_BUILDCHUNK_MALLOC 0x70D0090    //构建CHUNK申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETLIST_PARAMENT 0x70D00A0     //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETLIST_EMPTY 0x70D00A1        //空的队列
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETPOOL_PARAMENT 0x70D00B0     //没有参数
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETPOOL_NOTENABLE 0x70D00B1    //此功能没有启用
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_GETPOOL_NOTFOUND 0x70D00B2     //没有找到索引
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOL_ACTIVE_NOTFOUND 0x70D00C0      //没有找到指定池
//////////////////////////////////////////////////////////////////////////
//                       扩展组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_EX_MALLOC 0x70D1001
#define ERROR_HELPCOMPONENTS_PACKETS_EX_NOTFOUND 0x70D1002
//////////////////////////////////////////////////////////////////////////
//                       包处理帮助错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_HELP_BUILDPACKET_PARAMENT 0x70D2001 //参数错误，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_HELP_BUILDPACKET_LEN 0x70D2002      //长度有问题
#define ERROR_HELPCOMPONENTS_PACKETS_HELP_REWRITEHDR_PARAMENT 0x70D2010  //参数错误
//////////////////////////////////////////////////////////////////////////
//                       文件包处理错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_CREATEFILE_PARMENT 0x70D3001    //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_CREATEFILE_NOTFOUND 0x70D3002   //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_CREATEFILE_NOTCOMPLETE 0x70D3003  //组包未完成
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_CREATEFILE_ISFAILED 0x70D3004   //创建文件失败
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_CREATEFILE_EXIST 0x70D3005      //文件已经存在
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_POST_PARMENT 0x70D3010          //参数错误,投递失败
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_POST_NOTFOUND 0x70D3011         //没有找到这个客户端地址
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_POST_HDRNOTCOMPLETE 0x70D3012   //协议头没有组完,无法使用此函数
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_POST_COMPLETE 0x70D3013         //这个文件数据已经组完
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_POST_NOUPFILE 0x70D3014         //不是上传请求
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_POST_NOTCREATE 0x70D3015        //你还没有创建文件,无法组包
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETHDR_PARAMENT 0x70D3020       //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETHDR_NOTFOUND 0x70D3021       //没有找到客户端
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETSTATUS_PARMENT 0x70D3030     //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETSTATUS_NOTFOUND 0x70D3031    //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETSTATUS_NOTCOMPLETE 0x70D3032 //没有组好文件
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETFILE_PARMENT 0x70D3040       //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETFILE_NOTFOUND 0x70D3041      //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETFILE_HDRNOTCOMPLETE 0x70D3042//头没有组好包
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETFILE_COMPLETE 0x70D3043      //已经完成组包
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETFILE_NOGETFILE 0x70D3044     //不是获取文件请求,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETFILE_NOTOPEN 0x70D3045       //没有打开文件,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_SETINFO_PARMENT 0x70D3050       //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_SETINFO_NOTFOUND 0x70D3051      //没有找到客户端
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_SETINFO_MALLOC 0x70D3052        //申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETINFO_PARMENT 0x70D3060       //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_GETINFO_NOTFOUND 0x70D3061      //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_PARSEHDR_PARMENT 0x70D3070      //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_PARSEHDR_NOTFOUND 0x70D3071     //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_PARSEHDR_HDRCOMPLETE 0x70D3072  //包已经租好了
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_PARSEHDR_NOTCOMPLETE 0x70D3073  //组包失败,缓冲区大小不足够
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_PARSEHDR_HDR 0x70D3074        //协议头错误
#define ERROR_HELPCOMPONENTS_PACKETS_FILE_PARSEHDR_PROTOCOL 0x70D3075   //协议错误,不是文件传输协议
//////////////////////////////////////////////////////////////////////////
//                       扩展协议组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_PARAMENT 0x70D4001        //投递包失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_MAXCOUNT 0x70D4002        //最大包个数，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_NOTFOUND 0x70D4003        //投递失败,没有找到客户端ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_POST_MALLOC 0x70D4004          //申请内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_PUSH_NOTMATCH 0x70D4012        //协议不匹配，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_PUSH_MALLOC 0x70D4013          //申请数据缓冲区失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_CREATE_MALLOCROOT 0x70D4020    //申请根内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_CREATE_MALLOCNOTE 0x70D4021    //申请节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_CREATE_NOTPOOL 0x70D4022       //没有可用池
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETPOOL_PARAMENT 0x70D4030     //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETPOOL_NOTENABLE 0x70D4031    //没有启用
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETPOOL_NOTFOUND 0x70D4032     //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_PARAMENT 0x70D4051         //分解包失败，获取失败，参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_IDNONE 0x70D4053           //没有任何ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_NOTFOUND 0x70D4054         //没有找到此ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_ISNULL 0x70D4055           //这个ID没有任何数据包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_NOCOMPLETE 0x70D4056       //不是一个完成的包，需要等待组建
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_PKTNULL 0x70D4057          //有数据长度但是无数据，可能内部有问题
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_SMALL 0x70D4058            //给出的缓冲区长度太小！无法满足
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GET_BUSY 0x70D4059             //无法获取锁,这个包正在被操作
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETRONDOM_PARAMENT 0x70D4060   //参数错误,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETRONDOM_ISNULL 0x70D4061     //没有可用包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_WAITEVENT_NOPACKET 0x70D4071   //没有包,错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_WAITEVENT_TIMEOUT 0x70D4072    //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_WAITEVENT_NOTFOUND 0x70D4073   //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETSINGLE_PARAMENT 0x70D4080   //参数凑无,无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETSINGLE_NONE 0x70D4081       //获取失败,没有可用包
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETSINGLE_SMALL 0x70D4082      //提供的缓冲区大小不足够
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_BUILD_TAIL 0x70D4090           //协议尾部不正确，包已经被抛弃
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_BUILD_CHECK 0x70D4091          //校验码不正确
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_PARAMENT 0x70D40A0      //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_NONE 0x70D40A1          //获取失败，队列没有任何数据
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_NOTFOUND 0x70D40A2      //没有找到ID
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_BUSY 0x70D40A3          //队列忙碌，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_ISNULL 0x70D40A4        //这个ID没有数据
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_NOCOMPLETE 0x70D40A5    //没有组好包，无法继续
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETALL_SMALL 0x70D40A6         //缓冲区太小
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETLIST_PARAMENT 0x70D40B0     //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_GETLIST_EMPTY 0x70D40B1        //空的队列
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_ACTIVE_NOTFOUND 0x70D40C0      //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_PROTOCOLEX_BUILDCHUNK_MALLOC 0x70D40D0
//////////////////////////////////////////////////////////////////////////
//                       自定义协议组包器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_CREATE_NOTPOOL 0x70D5001      //没有创建分布池
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_CREATE_MALLOCROOT 0x70D5002   //申请根节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_CREATE_MALLOCNOTE 0x70D5003   //申请节点内存失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_POST_PARAMENT 0x70D5010       //参数错误,投递数据失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_POST_MAXCOUNT 0x70D5011       //达到最大队列大小
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_POST_NOTFOUND 0x70D5012       //没有找到指定队列
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_PARAMENT 0x70D5020        //参数错误,获取失败
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_IDNONE 0x70D5021          //空的队列
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_NOTFOUND 0x70D5022        //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_BUSY 0x70D5023            //指定队列忙碌中
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_ISNULL 0x70D5024          //指定队列为空
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_NOCOMPLETE 0x70D5025      //没有完成的包
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GET_SMALL 0x70D5026           //提供的缓冲区过小
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GETLIST_PARAMENT 0x70D5030    //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GETLIST_EMPTY 0x70D5031       //空队列
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GETPOOL_PARAMENT 0x70D5040    //参数错误
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GETPOOL_NOTENABLE 0x70D5041   //此功能没有启用
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_GETPOOL_NOTFOUND 0x70D5042    //没有找到指定分布池任务
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_WAITEVENT_NOTFOUND 0x70D5050  //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_WAITEVENT_TIMEOUT 0x70D5051   //等待超时
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_WAITEVENT_NOPACKET 0x70D5052  //没有包,错误的激活行为
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_ACTIVE_NOTFOUND 0x70D5060     //没有找到
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_PUSH_MAXSIZE 0x70D5070        //包大小超过系统内部限制
#define ERROR_HELPCOMPONENTS_PACKETS_CUSTOM_PUSH_MALLOC 0x70D5071         //申请内存失败
