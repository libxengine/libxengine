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
//////////////////////////////////////////////////////////////////////////
//                            导出的枚举型
//////////////////////////////////////////////////////////////////////////
#ifndef _MSC_BUILD
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
static LPCXSTR lpszXSerialType[5] = { "UNKNOW","MINUTE","DAY","TIME","CUSTOM" };
static LPCXSTR lpszXRegType[6] = { "UNKNOW","TEMP","TRY","OFFICIAL","UNLIMIT","EXPIRED" };
static LPCXSTR lpszXHDType[6] = { "UNKNOW","CPU","DISK","BOARD","MAC","BIOS" };
#ifndef _MSC_BUILD
#pragma GCC diagnostic pop
#endif
typedef enum
{
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_UNKNOW = 0,                 //无法识别的充值卡
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_MINUTE = 1,                 //分钟,本地使用在read和write的时候更新使用分钟
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_DAY = 2,                    //天数,本地使用天数卡,不使用不减天数.
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_TIME = 3,                   //次数卡
    ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_CUSTOM = 4                  //自定义过期日期
}ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE, * LPENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE;
typedef enum
{
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_UNKNOW = 0,                    //未注册,Authorize_Local_GetLeftTimer将返回失败
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_TEMP = 1,                      //临时,Authorize_Local_GetLeftTimer一次后过期,需要Write
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_TRY = 2,                       //试用
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_OFFICIAL = 3,                  //正式版
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_UNLIMIT = 4,                   //无限制版,永不过期.CDKEY不做任何验证
	ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE_EXPIRED = 5                    //已过期的版本,Authorize_Local_GetLeftTimer将返回失败
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
typedef enum
{
	ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE_UNKNOW = 0,                 //未知
	ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE_LOCAL = 0x01,               //本地
	ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE_LAN = 0x02,                 //局域网
	ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE_NETWORK = 0x04,             //网络
}ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE, * LPENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE;
//////////////////////////////////////////////////////////////////////////
//                            导出的结构体
//////////////////////////////////////////////////////////////////////////
typedef struct 
{
	XCHAR tszAddr[32];                                                    //服务器IP地址
	int nPort;                                                           //端口号码,如果>0表示CDKEY验证失败后改为网络验证
	//版本信息
	struct
	{
		XCHAR tszAppName[128];                                            //应用程序名称
		XCHAR tszAppVer[128];                                             //应用程序版本号
		__int64x nExecTime;                                              //程序已经执行次数,调用Authorize_Local_GetLeftTimer会更新
		bool bInit;                                                      //是否初始化,由用户控制
	}st_AuthAppInfo;
	//CDKEY信息
	struct
	{
		XCHAR tszHardware[1024];                                          //硬件码
		XCHAR tszCreateTime[64];                                          //CDKEY创建日期，年/月/日-小时：分钟：秒
		XCHAR tszRegisterTime[64];                                        //注册时间，年/月/日-小时：分钟：秒
		XCHAR tszLeftTime[64];                                            //总的剩余时间,过期日期，根据nLeftType决定此值的意义
		XCHAR tszStartTime[64];                                           //当前启动时间,由系统读取CDKEY的时候自动更新,天数和分钟有效
		XCHAR tszExpiryTime[64];                                          //过期的时间,需要调用Authorize_Local_GetLeftTimer并且Write才生效
		__int64x nHasTime;                                               //当前还拥有时间，根据nLeftType决定此值的意义,调用Authorize_Local_GetLeftTimer会更新
		ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE enSerialType;          //过期类型，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE
		ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE enRegType;                //注册类型，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_REG_TYPE
		ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE enHWType;                  //硬件类型，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_HW_TYPE
		ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE enVModeType;          //验证方式，参考:ENUM_HELPCOMPONENTS_AUTHORIZE_VERMODE_TYPE 
	}st_AuthRegInfo;
	//临时序列号
	struct  
	{
		//次数限制
		struct  
		{
			XCHAR tszTimeSerial[128];                                     
			int nTimeCount;                                              //使用次数
			int nTimeNow;                                                //已用次数
		}st_TimeLimit;
		//时间限制
		struct  
		{
			XCHAR tszDataTime[128];                                       //过期时间
			XCHAR tszDataSerial[128];                                     //序列号
		}st_DataLimit;
		//无限制
		struct  
		{
			XCHAR tszUNLimitSerial[128];                                  //无限制序列号
		}st_UNLimit;
	}st_AuthSerial;
	//注册的用户信息，可以不填
	struct
	{
		XCHAR tszUserName[64];                                            //注册的用户
		XCHAR tszUserContact[64];                                         //联系方式，电子邮件或者手机等
		XCHAR tszCustom[1024];                                            //自定义数据
	}st_AuthUserInfo;
}XENGINE_AUTHORIZE_LOCAL, * LPXENGINE_AUTHORIZE_LOCAL;
//////////////////////////////////////////////////////////////////////////
//                            导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG Authorize_GetLastError(int *pInt_SysError = NULL);
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
  意思：卡的段数，AAAAA-BBBBB-CCCCC-DDDDD-EEEEE,不包含三段自定义头,总字段:3 + nFieldNumber
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
extern "C" bool Authorize_Serial_Creator(XCHAR * **ppptszSerialNumber, LPCXSTR lpszUserHeader, int nCardNumber, int nFieldNumber, XENGINE_LIBTIMER * pSt_CustomTimer, ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE enSerialType = ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE_DAY);
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
extern "C" bool Authorize_Serial_Create(XCHAR*** ppptszSerialNumber, LPCXSTR lpszUserHeader, int nCardNumber, int nFieldNumber);
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
extern "C" bool Authorize_Serial_GetType(LPCXSTR lpszSerialNumber, ENUM_HELPCOMPONENTS_AUTHORIZE_SERIAL_TYPE* penSerialType, XENGINE_LIBTIMER* pSt_CustomTimer = NULL);
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
extern "C" bool Authorize_Local_WriteKey(LPCXSTR lpszFileKey, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
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
extern "C" bool Authorize_Local_ReadKey(LPCXSTR lpszFileKey, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
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
extern "C" bool Authorize_Local_WriteMemory(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
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
extern "C" bool Authorize_Local_ReadMemory(LPCXSTR lpszMsgBuffer, int nMsgLen, XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal);
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
  意思：可用时间或者次数.非自定义时间需要设置此值
 参数.三：pSt_DayTimer
  In/Out：In
  类型：结构体指针
  可空：Y
  意思：如果是自定义时间,这个参数需要设置,其他类型请设置参数二
返回值
  类型：逻辑型
  意思：是否构造成功
备注：此函数会修改st_AuthRegInfo的时间信息成员
*********************************************************************/
extern "C" bool Authorize_Local_BuildKeyTime(XENGINE_AUTHORIZE_LOCAL* pSt_AuthLocal, __int64x nDayTimer = 0, XENGINE_LIBTIMER* pSt_DayTimer = NULL);
/********************************************************************
函数名称：Authorize_Local_GetLeftTimer
函数功能：验证CDKey
 参数.一：pSt_AuthLocal
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入Authorize_Local_ReadKey获取到的值
 参数.二：lpszSerialNumber
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：如果CDKEY带序列号,可以输入序列号进行验证(优先序列号验证,失败进行常规CDKEY验证)
返回值
  类型：逻辑型
  意思：是否成功
备注：无限制版本不做验证
	  其他验证nHasTime将被设置还拥有时间
*********************************************************************/
extern "C" bool Authorize_Local_GetLeftTimer(XENGINE_AUTHORIZE_LOCAL * pSt_AuthLocal, LPCXSTR lpszSerialNumber = NULL);
/********************************************************************
函数名称：Authorize_Local_WriteTime
函数功能：记录一次执行时间
 参数.一：lpszFileKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的文件
 参数.二：nCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入最大允许记录个数,0不限制
返回值
  类型：逻辑型
  意思：是否成功
备注：记录次数越多,文件越大.读取需要的内存就越多
*********************************************************************/
extern "C" bool Authorize_Local_WriteTime(LPCXSTR lpszFileKey, int nCount = 0);
/********************************************************************
函数名称：Authorize_Local_ReadTime
函数功能：读取记录的时间列表信息
 参数.一：lpszFileKey
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要读取的文件
 参数.二：ppptszTimeList
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出时间信息列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool Authorize_Local_ReadTime(LPCXSTR lpszFileKey, XCHAR*** ppptszTimeList, int* pInt_ListCount);