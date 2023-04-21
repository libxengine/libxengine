#pragma once
/********************************************************************
//	Created:	2019/1/18   9:32
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SIP\RfcSip_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_RfcComponents\RfcComponents_SIP
//	File Base:	RfcSip_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	SIP协议导出错误
//	History:
*********************************************************************/
/************************************************************************/
/*                     SIP协议端导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSE_PARAMENT 0x70F0001        //初始化失败，参数错误
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSE_MALLOC 0x70F0002          //申请内存失败
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEHDR_NOTCOMPLETE 0x70F0010  //协议不完成
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEHDR_LOST 0x70F0011         //协议丢失或者被损坏
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEHDR_FAILED 0x70F0012       //协议头错误,协议不正确
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PACKET_PARAMENT 0x70F0020       //参数错误
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_VIA 0x70F00A0          //协议错误,无法继续
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_VIANOTCOMPLETE 0x70F00A1  //协议错误,不完整
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_CONTACT 0x70F00A2      //协议错误,无法继续
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_TO 0x70F00A3           //协议错误,无法继续
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_FROM 0x70F00A4         //协议解析失败
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_AUTH 0x70F00A5         //协议错误,无法继续
#define ERROR_RFCCOMPONENTS_SIP_PROTOCOL_PARSEPRO_VIANOTIDEL 0x70F00A6   //没有可用的路由信息
/************************************************************************/
/*                     SIP组包器导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SIP_PACKET_INSERT_PARAMENT 0x70F1001         //参数错误
#define ERROR_RFCCOMPONENTS_SIP_PACKET_INSERT_MALLOC 0x70F1002           //申请内存失败
#define ERROR_RFCCOMPONENTS_SIP_PACKET_INSERT_PROTOCOL 0x70F1003         //协议错误
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GET_PARAMENT 0x70F1010            //参数错误
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GET_EMPTY 0x70F1011               //数据队列什么都没有
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GET_NOTFOUND 0x70F1012            //没有找到指定客户端
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GET_NOTDATA 0x70F1013             //指定客户端没有数据
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GET_SIZE 0x70F1014                //提供的缓冲区大小不够
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GETRANDOM_PARAMENT 0x70F1020      //参数错误
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GETRANDOM_EMPTY 0x70F1021         //没有队列
#define ERROR_RFCCOMPONENTS_SIP_PACKET_GETRANDOM_NOTPKT 0x70F1022        //没有可取的数据包
/************************************************************************/
/*                     SIP组包器导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_INITCODE_NOTFOUND 0xA0B2000        //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_INITCODE_PARSE 0xA0B2001           //解析错误
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_GETCODE_PARAMENT 0xA0B2010         //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_GETCODE_NOTFOUND 0xA0B2011         //没有找到
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_INITMIME_PARAMENT 0xA0B2020        //参数错误，初始化失败
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_INITMIME_READFILE 0xA0B2021        //读取配置文件错误
#define ERROR_RFCCOMPONENTS_SIP_CONFIG_GETMIME_PARAMENT 0xA0B2030         //参数错误
/************************************************************************/
/*                     SIP服务器导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SIP_SERVER_INIT_PARAMENT 0xA0B3001            //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_CREATE_PARAMENT 0xA0B3010          //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_PROCESS_PARAMENT 0xA0B3020         //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_PROCESS_NOTFOUND 0xA0B3021         //没有找到客户端
#define ERROR_RFCCOMPONENTS_SIP_SERVER_SETSTATUS_PARAMENT 0xA0B3030       //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_SETSTATUS_NOTFOUND 0xA0B3031       //没有找到
#define ERROR_RFCCOMPONENTS_SIP_SERVER_GETSTATUS_PARAMENT 0xA0B3040       //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_GETSTATUS_NOTFOUND 0xA0B3041       //没有找到
#define ERROR_RFCCOMPONENTS_SIP_SERVER_FINDADDR_PARAMENT 0xA0B3051 //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_FINDADDR_NOTFOUND 0xA0B3052        //没有找到指定用户
#define ERROR_RFCCOMPONENTS_SIP_SERVER_SETRESPONSE_PARAMENT 0xA0B3060     //参数错误,设置失败
#define ERROR_RFCCOMPONENTS_SIP_SERVER_SETRESPONSE_NOTFOUND 0xA0B3061     //没有找到
#define ERROR_RFCCOMPONENTS_SIP_SERVER_GETRESPONSE_PARAMENT 0xA0B3070     //参数错误
#define ERROR_RFCCOMPONENTS_SIP_SERVER_GETRESPONSE_NOTFOUND 0xA0B3071     //没有找到
/************************************************************************/
/*                     SIP客户端导出错误                                */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_CREATE_PARAMENT 0xA0B4001          //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REGISTER_PARAMENT 0xA0B4010        //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REGISTER_NOTFOUND 0xA0B4011        //没有找到客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REGISTER_NOTSUPPORTAUTH 0xA0B4012  //服务器需要验证,客户端不支持
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQINVITE_PARAMENT 0xA0B4020       //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQINVITE_NOTFOUND 0xA0B4021       //没有找到客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REPINVITE_PARAMENT 0xA0B4030       //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REPINVITE_NOTFOUND 0xA0B4031       //没有找到客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQMESSAGE_PARAMENT 0xA0B4040      //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQMESSAGE_NOTFOUND 0xA0B4041      //没有找到指定客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_GETSTATUS_PARAMENT 0xA0B4050       //获取状态失败,参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_GETSTATUS_NOTFOUND 0xA0B4051       //没有找到指定客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_SETSTATUS_NOTFOUND 0xA0B4060       //没有找到指定客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQCANECEL_PARAMENT 0xA0B4070      //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQCANECEL_NOTFOUND 0xA0B4071      //没有找到
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQBYE_PARAMENT 0xA0B4080          //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_REQBYE_NOTFOUND 0xA0B4081          //没有找到
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_OPTION_PARAMENT 0xA0B4090          //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_OPTION_NOTFOUND 0xA0B4091          //没有找到
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESS_PARAMENT 0xA0B4100         //参数错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESS_NOTFOUND 0xA0B4101         //没有找到客户端
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_NOTTAUTH 0xA0B4120      //客户端不支持验证
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_NEEDAUTH 0xA0B4121      //需要验证
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_OTHER 0xA0B4122         //服务器返回了其他错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_INVITE 0xA0B4123        //呼叫失败.返回了一个错误
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_RING 0xA0B4124          //响铃失败
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_COMM 0xA0B4125          //对话挂断了通话
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_NEWMESSAGE 0xA0B4126    //服务器处理消息转发失败
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_MESSAGE 0xA0B4127       //消息处理失败
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_CANCEL 0xA0B4128        //取消失败
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_BYE 0xA0B4129           //结束失败
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSREP_OPTION 0xA0B412A        //请求选项失败
#define ERROR_RFCCOMPONENTS_SIP_CLIENT_PROCESSSTATUS_STATUS 0xA0B4130     //状态错误,无法继续
