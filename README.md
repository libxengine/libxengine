[中文](README.md) ||  [English](README.en.md)  
# XEngine
网络开发包,网络通信引擎,网络通信中间件,网络通信开发框架

## 当前版本
V7.37.0.1001  

## 注意
你应该先阅读README.md(English:README.en.md) .如果可以,请阅读XEngine_Docment/开发人员必读.docx  
建议使用宋体,阅读更新历史  
更多内容,请访问我们的网站:www.xyry.org  

## 项目介绍
XEngine是基于C/C++开发的一套网络通信开发框架,它是一套跨平台(支持Windows,Linux,Mac,Android,IOS)稳定可靠的网络开发框架。你可以在这套框架上面快速的开发部署你的网络应用程序环境。此引擎不光封装了高性能API函数，还封装了底层网络IO和网络应用与协议相关接口，你可以使用此SDK快速部署与开发大型或者中小型应用服务器以及其他与网络和通信相关的应用程序。  
你可以使用这套SDK,开发你想要的任何网络与通信程序或服务,包括不限于:聊天服务,视频会议,语音会议,文件服务,远程监控,日志服务,HTTP服务,代理服务,数据转发服务,消息服务,安全验证,流媒体服务,音视频编解码,P2P等等相关工具和服务的开发。  
XEngine是关于网络通信和后台服务器相关的一整套开发套件,他提供了整个后台服务生命周期的开发库.他为你解决了从网络IO层到应用层的一系列复杂的问题,包括性能问题  

## 软件目标
学会这套开发通信引擎后,在你以后工作学习中,你会发现开发网络通信相关的应用程序非常轻松愉快.它几乎包含了所有网络通信相关的API函数封装.  
此开发包统一使用了C方式的导出,模块间函数可以独立使用,也可以全部使用.你可以根据自己需要选择使用的模块.  
我们有完善的技术支持,你有任何问题都可以向我们提问,我们会为你提供尽所能及的帮助  
现在,开始学习这套引擎吧...  

## 部署环境
我们建议你使用git工具下载和更新  
git clone https://gitee.com/xyry/libxengine.git  
git clone https://github.com/libxengine/xengine.git  

#### Windows
下载完毕后,你可以直接运行主目录下的XEngine_WINEnv.bat文件  
执行成功后会在你的系统中添加此目录的用户环境变量  
在你的项目,属性,VC++目录 的包含目录添加\$(XEngine_Include)库目录添加\$(XEngine_Library) 或者x86添加:\$(XEngine_Lib32),x64添加:\$(XEngine_Lib64)  
注意:x86版本将在V8版本后被移除,请尽量使用X64.

#### Linux
打开终端  
cd libxengine  
chmod 777 *  
sudo ./XEngine_LINEnv.sh -i 3  
此脚本可以单独运行  

#### MacOS
先决条件.安装homebrew    
打开终端,执行./XEngine_LINEnv.sh  
此脚本可以单独运行  

## 使用说明
加载头文件:  
#include <pch.h>                  //预编译,WINDOWS可能需要  
#include <系统头文件.h>  
using namespace 名词空间;          //C++名词空间  
#include <XEngine_CommHdr.h>  
#include <XEngine_Types.h>        //非WINDOWS系统需要  
#include <XEngine_ProtocolHdr.h>  //可能需要  
#include <XEngine_Include/组件目录/模块名称_Define.h>  
#include <XEngine_Include/组件目录/模块名称_Error.h>  
#include <你的头文件>  
如果遇到某些宏定义重复,请注意你的宏定义加载是否正常或者你的头文件是否加载正确,或者你可以删除我们的重复的宏定义.  

### Windows  
发布的版本有64和32位,你可以根据需要加载,这两个版本不可以通用,我们发布的SDK现在是基于ANSI的字符编码,暂时不提供UNICODE编码，你如果是UNICODE程序，可以自己转换成UNICODE编码。  
注意:如果你在使用UNICODE编码编写程序的时候发现我们的导出函数是UNICODE样式的(WCHAR TCHAR LPCTSTR LPWSTR等).你可以自己把这个类型改成ANSI格式的类型.不然会出错!
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
    *    --XEngine_Types.h        跨平台函数转换定义头文件  
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
 * CHANGELOG                最新版本更新说明
 * COPYRIGHT                第三方版权说明
 * HOSTORY                  以往更新历史
 * LICENSE                  XEngine版权说明

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