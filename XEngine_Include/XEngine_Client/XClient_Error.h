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
/*                    客户端XSOCKET选择IO错误导出表                         */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_SETSOCKET 0x30A1010      //设置套接字失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_CONNECT 0x30A1011        //连接失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_LISTEN 0x30A1012         //监听套接字失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CREATE_BIND 0x30A1013           //指定端口网卡失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECV_PROGRESS 0x30A101A         //你设置了非阻塞 接受正在处理中，无法预知是否成功
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECV_ISFAILED 0x30A101B         //接受失败，可能没有数据
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECV_SRVCLOSE 0x30A101C         //服务器已经关闭
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_CLOSE_PARAMENT 0x30A101D        //参数错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECVPKT_PARAMENT 0x30A1020      //参数错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECVPKT_MALLOC 0x30A1021        //申请内存失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_RECVPKT_TIMEOUT 0x30A1022       //超时
//扩展错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_PARAMENT 0x30A2000          //参数错误，启动失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SETSOCKET 0x30A2001         //设置套接字失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CONNECT 0x30A2002           //连接失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_MALLOC 0x30A2003
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_BIND 0x30A2004
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SETSNDOUT 0x30A2005
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_SETRCVOUT 0x30A2006
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CONNECTISSET 0x30A2007
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CONNECTTIMEOUT 0x30A2008
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CONNECTREFUSED 0x30A2009
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_NOTFOUND 0x30A2011       //没有找到客户端
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_ISFAILED 0x30A2012       //内部错误
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_NOTSUP 0x30A2013         //不支持的类型
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_ISCALLBACK 0x30A2014     //回调模式无法继续
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CLOSE 0x30A2015          //关闭失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_NOREADY 0x30A2016        //没有准备好 
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_CREATETHREAD 0x30A2017   //创建线程失败
#define ERROR_XCLIENT_SOCKET_TCPSOCKET_SELECT_EX_NOTCLIENT 0x30A2018      //没有找到客户端
/************************************************************************/
/*                   网络客户端UDP选择模型套接字错误                         */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CREATE_PARAMENT 0x30A3000       //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CREATE_SETSOCKET 0x30A3002      //设置套接字失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_SENDMSG_PARAMENT 0x30A3010      //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVMSG_PARAMENT 0x30A3020      //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVMSG_ISFAILED 0x30A3023      //接受数据失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_BIND_NOTFOUND 0x30A3031         //没有找到
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_BIND_ISFAILED 0x30A3032         //绑定失败，内部错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_BIND_SETOPT 0x30A3033           //设置套接字失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVPKT_PARAMENT 0x30A3050      //接受参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVPKT_MALLOC 0x30A3051        //申请内存失败
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_RECVPKT_TIMEOUT 0x30A3052       //超时
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CONNECT_PARAMENT 0x30A3060      //参数错误
#define ERROR_XCLIENT_SOCKET_UDPSOCKET_SELECT_CONNECT_CONNECT 0x30A3061       //连接失败
//////////////////////////////////////////////////////////////////////////
//                    UNIX套接字错误导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_PARAMENT 0x30A4001           //参数错误
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_SOCKET 0x30A4002             //设置套接字失败
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_BIND 0x30A4003               //绑定套接字失败
#define ERROR_XCLIENT_SOCKET_UNIX_CONNECT_FAILED 0x30A4004             //连接失败
#define ERROR_XCLIENT_SOCKET_UNIX_SEND_PROGRESS 0x30A4010              //发送不明确,正在执行中,这个过程不可预料
#define ERROR_XCLIENT_SOCKET_UNIX_SEND_ISFAILED 0x30A4011              //发送失败
#define ERROR_XCLIENT_SOCKET_UNIX_SEND_LEN 0x30A4012                   //发送大小不正确
#define ERROR_XCLIENT_SOCKET_UNIX_RECV_PROGRESS 0x30A4020              //接受不明确,正在执行中
#define ERROR_XCLIENT_SOCKET_UNIX_RECV_ISFAILED 0x30A4021              //接受失败
#define ERROR_XCLIENT_SOCKET_UNIX_RECV_SRVCLOSE 0x30A4022              //服务器关闭了连接
//////////////////////////////////////////////////////////////////////////
//                    UDX套接字错误导出
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                  客户端UDX协议错误导出表                             */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_UDX_INIT_PARAMENT 0x30A5000                      //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_INIT_CREATETHREAD 0x30A5001                  //创建线程失败
#define ERROR_XCLIENT_SOCKET_UDX_INIT_TIMEOUT 0x30A5002                       //登录超时,无法继续
#define ERROR_XCLIENT_SOCKET_UDX_SEND_PARAMENT 0x30A5010                      //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_SEND_ISCLOSE 0x30A5011                       //连接关闭
#define ERROR_XCLIENT_SOCKET_UDX_SEND_WINDOWSIZE 0x30A5012                    //滑动窗口已满
#define ERROR_XCLIENT_SOCKET_UDX_RECV_PARAMENT 0x30A5020                      //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_RECV_ISCLOSE 0x30A5021                       //链路关闭
#define ERROR_XCLIENT_SOCKET_UDX_RECV_ISNULL 0x30A5022                        //数据队列为空
#define ERROR_XCLIENT_SOCKET_UDX_RECV_NOTDATA 0x30A5023                       //接受数据失败,没有数据或者数据不正确
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_PARAMENT 0x30A5050                     //参数错误
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_WINDOWFULL 0x30A5051                   //滑动窗口已满,无法接受数据
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_PROTOCOL 0x30A5052                     //协议错误
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_SAME 0x30A5053                         //处理到相同序列号数据
#define ERROR_XCLIENT_SOCKET_UDX_PARSE_TIMEOUT 0x30A5054                      //接受到一个过期的包
#define ERROR_XCLIENT_SOCKET_UDX_EX_MALLOC 0x30A50A0                          //申请内存失败
#define ERROR_XCLIENT_SOCKET_UDX_EX_NOTFOUND 0x30A50A1                        //没有找到指定客户端
/************************************************************************/
/*                  客户端SCTP协议错误导出表                                */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_PARAMENT 0x30A6001            //创建SCTP失败，参数错误
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_SOCKET 0x30A6002              //设置套接字失败
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_SETOPT 0x30A6003              //设置属性失败
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_CONNECT 0x30A6004             //链接服务器失败
#define ERROR_XCLIENT_SOCKET_STCP_CREATE_GETOPT 0x30A6005              //获取属性失败
#define ERROR_XCLIENT_SOCKET_STCP_SENDMSG_PARAMENT 0x30A6010           //发送数据失败，参数错误
#define ERROR_XCLIENT_SOCKET_STCP_SENDMSG_ISFAILED 0x30A6011           //发送失败，网络错误
#define ERROR_XCLIENT_SOCKET_STCP_SENDMSG_LEN 0x30A6012                //发送失败，长度不对
#define ERROR_XCLIENT_SOCKET_STCP_RECVMSG_PARAMENT 0x30A6020           //接受数据失败，参数错误
#define ERROR_XCLIENT_SOCKET_STCP_RECVMSG_SRVISFAILED 0x30A6021        //接受数据失败，网络错误
#define ERROR_XCLIENT_SOCKET_STCP_RECVMSG_SRVCLOSE 0x30A6022           //接受数据失败，服务器已经关闭
#define ERROR_XCLIENT_SOCKET_STCP_IOSELECT_ISFAILED 0x30A6030          //轮寻失败，内部错误
#define ERROR_XCLIENT_SOCKET_STCP_IOSELECT_NOREADLY 0x30A6031          //没有准备好
#define ERROR_XCLIENT_SOCKET_STCP_IOSELECT_SET 0x30A6032               //设置读写模式失败
/************************************************************************/
/*                    套接字操作错误                                    */
/************************************************************************/
#define ERROR_XCLIENT_SOCKET_OPT_IOSELECT_ERROR 0x30AA001       //套接字发生错误
#define ERROR_XCLIENT_SOCKET_OPT_IOSELECT_NOTREAD 0x30AA002     //没有准备好
#define ERROR_XCLIENT_SOCKET_OPT_IOSELECT_ISFAILED 0x30AA003    //轮训失败
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_SETBLOCK 0x30AA010     //设置失败
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_SETNOBLOCK 0x30AA011   //取消失败
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_CLOSE 0x30AA020        //关闭套接字
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_TIMEOUT 0x30AA021      //超时
#define ERROR_XCLIENT_SOCKET_OPT_IOBLOCK_ISFAILED 0x30AA022     //发送失败,内部错误
