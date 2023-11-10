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
#if __MACOS__ || __IOS__
typedef pthread_t XPTHREAD;
#else
typedef int XPTHREAD;
#endif
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
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_EXT4 = 4,                      //EXT4文件系统
    ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE_APFS = 5                       //macos的文件系统
}ENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE,*LPENUM_SYSTEMAPI_HARDWARE_FILESYSTEMTYPE;
//进程状态
typedef enum 
{
	ENUM_SYSTEMAPI_PROCESS_STATUS_RUNNING = 0,                            //运行中
	ENUM_SYSTEMAPI_PROCESS_STATUS_SLEEP,                                  //睡眠中
	ENUM_SYSTEMAPI_PROCESS_STATUS_DISKSLEEP,                              //磁盘休眠中
	ENUM_SYSTEMAPI_PROCESS_STATUS_ZOMBIE,                                 //僵尸进程
	ENUM_SYSTEMAPI_PROCESS_STATUS_TRACESTOP,                              //跟踪暂停
	ENUM_SYSTEMAPI_PROCESS_STATUS_PAGING,                                 //分页中
	ENUM_SYSTEMAPI_PROCESS_STATUS_UNKNOW                                  //未知状态
}ENUM_SYSTEMAPI_PROCESS_STATUS, * LPENUM_SYSTEMAPI_PROCESS_STATUS;
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
//////////////////////////////////////////////////////////////////////////
//                        导出数据结构定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      文件路径SDK数据结构                             */
/************************************************************************/
typedef struct tag_SystemApi_File_Infomation
{
    bool bIsFile;                                                         //文件还是路径,真为文件
    XCHAR tszFileDir[MAX_PATH];                                           //文件或者路径名
}SYSTEMAPI_FILE_INFOMATION, *LPSYSTEMAPI_FILE_INFOMATION;
//内存信息获取结构体
typedef struct tag_SystemApi_Memory_Infomation
{
    int nMemoryUsage;                                                    //当前系统使用率
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
    XCHAR tszAppName[MAX_PATH];                                           //进程名
    XCHAR tszAppUser[MAX_PATH];                                           //进程所属用户
    ENUM_SYSTEMAPI_PROCESS_STATUS en_ProcessState;                        //程序状态
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
    XLONG dwDiskPermissions[4];                                           //磁盘权限标记,WINDOWS无效
}SYSTEMAPI_DISK_INFOMATION,*LPSYSTEMAPI_DISK_INFOMATION;
//CPU信息
typedef struct tag_SystemApi_Cpu_Information
{
    XCHAR tszCpuName[128];                                                 //CPU名称
    XCHAR tszCpuVendor[64];                                                //CPU供应商
    int nCpuCacheL1;                                                      //CPUL1缓存大小 KB
    int nCpuSpeed;                                                        //CPU最大速度，MHZ
    int nCpuNumber;                                                       //CPU核心数
}SYSTEMAPI_CPU_INFOMATION,*LPXENGINE_SDK_CPUINFOMATION;
//序列号信息,如果不支持的序列号获取，BUFF会被填充为NOTSUPPORT
typedef struct tag_SystemApi_SdkSerial_Information
{
    XCHAR tszCpuSerial[64];                                               //CPU序列号
    XCHAR tszBoardSerial[64];                                             //主板ID,linux传递vm 表示当前在虚拟机，rl表示真实机器,否则不起作用
    XCHAR tszDiskSerial[64];                                              //系统所在硬盘的序列号,获取硬盘序列号，/dev/sda
    XCHAR tszSystemSerail[64];                                            //系统序列号
}SYSTEMAPI_SERIAL_INFOMATION, *LPSYSTEMAPI_SERIAL_INFOMATION;
//////////////////////////////////////////////////////////////////////////
//                        导出函数定义机器s
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG SystemApi_GetLastError(int *pInt_SysError = NULL);
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
extern "C" bool SystemApi_File_IsDirExist(LPCXSTR lpszPath);
/********************************************************************
函数名称：SystemApi_File_SaveBuffToFile
函数功能：把缓冲区的内容保存为文件
参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：保存文件路径
参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：缓冲区
参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：缓冲区长度
返回值
  类型：逻辑型
  意思：是否保存成功
备注：
*********************************************************************/
extern "C" bool SystemApi_File_SaveBuffToFile(LPCXSTR lpszFileName, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：SystemApi_File_EnumFile
函数功能：枚举文件
 参数.一：lpszPath
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要枚举的文件目录,末尾必须添加通配符 比如d:\\*.dll 或者直接全部 *
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
 参数.四：bRecursion
  In/Out：In/Out
  类型：逻辑型
  可空：Y
  意思：是否枚举子目录，默认为真
 参数.五：nFindType
  In/Out：In
  类型：整数型
  可空：Y
  意思：查找的类型,1文件,2文件夹,3包含两者
返回值
  类型：逻辑型
  意思：是否枚举成功
备注：参数二必须调用基础库的内存释放函数进行内存释放
*********************************************************************/
extern "C" bool SystemApi_File_EnumFile(LPCXSTR lpszPath, XCHAR * **pppszListDir = NULL, int* pInt_ListCount = NULL, bool bRecursion = true, int nFindType = 3);
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
extern "C" bool SystemApi_File_CreateMutilFolder(LPCXSTR lpszFolder,XLONG dwFloder = 0);
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
extern "C" bool SystemApi_File_DeleteMutilFolder(LPCXSTR lpszFolder,bool bDelMain = true);
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
extern "C" bool SystemApi_File_CreateSparseFile(LPCXSTR lpszFile, __int64x nFileSize);
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
extern "C" bool SystemApi_File_CopyFile(LPCXSTR lpszSrcFile, LPCXSTR lpszDstFile, bool bExistFail = true);
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
  类型：逻辑型
  意思：是否获取成功
备注：
************************************************************************/
extern "C" bool SystemApi_HardWare_GetDiskInfomation(LPCXSTR lpszPath,SYSTEMAPI_DISK_INFOMATION *pSt_DiskInfo,int nTypeSize = XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_B);
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
extern "C" bool SystemApi_HardWare_GetDiskNumber(XCHAR * **ppptszRootName, int* pInt_ListCount);
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
extern "C" bool SystemApi_HardWare_GetCpuInfomation(SYSTEMAPI_CPU_INFOMATION *pSt_CpuInfo);
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
extern "C" bool SystemApi_HardWare_GetSerial(SYSTEMAPI_SERIAL_INFOMATION *pSt_SDKSerial);
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
extern "C" bool SystemApi_Process_ReadCmdReturn(LPCXSTR lpszCmd, XCHAR* ptszMsgBuffer, int nCountLine = 0, int nReadLen = 0, int* pInt_Len = NULL);
#ifndef __IOS__
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
extern "C" bool SystemApi_Process_GetProcessInfo(SYSTEMAPI_PROCESS_INFOMATION * pSt_ProcessInfo, LPCXSTR lpszProcessName = NULL, int nPid = 0);
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
extern "C" bool SystemApi_Process_GetProcessCpuUsage(int *pInt_Usage,int nPid = 0);
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
extern "C" bool SystemApi_Process_GetUpTime(LPXENGINE_LIBTIMER pSt_SysTime,int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_GetPath
函数功能：获取进程相关路径信息
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获得的路径
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入要获取的进程ID
返回值
  类型：逻辑型
  意思：是否成功
备注：如果想获得进程运行目录,可以通过BaseLib_OperatorString_GetFileAndPath来分割
*********************************************************************/
extern "C" bool SystemApi_Process_GetPath(XCHAR* ptszMsgBuffer, int nPid = 0);
#endif
/********************************************************************
函数名称：SystemApi_Process_IsAdmin
函数功能：是否是管理员权限运行
返回值
  类型：逻辑型
  意思：返回真为管理员,否则不是
备注：
*********************************************************************/
extern "C" bool SystemApi_Process_IsAdmin();
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
extern "C" bool SystemApi_Process_GetPriority(int *pInt_Priority,int nPid = 0);
/********************************************************************
函数名称：SystemApi_Process_SetPriority
函数功能：设置进程或者线程的优先级
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
extern "C" bool SystemApi_Process_SetPriority(int nPriority,int nPid = 0);
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
extern "C" bool SystemApi_Process_Stop(LPCXSTR lpszProcessName = NULL,int nPid = 0,bool bIgnSign = true);
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
extern "C" bool SystemApi_Process_CreateProcess(XLONG * pdwProcessId, LPCXSTR lpszFileName, LPCXSTR lpszFileArg = NULL, bool bShowWindows = true);
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
extern "C" bool SystemApi_Process_RunProcess(XLONG* pdwProcessId, LPCXSTR lpszFilePath, LPCXSTR lpszFileName, LPCXSTR lpszFileArg = NULL, bool bShowWindows = true);
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
        MACOS代表0开始的CPU编号
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool SystemApi_Process_SetProcessForCpu(XPTHREAD nPid,XLONG dwCpuMask);
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
extern "C" bool SystemApi_Process_GetProcessForCpu(XPTHREAD nPid,XLONG *pdwCpuMask);
/************************************************************************/
/*                        LINUXSDK系统函数导出                            */
/************************************************************************/
/********************************************************************
函数名称：SystemApi_System_GetSystemVer
函数功能：获取系统版本和名称
 参数.一：pszOS
  In/Out：Out
  类型：字符指针
  可空：N
  意思：获取系统发行名称
 参数.二：pInt_OSVersion
  In/Out：Out
  类型：字符指针
  可空：N
  意思：获取发行版本号
 参数.三：ptszOSVersion
  In/Out：Out
  类型：字符指针
  可空：N
  意思：获取系统构建类型
 参数.四：ptszOSBuild
  In/Out：Out
  类型：字符指针
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
extern "C" bool SystemApi_System_GetSystemVer(XCHAR * ptszOSName, XCHAR * ptszOSVersion, XCHAR * ptszOSBuild, XLONG * pInt_Processor, XCHAR * ptszKernelVer = NULL);
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
extern "C" bool SystemApi_System_GetMemoryUsage(SYSTEMAPI_MEMORY_INFOMATION *pSt_MemoryInfo,int nTypeSize = XENGINE_SYSTEMSDK_API_SYSTEM_SIZE_KB);
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
extern "C" bool SystemApi_System_GetCpuUsage(int *pInt_CpuUSage);
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
extern "C" bool SystemApi_System_GetCpuCount(int *pInt_CpuCount);
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
extern "C" bool SystemApi_System_GetUpTime(LPXENGINE_LIBTIMER pSt_SysTime);
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
extern "C" bool SystemApi_System_GetProcessCount(int *pInt_ProcessCount);
#ifndef __IOS__
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
extern "C" bool SystemApi_System_Shutdown(XLONG dwBootType);
#endif
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
extern "C" bool SystemApi_System_SystemEx(LPCXSTR lpszSystemCmd, int nTimeout = -1);
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
extern "C" bool SystemApi_System_GetSysIdleTime(XLONG & dwTime);