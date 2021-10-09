[中文](README.md) ||  [English](README.en.md) 
# XEngine
Network development kit, network communication engine, network communication middleware

## Now Version is
V7.22.0.1001

## Description
XEngine is a network communication development framework based on C/C++ development, it is a cross-platform stable and reliable network development framework. You can quickly deploy your application environment on this engine. This engine not only encapsulates high-performance API functions, but also encapsulates the underlying network IO and network application and protocol-related interfaces. You can use this SDK to quickly deploy and develop large or small and medium-sized application servers and other network and communication-related applications  
You can use this SDK to develop any network and communication programs or services you want, including but not limited to: chat service, video conference, voice conference, file service, remote monitoring, log service, HTTP service, proxy service, data forwarding Services, messaging services, security verification, streaming media services, audio and video codec, P2P and other related tools and services development  
XEngine is a complete set of development kits related to network communication and backend servers.He provides a development library for the entire back-end service life cycle,He solves a series of complex problems from the network IO layer to the application layer, including performance problems  

## Software goals
After learning this set of development communication engine, in your future work and study, you will find that the development of network communication-related applications is very easy and happy, and there will be no troubles. It almost contains all the API function packages related to network communication.  
This development kit uses the export of C mode uniformly, and the functions between modules can be used independently or all. You can choose the module to use according to your needs.  
Now, let's start learning this engine...  

## Deployment environment
We recommend you to use git tool download and update  
China:git clone https://gitee.com/xyry/libxengine.git  
Other regions:git clone https://github.com/libxengine/xengine.git  

#### Windows
After the download is complete, you can directly run the XEngine_WINEnv.bat file in the home directory  
After the execution is successful, the user environment variable of this directory will be added to your system  
Add $(XEngine_Include) to the include directory of your project of properties of VC++ directory, add $(XEngine_Library) to the library directory  

#### Linux
Run command sudo ./XEngine_LINEnv.sh -i 3 in the terminal  
the script can be run by self  

## System Version
The version downloaded from the network disk does not include audio and video codec and streaming media function modules. You can download the full version through our git or the third-party dependent ffmpeg library  
load header file:  
#include <system header.h>  
#include <XEngine_CommHdr.h>  
#include <XEngine_Types.h>        //linux need  
#include <XEngine_ProtocolHdr.h>  //maybe need  
#include <XEngine_Include/components dir/moduename_Define.h>  
#include <XEngine_Include/components dir/moduename_Error.h>  
#include <your header file>  

### Windows  
WINDOWS:release version has 32bit and 64bit,You can load as needed,These two versions cannot be used in common, the SDK we released is now based on ANSI character encoding  

### Linux  
LINUX:Only supports BIT64 bit system. We provide an environment to run the installation script, the installation script is based on Centos 8_x64 and Ubuntu20.04_x64. Our software supports RedHat, Centos, Ubuntu and Debian. If you are not using these systems, then you need to check our dependent libraries and install them, Here: We recommend that you use Centos8 or Ubuntu20.04 or higher. The default installation script will only install the header files. If you want to install the shared library into the header files together, you can view the installation method through the -h parameter of the installation script. Note: UBUNTU (DEBIAN) and CENTOS (REDHAT) cores are separate, It is currently not compatible at the same time, and these problems will be solved in the future  

## Directory Structure

*libxengine            SDK Release dir
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
 * XEngine_Include         Header Folder  
    *    --XEngine_CommHdr.h      Public header file(may need to include first)  
    *    --XEngine_Types.h        Cross-platform function conversion definition header file  
    *    --XEngine_ProtocolHdr.h  protocol header  
    *    --XEngine_*              Components Header  

## Join us

Not fully open, only available to internal members.  
To join the development, you need to apply first. You can join after the assessment  

## Software Architecture
![软件架构图](http://www.xyry.org/EngineFrameWork.png "软件架构图")
![引擎模块图](http://www.xyry.org/EngineRelation.png "引擎模块图")

### components struct picture 
![音视频编解码组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_AVCoder.png "音视频编解码组件结构图")
![基础组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_BaseLib.png "基础组件结构图")
![客户端组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Client.png "客户端组件结构图")
![核心组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_Core.png "核心组件结构图")
![帮助组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_HelpComponents.png "帮助组件结构图")
![网络组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_NetHelp.png "网络组件结构图")
![标准组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_RfcComponents.png "标准组件结构图")
![流媒体组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_StreamMedia.png "流媒体组件结构图")
![系统组件结构图](http://www.xyry.org/XEngine_StructPic/XEngine_SystemSdk.png "系统组件结构图")