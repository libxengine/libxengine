[中文](README.md) ||  [English](README.en.md)  
# XEngine
网络与媒体开发包,通信引擎与中间件,网络通信开发框架,流媒体开发框架,音视频开发框架
  
## 当前版本
V9.15.0.1001
  
## 注意
你应该先阅读README.md(English:README.en.md) .如果可以,请阅读XEngine_Docment/开发人员必读.docx  
更多内容,请访问我们的网站:www.xyry.org
  
## 项目介绍
XEngine是基于C/C++开发的一套跨平台(支持Windows,Linux,Mac,Android,IOS)稳定可靠的开发框架,他提供了47个模块(SO,DLL,DYLIB)和上千个API函数供你调用,你可以在这套框架上面快速的开发部署你的网络应用程序环境。此引擎提供了底层网络IO和网络应用与协议相关的高性能接口，你可以使用此框架快速部署与开发大型或者中小型应用服务器以及其他与网络与协议相关的应用程序。他是关于网络协议,流媒体,音视频与服务器相关的一整套开发框架,并且他提供了整个服务生命周期的开发库.他为你解决了从网络IO层到应用层的一系列复杂的问题,包括性能问题。  
此引擎你可以把他当成一个小型的C接口的BOOST库,只是他更偏向网络通信,后台服务,通用网络协议,流媒体协议,音视频编解码,你可以使用这套框架提供的API,开发你想要的任何网络与通信程序或服务,包括不限于:聊天服务,视频会议,语音会议,文件服务,远程监控,日志服务,HTTP服务,代理服务,数据转发服务,消息服务,安全验证,流媒体服务,音视频编解码,P2P等等相关工具和服务的开发  
XEngine拥有一整套完整的线程池模型(从网络IO到业务处理),而不是市面上的伪线程池模型,也不需要莫名其妙的协程,你可以真正实现一套高性服务器  
  
## 软件目标
学会这套开发通信引擎后,在你以后工作学习中,你会发现开发网络通信相关的应用程序非常轻松愉快.你可以在一周内完成一个团队3个月时间的工作.  
此开发包统一使用了C接口方式的导出,模块间函数可以独立使用,也可以全部使用.你可以根据自己需要选择使用的模块.  
现在,开始学习这套引擎吧...
#### 学习计划
想要使用这套框架,完整的学习到上手可能需要一周时间.  
你可以通过文档了解基础结构,通过查找头文件与全局搜索注释找到想要的功能

#### 学习方式
如果想要做网络服务通信开发,你需要了解XEngine_Core组件的XEngine_Core模块以及XEngine_Client组件的XClient_Socket模块  
你还可以查看XEngine_HelpComponents组件的HelpComponents_Packets了解如何处理网络包  
更高级的使用可以结合XEngine_HelpComponents组件下的HelpComponents_XLog日志模块与HelpComponents_Database数据库模块使用  
当你熟悉这套框架,你可以使用XEngine_StreamMedia组件开发流媒体或者XEngine_AVCodec开发音视频编解码功能  
你还可以使用XEngine_RfcComponents组件开发一些常用的协议服务,比如HTTP,WEBSOCKET,SIP等等...
#### 学习教程
你也可以去观看我们提供的视频教程进一步了解每个组件模块的使用方法:https://www.xyry.org/Learn.docx
  
## 部署环境
我们建议你使用git工具下载和更新(windows可以使用TortoiseGit),仅限英文路径  
注意:更多可用系统版本将只在github发布.建议使用github  
git clone https://gitee.com/libxengine/libxengine.git  
git clone https://github.com/libxengine/libxengine.git
  
#### Windows
下载完毕后,你可以直接运行主目录下的XEngine_WINEnv64.bat文件,根据你需要的系统版本  
注意:git版本默认64bit的,如果需要32BIT或者ARM64那么需要在github发布页下载后放到其他目录运行XEngine_WINEnv32或者XEngine_WINEnvArm64脚本文件  
执行成功后会在你的系统中添加此目录的用户环境变量  
以Visual Studio为例,右键你的项目->属性->VC++目录  
包含目录添加$(XEngine_Include)头文件环境  
x86添加$(XEngine_Lib32)库目录环境  
x64添加$(XEngine_Lib64)库目录环境  
ARM64添加$(XEngine_Arm64)库目录环境
###### 如何使用
WINDOWS下使用我们的库的时候,你需要在你应用程序初始化的时候手动启用WSAStartup(MAKEWORD(2,2),&st_WSAData); 应用程序销毁的时候启用WSAClean() 这个函数才能使用我们的网络库  
连接到库,比如基础库:#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseLib")  
###### 运行时库
我们发布的软件都使用的是MD编译.需要VS2022的运行时库  
大多数时候系统中已经安装运行库了,如果没有，那么我们建议你安装。  
x86(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x86.exe  
X64(VS2015-VS2022):https://aka.ms/vs/17/release/vc_redist.x64.exe  
ARM64(VS2022):https://aka.ms/vs/17/release/vc_redist.arm64.exe
###### 更新引擎
直接使用git拉取,git pull 即可.
  
#### Linux
我们提供了环境运行安装脚本，安装脚本是基于Ubuntu24.04位编写。我们的软件支持Ubuntu和Rocklinux，如果你不是使用的这些系统，那么你需要自己查看我们的依赖库并且安装。你可以通过安装脚本 -h 参数查看安装方法.注意:UBUNTU(DEBIAN)和Rocklinux(REDHAT)核心是分开的,无法同时兼容  
linux提供了ARM64和X64的系统环境,git仓库是x86_64的.arm64的需要自己去发布页面下载
###### 如何使用
打开终端  
cd libxengine  
chmod 777 *  
sudo ./XEngine_LINEnv.sh -i 3  
此脚本可以单独运行  
我们推荐你执行两次环境配置脚本用于检查环境安装是否成功  
连接到库,比如基础库:-lXEngine_BaseLib  
###### 更新引擎
终端使用git更新:git pull  
成功后执行命令:sudo ./XEngine_LINEnv.sh -b -i 6 清理，sudo ./XEngine_LINEnv.sh -b -i 3  安装  
如果有大更新,建议清理后执行 sudo ./XEngine_LINEnv.sh -i 3重新处理环境
#### MacOS
MacOS需要13以及以上的系统,安装方式同LINUX,你可以通过安装脚本 -h 参数查看安装方法  
在执行此脚本前,请确保你电脑安装了xcode,如果没有,请在终端执行:xcode-select --install  
配置brew环境的时候需要你手动输入密码和回车确认信息  
我们推荐你执行两次环境配置脚本用于检查环境安装是否成功  
linux提供了ARM64和X64的系统环境,git仓库是x86_64的.arm64的需要自己去发布页面下载
  
###### 如何使用
安装更新方式可以参考LINUX，都一样的。  
此脚本可以单独运行
  
#### Android
只能通过拷贝SO自己配置环境,拷贝依赖的模块到你的程序中,ANDROID环境需要再GITHUB发布页下载  
支持ANDROID10以及以上系统,ARM64位
  
#### IOS(IPHONE)
由于系统限制,你只能拷贝依赖的共享库到你的程序目录下放到一起,IOS环境需要再GITHUB发布页下载.  
支持IOS15以及以上系统,需要ARM64位的架构
  
## 使用说明
加载头文件:  
#include <pch.h> //预编译,WINDOWS可能需要  
#include <系统头文件.h>  
using namespace 名词空间;          //C++名词空间  
#include <XEngine_CommHdr.h>  
#include <XEngine_ProtocolHdr.h> //可能需要  
#include <XEngine_Include/组件目录/模块名称_Define.h>  
#include <XEngine_Include/组件目录/模块名称_Error.h>  
#include <你的头文件>  
  
## 目录结构

*libxengine            SDK发布文件夹
* XEngine_Mac              MacOS系统模块发布文件夹(x86_64)
* XEngine_Windows          WINDOWS发布版本文件夹,包括lib.dll等(x86_64)
* XEngine_Linux            LINUX系统模块发布文件夹(UBuntu24.04_x86_64)
* XEngine_Include         头文件目录
 * --XEngine_CommHdr.h      公用头文件
 * --XEngine_ProtocolHdr.h  协议头文件
 * --XEngine_Types.h        非WINDOWS系统平台的函数转换头文件
 * --XEngine_*              组件头文件目录
 * XEngine_Docment         文档目录
 * --SDK服务协议.docx        协议文档
 * --开发人员必读.docx       系统说明文档
 * --开发文档.docx           开发组必读,开发规范
 * --结构图
* XEngine_Configure        配置文件所在文件夹,用于HTTP,SIP等的配置
* CODE_OF_CONDUCT.md       贡献内容说明
* CONTRIBUTING.md          贡献名单
* README.en.md             英文必读说明
* README.md                中文必读
* SECURITY.md              版本维护安全更新说明
* XEngine_LINEnv.sh        Linux和MacOS的XEngine安装配置脚本
* XEngine_WINEnv32.bat     Windows环境32位XEngine安装配置脚本
* XEngine_WINEnv64.bat     Windows环境64位XEngine安装配置脚本
* XEngine_WINEnvArm64.bat  Windows环境Arm64位XEngine安装配置脚本
* XEngine_APIDoc.chm       API文档
* CHANGELOG                最新版本更新说明
* COPYRIGHT                第三方版权说明
* HOSTORY                  以往更新历史
* LICENSE                  XEngine版权说明
  
## 关注我们
如果你觉得这个软件对你有帮助,请你给我们一个START吧  
也可以通过微信关注我们  
![qrcode](https://www.xyry.org/qrcode.jpg)
  
### 组件结构
* 编解码组件:用于音频和视频编解码开发和过滤器,转码等操作
* 基础组件:包含基本的时间,字符串,字符集,算法,事件,句柄,时间,安全函数等操作
* 客户端组件:包含常规TCP和UDP客户端开发,以及其他高级客户端开发SDK
* 核心组件:包括各种高性能网络服务,高性能线程池和网络相关基础协议开发等
* 帮助组件:包括协议组包拆包,二进制组包拆包,解压缩,数据库相关SDK开发
* 网络组件:与网络相关的协议与工具开发SDK
* 标准组件:用于RFC标准组织推出的协议所开发的模块.
* 流媒体组件:用于流媒体协议客户端服务器协议相关开发的接口模块
* 系统组件:用于系统平台相关的SDK开发组件

## 参与贡献
代码库目录:https://github.com/libxengine/xengine  
代码授权信息:https://www.xyry.org/auth.html  
参与贡献的代码请自己fork后在自己的仓库编写代码,编写完成后可以提交PR到我们仓库的develop分支  
你需要严格按照编码格式<开发文档.docx>来编写代码,参考<环境配置.docx>来配置开发环境  
如果你只需要使用代码自己编译,那么请在我们仓库切换到master分支使用,develop是开发分支.不提供日常使用
  
## 软件架构
  
![软件架构图](https://www.xyry.org/XEngine_StructPic/EngineFrameWork.png  "软件架构图")
![引擎模块图](https://www.xyry.org/XEngine_StructPic/EngineRelation.png  "引擎模块图")
  
### 组件结构图
![音视频编解码组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_AVCodec.png  "音视频编解码组件结构图")
![基础组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_BaseLib.png  "基础组件结构图")
![客户端组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_Client.png  "客户端组件结构图")
![核心组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_Core.png  "核心组件结构图")
![帮助组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_HelpComponents.png  "帮助组件结构图")
![网络组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_NetHelp.png  "网络组件结构图")
![标准组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_RfcComponents.png  "标准组件结构图")
![流媒体组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_StreamMedia.png  "流媒体组件结构图")
![系统组件结构图](https://www.xyry.org/XEngine_StructPic/XEngine_SystemSdk.png  "系统组件结构图")