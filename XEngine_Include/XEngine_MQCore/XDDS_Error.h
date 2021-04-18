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
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_CREATEDOMAIN_NOINIT 0x160A1010//没有初始化，无法创建域
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETEDOMAIN_NOTFOUND 0x160A1020  //删除域失败，没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_PARAMENT 0x160A1020   //参数错误，无法继续
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_NOINIT 0x160A1021     //没有初始化
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_TOPICCREATE_NOTDOMAIN 0x160A1022  //没有找到域
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_PARAMENT 0x160A1030   //参数错误
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_NOINIT 0x160A1031     //没有初始化
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_NOTDOMAIN 0x160A1032  //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELETETOPIC_NOTTOPIC 0x160A1033   //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_GETTOPIC_NOINIT 0x160A1040      //没有初始化，无法继续
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_GETTOPIC_NOTDOMAIN 0x160A1041   //没有域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_GETTOPIC_NOTTOPIC 0x160A1042    //没有这个主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_REQCREATETOPIC_NOTINIT 0x160A1050 //没有初始化
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_REQCREATETOPIC_NOTFOUND 0x160A1051//没有找到
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ACKCREATETOPIC_NOTDOMAIN 0x160A1060    //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ACKCREATETOPIC_NOTCREATER 0x160A1061   //没有找到创建者
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ADDTOPIC_NOTDOMAIN 0x160A1070 //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ADDTOPIC_NOTTOPIC 0x160A1071  //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELTOPIC_NOTDOMAIN 0x160A1080 //没有找到域ID
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_DELTOPIC_NOTTOPIC 0x160A1081  //没有找到主题
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_REQCREATEDOMAIN_NOTINIT 0x160A1090    //请求域ID列表失败,没有初始化
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_ALLOCIP_FULL 0x160A10A0       //所有IP地址范围已经分配完毕,无法继续
#define ERROR_XENGINE_MQCORE_XDDS_COMMAPI_GETINFO_NOTFOUND 0x160A10B0   //没有这个域ID存在的信息
//////////////////////////////////////////////////////////////////////////
//                       发布者错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_CREATE_PARAMENT 0x160A2001    //参数错误，无法创建发布者
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_CREATE_NOTPORT 0x160A2002     //没有找到可用端口
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_CREATE_NOTPORTRES 0x160A2003
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_DELETE_NOTFOUND 0x160A2010    //删除发布者失败，没有找到句柄
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_SEND_PARAMENT 0x160A2020      //发送数据失败，参数错误
#define ERROR_XENGINE_MQCORE_XDDS_PUBLISH_SEND_NOTPUB 0x160A2021        //没有找到发布者
//////////////////////////////////////////////////////////////////////////
//                       订阅者错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_CREATE_PARAMENT 0x1602A01  //参数错误，创建失败
#define ERROR_XENGINE_MQCORE_XDDS_SUBCRIBE_DELETE_NOTFOUND 0x1602A10   //没有找到订阅者
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_READ_PARAMENT 0x1602A20    //读取数据失败，参数错误
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_READ_NOTSUB 0x1602A21      //没有找到订阅者
#define ERROR_XENGINE_MQCORE_XDDS_SUBSCRIBE_READ_NOMSG 0x1602A23       //没有消息可以读取

