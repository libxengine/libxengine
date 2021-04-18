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
//                       网络地址表错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_NETXAPI_NETADDRESS_QQWAY_OPEN_PARAMENT 0x10C0000    //参数错误
#define ERROR_XCORE_NETXAPI_NETADDRESS_QQWAY_OPEN_OPENFILE 0x10C0001    //打开文件失败
#define ERROR_XCORE_NETXAPI_NETADDRESS_QQWAY_OPEN_NOTIPDATA 0x10C0002   //不是IP数据库文件
#define ERROR_XCORE_NETXAPI_NETADDRESS_QQWAY_IPTO_PARAMENT 0x10C0010    //参数错误
#define ERROR_XCORE_NETXAPI_NETADDRESS_QQWAY_IPTO_NOTOPEN 0x10C0011     //没有打开数据库
#define ERROR_XCORE_NETXAPI_NETADDRESS_QQWAY_IPTO_NOTFOUND 0x10C0012    //没有找到指定IP地址数据
//////////////////////////////////////////////////////////////////////////
//                       网络嗅探器错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_NETXAPI_SNIFFER_START_PARAMENT 0x10C1001            //参数错误
#define ERROR_XCORE_NETXAPI_SNIFFER_START_MALLOC 0x10C1002              //申请内存失败
#define ERROR_XCORE_NETXAPI_SNIFFER_START_OPENDEV 0x10C1003             //打开设备失败
#define ERROR_XCORE_NETXAPI_SNIFFER_START_THREAD 0x10C1004              //启动线程失败
#define ERROR_XCORE_NETXAPI_SNIFFER_FILTER_NOTFOUND 0x10C1010           //过滤器设置失败,句柄没有找到
#define ERROR_XCORE_NETXAPI_SNIFFER_FILTER_COMPILE 0x10C1011            //编译过滤器失败,可能语法错误
#define ERROR_XCORE_NETXAPI_SNIFFER_FILTER_SET 0x10C1012                //设置失败,内部错误
#define ERROR_XCORE_NETXAPI_SNIFFER_WRITE_NOTFOUND 0x10C1020            //没有找到句柄
#define ERROR_XCORE_NETXAPI_SNIFFER_WRITE_OPEN 0x10C1021                //创建文件失败
#define ERROR_XCORE_NETXAPI_SNIFFER_GETIF_PARAMENT 0x10C1030            //参数错误
#define ERROR_XCORE_NETXAPI_SNIFFER_GETIF_FIND 0x10C1031                //没有找到设备
#define ERROR_XCORE_NETXAPI_SNIFFER_GETIF_EMPTY 0x10C1032               //设备列表为空
//////////////////////////////////////////////////////////////////////////
//                       网络流量获取错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_PARAMT 0x10C20000          //参数传递错误
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_EXE 0x10C2001              //执行命令失败
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_NOTFOUND 0x10C2002         //获取流量失败，没有找到网卡信息
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_ISFAILED 0x10C2003         //内部错误
#define ERROR_XCORE_NETXAPI_FLOW_NET_GETFLOW_STATUS 0x10C2004           //找到了网卡,但是网卡状态不对(没启用或者网卡没有联网)
//流量控制错误
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_PARAMENT 0x10C3000           //初始化失败,参数错误
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_CLEAR 0x10C3001              //清理设备QOS失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_REG 0x10C3002                //初始化失败,注册失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_ENUM 0x10C3003               //枚举设备失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_MALLOC 0x10C3004             //申请内存失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_INIT_OPEN 0x10C3005               //打开设备失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_PARAMENT 0x10C3010        //添加失败,参数错误
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_NOTFOUND 0x10C3011        //没有找到主句柄
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_MALLOC 0x10C3012          //申请内存失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_ISFAILED 0x10C3013        //添加流量规则失败
#define ERROR_XCORE_NETXAPI_FLOW_CTRL_ADDFLOW_FILTER 0x10C3014          //添加过滤器失败
//////////////////////////////////////////////////////////////////////////
//                       枚举局域网计算机信息错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_NETXAPI_LANENUM_START_PARAMENT 0x10C4001            //参数错误
#define ERROR_XCORE_NETXAPI_LANENUM_START_MALLOC 0x10C4002              //申请内存失败
#define ERROR_XCORE_NETXAPI_LANENUM_START_OPENDEV 0x10C4003             //打开设备失败
#define ERROR_XCORE_NETXAPI_LANENUM_START_COMPILE 0x10C4004             //编译失败
#define ERROR_XCORE_NETXAPI_LANENUM_START_SETFILTER 0x10C4005           //设置过滤器失败
#define ERROR_XCORE_NETXAPI_LANENUM_START_THREAD 0x10C4006              //启动线程失败
#define ERROR_XCORE_NETXAPI_LANENUM_GETCARD_SOCKET 0x10C4010            //创建套接字失败
#define ERROR_XCORE_NETXAPI_LANENUM_GETCARD_FAILED 0x10C4011            //获取网卡信息内部错误
#define ERROR_XCORE_NETXAPI_LANENUM_GETCARD_NOTFOUND 0x10C4012          //没有找到指定网卡
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
/************************************************************************/
/*                     网络连接类型错误导出表                           */
/************************************************************************/
#define ERROR_XCORE_NETXAPI_SOCKET_NETCONNECTTYPE_NOCONNECT 0x10A5110         //可能没有连接，可能发生底层错误
#define ERROR_XCORE_NETXAPI_SOCKET_NETCONNECTTYPE_UNKNOW 0x10A5111            //无法识别的错误
#define ERROR_XCORE_NETXAPI_SOCKET_ROTOCOLSTATICS_IPINFO 0x10A5112            //获取IP状态信息失败
#define ERROR_XCORE_NETXAPI_SOCKET_ROTOCOLSTATICS_TCPINFO 0x10A5113           //获取TCP状态信息失败
#define ERROR_XCORE_NETXAPI_SOCKET_ROTOCOLSTATICS_UDPINFO 0x10A5114           //获取UDP状态信息失败
#define ERROR_XCORE_NETXAPI_SOCKET_ROTOCOLSTATICS_ICMPINFO 0x10A5115          //获取ICMP状态信息失败
//进程网络连接状态设置获取错误表
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_SET_ISFAILED 0x10A51A0   //设置进程连接状态失败
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_SET_NOTSUPPET 0x10A51A1  //不支持的状态设置
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_TABLE 0x10A51A2  //获取表错误
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_MALLOC 0x10A51A3 //申请内存错误
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_FIALED 0x10A51A4 //获取列表错误，无法预知的问题
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_BUFFER 0x10A51A5 //BUFFER空间错误
#define ERROR_XCORE_NETXAPI_SOCKET_PROCESSNETSTATUES_GETLIST_PARAMENT 0x10A51A6//参数错误
/************************************************************************/
/*                     本地网络信息参数错误                             */
/************************************************************************/
#define ERROR_XCORE_NETXAPI_SOCKET_NETTABLE_PARAMENT 0x10A5200                //参数错误,无法继续
#define ERROR_XCORE_NETXAPI_SOCKET_NETTABLE_GETNETPARAMS 0x10A5201            //获取网络参数错误
/************************************************************************/
/*                     网络地址获取                                     */
/************************************************************************/
//主机地址
#define ERROR_XCORE_NETXAPI_SOCKET_GETHOSTNAME_PARAMENT 0x10A5320             //参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_GETHOSTNAME_IPADDR 0x10A5321               //不是标准的地址
#define ERROR_XCORE_NETXAPI_SOCKET_GETHOSTNAME_ISFAILED 0x10A5322             //获取失败，内部错误
#define ERROR_XCORE_NETXAPI_SOCKET_GETHOSTNAME_EMPTY 0x10A5323                //空的列表
//
#define ERROR_XCORE_NETXAPI_SOCKET_DOMAINTOADDR_PARAMENT 0x10A5330            //解析失败,参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_DOMAINTOADDR_NOTDOMAIN 0x10A5331           //不是域名或者没有连接网络
#define ERROR_XCORE_NETXAPI_SOCKET_GETNCLIST_PARAMENT 0x10A5330               //参数错误
#define ERROR_XCORE_NETXAPI_SOCKET_GETNCLIST_MALLOC 0x10A5331                 //申请内存失败
#define ERROR_XCORE_NETXAPI_SOCKET_GETNCLIST_ISFAILED 0x10A5332               //获取失败,内部错误
#define ERROR_XCORE_NETXAPI_SOCKET_GETNCLIST_EMPTY 0x10A5333                  //为空,没有获取到网卡信息
