#pragma once
/********************************************************************
//	Created:	2013/1/3  19:22
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_EmailClient\EmailClient_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_EmailClient
//	File Base:	EmailClient_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	电子邮件客户端导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                    导出的回调函数
//////////////////////////////////////////////////////////////////////////
//参数意思：发送者的句柄，发送是否成功，发送者参数
typedef void(CALLBACK *CALLBACK_RFCCOMPONENTS_EMAILCLIENT_SMTP_SENDPROGRESS)(XHANDLE xhNet,BOOL bRet,LPVOID lParam);
//POP3回调，如果你设置的索引号为0，那么这个参数将导出邮件个数，第二个参数无效，第三个参数是获取到的内容，内容格式是 1 3333（第一封邮件，大小3333）以换行符为分割，输出多少封，第四个参数无效。
//否则 第二个参数表明是否收取成功，为假表示收取失败，第三个参数是邮件内容，第四个参数是内容大小。
typedef void(CALLBACK *CALLBACK_RFCCOMPONENTS_EMAILCLIENT_POP3_RECVPROGRESS)(XHANDLE xhNet,BOOL bRet,LPCSTR lpszBuffer,int nLen,LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                    导出的数据结构
//////////////////////////////////////////////////////////////////////////
//邮件内容构造
typedef struct
{
    CHAR tszServiceAddr[MAX_PATH];                                        //服务器地址 smtp://mainserver.example.net:587
    CHAR tszCertFile[MAX_PATH];                                           //PEM个人证书路径，如果为NULL，将不使用SSL传送
    CHAR tszUserName[MAX_PATH];                                           //发送的用户名 486179@qq.com
    CHAR tszPassWord[MAX_PATH];                                           //你的邮箱密码 486179
    CHAR tszFromAddr[MAX_PATH];                                           //回复地址，也可以是你的用户名，有的邮箱如果有防洪水邮件会验证你的回复地址，如果你传递假的会造成发送失败
    BOOL bIsCall;                                                         //是否启用回调，非阻塞发送。为假将不启用，如果启用你需要优先调用SetCallBack函数设置回调。
}RFCCOMPONENTS_EMAILSMTP,*LPRFCCOMPONENTS_EMAILSMTP;
typedef struct
{
	CHAR tszServiceAddr[MAX_PATH];                                        //服务器地址 pop3://pop.example.net        //具体地址请你查看你邮箱的说明，每个邮箱都不同
	CHAR tszFilePath[MAX_PATH];                                           //保存路径,一封邮件可能很大，如果你想把这封邮件保存到一个地方，可以设置这个参数，如果为NULL，将不写文件
	CHAR tszCertFile[MAX_PATH];                                           //PEM个人证书路径，如果为NULL，将不使用SSL
	CHAR tszUserName[MAX_PATH];                                           //你的用户名和密码 486179@qq.com:123123
    int nIndex;                                                           //要收取第几个文件，为0表示获取邮件多少封
    BOOL bIsCall;                                                         //是否启用回调，非阻塞接受。为假将不启用
}RFCCOMPONENTS_EMAILPOP3,*LPRFCCOMPONENTS_EMAILPOP3;
//////////////////////////////////////////////////////////////////////////
//                    导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD EMailClient_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                    SMTP客户端导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_EMailClient_SmtpInit
函数功能：初始化一个SMTP客户端
 参数.一：pSt_EmailInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：电子邮箱的常规信息
返回值
  类型：句柄型
  意思：成功返回句柄,失败返回NULL
备注：
*********************************************************************/
extern "C" XHANDLE RfcComponents_EMailClient_SmtpInit(LPRFCCOMPONENTS_EMAILSMTP pSt_EmailInfo);
/********************************************************************
函数名称：RfcComponents_EMailClient_SmtpSetCallBack
函数功能：设置SMTP邮件客户端回调函数
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：fpCall_SendProgress
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：发送过程回调
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数针对每个客户端需要设置一次回调
*********************************************************************/
extern "C" BOOL RfcComponents_EMailClient_SmtpSetCallBack(XHANDLE xhNet, CALLBACK_RFCCOMPONENTS_EMAILCLIENT_SMTP_SENDPROGRESS fpCall_SendProgress, LPVOID lParam = NULL);
/********************************************************************
函数名称：RfcComponents_EMailClient_SmtpSend
函数功能：发送已经准备好的电子邮件
 参数.一：xhNet
  In/Out：In
  类型：X网络句柄
  可空：N
  意思：要发送的指定SMTP客户端
 参数.二：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：对方的邮件地址,使用;符号分割多个
 参数.三：lpszSubJect
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：邮件标题
 参数.四：lpszPayLoad
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：邮件正文，换行符\n
返回值
  类型：逻辑型
  意思：是否成功发送
备注：设置了回调函数后，这个函数并不能保证所有邮件都能发送成功，如果你没有设置回调函数，那么这个函数会
      阻塞应用程序并且指导所有操作完成，那么这个函数返回真表示发送成功
*********************************************************************/
extern "C" BOOL RfcComponents_EMailClient_SmtpSend(XHANDLE xhNet, LPCSTR lpszClientAddr, LPCSTR lpszSubJect,LPCSTR lpszPayLoad);
/********************************************************************
函数名称：RfcComponents_EMailClient_SmtpClose
函数功能：关闭客户端
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的指定客户端句柄
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_EMailClient_SmtpClose(XHANDLE xhNet);
/************************************************************************/
/*                    POP3客户端导出函数                                */
/************************************************************************/
/********************************************************************
函数名称：RfcComponents_EMailClient_POP3Init
函数功能：初始化一个POP3客户端
 参数.一：pSt_EMailInfo
  In/Out：In
  类型：In
  可空：N
  意思：POP3客户端参数
返回值
  类型：句柄型
  意思：成功返回句柄,失败返回NULL
备注：
*********************************************************************/
extern "C" XHANDLE RfcComponents_EMailClient_POP3Init(LPRFCCOMPONENTS_EMAILPOP3 pSt_EMailInfo);
/********************************************************************
函数名称：RfcComponents_EMailClient_SmtpSetCallBack
函数功能：设置SMTP邮件客户端回调函数
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：fpCall_SendProgress
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：发送过程回调
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数的参数
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数针对每个客户端需要设置一次回调
*********************************************************************/
extern "C" BOOL RfcComponents_EMailClient_POP3SetCallBack(XHANDLE xhNet, CALLBACK_RFCCOMPONENTS_EMAILCLIENT_POP3_RECVPROGRESS fpCall_RecvProgress, LPVOID lParam = NULL);
/********************************************************************
函数名称：RfcComponents_EMailClient_POP3Recv
函数功能：开始接受数据
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要接受的网络客户端
返回值
  类型：逻辑型
  意思：是否成功接受
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_EMailClient_POP3Recv(XHANDLE xhNet);
/********************************************************************
函数名称：RfcComponents_EMailClient_POP3Close
函数功能：关闭一个指定的客户端
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的网络客户端
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" BOOL RfcComponents_EMailClient_POP3Close(XHANDLE xhNet);
