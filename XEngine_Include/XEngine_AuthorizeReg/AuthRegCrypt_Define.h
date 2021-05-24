#pragma once
/********************************************************************
//	Created:	2013/2/1  17:38
//	File Name: 	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegCrypt\AuthRegCrypt_Define.h
//	File Path:	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegCrypt
//	File Base:	AuthRegCrypt_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	加解密库函数导出
//	History:
//  Notic:
*********************************************************************/
typedef struct tag_XEngine_AuthRegCrypt_Local
{
    CHAR tszAddr[32];                                                    //服务器IP地址
    int nPort;                                                           //端口号码
    //版本信息
    struct
    {
        CHAR tszAppName[128];                                            //应用程序名称
        CHAR tszAppVer[128];                                             //应用程序版本号
        BOOL bInit;                                                      //是否初始化,发布为假,第一次运行注册后设置为真,可以带CDKEY发布
    }st_AuthAppInfo;
    //CDKEY信息
    struct
    {
        __int64x nHasTime;                                               //总有拥有时间，根据nLeftType决定此值的意义
        int nHWType;                                                     //硬件类型
        int nRegType;                                                    //注册类型，0未注册，1临时，2试用，3正式
        int nLeftType;                                                   //过期类型,参考:ENUM_AUTHREG_GENERATESERIALTYPE
        CHAR tszHardware[64];                                            //硬件码
        CHAR tszRegTime[64];                                             //注册时间，年/月/日-小时：分钟：秒
        CHAR tszLeftTime[64];                                            //剩余时间,过期日期，根据nLeftType决定此值的意义
    }st_AuthRegInfo;    
    //注册的用户信息，可以不填
    struct
    {
        CHAR tszUserName[64];                                            //注册的用户
        CHAR tszUserContact[64];                                         //联系方式，电子邮件或者手机等
        CHAR tszCustom[64];                                              //自定义数据
    }st_AuthUserInfo;                                                    
}XENGINE_AUTHREGCRYPT_LOCAL,*LPXENGINE_AUTHREGCRYPT_LOCAL;
//////////////////////////////////////////////////////////////////////////
//                  导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AuthRegCrypt_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                  解密函数导出                                        */
/************************************************************************/
/********************************************************************
函数名称：AuthRegCrypt_DeCoder_String
函数功能：解密数据
 参数.一：puszSource
  In/Out：In
  类型：常量无符号字符指针
  可空：N
  意思：要解密的数据
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入解密数据长度，输出解密后的数据长度
 参数.三：puszDest
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解密后的数据
 参数.四：lpszPassword
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解密数据需要的密码
返回值
  类型：逻辑型
  意思：是否解密成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegCrypt_DeCoder_String(const UCHAR *puszSource,int *pInt_Len,CHAR *ptszDest, LPCSTR lpszPassword);
/************************************************************************/
/*                  加密函数导出                                        */
/************************************************************************/
/********************************************************************
函数名称：AuthRegCrypt_EnCoder_String
函数功能：加密数据
 参数.一：lpszSource
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要加密的数据
 参数.二：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入加密数据长度，输出加密后的数据长度
 参数.三：puszDest
  In/Out：Out
  类型：无符号字符指针
  可空：N
  意思：输出加密后的数据
 参数.四：lpszPassword
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：输入要加密数据的密码
返回值
  类型：逻辑型
  意思：是否加密成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegCrypt_EnCoder_String(LPCSTR lpszSource,int *pInt_Len,UCHAR *puszDest, LPCSTR lpszPassword);
/************************************************************************/
/*                  本地注册信息文件管理器                              */
/************************************************************************/
/********************************************************************
函数名称：AuthRegCrypt_Local_WriteDatFile
函数功能：创建或者重写一个CDKEY
 参数.一：lpszFileDat
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册信息文件路径
 参数.二：pSt_AuthRegLocal
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要重写的结构体
 参数.三：lpszPassword
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入注册信息文件密码,如果为NULL,CDKEY将为明文
返回值
  类型：逻辑型
  意思：是否成功
备注：如果是创建pSt_AuthRegLocal里面的内容需要你自己添加
*********************************************************************/
extern "C" BOOL AuthRegCrypt_Local_WriteDatFile(LPCSTR lpszFileDat, LPXENGINE_AUTHREGCRYPT_LOCAL pSt_AuthRegLocal, LPCSTR lpszPassword = NULL);
/********************************************************************
函数名称：AuthRegCrypt_Local_ReadDatFile
函数功能：读取一个CDKEY
 参数.一：lpszFileDat
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册信息文件路径
 参数.二：pSt_AuthRegLocal
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出读取到的结构体
 参数.三：lpszPassword
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入注册信息文件密码,如果为NULL,那么CDKEY必须是明文
返回值
  类型：逻辑型
  意思：是否成功
备注：要判断一个CDKEY是否过期可以通过此函数获取来处理,然后通过硬件码判断是否匹配
*********************************************************************/
extern "C" BOOL AuthRegCrypt_Local_ReadDatFile(LPCSTR lpszFileDat, LPXENGINE_AUTHREGCRYPT_LOCAL pSt_AuthRegLocal, LPCSTR lpszPassword = NULL);
/********************************************************************
函数名称：AuthRegCrypt_Local_BuildKeyTime
函数功能：构造注册的时间结构体信息
 参数.一：pSt_AuthRegLocal
  In/Out：In
  类型：结构体指针
  可空：N
  意思：要构造的结构体
 参数.二：nDayTimer
  In/Out：In
  类型：整数型
  可空：Y
  意思：使用的时间，单位：天，如果为空 第三个参数不能为空
 参数.三：pSt_DayTimer
  In/Out：In
  类型：结构体指针
  可空：Y
  意思：到期的日期，如果这个参数为空，第二个参数不能为空
返回值
  类型：逻辑型
  意思：是否构造成功
备注：此函数会修改st_AuthRegInfo的时间信息成员
*********************************************************************/
extern "C" BOOL AuthRegCrypt_Local_BuildKeyTime(LPXENGINE_AUTHREGCRYPT_LOCAL pSt_AuthRegLocal, int nDayTimer = 0, XENGINE_LIBTIMER *pSt_DayTimer = NULL);
/********************************************************************
函数名称：AuthRegClient_Local_GetLeftTimer
函数功能：获取用户注册超时时间
 参数.一：pInt_LeftTimer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的到期的时间,根据nLeftType确定此值过期类型
 参数.二：pSt_AuthRegLocal
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入AuthRegCrypt_Local_ReadDatFile获取到的值
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AuthRegCrypt_Local_GetLeftTimer(__int64x *pInt_LeftTimer, XENGINE_AUTHREGCRYPT_LOCAL *pSt_AuthRegLocal);
