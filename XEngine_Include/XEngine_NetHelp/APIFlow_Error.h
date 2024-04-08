#pragma once
/********************************************************************
//    Created:     2024/04/02  14:17:04
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIFlow\APIFlow_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIFlow
//    File Base:   APIFlow_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     流量接口错误导出表
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       网络流量获取错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_APIFLOW_NET_GETFLOW_PARAMT 0x60A0000          //参数传递错误
#define ERROR_NETHELP_APIFLOW_NET_GETFLOW_EXE 0x60A001              //执行命令失败
#define ERROR_NETHELP_APIFLOW_NET_GETFLOW_NOTFOUND 0x60A002         //获取流量失败，没有找到网卡信息
#define ERROR_NETHELP_APIFLOW_NET_GETFLOW_ISFAILED 0x60A003         //内部错误
#define ERROR_NETHELP_APIFLOW_NET_GETFLOW_STATUS 0x60A004           //找到了网卡,但是网卡状态不对(没启用或者网卡没有联网)
#define ERROR_NETHELP_APIFLOW_NET_GETFLOW_MALLOC 0x60A005           //申请内存失败
//////////////////////////////////////////////////////////////////////////
//                       流量控制错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_NETHELP_APIFLOW_CTRL_INIT_PARAMENT 0x60A1000           //初始化失败,参数错误
#define ERROR_NETHELP_APIFLOW_CTRL_INIT_CLEAR 0x60A1001              //清理设备QOS失败
#define ERROR_NETHELP_APIFLOW_CTRL_INIT_REG 0x60A1002                //初始化失败,注册失败
#define ERROR_NETHELP_APIFLOW_CTRL_INIT_ENUM 0x60A1003               //枚举设备失败
#define ERROR_NETHELP_APIFLOW_CTRL_INIT_MALLOC 0x60A1004             //申请内存失败
#define ERROR_NETHELP_APIFLOW_CTRL_INIT_OPEN 0x60A1005               //打开设备失败
#define ERROR_NETHELP_APIFLOW_CTRL_ADDFLOW_PARAMENT 0x60A1010        //添加失败,参数错误
#define ERROR_NETHELP_APIFLOW_CTRL_ADDFLOW_NOTFOUND 0x60A1011        //没有找到主句柄
#define ERROR_NETHELP_APIFLOW_CTRL_ADDFLOW_MALLOC 0x60A1012          //申请内存失败
#define ERROR_NETHELP_APIFLOW_CTRL_ADDFLOW_ISFAILED 0x60A1013        //添加流量规则失败
#define ERROR_NETHELP_APIFLOW_CTRL_ADDFLOW_FILTER 0x60A1014          //添加过滤器失败