#pragma once
/********************************************************************
//	Created:	2012/1/24  16:25
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_NetXApi\NetXApi_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngineCore\NetEngine_NetXApi
//	File Base:	NetXApi_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	网络XAPI 错误导出表
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       网络嗅探器错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_NETXAPI_SNIFFER_START_PARAMENT 0x20C1001            //参数错误
#define ERROR_XCORE_NETXAPI_SNIFFER_START_MALLOC 0x20C1002              //申请内存失败
#define ERROR_XCORE_NETXAPI_SNIFFER_START_SOCKET 0x20C1003              //打开句柄失败
#define ERROR_XCORE_NETXAPI_SNIFFER_START_BIND 0x20C1004                //绑定端口失败
#define ERROR_XCORE_NETXAPI_SNIFFER_START_IOCTL 0x20C1005               //IOCTL错误
#define ERROR_XCORE_NETXAPI_SNIFFER_START_THREAD 0x20C1006              //启动线程失败
#define ERROR_XCORE_NETXAPI_SNIFFER_FILTER_NOTFOUND 0x20C1010           //过滤器设置失败,句柄没有找到
//////////////////////////////////////////////////////////////////////////
//                       网络流量获取错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_PARAMT 0x20C20000          //参数传递错误
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_EXE 0x20C2001              //执行命令失败
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_NOTFOUND 0x20C2002         //获取流量失败，没有找到网卡信息
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_ISFAILED 0x20C2003         //内部错误
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_STATUS 0x20C2004           //找到了网卡,但是网卡状态不对(没启用或者网卡没有联网)
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_MALLOC 0x20C2005           //申请内存失败
//流量控制错误
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_PARAMENT 0x20C3000           //初始化失败,参数错误
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_CLEAR 0x20C3001              //清理设备QOS失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_REG 0x20C3002                //初始化失败,注册失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_ENUM 0x20C3003               //枚举设备失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_MALLOC 0x20C3004             //申请内存失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_OPEN 0x20C3005               //打开设备失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_PARAMENT 0x20C3010        //添加失败,参数错误
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_NOTFOUND 0x20C3011        //没有找到主句柄
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_MALLOC 0x20C3012          //申请内存失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_ISFAILED 0x20C3013        //添加流量规则失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_FILTER 0x20C3014          //添加过滤器失败
//////////////////////////////////////////////////////////////////////////
//                    套接字函数错误导出
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                    TCP-UDP端口获取列表导出错误表                     */
/************************************************************************/
#define ERROR_XCORE_NETXAPI_SOCKET_ISPORTUSED_NOTFOUND 0x10A5001    //没有找到
#define ERROR_XCORE_NETXAPI_SOCKET_ISPORTUSED_NOTSUPPORT 0x10A5002  //不支持的协议
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_PARAMENT 0x10A5010                //参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_TCPV4_MALLOCFORTABLE 0x10A5011    //申请内存失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_TCPV4_GETTABLEFAILED 0x10A5012    //获取TCP列表失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_UDPV4_MALLOCFORTABLE 0x10A5013    //申请内存失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_UDPV4_GETTABLEFAILED 0x10A5015    //获取UDP列表失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_NOTFOUND 0x10A5016                //没有找到指定端口，这个端口没有被使用
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_GETAPPNAME 0x10A5017          //获取应用程序名称失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_GETAPPPID 0x10A5018           //获取应用程序PID失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_GETUSERNAME 0x10A5019         //获取所属用户失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_GETIPVERSION 0x10A501A        //获取协议版本失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_GETPROTOCOL 0x10A501B         //获取协议类型失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETPORTSTATE_GETSTATE 0x10A501C            //获取状态失败
#define ERROR_XCORE_NETXAPI_SOCKET_PIDTONAME_OPENPID 0x10A5020                //打开PID失败
#define ERROR_XCORE_NETXAPI_SOCKET_PIDTONAME_ENUMFIRST 0x10A5021              //枚举第一个列表失败
#define ERROR_XCORE_NETXAPI_SOCKET_PIDTONAME_NOTFOUND 0x10A5022               //没有找到指定的PID
#define ERROR_XCORE_NETXAPI_SOCKET_GETADDRESS_PARAMENT 0x10A5030              //参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_GETADDRESS_FAILED 0x10A5031                //处理失败,可能不是套接字
#define ERROR_XCORE_NETXAPI_SOCKET_GETADDRESS_CONVERT 0x10A5032               //转换失败
/************************************************************************/
/*                     网络连接类型错误导出表                           */
/************************************************************************/
#define ERROR_XCORE_NETXAPI_SOCKET_NETCONNECTTYPE_NOCONNECT 0x10A5110         //可能没有连接，可能发生底层错误
#define ERROR_XCORE_NETXAPI_SOCKET_NETCONNECTTYPE_UNKNOW 0x10A5111            //无法识别的错误
//进程网络连接状态设置获取错误表
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_SET_ISFAILED 0x10A5120   //设置进程连接状态失败
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_SET_NOTSUPPET 0x10A5121  //不支持的状态设置
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_PARAMENT 0x10A5130//参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_OPEN 0x10A5131   //打开失败
/************************************************************************/
/*                     网络地址获取                                     */
/************************************************************************/
#define ERROR_XCORE_NETXAPI_SOCKET_DOMAINTOADDR_PARAMENT 0x10A5300        //解析失败,参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_DOMAINTOADDR_NOTDOMAIN 0x10A5301       //不是域名或者没有连接网络
#define ERROR_XCORE_NETXAPI_SOCKET_DOMAINTOADDR_EMPTY 0x10A5302           //空的列表
#define ERROR_XCORE_NETXAPI_SOCKET_GETIPADDR_MALLOC 0x10A5310             //申请内存失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETIPADDR_ISFAILED 0x10A5311           //处理失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETFILE_ISFAILED 0x10A5320             //打开文件失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETFILE_BUFFER 0x10A5321               //获取内容失败