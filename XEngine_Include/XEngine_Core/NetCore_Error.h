#pragma once
/********************************************************************
//	Created:	2011/10/10   15:14
//	Filename: 	NetSocketEngine/NETCORE/Net/Engine_Core/NetCore_Error.h
//	File Path:	NetSocketEngine/NETCORE/Engine_Core/
//	File Base:	NETCORE_Core
//	File Ext:	h
//  Project:    血与荣誉网络通信引擎 For Linux
//	Author:		dowflyon
//	Purpose:	网络通信服务器引擎核心错误导出
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     进程通信机制错误导出表
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                     IPC通信                                           */
/************************************************************************/
#define ERROR_XCORE_PIP_IPC_CREATE_PARRAMENT 0x20A1001                 //参数错误
#define ERROR_XCORE_PIP_IPC_CREATE_SIZE 0x20A1002                      //创建失败，大小不正确
#define ERROR_XCORE_PIP_IPC_CREATE_FAILED 0x20A1003                    //创建失败，内部错误
#define ERROR_XCORE_PIP_IPC_OPEN_FAILED 0x20A1010                      //打开失败，可能不存在
/************************************************************************/
/*                     内存映射                                          */
/************************************************************************/
#define ERROR_XCORE_PIP_MMAP_CREATE_PARRAMENT 0x20A1101                //打开匿名管道失败
#define ERROR_XCORE_PIP_MMAP_CREATE_FILE 0x20A1102                     //创建或者打开文件失败
#define ERROR_XCORE_PIP_MMAP_CREATE_MAP 0x20A1103                      //创建共享内存失败
#define ERROR_XCORE_PIP_MMAP_CREATE_STAT 0x20A1104                     //获取文件状态失败
#define ERROR_XCORE_PIP_MMAP_WRITE_PARAMENT 0x20A1110                  //写入失败,参数错误
#define ERROR_XCORE_PIP_MMAP_WRITE_NOTFOUND 0x20A1111                  //没有找到
#define ERROR_XCORE_PIP_MMAP_WRITE_MAPDATA 0x20A1113                   //映射共享内存数据失败
#define ERROR_XCORE_PIP_MMAP_WRITE_UNMAP 0x20A1114                     //卸载内存失败
#define ERROR_XCORE_PIP_MMAP_READ_PARAMENT 0x20A120                    //参数错误,读取失败
#define ERROR_XCORE_PIP_MMAP_READ_NOTFOUND 0x20A121                    //没有找到
#define ERROR_XCORE_PIP_MMAP_READ_MAPDATA 0x20A122                     //映射共享内存失败
#define ERROR_XCORE_PIP_MMAP_READ_UNMAP 0x20A123                       //卸载共享内存失败
#define ERROR_XCORE_PIP_MMAP_OPEN_PARAMENT 0x20A130                    //参数错误,打开失败
#define ERROR_XCORE_PIP_MMAP_OPEN_MAP 0x20A131                         //打开共享内存失败,可能没有这个名称的共享内存
#define ERROR_XCORE_PIP_MMAP_GETPOINT_PARAMENT 0x20A140                //参数错误
#define ERROR_XCORE_PIP_MMAP_GETPOINT_NOTFOUND 0x20A141                //没有找到
#define ERROR_XCORE_PIP_MMAP_GETPOINT_MAPDATA 0x20A142                 //映射内存失败
#define ERROR_XCORE_PIP_MMAP_FREEPOINT_PARAMENT 0x20A150               //参数错误
#define ERROR_XCORE_PIP_MMAP_FREEPOINT_NOTFOUND 0x20A151               //没有找到
#define ERROR_XCORE_PIP_MMAP_FREEPOINT_UNMAP 0x20A152                  //卸载内存失败
/************************************************************************/
/*                     匿名管道                                         */
/************************************************************************/
#define ERROR_XCORE_PIP_ANONYMOUS_CREATE_PARAMENT 0x20A1200            //参数错误
#define ERROR_XCORE_PIP_ANONYMOUS_CREATE_READHANDLE 0x20A1201          //读取句柄创建失败
#define ERROR_XCORE_PIP_ANONYMOUS_CREATE_WRITEHANDLE 0x20A1202         //写入句柄创建失败
#define ERROR_XCORE_PIP_ANONYMOUS_CREATE_ERRORHANDLE 0x20A1203         //错误句柄创建失败
#define ERROR_XCORE_PIP_ANONYMOUS_CREATE_PIPE 0x20A1204                //创建匿名管道失败
#define ERROR_XCORE_PIP_ANONYMOUS_CREATE_PROCESS 0x20A1205             //创建子进程失败
#define ERROR_XCORE_PIP_ANONYMOUS_RAED_PARAMENT 0x20A1210              //参数错误
#define ERROR_XCORE_PIP_ANONYMOUS_RAED_NOTFOUND 0x20A1211              //没有找到
#define ERROR_XCORE_PIP_ANONYMOUS_RAED_FAILED 0x20A1212                //读取失败,内部错误
#define ERROR_XCORE_PIP_ANONYMOUS_WRITE_PARAMENT 0x20A1220             //参数错误
#define ERROR_XCORE_PIP_ANONYMOUS_WRITE_NOTFOUND 0x20A1221             //没有找到
#define ERROR_XCORE_PIP_ANONYMOUS_WRITE_FAILED 0x20A1222               //写入失败,内部错误
#define ERROR_XCORE_PIP_ANONYMOUS_WRITE_LEN 0x20A1223                  //写入失败,大小不对
/************************************************************************/
/*                     命名管道                                         */
/************************************************************************/
#define ERROR_XCORE_PIP_NAMED_CREATE_PARAMENT 0x20A1300                //参数错误
#define ERROR_XCORE_PIP_NAMED_CREATE_FAILED 0x20A1301                  //命名管道已经存在，无法创建
#define ERROR_XCORE_PIP_NAMED_CREATE_OPEN 0x20A1302                    //打开管道失败
#define ERROR_XCORE_PIP_NAMED_READ_PARAMENT 0x20A1310                  //参数错误
#define ERROR_XCORE_PIP_NAMED_READ_NOTFOUND 0x20A1311                  //没有找到
#define ERROR_XCORE_PIP_NAMED_READ_NOTCONNECT 0x20A1312                //没有客户端进入,无法读取数据
#define ERROR_XCORE_PIP_NAMED_READ_FAILED 0x20A1313                    //读取失败,内部错误
#define ERROR_XCORE_PIP_NAMED_WRITE_PARAMENT 0x20A1320                 //参数错误
#define ERROR_XCORE_PIP_NAMED_WRITE_NOTFOUND 0x20A1321                 //没有找到
#define ERROR_XCORE_PIP_NAMED_WRITE_NOTCONNECT 0x20A1322               //没有客户端连接,无法写入数据
#define ERROR_XCORE_PIP_NAMED_WRITE_FAILED 0x20A1323                   //写入失败,内部错误
#define ERROR_XCORE_PIP_NAMED_WRITE_LEN 0x20A1324                      //写入大小不合适
#define ERROR_XCORE_PIP_NAMED_OPEN_PARAMENT 0x20A1330                  //参数错误
#define ERROR_XCORE_PIP_NAMED_OPEN_FAILED 0x20A1332                    //打开失败
#define ERROR_XCORE_PIP_NAMED_OPEN_CONNECT 0x20A1333                   //连接失败
#define ERROR_XCORE_PIP_NAMED_OPEN_SETMODE 0x20A1334                   //设置模式失败
#define ERROR_XCORE_PIP_NAMED_WAIT_PARAMENT 0x20A1340                  //参数错误
#define ERROR_XCORE_PIP_NAMED_WAIT_NOTFOUND 0x20A1341                  //没有找到
#define ERROR_XCORE_PIP_NAMED_WAIT_CONNECT 0x20A1342                   //等待连接失败
/************************************************************************/
/*                     邮槽通信错误导出                                 */
/************************************************************************/
#define ERROR_XCORE_PIP_MAILSLOT_CREATE_PARAMENT 0x20A1401             //参数错误
#define ERROR_XCORE_PIP_MAILSLOT_CREATE_FAILED 0x20A1402               //创建邮槽句柄失败
#define ERROR_XCORE_PIP_MAILSLOT_READ_PARAMENT 0x20A1410               //参数错误
#define ERROR_XCORE_PIP_MAILSLOT_READ_NOTFOUND 0x20A1411               //没有找到
#define ERROR_XCORE_PIP_MAILSLOT_READ_GETINFO 0x20A1412                //获取邮槽信息失败
#define ERROR_XCORE_PIP_MAILSLOT_READ_NOTMESSAGE 0x20A1413             //目前消息队列为空
#define ERROR_XCORE_PIP_MAILSLOT_READ_SIZE 0x20A1414                   //提供的缓冲区大小不合适
#define ERROR_XCORE_PIP_MAILSLOT_READ_FAILED 0x20A1415                 //读取失败,内部错误
#define ERROR_XCORE_PIP_MAILSLOT_WRITE_PARAMENT 0x20A1420              //参数错误
#define ERROR_XCORE_PIP_MAILSLOT_WRITE_NOTFOUND 0x20A1421              //没有找到
#define ERROR_XCORE_PIP_MAILSLOT_WRITE_FAILED 0x20A1422                //写入数据失败
#define ERROR_XCORE_PIP_MAILSLOT_WRITE_LEN 0x20A1423                   //写入大小不对
#define ERROR_XCORE_PIP_MAILSLOT_OPEN_PARAMENT 0x20A1430               //参数错误
#define ERROR_XCORE_PIP_MAILSLOT_OPEN_FAILED 0x20A1431                 //打开失败
#define ERROR_XCORE_PIP_MAILSLOT_SETATTR_PARAMENT 0x20A1440            //参数错误
#define ERROR_XCORE_PIP_MAILSLOT_SETATTR_NOTFOUND 0x20A1441            //没有找到队列
#define ERROR_XCORE_PIP_MAILSLOT_SETATTR_FAILED 0x20A1442              //设置属性失败，内部错误
#define ERROR_XCORE_PIP_MAILSLOT_GETATTR_PARAMENT 0x20A1450            //参数错误
#define ERROR_XCORE_PIP_MAILSLOT_GETATTR_NOTFOUND 0x20A1451            //没有找到队列
#define ERROR_XCORE_PIP_MAILSLOT_GETATTR_FAILED 0x20A1452              //获取属性失败，内部错误
//////////////////////////////////////////////////////////////////////////
//                     串口错误导出类型定义
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_SERIALPORT_OPENDEV_MALLOC 0x20A3001                //申请内存失败
#define ERROR_XCORE_SERIALPORT_OPENDEV_FAILED 0x20A3002                //打开串口失败
#define ERROR_XCORE_SERIALPORT_OPENDEV_GETCOMSTATE 0x20A3003           //获取串口状态错误
#define ERROR_XCORE_SERIALPORT_OPENDEV_SETCOMSTATE 0x20A3004           //设置串口状态错误
#define ERROR_XCORE_SERIALPORT_OPENDEV_CREATETHREAD 0x20A3005          //创建线程失败
#define ERROR_XCORE_SERIALPORT_SENDDATA_NOTFOUND 0x20A3010             //没有找到指定的串口
#define ERROR_XCORE_SERIALPORT_SENDDATA_NOTREADY 0x20A3011             //没有准备号
#define ERROR_XCORE_SERIALPORT_SENDDATA_FAILED 0x20A3012               //写入数据失败
#define ERROR_XCORE_SERIALPORT_SENDDATA_CLEARERROR 0x20A3013           //清理错误缓冲区失败
#define ERROR_XCORE_SERIALPORT_SENDDATA_CLEARSEND 0x20A3014            //清理发送缓冲区失败
#define ERROR_XCORE_SERIALPORT_SENDDATA_CREATEOL 0x20A3015             //创建一个OVERLAPPED事件失败
#define ERROR_XCORE_SERIALPORT_SENDDATA_GETOLRESULT 0x20A3016          //发送失败，获取发送处理结果失败 
#define ERROR_XCORE_SERIALPORT_SENDDATA_SIZE 0x20A3017                 //写入的大小与指定大小不同
#define ERROR_XCORE_SERIALPORT_READDATA_NOTFOUND 0x20A3021             //接受数据失败，没有找到指定串口
#define ERROR_XCORE_SERIALPORT_READDATA_NOTSUPPORT 0x20A3022           //不支持这样的操作
#define ERROR_XCORE_SERIALPORT_READ_NOTREADY 0x20A3030                 //设备没有准备好，有可能是没有数据可读
#define ERROR_XCORE_SERIALPORT_READ_FAILED 0x20A3031                   //读取失败
#define ERROR_XCORE_SERIALPORT_READ_CLEARERROR 0x20A3032               //读取数据清理错误失败
#define ERROR_XCORE_SERIALPORT_READ_CLEARRECV 0x20A3033                //清理接受缓冲区失败
#define ERROR_XCORE_SERIALPORT_READ_CREATEOL 0x20A3034                 //创建接受事件失败
#define ERROR_XCORE_SERIALPORT_READ_GETOLRESULT 0x20A3035              //获取重叠IO返回值失败
//属性设置
#define ERROR_XCORE_SERIALPORT_SETSPEED_GETDEFAULT 0x20A3101           //获取默认设置失败
#define ERROR_XCORE_SERIALPORT_SETSPEED_FAILED 0x20A3102               //设置速率失败
#define ERROR_XCORE_SERIALPORT_SETSPEED_FLUSH 0x20A3103                //刷新缓冲区失败
#define ERROR_XCORE_SERIALPORT_SETPARITY_GETDEFAULT 0x20A3110          //获取默认属性失败
#define ERROR_XCORE_SERIALPORT_SETPARITY_NOTSUPPORTBIT 0x20A3111       //不支持的数据位数
#define ERROR_XCORE_SERIALPORT_SETPARITY_NOTSUPPORTCHECK 0x20A3112     //不支持的校验位方法
#define ERROR_XCORE_SERIALPORT_SETPARITY_NOTSUPPORTSTOP 0x20A3113      //不支持的停止位数
#define ERROR_XCORE_SERIALPORT_SETPARITY_FAILED 0x20A3114              //写入设置到串口属性失败
//////////////////////////////////////////////////////////////////////////
//                         网络核心套接字错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_SOCKET_SOCKET_CREATE_PARAMENT 0x20A4501            //参数错误
#define ERROR_XCORE_SOCKET_SOCKET_CREATE_ISFAILED 0x20A4502            //创建失败，内部错误
#define ERROR_XCORE_SOCKET_SOCKET_CREATE_SIGEMPTY 0x20A4503            //清空信号失败
#define ERROR_XCORE_SOCKET_SOCKET_CREATE_SIGACTION 0x20A4504           //设置信号失败
#define ERROR_XCORE_SOCKET_SOCKET_BIND_LISTEN 0x20A4510                //监听端口失败
#define ERROR_XCORE_SOCKET_SOCKET_BIND_BIND 0x20A4511                  //绑定端口失败
#define ERROR_XCORE_SOCKET_SOCKET_SEND_CLOSE 0x20A4521                 //发送失败,对方关闭连接
#define ERROR_XCORE_SOCKET_SOCKET_SEND_ISFAILED 0x20A4522              //发送失败，内部错误
#define ERROR_XCORE_SOCKET_SOCKET_SEND_TIMEOUT 0x20A4523               //发送失败，超时
#define ERROR_XCORE_SOCKET_SOCKET_SEND_ISCLOSED 0x20A4525              //发送的套接字被对方强制关闭
#define ERROR_XCORE_SOCKET_SOCKET_RECV_RETRY 0x20A4531                 //接受失败，需要重试
#define ERROR_XCORE_SOCKET_SOCKET_RECV_ISFAILED 0x20A4532              //接受失败，内部错误
#define ERROR_XCORE_SOCKET_SOCKET_RECV_CLIENTCLOSE 0x20A4533           //客户端已经关闭。
#define ERROR_XCORE_SOCKET_SOCKET_SETNONEBLOC_GETFL 0x20A4540          //获取状态失败
#define ERROR_XCORE_SOCKET_SOCKET_SETNONEBLOC_SETNONFAILED 0x20A4541   //设置非阻塞失败
#define ERROR_XCORE_SOCKET_SOCKET_SETNONEBLOC_BLOCKING 0x20A4542       //设置阻塞失败
#define ERROR_XCORE_SOCKET_SOCKET_READDR_SETFAILED 0x20A4560           //设置重用失败
#define ERROR_XCORE_SOCKET_SOCKET_SETTIMEOUT_SEND 0x20A4570            //设置发送超时时间失败
#define ERROR_XCORE_SOCKET_SOCKET_SETTIMEOUT_RECV 0x20A4571            //设置接受超时时间失败
#define ERROR_XCORE_SOCKET_SOCKET_KEEPALIVE_OPEN 0x20A4580             //打开保活计时器失败
#define ERROR_XCORE_SOCKET_SOCKET_KEEPALIVE_SETIDLETIME 0x20A4581      //设置空闲探测时间失败
#define ERROR_XCORE_SOCKET_SOCKET_KEEPALIVE_SETINTERVALTIME 0x20A4582  //设置探测间隔时间
#define ERROR_XCORE_SOCKET_SOCKET_KEEPALIVE_SETKEEPCOUNT 0x20A4583     //设置次数失败
#define ERROR_XCORE_SOCKET_SOCKET_FASTSTART_NODELAY 0x20A45A0          //设置没有延迟失败
#define ERROR_XCORE_SOCKET_SOCKET_FASTSTART_NOROUTE 0x20A45A1          //设置不经过路由失败
#define ERROR_XCORE_SOCKET_SOCKET_SELECT_PARAMENT 0x20A40B0            //参数错误
#define ERROR_XCORE_SOCKET_SOCKET_SELECT_NOREADLY 0x20A40B1            //没有设备可用
#define ERROR_XCORE_SOCKET_SOCKET_SELECT_UNKNOW 0x20A40B2              //多路IO选择发送了未知错误
#define ERROR_XCORE_SOCKET_SOCKET_SELECT_ERROR 0x20A40B3               //轮训失败,错误的套接字
#define ERROR_XCORE_SOCKET_SOCKET_REPORT_SETFAILED 0x20A40C0           //设置失败
//////////////////////////////////////////////////////////////////////////
//                    网络服务函数错误
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                    Select服务器错误导出                                */
/************************************************************************/
#define ERROR_XCORE_SOCKET_TCP_SELECT_INIT_ISRUNNING 0x20A4101                //服务器已经开始运行了
#define ERROR_XCORE_SOCKET_TCP_SELECT_INIT_SETSIGEMPTY 0x20A4105              //清空信号失败
#define ERROR_XCORE_SOCKET_TCP_SELECT_INIT_SETSIGPIP 0x20A4106                //设置跳过信号失败
#define ERROR_XCORE_SOCKET_TCP_SELECT_INIT_CREATETHREAD 0x20A4107             //创建主线程失败
#define ERROR_XCORE_SOCKET_TCP_SELECT_INIT_CREATECLOSE 0x20A4108              //创建关闭线程失败
#define ERROR_XCORE_SOCKET_TCP_SELECT_SEND_NOTFOUND 0x20A4110                 //发送数据失败,客户端没有找到
#define ERROR_XCORE_SOCKET_TCP_SELECT_GETLIST_PARAMENT 0x20A4120              //参数错误
#define ERROR_XCORE_SOCKET_TCP_SELECT_GETLIST_EMPTY 0x20A4121                 //空的列表
#define ERROR_XCORE_SOCKET_TCP_SELECT_GETFLOW_PARAMTISNULL 0x20A4160          //获取流量参数错误
#define ERROR_XCORE_SOCKET_TCP_SELECT_READIO_PARAMENT 0x20A4170               //读取IO事件参数错误
#define ERROR_XCORE_SOCKET_TCP_SELECT_READIO_NOIOEVNET 0x20A4171              //没有可读IO事件
#define ERROR_XCORE_SOCKET_TCP_SELECT_READIO_NOTSUPPORT 0x20A4172             //不支持此方式读取IO事件，因为已经被设置为回调方式
#define ERROR_XCORE_SOCKET_TCP_SELECT_READIO_NOTFOUND 0x20A4173               //没有找到指定的事件，可能没有这类事件发生
#define ERROR_XCORE_SOCKET_TCP_SELECT_EX_START_ISEXIST 0x20A41E0
#define ERROR_XCORE_SOCKET_TCP_SELECT_EX_START_MALLOC 0x20A41E1
#define ERROR_XCORE_SOCKET_TCP_SELECT_EX_NOTFOUND 0x20A41E2
/************************************************************************/
/*          POLL服务器错误导出类型定义                                      */
/************************************************************************/
#define ERROR_XCORE_SOCKET_TCP_XPOLL_START_ISRUNNING 0x20A4201                 //服务器已经在运行了
#define ERROR_XCORE_SOCKET_TCP_XPOLL_START_CRAETETHREAD 0x20A4202              //创建接受者线程失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_POLL_NODEVREADY 0x20A4210                 //没有设备准备好
#define ERROR_XCORE_SOCKET_TCP_XPOLL_POLL_ISFAILED 0x20A4211                   //查询函数失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_POLL_MALLOC 0x20A4212                     //申请空间失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_SELECTLIST_MALLOC 0x20A4220               //申请内存失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_SELECTLIST_CREATETHREAD 0x20A4221         //创建线程失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_SEND_NOTFOUNDCLIENT 0x20A4230             //没有找到指定要发送的客户地址数据
#define ERROR_XCORE_SOCKET_TCP_XPOLL_SEND_SOCKETISFAILED 0x20A4231             //套接字句柄错误，无法发送
#define ERROR_XCORE_SOCKET_TCP_XPOLL_SEND_SENDISFAILED 0x20A4232               //发送失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_CALLBACK_REG_PARAMENT 0x20A4240           //设置回调数据失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XPOLL_STOP_NOTRUNNING 0x20A4450                 //没有运行，不需要关闭
#define ERROR_XCORE_SOCKET_TCP_XPOLL_STOP_SHUTDOWN 0x20A4451                   //卸载监听套接字失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_STOP_CLOSESOCKET 0x20A4452                //关闭套接字失败
#define ERROR_XCORE_SOCKET_TCP_XPOLL_STOP_TERMINATETHREAD 0x20A4453            //结束线程失败
/************************************************************************/
/*          EPOLL TCP服务器错误导出类型定义                                 */
/************************************************************************/
#define ERROR_XCORE_SOCKET_TCP_XCORE_START_EMPTYSIGN 0x20A4301                //清空信号失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_START_SETSIGN 0x20A4302                  //设置信号失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_START_CREATETHREAD 0x20A4303             //启动线程失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CREATE_MALLOC 0x20A4310                  //申请内存失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CREATE_EPOLL 0x20A4311                   //创建数据传输EPOLL失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CREATE_ADD 0x20A4312                     //添加到EPOLL事件失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CREATE_CREATEIO 0x20A4313                //创建IO失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CREATE_PIP 0x20A4314                     //创建管道失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CREATE_ADDPIP 0x20A4315                  //添加管道失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_POSTMSG_PARAMENT 0x20A4320               //投递数据失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_POSTMSG_NOTFOUND 0x20A4321               //没有找到客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_POSTMSG_NOTSUPPORT 0x20A4322             //不支持此模式
#define ERROR_XCORE_SOCKET_TCP_XCORE_POSTMSG_MALLOC 0x20A4323                 //申请内存失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_POSTMSG_ISFAILED 0x20A4324               //投递失败,内部错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_POSTMSG_MODEVENT 0x20A4325               //修改事件失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_CLOSE_PARAMENT 0x20A4330                 //参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_CLOSE_NOTFOUND 0x20A4331                 //没有找到客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_CLOSE_CTLDEL 0x20A4332                   //删除事件失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETFLOW_PARAMENT 0x20A4340               //获取流量失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETFLOW_NOTFOUND 0x20A4341               //没有找到指定客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_CALLBACK_PARAMENT 0x20A4350              //参数错误，设置回调失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_ACCEPT_ISFAILED 0x20A4360                //接受链接失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_ACCEPT_ADDCTL 0x20A4361                  //加入的用户添加到EPOLL集合中失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_ACCEPT_MAXCONN 0x20A4362                 //到达最大连接数
#define ERROR_XCORE_SOCKET_TCP_XCORE_ACCEPT_MALLOC 0x20A4363                  //申请内存失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETAVERFLOW_PARAMENT 0x20A4370           //参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETAVERFLOW_NOTFOUND 0x20A4371           //没有找到
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETSOCKET_PARAMENT 0x20A4380             //获取套接字失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETSOCKET_NOTFOUND 0x20A4381             //没有找到指定的客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETSOCKET_BADSOCKET 0x20A4382            //客户端套接字有错误，请关闭此客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETADDR_PARAMENT 0x20A4383               //获取地址失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETADDR_NOTFOUND 0x20A4384               //获取地址失败，没有这个客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_SENDMSG_PARAMENT 0x20A4391               //投递数据失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_SENDMSG_NOTFOUND 0x20A4392               //没有找到指定客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_SENDMSG_BREAK 0x20A4393                  //此客户端被设置为跳过数据处理
#define ERROR_XCORE_SOCKET_TCP_XCORE_SENDMSG_MALLOC 0x20A4394                 //申请内存失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_SENDMSG_ISFAILED 0x20A4395               //发送失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_SENDMSG_MODEVENT 0x20A4396               //修改事件失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETRECVTIME_PARAMENT 0x20A43A0           //参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETRECVTIME_NOTFOUND 0x20A43A1           //没有找到指定客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETALL_PARAMENT 0x20A43B0                //获取失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETALL_NOTCLIENT 0x20A43B1               //获取失败，没有客户端在线
#define ERROR_XCORE_SOCKET_TCP_XCORE_SETSTATUS_PARAMENT 0x20A43C0             //设置失败，参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_SETSTATUS_NOTFOUND 0x20A43C1             //没有找到客户端
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETTIME_PARAMENT 0x20A43D0               //参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETTIME_NOTFOUND 0x20A43D1               //没有找到
#define ERROR_XCORE_SOCKET_TCP_XCORE_SETMILIT_PARAMENT 0x20A43E0              //参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_SETMILIT_NOTFOUND 0x20A43E1              //没有找到
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETMILIT_PARAMENT 0x20A43F0              //参数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_GETMILIT_NOTFOUND 0x20A43F1              //没有找到
//扩展函数错误
#define ERROR_XCORE_SOCKET_TCP_XCORE_EX_MALLOC 0x20A43A0                      //申请内存失败
#define ERROR_XCORE_SOCKET_TCP_XCORE_EX_NOTFOUND 0x20A43A1                    //没有找到
/************************************************************************/
/*          SELECT UDP服务器错误导出类型定义                                 */
/************************************************************************/
#define ERROR_XCORE_SOCKET_UDP_SELECT_INIT_MALLOC 0x20A4402                    //申请内存失败
#define ERROR_XCORE_SOCKET_UDP_SELECT_INIT_CREATETHREAD 0x20A4405              //创建线程失败
#define ERROR_XCORE_SOCKET_UDP_SELECT_SENDTO_PARAMENT 0x20A4421                //参数错误
#define ERROR_XCORE_SOCKET_UDP_SELECT_SENDTO_NOTFOUND 0x20A4422                //没有找到指定客户端
#define ERROR_XCORE_SOCKET_UDP_SELECT_RECV_PARAMENT 0x20A4430                  //参数错误
#define ERROR_XCORE_SOCKET_UDP_SELECT_RECV_CALLBACK 0x20A4431                  //模式错误，不能主动接受数据
#define ERROR_XCORE_SOCKET_UDP_SELECT_RECV_NOTFOUND 0x20A4432                  //没有找到指定客户端
#define ERROR_XCORE_SOCKET_UDP_SELECT_RECV_ISFAILED 0x20A4433                  //接受失败，内部错误
#define ERROR_XCORE_SOCKET_UDP_SELECT_RECV_NOTBIND 0x20A4434                   //没有绑定端口,无法继续
#define ERROR_XCORE_SOCKET_UDP_SELECT_SETMODE_NOTFOUND 0x20A4440               //没有找到指定客户端
#define ERROR_XCORE_SOCKET_UDP_SELECT_CALLBACK_NOTFOUND 0x20A4450              //没有找到
/************************************************************************/
/*          EPOLL UDP服务器错误导出类型定义                                 */
/************************************************************************/
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_MALLOC 0x20A4501                   //申请内存失败，启动错误
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_IO 0x20A4502                       //创建EPOLL事件失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_CTLADD 0x20A4503                   //加入套接字集合失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_BIND 0x20A4504                     //绑定IOCP失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_FAILED 0x20A4505                   //内部错误
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_PIP 0x20A4506                      //创建管道失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_START_ADDPIP 0x20A4507                   //添加失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_SENDMSG_PARAMENT 0x20A4510               //参数错误，发送失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_GETFLOW_PARAMENT 0x20A4520               //获取流量参数为空
#define ERROR_XCORE_SOCKET_UDP_XCORE_CALLBACK_PARAMENT 0x20A4530              //设置回调失败，参数错误
#define ERROR_XCORE_SOCKET_UDP_XCORE_GETTIME_PARAMENT 0x20A4550               //参数错误获取失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_GETAVERFLOW_PARAMENT 0x20A4660           //参数错误获取失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_EX_MALLOC 0x20A45A0                      //扩展函数启动失败,申请内存失败
#define ERROR_XCORE_SOCKET_UDP_XCORE_EX_NOTFOUND 0x20A45A1                    //没有找到指定的句柄
/************************************************************************/
/*          SCTP服务器错误导出类型定义                                      */
/************************************************************************/
#define ERROR_XCORE_SOCKET_SCTP_START_EMPTYSIGN 0x20A4600                      //启动失败，设置空信号失败
#define ERROR_XCORE_SOCKET_SCTP_START_SETSIGN 0x20A4601                        //设置信号量失败
#define ERROR_XCORE_SOCKET_SCTP_SEND_PARAMENT 0x20A4620                        //发送数据失败，参数错误
#define ERROR_XCORE_SOCKET_SCTP_SEND_NOTFOUND 0x20A4621                        //没有找到
#define ERROR_XCORE_SOCKET_SCTP_SEND_ISFAILED 0x20A4621                        //发送失败，内部错误
#define ERROR_XCORE_SOCKET_SCTP_CLOSE_PARAMENT 0x20A4630                       //关闭失败，参数错误
#define ERROR_XCORE_SOCKET_SCTP_CLOSE_NOTFOUND 0x20A4631                       //关闭失败，没有找到
#define ERROR_XCORE_SOCKET_SCTP_CLOSE_CTRL 0x20A4632                           //关闭失败，删除表失败
#define ERROR_XCORE_SOCKET_SCTP_GETFLOW_PARAMENT 0x20A4640                     //获取流量失败
#define ERROR_XCORE_SOCKET_SCTP_GETFLOW_NOTFOUND 0x20A4641                     //没有找到
#define ERROR_XCORE_SOCKET_SCTP_CALLBACK_PARAMENT 0x20A4650                    //设置回调函数失败
#define ERROR_XCORE_SOCKET_SCTP_GETSOCKET_PARAMENT 0x20A4670                   //参数错误
#define ERROR_XCORE_SOCKET_SCTP_GETSOCKET_NOTFOUND 0x20A4671                   //没有找到
#define ERROR_XCORE_SOCKET_SCTP_GETSOCKET_BADSOCKET 0x20A4672                  //错误的套机字
#define ERROR_XCORE_SOCKET_SCTP_GETADDR_PARAMENT 0x20A4680                     //参数错误
#define ERROR_XCORE_SOCKET_SCTP_GETADDR_ISFAILED 0x20A4681                     //内部错误
#define ERROR_XCORE_SOCKET_SCTP_ACCEPT_ISFAILED 0x20A4690                      //内部错误，结束链接失败
#define ERROR_XCORE_SOCKET_SCTP_ACCEPT_GETOPT_STATUS 0x20A4691                 //获取状态失败
#define ERROR_XCORE_SOCKET_SCTP_ACCEPT_ADDCTL 0x20A4692                        //添加到EPOLL中失败
#define ERROR_XCORE_SOCKET_SCTP_ACCEPT_MALLOC 0x20A4693                        //申请内存失败
#define ERROR_XCORE_SOCKET_SCTP_RECV_CLIENTLEAVE 0x20A46A0                     //接受失败，客户端离开
#define ERROR_XCORE_SOCKET_SCTP_RECV_BUFFISNULL 0x20A46A1                      //数据为空，无法继续
#define ERROR_XCORE_SOCKET_SCTP_RECV_ISFAILED 0x20A46A2                        //内部错误
#define ERROR_XCORE_SOCKET_SCTP_CREATE_SOCKET 0x20A46B0                        //创建套接字失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_MALLOC 0x20A46B1                        //申请内存失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_BIND 0x20A46B2                          //绑定端口失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_SETOPTMSG 0x20A46B3                     //设置消息选项失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_LISTEN 0x20A46B4                        //监听失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_CREATE 0x20A46B5                        //创建EPOLL失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_CTRL 0x20A46B6                          //创建ET事件失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_PIP 0x20A46B7                           //创建管道失败
#define ERROR_XCORE_SOCKET_SCTP_CREATE_ADDPIP 0x20A46B8                        //添加失败
#define ERROR_XCORE_SOCKET_SCTP_GETRECVTIME_PARAMENT 0x20A46C0                 //参数错误
#define ERROR_XCORE_SOCKET_SCTP_GETRECVTIME_NOTFOUND 0x20A46C1                 //没有找到
#define ERROR_XCORE_SOCKET_SCTP_GETAVERFLOW_PARAMENT 0x20A46D0                 //参数错误
#define ERROR_XCORE_SOCKET_SCTP_GETAVERFLOW_NOTFOUND 0x20A46D1                 //没有找到
//////////////////////////////////////////////////////////////////////////
//                     网络高级操作导出错误类型	
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      组播管理器错误                                  */
/************************************************************************/
#define ERROR_XCORE_MULTICAS_GROUPCAST_PARAMENT 0x20A6001                //参数错误，创建发送者失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_SOCKET 0x20A6002                  //获取套接字失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_SETOPTLOOP 0x20A6003              //设置LOOP属性失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_SETOPTTTL 0x20A6004               //设置TTL属性失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_BIND 0x20A6006                    //绑定失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_JOIN 0x20A6007                    //加入组播失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_NOTFOUND 0x20A6008                //没有找到
#define ERROR_XCORE_MULTICAS_GROUPCAST_SEND 0x20A6009                    //发送失败
#define ERROR_XCORE_MULTICAS_GROUPCAST_RECV 0x20A6010                    //接受数据失败
/************************************************************************/
/*                      广播通信管理错误导出表                          */
/************************************************************************/
#define ERROR_XCORE_MULTICAST_BROADCAST_PARAMENT 0x20A6100               //参数错误，无法继续
#define ERROR_XCORE_MULTICAST_BROADCAST_SETSOCKET 0x20A6101              //设置套接字属性失败
#define ERROR_XCORE_MULTICAST_BROADCAST_SETBROADCAST 0x20A6102           //初始化广播参数失败
#define ERROR_XCORE_MULTICAST_BROADCAST_BIND 0x20A6103                   //绑定服务地址端口失败
#define ERROR_XCORE_MULTICAST_BROADCAST_NOTFOUNDID 0x20A6105             //没有找到套接字
#define ERROR_XCORE_MULTICAST_BROADCAST_SENDTOFAILED 0x20A6106           //发送失败，XSOCKET错误
#define ERROR_XCORE_MULTICAST_BROADCAST_RECVISFIALED 0x20A6107           //接受失败，套接字错误
/************************************************************************/
/*                      心跳管理错误导出表                                 */
/************************************************************************/
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INIT_PARAMENT 0x20A6200          //初始化失败，参数错误，时间次数不能小于1
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INIT_CREATETHREAD 0x20A6201      //创建线程失败
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INSERTADDR_NOTRUN 0x20A6220      //没有运行，无法继续
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INSERTADDR_NOTSUPPORT 0x20A6221  //不支持的模式
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INSERTADDR_PARAMENT 0x20A6222    //参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INSERTSOCKET_NOTRUN 0x20A6230    //没有运行
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INSERTSOCKET_NOTSUPPORT 0x20A6231//不支持的模式
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INSERTSOCKET_PARAMENT 0x20A6232  //参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVEADDR_PARAMENT 0x20A6240    //激活客户端失败，参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVEADDR_NOTRUN 0x20A6241      //没有初始化
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVEADDR_NOTSUPPORT 0x20A6242  //不支持的模式
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVEADDR_NOTFOUND 0x20A6243    //没有找到指定的客户端
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVESOCKET_NOTRUN 0x20A6250    //没有初始化
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVESOCKET_NOTSUPPORT 0x20A6251//不支持的模式
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVESOCKET_PARAMENT 0x20A6252  //参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_ACTIVESOCKET_NOTFOUND 0x20A6253  //没有找到指定的客户端
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETEADDR_PARAMENT 0x20A6260    //删除失败，参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETEADDR_NOTFOUND 0x20A6261    //删除失败，没有找到
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETEADDR_NOTRUN 0x20A6262      //没有初始化
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETEADDR_NOTSUPPORT 0x20A6263  //不支持的模式
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETESOCKET_NOTRUN 0x20A6270    //没有初始化
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETESOCKET_NOTSUPPORT 0x20A6271//不支持的模式
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETESOCKET_PARAMENT 0x20A6272  //删除失败，参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_DELETESOCKET_NOTFOUND 0x20A6273  //删除失败，没有找到
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETTIMEOUT_PARAMENT 0x20A6280    //参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETTIMEOUT_CALLBACK 0x20A6281    //设置了回调函数，不允许使用此函数
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETTIMEOUT_NOTCLIENT 0x20A6282   //没有客户端断线
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETTIMEOUT_NOTRUN 0x20A6283      //没有初始化
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_FORCEOUT_PARAMENT 0x20A6290      //参数错误，无法继续
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_FORCEOUT_NOTFOUND 0x20A6291      //没有找到指定的客户端地址
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_SETLOAD_PARAMENT 0x20A62A0       //设置负载失败，参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETLOAD_PARAMENT 0x20A62A1       //获取失败，参数错误
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETLOAD_NOTFOUND 0x20A62A2       //获取失败，没有找到
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETADDR_PARAMENT 0x20A62B0       //参数错误,获取地址信息失败
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETADDR_NOTFOUND 0x20A62B1       //没有找到
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_GETSOCKET_NOTFOUND 0x20A62C0     //没有找到
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INIT_EX_MALLOC 0x20A62F0         //申请内存失败
#define ERROR_XCORE_SOCKOPT_HEARTBEAT_INIT_EX_NOTFOUND 0x20A62F1       //没有找到指定的心跳管理器
//////////////////////////////////////////////////////////////////////////
//                     UNIX域协议C/S模式导出错误码
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_UNIXDOMAIN_START_PARAMENT 0x20A7001         //参数错误
#define ERROR_XCORE_UNIXDOMAIN_START_SOCKET 0x20A7002           //设置套接字失败,可能不支持
#define ERROR_XCORE_UNIXDOMAIN_START_BIND 0x20A7003             //绑定失败,可能已经存在的名称
#define ERROR_XCORE_UNIXDOMAIN_START_LISTEN 0x20A7004           //监听失败
#define ERROR_XCORE_UNIXDOMAIN_START_THREAD 0x20A7005           //启动内部线程失败
#define ERROR_XCORE_UNIXDOMAIN_SEND_PARAMENT 0x20A7010          //参数错误
#define ERROR_XCORE_UNIXDOMAIN_SEND_NOTFOUND 0x20A7011          //发送失败,没有找到
#define ERROR_XCORE_UNIXDOMAIN_SEND_FAILED 0x20A7012            //发送失败,内部错误
#define ERROR_XCORE_UNIXDOMAIN_SEND_LEN 0x20A7013               //发送数据的大小不匹配
//////////////////////////////////////////////////////////////////////////
//                    UDX传输协议导出
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCORE_UDX_ACCEPT_PARAMENT 0x20A8000             //参数错误,接受处理失败
#define ERROR_XCORE_UDX_ACCEPT_MALLOC 0x20A8001               //申请内存失败
#define ERROR_XCORE_UDX_PARSE_PARAMENT 0x20A8010              //参数错误,接受数据失败
#define ERROR_XCORE_UDX_PARSE_NOTFOUND 0x20A8011              //没有找到指定的句柄
#define ERROR_XCORE_UDX_PARSE_WINDOWFULL 0x20A8012            //滑动窗口已满,无法接受数据
#define ERROR_XCORE_UDX_PARSE_PROTOCOL 0x20A8013              //协议不正确
#define ERROR_XCORE_UDX_PARSE_SAME 0x20A8014                  //相同的序列号包
#define ERROR_XCORE_UDX_PARSE_RETRY 0x20A8015                 //报告了一个重传错误,某一个序列号已经被丢弃
#define ERROR_XCORE_UDX_PARSE_NOLOGIN 0x20A8016               //用户没有登录,无法继续
#define ERROR_XCORE_UDX_PARSE_TIMEOUT 0x20A8017               //接收到一个过期的包
#define ERROR_XCORE_UDX_SEND_PARAMENT 0x20A8020               //参数错误,发送失败
#define ERROR_XCORE_UDX_SEND_NOTFOUND 0x20A8021               //没有找到指定客户端
#define ERROR_XCORE_UDX_SEND_WINDOWSIZE 0x20A8022             //对端阻塞,无法发送数据
#define ERROR_XCORE_UDX_RECV_PARAMENT 0x20A8030               //参数错误,接受数据失败
#define ERROR_XCORE_UDX_RECV_NOTFOUND 0x20A8031               //没有找到指定客户端
#define ERROR_XCORE_UDX_RECV_ISNULL 0x20A8032                 //数据队列为空
#define ERROR_XCORE_UDX_RECV_NOTDATA 0x20A8033                //没有数据或者包不完成
#define ERROR_XCORE_UDX_INIT_PARAMENT 0x20A8040               //初始化失败,参数错误
#define ERROR_XCORE_UDX_INIT_CREATETHREAD 0x20A8041           //初始化失败,创建线程失败
#define ERROR_XCORE_UDX_CBSET_PARAMENT 0x20A8050              //设置回调失败,参数错误
#define ERROR_XCORE_UDX_EX_MALLOC 0x20A80A0                   //申请内存错误
#define ERROR_XCORE_UDX_EX_NOTFOUND 0x20A80A1                 //没有找到指定服务
//////////////////////////////////////////////////////////////////////////
//                         无线通信导出错误
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                          蓝牙设备API错误                             */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////LINUX
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SCAN_NOTDEVICE 0x20A9000          //没有找到本地蓝牙设备
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SCAN_GETHANDLE 0x20A9001          //打开本地蓝牙设备失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SCAN_MALLOC 0x20A9002             //申请内存空间失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SCAN_NOSEARCH 0x20A9003           //没有搜索到别的蓝牙设备
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDCONNECT_PARAMENT 0x20A90010    //参数错误，无法连接
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDCONNECT_SETSOCKET 0x20A90011   //设置套接字属性失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDCONNECT_BIND 0x20A90012        //绑定网络失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDCONNECT_ISFAILED 0x20A90013    //连接失败，内部错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDSEND_PARAMENT 0x20A90020       //参数错误，发送数据失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDSEND_NOTFOUND 0x20A90021       //没有找到网络句柄
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDSEND_ISFAILED 0x20A90022       //发送数据失败，内部错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDRECV_PARAMENT 0x20A90030       //接受数据失败，参数错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDRECV_NOTFOUND 0x20A90031       //没有找到网络句柄
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDRECV_ISFAILED 0x20A90032       //接受数据失败，内部错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CMDCLOSE_NOTFOUND 0x20A90040      //没有找到句柄，关闭失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_START_PARAMENT 0x20A90050         //启动失败，参数错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_START_SETSOCKET 0x20A90051        //设置套接字失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_START_BIND 0x20A90052             //绑定服务失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_START_SETOPT 0x20A90053           //设置蓝牙属性失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_START_LISTEN 0x20A90054           //监听失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_START_CREATETHREAD 0x20A90055     //创建线程失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CONNECT_PARAMENT 0x20A90060       //连接失败，参数错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CONNECT_SETSOCKET 0x20A90061      //设置套接字失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CONNECT_BIND 0x20A90062           //绑定服务器失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_CONNECT_ISFAILED 0x20A90063       //连接失败，内部错误
//////////////////////////////////////////////////////////////////////////WINDOWS
#define ERROR_XCORE_WIRELESS_BLUETOOTH_BEGINLOOKUP 0x20A0001           //准备循环查找失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_PARAM 0x20A0002                 //参数传递错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_GETDEVINFO 0x20A0003            //获取设备信息错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_UNKNOW 0x20A0004                //未知错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_BTHADDRISNULL 0x20A0005         //蓝牙地址为空
#define ERROR_XCORE_WIRELESS_BLUETOOTH_FINDFIRSTENUM 0x20A0006         //开始枚举本地蓝牙设备失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETSTATE1 0x20A0007             //设置蓝牙状态失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETSTATE2 0x20A0008             //设置蓝牙状态失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETSTATE3 0x20A0009             //设置蓝牙状态失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_ENUMINSTALLSRV 0x20A000A        //枚举已经安装服务失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SELECTDEV 0x20A000B             //选择设备失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETSRVSTATE 0x20A000C           //设置蓝牙设备状态失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_ISOPENED 0x20A000D              //蓝牙设备已经打开了
#define ERROR_XCORE_WIRELESS_BLUETOOTH_COMNUMBER 0x20A0011             //串口号码范围错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_OPENCOM 0x20A0012               //打开蓝牙端口失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_GETCOMSTATE 0x20A0013           //获取蓝牙串口状态失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETTIMEOUT 0x20A0014            //设置超时时间失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETDTR 0x20A0005                //设置电位失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_GETPROPERTIES 0x20A0016         //获取通信属性失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_INPUTBUFFISSMALL 0x20A0017      //输入缓冲区太小了
#define ERROR_XCORE_WIRELESS_BLUETOOTH_READUNKOWN 0x20A0018            //读取缓冲区发生未知错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_WRITEBUFTOOSMALL 0x20A0019      //写入缓冲区太小了
#define ERROR_XCORE_WIRELESS_BLUETOOTH_WRITEUNKOWN 0x20A001A           //写入缓冲区发生未知错误
#define ERROR_XCORE_WIRELESS_BLUETOOTH_NOINIT 0x20A001B                //设备没有准备好或者没有初始化
#define ERROR_XCORE_WIRELESS_BLUETOOTH_SETMASK 0x20A001C               //设置蓝牙串口事件失败
#define ERROR_XCORE_WIRELESS_BLUETOOTH_WAITEVENT 0x20A001D             //设置等待事件失败
/************************************************************************/
/*                          红外设备API错误                             */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////LINUX
#define ERROR_XCORE_WIRELESS_INFRARED_INIT_PARAMENT 0x20A9100           //初始化失败，参数错误
#define ERROR_XCORE_WIRELESS_INFRARED_INIT_ISFAILED 0x20A9101           //初始化失败，内部错误
#define ERROR_XCORE_WIRELESS_INFRARED_INIT_READCONFIG 0x20A9102         //读取配置文件失败，无法继续
#define ERROR_XCORE_WIRELESS_INFRARED_GETCODE_NOTFOUND 0x20A9110        //没有找到TOKEN
#define ERROR_XCORE_WIRELESS_INFRARED_GETCODE_ISFAILED 0x20A9111        //获取CODE失败，内部错误
#define ERROR_XCORE_WIRELESS_INFRARED_GETCODE_ISNULL 0x20A9112          //获取CODE失败，红外没有接收到任何数据
#define ERROR_XCORE_WIRELESS_INFRARED_GETMSG_NOTFOUND 0x20A9120         //获取消息失败，没有找到
#define ERROR_XCORE_WIRELESS_INFRARED_GETMSG_ISFAILED 0x20A9121         //内部错误
#define ERROR_XCORE_WIRELESS_INFRARED_GETMSG_ISNULL 0x20A9122           //获取失败，这个CODE关联的数据已经空了
#define ERROR_XCORE_WIRELESS_INFRARED_SEND_PARAMENT 0x20A9130           //发送数据失败，参数错误
#define ERROR_XCORE_WIRELESS_INFRARED_SEND_OPEN 0x20A9131               //打开红外设备失败
#define ERROR_XCORE_WIRELESS_INFRARED_SEND_ISFAILED 0x20A9132           //内部错误
#define ERROR_XCORE_WIRELESS_INFRARED_DESTORY_NOTFOUND 0x20A9140        //没有找到，不需要销毁
//////////////////////////////////////////////////////////////////////////WINDOWS
#define ERROR_XCORE_WIRELESS_INFRARED_INIT_WSASOCKET 0x20A0110          //设置套接字模式失败
#define ERROR_XCORE_WIRELESS_INFRARED_INIT_GETOPTENUMDEV 0x20A0111      //获取套接字选项失败
#define ERROR_XCORE_WIRELESS_INFRARED_INIT_GETQUERYOPT 0x20A0112        //获取查询选项失败