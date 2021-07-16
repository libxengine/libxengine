# libXEngine

## 项目介绍
  libXEngine网络通信引擎主要提供了网络与通信引擎和网络中间件开发的SDK，提供了跨平台，稳定可靠的网络通信引擎。你可以在这套引擎上面快速的部署你的网络应用程序环境。此引擎不光封装了高性能API函数，还封装了底层网络IO和网络应用与协议相关接口，你可以使用此SDK快速部署与开发大型或者中小型应用服务器以及其他与网络和通信相关的应用程序。  
  你可以使用这套SDK,开发你想要的任何网络与通信程序或服务,包括不限于:聊天服务,视频会议,语音会议,文件服务,远程监控,日志服务,HTTP服务,代理服务,数据转发服务,消息服务,安全验证,流媒体服务,音视频编解码,P2P等等相关工具和服务的开发。  
  XEngine 让您的网络编程开发工作更加轻松愉快.现在,开始学习这套引擎吧...  

## 软件目标
  学会这套开发通信引擎后,在你以后工作学习中,你会发现开发网络通信相关的应用程序非常轻松愉快,不会在有任何烦恼.它几乎包含了所有网络通信相关的API函数封装.

## 软件架构
![软件架构图](http://www.xyry.org/EngineFrameWork.png "软件架构图")
![引擎模块图](http://www.xyry.org/EngineRelation.png "引擎模块图")

### 组件结构图
![网络验证组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_AuthorizeReg.png "网络验证组件结构图")
![音视频编解码组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_AVCoder.png "音视频编解码组件结构图")
![基础组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_BaseLib.png "基础组件结构图")
![客户端组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Client.png "客户端组件结构图")
![核心组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Core.png "核心组件结构图")
![帮助组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_HelpComponents.png "帮助组件结构图")
![网络组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_NetHelp.png "网络组件结构图")
![插件组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Plugin.png "插件组件结构图")
![标准组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_RfcComponents.png "标准组件结构图")
![存储组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Storage.png "存储组件结构图")
![流媒体组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_StreamMedia.png "流媒体组件结构图")
![系统组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_SystemSdk.png "系统组件结构图")
![更新组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_UPData.png "更新组件结构图")
![下载组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Download.png "更新组件结构图")


## 安装教程

1. 下载本引擎代码
2. 根据系统选择你需要的SDK
3. 直接Include即可

## 系统说明

### Windows  
WINDOWS:发布的版本有64和32位,你可以根据需要加载,这两个版本不可以通用,我们发布的SDK现在是基于ANSI的字符编码  
### Linux  
LINUX:只支持BIT64位系统。我们提供了环境运行安装脚本，如果在你的系统中运行，安装脚本是基于Centos 8_x64和Ubuntu20.04_x64 位编写。我们的软件支持RedHat,Centos,Ubuntu和Debian，如果你不是使用的这些系统，那么你需要自己查看我们的依赖库并且安装，只要是64位即可。在此：我们建议你使用Centos8或者Ubuntu20.04以上的系统。默认安装脚本只会安装头文件，如果你想要把共享库一起安装到头文件中，你可以通过安装脚本 -h 参数查看安装方法.注意:UBUNTU(DEBIAN)和CENTOS(REDHAT)核心是分开的,目前无法同时兼容,将会在以后解决这些问题.  

## 目录结构

*XEngine_Release          SDK发布文件夹
 * XEngine_Windows          WINDOWS发布版本文件夹,包括lib.dll等  
    *    --x64                    64位DLL发布文件夹  
        *        --XEngine_*              组件目录 包含组件拥有的dll和lib  
    *    --x86                    32位DLL发布文件夹  
        *        同64位  
 * XEngine_Linux           LINUX系统模块发布文件夹  
    *    --Centos                Centos系统专用发布文件夹  
        *        --XEngine_*             组件模块发布目录  
    *    --Ubuntu                Ubuntu系统专用发布文件夹  
        *        同64位  
 * NetEngine_Include        头文件目录  
    *    --XEngine_CommHdr.h      公用头文件(可能需要优先加载)  
    *    --XEngine_Types.h        跨平台函数转换定义头文件  
    *    --XEngine_ProtocolHdr.h  协议头文件  
    *    --XEngine_*            组件头文件目录  


## 注意说明

WINDOWS:发布的版本有64和32位,你可以根据需要加载,这两个版本不可以通用,我们发布的SDK现在是基于ANSI的字符编码  
LINUX:只支持BIT64位系统。我们提供了环境运行安装脚本，如果在你的系统中运行，安装脚本是基于Centos 8_x64和Ubuntu20.04_x64 位编写。我们的软件支持 RedHat,Centos,Ubuntu和Debian，如果你不是使用的这些系统，那么你需要自己查看我们的依赖库并且安装，只要是64位即可。在此：我们建议你使用Centos8或者Ubuntu20.04以上的系统。默认安装脚本只会安装头文件，如果你想要把共享库一起安装到头文件中，你可以通过安装脚本 -h 参数查看安装方法.注意:UBUNTU(DEBIAN)和CENTOS(REDHAT)核心是分开的,目前无法同时兼容,将会在以后解决这些问题.

## 加入开发

目前代码并没有完全开放,只提供内部成员使用.  
想要加入开发,你需要阅读开发文档和协议文档,运行执行例子.  
查看了解每个模块功能和导出函数,对每个模块功能有个大致的了解.然后写一些测试用例.了解整个引擎运行机制  
你需要先申请.经过验证,会把你加入到开发成员中...  