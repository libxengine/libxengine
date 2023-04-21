#pragma once
/********************************************************************
//	Created:	2012/4/12  0:36
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_ManagePool\ManagePool_Define.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_ManagePool
//	File Base:	ManagePool_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	管理池模块导出定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      导出的定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      连接池定义                                      */
/************************************************************************/
#define XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_TCPV4 0x0A01                    //TCP套接字
#define XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_UDPV4 0x0A02                    //UDP套接字
#define XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_RAWV4 0x0A03                    //RAW套接字
#define XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_TCPV6 0x0A04                    //TCP套接字
#define XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_UDPV6 0x0A05                    //UDP套接字
#define XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_RAWV6 0x0A06                    //RAW套接字
//////////////////////////////////////////////////////////////////////////
//                      回调函数
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      线程池回调函数                                  */
/************************************************************************/
typedef XHTHREAD(CALLBACK* MANAGEPOOL_THREAD_WORKERPROC)(XPVOID lParam);             //线程池处理函数，要处理的函数通过此投递
/************************************************************************/
/*                      内存池回调函数                                  */
/************************************************************************/
typedef void(CALLBACK* CALLBACK_MANAGEPOOL_MEMORY_CLEANUP_HANDLE)(XPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                      数据结构定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      线程池                                           */
/************************************************************************/
//线程信息状态
typedef struct tag_ThreadPool_StateCount
{
    int nIdleThreads;                                                     //空闲线程数量
    int nNormalThreads;                                                   //正常线程数量
    int nBusyThreads;                                                     //忙碌线程数量
}THREADPOOL_STATECOUNT, * LPTHREADPOOL_STATECOUNT;
//线程池独立参数
typedef struct tag_ThreadPool_Parament
{
    XPVOID lParam;                                                        //处理函数独立参数
    MANAGEPOOL_THREAD_WORKERPROC fpCall_ThreadsTask;                      //线程池处理函数
}THREADPOOL_PARAMENT, * LPTHREADPOOL_PARAMENT;
/************************************************************************/
/*                      连接池                                           */
/************************************************************************/
//套接字选项定义。请注意，如果你对连接池调用了 ManagePool_Socket_PerformanceOptimization函数，那么下面的结构体设置将无任何效果
//传递0将不获取或者设置，如果是bool型，因为是指针所以传递NULL 将不获取。
typedef struct tag_XEngine_ManagePool_SocketOpt
{
    bool* pbDelay;                                                        //是否开启沾包处理,只支持TCP
    bool* pbKeepLive;                                                     //是否开启保活计时器，不支持ATM
    bool* pbReuseAddr;                                                    //是否允许地址重用
    bool* pbSndLinger;                                                    //如果设置为真，那么将会阻塞close并且不会让发送缓冲区完成发送
    bool* pbRcvLinger;                                                    //关闭延迟接受，目前不支持此参数设置
    int nError;                                                           //套接字错误代码，设置此选项被忽略，没有错误为0，获取后清除错误
    //接受套接字选项
    struct
    {
        int nSendSize;                                                    //接受缓冲区大小，0为不设置
        int nSendLow;                                                     //发送缓冲区最低限度，指定的值表示最小达到这个值才真正发送
        int nTimeout;                                                     //接受超时时间，0为不设置，如果你使用异步模型此选项被忽略
    }st_SocketOpt_Send;
    //发送套接字选项
    struct
    {
        int nRecvSize;                                                    //发送缓冲区系统大小，0为不设置
        int nRecvLow;                                                     //接受缓冲区最低限度，0为不设置 BSD系统兼容，WINDOWS不支持
        int nTimeout;                                                     //发送超时时间，设置后，此选项EAGAIN，此选项来判断超时还是错误
    }st_SocketOpt_Recv;
}XENGINE_MANAGEPOOL_SOCKETOPT, * LPXENGINE_MANAGEPOOL_SOCKETOPT;
//////////////////////////////////////////////////////////////////////////
//                      数据结构定义
//////////////////////////////////////////////////////////////////////////
//获取最后发生的错误，参数导出系统错误，默认不获取
extern "C" XLONG ManagePool_GetLastError(int* pInt_SysErrno = NULL);
/************************************************************************/
/*                      线程池                                           */
/************************************************************************/
/********************************************************************
函数名称：ManagePool_Thread_DTCreateEx
函数功能：创建线程池
 参数.一：nThreadCount
  In/Out：In
  类型：整数型
  可空：N
  意思：可运行线程池数量
 参数.二：nMaxTask
  In/Out：In
  类型：整数型
  可空：Y
  意思：每个线程最多可运行执行多少任务，默认10000
 参数.三：bIsClear
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：超过指定任务大小是否清理任务池，默认为真
返回值
  类型：句柄型
  意思：成功返回创建的句柄,失败返回NULL
备注：
*********************************************************************/
extern "C" XHANDLE ManagePool_Thread_DTCreate(int nThreadCount, int nMaxTask = 10000, bool bIsClear = true);
/********************************************************************
函数名称：ManagePool_Thread_DTDestroy
函数功能：销毁一个线程池
 参数.一：xhPool
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要销毁的线程池句柄
返回值
  类型：逻辑型
  意思：是否销毁创建线程池
备注：
*********************************************************************/
extern "C" bool ManagePool_Thread_DTDestroy(XHANDLE xhPool);
/********************************************************************
函数名称：ManagePool_Thread_DTPostTaskEx
函数功能：投递一个任务到线程池
 参数.一：xhPool
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要投递到哪个创建的线程池中
 参数.二：fpCall_ThreadsTask
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：要投递的任务
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：投递任务的参数
 参数.四：xhToken
  In/Out：In
  类型：句柄
  可空：Y
  意思：这个任务所属句柄(自己创建,可唯一可重用)
 参数.五：xhSerial
  In/Out：In
  类型：整数型
  可空：Y
  意思：这个任务的序列号
返回值
  类型：逻辑型
  意思：是否成功投递任务到线程池中
备注：
*********************************************************************/
extern "C" bool ManagePool_Thread_DTPostTask(XHANDLE xhPool, MANAGEPOOL_THREAD_WORKERPROC fpCall_ThreadsTask, XPVOID lParam = NULL, XNETHANDLE xhToken = 0, XNETHANDLE xhSerial = 0);
/********************************************************************
函数名称：ManagePool_Thread_DTAddBreakTask
函数功能：添加一个跳过任务属性
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要跳过的任务TOKEN，如果START参数都为0，那么这个TOKEN全部跳过
 参数.二：xhStart
  In/Out：In
  类型：整数型
  可空：Y
  意思：跳过任务的起始序列
 参数.三：xhStop
  In/Out：In
  类型：整数型
  可空：Y
  意思：跳过任务的结束序列，如果为0,那么表示只判断Start序列
返回值
  类型：逻辑型
  意思：是否成功
备注：xhToken不允许为0,如果TOKEN存在将修改跳过任务信息，否则将增加
*********************************************************************/
extern "C" bool ManagePool_Thread_DTAddBreakTaskEx(XHANDLE xhPool, XNETHANDLE xhToken, XNETHANDLE xhStart = 0, XNETHANDLE xhStop = 0);
/********************************************************************
函数名称：ManagePool_Thread_DTDelBreakTask
函数功能：删除一个跳过任务属性
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要删除的Token
返回值
  类型：逻辑型
  意思：是否成功
备注：不在使用必须跳过此函数删除跳过信息资源
*********************************************************************/
extern "C" bool ManagePool_Thread_DTDelBreakTaskEx(XHANDLE xhPool, XNETHANDLE xhToken);
/********************************************************************
函数名称：ManagePool_Thread_DTGetThreadStateEx
函数功能：获取线程池状态
 参数.一：xhPool
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要获取的线程池句柄
 参数.二：pSt_ThreadState
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出获取到的线程池状态
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool ManagePool_Thread_DTGetThreadStateEx(XHANDLE xhPool, LPTHREADPOOL_STATECOUNT pSt_ThreadState);
/********************************************************************
函数名称：ManagePool_Thread_DTSetThread
函数功能：设置线程池线程数量
 参数.一：nThreadCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要设置的线程池内部线程数量
返回值
  类型：逻辑型
  意思：是否成功
备注：会根据值自动增加和减少
*********************************************************************/
extern "C" bool ManagePool_Thread_DTSetThreadEx(XHANDLE xhPool, int nThreadCount);
//////////////////////////////////////////////////////////////////////////无队列线程池
/********************************************************************
函数名称：ManagePool_Thread_NQCreate
函数功能：创建一个无队列模式线程池
 参数.一：pppSt_ListParam
  In/Out：In
  类型：三级指针
  可空：N
  意思：根据容器个数创建线程个数，容器里面的元素代表每个线程的参数
        用户提供内存,系统销毁,如果不使用BaseLib_OperatorMemory_Malloc申请,那么使用malloc申请
 参数.二：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入线程列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：创建一个无队列模式线程池,这个任务线程你需要自己循环,不然线程将退出!
*********************************************************************/
extern "C" XHANDLE ManagePool_Thread_NQCreate(THREADPOOL_PARAMENT * **pppSt_ListParam, int nListCount);
/********************************************************************
函数名称：ManagePool_Thread_NQDestroy
函数功能：销毁无队列线程池
 参数.一：xhPool
  In/Out：In
  类型：句柄
  可空：N
  意思：要销毁的线程池句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：正确销毁方式是先退出你的任务处理函数,在调用此函数
*********************************************************************/
extern "C" bool ManagePool_Thread_NQDestroy(XHANDLE xhPool);
//////////////////////////////////////////////////////////////////////////竞争模式
/********************************************************************
函数名称：ManagePool_Thread_CTCreate
函数功能：创建竞争模式线程池
 参数.一：nThreadCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：可运行线程池数量,如果为0,那么表示自动获取当前CPU核心数
 参数.二：nMaxTask
  In/Out：In
  类型：整数型
  可空：Y
  意思：每个线程最多可运行执行多少任务，默认10000
 参数.三：bIsClear
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：超过指定任务大小是否清理任务池，默认为真
返回值
  类型：逻辑型
  意思：是否成功创建线程池
备注：
*********************************************************************/
extern "C" bool ManagePool_Thread_CTCreate(int nThreadCount = 0, int nMaxTask = 10000, bool bIsClear = true);
/********************************************************************
函数名称：ManagePool_Thread_CTPostTask
函数功能：投递任务
 参数.一：fpCall_ThreadsTask
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：自定义线程处理函数
 参数.二：lParam
  In/Out：In
  类型：无类型指针
  可空：N
  意思：线程参数
返回值
  类型：逻辑型
  意思：是否成功投递任务到线程池队列中
备注：
*********************************************************************/
extern "C" bool ManagePool_Thread_CTPostTask(MANAGEPOOL_THREAD_WORKERPROC fpCall_ThreadsTask, XPVOID lParam = NULL);
/********************************************************************
函数名称：ManagePool_Thread_CTDestroy
函数功能：销毁线程池
返回值
  类型：逻辑型
  意思：是否成功销毁
备注：
*********************************************************************/
extern "C" bool ManagePool_Thread_CTDestroy();
/************************************************************************/
/*                      连接池                                          */
/************************************************************************/
/********************************************************************
函数名称：ManagePool_Socket_Create
函数功能：创建一个连接池
 参数.一：pxhPool
  In/Out：In/Out
  类型：连接池句柄指针
  可空：N
  意思：导出一个新分配的连接池句柄
 参数.二：dwSocketNumber
  In/Out：In
  类型：双字
  可空：N
  意思：要创建的套接字个数
 参数.三：dwSocket
  In/Out：In
  类型：双字
  可空：Y
  意思：套接字属性，默认给你设置为TCP V4版本
返回值
  类型：逻辑型
  意思：是否创建成功
备注：使用了我们的连接池后，套接字全部交由我们来管理，你不需要并且不能管理套接字
*********************************************************************/
extern "C" bool ManagePool_Socket_Create(XNETHANDLE * pxhPool, XLONG dwSocketNumber, XLONG dwSocket = XENGINE_MANAGEPOOL_SOCKET_IN_TYPE_TCPV4);
/********************************************************************
函数名称：ManagePool_Socket_GetIdleSocket
函数功能：获得一个空闲的套接字
 参数.一：xhPool
  In/Out：In
  类型：连接池句柄
  可空：N
  意思：要检测的套接字池索引
 参数.二：phSocket
  In/Out：Out
  类型：整数型
  可空：N
  意思：导出获取到的空闲套接字
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool ManagePool_Socket_GetIdleSocket(XNETHANDLE xhPool, XSOCKET * phSocket);
/********************************************************************
函数名称：ManagePool_Socket_RetIdleSocket
函数功能：返回一个套接字
 参数.一：xhPool
  In/Out：In
  类型：连接池句柄
  可空：N
  意思：要返回给哪个连接池
 参数.二：hSocket
  In/Out：In
  类型：套接字
  可空：N
  意思：套接字句柄
返回值
  类型：逻辑型
  意思：是否返回给连接池成功
备注：一个套接字不在使用的时候，通过此来返回给连接池
*********************************************************************/
extern "C" bool ManagePool_Socket_RetIdleSocket(XNETHANDLE xhPool, XSOCKET hSocket);
/********************************************************************
函数名称：ManagePool_Socket_SetSize
函数功能：设置指定连接池大小
 参数.一：xhPool
  In/Out：In
  类型：连接池句柄
  可空：N
  意思：要设置的连接池
 参数.二：unPoolSize
  In/Out：In
  类型：无符号整数型
  可空：N
  意思：要设置的大小，请看备注
 参数.三：dwSocket
  In/Out：In
  类型：双字
  可空：Y
  意思：在增加的时候，可以调用此来设置新增加的XSOCKET的模式，也可以不设置，在减少的时候，此参数没有任何作用
返回值
  类型：逻辑型
  意思：时候设置成功
备注：大小设置可以新增加也可以减少，函数内部会自动判断应该怎么做，在减少的时候，连接池会选择释放空闲的
      和错误的套接字,正在使用中的连接不会被释放！
*********************************************************************/
extern "C" bool ManagePool_Socket_SetSize(XNETHANDLE xhPool, XUINT unPoolSize, XLONG dwSocket = 0);
/********************************************************************
函数名称：ManagePool_Socket_Opt_Get
函数功能：获取套接字选项
 参数.一：hSocket
  In/Out：In/Out
  类型：套接字句柄
  可空：N
  意思：要获取的套接字句柄
 参数.二：pSt_ManagePool_SocketOpt
  In/Out：In/Out
  类型：结构体指针
  可空：N
  意思：获取到的套接字属性，请注意，内存你需要自己管理
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool ManagePool_Socket_Opt_Get(XSOCKET hSocket, LPXENGINE_MANAGEPOOL_SOCKETOPT pSt_ManagePool_SocketOpt);
/********************************************************************
函数名称：ManagePool_Socket_Opt_Set
函数功能：设置套接字选项
 参数.一：hSocket
  In/Out：In
  类型：套接字句柄
  可空：N
  意思：要设置的套接字句柄
 参数.二：pSt_ManagePool_SocketOpt
  In/Out：In/Out
  类型：结构体指针
  可空：N
  意思：设置的套接字属性
返回值
  类型：逻辑型
  意思：是否设置成功
备注：
*********************************************************************/
extern "C" bool ManagePool_Socket_Opt_Set(XSOCKET hSocket, LPXENGINE_MANAGEPOOL_SOCKETOPT pSt_ManagePool_SocketOpt);
/********************************************************************
函数名称：ManagePool_Socket_Destroy
函数功能：销毁一个连接池
 参数.一：xhPool
  In/Out：In
  类型：连接池句柄
  可空：N
  意思：要销毁的连接池索引
返回值
  类型：逻辑型
  意思：是否销毁成功
备注：
*********************************************************************/
extern "C" bool ManagePool_Socket_Destroy(XNETHANDLE xhPool);
/************************************************************************/
/*                      内存池                                          */
/************************************************************************/
/********************************************************************
函数名称：ManagePool_Memory_Create
函数功能：创建一个内存池
 参数.一：nSize
  In/Out：In
  类型：无符号整数型
  可空：N
  意思：要初始化内存池的大小
 参数.二：nEstimateSize
  In/Out：In
  类型：无符号整数型
  可空：Y
  意思：预测单个内存最大大小,为0不启用内存预测
 参数.三：nMaxSize
  In/Out：In
  类型：无符号整数型
  可空：Y
  意思：最大允许内存池大小,超过将无法允许申请内存,为0 不启用,单位MB
返回值
  类型：内存池句柄
  意思：成功返回句柄，失败返回NULL
备注：注意:内存池非线程安全
*********************************************************************/
extern "C" XHANDLE ManagePool_Memory_Create(size_t nSize = 4096, size_t nEstimateSize = 102400, size_t nMaxSize = 256);
/********************************************************************
函数名称：ManagePool_Memory_Destory
函数功能：销毁一个内存池
 参数.一：pxmPool
  In/Out：In
  类型：内存池句柄
  可空：N
  意思：要销毁的内存池句柄
返回值
  类型：无
  意思：
备注：
*********************************************************************/
extern "C" void ManagePool_Memory_Destory(XHANDLE pxmPool);
/********************************************************************
函数名称：ManagePool_Memory_Reset
函数功能：重置一个内存池
 参数.一：pxmPool
  In/Out：In
  类型：内存池句柄
  可空：N
  意思：要重置的内存池句柄
返回值
  类型：无
  意思：
备注：调用这个函数,所有的内存都将被初始化
*********************************************************************/
extern "C" void ManagePool_Memory_Reset(XHANDLE pxmPool);
/********************************************************************
函数名称：ManagePool_Memory_Alloc
函数功能：在内存池申请一段内存
 参数.一：pxmPool
  In/Out：In
  类型：内存池句柄
  可空：N
  意思：要操作的内存池
 参数.二：nSize
  In/Out：In
  类型：无符号整数型
  可空：N
  意思：要申请的内存池大小
 参数.三：bIsFree
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否允许被free,如果为假,调用释放的时候这块内存不会被还原到线程池
 参数.四：bAlign
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否使用内存对齐,默认使用
返回值
  类型：内存地址
  意思：申请到的内存空间地址
备注：
*********************************************************************/
extern "C" void* ManagePool_Memory_Alloc(XHANDLE pxmPool, size_t nSize, bool bIsFree = true, bool bAlign = true);
/********************************************************************
函数名称：ManagePool_Memory_Free
函数功能：通过内存池释放大块内存的接口函数
 参数.一：pxmPool
  In/Out：In
  类型：内存池句柄
  可空：N
  意思：要操作的内存池句柄
 参数.二：lPBuffer
  In/Out：In
  类型：内存地址
  可空：N
  意思：要释放的内存地址
返回值
  类型：无
  意思：
备注：此函数将还原大内存给内存池,内存块只有在被设置为可释放的情况才还原给内存池
*********************************************************************/
extern "C" void ManagePool_Memory_Free(XHANDLE pxmPool, XPVOID lPBuffer);
/********************************************************************
函数名称：ManagePool_Memory_CleanupAdd
函数功能：增加内存池销毁的时候预先处理函数
 参数.一：pxmPool
  In/Out：In
  类型：内存池句柄
  可空：N
  意思：要操作的内存池句柄
 参数.二：fpCall_Cleanup
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：要设置的回调信息
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ManagePool_Memory_CleanupAdd(XHANDLE pxmPool, CALLBACK_MANAGEPOOL_MEMORY_CLEANUP_HANDLE fpCall_Cleanup, XPVOID lParam = NULL);
