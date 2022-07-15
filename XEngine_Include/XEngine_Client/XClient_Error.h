#pragma once
/********************************************************************
//	Created:	2011/10/8   11:46
//	Filename: 	NetSocketEngine/NetEngine_Client/NetClient_Socket/NetClient_Socket_Error.h
//	File Path:	NetSocketEngine/NetEngine_Client/NetClient_Socket/
//	File Base:	NetClient_Socket_Error
//	File Ext:	h
//  Project:    血与荣誉客户端错误导出定义
//	Author:		dowflyon
//	Purpose:
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    套接字错误导出
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                    客户端SOCKET选择IO错误导出表                         */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_SETSOCKET 0x50A1010      //设置套接字失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_CONNECT 0x50A1011        //连接失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_LISTEN 0x50A1012         //监听套接字失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_BIND 0x50A1013           //指定端口网卡失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_SEND_PROGRESS 0x50A1018         //你设置了非阻塞 发送正在处理中，无法预知是否成功
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_SEND_ISFAILED 0x50A1019         //发送失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_SEND_LEN 0x50A101A              //发送数据长度不一致
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECV_PROGRESS 0x50A101A         //你设置了非阻塞 接受正在处理中，无法预知是否成功
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECV_ISFAILED 0x50A101B         //接受失败，可能没有数据
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECV_SRVCLOSE 0x50A101C         //服务器已经关闭
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CLOSE_PARAMENT 0x50A101D        //参数错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECVPKT_PARAMENT 0x50A1020      //参数错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECVPKT_MALLOC 0x50A1021        //申请内存失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECVPKT_TIMEOUT 0x50A1022       //超时
//扩展错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_PARAMENT 0x50A2000          //参数错误，启动失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_SETSOCKET 0x50A2001         //设置套接字失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_CONNECT 0x50A2002           //连接失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_RECVTHREAD 0x50A2003        //启动线程失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_MALLOC 0x50A2004
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_BIND 0x50A2006
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_SETSNDOUT 0x50A2008
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_SETRCVOUT 0x50A2009
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_CONNECTISSET 0x50A200C
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_CONNECTTIMEOUT 0x50A200D
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_START_CONNECTREFUSED 0x50A200E
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SEND_PARAMENT 0x50A2010           //发送失败，参数错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SEND_NOTFOUND 0x50A2011           //没有找到客户端
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SEND_ISFAILED 0x50A2012           //内部错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_GETADDR_PARAMENT 0x50A2070
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_GETADDR_NOTFOUND 0x50A2071
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_GETADDR_GETPEERNAME 0x50A2072
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CONNECT_NOTFOUND 0x50A2080
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CONNECT_NOTSUP 0x50A2081
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_RECV_PARAMENT 0x50A20A1
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_RECV_NOTFOUND 0x50A20A2
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_RECV_ISCALLBACK 0x50A20A3
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_RECV_CLOSE 0x50A20A5
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_RECV_NOREADY 0x50A20A6
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CVTSOCKET_PARAMENT 0x50A20B0
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CVTSOCKET_NOTFOUND 0x50A20B1
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SETCB_NOTFOUND 0x50A20C0
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SETCB_NOTSUPPORT 0x50A20C1
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_HBSTART_NOTFOUND 0x50A20D0
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_HBSTART_CREATETHREAD 0x50A20D1
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_GETFLOW_NOTFOUND 0x50A20E0
/************************************************************************/
/*                   网络客户端UDP选择模型套接字错误                         */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CREATE_PARAMENT 0x50A3000       //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CREATE_SETSOCKET 0x50A3002      //设置套接字失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_SENDMSG_PARAMENT 0x50A3010      //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_SENDMSG_ISFAILED 0x50A3012      //发送数据失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVMSG_PARAMENT 0x50A3020      //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVMSG_ISFAILED 0x50A3023      //接受数据失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_BIND_NOTFOUND 0x50A3031         //没有找到
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_BIND_ISFAILED 0x50A3032         //绑定失败，内部错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_BIND_SETOPT 0x50A3033           //设置套接字失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVPKT_PARAMENT 0x50A3050      //接受参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVPKT_MALLOC 0x50A3051        //申请内存失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVPKT_TIMEOUT 0x50A3052       //超时
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CONNECT_PARAMENT 0x50A3060      //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CONNECT_CONNECT 0x50A3061       //连接失败
//////////////////////////////////////////////////////////////////////////
//                    UNIX套接字错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_PARAMENT 0x50A4001           //参数错误
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_SOCKET 0x50A4002             //设置套接字失败
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_BIND 0x50A4003               //绑定套接字失败
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_FAILED 0x50A4004             //连接失败
#define ERROR_XCLIENT_SOCKET_UNIX_SEND_PROGRESS 0x50A4010              //发送不明确,正在执行中,这个过程不可预料
#define ERROR_XCLIENT_SOCKET_UNIX_SEND_ISFAILED 0x50A4011              //发送失败
#define ERROR_XCLIENT_SOCKET_UNIX_SEND_LEN 0x50A4012                   //发送大小不正确
#define ERROR_XCLIENT_SOCKET_UNIX_RECV_PROGRESS 0x50A4020              //接受不明确,正在执行中
#define ERROR_XCLIENT_SOCKET_UNIX_RECV_ISFAILED 0x50A4021              //接受失败
#define ERROR_XCLIENT_SOCKET_UNIX_RECV_SRVCLOSE 0x50A4022              //服务器关闭了连接
//////////////////////////////////////////////////////////////////////////
//                    UDX套接字错误导出
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                  客户端UDX协议错误导出表                             */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_UDX_INIT_PARAMENT 0x50A5000                      //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_INIT_CREATETHREAD 0x50A5001                  //创建线程失败
#define ERROR_XCLIENT_SOCKET_UDX_INIT_TIMEOUT 0x50A5002                       //登录超时,无法继续
#define ERROR_XCLIENT_SOCKET_UDX_SEND_PARAMENT 0x50A5010                      //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_SEND_ISCLOSE 0x50A5011                       //连接关闭
#define ERROR_XCLIENT_SOCKET_UDX_SEND_WINDOWSIZE 0x50A5012                    //滑动窗口已满
#define ERROR_XCLIENT_SOCKET_UDX_RECV_PARAMENT 0x50A5020                      //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_RECV_ISCLOSE 0x50A5021                       //链路关闭
#define ERROR_XCLIENT_SOCKET_UDX_RECV_ISNULL 0x50A5022                        //数据队列为空
#define ERROR_XCLIENT_SOCKET_UDX_RECV_NOTDATA 0x50A5023                       //接受数据失败,没有数据或者数据不正确
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_PARAMENT 0x50A5050                     //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_WINDOWFULL 0x50A5051                   //滑动窗口已满,无法接受数据
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_PROTOCOL 0x50A5052                     //协议错误
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_SAME 0x50A5053                         //处理到相同序列号数据
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_TIMEOUT 0x50A5054                      //接受到一个过期的包
#define ERROR_XCLIENT_SOCKET_UDX_EX_MALLOC 0x50A50A0                          //申请内存失败
#define ERROR_XCLIENT_SOCKET_UDX_EX_NOTFOUND 0x50A50A1                        //没有找到指定客户端
/************************************************************************/
/*                  客户端SCTP协议错误导出表                                */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_PARAMENT 0x50A6001            //创建SCTP失败，参数错误
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_SOCKET 0x50A6002              //设置套接字失败
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_SETOPT 0x50A6003              //设置属性失败
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_CONNECT 0x50A6004             //链接服务器失败
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_GETOPT 0x50A6005              //获取属性失败
#define ERROR_XCLIENT_SOCKET_STCP_SENDMSG_PARAMENT 0x50A6010           //发送数据失败，参数错误
#define ERROR_XCLIENT_SOCKET_STCP_SENDMSG_ISFAILED 0x50A6011           //发送失败，网络错误
#define ERROR_XCLIENT_SOCKET_STCP_SENDMSG_LEN 0x50A6012                //发送失败，长度不对
#define ERROR_XCLIENT_SOCKET_STCP_RECVMSG_PARAMENT 0x50A6020           //接受数据失败，参数错误
#define ERROR_XCLIENT_SOCKET_STCP_RECVMSG_SRVISFAILED 0x50A6021        //接受数据失败，网络错误
#define ERROR_XCLIENT_SOCKET_STCP_RECVMSG_SRVCLOSE 0x50A6022           //接受数据失败，服务器已经关闭
#define ERROR_XCLIENT_SOCKET_STCP_IOSELECT_ISFAILED 0x50A6030          //轮寻失败，内部错误
#define ERROR_XCLIENT_SOCKET_STCP_IOSELECT_NOREADLY 0x50A6031          //没有准备好
#define ERROR_XCLIENT_SOCKET_STCP_IOSELECT_SET 0x50A6032               //设置读写模式失败
/************************************************************************/
/*                    套接字操作错误                                    */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_OPT_IOSELECT_ERROR 0x50AA001       //套接字发生错误
#define ERROR_XCLIENT_SOCKET_OPT_IOSELECT_NOTREAD 0x50AA002     //没有准备好
#define ERROR_XCLIENT_SOCKET_OPT_IOSELECT_ISFAILED 0x50AA003    //轮训失败
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_SETBLOCK 0x50AA010     //设置失败
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_SETNOBLOCK 0x50AA011   //取消失败
