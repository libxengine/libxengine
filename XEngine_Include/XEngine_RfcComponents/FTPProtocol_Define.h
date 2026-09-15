#pragma once
/********************************************************************
//    Created:     2026/08/06  20:26:31
//    File Name:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_FTPProtocol\FTPProtocol_Define.h
//    File Path:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_FTPProtocol
//    File Base:   FTPProtocol_Define
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     FTP导出协议
//    History:
*********************************************************************/
//客户端请求
#define XENGINE_FTPROTOCOL_QUESTION_USER _X("USER")                         //USER,发送用户名
#define XENGINE_FTPROTOCOL_QUESTION_PASS _X("PASS")                         //PASS,发送密码
#define XENGINE_FTPROTOCOL_QUESTION_ACCT _X("ACCT")                         //ACCT
#define XENGINE_FTPROTOCOL_QUESTION_QUIT _X("QUIT")                         //QUIT
#define XENGINE_FTPROTOCOL_QUESTION_NOOP _X("NOOP")                         //NOOP,空指令
#define XENGINE_FTPROTOCOL_QUESTION_REIN _X("REIN")                         //REIN,
#define XENGINE_FTPROTOCOL_QUESTION_PORT _X("PORT")                         //PORT请求进入主动模式
#define XENGINE_FTPROTOCOL_QUESTION_PASV _X("PASV")                         //PASV,请求进入被动模式
#define XENGINE_FTPROTOCOL_QUESTION_TYPE _X("TYPE")                         //TYPE,设置传输模式,I 二进制,A ASCII,E 扩展模式,L 本地模式
#define XENGINE_FTPROTOCOL_QUESTION_STRU _X("STRU")                         //STRU,设置文件结构
#define XENGINE_FTPROTOCOL_QUESTION_MODE _X("MODE")                         //MODE,设置传输模式
#define XENGINE_FTPROTOCOL_QUESTION_RETR _X("RETR")                         //RETR,下载文件
#define XENGINE_FTPROTOCOL_QUESTION_STOR _X("STOR")                         //STOR,上传文件
#define XENGINE_FTPROTOCOL_QUESTION_APPE _X("APPE")                         //APPE,追加上传文件
#define XENGINE_FTPROTOCOL_QUESTION_LIST _X("LIST")                         //LIST,获取文件和目录的详细列表
#define XENGINE_FTPROTOCOL_QUESTION_NLST _X("NLST")                         //NLST,仅获取文件和目录的纯文件名列表
#define XENGINE_FTPROTOCOL_QUESTION_PWD _X("PWD")                           //PWD,显示当前目录
#define XENGINE_FTPROTOCOL_QUESTION_CWD _X("CWD")                           //CWD,切换目录
#define XENGINE_FTPROTOCOL_QUESTION_CDUP _X("CDUP")                         //CDUP,返回上一级目录
#define XENGINE_FTPROTOCOL_QUESTION_MKD _X("MKD")                           //MKD,创建目录
#define XENGINE_FTPROTOCOL_QUESTION_RMD _X("RMD")                           //RMD,删除目录
#define XENGINE_FTPROTOCOL_QUESTION_DELE _X("DELE")                         //DELE,删除文件
#define XENGINE_FTPROTOCOL_QUESTION_RENAME _X("RENAME")                     //RENAME,指定要重命名/移动的原文件名
#define XENGINE_FTPROTOCOL_QUESTION_SIZE _X("SIZE")                         //SIZE,获取文件大小
#define XENGINE_FTPROTOCOL_QUESTION_MDTM _X("MDTM")                         //MDTM,获取文件修改时间
//服务端响应
//初步响应
#define XENGINE_FTPROTOCOL_RESPONSE_125 125                                 //数据通道已打开，开始传输
#define XENGINE_FTPROTOCOL_RESPONSE_150 150                                 //数据通道准备完毕，即将开始传输数据
//完成响应
#define XENGINE_FTPROTOCOL_RESPONSE_200 200                                 //命令成功
#define XENGINE_FTPROTOCOL_RESPONSE_202 202                                 //命令未执行，命令不可执行
#define XENGINE_FTPROTOCOL_RESPONSE_211 211                                 //系统状态，或系统帮助响应
#define XENGINE_FTPROTOCOL_RESPONSE_220 220                                 //服务就绪
#define XENGINE_FTPROTOCOL_RESPONSE_221 221                                 //已退出，正在关闭连接，对 QUIT 的回应
#define XENGINE_FTPROTOCOL_RESPONSE_226 226                                 //数据通道关闭，文件/列表传输完成
#define XENGINE_FTPROTOCOL_RESPONSE_227 227                                 //进入被动模式
#define XENGINE_FTPROTOCOL_RESPONSE_230 230                                 //身份验证成功
#define XENGINE_FTPROTOCOL_RESPONSE_250 250                                 //请求文件操作成功
#define XENGINE_FTPROTOCOL_RESPONSE_257 257                                 //返回路径，如 PWD
//中间响应
#define XENGINE_FTPROTOCOL_RESPONSE_331 331                                 //用户名正确，需要密码
#define XENGINE_FTPROTOCOL_RESPONSE_332 332                                 //需要账户信息
#define XENGINE_FTPROTOCOL_RESPONSE_350 350                                 //请求的文件操作正在等待进一步的信息
//暂时拒绝
#define XENGINE_FTPROTOCOL_RESPONSE_421 421                                 //服务不可用，关闭控制连接
#define XENGINE_FTPROTOCOL_RESPONSE_425 425                                 //无法打开数据连接
#define XENGINE_FTPROTOCOL_RESPONSE_426 426                                 //连接关闭，传输中止
#define XENGINE_FTPROTOCOL_RESPONSE_450 450                                 //请求的文件操作未执行，文件不可用
#define XENGINE_FTPROTOCOL_RESPONSE_451 451                                 //请求的操作中止：本地错误处理
//永久拒绝
#define XENGINE_FTPROTOCOL_RESPONSE_500 500                                 //语法错误，命令不可识别
#define XENGINE_FTPROTOCOL_RESPONSE_501 501                                 //参数语法错误
#define XENGINE_FTPROTOCOL_RESPONSE_502 502                                 //命令不可执行
#define XENGINE_FTPROTOCOL_RESPONSE_503 503                                 //命令顺序错误
#define XENGINE_FTPROTOCOL_RESPONSE_530 530                                 //未登录
#define XENGINE_FTPROTOCOL_RESPONSE_550 550                                 //请求的操作未执行，文件不可用
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" XLONG FTPProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     FTP协议解析导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：FTPProtocol_Parse_Init
函数功能：初始化FTP解析器
 参数.一：lpszFTPCodes
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：FTP响应文件
 参数.二：nPoolCount
  In/Out：In
  类型：整数型
  可空：Y
  意思：任务池个数,应该配合线程池个数使用
 参数.三：bServer
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否为服务器模式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE FTPProtocol_Parse_InitEx(LPCXSTR lpszFTPCodes, int nPoolCount = 0, bool bServer = true);
/********************************************************************
函数名称：FTPProtocol_Parse_Destroy
函数功能：销毁
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_DestroyEx(XHANDLE xhToken);
/********************************************************************
函数名称：FTPProtocol_Parse_CreateClient
函数功能：创建一个客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端地址
 参数.二：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：线程索引,-1表示没有启用,0表示自动选择
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_CreateClientEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, int nPoolIndex = -1);
/********************************************************************
函数名称：FTPProtocol_Parse_GetClient
函数功能：从队列中获取一个待处理的客户端的包
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要处理的包的客户端地址
 参数.二：pSt_KeyValue
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出请求信息
返回值
  类型：逻辑型
  意思：是否获取成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_GetClientEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, XENGINE_KEYVALUE* pSt_KeyValue);
/********************************************************************
函数名称：FTPProtocol_Parse_InserQueue
函数功能：插入一段数据到队列中
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的客户端地址
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要插入的数据
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：要插入的数据的长度
返回值
  类型：逻辑型
  意思：是否插入成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_InsertQueueEx(XHANDLE xhToken, LPCXSTR lpszClientAddr, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：FTPProtocol_Parse_GetPool
函数功能：获取对应池化客户端列表
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入池化索引
 参数.二：pppSt_ListClient
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的对应类表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出客户端列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数二需要调用基础库的内存释放函数BaseLib_Memory_Free进行内存释放
*********************************************************************/
extern "C" bool FTPProtocol_Parse_GetPoolEx(XHANDLE xhToken, int nPoolIndex, XENGINE_MANAGEPOOL_TASKEVENT*** pppSt_ListClient, int* pInt_ListCount);
/********************************************************************
函数名称：FTPProtocol_Parse_DeleteClient
函数功能：删除客户端
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的客户端地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_DeleteClientEx(XHANDLE xhToken, LPCXSTR lpszClientAddr);
/********************************************************************
函数名称：FTPProtocol_Parse_EventWait
函数功能：等待一个完成包事件的发生
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布式池索引
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位毫秒 -1 不超时,0立即返回 > 0等待事件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_EventWaitEx(XHANDLE xhToken, int nPoolIndex = -1, int nTimeOut = -1);
/********************************************************************
函数名称：FTPProtocol_Parse_EventActive
函数功能：手动激活一次事件
 参数.一：nIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布池索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_EventActiveEx(XHANDLE xhToken, int nPoolIndex = -1);
/********************************************************************
函数名称：FTPProtocol_Parse_SendPacket
函数功能：发送数据包
 参数.一：nFTPCode
  In/Out：In
  类型：整数型
  可空：N
  意思：FTP协议代码
 参数.二：ptszMSGBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：要发送的消息缓冲区
 参数.三：pInt_MSGLen
  In/Out：Out
  类型：整数指针
  可空：N
  意思：输出消息长度
 参数.四：bPacket
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否需要组包
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Parse_SendPacketEx(XHANDLE xhToken, int nFTPCode, XCHAR* ptszMSGBuffer, int* pInt_MSGLen, bool bPacket = true);
/*************************************************************************
                        协议打包导出函数
**************************************************************************/
/********************************************************************
函数名称：FTPProtocol_Packet_Request
函数功能：FTP协议请求封装函数
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包好的数据缓冲区
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.三：pSt_KeyValue
  In/Out：In
  类型：数据结构指针
  可空：Y
  意思：输入要封装的响应或者请求
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool FTPProtocol_Packet_Request(XCHAR* ptszMsgBuffer, int* pInt_Len, XENGINE_KEYVALUE* pSt_KeyValue);