#pragma once
/********************************************************************
//	Created:	2012/1/22  15:51
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_DownLoad\NetEngine_DownLoad\DownLoad_Define.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_DownLoad\NetEngine_DownLoad
//	File Base:	DownLoad_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	网络下载引擎-导出数据函数定义
//	History:
*********************************************************************/
//状态
typedef enum en_NetDown_Engine_Status
{
    ENUM_XENGINE_DOWNLOAD_STATUS_DOWNLOADDING = 1,                      //下载中
    ENUM_XENGINE_DOWNLOAD_STATUS_SUSPENDED,                             //下载挂起中
    ENUM_XENGINE_DOWNLOAD_STATUS_STOP,                                  //下载停止，没有下载任务
    ENUM_XENGINE_DOWNLOAD_STATUS_COMPLETE,                              //下载完成
    ENUM_XENGINE_DOWNLOAD_STATUS_ERROR                                  //下载中出现错误，无法解决
}ENUM_DOWNENGINE_STATUS,*LPENUM_DOWNENGINE_STATUS;
//////////////////////////////////////////////////////////////////////////
//任务信息，回调函数为空才有用
typedef struct 
{
    double dlTotal;                                                       //下载总大小
    double dlNow;                                                         //已经下载大小
    double ulTotal;                                                       //上传总大小
    double ulNow;                                                         //已经上传大小

    ENUM_DOWNENGINE_STATUS en_DownStatus;                                 //状态
}NETDOWNLOAD_TASKINFO,*LPNETDOWNLOAD_TASKINFO;
//////////////////////////////////////////////////////////////////////////
//HTTP下载回调函数，参数意思：下载句柄，下载的总大小，当前下载大小，上传总大小，当前上传大小（下载这两个参数无效，为0），当前状态，自定义参数
typedef void(CALLBACK *CALLBACK_XENGINE_DOWNLOAD_HTTP_PROGRESS)(XNETHANDLE xhDown,double dlTotal,double dlNow,double ulTotal,double ulNow,ENUM_DOWNENGINE_STATUS en_DownHttpStatus,LPVOID lParam);
typedef void(CALLBACK *CALLBACK_XENGINE_DOWNLOAD_FTP_PROGRESS)(XNETHANDLE xhDown,double dlTotal,double dlNow,double ulTotal,double ulNow,ENUM_DOWNENGINE_STATUS en_DownHttpStatus,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                  导出函数
//////////////////////////////////////////////////////////////////////////
//获取错误码
extern "C" BOOL Download_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*           HTTP下载导出函数，如果是FTP匿名服务器，也可以用此下载      */
/************************************************************************/
/********************************************************************
函数名称：DownLoad_Http_Create
函数功能：创建一个HTTP下载任务
 参数.一：phNetDown
  In/Out：In
  类型：下载句柄
  可空：N
  意思：导出一个下载句柄
 参数.二：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：下载的HTTP地址
 参数.三：lpszSaveFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要保存的地址
 参数.四：bIsResume
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否是续传，默认为假，不续传,如果这个值为真，那么你的LPSZADDR 必须为上个文件所存在的位置，系统内部会自动判断续传位置
 参数.五：fpCall_HttpProgress
  In/Out：In
  类型：回调函数
  可空：Y
  意思：下载过程
 参数.六：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否创建成功
备注：回调函数为空请调用QUERY来查询！
*********************************************************************/
extern "C" BOOL DownLoad_Http_Create(PXNETHANDLE phNetDown,LPCSTR lpszAddr,LPCSTR lpszSaveFile,BOOL bIsResume = FALSE,CALLBACK_XENGINE_DOWNLOAD_HTTP_PROGRESS fpCall_HttpProgress = NULL,LPVOID lParam = NULL);
/********************************************************************
函数名称：DownLoad_Http_Query
函数功能：查询任务信息
 参数.一：xhDown
  In/Out：In
  类型：下载句柄
  可空：N
  意思：要查询的任务句柄
 参数.二：pSt_TaskInfo
  In/Out：Out
  类型：数据结构贺指针
  可空：N
  意思：导出查询到的任务信息
返回值
  类型：逻辑型
  意思：时候成功查询到任务
备注：
*********************************************************************/
extern "C" BOOL DownLoad_Http_Query(XNETHANDLE xhDown,LPNETDOWNLOAD_TASKINFO pSt_TaskInfo);
/********************************************************************
函数名称：DownLoad_Http_Delete
函数功能：删除一个下载任务
 参数.一：xhDown
  In/Out：In
  类型：下载句柄
  可空：N
  意思：要删除的任务句柄
返回值
  类型：逻辑型
  意思：是否成功删除
备注：下载完成后必须调用此函数，或者你不想下载一个任务。
*********************************************************************/
extern "C" BOOL DownLoad_Http_Delete(XNETHANDLE xhDown);
/********************************************************************
函数名称：DownLoad_Http_Pause
函数功能：暂停或者恢复
 参数.一：xhDown
  In/Out：bIsPause
  类型：下载句柄
  可空：N
  意思：要控制的下载句柄
 参数.二：bIsPause
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：暂停还是恢复，默认为假 恢复下载
返回值
  类型：逻辑型
  意思：是否成功处理
备注：支持上传和下载控制
*********************************************************************/
extern "C" BOOL DownLoad_Http_Pause(XNETHANDLE xhDown,BOOL bIsPause = FALSE);
/********************************************************************
函数名称：DownLoad_Http_GetFileSize
函数功能：获取文件大小
 参数.一：lpszUrlAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要获取的文件URL地址
 参数.二：pdlFileSize
  In/Out：Out
  类型：双精度型
  可空：N
  意思：导出获取到的文件大小，字节
返回值
  类型：逻辑型
  意思：是否获取成功
备注：此函数支持FTP模式，仅仅支持匿名FTP
*********************************************************************/
extern "C" BOOL DownLoad_Http_GetFileSize(LPCSTR lpszUrlAddr,double *pdlFileSize);
/********************************************************************
函数名称：DownLoad_Http_SetMaxSpeed
函数功能：设置HTTP下载上传最大速度
 参数.一：xhDown
  In/Out：In
  类型：句柄
  可空：N
  意思：要设置那个HTTP任务
 参数.二：nSendMax
  In/Out：In
  类型：整数型
  可空：N
  意思：要设置的发送最大速度 byte/second
 参数.三：nRecvMax
  In/Out：In
  类型：整数型
  可空：N
  意思：要设置的接受最大速度
返回值
  类型：逻辑型
  意思：是否设置成功
备注：任务没有创建无法设置！
*********************************************************************/
extern "C" BOOL DownLoad_Http_SetMaxSpeed(XNETHANDLE xhDown,int nSendMax,int nRecvMax);
/************************************************************************/
/*           FTP下载上传导出函数                                        */
/************************************************************************/
/********************************************************************
函数名称：DownLoad_Http_Create
函数功能：创建一个HTTP下载任务
 参数.一：phNetDown
  In/Out：In
  类型：下载句柄
  可空：N
  意思：导出一个下载句柄
 参数.二：lpszAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：下载的FTP地址，如果不是下载，这个参数表示上传的FTP地址       ftp://192.168.0.1/1.rar,用户名密码格式：ftp://ftpuser:123123@192.168.1.103/1.rar
 参数.三：lpszSaveFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要保存的地址，如果不是下载，这个参数表示要上传的文件
 参数.四：bIsResume
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否是续传，默认为假，不续传,如果这个值为真，那么你的LPSZADDR 必须为上个文件所存在的位置，系统内部会自动判断续传位置
 参数.五：bIsDown
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：上传还是下载，默认为下载
 参数.六：bIsPasv
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：FTP传输模式，默认为PASV 假为EPSV
 参数.七：fpCall_FtpProgress
  In/Out：In
  类型：回调函数
  可空：Y
  意思：下载过程
 参数.八：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否创建成功
备注：回调函数为空请调用QUERY来查询！
*********************************************************************/
extern "C" BOOL DownLoad_Ftp_Create(PXNETHANDLE phNetDown,LPCSTR lpszAddr,LPCSTR lpszSaveFile,BOOL bIsResume = FALSE,BOOL bIsDown = TRUE,BOOL bIsPasv = FALSE,CALLBACK_XENGINE_DOWNLOAD_FTP_PROGRESS fpCall_HttpProgress = NULL,LPVOID lParam = NULL);
/********************************************************************
函数名称：DownLoad_Ftp_Query
函数功能：查询任务信息
 参数.一：xhDown
  In/Out：In
  类型：下载句柄
  可空：N
  意思：要查询的任务句柄
 参数.二：pSt_TaskInfo
  In/Out：Out
  类型：数据结构贺指针
  可空：N
  意思：导出查询到的任务信息
返回值
  类型：逻辑型
  意思：时候成功查询到任务
备注：
*********************************************************************/
extern "C" BOOL DownLoad_Ftp_Query(XNETHANDLE xhDown,LPNETDOWNLOAD_TASKINFO pSt_TaskInfo);
/********************************************************************
函数名称：DownLoad_Ftp_Delete
函数功能：删除一个下载任务
 参数.一：xhDown
  In/Out：In
  类型：下载句柄
  可空：N
  意思：要删除的任务句柄
返回值
  类型：逻辑型
  意思：是否成功删除
备注：下载完成后必须调用此函数，或者你不想下载一个任务。
*********************************************************************/
extern "C" BOOL DownLoad_Ftp_Delete(XNETHANDLE xhDown);
/********************************************************************
函数名称：DownLoad_Ftp_Pause
函数功能：暂停或者恢复
 参数.一：xhDown
  In/Out：bIsPause
  类型：下载句柄
  可空：N
  意思：要控制的下载句柄
 参数.二：bIsPause
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：暂停还是恢复，默认为假 恢复下载
返回值
  类型：逻辑型
  意思：是否成功处理
备注：支持上传和下载控制
*********************************************************************/
extern "C" BOOL DownLoad_Ftp_Pause(XNETHANDLE xhDown,BOOL bIsPause = FALSE);
/********************************************************************
函数名称：DownLoad_Ftp_RemoteFileIsExist
函数功能：检查远程文件是否存在
 参数.一：lpszUrlAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要检查的URL地址
返回值
  类型：逻辑型
  意思：是否存在，返回假不存在，但是你需要获取错误码来正确判断
备注：适用于HTTP FTP 等文件，都可以使用此函数
*********************************************************************/
extern "C" BOOL DownLoad_Ftp_RemoteFileIsExist(LPCSTR lpszUrlAddr);
/********************************************************************
函数名称：DownLoad_Ftp_SetMaxSpeed
函数功能：设置FTP下载上传最大速度
 参数.一：xhDown
  In/Out：In
  类型：句柄
  可空：N
  意思：要设置那个FTP任务
 参数.二：nSendMax
  In/Out：In
  类型：整数型
  可空：N
  意思：要设置的发送最大速度
 参数.三：nRecvMax
  In/Out：In
  类型：整数型
  可空：N
  意思：要设置的接受最大速度
返回值
  类型：逻辑型
  意思：是否设置成功
备注：任务没有创建无法设置！
*********************************************************************/
extern "C" BOOL DownLoad_Ftp_SetMaxSpeed(XNETHANDLE xhDown,int nSendMax,int nRecvMax);
