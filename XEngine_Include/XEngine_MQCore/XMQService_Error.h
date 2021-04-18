#pragma once
/********************************************************************
//    Created:     2020/12/23  20:53:51
//    File Name:   H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_XMQCore\MQCore_XMQService\XMQService_Error.h
//    File Path:   H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_XMQCore\MQCore_XMQService
//    File Base:   XMQService_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     消息队列导出错误
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       消息队列错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XMQ_SERVICE_INIT_CREATETHREAD 0x160A0000          //初始化失败，创建线程失败
#define ERROR_XENGINE_XMQ_SERVICE_POST_PARAMENT 0x160A0010              //参数错误，投递失败
#define ERROR_XENGINE_XMQ_SERVICE_POST_MALLOC 0x160A0011                //申请内存失败，无法继续
#define ERROR_XENGINE_XMQ_SERVICE_PUSHLIST_ADDRKEEPNULL 0x160A0020      //投递失败，地址参数和时间不能同时为空
#define ERROR_XENGINE_XMQ_SERVICE_PUSHLIST_MAXSIZE 0x160A0021           //最大包个数，无法继续投递
#define ERROR_XENGINE_XMQ_SERVICE_PUSHLIST_SERIALEXIST 0x160A0022       //序列号已经存在，无法继续投递
#define ERROR_XENGINE_XMQ_SERVICE_PUSHMAP_MAXSIZE  0x160A0030           //最大包个数，无法继续
#define ERROR_XENGINE_XMQ_SERVICE_PUSHMAP_SERIALEXIST 0x160A0031        //包序列号已经存在，无法继续
#define ERROR_XENGINE_XMQ_SERVICE_GETLIST_EMPTY 0x160A0040              //获取数据失败，列表容器为空
#define ERROR_XENGINE_XMQ_SERVICE_GETLIST_NOTFOUND 0x160A0041           //获取失败，没有找到指定序列数据
#define ERROR_XENGINE_XMQ_SERVICE_GETLIST_LEN 0x160A0042                //长度错误，提供的缓冲区太小了
#define ERROR_XENGINE_XMQ_SERVICE_GETMAP_EMPTY 0x160A0050               //获取数据失败，KEY容器列表为空
#define ERROR_XENGINE_XMQ_SERVICE_GETMAP_NOTFOUND 0x160A0051            //没有找到指定序列数据
#define ERROR_XENGINE_XMQ_SERVICE_GETMAP_LEN 0x160A0052                 //数据长度不够
#define ERROR_XENGINE_XMQ_SERVICE_GET_PARAMENT 0x160A0060               //参数错误，无法继续
#define ERROR_XENGINE_XMQ_SERVICE_GET_SERIAL 0x160A0061                 //取值失败,序列号不正确
#define ERROR_XENGINE_XMQ_SERVICE_DEL_PARAMENT 0x160A0070               //删除失败，参数错误
//////////////////////////////////////////////////////////////////////////
//                       消息协议错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XMQ_PROTOCOL_REQPACKET_PARAMENT 0x160A1000        //参数错误
#define ERROR_XENGINE_XMQ_PROTOCOL_REPPACKET_PARAMENT 0x160A1010        //参数错误
#define ERROR_XENGINE_XMQ_PROTOCOL_REQLOGIN_PARAMENT 0x160A1020         //参数错误
#define ERROR_XENGINE_XMQ_PROTOCOL_REPLOGIN_PARAMENT 0x160A1030         //参数错误
//////////////////////////////////////////////////////////////////////////
//                       用户管理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_XMQ_USER_INSERT_PARAMENT 0x160A2000               //插入失败,参数错误
#define ERROR_XENGINE_XMQ_USER_GETSERIAL_PARAMENT 0x160A2010            //获取序列号失败,参数错误
#define ERROR_XENGINE_XMQ_USER_GETSERIAL_NOTFOUND 0x160A2020            //没有找到
#define ERROR_XENGINE_XMQ_USER_SETSERIAL_PARAMENT 0x160A2030            //参数错误
#define ERROR_XENGINE_XMQ_USER_SETSERIAL_NOTFOUND 0x160A2031            //设置失败,没有找到
