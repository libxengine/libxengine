#pragma once
/********************************************************************
//	Created:	2011/10/17   12:26
//	Filename: 	NetSocketEngine/NetLinuxSdk/LinuxSdk/LinuxSdk_Error.h
//	File Path:	NetSocketEngine/NetLinuxSdk/LinuxSdk/
//	File Base:	LinuxSdk
//	File Ext:	h
//  Project:    血与荣誉网络通信引擎 For Linux
//	Author:		dowflyon
//	Purpose:	LinuxSdk导出错误定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出错误定义
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*           文件操作SDK导出错误                                           */
/************************************************************************/
//枚举文件与文件夹
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ISDIR_PARAMENT 0x150A0001           //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ISDIR_NOTEXIST 0x150A0002           //文件夹不存在
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ISDIR_NOTDIR 0x150A0003             //不是文件夹
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SAVETOBUF_CREATE 0x150A0010         //创建文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_PARAMENT 0x150A0020            //枚举文件失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_CALLRET 0x150A0021             //枚举上层用户返回失败，用户取消枚举
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_ENUM_OPENDIR 0x150A0022             //枚举文件失败，打开目录错误
//创建多级目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_CREATEFOLDER_PARMENT 0x150A0030     //创建目录失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_CREATEFOLDER_MKDIR 0x150A0031       //内部发生了一个错误
//删除多级目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_PARMENT 0x150A0040     //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_ISNOTPATH 0x150A0041   //参数错误，不是一个目录
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_DELETEFOLDER_OPENDIR 0x150A0042     //打开目录失败，可能权限问题
//稀疏文件操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_PARAMENT 0x150A0050      //参数错误,创建稀疏文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_CREATE 0x150A0051        //创建错误,内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_MOVE 0x150A0052          //移动文件指针失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_SPARSEFILE_SET 0x150A0503           //设置为稀疏文件失败
//内容替换
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_PARAMENT 0x150A0060         //参数错误,无法继续替换
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_OPENSRC 0x150A0061          //打开原始文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_OPENDST 0x150A0062          //打开目标文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_MALLOC 0x150A0063           //申请内存空间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_READ 0x150A0064             //读取原始文件数据失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_WRITEHDR 0x150A0065         //写入文件头失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_WRITEREP 0x150A0066         //写入替换文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_FILE_REPLACE_WRITETAIL 0x150A0067        //写入文件尾失败
/************************************************************************/
/*                        系统SDK错误表                                   */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETVER_PARAMENT 0x150A1001        //获取失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETVER_ISFAILED 0x150A1002        //获取失败，系统错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETVER_UNKNOW 0x150A1003          //无法识别的系统版本
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_MEM_PARAMENT 0x150A1010           //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_MEM_GETSYSINFO 0x150A1011         //获取系统信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CPU_PARAMENT 0x150A1020           //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETUPTIME_PARAMENT 0x150A1030     //获取系统启动时间失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETUPTIME_GETLOCLTIME 0x150A1032  //获取本地时间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETCOUNT_PARAMENT 0x150A1040      //获取全局个数失败，参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_GETCOUNT_GETINFO 0x150A1041       //获取全局个数失败，获取信息内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SHUTDOWN_NOTSUPPORT 0x150A1050    //不支持的操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SHUTDOWN_EXEC 0x150A1051          //执行失败，内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_PARAMENT 0x150A1060      //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_SIGN 0x150A1061          //信号处理异常
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_CREATE 0x150A1062        //创建进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CPU_GETCPUFILE 0x150A10F0         //获取CPU状态文件信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_CPU_ISNULL 0x150A10F1             //为空，无法继续
//WINDOWS专用
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_REMOTESD_LOOP 0x150A10A0          //查找远程关机权限失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_REMOTESD_CALLREMOTE 0x150A10A1    //调整远程关机权限失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_REMOTESD_EXECUTIVE 0x150A10A2     //远程关机执行失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_REMOTESD_CONNECT 0x150A10A3       //连接远程主机失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_REMOTESD_OPENTOKEN 0x150A10A4     //打开令牌失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_PARAMENT 0x150A1060      //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_SYSTEMEX_FAILED 0x150A1061        //执行命令失败,可能不存在或者程序返回错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SYSTEM_IDLETIME_GETLASTINPUT 0x150A10B0  //获取系统空闲时间失败
/************************************************************************/
/*                        硬件SDK                                        */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_PARAMENT 0x150A2001    //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_GETDISKSPACE 0x150A2002//获取硬盘空间大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_NOTSUPPORT 0x150A2003  //不支持此返回大小类型
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKINFO_GETOTHER 0x150A2004    //获取其他信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKCOUNT_PARAMENT 0x150A2010   //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKCOUNT_MALLOC 0x150A2011     //申请内存失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_DISKCOUNT_GETMEMORY 0x150A2012  //获取内存大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_CPUINFO_PARAMENT 0x150A2020     //获取CPU信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_PARAMENT 0x160D2030      //参数错误,获取序列号失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_INIT 0x150A2031          //初始化失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_SECURITY 0x150A2032      //安全错误,无法继续
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_CREATE 0x150A2033        //创建失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_CONNECT 0x150A2034       //连接服务失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_SET 0x150A2035           //设置属性失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_GETCPU 0x150A2036        //获取CPU序列号失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_GETBASEBOARD 0x150A203   //获取主板序列号失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_FINDDISK 0x150A2038      //查找硬盘失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_GETDISK 0x150A2039       //获取硬盘序列号失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_GETBIOS 0x150A203A       //获取BIOS失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_HARDWARE_SERIAL_GETMAC 0x150A203B        //获取MAC地址失败
/************************************************************************/
/*                        进程线程错误表                                  */
/************************************************************************/
//线程信息
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_PARAMENT 0x150A3000      //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_OPENTOKEN 0x150A3001     //令牌打开失败，权限错误，或者没有找到
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_PROCESSFIRST 0x150A3002  //跳转进程过程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_OPENPROCESS 0x150A3003   //打开进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_GETMEM 0x150A3004        //获取进程内存信息失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_USERINFO 0x150A3005      //获取所属用户失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_NOTFOUND 0x150A3006      //没有找到进程
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_MALLOC 0x150A3007        //申请内存失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_GETTOKEN 0x150A3008      //获取令牌失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETINFO_GETUSER 0x150A3009       //获取进程关联用户失败
//CPU占用率
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CPUUSAGE_PARAMENT 0x150A3010     //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CPUUSAGE_OPENPROCESS 0x150A3011  //打开进程失败
//进程时间
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETUPTIME_PARAMENT 0x150A3020    //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETUPTIME_OPENPROCESS 0x150A3021 //打开进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETUPTIME_GETTIME 0x150A3022     //获取时间失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_GETUPTIME_FMTSYSTIME 0x150A3023  //格式化时间失败
//进程优先级
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PRIORITY_PARAMENT 0x150A3030     //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PRIORITY_OPENPROCESS 0x150A3031  //打开进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PRIORITY_GETPRIORITY 0x150A3032  //获取优先级失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PRIORITY_SETPRIORITY 0x150A3033  //设置优先级失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_PRIORITY_SETPARAMENT 0x150A3034  //设置优先级失败，参数错误
//进程操作
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_ISEXIST_ENUMPROCESS 0x150A3040   //枚举进程列表失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_ISEXIST_NOTFOUND 0x150A3041      //没有找到进程
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_STOP_ENUMPROCESS 0x150A3050      //结束进程失败,枚举进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_STOP_NOTFOUND 0x150A3051         //没有找到指定进程
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_STOP_NOAUTH 0x150A3052           //没有权限访问此进程
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_STOP_TERMINATE 0x150A3053        //结束失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CREATE_PARAMENT 0x150A3060       //参数错误，创建进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CREATE_ISFAILED 0x150A3061       //内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CREATE_EXEC 0x150A3062           //执行指定文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_RUN_PARAMENT 0x150A3070          //参数错误，创建进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_RUN_ISFAILED 0x150A3071          //内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_RUN_EXEC 0x150A3072              //执行指定文件失败
//进程CPU亲和
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CPUAFFINITY_OPEN 0x150A3070      //打开进程失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CPUAFFINITY_SET 0x150A3071       //设置失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CPUAFFINITY_GET 0x150A3072       //获取失败
//软件自启动
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_PARAMENT 0x150A3080    //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_SYSSTART 0x150A3081    //启动服务失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_SYSENABLE 0x150A3082   //自动启动服务启用失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_SYSSTOP 0x150A3083     //停止服务失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_SYSDISABLE 0x150A3084  //禁用自动启动服务失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_NOTSUPPORT 0x150A3085  //不支持的启动类型
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_GETFILENAME 0x150A3086 //获取自身文件名失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_OPENKEY 0x150A3087     //打开注册表失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_SET 0x150A3088         //设置自启动失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTOSTART_DEL 0x150A3089         //取消自启动失败
//软件自重启
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTORESTART_MALLOC 0x150A3090    //申请内存失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_AUTORESTART_CALLBACK 0x150A3091  //设置失败

#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CMD_PARAMENT 0x150A30A0          //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_PROCESS_CMD_EXEFAILED 0x150A30A1         //执行失败
/************************************************************************/
/*                       窗口界面操作类导出错误                         */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_ADSORPTI_NOTSUPPORT 0x150A4000      //参数不支持
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SETPARENT_PARAMENT 0x150A4010       //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SETPARENT_GETRECT 0x150A4011        //获取窗口大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SETPARENT_CHANGEWINDOW 0x150A4012   //改变窗口大小失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_DITHER_GETRECT 0x150A4030           //获取窗口的矩形失败，可能窗口句柄参数错误 
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTIP_INIT 0x150A4040             //初始化控件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTIP_CREATEWINDOW 0x150A4041     //创建一个提示窗口失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTIP_SETWINDOW 0x150A4042        //设置窗口失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTRAY_PARAMENT 0x150A4043        //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTRAY_GETMODUENAME 0x150A4044    //获取模块名字失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTRAY_GETMODUEHANDLE 0x150A4045  //获取模块句柄失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTRAY_ADD 0x150A4046             //添加托盘提示失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_TOOLTRAY_DEL 0x150A4047             //删除托盘提示失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_HWNDMASK_GETRECT 0x150A4050         //获取窗口矩形失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_GETCURSOR 0x150A4060          //获取鼠标指针失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_GETRECT 0x150A4061            //获取窗口举行失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_BLT 0x150A4062                //转换DC失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_CREATE 0x150A4063             //创建文件失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_WSTBMP 0x150A4064             //位图结构写入失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_WHBMP 0x150A4065              //位图头部写入失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SKIN_SHOTS_WBMP 0x150A4066               //位图数据写入失败
/************************************************************************/
/*                       SPI错误导出表                                  */
/************************************************************************/
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_INSTALL_PARAMENT 0x10AF001            //安装失败,参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_INSTALL_LSPUUID 0x10AF002             //获取LSP UUID失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_INSTALL_LSP 0x10AF003                 //安装LSP失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_INSTALL_GETUUID 0x10AF004             //获取安装的UUID失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_INSTALL_UUID 0x10AF005                //安装UUID失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_INSTALL_WRITEFIRST 0x10AF006          //写入第一条失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_DELETE_PARAMENT 0x10AF010             //参数错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_DELETE_NOTFOUND 0x10AF011             //没有找到协议
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_DELETE_REMOVEPROTO 0x10AF012          //移除协议失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_DELETE_REMOVELAYERED 0x10AF013        //移除协议层失败
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_GETPROTO_GETFAILED 0x10AF021          //获取错误,内部错误
#define ERROR_SYSTEMSDK_SYSTEMAPI_SPI_GETPROVIDER_WSCENUMPROTOCOL 0x10AF030 //枚举WSC协议链失败