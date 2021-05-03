#pragma once
/********************************************************************
//	Created:	2019/6/28   14:56
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Storage\NetEngine_XStorageCore\XStorageCore_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_Storage\NetEngine_XStorageCore
//	File Base:	XStorageCore_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	X存储服务导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
///                        导出数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct tag_XStorageCore_DirInfo
{
    CHAR tszRootDir[MAX_PATH];                                           //主目录
    CHAR tszUserDir[MAX_PATH];                                           //文件夹所属用户
    __int64x nDirCount;                                                    //文件夹最大允许大小,单位字节
    BOOL bEnableDay;                                                      //是否启用按天数管理文件
    BOOL bEnableType;                                                     //是否启用按照文件类型来管理
    BOOL bEnable;                                                         //是否启用这个配置
}XSTORAGECORE_DIRINFO,*LPXSTORAGECORE_DIRINFO;
typedef struct tag_XStorageCore_DBFILE
{
    XENGINE_PROTOCOLFILE st_ProtocolFile;
    CHAR tszTableName[64];                                                //日期表名称,插入:表示自定义插入日期表,获取:表示导出这个文件所属日期表
    CHAR tszFileRoot[MAX_PATH];                                           //机器路径
}XSTORAGECORE_DBFILE, *LPXSTORAGECORE_DBFILE;
typedef struct tag_XStorageCore_UserInfo
{
    XENGINE_PROTOCOL_USERREG st_ProtocolUser;
    __int64x nFileCount;                                                   //拥有的文件个数
    __int64x nFileSize;                                                    //文件占用大小
    XNETHANDLE xhToken;                                                   //用户临时会话句柄
    CHAR tszIPAddr[64];                                                   //最后登录IP地址
}XSTORAGECORE_USERINFO, *LPXSTORAGECORE_USERINFO;
//////////////////////////////////////////////////////////////////////////
///                        导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD XStorageCore_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                         导出的数据库操作函数                         */
/************************************************************************/
/********************************************************************
函数名称：XStorageCore_DBManage_Init
函数功能：初始化存储服务数据库管理器
 参数.一：pSt_DBConnector
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：数据MYSQL数据库连接信息
 参数.二：nTimeDay
  In/Out：In
  类型：整数型
  可空：N
  意思：输入文件数据保留时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_Init(DATABASE_MYSQL_CONNECTINFO *pSt_DBConnector, int nTimeDay = 30);
/********************************************************************
函数名称：XStorageCore_DBManage_Destory
函数功能：销毁数据库管理器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_Destory();
/********************************************************************
函数名称：XStorageCore_DBManage_FileInsert
函数功能：插入一个文件数据到数据库中
 参数.一：pSt_DBManage
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要插入的数据信息
返回值
  类型：逻辑型
  意思：是否成功
备注：这个结构所有值都必须填充
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_FileInsert(XSTORAGECORE_DBFILE *pSt_DBManage);
/********************************************************************
函数名称：XStorageCore_DBManage_FileDelete
函数功能：删除一个数据库文件信息
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要删除的文件全路径
 参数.二：lpszMd5
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要删除的文件MD5
 参数.三：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要操作的用户名
 参数.四：bDelFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否删除文件
返回值
  类型：逻辑型
  意思：是否成功
备注：参数不能全为空,不会删除文件
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_FileDelete(LPCSTR lpszFile = NULL, LPCSTR lpszMd5 = NULL, LPCSTR lpszUserName = NULL, BOOL bDelFile = TRUE);
/********************************************************************
函数名称：XStorageCore_DBManage_FileQuery
函数功能：查询文件信息
 参数.一：pppSt_ListFile
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出查询到的文件列表,此函数需要调用基础库的内存释放函数
 参数.二：pInt_ListCount
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出文件个数
 参数.三：lpszTimeStart
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：查找开始时间,20190701
 参数.四：lpszTimeEnd
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：查找结束时间,20190730
 参数.五：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要查询的名称
 参数.六：lpszMD5
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要查询的文件MD5
 参数.七：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要查询的文件的所属用户
返回值
  类型：逻辑型
  意思：是否成功
备注：返回假可能没有查找到,这条记录不存在.参数lpszFile和lpszMD5不能全为空
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_FileQuery(XSTORAGECORE_DBFILE * **pppSt_ListFile, int* pInt_ListCount, LPCSTR lpszTimeStart = NULL, LPCSTR lpszTimeEnd = NULL, LPCSTR lpszFile = NULL, LPCSTR lpszMD5 = NULL, LPCSTR lpszUser = NULL);
/********************************************************************
函数名称：XStorageCore_DBManage_FileQueryForTable
函数功能：通过指定表名称查询所有文件
 参数.一：pppSt_ListFile
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出查询到的文件信息
 参数.二：pInt_ListCount
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的列表个数
 参数.三：lpszTableName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查询的表名称
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一需要调用基础库的内存释放函数进行释放内存
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_FileQueryForTable(XSTORAGECORE_DBFILE * **pppSt_ListFile, int* pInt_ListCount, LPCSTR lpszTableName);
/********************************************************************
函数名称：XStorageCore_DBManage_FileQueryForMD5
函数功能：通过MD5查询文件信息
 参数.一：pSt_FileInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出查询到的文件信息
 参数.二：lpszFileMD5
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查询的文件MD5
 参数.三：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入文件所属用户
 参数.四：lpszTimeStart
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入开始时间
 参数.五：lpszTimeEnd
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入结束时间
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_FileQueryForMD5(XSTORAGECORE_DBFILE* pSt_FileInfo, LPCSTR lpszFileMD5, LPCSTR lpszUser = NULL, LPCSTR lpszTimeStart = NULL, LPCSTR lpszTimeEnd = NULL);
/********************************************************************
函数名称：XStorageCore_DBManage_FileGetCount
函数功能：获取数据库中文件总个数和总大小
 参数.一：pInt_Count
  In/Out：Out
  类型：64位整数型指针
  可空：N
  意思：导出获取到的文件个数
 参数.二：pInt_Size
  In/Out：Out
  类型：64位整数型指针
  可空：N
  意思：导出获取到的文件大小,单位字节(BYTE)
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_FileGetCount(__int64x *pInt_Count, __int64x *pInt_Size);
/********************************************************************
函数名称：XStorageCore_DBManage_DirInsert
函数功能：插入一个文件夹
 参数.一：pSt_DirInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入文件夹信息
返回值
  类型：逻辑型
  意思：是否成功
备注：加入一个新的文件夹到存储服务中,每个新用户都需要单独对应一个文件夹
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_DirInsert(XSTORAGECORE_DIRINFO *pSt_DirInfo);
/********************************************************************
函数名称：XStorageCore_DBManage_DirDelete
函数功能：删除一个绑定的文件夹
 参数.一：lpszUserDir
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要删除的用户
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_DirDelete(LPCSTR lpszUserDir);
/********************************************************************
函数名称：XStorageCore_DBManage_DirQuery
函数功能：查询一个目录是否存在我们的数据库中
 参数.一：pSt_DirInfo
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：填充主备份目录,输出其他属性
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_DirQuery(XSTORAGECORE_DIRINFO *pSt_DirInfo);
/********************************************************************
函数名称：XStorageCore_DBManage_DirQueryAll
函数功能：查询所有文件夹属性
 参数.一：pppSt_ListDir
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出文件夹列表
 参数.二：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一需要调用基础库的内存释放函数BaseLib_OperatorMemory_Free进行释放内存
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_DirQueryAll(XSTORAGECORE_DIRINFO * **pppSt_ListDir, int* pInt_ListCount);
/********************************************************************
函数名称：XStorageCore_DBManage_UserInsert
函数功能：用户插入
 参数.一：pSt_DBUser
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要插入的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_UserInsert(XSTORAGECORE_USERINFO *pSt_DBUser);
/********************************************************************
函数名称：XStorageCore_DBManage_UserInsert
函数功能：用户删除
 参数.一：pSt_DBUser
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要删除的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_UserDelete(XSTORAGECORE_USERINFO *pSt_DBUser);
/********************************************************************
函数名称：XStorageCore_DBManage_UserQuery
函数功能：用户查询
 参数.一：pSt_DBUser
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：要查询的信息,输入的用户名不能为空,导出相关信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_UserQuery(XSTORAGECORE_USERINFO *pSt_DBUser);
/********************************************************************
函数名称：XStorageCore_DBManage_UserDBFileSet
函数功能：设置用户文件信息数据
 参数.一：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入
 参数.二：nFileSize
  In/Out：In
  类型：整数型
  可空：N
  意思：输入文件大小
 参数.三：bDel
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：删除还是增加
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_UserDBFileSet(LPCSTR lpszUserName, __int64x nFileSize, BOOL bDel = FALSE);
/********************************************************************
函数名称：XStorageCore_DBManage_UserQueryForToken
函数功能：通过TOKEN查询用户信息
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要查询的TOKEN
 参数.二：pSt_DBUser
  In/Out：In/Out
  类型：数据结构指针
  可空：N
  意思：要查询的信息,输入的用户名不能为空,导出相关信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_UserQueryForToken(XNETHANDLE xhToken, XSTORAGECORE_USERINFO* pSt_DBUser);
/********************************************************************
函数名称：XStorageCore_DBManage_UserSet
函数功能：用户表设置
 参数.一：lpszUser
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的用户名
 参数.二：xhToken
  In/Out：In
  类型：句柄
  可空：Y
  意思：输入用户创建的句柄
 参数.三：nStatus
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入状态,0不在线,1在线
 参数.四：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入IP地址
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_DBManage_UserSet(LPCSTR lpszUser, XNETHANDLE xhToken = 0, int nStatus = 0, LPCSTR lpszClientAddr = NULL);
/************************************************************************/
/*                         导出的会话管理操作函数                       */
/************************************************************************/
/********************************************************************
函数名称：XStorageCore_Session_Insert
函数功能：插入一个用户到会话管理器中
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：用户地址
 参数.二：pSt_ProtocolUser
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：用户的登录信息
 参数.三：pSt_UserInfo
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：用户的数据信息
 参数.四：pxhToken
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出创建的网络句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_Session_Insert(LPCSTR lpszClientAddr, XENGINE_PROTOCOL_USERAUTH *pSt_ProtocolUser, XSTORAGECORE_USERINFO *pSt_UserInfo, XNETHANDLE *pxhToken = NULL);
/********************************************************************
函数名称：XStorageCore_Session_Delete
函数功能：从会话管理器中删除一个客户端
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
extern "C" BOOL XStorageCore_Session_Delete(LPCSTR lpszClientAddr);
/********************************************************************
函数名称：XStorageCore_Session_GetForAddr
函数功能：通过IP地址查找对应的用户信息
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查找的地址信息
 参数.二：pSt_UserInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出查找到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_Session_GetForAddr(LPCSTR lpszClientAddr, XSTORAGECORE_USERINFO *pSt_UserInfo);
/********************************************************************
函数名称：XStorageCore_Session_GetForUser
函数功能：通过用户名查找对应信息
 参数.一：lpszClientAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要查找的用户名
 参数.二：pSt_UserInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：输出查找到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_Session_GetForUser(LPCSTR lpszUserName, XSTORAGECORE_USERINFO *pSt_UserInfo);
/********************************************************************
函数名称：XStorageCore_Session_GetForToken
函数功能：通过TOKEN获取对应的信息
 参数.一：xhToken
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要操作的TOKEN
 参数.二：pSt_UserInfo
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出查找到的信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL XStorageCore_Session_GetForToken(XNETHANDLE xhToken, XSTORAGECORE_USERINFO *pSt_UserInfo);
