#pragma once
/********************************************************************
//	     此项目文件基本属性如下
//  Created:	2011/02/26   15:04
// 	FileName: 	/LinuxNetEngine/NetSocketEngine/NetEngine_LinuxApi/NetEngine_ProcSdk/ProcFile_Define.h
//	File Path:	/LinuxNetEngine/NetSocketEngine/NetEngine_LinuxApi/NetEngine_ProcSdk/
//	File Base:	ProcFile_Define
//	File Ext:	h
//	Author:		dowflyon
//  Project:    NetSocketEngine (网络通信引擎)
//	PurPose:	PROC文件系统导出函数
//  History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       导出的数据结构
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                        LINUXSDK进程数据结构                            */
/************************************************************************/
//进程信息结构
typedef struct tag_ProFile_Process_Stat
{
    int nPid;                                                             //PID
    XCHAR tszAppName[MAX_PATH];                                           //应用程序名称
    XCHAR cState;                                                         //运行状态
    int nPPid;                                                            //父进程ID
    int nGPid;                                                            //进程所属组ID
    int nSPid;                                                            //会话ID
    int nTty;                                                             //该任务的tty终端的设备号，INT（34817/256）=主设备号，（34817-主设备号）=次设备号
    int nGTty;                                                            //终端的进程组号，当前运行在该任务所在终端的前台任务(包括shell 应用程序)的PID
    unsigned int unFlag;                                                  //进程标识符 <linux/sched.h> 任务特性
    unsigned long ulMinflt;                                               //该任务不需要从硬盘拷数据而发生的缺页（次缺页）的次数
    unsigned long ulCMinflt;                                              //子进程不需要从硬盘拷贝数据而发生的缺失页
    unsigned long ulMajflt;                                               //该任务需要从硬盘拷数据而发生的缺页（主缺页）的次数
    unsigned long ulCmajflt;                                              //累计的该任务的所有的waited-for进程曾经发生的次缺页的次数目
    unsigned long ulUserTime;                                             //该任务在用户态运行的时间，单位为jiffies
    unsigned long ulSysTime;                                              //该任务在核心态运行的时间，单位为jiffies
    long int lnWaitUserTime;                                              //累计的该任务的所有的waited-for进程曾经在用户态运行的时间，单位为jiffies
    long int lnWaitSysTime;                                               //累计的该任务的所有的waited-for进程曾经在核心态运行的时间，单位为jiffies
    long int lnPriority;                                                  //任务的动态优先级
    long int lnNice;                                                      //任务的静态优先级
    long int lnThreadCount;                                               //线程数量
    long int lnItRealValue;                                               //由于计时间隔导致的下一个 SIGALRM 发送进程的时延，以 jiffy 为单位.
    unsigned long long ullStartTime;                                      //该任务启动的时间，单位为jiffies
    unsigned long ulVirtualMemorySize;                                    //该任务的虚拟地址空间大小
    long int lnRss;                                                       //该任务当前驻留物理地址空间的大小
    unsigned long ulRsslim;                                               //该任务能驻留物理地址空间的最大值
    unsigned long ulStartCode;                                            //该任务在虚拟地址空间的代码段的起始地址
    unsigned long ulEndCode;                                              //该任务在虚拟地址空间的代码段的结束地址
    unsigned long ulStartStack;                                           //栈的起始地址
    unsigned long ulKstkesp;                                              //(32 位堆栈指针) 的当前值, 与在进程的内核堆栈页得到的一致.
    unsigned long ulKstkeip;                                              //指向将要执行的指令的指针, EIP(32 位指令指针)的当前值.
    unsigned long ulSignal;                                               //待处理信号的位图
    unsigned long ulBlockSignal;                                          //阻塞的信号位图
    unsigned long ulSignaledNore;                                         //忽略的信号位图
    unsigned long ulSignalCatch;                                          //被俘获的信号的位图
    unsigned long ulWChan;                                                //如果该进程是睡眠状态，该值给出调度的调用点
    unsigned long ulNSwap;                                                //被swapped的页数，当前没用
    unsigned long ulCNSwap;                                               //所有子进程被swapped的页数的和，当前没用
    int nExitSignal;                                                      //该进程结束时，向父进程所发送的信号
    int nRunCpuNumber;                                                    //运行在哪个CPU上
    unsigned int unRealTimePriority;                                      //实时进程的相对优先级别
    unsigned int unPolicy;                                                //进程的调度策略，0=非实时进程，1=FIFO实时进程；2=RR实时进程
    unsigned long long ullIODelays;                                       //聚合块I / O延迟，以时钟周期为单位测量
    unsigned long ulGuestTime;                                            //GUEST账户的进程，虚拟进程CPU时间
    long int lnGuestChildTime;                                            //子进程时间向量
}PROCFILE_PROCESS_STATUS,*LPPROCFILE_PROCESS_STATUS;
//进程内存信息结构
typedef struct tag_ProFile_Process_Memory
{
    int nUseVirtualMemory;                                                //虚拟内存                     VmSize/4
    int nUsePhysicalMemory;                                               //物理内存                     VmRSS/4
    int nUseSharePage;                                                    //共享内存
    int nExecVirMemory;                                                   //程序所拥有的可执行虚拟内存的大小 VmExe/4
    int nMapVirMemory;                                                    //被映像到任务的虚拟内存空间的库的大小  VmLib/4
    int nDataStack;                                                       //程序数据段和用户态的栈的大小    （VmData+ VmStk ）4
    int nDirtyPage;                                                       //损坏的页数
}PROCFILE_PROCESS_MEMORY,*LPPROCFILE_PROCESS_MEMORY;
//网络状态信息
typedef struct tag_ProcFile_Process_NetDev
{
    XCHAR tszNetDev[10];

    unsigned long ulRecvBytes;                                            //接受到的字节
    unsigned long ulRecvPacket;                                           //接受到的包数量
    unsigned long ulRecvError;                                            //接受错误的数量
    unsigned long ulRecvDrop;
    unsigned long ulRecvFifo;
    unsigned long ulRecvFrame;
    unsigned long ulRecvCompress;
    unsigned long ulRecvMastCast;

    unsigned long ulSendBytes;
    unsigned long ulSendPacket;
    unsigned long ulSendError;
    unsigned long ulSendFifo;                                             //
    unsigned long ulSendDrop;                                             //
    unsigned long ulSendColls;                                            //
    unsigned long ulSendCerrier;                                          //
    unsigned long ulSendCompress;                                         //压缩的包
}PROCFILE_PROCESS_NETDEV,*LPPROCFILE_PROCESS_NETDEV;
/************************************************************************/
/*                        LINUXSDK系统数据结构                            */
/************************************************************************/
//stat系统CPU信息
typedef struct tag_ProcFile_System_CpuInfo
{
    XCHAR tszCpuName[10];                                                 //CPU名称
    long lUserTime;                                                       //用户时间。从系统启动开始累计到当前时刻，用户态的CPU时间
    long lNiceTime;                                                       //从系统启动开始累计到当前时刻，nice值为负的进程所占用的CPU时间
    long lSystemTime;                                                     //从系统启动开始累计到当前时刻，核心时间
    long lIdleTime;                                                       //从系统启动开始累计到当前时刻，除硬盘IO等待时间以外其它等待时间
    long lIOWaitTime;                                                     //从系统启动开始累计到当前时刻，硬盘IO等待时间
    long lIrqTime;                                                        //从系统启动开始累计到当前时刻，硬中断时间
    long lSoftIrqTime;                                                    //从系统启动开始累计到当前时刻，软中断时间
    long lStealstolenTime;                                                //这是操作系统其他的运行的虚拟进程时间
    long lGuestTime;                                                      //这是客户机操作系统的控制下的Linux内核上运行一个虚拟的CPU所花的时间。
    long lGuestNice;                                                      //运行一个带nice值的guest花费的时间
}PROCFILE_SYSTEM_CPUINFO,*LPPROCFILE_SYSTEM_CPUINFO;
/************************************************************************/
/*                        LINUXSDK 硬件PROC文件系统结构                   */
/************************************************************************/
//盘符结构表
typedef struct tag_ProcFile_HardWare_DiskInfo
{
    int nMajor;                                                           //高位
    int nMinor;                                                           //低位
    __int64u ullDiskSize;                                                  //大小，字节
    XCHAR tszDiskName[MAX_PATH];                                          //名称
}PROCFILE_HARDWARE_DISKINFO,*LPPROCFILE_HARDWARE_DISKINFO;
//CPU信息结构
typedef struct tag_ProcFile_HardWare_CpuInfo
{
    XCHAR tszCPUVendor[MAX_PATH];                                         //CPU供应商
    int nCpuFamily;                                                       //CPU家族
    XCHAR tszCPUName[MAX_PATH];                                           //CPU名称
    XCHAR tszHardCode[MAX_PATH];                                          //硬件码
    int nCpuMhz;                                                          //CPU速度
    int nCpuCache;                                                        //缓存大小
}PROCFILE_HARDWARE_CPUINFO,*LPPROCFILE_HARDWARE_CPUINFO;
//////////////////////////////////////////////////////////////////////////
//                       导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG ProcFile_GetLastError(int *pInt_SysError = NULL);     //获取错误码
/************************************************************************/
/*                        LINUXSDK进程读取函数导出                         */
/************************************************************************/
/********************************************************************
函数名称：ProcFile_Process_ReadStat
函数功能：读取进程的状态信息
 参数.一：pSt_ProcStat
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的数据
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要获取的进程PID，默认为0，表示获取自身
返回值
  类型：逻辑型
  意思：是否发生错误
备注：
*********************************************************************/
extern "C" bool ProcFile_Process_ReadStat(LPPROCFILE_PROCESS_STATUS pSt_ProcStat,int nPid = 0);
/********************************************************************
函数名称：ProcFile_Process_ReadCpu
函数功能：获取进程CPU占用率
 参数.一：pflCpuUsage
  In/Out：Out
  类型：浮点型指针
  可空：N
  意思：导出进程的CPU占用率，一秒钟内占用的CPU
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要获取的进程PID，默认为0，表示自身
返回值
  类型：逻辑型
  意思：是否发生错误
备注：
*********************************************************************/
extern "C" bool ProcFile_Process_ReadCpu(float *pflCpuUsage,int nPid = 0);
/********************************************************************
函数名称：ProcFile_Process_ReadMemory
函数功能：读取进程的内存信息
 参数.一：pSt_ProcStat
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的数据
 参数.二：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要获取的进程PID，默认为0，表示获取自身
返回值
  类型：逻辑型
  意思：是否发生错误
备注：
*********************************************************************/
extern "C" bool ProcFile_Process_ReadMemory(LPPROCFILE_PROCESS_MEMORY pSt_ProcStatm,int nPid = 0);
/********************************************************************
函数名称：ProcFile_Process_ReadNetDev
函数功能：读取进程的网络流量信息
 参数.一：pppSt_ListNet
  In/Out：Out
  类型：指向指针的指针的指针
  可空：N
  意思：导出获取到的数据
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出数据的个数
 参数.三：nPid
  In/Out：In
  类型：整数型
  可空：Y
  意思：要获取的进程PID，默认为0，表示获取自身
 参数.四：bIsBreakError
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否忽略本地网络流量，也就是127.0.0.1 回环流量，默认忽略
返回值
  类型：逻辑型
  意思：是否发生错误
备注：
*********************************************************************/
extern "C" bool ProcFile_Process_ReadNetDev(PROCFILE_PROCESS_NETDEV ***pppSt_ListNet,int *pInt_ListCount,int nPid = 0,bool bIsBreak = true);
/************************************************************************/
/*                        LINUXSDK系统读取函数导出                         */
/************************************************************************/
/********************************************************************
函数名称：ProcFile_System_CPUStat
函数功能：读取系统CPU信息
 参数.一：pSt_SysProcStat
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的数据
返回值
  类型：逻辑型
  意思：是否发生错误
备注：
*********************************************************************/
extern "C" bool ProcFile_System_CPUStat(LPPROCFILE_SYSTEM_CPUINFO pSt_SysProcStat);
/********************************************************************
函数名称：ProcFile_System_NetFlowDev
函数功能：获取指定网卡的网络流量
 参数.一：lpszDevName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要获取的网卡名称(ifconfig)
 参数.二：pInt_RecvFlow
  In/Out：Out
  类型：四字指针
  可空：N
  意思：导出获取到的网卡接受流量大小
 参数.三：pInt_SendFlow
  In/Out：Out
  类型：四字指针
  可空：N
  意思：导出获取到的网卡发送流量大小
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool ProcFile_System_NetFlowDev(LPCXSTR lpszDevName,__int64u *pInt_RecvFlow,__int64u *pInt_SendFlow);
/********************************************************************
函数名称：ProcFile_System_GetTime
函数功能：获取系统启动时间信息
 参数.一：pInt_UPTime
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出系统启动时间,单位秒
 参数.二：pInt_IdleTime
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出系统启动来的空闲时间,单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProcFile_System_GetTime(__int64u* pInt_UPTime = NULL, __int64u* pInt_IdleTime = NULL);
/************************************************************************/
/*                        LINUXSDK硬件读取函数导出                         */
/************************************************************************/
/********************************************************************
函数名称：ProcFile_HardWare_ReadDisk
函数功能：读取硬盘列表信息
 参数.一：pppSt_HardDisk
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出硬盘列表信息,内存需要手动释放
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProcFile_HardWare_ReadDisk(PROCFILE_HARDWARE_DISKINFO * **pppSt_HardDisk, int* pInt_ListCount);
/********************************************************************
函数名称：ProcFile_HardWare_ReadCpu
函数功能：读取CPU信息
 参数.一：pSt_HardDisk
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的CPU信息
返回值
  类型：逻辑型
  意思：是否发生错误
备注：
*********************************************************************/
extern "C" bool ProcFile_HardWare_ReadCpu(LPPROCFILE_HARDWARE_CPUINFO pSt_CPUInfo);
