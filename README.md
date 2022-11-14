[中文](README.md) ||  [English](README.en.md)  
# XEngine
网络开发包,网络通信引擎,网络通信中间件,网络通信开发框架

## 当前版本
V7.44.0.1001  

## 注意
你应该先阅读README.md(English:README.en.md) .如果可以,请阅读XEngine_Docment/开发人员必读.docx  
建议使用宋体,阅读更新历史  
更多内容,请访问我们的网站:www.xyry.org  

## 项目介绍
XEngine是基于C/C++开发的一套网络通信开发框架,它是一套跨平台(支持Windows,Linux,Mac,Android,IOS)稳定可靠的网络开发框架。你可以在这套框架上面快速的开发部署你的网络应用程序环境。此引擎不光封装了高性能API函数，还封装了底层网络IO和网络应用与协议相关接口，你可以使用此SDK快速部署与开发大型或者中小型应用服务器以及其他与网络和通信相关的应用程序。  
你可以使用这套SDK,开发你想要的任何网络与通信程序或服务,包括不限于:聊天服务,视频会议,语音会议,文件服务,远程监控,日志服务,HTTP服务,代理服务,数据转发服务,消息服务,安全验证,流媒体服务,音视频编解码,P2P等等相关工具和服务的开发。  
XEngine是关于网络通信和后台服务器相关的一整套开发套件,他提供了整个后台服务生命周期的开发库.他为你解决了从网络IO层到应用层的一系列复杂的问题,包括性能问题  
XEngine拥有一整套完整的线程池模型(从网络IO到业务处理),而不是市面上的伪线程池模型,也不需要莫名其妙的协程,你可以真正实现一套高性服务器.  

## 软件目标
学会这套开发通信引擎后,在你以后工作学习中,你会发现开发网络通信相关的应用程序非常轻松愉快.它几乎包含了所有网络通信相关的API函数封装.  
此开发包统一使用了C方式的导出,模块间函数可以独立使用,也可以全部使用.你可以根据自己需要选择使用的模块.  
我们有完善的技术支持,你有任何问题都可以向我们提问,我们会为你提供尽所能及的帮助  
你甚至可以用我们这套SDK不调用任何系统API就可以开发一套大型的服务器  
现在,开始学习这套引擎吧...  

## 部署环境
我们建议你使用git工具下载和更新(windows可以使用TortoiseGit)  
git clone https://gitee.com/xyry/libxengine.git  
git clone https://github.com/libxengine/xengine.git  

#### Windows
下载完毕后,你可以直接运行主目录下的XEngine_WINEnv.bat文件  
执行成功后会在你的系统中添加此目录的用户环境变量  
在你的项目,属性,VC++目录 的包含目录添加 $(XEngine_Include)库目录添加 $(XEngine_Library) 或者x86添加: $(XEngine_Lib32),x64添加: $(XEngine_Lib64)  
注意:x86版本将在V8版本后被移除,请尽量使用X64.
###### 更新引擎
直接使用git拉取,git pull 即可.

#### Linux
打开终端  
cd libxengine  
chmod 777 *  
sudo ./XEngine_LINEnv.sh -i 3  
此脚本可以单独运行  
###### 更新引擎
终端使用git更新:git pull origin master  
成功后执行命令:sudo ./XEngine_LINEnv.sh -b -i 3  

#### MacOS
先决条件.安装homebrew    
打开终端,执行./XEngine_LINEnv.sh 如果已经安装过只是升级可以使用 ./XEngine_LINEnv.sh -b -i 3  
此脚本可以单独运行  
###### 更新引擎
终端使用git更新:git pull origin master  
成功后执行命令:sudo ./XEngine_LINEnv.sh -b -i 3  

## 使用说明
加载头文件:  
#include <pch.h>                  //预编译,WINDOWS可能需要  
#include <系统头文件.h>  
using namespace 名词空间;          //C++名词空间  
#include <XEngine_CommHdr.h>  
#include <XEngine_ProtocolHdr.h>  //可能需要  
#include <XEngine_Include/组件目录/模块名称_Define.h>  
#include <XEngine_Include/组件目录/模块名称_Error.h>  
#include <你的头文件>  
如果遇到某些宏定义重复,请注意你的宏定义加载是否正常或者你的头文件是否加载正确,或者你可以删除我们的重复的宏定义.  

### Windows  
WINDOWS下使用我们的库的时候,你需要在你应用程序初始化的时候手动启用WSAStartup(MAKEWORD(2,2),&st_WSAData); 应用程序销毁的时候启用WSAClean() 这个函数才能使用我们的网络库  
连接到库,比如基础库:#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseLib")  

#### 运行时库
我们发布的软件都使用的是MD编译.需要VS2022的运行时库  
大多数时候系统中已经安装运行库了,如果没有，那么我们建议你安装。  
x86(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x86.exe  
X64(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x64.exe  

### Linux  
LINUX:只支持BIT64位系统。我们提供了环境运行安装脚本，如果在你的系统中运行，安装脚本是基于Centos 8_x64和Ubuntu20.04_x64 位编写。我们的软件支持RedHat,Centos,Ubuntu和Debian，如果你不是使用的这些系统，那么你需要自己查看我们的依赖库并且安装，只要是64位即可。在此：我们建议你使用Centos8或者Ubuntu20.04以上的系统。你可以通过安装脚本 -h 参数查看安装方法.注意:UBUNTU(DEBIAN)和CENTOS(REDHAT)核心是分开的,目前无法同时兼容.  
连接到库,比如基础库:-L ../../../XEngine/XEngine_Release/XEngine_Linux/Ubuntu/XEngine_BaseLib -lXEngine_BaseLib  

### MacOS  
MacOS需要12以及以上的系统,只支持64位系统,安装方式同LINUX,你可以通过安装脚本 -h 参数查看安装方法  
MacOS链接库(dylib)可以直接放到和程序一样的目录下运行,而不是放到系统目录.具体可以根据你的使用方式决定  

## 目录结构

*libxengine            SDK发布文件夹
 * XEngine_Windows          WINDOWS发布版本文件夹,包括lib.dll等  
    *    --x64                    64位DLL发布文件夹  
        *        --XEngine_*              组件目录 包含组件拥有的dll和lib  
    *    --x86                    32位DLL发布文件夹  
        *        同64位  
 * XEngine_Linux           LINUX系统模块发布文件夹  
    *    --Centos                 Centos系统专用发布文件夹  
        *        --XEngine_*             组件模块发布目录  
    *    --Ubuntu                 Ubuntu系统专用发布文件夹  
        *        同Centos位  
 * XEngine_Mac             MacOS系统模块发布文件夹  
    *    --XEngine_*              组件模块发布目录  
 * XEngine_Include         头文件目录  
    *    --XEngine_CommHdr.h      公用头文件  
    *    --XEngine_ProtocolHdr.h  协议头文件  
    *    --XEngine_*              组件头文件目录
  * XEngine_Docment         文档目录  
    *    --SDK服务协议.docx        协议文档
    *    --开发人员必读.docx       系统说明文档 
    *    --开发文档.docx           开发组必读,开发规范  
    *    --结构图                
 * XEngine_LibPath.conf     Linux模块配置文件
 * CONTRIBUTING.md          贡献名单
 * README.en.md             英文必读说明
 * README.md                中文必读
 * XEngine_LINEnv.sh        Linux和MacOS的XEngine安装配置脚本 
 * XEngine_WINEnv.bat       Windows环境XEngine安装配置脚本
 * XEngine_APIDoc.chm       API文档
 * CHANGELOG                最新版本更新说明
 * COPYRIGHT                第三方版权说明
 * HOSTORY                  以往更新历史
 * LICENSE                  XEngine版权说明

### 模块结构
#### 1.XEngine_LibEx
第三方库模块,放在这个下面的模块都是本引擎可能会经常用到的第三方模块.
#### 2.XEngine_AvCoder
编解码组件:用于音频和视频编解码开发和过滤器,转码等操作
##### 2.1 XEngine_AudioCoder
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;音频编解码开发模块
##### 2.2 XEngine_AVCollect
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;音视频采集模块,支持音频,桌面,摄像头采集
##### 2.3 XEngine_AVHelp
音视频开发帮助模块,枚举视频,音频设备和获取支持的编解码器操作等
##### 2.4 XEngine_VideoCoder
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;视频编解码开发模块
##### 2.5 XEngine_AVPlayer
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;播放器模块,可以播放音视频
##### 2.6 XEngine_AVPacket
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;音视频文件格式封装和格式转换模块
#### 3. XEngine_BaseLib
基础组件:包含基本的时间,字符串,算法,文件,事件,句柄等操作
##### 3.1 XEngine_Algorithm
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;算法库开发模块,包含一些常用算法操作API
##### 3.2 XEngine_BaseLib
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;基础模块,包含字符串,事件,句柄,时间,位,配置读写(linux)等操作的API函数集
#### 4. XEngine_Client
客户端组件:包含常规TCP和UDP客户端开发,以及其他高级客户端开发SDK
##### 4.1 XClient_Socket
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;网络客户端开发模块,这个客户端包含TCP,UDP,UDT,SCTP客户端操作,支持高性能,可靠,低延迟,等客户端网络开发API函数.如果不是UDT,SCTP,用户可以不适用这个模块,而自己适用标准SOCKET开发客户端.
##### 4.2 XClient_Ssl
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;网络安全客户端开发模块,通过这个模块可以让你的网络通信进行加密方式传输数据.
#### 5. XEngine_Core
核心组件:包括各种高性能网络服务,高性能线程池和网络相关基础协议开发等
##### 5.1 XEngine_Core
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;网络服务开发模块,里面包含了所有可用服务开发的API接口,是整套引擎的核心模块,你可以在这里面找到TCP,UDP各种高性能开发模型API接口,也可以找到无线通信,红外,蓝牙开发接口,还可以找到其他各种通信方式,广播,组播的开发接口,等等,具体可以查看导出的API说明.
##### 5.2 XEngine_ManagePool
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;管理池模块,这里面包含内存池,线程池,连接池的开发API接口
##### 5.3 XEngine_NetXApi
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;网络API封装接口,IP库,抓包.流量获取等API接口
##### 5.4 XEngine_OpenSsl
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;安全加解密开发模块,包含安全服务API接口和加解密等API接口
##### 5.5 XEngine_Protocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RFC协议开发接口,一些标准的,小型RFC接口定义使用这个模块开发.
##### 5.6 XEngine_WBlackList
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;黑白名单策略模块,可以对IPV4和域名进程过滤和配置策略
#### 7. XEngine_DownLoad
下载组件:用于上传下载协议
##### 7.1 XEngine_DownLoad
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;下载开发接口:包括HTTP和FTP下载和上传开发.
##### 7.2 XEngine_BTorrent
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;用于BT种子下载,制作,解析的模块
#### 8. XEngine_HelpComponents
帮助组件:包括协议组包拆包,二进制组包拆包,解压缩,数据库相关SDK开发
##### 8.1 HelpComponents_BINPack
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;二进制打包解包API工具,可以将多个文件打包成一个文件或者解包成多个文件.
##### 8.2 HelpComponents_Compress
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;解压缩API开发模块
##### 8.3 HelpComponents_DataBase
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;数据库开发模块,支持SQLITE,MYSQL,MSSQL,MARAIDB,POSTPRESQL,MONGODB数据库
##### 8.4 HelpComponents_Packets
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;数据流,组包,解包模块,可以把TCP留组包,或者解包,TCP是流式套接字,必须通过这个模块操作你才能处理一个完成的包,不然你接受数据的时候可能会造成沾包的情况发生.
##### 8.5 HelpComponents_XLog
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;日志模块,可以打印日志,并且保存日志,备份日志.服务器最好使用这个模块来记录日志信息.
##### 8.6 HelpComponents_Authorize
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;授权验证模块,用于本地授权验证和序列卡生成验证
#### 9. XEngine_NetHelp
网络组件:与网络相关的协议与工具开发SDK
##### 9.1 NetHelp_APIHelp
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;网络HTTP客户端开发模块,包含POST,GET等API操作
##### 9.2 NetHelp_StressTest
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;压力测试模块,可以对服务器进行压力测试,包括连接测试,大数据测试等.
#### 10. XEngine_Rfccomponets
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;标准组件:用于RFC标准组织推出的协议所开发的模块.
##### 10.1 RfcComponents_EmailClient
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;电子邮件客户端开发模块,通过这个模块,你可以开发自己的邮件客户端,支持POP,SMTP等协议
##### 10.2 RfcComponents_ProxyProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;代理协议开发接口模块,可以开发代理服务器或者客户端,包括SOCKS5和HTTP隧道道理
##### 10.3 RfcComponents_WSProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;HTTP WEBSOCKET开发接口,支持发送和接受WEBSOCKET协议.
##### 10.4 RfcComponents_SIPProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SIP客户端服务器模块,支持SIP协议操作
##### 10.5 RfcComponents_Snmp
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SNMP协议客户端封装模块,使用此模块快速进行SNMP协议开发
##### 10.6 RfcComponents_NatClient
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NAT客户端模块,用于内网进行穿墙打洞服务
##### 10.7 RfcComponents_HttpServer
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;HTTP服务器开发模块
##### 10.8 RfcComponents_SDPProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDP封包解包开发模块
##### 10.9 RfcComponents_UPNPProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;UPNP操作接口,通过这个模块的API,你可以操作路由器 
##### 10.10 RfcComponents_MQTTProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MQTT协议操作模块,支持协议的解析和封包
#### 11. XEngine_StreamMedia
流媒体组件:用于流媒体协议客户端服务器协议相关开发的接口模块
##### 11.1 StreamMedia_RtspProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RTSP协议处理模块,支持RTSP协议解析和组包
##### 11.2 StreamMedia_RtpProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RTP协议处理模块,支持RTP协议解析和打包
##### 11.3 StreamMedia_RtcpProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RTCP协议处理模块,支持RTCP协议解析和打包
##### 11.4 StreamMedia_HLSProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;HLS直播,录播协议处理与媒体分片模块
##### 11.5 StreamMedia_XClient
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;XClient用于流媒体协议客户端,可支持推流拉流
#### 12. XEngine_SystemSdk
系统组件:用于系统平台相关的SDK开发组件
##### 12.1 XEngine_SystemApi
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;系统模块:封装了大部分操作,进程,线程,网络,界面的API接口操作,还有CPU,内存等信息获取的API接口,具体查看导出的接口定义.
##### 12.2 XEngine_ProcSdk
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ProcFile文件信息读取模块,用于获取linux proc文件系统信息.

## 学习计划
想要使用这套框架,完整的学习到上手可能需要一周时间.  
你可以通过文档了解基础结构,通过查找头文件与全局搜索注释找到想要的功能  

#### 学习方式
如果想要做网络服务通信开发,你需要了解XEngine_Core组件的XEngine_Core模块以及XEngine_Client组件的XClient_Socket模块  
你还可以查看XEngine_HelpComponents组件的HelpComponents_Packets了解如何处理网络包  
更高级的使用可以结合XEngine_HelpComponents组件下的HelpComponents_XLog日志模块与HelpComponents_Database数据库模块使用  
当你熟悉这套框架,你可以使用XEngine_StreamMedia组件开发流媒体或者XEngine_AVCoder开发音视频编解码功能  
你还可以使用XEngine_RfcComponents组件开发一些常用的协议服务,比如HTTP,WEBSOCKET,SIP等等...  

## 加入开发

目前代码并没有完全开放,只提供内部成员使用.  
想要加入开发,你需要先申请.经过审核后可以加入我们的内部开发组获得代码权限... 

## 软件架构

![软件架构图](http://www.xyry.org/EngineFrameWork.png "软件架构图")
![引擎模块图](http://www.xyry.org/EngineRelation.png "引擎模块图")

### 组件结构图
![音视频编解码组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_AVCoder.png "音视频编解码组件结构图")
![基础组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_BaseLib.png "基础组件结构图")
![客户端组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Client.png "客户端组件结构图")
![核心组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Core.png "核心组件结构图")
![帮助组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_HelpComponents.png "帮助组件结构图")
![网络组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_NetHelp.png "网络组件结构图")
![标准组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_RfcComponents.png "标准组件结构图")
![流媒体组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_StreamMedia.png "流媒体组件结构图")
![系统组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_SystemSdk.png "系统组件结构图")