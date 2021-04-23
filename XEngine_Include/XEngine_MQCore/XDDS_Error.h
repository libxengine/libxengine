#pragma once
/********************************************************************
//	Created:	2018/1/6   20:13
//	Filename: 	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_XMQCore/NetEngine_XMDDService/XMDDS_Error.h
//	File Path:	/NetEngine_Linux/NetEngine_SourceCode/NetEngine_XMQCore/NetEngine_XMDDService/
//	File Base:	XMDDS_Error
//	File Ext:	h
//  Project:    NetEngine_Linux(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	导出的错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       DDS服务公有API导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_INIT_CREATETHREAD 0x160A1000   //创建线程失败
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_CREATEDOMAIN_NOINIT 0x160A1010 //没有初始化，无法创建域
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETEDOMAIN_NOTFOUND 0x160A1020  //删除域失败，没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_PARAMENT 0x160A1020   //参数错误，无法继续
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_NOINIT 0x160A1021     //没有初始化
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_NOTDOMAIN 0x160A1022  //没有找到域
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_FAILED 0x160A1023     //内部严重错误
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_PARAMENT 0x160A1030   //参数错误
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_NOINIT 0x160A1031     //没有初始化
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_NOTDOMAIN 0x160A1032  //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_NOTTOPIC 0x160A1033   //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICGET_PARAMENT 0x160A1040      //参数错误
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICGET_NOTDOMAIN 0x160A1041     //没有找到域
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICGET_NOTTOPIC 0x160A1042      //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICGET_EMPTY 0x160A1043         //主题列表为空
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ADDPUBLISH_NOTDOMAIN 0x160A1050   //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ADDPUBLISH_NOTTOPIC 0x160A1051    //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELPUBLISH_NOTDOMAIN 0x160A1060   //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELPUBLISH_NOTTOPIC 0x160A1061    //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_GETINFO_NOTFOUND 0x160A1070       //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ALLOCIP_FULL 0x160A1071          //没有找到主题
//////////////////////////////////////////////////////////////////////////
//                       发布者错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_CREATE_PARAMENT 0x160A2001      //参数错误，无法创建发布者
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_CREATE_NOTPORTRES 0x160A2003    //没有可用的资源了
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_SEND_PARAMENT 0x160A2010        //发送数据失败，参数错误
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_SEND_NOTPUB 0x160A2011          //没有找到发布者
//////////////////////////////////////////////////////////////////////////
//                       订阅者错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_CREATE_PARAMENT 0x1602A01     //参数错误，创建失败
#define ERROR_XENGINE_MQCORE_XDDS_SUBCRIBE_INSERT_PARAMENT 0x1602A10      //参数错误
#define ERROR_XENGINE_MQCORE_XDDS_SUBCRIBE_INSERT_NOTFOUND 0x1602A11      //没有找到
#define ERROR_XENGINE_MQCORE_XDDS_SUBCRIBE_INSERT_NOTMATCH 0x1602A12      //不匹配,不需要加入
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_READ_PARAMENT 0x1602A20       //读取数据失败，参数错误
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_READ_NOTSUB 0x1602A21         //没有找到订阅者
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_READ_NOMSG 0x1602A23          //没有消息可以读取

