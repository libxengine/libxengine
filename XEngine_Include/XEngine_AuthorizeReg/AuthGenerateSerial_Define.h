#pragma once
/********************************************************************
//	Created:	2013/1/30  15:56
//	File Name: 	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthGenerateSerial\AuthGenerateSerial_Define.h
//	File Path:	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthGenerateSerial
//	File Base:	AuthGenerateSerial_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	生成卡号和密码导出函数
//	History:
*********************************************************************/
//LPCSTR lpszKeyType[] = { "未知类型","分钟卡","天数卡","次数卡","自定义卡" };
typedef enum 
{
    ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_UNKNOW = 0,                //无法识别的充值卡
    ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_MINUTE = 1,                //分钟
    ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_DAY = 2,                   //天数
    ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_TIME = 3,                  //次数卡
    ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_CUSTOM = 4                 //自定义过期日期
}ENUM_AUTHREG_GENERATESERIALTYPE,*LPENUM_AUTHREG_GENERATESERIALTYPE;
//////////////////////////////////////////////////////////////////////////
//                            导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD GenerateSerial_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                          天数类型卡导出函数                          */
/************************************************************************/
/********************************************************************
函数名称：XEngine_AuthGenerateSerial_Start
函数功能：开始生成指定的序列号
 参数.一：lpszUserHeader
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：自定义头，长度为6，填充5 比如 XHEAD
 参数.二：nHowNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：要生成多少张卡，生成多了，此函数会阻塞程序，那么请放置线程中运行
 参数.三：nCardNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：卡的段数，默认为5，AAAAA-BBBBB-CCCCC-DDDDD-EEEEE，取值范围4-10
 参数.四：pSt_CustomTimer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：如果第四个参数为自定义日期，那么这个参数必须赋值。如果第四个参数为天数卡，这个结构体的nDay 必须赋值，表明拥有几天。
        如果是分钟卡,那么这个值的nMinute必须有值,表示拥有的分钟.如果是次数卡,那么这个值的wFlags必须有值,表示拥有的次数,其他类型可以为NULL
 参数.五：en_GeneraterSerialType
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要生成的卡类型
返回值
  类型：逻辑型
  意思：是否生成成功
备注：生成成功后调用get函数来获取生成的卡，如果你不调用，而是再次调用此函数，那么此函数将会清空上次生成的卡信息
      输入的时间不能超过99999,多天卡现在由用户直接使用pSt_CustomTimer参数指定,不在内部指定了
*********************************************************************/
extern "C" BOOL XEngine_AuthGenerateSerial_Start(LPCSTR lpszUserHeader, int nHowNumber, int nCardNumber, XENGINE_LIBTIMER * pSt_CustomTimer, ENUM_AUTHREG_GENERATESERIALTYPE en_GeneraterSerialType = ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_DAY);
/********************************************************************
函数名称：XEngine_AuthGenerateSerial_Get
函数功能：获取一个序列号
 参数.一：ptszSerialNumber
  In/Out：In/Out
  类型：字符指针
  可空：N
  意思：输入你初始化为0的字符串内存缓冲区，最小 7 * 6 + 1。根据你上次生成的大小不同而不同
返回值
  类型：逻辑型
  意思：是否获取成功
备注：每次只能获取一次，生成好后通过此函数获取，你可以继续调用此函数来获取下一个序列号，直到返回假 错误码为ERROR_AUTHORIZEREG_SERIAL_GENERATER_DAY_GET_NONE
*********************************************************************/
extern "C" BOOL XEngine_AuthGenerateSerial_Get(CHAR *ptszSerialNumber);
/********************************************************************
函数名称：XEngine_AuthGenerateSerial_GetType
函数功能：获取一个序列号的类型
 参数.一：lpszSerialNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的缓冲区
 参数.二：pen_GeneraterSerialType
  In/Out：Out
  类型：枚举型
  可空：Y
  意思：导出此卡的类型
 参数.三：pSt_CustomTimer
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：如果不是自定义类型或者天数卡,或者次数卡，这个参数将不起作用
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL XEngine_AuthGenerateSerial_GetType(LPCSTR lpszSerialNumber,ENUM_AUTHREG_GENERATESERIALTYPE *pen_GeneraterSerialType,XENGINE_LIBTIMER *pSt_CustomTimer = NULL);
/********************************************************************
函数名称：XEngine_AuthGenerateSerial_GetCount
函数功能：获取剩余序列号个数
 参数.一：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的生成的序列号剩余个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XEngine_AuthGenerateSerial_GetCount(int* pInt_Count);
/************************************************************************/
/*                          扩展导出函数,建议使用                       */
/************************************************************************/
extern "C" BOOL XEngine_AuthGenerateSerial_StartEx(XNETHANDLE * pxhToken, LPCSTR lpszUserHeader, int nHowNumber, int nCardNumber, XENGINE_LIBTIMER * pSt_CustomTimer, ENUM_AUTHREG_GENERATESERIALTYPE en_GeneraterSerialType = ENUM_XENGINE_AUTHREG_GENERATESERIAL_TYPE_DAY);
extern "C" BOOL XEngine_AuthGenerateSerial_GetEx(XNETHANDLE xhToken, CHAR* ptszSerialNumber);
extern "C" BOOL XEngine_AuthGenerateSerial_GetTypeEx(XNETHANDLE xhToken, LPCSTR lpszSerialNumber, ENUM_AUTHREG_GENERATESERIALTYPE* pen_GeneraterSerialType, XENGINE_LIBTIMER* pSt_CustomTimer = NULL);
extern "C" BOOL XEngine_AuthGenerateSerial_GetCountEx(XNETHANDLE xhToken, int* pInt_Count);
extern "C" BOOL XEngine_AuthGenerateSerial_CloseEx(XNETHANDLE xhToken);
