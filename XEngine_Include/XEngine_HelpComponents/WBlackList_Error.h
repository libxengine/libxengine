﻿#pragma once
/********************************************************************
//    Created:     2024/03/29  16:48:02
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_HelpComponents\HelpComponents_WBlackList\WBlackList_Error.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_HelpComponents\HelpComponents_WBlackList
//    File Base:   WBlackList_Error
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     黑白名单列表模块导出错误
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       IPV4黑名单错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_INIT_PARAMENT 0x50A0001       //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_INIT_MALLOC 0x50A0002         //申请内存失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ADD_PARAMENT 0x50A0010        //添加失败,参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ADD_NOTFOUND 0x50A0011        //没有找到指定句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ADD_ISEXIST 0x50A0012         //添加的黑名单已经存在了
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_IPC_ADDRSTART 0x50A0020       //解析开始地址失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_IPC_ADDREND 0x50A0021         //解析结束地址失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_IPC_NOTSUPPORT 0x50A0022      //不支持的通配符方式
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEXIST_ALLNONE 0x50A0030     //全部为过滤,这个设置没有任何效果
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEXIST_EXIST 0x50A0031       //已经存在
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEXIST_RANGE 0x50A0032       //在范围内
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_GET_PARAMENT 0x50A0040        //参数错误,获取失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_GET_NOTFOUND 0x50A0041        //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_GET_ISNULL 0x50A0042          //列表为空
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEBLACK_PARAMENT 0x50A0050   //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEBLACK_NOTIPADDR 0x50A0051  //不是标准的IP地址
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEBLACK_NOTFOUND 0x50A0052   //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ISEBLACK_NOTEXIST 0x50A0053   //这个IP地址不存在
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ADDWHITE_PARAMENT 0x50A0060   //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV4ADDR_ADDWHITE_NOTFOUND 0x50A0061   //没有找到句柄
//////////////////////////////////////////////////////////////////////////
//                       域名黑名单错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_INIT_PARAMENT 0x50A1001     //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_INIT_MALLOC 0x50A1002       //申请内存失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ADD_PARAMENT 0x50A1011      //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ADD_NOTFOUND 0x50A1012      //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ADD_ISEXIST 0x50A1013       //已经存在于黑名单
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_GET_PARAMENT 0x50A1020      //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_GET_NOTFOUND 0x50A1021      //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_GET_ISNULL 0x50A1022        //黑名单列表为空
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ISEBLACK_PARAMENT 0x50A1030 //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ISEBLACK_NOTFOUND 0x50A1031 //检查失败,没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ISEBLACK_NOTEXIST 0x50A1032 //不存在黑名单
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ADDWHITE_PARAMENT 0x50A1040 //添加失败,参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_ADDWHITE_NOTFOUND 0x50A1041 //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_DOMAINADDR_CONVERT_NOTDOMAIN 0x50A1050  //这个域名不正确
//////////////////////////////////////////////////////////////////////////
//                       IPV4黑名单错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_INIT_PARAMENT 0x50A2001       //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_INIT_MALLOC 0x50A2002         //申请内存失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ADD_PARAMENT 0x50A2010        //添加失败,参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ADD_NOTFOUND 0x50A2011        //没有找到指定句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ADD_ISEXIST 0x50A2012         //添加的黑名单已经存在了
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_IPC_ADDRSTART 0x50A2020       //解析开始地址失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_IPC_ADDREND 0x50A2021         //解析结束地址失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_IPC_NOTSUPPORT 0x50A2022      //不支持的通配符方式
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEXIST_ALLNONE 0x50A2030     //全部为过滤,这个设置没有任何效果
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEXIST_EXIST 0x50A2031       //已经存在
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEXIST_RANGE 0x50A2032       //在范围内
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_GET_PARAMENT 0x50A2040        //参数错误,获取失败
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_GET_NOTFOUND 0x50A2041        //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_GET_ISNULL 0x50A2042          //列表为空
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEBLACK_PARAMENT 0x50A2050   //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEBLACK_NOTIPADDR 0x50A2051  //不是标准的IP地址
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEBLACK_NOTFOUND 0x50A2052   //没有找到句柄
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ISEBLACK_NOTEXIST 0x50A2053   //这个IP地址不存在
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ADDWHITE_PARAMENT 0x50A2060   //参数错误
#define ERROR_HELPCOMPONENTS_WBLACKLIST_IPV6ADDR_ADDWHITE_NOTFOUND 0x50A2061   //没有找到句柄
