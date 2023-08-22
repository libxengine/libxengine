[中文](README.md) ||  [English](README.en.md) 
# XEngine
Network development kit, network communication engine, network communication middleware,Network communication development framework

## Now Version is
V8.16.0.1001

## Note  
You should read README.md(English:README.en.md) first. If you can, please read XEngine_Docment/开发人员必读.docx  
It is recommended to use Arial, read the update history  
For more content,please visit our website: www.xyry.org  

## Description
XEngine is a cross-platform (support Windows, Linux, Mac, Android, IOS) network communication development framework based on C/C++.It provides 42 modules (SO, DLL, DYLIB) and thousands of API functions for you to call,You can quickly develop and deploy your web application environment on top of this framework. This engine not only encapsulates high-performance API functions, but also encapsulates the underlying network IO and network application and protocol-related interfaces, which you can use to quickly deploy and develop large or medium-sized application servers and other network and communication-related applications. He is a complete development kit related to network communication and back-end servers, and he provides development libraries for the entire back-end service lifecycle. He solves a range of complex problems, including performance issues, from the network IO layer to the application layer  
You can use this SDK to develop any network and communication program or service you want, including but not limited to: chat service, video conference, voice conference, file service, remote monitoring, log service, HTTP service, proxy service, data forwarding service, message service, security verification, streaming media service, audio and video codec, P2P and other related tools and services development  
XEngine has a complete set of thread pool models (from network IO to business processing), instead of the pseudo-thread pool model on the market, and there is no need for inexplicable coroutines, you can really implement a set of high-performance servers  

## Software goals
After learning this set of development communication engine, in your future work and study, you will find that the development of network communication-related applications is very easy and happy, and there will be no troubles. It almost contains all the API function packages related to network communication.  
This development kit uses the export of C interface, and the functions between modules can be used independently or all. You can choose the module to use according to your needs.  
You can even use our SDK to develop a server without any system API  
Now, let's start learning this engine...  

## Deployment environment
We recommend you to use git tool download and update(windows can use TortoiseGit),only english path  
git clone https://gitee.com/xyry/libxengine.git  
git clone https://github.com/libxengine/xengine.git  

#### Windows
After the download is complete, you can directly run the XEngine_WINEnv.bat file in the home directory  
After the execution is successful, the user environment variable of this directory will be added to your system  
Take Visual Studio as an example, add in your project->properties->VC++ directory->include directory $(XEngine_Include) header file environment  
add $(XEngine_Lib32) to the library directory for x86 arch  
add $(XEngine_Lib64) for x64 arch  
###### how to use
When using our library under WINDOWS, you need to enable WSAStartup(MAKEWORD(2,2),&st_WSAData) when you program start and use WSAClean() when your program destory to use our network library  
link to the library,sush as base library:#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseLib")  
###### Runtime library
The software we release is compiled using MD. The runtime library of VS2022 is required  
Most of the time, the runtime library is already installed on the system, if not, then we recommend that you install it  
x86(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x86.exe  
X64(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x64.exe  
###### UPDate
Use git to pull directly  

#### Linux
Only supports BIT64 bit system. We provide an environment to run the installation script, the installation script is based on RockyLinux 9_x64 and Ubuntu22.04_x64. Our software supports RockyLinux,RedHat, Centos, Ubuntu and Debian. If you are not using these systems, then you need to check our dependent libraries and install them, you can view the installation method through the -h parameter of the installation script. Note: UBUNTU (DEBIAN) and RockyLinux (REDHAT) cores are separate, It is currently not compatible.
###### how to use
open terminal  
cd libxengine  
chmod 777 *  
sudo ./XEngine_LINEnv.sh -i 3  
the script can be run by self  
We recommend that you execute the environment configuration script twice to check whether the environment installation is successful  
link to the library,sush as base library:-L ../../../XEngine/XEngine_Release/XEngine_Linux/Ubuntu/XEngine_BaseLib -lXEngine_BaseLib  
###### UPDate
terminate execution in the xengine dir:git pull  
Execute the command after success:sudo ./XEngine_LINEnv.sh -b -i 3  

#### MacOS
MacOS requires system 13 and above,install like to linux,you can view the installation method through the -h parameter of the installation script.  
please make sure xcode is installed in you system before execution this script.if not,please execution:xcode-select --install  
MacOS link library (dylib) can be directly placed in the same directory as the program to run,It depends on how you use it  
When configuring the brew environment, you need to manually enter the password and press Enter to confirm the information  
We recommend that you execute the environment configuration script twice to check whether the environment installation is successful  
###### how to use
you must installed homebrew on your system first    
open terminal,execution:./XEngine_LINEnv.sh  
the script can be run by self  
###### UPDate
terminate execution in the xengine dir:git pull  
Execute the command after success:./XEngine_LINEnv.sh -b -i 3  

#### Android
copy depend file into your project  
support ANDROID system 10 and above,ARM64 

#### IOS(IPHONE)
Due to system limitations, you can only copy the dependent shared libraries to your program directory and put them together  
Support IOS13 and above systems, ARM64-bit architecture is required  

## System Version
load header file:  
#include <pch.h>                  //Precompiled, Windows may require  
#include <system header.h>  
using namespace *;                //C++ NAME SPACE  
#include <XEngine_CommHdr.h>  
#include <XEngine_ProtocolHdr.h>  //maybe need  
#include <XEngine_Include/components_dir/moduename_Define.h>  
#include <XEngine_Include/components_dir/moduename_Error.h>  
#include <your header file>  
If you encounter some duplicate macro definitions, please pay attention to whether your macro definitions are loaded normally or your header files are loaded correctly, or you can delete our duplicate macro definitions  

## Directory Structure

*libxengine            SDK Release dir
 * XEngine_Android          Android Release version folder  
 * XEngine_IOS              IOS Release version folder  
 * XEngine_Mac              MacOS System Release version folder
 * XEngine_Windows          WINDOWS Release version folder  
    *    --x64                    64bit DLL  
        *        --XEngine_*              Components folder,include dll and lib...  
    *    --x86                    32bit DLL  
        *        same to 64bit  
 * XEngine_Linux           LINUX release version folder  
    *    --Centos                 Centos System Version  
        *        --XEngine_*              Components folder,include so file  
    *    --Ubuntu                 Ubuntu System Version  
        *        same to centos  
 
 * XEngine_Include         Header Folder  
    *    --XEngine_CommHdr.h      Public header file  
    *    --XEngine_ProtocolHdr.h  protocol header  
    *    --XEngine_Types.h        Function conversion header files for non-WINDOWS system platforms
    *    --XEngine_*              Components Header  
  * XEngine_Docment        Docment Dir  
    *    --SDK服务协议.docx        Protocol Docment
    *    --开发人员必读.docx       Xengine docment 
    *    --开发文档.docx           develop docment  
    *    --结构图      
 * XEngine_Configure        Configure file Dir,for http and sip configure
 * XEngine_LibPath.conf     Linux Module Configure File
 * CONTRIBUTING.md          CONTRIBUTING List
 * XEngine_LINEnv.sh        Linux And MacOS Env XEngine Install Configure Script
 * XEngine_WINEnv.bat       Windows Env XEngine Install Configure Script
 * XEngine_APIDoc.chm       API Docment
 * README.en.md             english readme
 * README.md                chinese readme 
 * CHANGELOG                Latest version update instructions
 * COPYRIGHT                Third-party library copyright notice
 * HOSTORY                  update history
 * LICENSE                  XEngine copyright notice

## learn to
If you want to use this framework, it may take a week to fully learn to get started.  
You can understand the infrastructure through the documentation, you can find Function by search header file or comments  

#### learning method
If you want to do network service communication development, you need to understand the XEngine_Core module of the XEngine_Core component and the XClient_Socket module of the XEngine_Client component  
You can also look at HelpComponents_Packets of the XEngine_HelpComponents component to see how network packets are handled  
More advanced use can be combined with the HelpComponents_XLog log module under the XEngine_HelpComponents component and the HelpComponents_Database database module  
When you are familiar with this framework, you can use the XEngine_StreamMedia component to develop streaming media or XEngine_AVCoder to develop audio and video codec functions  
You can also use the XEngine_RfcComponents component to develop some common protocol services, such as HTTP, WEBSOCKET, SIP, etc...  

## Join us
To join the development, you need to apply first. You can join after the assessment  

### component struct
 * Codec component: used for audio and video codec development and filter, transcoding and other operations
 * Basic components: including basic time, string, algorithm, file, event, handle and other operations
 * Client Components: Contains regular TCP and UDP client development, as well as other advanced client development SDKs
 * Core components: including various high-performance network services, high-performance thread pools and network-related basic protocol development, etc.
 * Helping components: including protocol group unpacking, binary group unpacking, decompression, database related SDK development
 * Network components: SDKs for network-related protocols and tools development
 * Standard Components: Modules developed for protocols introduced by the RFC standards organization.
 * Streaming Media Components: Interface modules for client-server protocol-related development of streaming media protocols
 * System components: SDK development components related to the system platform
 
## Software Architecture
![软件架构图](https://www.xyry.org/EngineFrameWork.png "软件架构图")
![引擎模块图](https://www.xyry.org/EngineRelation.png "引擎模块图")

### components struct picture 
![音视频编解码组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_AVCodec.png "音视频编解码组件结构图")
![基础组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_BaseLib.png "基础组件结构图")
![客户端组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_Client.png "客户端组件结构图")
![核心组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_Core.png "核心组件结构图")
![帮助组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_HelpComponents.png "帮助组件结构图")
![网络组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_NetHelp.png "网络组件结构图")
![标准组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_RfcComponents.png "标准组件结构图")
![流媒体组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_StreamMedia.png "流媒体组件结构图")
![系统组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_SystemSdk.png "系统组件结构图")