#pragma once
/********************************************************************
//	Created:	2013/3/20   09:17
//	Filename: 	NetEngine_SourceCode/NetEngine_Lib/NetEngine_PublicOperator/NetOperator_Error.h
//	File Path:	NetEngine_SourceCode/NetEngine_Lib/NetEngine_PublicOperator/
//	File Base:	NetOperator_Error.h
//	File Ext:	h
//  Project:    网络中心
//	Author:		dowflyon
//	Purpose:    导出的错误码
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         事件操作导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_MALLOC 0x10B0000             //申请内存失败
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_INITEVENT 0x10B0001          //初始化事件管理器失败
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_INITMUTEX 0x10B0002          //初始化临界区失败
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_PARAMENT 0x10B0003           //删除失败，参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_EVENT 0x10B0004              //删除事件失败
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_MUTEX 0x10B0005              //删除临界区失败
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_TIMEDOUT 0x10B0006           //等到超时
#define ERROR_XENGINE_BASELIB_BASELIB_EVENT_FAILED 0x10B0007             //重置失败,内部错误
//////////////////////////////////////////////////////////////////////////
//                         句柄操作导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_HANDLE_PARAMENT 0x10B1000           //参数错误,生成失败
#define ERROR_XENGINE_BASELIB_BASELIB_HANDLE_FAILED 0x10B1001             //生成失败
//////////////////////////////////////////////////////////////////////////
//                         字符集操作错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_CHARSET_PARAMENT 0x10B2000          //参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_CHARSET_GETMEMORYSIZE 0x10B2001     //获取字符串空间所需大小失败
#define ERROR_XENGINE_BASELIB_BASELIB_CHARSET_LEN 0x10B2002               //转换失败,提供的大小不够
#define ERROR_XENGINE_BASELIB_BASELIB_CHARSET_ISFAILED 0x10B2003          //转换失败,无法继续
#define ERROR_XENGINE_BASELIB_BASELIB_CHARSET_MALLOC 0x10B2004            //内存申请失败
#define ERROR_XENGINE_BASELIB_BASELIB_CHARSET_OPEN 0x10B2005              //参数错误
//////////////////////////////////////////////////////////////////////////
//                         字符串操作导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_STRING_PARAMENT 0x10B3000           //删除字符串失败，参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_STRING_MALLOC 0x10B3001             //申请内存失败
#define ERROR_XENGINE_BASELIB_BASELIB_STRING_NOTFOUND 0x10B3002           //没有找到需要删除的字符串
#define ERROR_XENGINE_BASELIB_BASELIB_STRING_START 0x10B3003              //查找开始位置失败
#define ERROR_XENGINE_BASELIB_BASELIB_STRING_END 0x10B3004                //查找结束位置失败
#define ERROR_XENGINE_BASELIB_BASELIB_STRING_TYPE 0x10B3005               //输入的路径有问题,无法处理
//////////////////////////////////////////////////////////////////////////
//                       时间类错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_TIME_PARAMENT 0x10B3000             //获取系统时间失败，参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_TIME_LOCAL 0x10B3001                //获取本地时间失败
#define ERROR_XENGINE_BASELIB_BASELIB_TIME_NOTIME 0x10B3002               //不是标准时间格式,无法转换
#define ERROR_XENGINE_BASELIB_BASELIB_TIME_CVT 0x10B3003                  //转换失败
#define ERROR_XENGINE_BASELIB_BASELIB_TIMESPAN_PARAMENT 0x10B3004         //获取时间差失败,参数错误
/************************************************************************/
/*                       时间触发器                                     */
/************************************************************************/
#define ERROR_XENGINE_BASELIB_BASELIB_TRIGGER_PARAMENT 0x10B3100          //参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_TRIGGER_MALLOC 0x10B3101            //申请内存失败
#define ERROR_XENGINE_BASELIB_BASELIB_TRIGGER_THREAD 0x10B3102            //创建线程失败
#define ERROR_XENGINE_BASELIB_BASELIB_TRIGGER_EXIST 0x10B3103             //设置失败,已经存在的ID
#define ERROR_XENGINE_BASELIB_BASELIB_TRIGGER_NOTFOUND 0x10B3104          //获取失败,ID不存在
//////////////////////////////////////////////////////////////////////////
//                       内存操作
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_MEMORY_PARAMENT 0x10B4000           //参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_MEMORY_MALLOC 0x10B4001             //申请内存失败
//////////////////////////////////////////////////////////////////////////
//                       版本号操作
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_IPVER_PARAMENT 0x10B5000            //参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_IPVER_FAILED 0x10B5001              //版本号错误
//////////////////////////////////////////////////////////////////////////
//                       BIT流操作
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_BASELIB_BASELIB_TREAM_PARAMENT 0x10B6000            //参数错误
#define ERROR_XENGINE_BASELIB_BASELIB_TREAM_MALLOC 0x10B6001              //内存申请失败