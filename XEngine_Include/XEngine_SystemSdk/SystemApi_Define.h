#pragma once
/********************************************************************
//	Created:	2011/10/17   12:26
//	Filename: 	NetSocketEngine/NetLinuxSdk/LinuxSdk/LinuxSdk_Define.h
//	File Path:	NetSocketEngine/NetLinuxSdk/LinuxSdk/
//	File Base:	LinuxSdk
//	File Ext:	h
//  Project:    血与荣誉网络通信引擎 For Linux
//	Author:		dowflyon
//	Purpose:	LinuxSdk导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//磁盘类型
typedef enum en_SystemApi_Disk_Type
{
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_UNKNOW = 0,                          //未知类型
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_INVALID = 1,                         //无效
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_REMOVABLE = 2,                       //可移动磁盘
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_FIXED = 3,                           //固定硬盘
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_REMOTE = 4,                          //网络磁盘
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_CDROM = 5,                           //光驱
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE_RAMDISK = 6                          //内存
}ENUM_SYSTEMAPI_HARDWARE_DISKTYPE,*LPENUM_SYSTEMAPI_HARDWARE_DISKTYPE;
//文件系统类型
typedef enum en_SystemApi_FileSys_Type
{
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_UNKNOW = 0,                    //未知类型
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_FAT = 1,                       //FAT文件系统
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_NTFS = 2,                      //NFTS文件系统
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_OLDEXT2 = 3,                   //老旧的EXT2文件系统
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_EXT4 = 4                       //EXT4文件系统
}ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE,*LPENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE;
//////////////////////////////////////////////////////////////////////////
//                        导出的定义
//////////////////////////////////////////////////////////////////////////
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_SHUTDOWN 0x00010001L      //关闭计算机
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_CLOSESCREEN 0x00010002L   //关闭屏幕
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_REBOOT 0x00010003L        //重新启动计算机
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_LOGOUT 0x00010004L        //注销
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_LOCK 0x00010005L          //锁定计算机
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_SLEEP 0x00010006L         //休眠
#define XENGINE_SYSTEMSDK_API_SYSTEM_SHUTDOWN_HOOK 0x00010007L          //挂起
/************************************************************************/
/*               系统SDK开发类导出的定义                                   */
/************************************************************************/
//内存信息返回
#define XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_B 1                          //内存信息返回，大小B
#define XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_KB 2                         //返回KB
#define XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_MB 3                         //返回MB
#define XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_GB 4                         //返回GB
//系统构建类型
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_CENTOS 0x0001DC01         //CENTOS系统
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_REDHAT 0x0001DC02         //REDHAT
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_UBUNTU 0x0001DC03
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_DEBIAN 0x0001DC04
//这里是系统信息类导出的定义。用于获取系统是否正常启动
#define XENGINE_SYSTEMSDK_API_SYSTEM_BOOT_NORMAL 0x0000000A                //系统是正常启动的
#define XENGINE_SYSTEMSDK_API_SYSTEM_BOOT_FAILDSAFE 0x0000000B             //故障安全引导方式启动
#define XENGINE_SYSTEMSDK_API_SYSTEM_BOOT_FAILDNETSAFE 0x0000000C          //故障安全带网络模式的启动
#define XENGINE_SYSTEMSDK_API_SYSTEM_BOOT_UNKNOW 0x0000000D                //无法识别的启动方式
//系统版本
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_VISTA 6001               //VISTA
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_2008 6002                //2008
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_7 6101                   //WINDOWS7
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_2008R2 6102              //2008-R2
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_8 6201                   //WIN8
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_2012 6202                //2012
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_81 6301                  //WIN8.1
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_2012R2 6302              //2012-R2
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_10 10000
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_2016 10001
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERSION_2019 11000
//系统构建类型
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_ULTIMATE 0x0001DC01       //旗舰版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_PROFESSIONAL 0x0001DC02   //专业版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_HOMEPREMIUM 0x0001DC03    //家庭高级版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_HOMEBASIC 0x0001DC04      //家庭基础版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_ENTERPRISE 0x0001DC05     //企业版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_BUSINESS 0x0001DC06       //商业版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_STARTER 0x0001DC07        //简化版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_CLUSTERSERVER 0x0001DC08  //磁簇服务器版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_DATACENTER 0x0001DC09     //数据中心版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_COREINSTALL 0x0001DC0A    //核心安装版 
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_ENTERPRISESERVER 0x0001DC0B               //企业服务器版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_CORESERVERINSTALL 0x0001DC0C              //核心服务安装版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_ENTEPRISEITANIUMBASE 0x0001DC0D           //企业版本基于IA64架构
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_SMALLBUSINESSSERVER 0x0001DC0E            //最小的商业服务器版本
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_SMALLBUSINESSSERVERPREMIUM 0x0001DC0F     //小型服务器商业高级版本
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_STANDARD 0x0002DC00       //标准版
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_STANDARDCOREINSTALL 0x0002DC01            //标准核心安装
#define XENGINE_SYSTEMSDK_API_SYSTEM_VERTYPE_WEBSERVER 0x0002DC02      //WEB服务器版本
/************************************************************************/
/*                界面控制函数导入定义                                  */
/************************************************************************/
//窗口吸附选项
#define XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_LEFT 0x0001            //窗口吸附左边
#define XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_TOP 0X0002             //窗口吸附顶边
#define XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_RIGHT 0x0003           //窗口吸附右边
#define XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_BOTTOM 0x0004          //窗口吸附下面s
#define XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_AUTO 0x0005            //窗口吸附自动调整
//窗口吸附样式
#define XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_NORMAL 0x0006          //普通样式
//////////////////////////////////////////////////////////////////////////
//                        导出的回调函数
//////////////////////////////////////////////////////////////////////////
//文件枚举回调函数声明 导出目录或者文件路径，自定义参数，如果你想结束，不像继续枚举，那么就返回FALSE给我们即可
typedef BOOL(CALLBACK *CALLBACK_XENGINE_SDK_SYSTEMAPI_FILE_ENUM)(LPCSTR lpszFileOrPath,BOOL bFindPath,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                        导出数据结构定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      文件路径SDK数据结构                             */
/************************************************************************/
typedef struct tag_SystemApi_File_Infomation
{
    BOOL bIsFile;                                                         //文件还是路径,真为文件
    CHAR tszFileDir[MAX_PATH];                                           //文件或者路径名
}SYSTEMAPI_FILE_INFOMATION, *LPSYSTEMAPI_FILE_INFOMATION;
//内存信息获取结构体
typedef struct tag_SystemApi_Memory_Infomation
{
    int nMemoryUsage;                                                     //当前系统使用率
    __int64u dwMemory_Total;                                             //系统物理内存总大小
    __int64u dwMemory_Free;                                              //系统物理内存剩余大小
    __int64u dwMemory_TotalSwap;                                         //交换分区总大小
    __int64u dwMemory_FreeSwap;                                          //交换分区剩余大小
    __int64u dwMemory_Share;                                             //共享内存大小 WINDOWS无效
    __int64u dwMemory_TotalVirtual;                                      //虚拟内存总数 Linux无效
    __int64u dwMemory_FreeVirtual;                                       //虚拟内存剩余大小 Linux无效
}SYSTEMAPI_MEMORY_INFOMATION,*LPSYSTEMAPI_MEMORY_INFOMATION;
//进程信息
typedef struct tag_SystemApi_Process_Infomation
{
    int nPid;                                                             //进程ID
    int nThreadCount;                                                     //进程拥有的线程数量
    CHAR tszAppName[MAX_PATH];                                            //进程名
    CHAR tszAppUser[MAX_PATH];                                            //进程所属用户
    ENUM_SYSTEMSDK_PROCFILE_PROCFILE_PROCESSSTATE en_ProcessState;        //程序状态
    struct                                                                //内存信息
    {
        int nUseVirtualMemory;                                            //使用的虚拟内存大小
        int nUsePhysicalMemory;                                           //使用的物理内存大小
        int nUseSharePage;                                                //使用的共享内存
    }st_MemoryInfo;
}SYSTEMAPI_PROCESS_INFOMATION,*LPSYSTEMAPI_PROCESS_INFOMATION;
/************************************************************************/
/*           硬件SDK导出定义                                            */
/************************************************************************/
//获取磁盘状态信息
typedef struct tag_SystemApi_Disk_Information
{
    ENUM_SYSTEMAPI_HARDWARE_DISKTYPE en_DiskType;                         //磁盘类型
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE en_FileSystemType;             //文件系统类型
    __int64u dwDiskTotal;                                                //磁盘总大小
    __int64u dwDiskFree;                                                 //磁盘剩余大小
    DWORD dwDiskPermissions[4];                                           //磁盘权限标记,WINDOWS无效
}SYSTEMAPI_DISK_INFOMATION,*LPSYSTEMAPI_DISK_INFOMATION;
//CPU信息
typedef struct tag_SystemApi_Cpu_Information
{
    CHAR tszCpuName[128];                                                 //CPU名称
    CHAR tszCpuVendor[64];                                                //CPU供应商
    int nCpuCacheL1;                                                      //CPUL1缓存大小 KB
    int nCpuSpeed;                                                        //CPU最大速度，MHZ
    int nCpuNumber;                                                       //CPU核心数
}SYSTEMAPI_CPU_INFOMATION,*LPNETENGINE_SDK_CPUINFOMATION;
//序列号信息,如果不支持的序列号获取，BUFF会被填充为NOTSUPPORT
typedef struct tag_SystemApi_SdkSerial_Information
{
    CHAR tszCpuSerial[64];                                               //CPU序列号
    CHAR tszBoardSerial[64];                                             //主板ID,linux传递vm 表示当前在虚拟机，rl表示真实机器,否则不起作用
    CHAR tszDiskSerial[64];                                              //系统所在硬盘的序列号,获取硬盘序列号，/dev/sda
    CHAR tszSystemSerail[64];                                            //系统序列号
}SYSTEMAPI_SERIAL_INFOMATION, *LPSYSTEMAPI_SERIAL_INFOMATION;
/************************************************************************/
/*            SkinInterfaceSdk类所需要的结构体                          */
/************************************************************************/
//窗口被遮罩的角度
typedef struct tag_WinSdk_Skin_WindowMask
{
	BOOL bLeftTop;                                                        //左上角
	BOOL bLeftBottom;                                                     //左下角
	BOOL bRightTop;                                                       //右上角
	BOOL bRightBottom;                                                    //右下角
}WINSDK_SKIN_WINDOWMASK, * LPWINSDK_SKIN_WINDOWMASK;
/************************************************************************/
/*                      SPI协议枚举导出数据结构                            */
/************************************************************************/
//通过枚举SPI得到的SPI协议信息
#ifdef _MSC_BUILD
typedef struct 
{
	DWORD dwServiceFlags1;
	DWORD dwServiceFlags2;
	DWORD dwServiceFlags3;
	DWORD dwServiceFlags4;
	DWORD dwProviderFlags;
	GUID ProviderId;
	DWORD dwCatalogEntryId;
	typedef struct
	{
		int ChainLen;
		DWORD ChainEntries[7];
	} WSAPROTOCOLCHAIN;
	int iVersion;
	int iAddressFamily;
	int iMaxSockAddr;
	int iMinSockAddr;
	int iSocketType;
	int iProtocol;
	int iProtocolMaxOffset;
	int iNetworkByteOrder;
	int iSecurityScheme;
	DWORD dwMessageSize;
	DWORD dwProviderReserved;
	WCHAR  szProtocol[256];
}SYSTEMAPI_SOCKETSPI_PROTOCOL, * LPSYSTEMAPI_SOCKETSPI_PROTOCOL;
#endif
//////////////////////////////////////////////////////////////////////////
//                        导出函数定义机器s
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD SystemApi_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*            文件管理导出的函数                                           */
/************************************************************************/
/********************************************************************
函数名称：SystemApi_File_IsDirExist
函数功能：文件夹是否存在
 参数.一：lpszPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：文件夹路径
返回值
  类型：逻辑型
  意思：返回真表示在，否则返回假并且重置错误码
备注：
*********************************************************************/
extern "C" BOOL SystemApi_File_IsDirExist(LPCSTR lpszPath);
/********************************************************************
函数名称：SystemApi_File_SaveBuffToFile
函数功能：把缓冲区的内容保存为文件
参数.一：lpszFilePath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：保存文件路径
参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要保存的文件夹
参数.三：lpszBuff
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：缓冲区
参数.四：nBuffferLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区长度
返回值
  类型：逻辑型
  意思：是否保存成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_File_SaveBuffToFile(LPCSTR lpszFilePath,LPCSTR lpszFileName,LPCSTR lpszBuff,int nBuffferLen);
/********************************************************************
函数名称：SystemApi_File_EnumFile
函数功能：枚举文件
 参数.一：lpszPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要枚举的文件目录
 参数.二：pppszListDir
  In/Out：Out
  类型：三级指针
  可空：Y
  意思：导出获取到的文件目录列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出文件列表个数
 参数.四：fpCall_FileEnum
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：枚举到文件的返回内容
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：用户数据，自定义上层处理参数
 参数.六：bRecursion
  In/Out：In/Out
  类型：逻辑型
  可空：Y
  意思：是否枚举子目录，默认为真
 参数.七：nFindType
  In/Out：In
  类型：整数型
  可空：Y
  意思：查找的类型,1文件,2文件夹,3包含两者
返回值
  类型：逻辑型
  意思：是否枚举成功
备注：参数二必须调用基础库的内存释放函数进行内存释放
*********************************************************************/
extern "C" BOOL SystemApi_File_EnumFile(LPCSTR lpszPath, CHAR * **pppszListDir = NULL, int* pInt_ListCount = NULL, CALLBACK_XENGINE_SDK_SYSTEMAPI_FILE_ENUM fpCall_FileEnum = NULL, LPVOID lParam = NULL, BOOL bRecursion = TRUE, int nFindType = 3);
/********************************************************************
函数名称：SystemApi_File_CreateMutilFolder
函数功能：创建多级目录
 参数.一：lpszFolder
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：要创建的目录
 参数.二：dwFloder
   In/Out：In
   类型：双字
   可空：Y
   意思：要创建的目录的权限，如果指定0.那么表示任何权限的人都可以访问 读取 写入 执行
返回值
   类型：逻辑型
   意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_File_CreateMutilFolder(LPCSTR lpszFolder,DWORD dwFloder = 0);
/********************************************************************
函数名称：SystemApi_File_DeleteMutilFolder
函数功能：删除多级目录
 参数.一：lpszFolder
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的目录
 参数.二：bDelMain
  In/Out：In
  类型：逻辑型
  可空：N
  意思：为真表示删除主目录文件,假将保留主目录文件夹
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_File_DeleteMutilFolder(LPCSTR lpszFolder,BOOL bDelMain = TRUE);
/********************************************************************
函数名称：SystemApi_File_CreateSparseFile
函数功能：创建一个稀疏文件
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建的文件所保存的路径
 参数.二：nFileSize
  In/Out：In
  类型：64位整数型
  可空：N
  意思：要创建的大小,单位:字节
返回值
  类型：逻辑型
  意思：是否成功
备注：创建成功后像普通文件操作即可
*********************************************************************/
extern "C" BOOL SystemApi_File_CreateSparseFile(LPCSTR lpszFile, __int64x nFileSize);
/********************************************************************
函数名称：BaseLib_OperatorFile_CopyFile
函数功能：拷贝文件
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要拷贝的原始文件
 参数.二：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：拷贝到的文件位置
 参数.三：bExistFail
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：目标存在是否返回错误
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_File_CopyFile(LPCSTR lpszSrcFile, LPCSTR lpszDstFile, BOOL bExistFail = TRUE);
/************************************************************************/
/*            硬件导出函数                                                */
/************************************************************************/
/************************************************************************
函数名称：SystemApi_HardWare_GetDiskInfomation
函数功能：获取磁盘信息
  参数一：lpszPath
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：要获取的磁盘目标路径
  参数二：pSt_DiskInfo
   In/Out：Out
   类型：结构体指针
   可空：N
   意思：获取到的磁盘信息结构体
  参数三：nTypeSize
   In/Out：In
   类型：整数型
   可空：Y
   意思：导出的磁盘大小表示的单位
返回值
  类型：逻辑型pSt_DiskInfo
  意思：是否获取成功
备注：
************************************************************************/
extern "C" BOOL SystemApi_HardWare_GetDiskInfomation(LPCSTR lpszPath,SYSTEMAPI_DISK_INFOMATION *pSt_DiskInfo,int nTypeSize = XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_B);
/********************************************************************
函数名称：SystemApi_HardWare_GetDiskNumber
函数功能：获取磁盘个数
 参数.一：ppptszRootName
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出磁盘名称列表
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出列表个数
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_HardWare_GetDiskNumber(CHAR * **ppptszRootName, int* pInt_ListCount);
/********************************************************************
函数名称：SystemApi_HardWare_GetCpuInfomation
函数功能：获取CPU信息
 参数.一：pSt_CpuInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的CPU信息
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_HardWare_GetCpuInfomation(SYSTEMAPI_CPU_INFOMATION *pSt_CpuInfo);
/********************************************************************
函数名称：SystemApi_HardWare_GetSerial
函数功能：获取硬件序列号
 参数.一：pSt_SDKSerial
  In/Out：Out
  类型：结构体指针
  可空：N
  意思：导出获取到的硬件序列号
返回值
  类型：逻辑型
  意思：是否获取成功
备注：调用此函数需要管理员权限
*********************************************************************/
extern "C" BOOL SystemApi_HardWare_GetSerial(SYSTEMAPI_SERIAL_INFOMATION *pSt_SDKSerial);
/************************************************************************/
/*                        LINUXSDK进程函数导出                            */
/************************************************************************/
/************************************************************************
函数名称：SystemApi_Process_ReadCmdReturn
函数功能：读取进程CMD命令管道返回的内容
参数.一：lpszCmd
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行CMD命令
 参数.二：ptszOutBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出的内容
 参数.三：nCountLine
  In/Out：In
  类型：整数型
  可空：Y
  意思：要读取几行,0表示全部读取
 参数.四：nReadLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：从第几行开始读取
 参数.五：pInt_Len
  类型：整数型指针
  可空：Y
  意思：输出读取到的返回内容大小，可以为NULL，不获取
返回值
  类型：逻辑性
  意思：是否执行成功
备注：
*************************************************************************/
extern "C" BOOL SystemApi_Process_ReadCmdReturn(LPCSTR lpszCmd, CHAR* ptszMsgBuffer, int nCountLine = 0, int nReadLen = 0, int* pInt_Len = NULL);
/********************************************************************
函数名称：SystemApi_Process_GetProcessInfo
函数功能：获取进程信息
 参数.一：pSt_ProcessInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的信息
 参数.二：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要获取的进程名
 参数.三：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要获取的PID
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_GetProcessInfo(SYSTEMAPI_PROCESS_INFOMATION * pSt_ProcessInfo, LPCSTR lpszProcessName = NULL, int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_GetProcessCpuUsage
函数功能：获取进程CPU占用率
 参数.一：pInt_Usage
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的CPU占用率
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要获取的进程ID号,默认自己
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数会阻塞进程运行1秒
*********************************************************************/
extern "C" BOOL SystemApi_Process_GetProcessCpuUsage(int *pInt_Usage,int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_GetUpTime
函数功能：获取进程启动时间
 参数.一：pSt_SysTime
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的进程启动时间
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要获取哪个进程的信息，默认为自身
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_GetUpTime(LPXENGINE_LIBTIMER pSt_SysTime,int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_GetPriority
函数功能：获取进程或者线程的优先级
 参数.一：pInt_Priority
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的优先级
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要获取的PID，如果为0，将获取自身的优先级
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_GetPriority(int *pInt_Priority,int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_SetPriority
函数功能：获取进程或者线程的优先级
 参数.一：pInt_Priority
  In/Out：In
  类型：整数型
  可空：N
  意思：要设置的优先级，-20 - 20 范围
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要设置的PID，如果为0，将设置自身的优先级
返回值
  类型：逻辑型
  意思：是否设置成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_SetPriority(int nPriority,int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_Stop
函数功能：结束一个指定的进程
 参数.一：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要结束的进程名称
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要结束的进程ID
 参数.三：bIgnSign
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否忽略信号，如果不忽略你需要自己处理子进程信号，不然会造成僵尸进程
返回值
  类型：逻辑型
  意思：是否成功
备注：只需要使用一个参数即可
*********************************************************************/
extern "C" BOOL SystemApi_Process_Stop(LPCSTR lpszProcessName = NULL,int nPid = 0,BOOL bIgnSign = TRUE);
/********************************************************************
函数名称：SystemApi_Process_CreateProcess
函数功能：创建一个指定的进程
 参数.一：pdwProcessId
  In/Out：Out
  类型：双字
  可空：N
  意思：输出创建成功的进程ID
 参数.二：lpszFilePath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建的进程的路径
 参数.三：lpszFileArg
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要创建进程的参数，使用空格分割
 参数.四：bShowWindows
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：进程窗口是显示还是隐藏,默认显示
返回值
  类型：逻辑型
  意思：是否成功
备注：创建后，这个进程将被当做此程序的子进程运行，这个函数不会阻塞你的主程序
      注意:LINUX下创建的进程执行结束进程也会一直存在,除非调用waitpid函数.
*********************************************************************/
extern "C" BOOL SystemApi_Process_CreateProcess(DWORD * pdwProcessId, LPCSTR lpszFileName, LPCSTR lpszFileArg = NULL, BOOL bShowWindows = TRUE);
/********************************************************************
函数名称：SystemApi_Process_RunProcess
函数功能：执行一个指定的进程
 参数.一：pdwProcessId
  In/Out：Out
  类型：双字
  可空：N
  意思：输出执行成功的进程ID
 参数.二：lpszFilePath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建的进程的路径+文件名+参数
 参数.三：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：文件全名称
 参数.四：lpszFileArg
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建进程的参数
 参数.五：bShowWindows
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：进程窗口是显示还是隐藏,默认显示
返回值
  类型：逻辑型
  意思：是否成功
备注：创建后，这个进程将被当做此程序的子进程运行，并且你的线程将被阻塞直到进程退出
*********************************************************************/
extern "C" BOOL SystemApi_Process_RunProcess(DWORD* pdwProcessId, LPCSTR lpszFilePath, LPCSTR lpszFileName, LPCSTR lpszFileArg = NULL, BOOL bShowWindows = TRUE);
/********************************************************************
函数名称：SystemApi_Process_SetProcessForCpu
函数功能：设置进程可运行的CPU
 参数.一：nPid
  In/Out：In
  类型：整数型
  可空：N
  意思：进程ID
 参数.二：dwCpuMask
  In/Out：In
  类型：双字
  可空：N
  意思：要设置进程运行的CPU,以二进制模式配置,二进制的1 表示第一个CPU,二进制的10表示第二个CPU
        二进制11表示进程可使用1和2CPU
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_SetProcessForCpu(int nPid,DWORD dwCpuMask);
/********************************************************************
函数名称：SystemApi_Process_GetProcessForCpu
函数功能：获取进程运行的CPU
 参数.一：nPid
  In/Out：In
  类型：整数型
  可空：N
  意思：进程ID
 参数.二：pdwCpuMask
  In/Out：Out
  类型：双字指针
  可空：N
  意思：进程相关CPU,二进制位操作,意识和设置一样
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_GetProcessForCpu(int nPid,DWORD *pdwCpuMask);
/********************************************************************
函数名称：SystemApi_Process_AutoStart
函数功能：注册自动启动与服务函数
 参数.一：lpszDesName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：注册服务的时候用到的描述说明
        WINDOWS:添加启动项的识别名称，可空
 参数.二：lpszProcessName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要注册启动项目的全路径
        WINDOWS:要添加到启动项的应用程序路径和参数，为空获取自身
 参数.三：bIsAuto
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否让其自动启动，默认为真，自动启动
 参数.四：bIsService
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否注册为服务，注册为服务后不需要在前台启动，会自动给你挂载到后台。默认为假
        此参数LINUX才有效
返回值
  类型：逻辑型
  意思：是否注册成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Process_AutoStart(LPCSTR lpszDesName, LPCSTR lpszProcessName, BOOL bIsAuto = TRUE, BOOL bIsService = FALSE);                                     
/************************************************************************/
/*                        LINUXSDK系统函数导出                            */
/************************************************************************/
/********************************************************************
函数名称：SystemApi_System_GetSystemVer
函数功能：获取系统版本和名称
 参数.一：ptszOSName
  In/Out：Out
  类型：字符指针
  可空：N
  意思：获取系统发行名称
 参数.二：pInt_OSVersion
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：获取发行版本号
 参数.三：pInt_Build
  In/Out：Out
  类型：双字指针
  可空：N
  意思：获取系统构建类型
 参数.四：pInt_Processor
  In/Out：Out
  类型：双字指针
  可空：N
  意思：获取系统平台架构
 参数.五：ptszKernelVer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：获取内核版本号
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_System_GetSystemVer(CHAR *ptszOSName, DWORD * pInt_OSVersion,DWORD *pInt_Build,DWORD *pInt_Processor,CHAR *ptszKernelVer = NULL);
/********************************************************************
函数名称：SystemApi_System_GetMemoryUsage
函数功能：获取系统内存使用率
 参数.一：pSt_MemoryInfo
  In/Out：Out
  类型：结构体指针
  可空：N
  意思：系统使用的内存结构体
 参数.二：nTypeSize
  In/Out：In
  类型：整数型
  可空：N
  意思：要获取的类型，空表示MB
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_System_GetMemoryUsage(SYSTEMAPI_MEMORY_INFOMATION *pSt_MemoryInfo,int nTypeSize = XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_KB);
/********************************************************************
函数名称：SystemApi_System_GetCpuUsage
函数功能：获取当前CPU使用率
 参数.一：pInt_CpuUSage
  In/Out：Out
  类型：整数型
  可空：N
  意思：返回当前CPU使用率
返回值
  类型：逻辑型
  意思：是否成功
备注：获取的是每秒CPU使用率,此函数会让线程阻塞
*********************************************************************/
extern "C" BOOL SystemApi_System_GetCpuUsage(int *pInt_CpuUSage);
/************************************************************************
函数名称：SystemApi_System_GetCpuCount
函数功能：获取CPU个数
  参数一：pInt_CpuCount
   In/Out：Out
   类型：指向整数的指针
   可空：N
   意思：输出当前机器CPU个数
返回值
  类型：逻辑型
  意思：是否成功获取得到
备注：
************************************************************************/
extern "C" BOOL SystemApi_System_GetCpuCount(int *pInt_CpuCount);
/************************************************************************
函数名称：SystemApi_System_GetUpTime
函数功能：获取系统启动时间
  参数一：pSt_SysTime
   In/Out：Out
   类型：数据结构指针
   可空：N
   意思：输出系统启动时间
返回值
  类型：逻辑型
  意思：是否成功获取得到
备注：
************************************************************************/
extern "C" BOOL SystemApi_System_GetUpTime(LPXENGINE_LIBTIMER pSt_SysTime);
/************************************************************************
函数名称：SystemApi_System_GetProcessCount
函数功能：获取当前系统进程个数
  参数一：pInt_ProcessCount
   In/Out：Out
   类型：整数型指针
   可空：N
   意思：输出获取到的系统进程个数
返回值
  类型：逻辑型
  意思：是否成功获取得到
备注：
************************************************************************/
extern "C" BOOL SystemApi_System_GetProcessCount(int *pInt_ProcessCount);
/************************************************************************
函数名称：SystemApi_System_Shutdown
函数功能：关闭系统或者重启操作
  参数一：dwBootType
   In/Out：In
   类型：双字
   可空：Y
   意思：要重启还是关机
返回值
  类型：逻辑型
  意思：是否成功执行
备注：
************************************************************************/
extern "C" BOOL SystemApi_System_Shutdown(DWORD dwBootType);
/********************************************************************
函数名称：SystemApi_System_SystemEx
函数功能：SYSTEM扩展函数,执行一条带超时的命令
 参数.一：lpszSystemCmd
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的命令
 参数.二：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,-1不超时,单位:秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_System_SystemEx(LPCSTR lpszSystemCmd, int nTimeout = -1);
/************************************************************************
函数名称：SystemApi_System_SDRemoteMachine
函数功能：远程关闭机器
  参数一：lpszMachineName
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：远程机器名称
  参数二：lpszUser
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：远程用户名
  参数三：lpszPwd
   In/Out：In
   类型：常量字符指针
   可空：N
   意思：密码
  参数四：lpszMsg
   In/Out：In
   类型：常量字符指针
   可空：Y
   意思：要显示的消息
  参数五：dwTimeOut
   In/Out：In
   类型：双字
   可空：Y
   意思：显示消息时间
  参数六：dwReason
   In/Out：In
   类型：双字
   可空：Y
   意思：关闭的原因
返回值
  类型：逻辑型
  意思：是否成功执行
备注：最后三个参数可以省略，lpMsg和dwTimeOut 有关联性，他们两个其中一个使用另一个
      也必定使用，传递他们的作用是让用户选择可以取消关机操作
************************************************************************/
extern "C" BOOL SystemApi_System_SDRemoteMachine(LPCSTR lpszMachineName, LPCSTR lpszUser, LPCSTR lpszpwd, LPCSTR lpszMsg = NULL, DWORD dwTimeOut = 0);
/************************************************************************
函数名称：GetSystemStartInfo
函数功能：获取系统开机的类型
返回值
  类型：DWORD
  意思：返回系统启动类型
备注：
************************************************************************/
extern "C" DWORD SystemApi_System_GetSystemStartInfo();
/************************************************************************
函数名称：SystemApi_System_IsRemoteContral
函数功能：判断当前系统是否正在远程控制状态下
返回值
  类型：逻辑型
  意思：如果返回真表示在，返回假表示不是
备注：
************************************************************************/
extern "C" BOOL SystemApi_System_IsRemoteContral();
/************************************************************************
函数名称：SystemApi_System_GetSysIdleTime
函数功能：获取系统空闲时间
  参数一：dwTime
   In/Out：Out
   类型：双字节型
   可空：N
   意思：系统的空闲时间
返回值
  类型：逻辑型
  意思：是否获取成功，失败返回假
备注：
************************************************************************/
extern "C" BOOL SystemApi_System_GetSysIdleTime(DWORD & dwTime);
/************************************************************************/
/*                        界面函数导出                                  */
/************************************************************************/
#ifdef _MSC_BUILD
/********************************************************************
函数名称：SystemApi_Skin_SethWndAdsorpti
函数功能：设置窗口吸附
 参数.一：hAdWnd
  In/Out：In
  类型：窗口句柄
  可空：N
  意思：要吸附的窗口句柄
 参数.二：hSelfWnd
  In/Out：In
  类型：窗口句柄
  可空：N
  意思：吸附的窗口句柄
 参数.三：dwPos
  In/Out：In
  类型：双字
  可空：Y
  意思：要吸附窗口的位置，默认自动
 参数.四：dwType
  In/Out：In
  类型：双字
  可空：Y
  意思：显示的样式，默认普通样式
返回值
  类型：逻辑型
  意思：是否成功设置吸附
备注：设置成功后，窗口会自动处理吸附关系
*********************************************************************/
extern "C" BOOL SystemApi_Skin_SethWndAdsorpti(HWND hAdWnd, HWND hSelfWnd, DWORD dwPos = XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_AUTO, DWORD dwType = XENGINE_SYSTEMSDK_API_SKIN_ADSORPTI_NORMAL);
/********************************************************************
函数名称：SystemApi_Skin_WindowDithering
函数功能：窗口抖动函数
 参数.一：hWnd
  In/Out：In
  类型：窗口句柄
  可空：N
  意思：要设置的窗口
 参数.二：nDitheringDegree
  In/Out：In
  类型：整数型
  可空：Y
  意思：抖动次数，默认4此
 参数.三：nDitheringCareer
  In/Out：In
  类型：整数型
  可空：Y
  意思：抖动间隔，默认30毫秒
返回值
  类型：逻辑型
  意思：是否成功抖动
备注：仿造QQ抖动，支持抖动后播放声音或者不播放，不播放传递NULL
*********************************************************************/
extern "C" BOOL SystemApi_Skin_WindowDithering(HWND hWnd, int nDitheringDegree = 4, int nDitheringCareer = 30);
/********************************************************************
函数名称：SystemApi_Skin_IsFullWindow
函数功能：是否有全频运行的窗口
返回值
  类型：逻辑型
  意思：返回真表示有，返回假表示没有
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Skin_IsFullWindow();
/********************************************************************
函数名称：SystemApi_Skin_CreateTooltip
函数功能：为控件句柄添加提示
 参数.一：hWnd
  In/Out：In
  类型：句柄
  可空：N
  意思：控件的句柄
 参数.二：lpszContextOfTip
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：是否添加成功
返回值
  类型：逻辑型
  意思：是否成功添加
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Skin_CreateTooltip(HWND hWnd, LPCSTR lpszContextOfTip);
/********************************************************************
函数名称：SystemApi_Skin_CreateTrayTip
函数功能：创建托盘图标提示信息
 参数.一：hWnd
  In/Out：In
  类型：句柄
  可空：N
  意思：要创建的主窗口句柄，MFC:m_hWnd可以得到
 参数.二：lpszContextTitle
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：托盘提示标题
 参数.三：CallBack_FPTrayMsg
  In/Out：In
  类型：长整形
  可空：N
  意思：托盘事件处理程序回调函数，请自己调用处理这个消息
 参数.四：unResID
  In/Out：In
  类型：无符号整数型
  可空：N
  意思：资源图标，托盘图标
 参数.五：IsCreateTray
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是创建还是删除，默认创建
返回值
  类型：逻辑型
  意思：是否创建或者删除成功
备注：如果你要删除的话，最后一个参数传递假即可。回调函数需要你自己处理，这个消息指请在用户开发指导说明书中找到
*********************************************************************/
extern "C" BOOL SystemApi_Skin_CreateTrayTip(HWND hWnd, LPCSTR lpszContextTitle, DWORD CallBack_FPTrayMsg, UINT unResID, BOOL IsCreateTray = TRUE);
/********************************************************************
函数名称：SystemApi_Skin_IshWndMask
函数功能：窗口是否被遮罩
 参数.一：hWnd
  In/Out：In
  类型：句柄
  可空：N
  意思：要检测的窗口的句柄
 参数.二：pSt_hWndMask
  In/Out：Out
  类型：结构体指针
  可空：N
  意思：输出窗口被遮罩的角度
返回值
  类型：逻辑型
  意思：是否检测成功
备注：为了保证获取到正确的信息，第二个参数结构体请全部初始化为FALSE
*********************************************************************/
extern "C" BOOL SystemApi_Skin_IshWndMask(HWND hWnd, LPWINSDK_SKIN_WINDOWMASK pSt_hWndMask);
/********************************************************************
函数名称：SystemApi_Skin_SethWndParent
函数功能：设置一个窗口嵌入到指定窗口中
 参数.一：hWnd
  In/Out：In
  类型：句柄
  可空：N
  意思：父窗口句柄
 参数.二：hChWnd
  In/Out：In
  类型：句柄
  可空：N
  意思：要嵌入到的窗口句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL SystemApi_Skin_SethWndParent(HWND hWnd, HWND hChWnd);
/************************************************************************
函数名称：SystemApi_Skin_ExithWndParent
函数功能：还原嵌入窗口操作
 参数.一：hWnd
  In/Out：In
  类型：句柄
  可空：N
  意思：要退出的窗口句柄
返回值
  类型：无
  意思：
备注：
************************************************************************/
extern "C" void SystemApi_Skin_ExithWndParent(HWND hWnd);
/********************************************************************
函数名称：SystemApi_Skin_SaveScreenShotsToFile
函数功能：屏幕区域截图
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：把图片保存到哪儿
 参数.二：nScreenX
  In/Out：In
  类型：整数型
  可空：N
  意思：截图坐标X
 参数.三：nScreenY
  In/Out：In
  类型：整数型
  可空：N
  意思：截图坐标Y
返回值
  类型：逻辑型
  意思：是否截取成功
备注：如果后面两个参数传递0 那么就表示全屏截图。如果传递-1表示鼠标所在窗口截图
*********************************************************************/
extern "C" BOOL SystemApi_Skin_SaveScreenShotsToFile(LPCSTR lpszFileName, int nScreenX = 0, int nScreenY = 0);
/************************************************************************/
/*                     SPI导出函数定义                                  */
/************************************************************************/
/********************************************************************
函数名称：SystemApi_SPISocket_Install
函数功能：安装LSP模块
 参数.一：lpszPathName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：LSP模块路径地址
 参数.二：lpszProtoName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要被安装的LSP协议名称,这个参数作为后续操作参数
返回值
  类型：逻辑型
  意思：是否成功安装
备注：
*********************************************************************/
extern "C" BOOL SystemApi_SPISocket_Install(LPCSTR lpszPathName, LPCSTR lpszProtoName);
/********************************************************************
函数名称：SystemApi_SPISocket_Delete
函数功能：删除一个关联的SPI协议层
 参数.一：lpszProtoName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要移除的指定协议层名称
返回值
  类型：逻辑型
  意思：是否成功移除
备注：
*********************************************************************/
extern "C" BOOL SystemApi_SPISocket_Delete(LPCSTR lpszProtoName);
/********************************************************************
函数名称：SystemApi_SPISocket_WSCGetProtocols
函数功能：枚举协议 它能够枚举各种协议，包括分层协议，基础协议和协议链。
 参数.一：pSt_SocketSpiProtocols
  In/Out：Out
  类型：结构体指针
  可空：N
  意思：需要足够大的缓冲区来存放导出的协议链信息
 参数.二：pnProtocols
  In/Out： In/Out
  类型：整数型指针
  可空：Y
  意思：如果不为NULL,这个函数只会导出拥有的协议链个数
返回值
  类型：逻辑型
  意思：是否获取成功
备注：一般的，请你先获取有多少个协议链，在传递第二次调用此函数获取有协议链信息
*********************************************************************/
extern "C" BOOL SystemApi_SPISocket_WSCGetProtocols(LPSYSTEMAPI_SOCKETSPI_PROTOCOL pSt_SocketSpiProtocols, int* pnProtocols = NULL);
#endif
