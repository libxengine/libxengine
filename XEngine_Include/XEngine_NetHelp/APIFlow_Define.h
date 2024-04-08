#pragma once
/********************************************************************
//    Created:     2024/04/02  14:19:29
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIFlow\APIFlow_Define.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_NetHelp\NetHelp_APIFlow
//    File Base:   APIFlow_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     流量操作接口导出函数定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
//获取网卡流量信息
typedef struct 
{
    XCHAR tszDevName[64];                    //设备名称

    struct
    {
        __int64u ullBytes;                  //接受的流量
        __int64u ullPackets;                //接受包个数
        __int64u ullError;                  //错误的包
        __int64u ullDrop;                   //被丢弃的包
        __int64u ullFifo;                   //出入队列
        __int64u ullFrame;                  //帧
        __int64u ullCompress;               //压缩的包
        __int64u ullMultiCast;              //多播包
    }st_RecvPackets;
    struct
    {
        __int64u ullBytes;                  //接受的流量
        __int64u ullPackets;                //接受包个数
        __int64u ullError;                  //错误的包
        __int64u ullDrop;                   //被丢弃的包
        __int64u ullFifo;                   //出入队列
        __int64u ullFrame;                  //帧
        __int64u ullCompress;               //压缩的包
        __int64u ullMultiCast;              //多播包
    }st_SendPackets;
}APIFLOW_STATUSINFO;
//////////////////////////////////////////////////////////////////////
//                        导出函数
//////////////////////////////////////////////////////////////////////
extern "C" XLONG APIFlow_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                     流量获取函数导出                                    */
/************************************************************************/
/************************************************************************
函数名称：APIFlow_NetGet_All
函数功能：获取网络流量信息
  参数.一：pSt_FlowState
   In/Out：Out
   类型：数据结构指针
   可空：N
   意思：网络流量信息结构体
  参数.二：lpszEth_Name
   In/Out：In
   类型：常量字符指针
   可空：Y
   意思：要获取的网卡名称，比如：eth0
  参数.三：nNumEntries
   In/Out：In
   类型：整数型
   可空：Y
   意思：要获取的网卡编号
返回值
  类型：逻辑型
  意思：是否成功获取
备注：最后两个参数不能同时为空,每秒获取一次,这一次减去上一次的流量就得到当前每秒流量
************************************************************************/
extern "C" bool APIFlow_NetGet_All(APIFLOW_STATUSINFO *pSt_FlowState,LPCXSTR lpszDevName = NULL,int nNumEntries = 0);
/************************************************************************/
/*                     网络流量控制导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：APIFlow_NetCtrl_Init
函数功能：初始化流量控制程序
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出初始化成功的句柄
 参数.二：lpszDevName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入你的网卡名称,macos表示流量配置路径
 参数.三：bIsClear
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否清理老旧的流量控制服务设定
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数需要管理员权限
*********************************************************************/
extern "C" bool APIFlow_NetCtrl_Init(XNETHANDLE *pxhNet,LPCXSTR lpszDevName,bool bIsClear = true);
/********************************************************************
函数名称：APIFlow_NetCtrl_AddFlow
函数功能：为一条连接添加一个流量控制程序
 参数.一：xhNet
  In/Out：n
  类型：网络句柄
  可空：N
  意思：输入要操作的流量控制程序
 参数.二：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出添加的过滤器句柄
 参数.三：nLimitByte
  In/Out：In
  类型：整数型
  可空：N
  意思：设置要限制的速度，每秒Byte,不能超过你的网卡负载大小
 参数.四：nRecvByte
  In/Out：In
  类型：整数型
  可空：N
  意思：Linux版本此参数无效！暂时无效
 参数.五：nDstPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：设置要控制通道的目标端口
 参数.六：nSrcPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：设置要控制流量通道的源端口,可以为空,只用目标端口控制某一条通道流量信息
返回值
  类型：逻辑型
  意思：是否成功
备注：参数5和6不能同时为0
*********************************************************************/
extern "C" bool APIFlow_NetCtrl_AddFlow(XNETHANDLE xhNet,XNETHANDLE *pxhFilter,int nLimitByte, int nRecvByte, int nDstPort = 0, int nSrcPort = 0);
/********************************************************************
函数名称：APIFlow_NetCtrl_DelFlow
函数功能：删除一条流量控制信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要操作的流量控制句柄
 参数.二：xhFilter
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要删除的过滤器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：macos不支持
*********************************************************************/
extern "C" bool APIFlow_NetCtrl_DelFlow(XNETHANDLE xhNet,XNETHANDLE xhFilter);
/********************************************************************
函数名称：APIFlow_NetCtrl_Destory
函数功能：销毁流量控制程序
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要销毁的流量控制句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool APIFlow_NetCtrl_Destory(XNETHANDLE xhNet);