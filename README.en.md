[中文](README.md) ||  [English](README.en.md) 
# XEngine
Network development kit, network communication engine, network communication middleware,Network communication development framework

## Now Version is
V7.45.0.1001

## Note  
You should read README.md(English:README.en.md) first. If you can, please read XEngine_Docment/开发人员必读.docx  
It is recommended to use Arial, read the update history  
For more content,please visit our website: www.xyry.org  

## Description
XEngine is a network communication development framework based on C/C++ development, it is a cross-platform(Suppoort:Windows,Linux,Mac,Android,IOS) stable and reliable network development framework. You can quickly deploy your application environment on this engine. This engine not only encapsulates high-performance API functions, but also encapsulates the underlying network IO and network application and protocol-related interfaces. You can use this SDK to quickly deploy and develop large or small and medium-sized application servers and other network and communication-related applications  
You can use this SDK to develop any network and communication programs or services you want, including but not limited to: chat service, video conference, voice conference, file service, remote monitoring, log service, HTTP service, proxy service, data forwarding Services, messaging services, security verification, streaming media services, audio and video codec, P2P and other related tools and services development  
XEngine is a complete set of development kits related to network communication and backend servers.He provides a development library for the entire back-end service life cycle,He solves a series of complex problems from the network IO layer to the application layer, including performance problems  
XEngine has a complete set of thread pool models (from network IO to business processing), instead of other pseudo thread pool models, and does not require inexplicable coroutines, you can truly implement a set of high-performance servers  

## Software goals
After learning this set of development communication engine, in your future work and study, you will find that the development of network communication-related applications is very easy and happy, and there will be no troubles. It almost contains all the API function packages related to network communication.  
This development kit uses the export of C mode uniformly, and the functions between modules can be used independently or all. You can choose the module to use according to your needs.  
We have comprehensive technical support, you can ask us questions if you have any questions, and we will do our best to help for you  
You can even use our SDK to develop a server without any system API  
Now, let's start learning this engine...  

## Deployment environment
We recommend you to use git tool download and update(windows can use TortoiseGit)  
git clone https://gitee.com/xyry/libxengine.git  
git clone https://github.com/libxengine/xengine.git  

#### Windows
After the download is complete, you can directly run the XEngine_WINEnv.bat file in the home directory  
After the execution is successful, the user environment variable of this directory will be added to your system  
Add $(XEngine_Include) to the include directory of your project of properties of VC++ directory, add $(XEngine_Library) to the library directory or x86 add: $(XEngine_Lib32),x64 add: $(XEngine_Lib64)  
Note: The x86 version will be removed after the V8 version, please try to use X64.
###### UPDate
Use git to pull directly  

#### Linux
open terminal  
cd libxengine  
chmod 777 *  
sudo ./XEngine_LINEnv.sh -i 3  
the script can be run by self  
###### UPDate
terminate execution in the xengine dir:git pull origin master  
                                       sudo ./XEngine_LINEnv.sh -b -i 3  

#### MacOS
you must installed homebrew on your system first    
open terminal,execution:./XEngine_LINEnv.sh  
the script can be run by self  
###### UPDate
terminate execution in the xengine dir:git pull origin master  
                                       ./XEngine_LINEnv.sh -b -i 3  

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

### Windows  
WINDOWS:release version has 32bit and 64bit,You can load as needed,These two versions cannot be used in common, the SDK we released is now based on ANSI character encoding,UNICODE code is not provided temporarily, if you are a UNICODE program, you can convert it to UNICODE code yourself  
When using our library under WINDOWS, you need to enable WSAStartup(MAKEWORD(2,2),&st_WSAData) when you program start and use WSAClean() when your program destory to use our network library  
link to the library,sush as base library:#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseLib")  

#### Runtime library
The software we release is compiled using MD. The runtime library of VS2022 is required  
Most of the time, the runtime library is already installed on the system, if not, then we recommend that you install it  
x86(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x86.exe  
X64(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x64.exe  

### Linux  
LINUX:Only supports BIT64 bit system. We provide an environment to run the installation script, the installation script is based on Centos 8_x64 and Ubuntu20.04_x64. Our software supports RedHat, Centos, Ubuntu and Debian. If you are not using these systems, then you need to check our dependent libraries and install them, Here: We recommend that you use Centos8 or Ubuntu20.04 or higher. you can view the installation method through the -h parameter of the installation script. Note: UBUNTU (DEBIAN) and CENTOS (REDHAT) cores are separate, It is currently not compatible at the same time.link to the library,sush as base library:-L ../../../XEngine/XEngine_Release/XEngine_Linux/Ubuntu/XEngine_BaseLib -lXEngine_BaseLib  

### MacOS 
MacOS requires system 12 and above,install like to linux,you can view the installation method through the -h parameter of the installation script.  
MacOS link library (dylib) can be directly placed in the same directory as the program to run,It depends on how you use it  

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
 * XEngine_Mac             MacOS System Release version folder
    *    --XEngine_*              Module Folder  
 * XEngine_Include         Header Folder  
    *    --XEngine_CommHdr.h      Public header file  
    *    --XEngine_ProtocolHdr.h  protocol header  
    *    --XEngine_*              Components Header  
  * XEngine_Docment        Docment Dir  
    *    --SDK服务协议.docx        Protocol Docment
    *    --开发人员必读.docx       Xengine docment 
    *    --开发文档.docx           develop docment  
    *    --结构图      
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

### module struct
#### 1. XEngine_LibEx
third-part library
#### 2. XEngine_AvCoder
Codec component: used for audio and video codec development and filter, transcoding and other operations
##### 2.1 XEngine_AudioCoder
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Audio codec development module
##### 2.2 XEngine_AVCollect
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Audio and video capture module, support audio, desktop, camera capture
##### 2.3 XEngine_AVHelp
Audio and video development help module, enumerate video, audio devices and get supported codec operations, etc.
##### 2.4 XEngine_VideoCoder
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Video codec development module
##### 2.5 XEngine_AVPlayer
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Player module, can play audio and video
##### 2.6 XEngine_AVPacket
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Audio and video file format encapsulation and format conversion module
#### 3. XEngine_BaseLib
Basic components: including basic time, string, algorithm, file, event, handle and other operations
##### 3.1 XEngine_Algorithm
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Algorithm library development module, including some common algorithm operation API
##### 3.2 XEngine_BaseLib
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Basic module, including string, event, handle, time, bit, configuration read and write (linux) API function set
#### 4. XEngine_Client
Client Components: Contains regular TCP and UDP client development, as well as other advanced client development SDKs
##### 4.1 XClient_Socket
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Network client development module, this client includes TCP, UDP, UDT, SCTP client operations, supports high performance, reliability, low latency, and other client network development API functions. If it is not UDT, SCTP, users can not use this module, but use the standard SOCKET development client.
##### 4.2 XClient_Ssl
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Network security client development module, through this module, your network communication can be encrypted to transmit data.
#### 5. XEngine_Core
Core components: including various high-performance network services, high-performance thread pools and network-related basic protocol development, etc.
##### 5.1 XEngine_Core
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Network service development module, which contains API interfaces for all available service development, is the core module of the whole engine, you can find various high-performance development models of TCP and UDP in it API interface, you can also find wireless communication, infrared, Bluetooth development interfaces, and you can also find various other communication methods, broadcast, multicast development interfaces, etc. For details, you can check the exported API description.
##### 5.2 XEngine_ManagePool
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Management pool module, which includes the development API interface of memory pool, thread pool, connection pool
##### 5.3 XEngine_NetXApi
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Network API encapsulation interface, IP library, packet capture, traffic acquisition and other API interfaces
##### 5.4 XEngine_OpenSsl
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Security encryption and decryption development module, including security service API interface and encryption and decryption API interface
##### 5.5 XEngine_Protocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RFC protocol development interface, some standard, small RFC interface definitions are developed using this module.
##### 5.6 XEngine_WBlackList
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Black and white list policy module, which can filter and configure policies for IPV4 and domain name processes
#### 7. XEngine_DownLoad
Download component: used to upload download protocol
##### 7.1 XEngine_DownLoad
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Download development interface: including HTTP and FTP download and upload development.
##### 7.2 XEngine_BTorrent
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A module for downloading, making and parsing BT seeds
#### 8. XEngine_HelpComponents
Helping components: including protocol group unpacking, binary group unpacking, decompression, database related SDK development
##### 8.1 HelpComponents_BINPack
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Binary packaging and unpacking API tool, which can pack multiple files into one file or unpack into multiple files.
##### 8.2 HelpComponents_Compress
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Unzip API Development Module
##### 8.3 HelpComponents_DataBase
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Database development module, support SQLITE,MYSQL,MSSQL,MARAIDB,POSTPRESQL,MONGODB database
##### 8.4 HelpComponents_Packets
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Data flow, packetization, unpacking module, you can leave the TCP packet, or unpack, TCP is a stream socket, you must operate through this module to process a The completed package, otherwise when you accept the data, it may cause the package to be smeared.
##### 8.5 HelpComponents_XLog
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Log module, which can print logs, save logs, and backup logs. It is best for the server to use this module to record log information.
##### 8.6 HelpComponents_Authorize
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Authorization verification module for local authorization verification and serial card generation verification
#### 9. XEngine_NetHelp
Network components: SDKs for network-related protocols and tools development
##### 9.1 NetHelp_APIHelp
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Network HTTP client development module, including POST, GET and other API operations
##### 9.2 NetHelp_StressTest
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The stress test module can perform stress test on the server, including connection test, big data test, etc.
#### 10. XEngine_Rfccomponents
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Standard Components: Modules developed for protocols introduced by the RFC standards organization.
##### 10.1 RfcComponents_EmailClient
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Email client development module, through this module, you can develop your own mail client, support POP, SMTP and other protocols
##### 10.2 RfcComponents_ProxyProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Proxy protocol development interface module, can develop proxy server or client, including SOCKS5 and HTTP tunnel principle
##### 10.3 RfcComponents_WSProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;HTTP WEBSOCKET development interface, supports sending and receiving WEBSOCKET protocol.
##### 10.4 RfcComponents_SIPProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SIP client server module, support SIP protocol operation
##### 10.5 RfcComponents_Snmp
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SNMP protocol client encapsulation module, use this module to quickly develop SNMP protocol
##### 10.6 RfcComponents_NatClient
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NAT client module, used for intranet hole drilling service
##### 10.7 RfcComponents_HttpServer
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;HTTP Server Development Module
##### 10.8 RfcComponents_SDPProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDP Packet Unpacking Development Module
##### 10.9 RfcComponents_UPNPProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;UPNP operation interface, through the API of this module, you can operate the router
##### 10.10 RfcComponents_MQTTProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MQTT protocol operation module, support protocol analysis and packetization
#### 11. XEngine_StreamMedia
Streaming Media Components: Interface modules for client-server protocol-related development of streaming media protocols
##### 11.1 StreamMedia_RtspProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RTSP protocol processing module, support RTSP protocol parsing and grouping
##### 11.2 StreamMedia_RtpProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RTP protocol processing module, support RTP protocol parsing and packaging
##### 11.3 StreamMedia_RtcpProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RTCP protocol processing module, support RTCP protocol parsing and packaging
##### 11.4 StreamMedia_HLSProtocol
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;HLS live broadcast, recording protocol processing and media segmentation module
##### 11.5 StreamMedia_XClient
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;XClient is used for streaming media protocol client, which can support push stream and pull stream
#### 12. XEngine_SystemSdk
System components: SDK development components related to the system platform
##### 12.1 XEngine_SystemApi
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;System module: encapsulates most operations, process, thread, network, interface API interface operations, and API interfaces for obtaining information such as CPU and memory.

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