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
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_CREATE_MALLOC 0x80B0000             //申请内存失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_CREATE_INITEVENT 0x80B0001          //初始化事件管理器失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_CREATE_INITMUTEX 0x80B0002          //初始化临界区失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_DELETE_PARAMENT 0x80B0010           //删除失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_DELETE_EVENT 0x80B0011              //删除事件失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_DELETE_MUTEX 0x80B0012              //删除临界区失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_WAIT_PARAMENT 0x80B0020             //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_WAIT_EVENT 0x80B0021                //等待事件失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_WAIT_MUTEX 0x80B0022                //等待临界区失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_WAIT_TIMEDOUT 0x80B0023             //等到超时
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_ACTIVE_PARAMENT 0x80B0030           //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_ACTIVE_EVENT 0x80B0031              //激活事件失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_RESET_PARAMENT 0x80B0040            //重置失败,参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATOREVENT_RESET_FAILED 0x80B0041              //重置失败,内部错误
//////////////////////////////////////////////////////////////////////////
//                         句柄操作导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_ADD_PARAMENT 0x80B1001              //参数错误，无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_ADD_ISEXIST 0x80B1002               //句柄存在,无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_ADD_MALLOC 0x80B1003                //申请内存失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_SET_NOTFOUND 0x80B1011              //没有找到，设置失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_GET_NOTFOUND 0x80B1020              //没有找到，获取失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_CREATE_PARAMENT 0x80B1030           //参数错误,生成失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORHANDLE_CREATE_FAILED 0x80B1031             //生成失败
//////////////////////////////////////////////////////////////////////////
//                         字符串操作导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_ATU_PARAMENT 0x80B2010            //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_ATU_GETMEMORYSIZE 0x80B2011       //获取字符串空间所需大小失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_ATU_LEN 0x80B2012                 //转换失败,提供的大小不够
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_ATU_ISFAILED 0x80B2012            //转换失败,无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_ATU_MALLOC 0x80B2013              //内存申请失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTA_PARAMENT 0x80B2020            //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTA_GETMEMORYSIZE 0x80B2021       //获取字符串空间所需大小失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTA_LEN 0x80B2021                 //转换失败,提供的大小不够
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTA_ISFAILED 0x80B2022            //转换失败,无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTA_MALLOC 0x80B2023              //申请内存失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHARCONVER_OPEN 0x80B2030         //打开转换器失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHARCONVER_MALLOC 0x80B2031       //申请内存失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHARCONVER_ISFAILED 0x80B2032     //转换失败，内部错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHARCONVER_NOTSUPPORT 0x80B2033   //不支持的转换参数
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_DELSUB_PARAMENT 0x80B2060         //删除字符串失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_DELSUB_MALLOC 0x80B2061           //申请内存失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_DELSUB_NOTFOUND 0x80B2062         //没有找到需要删除的字符串
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_DELFORCH_PARAMENT 0x80B2070       //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_DELTFORCH_NOTFOUND 0x80B2071      //没有找到指定字符
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHANGE_PARAMENT 0x80B2080         //修改字符串函数错误，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHANGE_START 0x80B2081            //查找开始位置失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_CHANGE_END 0x80B2082              //查找结束位置失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_FIXPATH_PARAMENT 0x80B2090        //修复失败,参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_FIXPATH_TYPE 0x80B2091            //输入的路径有问题,无法处理
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_GETLASTSTR_PARAMENT 0x80B20A0     //参数错误，无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_GETLASTSTR_LEN 0x80B20A1          //长度不正确，无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_GETSE_PARAMENT 0x80B20A2          //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_GETSE_FOUNDSTART 0x80B20A3        //查找开始字符串失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_GETSE_FOUNDEND 0x80B20A4          //查找结束字符串失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_GETPF_PARAMENT 0x80B20C0          //参数错误，无法继续
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_FROMSTRGET_PARAMENT 0x80B20E0     //分割key value失败,参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_FROMSTRGET_NOTFOUND 0x80B20E1     //没有找到
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_STRTOHEX_PARAMENT 0x80B2130       //字符串转16进制
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_HEXTOSTR_PARAMENT 0x80B2140       //16进制转字符串
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTU_PARAMENT 0x80B2150            //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORSTRING_UTU_FAILED 0x80B2151              //转换失败
//////////////////////////////////////////////////////////////////////////
//                       时间类错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_GETSYSTEM_PARAMENT 0x80B3000        //获取系统时间失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_GETSYSTEM_LOCAL 0x80B3001           //获取本地时间失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_FORMATSQL_PARAMENT 0x80B3010        //格式化时间失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_TTIMETOSTRING_PARAMENT 0x80B3020    //转换失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_TTIMETOSTRING_LOCAL 0x80B3021       //获取本地时间失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_GETTIMEOFDAY_PARAMENT 0x80B3040     //获取失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_STRTOSTUTIME_PARAMENT 0x80B3050     //参数错误转换失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMER_STRTOSTUTIME_NOTIME 0x80B3051       //不是标准时间格式,无法转换
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMESPAN_GETSTU_PARAMENT 0x80B3100      //获取时间差失败,参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMESPAN_GETSTR_PARAMENT 0x80B3110      //获取时间差失败
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMESPAN_CALSTU_PARAMENT 0x80B3120      //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMESPAN_CALSTR_PARAMENT 0x80B3130      //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMESPAN_GETGMT_PARAMENT 0x80B3140      //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORTIMESPAN_GETGMT_CVT 0x80B3141           //转换失败
/************************************************************************/
/*                       时间触发器                                     */
/************************************************************************/
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_CREATE_PARAMENT 0x80B3201       //参数错误
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_CREATE_MALLOC 0x80B3201         //申请内存失败
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_CREATE_THREAD 0x80B3202         //创建线程失败
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_SET_PARAMENT 0x80B3210          //参数错误
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_SET_EXIST 0x80B3211             //设置失败,已经存在的ID
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_GET_PARAMENT 0x80B3220          //参数错误
#define ERROR_XENGINE_LIB_BASELIB_TRIGGER_GET_NOTFOUND 0x80B3221          //获取失败,ID不存在
//////////////////////////////////////////////////////////////////////////
//                       文件字符串导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_READPROFILE_PARAMENT 0x80B5010
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_READPROFILE_OPENFILE 0x80B5011
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_READPROFILE_NOTFOUND 0x80B5012
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_WRITEPROFILE_PARAMENT 0x80B5020
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_WRITEPROFILE_OPENFILE 0x80B5021
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_WRITEPROFILE_CHANGEFILE 0x80B5022
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORFILE_WRITEPROFILE_MALLOC 0x80B5023
//////////////////////////////////////////////////////////////////////////
//                       内存操作
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_LIB_BASELIB_OPERATORBIT_MEMORY_MALLOC_PARAMENT 0x80B6001    //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERATORBIT_MEMORY_MALLOC_MALLOC 0x80B6002      //申请内存失败
//////////////////////////////////////////////////////////////////////////
//                       IP地址操作
//////////////////////////////////////////////////////////////////////////
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_SEGADDR_PARAMENT 0x80B7000      //分割失败，参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_SEGADDR_NOTFOUND 0x80B7001      //不是XENGINE标准
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_ADDRSTRUCT_PARAMENT 0x80B7010   //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_ADDRSTRUCT_NOTADDR 0x80B7011    //不是标准的IPV4地址
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_ADDRSTRUCT_NOTRANGE 0x80B7012   //地址返回不正确
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_IPV4ADDR_PARAMENT 0x80B7020     //不是IPV4,参数为空
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_IPV4ADDR_LEN 0x80B7021      //长度不对
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_IPV4ADDR_RANGE 0x80B7022    //地址的范围是错误的
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_IPV4ADDR_POINT 0x80B7023    //IP地址分割的点个数不正确
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_LANADDR_PARAMENT 0x80B7030  //参数错误，无法判断是否是内网IP
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_LANADDR_LEN 0x80B7031       //长度不合适
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_LANADDR_NOTIP 0x80B7032     //不是IP地址
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_LANADDR_GETRANGE 0x80B7033  //获取内网IP地址范围失败
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_LANADDR_NOTLANIP 0x80B7034  //不是内网IP
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_ADDR_PARAMENT 0x80B7040     //参数错误
#define ERROR_XENGINE_LIB_BASELIB_OPERTATORIPADDR_ADDR_NOTIP 0x80B7041        //不是IP地址