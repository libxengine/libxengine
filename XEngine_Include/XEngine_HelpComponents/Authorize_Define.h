#pragma once
/********************************************************************
//    Created:     2021/07/20  10:49:03
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_HelpComponents\HelpComponents_Serial\Serial_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_HelpComponents\HelpComponents_Serial
//    File Base:   Serial_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     序列号生成器
//    History:
*********************************************************************/
//LPCSTR lpszKeyType[] = { "未知类型","分钟卡","天数卡","次数卡","自定义卡" };
//////////////////////////////////////////////////////////////////////////
//                            导出的枚举型
//////////////////////////////////////////////////////////////////////////
typedef enum
{
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_UNKNOW = 0,                 //无法识别的充值卡
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_MINUTE = 1,                 //分钟
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_DAY = 2,                    //天数
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_TIME = 3,                   //次数卡
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_CUSTOM = 4                  //自定义过期日期
}ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE, * LPENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE;
typedef enum
{
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_UNKNOW = 0,                    //未注册
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_TEMP = 1,                      //临时
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_TRY = 2,                       //试用
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_OFFICIAL = 3,                  //正式版
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_UNLIMIT = 4                    //无限制版
}ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE, * LPENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE;
typedef enum
{
	ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE_UNKNOW = 0,                     //未指定
	ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE_CPU = 1,                        //CPU序列号
	ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE_DISK = 2,                       //硬盘序列号
	ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE_BOARD = 3,                      //主板序列号
	ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE_MAC = 4,                        //网卡MAC地址
	ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE_BIOS = 5                        //BIOS序列号
}ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE, * LPENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE;
//////////////////////////////////////////////////////////////////////////
//                            导出的结构体
//////////////////////////////////////////////////////////////////////////
typedef struct 
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
		CHAR tszHardware[64];                                            //硬件码
		CHAR tszCreateTime[64];                                          //CDKEY创建日期，年/月/日-小时：分钟：秒
		CHAR tszRegisterTime[64];                                        //注册时间，年/月/日-小时：分钟：秒
		CHAR tszLeftTime[64];                                            //剩余时间,过期日期，根据nLeftType决定此值的意义
		__int64x nHasTime;                                               //总有拥有时间，根据nLeftType决定此值的意义
		ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE enSerialType;          //过期类型，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE
		ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE enRegType;                //注册类型，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE
		ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE enHWType;                  //硬件类型，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE
	}st_AuthRegInfo;
	//注册的用户信息，可以不填
	struct
	{
		CHAR tszUserName[64];                                            //注册的用户
		CHAR tszUserContact[64];                                         //联系方式，电子邮件或者手机等
		CHAR tszCustom[64];                                              //自定义数据
	}st_AuthUserInfo;
}XENGINE_AUTHORIZE_LOCAL, * LPXENGINE_AUTHORIZE_LOCAL;
//////////////////////////////////////////////////////////////////////////
//                            导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD Authorize_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                           序列卡导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：Authorize_Serial_Creator
函数功能：开始生成指定的序列号
 参数.一：ppptszSerialNumber
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出序列卡列表,根据nCardNumber 来确定列表个数
 参数.二：lpszUserHeader
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：自定义头，长度为6，填充5 比如 XHEAD
 参数.三：nCardNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：要生成多少张卡，生成多了，此函数会阻塞程序，那么请放置线程中运行
 参数.四：nFieldNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：卡的段数，AAAAA-BBBBB-CCCCC-DDDDD-EEEEE
 参数.五：pSt_CustomTimer
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：如果第五个参数为自定义日期，那么这个参数必须赋值。如果第五个参数为天数卡，这个结构体的nDay 必须赋值，表明拥有几天。
		如果是分钟卡,那么这个值的nMinute必须有值,表示拥有的分钟.如果是次数卡,那么这个值的wFlags必须有值,表示拥有的次数,其他类型可以为NULL
 参数.六：enSerialType
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要生成的卡类型
返回值
  类型：逻辑型
  意思：是否生成成功
备注：输入的时间不能超过99999,多天卡现在由用户直接使用pSt_CustomTimer参数指定,不在内部指定了
*********************************************************************/
extern "C" BOOL Authorize_Serial_Creator(CHAR * **ppptszSerialNumber, LPCSTR lpszUserHeader, int nCardNumber, int nFieldNumber, XENGINE_LIBTIMER * pSt_CustomTimer, ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE enSerialType = ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_DAY);
/********************************************************************
函数名称：Authorize_Serial_Create
函数功能：创建自定义无类型序列号
 参数.一：ppptszSerialNumber
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出序列卡列表,根据nCardNumber 来确定列表个数
 参数.二：lpszUserHeader
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：自定义头，长度为6，填充5 比如 XHEAD
 参数.三：nCardNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：要生成多少张卡，生成多了，此函数会阻塞程序，那么请放置线程中运行
 参数.四：nFieldNumber
  In/Out：In
  类型：整数型
  可空：N
  意思：卡的段数，AAAAA-BBBBB-CCCCC-DDDDD-EEEEE
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Authorize_Serial_Create(CHAR*** ppptszSerialNumber, LPCSTR lpszUserHeader, int nCardNumber, int nFieldNumber);
/********************************************************************
函数名称：Authorize_Serial_GetType
函数功能：获取一个序列号的类型
 参数.一：lpszSerialNumber
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的缓冲区
 参数.二：penSerialType
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
extern "C" BOOL Authorize_Serial_GetType(LPCSTR lpszSerialNumber, ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE* penSerialType, XENGINE_LIBTIMER* pSt_CustomTimer = NULL);
/************************************************************************/
/*                           本地授权导出函数                           */
/************************************************************************/
/********************************************************************
函数名称：Authorize_Local_WriteKey
函数功能：写一个CDKey文件
 参数.一：lpszFileKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的文件路径
 参数.二：pSt_AuthLocal
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要写入的文件信息
返回值
  类型：逻辑型
  意思：是否成功
备注：写入读取必须是明文,建议你加密处理CDKEY,通过OPENSSL模块,来加解密,在读写
*********************************************************************/
extern "C" BOOL Authorize_Local_WriteKey(LPCSTR lpszFileKey, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
/********************************************************************
函数名称：Authorize_Local_ReadKey
函数功能：读一个数据文件
 参数.一：lpszFileKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的文件路径
 参数.二：pSt_AuthLocal
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的文件信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Authorize_Local_ReadKey(LPCSTR lpszFileKey, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
/********************************************************************
函数名称：Authorize_Local_WriteMemory
函数功能：写配置信息到内存
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：写到的内存
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：写到的内存大小
 参数.三：pSt_AuthLocal
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要写的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Authorize_Local_WriteMemory(TCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
/********************************************************************
函数名称：Authorize_Local_ReadMemory
函数功能：内存配置文件读取
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取配置的内存
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入读取内存大小
 参数.三：pSt_AuthLocal
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出读取到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL Authorize_Local_ReadMemory(LPCTSTR lpszMsgBuffer, int nMsgLen, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
/********************************************************************
函数名称：Authorize_Local_BuildKeyTime
函数功能：构造注册的时间结构体信息
 参数.一：pSt_AuthLocal
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
extern "C" BOOL Authorize_Local_BuildKeyTime(XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal, __int64x nDayTimer = 0, XENGINE_LIBTIMER* pSt_DayTimer = NULL);
/********************************************************************
函数名称：AuthRegClient_Local_GetLeftTimer
函数功能：获取用户注册超时时间
 参数.一：pInt_LeftTimer
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的到期的时间,根据nLeftType确定此值过期类型
 参数.二：pSt_AuthLocal
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入Authorize_Local_ReadKey获取到的值
返回值
  类型：逻辑型
  意思：是否成功
备注：无限制版本参数一将导出-1并且不在计算过期时间
*********************************************************************/
extern "C" BOOL Authorize_Local_GetLeftTimer(__int64x* pInt_LeftTimer, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);