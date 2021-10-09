[中文](README.md) ||  [English](README.en.md)  
# XEngine
网络开发包,网络通信引擎,网络通信中间件

## 当前版本
V7.22.0.1001

## 项目介绍
XEngine是基于C/C++开发的一套网络通信开发框架,它是一套跨平台稳定可靠的网络开发框架。你可以在这套框架上面快速的开发部署你的网络应用程序环境。此引擎不光封装了高性能API函数，还封装了底层网络IO和网络应用与协议相关接口，你可以使用此SDK快速部署与开发大型或者中小型应用服务器以及其他与网络和通信相关的应用程序。  
你可以使用这套SDK,开发你想要的任何网络与通信程序或服务,包括不限于:聊天服务,视频会议,语音会议,文件服务,远程监控,日志服务,HTTP服务,代理服务,数据转发服务,消息服务,安全验证,流媒体服务,音视频编解码,P2P等等相关工具和服务的开发。  
XEngine是关于网络通信和后台服务器相关的一整套开发套件,他提供了整个后台服务生命周期的开发库.他为你解决了从网络IO层到应用层的一系列复杂的问题,包括性能问题  

## 软件目标
学会这套开发通信引擎后,在你以后工作学习中,你会发现开发网络通信相关的应用程序非常轻松愉快.它几乎包含了所有网络通信相关的API函数封装.  
此开发包统一使用了C方式的导出,模块间函数可以独立使用,也可以全部使用.你可以根据自己需要选择使用的模块.  
现在,开始学习这套引擎吧...  

## 部署环境
我们建议你使用git工具下载和更新  
China:git clone https://gitee.com/xyry/libxengine.git  
Other regions:git clone https://github.com/libxengine/xengine.git  

#### Windows
下载完毕后,你可以直接运行主目录下的XEngine_WINEnv.bat文件  
执行成功后会在你的系统中添加此目录的用户环境变量  
在你的项目,属性,VC++目录 的包含目录添加$(XEngine_Include)库目录添加$(XEngine_Library)

#### Linux
直接在终端运行 sudo ./XEngine_LINEnv.sh -i 3 即可  
此脚本可以单独运行  

## 系统说明
网盘下载的版本不包含音视频编解码和流媒体功能模块.你可以通过我们的git上面下载完整版本或者第三方依赖的ffmpeg库  
加载头文件:  
#include <系统头文件.h>  
#include <XEngine_CommHdr.h>  
#include <XEngine_Types.h>        //LNIUX需要  
#include <XEngine_ProtocolHdr.h>  //可能需要  
#include <XEngine_Include/组件目录/模块名称_Define.h>  
#include <XEngine_Include/组件目录/模块名称_Error.h>  
#include <你的头文件>  

### Windows  
发布的版本有64和32位,你可以根据需要加载,这两个版本不可以通用,我们发布的SDK现在是基于ANSI的字符编码  
WINDOWS下使用我们的库的时候,你需要手动启用	WSAStartup(MAKEWORD(2,2),&st_WSAData); WSAClean() 这个函数才能使用我们的网络库  
### Linux  
LINUX:只支持BIT64位系统。我们提供了环境运行安装脚本，如果在你的系统中运行，安装脚本是基于Centos 8_x64和Ubuntu20.04_x64 位编写。我们的软件支持RedHat,Centos,Ubuntu和Debian，如果你不是使用的这些系统，那么你需要自己查看我们的依赖库并且安装，只要是64位即可。在此：我们建议你使用Centos8或者Ubuntu20.04以上的系统。默认安装脚本只会安装头文件，如果你想要把共享库一起安装到头文件中，你可以通过安装脚本 -h 参数查看安装方法.注意:UBUNTU(DEBIAN)和CENTOS(REDHAT)核心是分开的,目前无法同时兼容,将会在以后解决这些问题.  

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
 * XEngine_Include         头文件目录  
    *    --XEngine_CommHdr.h      公用头文件(可能需要优先加载)  
    *    --XEngine_Types.h        跨平台函数转换定义头文件  
    *    --XEngine_ProtocolHdr.h  协议头文件  
    *    --XEngine_*              组件头文件目录  


## 加入开发

目前代码并没有完全开放,只提供内部成员使用.  
想要加入开发,你需要先申请.经过考核后才能加入... 

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