# XEngine

## Description
  XEngine-Toolkit network communication engine mainly provides SDK for network and communication and network middleware development. It is a cross-platform, stable and reliable network communication engine. You can quickly deploy your application environment on this engine. This engine not only encapsulates high-performance API functions, but also encapsulates the underlying network IO and network application and protocol-related interfaces. You can use this SDK to quickly deploy and develop large or small and medium-sized application servers and other network and communication-related applications  
  You can use this SDK to develop any network and communication programs or services you want, including but not limited to: chat service, video conference, voice conference, file service, remote monitoring, log service, HTTP service, proxy service, data forwarding Services, messaging services, security verification, streaming media services, audio and video codec, P2P and other related tools and services development  
  XEngine makes your network programming and development work easier and more enjoyable. Now, start learning this engine...  

## Software goals
  After learning this set of development communication engine, in your future work and study, you will find that the development of network communication-related applications is very easy and happy, and there will be no troubles. It almost contains all the API function packages related to network communication.

## Software Architecture
![软件架构图](http://www.xyry.org/EngineFrameWork.png "软件架构图")
![引擎模块图](http://www.xyry.org/EngineRelation.png "引擎模块图")

### components struct picture 
![网络验证组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_AuthorizeReg.png "网络验证组件结构图")
![音视频编解码组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_AVCoder.png "音视频编解码组件结构图")
![基础组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_BaseLib.png "基础组件结构图")
![客户端组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Client.png "客户端组件结构图")
![核心组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Core.png "核心组件结构图")
![帮助组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_HelpComponents.png "帮助组件结构图")
![消息组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_MQCore.png "消息组件结构图")
![网络组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_NetHelp.png "网络组件结构图")
![插件组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Plugin.png "插件组件结构图")
![标准组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_RfcComponents.png "标准组件结构图")
![流媒体组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_StreamMedia.png "流媒体组件结构图")
![系统组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_SystemSdk.png "系统组件结构图")
![更新组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_UPData.png "更新组件结构图")
![下载组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Download.png "更新组件结构图")

## Installation

1. download the engine  
2. select you sdk by system  
3. configure system enviroment  
4. include header and developer  

## System Version

### Windows  
WINDOWS:release version has 32bit and 64bit,You can load as needed,These two versions cannot be used in common, the SDK we released is now based on ANSI character encoding  

### Linux  
LINUX:Only supports BIT64 bit system. We provide an environment to run the installation script, the installation script is based on Centos 8_x64 and Ubuntu20.04_x64. Our software supports RedHat, Centos, Ubuntu and Debian. If you are not using these systems, then you need to check our dependent libraries and install them, Here: We recommend that you use Centos8 or Ubuntu20.04 or higher. The default installation script will only install the header files. If you want to install the shared library into the header files together, you can view the installation method through the -h parameter of the installation script. Note: UBUNTU (DEBIAN) and CENTOS (REDHAT) cores are separate, It is currently not compatible at the same time, and these problems will be solved in the future  

## Directory Structure

*XEngine_Release          SDK Release dir
 * XEngine_Windows          WINDOWS Release version folder  
    *    --x64                    64bit DLL  
        *        --XEngine_*              Components folder,include dll and lib...  
    *    --x86                    32bit DLL  
        *        same to 64bit  
 * XEngine_Linux           LINUX release version folder  
    *    --Centos                Centos System Version  
        *        --XEngine_*              Components folder,include so file  
    *    --Ubuntu                Ubuntu System Version  
        *        same to centos  
 * NetEngine_Include        Header Folder  
    *    --XEngine_CommHdr.h      Public header file(may need to include first)  
    *    --XEngine_Types.h        Cross-platform function conversion definition header file  
    *    --XEngine_ProtocolHdr.h  protocol header  
    *    --XEngine_*            Components Header  

## Note

   You can find the required component directory according to the directory structure, and then find the module header file, copy it to your development project and use it. For specific use, you can refer to our example or contact our official forum for inquiries  
   When using our library under WINDOWS, you need to manually enable WSAStartup(MAKEWORD(2,2),&st_WSAData); WSAClean() This function can use our network library. At some point, you need to define the _WINDOWS macro definition. To use our code normally  

## question
  if you have question,you can post issuse...

## Join us

Not fully open, only available to internal members.  
To join development, you need to read the development document and agreement document, and run the implementation example.  
Check and understand each module function and export function, and have a general understanding of each module function. Then write some test cases. Understand the entire engine operating mechanism  
You need to apply first. After verification, you will be added to the development member...  