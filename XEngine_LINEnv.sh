#!/bin/bash
clear
m_EnvTimer=$(date)
m_EnvCurrent=0
m_EnvExecName=$(whoami)
m_EnvInstall=1
m_EnvInsBreak=0
m_EnvFileBreak=0
m_CMDBrew=0
m_EvnFileClear=0
m_EnvAuthBreak=0
m_EnvRelease=0
m_EnvRPM='git openssl-libs libcurl mysql-libs zlib minizip ffmpeg-libs mongo-c-driver-libs libpq libsqlite3x libnghttp2'
m_EnvAPT='git libmysqlclient21 zlib1g libpq5 libsqlite3-0 libnghttp2-14'
m_EnvMAC='curl openssl@3.0 sqlite zlib minizip mongo-c-driver mysql-client@8.0 libpq libnghttp2 ffmpeg@6'

#打印环境
function InstallEnv_Print()
{
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "\033[33m                 XEngine-Toolkit Linux和Mac版本环境安装脚本                    \033[0m"
	echo -e "\033[33m                       运行环境：Linux x64 AND MacOS x64                      \033[0m"
	echo -e "\033[33m                       脚本版本：Ver 9.2.0.1001                              \033[0m"
	echo -e "\033[33m                  安装环境的时候请检查所有三方库下载安装成功                     \033[0m"
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "\033[44;37m当前时间：$m_EnvTimer 执行用户：$m_EnvExecName 你的环境：$m_EnvCurrent\033[0m"
}
#安装条件
function InstallEnv_CheckEnv()
{
	if [ $(getconf WORD_BIT) != '32' ] && [ $(getconf LONG_BIT) != '64' ] ; then
		echo -e "\033[31m本网络引擎只支持64位操作系统，不支持32位。。。\033[0m"
		exit
	fi
	
	if [ $(uname) == "Linux" ] ; then
		m_EnvRelease=0
		if grep -Eq "CentOS" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
			echo -e "\033[30mWARN:AVCodec library are not support running on Like Centos。。。\033[0m"
		elif grep -Eq "Rocky Linux" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
			echo -e "\033[30mWARN:AVCodec library are not support running on Like Centos。。。\033[0m"
		elif grep -Eq "Red Hat Enterprise Linux Server" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
			echo -e "\033[30mWARN:AVCodec library are not support running on Like Centos。。。\033[0m"
		elif grep -Eq "Fedora" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
			echo -e "\033[30mWARN:AVCodec library are not support running on Like Centos。。。\033[0m"
		elif grep -Eq "Debian" /etc/*-release; then
			m_EnvRelease=2
			m_EnvCurrent=$(cat /etc/issue)
		elif grep -Eq "Ubuntu" /etc/*-release; then
			m_EnvRelease=2
			m_EnvCurrent=$(cat /etc/issue)
		elif grep -Eq "Raspbian" /etc/*-release; then
			m_EnvRelease=2
			m_EnvCurrent=$(cat /etc/issue)
		else
        	echo -e "不支持的发行版本，无法继续"
			exit
		fi
	elif [ $(uname) == "Darwin" ] ; then
		m_EnvRelease=3
		m_EnvCurrent=$(sw_vers)
	elif [ $(uname) == "MINGW32_NT" ] ; then
		m_EnvRelease=4
	else
		echo -e "不支持的发行版本，无法继续"
		exit
	fi
}
#权限检查
function InstallEnv_CheckRoot()
{
	if [ "$m_EnvRelease" -eq "3" ] ; then
		echo -e "\033[34m检查你的执行权限中。。。\033[0m"
		ROOT_UID=0
		if [ "$UID" -eq "$ROOT_UID" ] ; then
			echo -e "\033[31m检查到是ROOT权限执行，无法继续,请切换为普通用户。。。\033[0m"
			exit 0
		fi
	else
		echo -e "\033[34m检查你的执行权限中。。。\033[0m"
 		ROOT_UID=0
		if [ "$UID" -eq "$ROOT_UID" ] ; then
			echo -e "\033[32m检查到是ROOT权限执行，继续执行下一步。。。\033[0m"
		else
			echo -e "\033[31m检查到你不是ROOT权限，请切换到ROOT权限执行。。。 \033[0m"
			exit 0
		fi
	fi
}
#安装环境扩展源检查
function InstallEnv_Checkepel()
{
	if [ "$m_EnvRelease" -eq "1" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[34m检查你的扩展源是否安装。。。\033[0m"
			rpmepel='epel-release'
			rpmfusion='rpmfusion-free-release'
			sudo dnf update -y
			if test -z `rpm -qa $rpmepel`
			then 
				echo -e "\033[35m不存在epel扩展源，将开始安装。。。\033[0m"
				sudo dnf install epel-release -y
				echo -e "\033[36m$rpmepel 安装完毕\033[0m"
			else
				echo -e "\033[36mepel扩展源存在。。。\033[0m"
			fi
			if test -z `rpm -qa | grep $rpmfusion`
			then 
				echo -e "\033[35m不存在rpmfusion扩展源，将开始安装。。。\033[0m"
				sudo dnf install --nogpgcheck https://mirrors.rpmfusion.org/free/el/rpmfusion-free-release-$(rpm -E %rhel).noarch.rpm https://mirrors.rpmfusion.org/nonfree/el/rpmfusion-nonfree-release-$(rpm -E %rhel).noarch.rpm -y
				sudo dnf config-manager --enable crb
				echo -e "\033[36m$rpmfusion 安装完毕\033[0m"
			else
				echo -e "\033[36mrpmfusion 扩展源存在。。。\033[0m"
			fi
		fi
	elif [ "$m_EnvRelease" -eq "2" ] ; then 
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[33m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[33mUbuntu不需要扩展源。。。\033[0m"
			apt update -y
		fi
	elif [ "$m_EnvRelease" -eq "3" ] ; then 
		if [ "$m_CMDBrew" -eq "1" ] ; then
			echo -e "\033[34mMacos检查是否安装brew。。。\033[0m"
			if ! type brew >/dev/null 2>&1; then
   				echo -e "\033[35mbrew 未安装,开始安装brew。。。\033[0m"
				/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
				brew update
			else
				echo -e "\033[36mbrew 已安装\033[0m"
			fi
		else
			echo -e "\033[36mBrew配置为用户自己安装。。。\033[0m"
		fi
	fi
} 
#开始安装依赖库
function InstallEnv_CheckIns()
{
	# centos
	if [ "$m_EnvRelease" -eq "1" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查到不执行环境安装，跳过运行环境检查步骤。。。\033[0m"
		else
			echo -e "\033[35mdeb开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			sudo dnf install $m_EnvRPM -y
			echo -e "\033[36mdeb依赖库安装完毕\033[0m"
		fi
	fi
	# ubuntu
	if [ "$m_EnvRelease" -eq "2" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查到不执行环境安装，跳过运行环境检查步骤。。。\033[0m"
		else
			# 读取 /etc/os-release 文件中的 VERSION_ID
			VERSION_ID=$(grep 'VERSION_ID' /etc/os-release | cut -d '"' -f 2)
			# 判断 Ubuntu 版本号
			if [ "$VERSION_ID" == "22.04" ]; then
    			m_EnvAPT="$m_EnvAPT gcc make nasm libssl3 libcurl4 libminizip1 libmongoc-1.0-0 libbson-1.0-0 libx264-dev libx265-dev libfontconfig-dev libfreetype-dev libfribidi-dev libharfbuzz-dev libgme-dev libgmp-dev  libmp3lame-dev libopus-dev libxvidcore-dev libsdl2-dev libzip-dev"
			elif [ "$VERSION_ID" == "24.04" ]; then
    			m_EnvAPT="$m_EnvAPT libssl3t64 libcurl4t64 libminizip1t64 libmongoc-1.0-0t64 libbson-1.0-0t64 libavcodec60 libavdevice60 libavformat60 libavfilter9 libswresample4 libswscale7"
			else
				echo -e "\033[31mThis script only supports Ubuntu 22.04 and 24.04.\033[0m"
				exit 1
			fi

			echo -e "\033[35mdeb开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			sudo apt install $m_EnvAPT -y
			echo -e "\033[36mdeb依赖库安装完毕\033[0m"


			if [ "$VERSION_ID" == "22.04" ]; then
				if [ ! -e /usr/local/bin/ffmpeg ]; then
					# 安装ffmpeg
					echo -e "\033[35mFFMpeg没有被安装,开始安装FFMpeg库\033[0m"
					wget https://ffmpeg.org/releases/ffmpeg-6.1.2.tar.gz
					cd
					tar zxvf ./ffmpeg-6.1.2.tar.gz
					cd ffmpeg-6.1.2
					./configure --pkg-config=pkg-config --enable-gpl --enable-version3 --disable-debug --disable-static --enable-shared --enable-libx264 --enable-libx265 --enable-fontconfig --enable-libfreetype --enable-libfribidi --enable-libharfbuzz --enable-libgme --enable-gmp --enable-libmp3lame --enable-libopus --enable-sdl2 --enable-zlib
					make
					make install
					make clean
					sudo ldconfig
				fi
			fi
		fi
	fi
	# macos 
	if [ "$m_EnvRelease" -eq "3" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查到不执行环境安装，跳过运行环境检查步骤。。。\033[0m"
		else
			echo -e "\033[35mdeb开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			brew install $m_EnvMAC
			echo -e "\033[36mdeb依赖库安装完毕\033[0m"
		fi
	fi
}
#是否下载
function InstallEnv_CheckFile()
{
	if [ "$m_EnvFileBreak" -eq "1" ] ; then
		echo -e "\033[34m检测到不需要进行文件存在性检查，跳过文件检查。。。\033[0m"
	else
		local m_bDownload=0
		if [ ! -d "./XEngine_Include/" ];then
			m_bDownload=1
		else
			m_bDownload=0
		fi
	
		if [ "$m_EnvRelease" -eq "1" ] ; then
			echo -e "\033[36m没有检查到文件，需要下载,文件下载中。。。\033[0m"
			git clone https://gitee.com/libxengine/libxengine.git
			cp -rf ./libxengine/XEngine_Include ./
			cp -rf ./libxengine/XEngine_Linux ./
			cp -rf ./libxengine/XEngine_Mac ./
			m_EvnFileClear=1
		else
			echo -e "\033[36m检查到文件存在，不需要下载。。。\033[0m"
		fi
	fi
}
#安装头文件
function InstallEnv_SdkInclude()
{
	if [ "$m_EnvInstall" -eq "1" ] || [ "$m_EnvInstall" -eq "3" ] ; then 
		echo -e "\033[34m检查到你需要安装SDK头文件，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "3" ] ; then
			cp -rf ./XEngine_Include /usr/local/include
		else
			cp -rf ./XEngine_Include /usr/include/
		fi
		echo -e "\033[45;37m安装头文件完毕\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "4" ] || [ "$m_EnvInstall" -eq "6" ] ; then 
		echo -e "\033[34m检查到你需要删除SDK头文件，正在删除中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "3" ] ; then
			rm -rf /usr/local/include/XEngine_Include
		else
			rm -rf /usr/include/XEngine_Include
		fi
		echo -e "\033[45;37m删除头文件完毕\033[0m"
	fi
}
#安装SO库
m_EnvDir=
function InstallEnv_CopyModule()
{
	local ModulePath=$1
	local ModuleFile=$(ls $ModulePath)
	
	for file in $ModuleFile ; do
		local PathFile="$ModulePath/$file"
		if [ -d "$PathFile" ] ; then
			InstallEnv_CopyModule $PathFile
		else
			if [ "${file##*.}"x = "dylib"x ] || [ "${file##*.}"x = "so"x ] ; then
				cp -rf $PathFile /usr/local/lib/$file
			fi
		fi
	done
}
#安装库文件
function InstallEnv_SdkShared()
{
	if [ "$m_EnvInstall" -eq "2" ] || [ "$m_EnvInstall" -eq "3" ] ; then
		echo -e "\033[34m检查到你需要安装SDK共享库，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "1" ] ; then
			m_EnvDir=$(pwd)/XEngine_Linux
		fi
		if [ "$m_EnvRelease" -eq "2" ] ; then
			m_EnvDir=$(pwd)/XEngine_Linux
		fi
		if [ "$m_EnvRelease" -eq "3" ] ; then
			m_EnvDir=$(pwd)/XEngine_Mac
		fi
		InstallEnv_CopyModule $m_EnvDir
		if [ "$m_EnvRelease" -eq "1" ] || [ "$m_EnvRelease" -eq "2" ] ; then
			ldconfig
		fi
		echo -e "\033[45;37m安装共享库成功\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "5" ] || [ "$m_EnvInstall" -eq "6" ] ; then
		echo -e "\033[34m检查到你需要删除SDK共享库，正在删除中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "3" ] ; then
			rm -rf /usr/local/lib/libXEngine_*.dylib
			rm -rf /usr/local/lib/libXClient_*.dylib
			rm -rf /usr/local/lib/libNetHelp_*.dylib
			rm -rf /usr/local/lib/libHelpComponents_*.dylib
			rm -rf /usr/local/lib/libRfcComponents_*.dylib
			rm -rf /usr/local/lib/libStreamMedia_*.dylib
		else
			rm -rf /usr/local/lib/libXEngine_*.so
			rm -rf /usr/local/lib/libXClient_*.so
			rm -rf /usr/local/lib/libNetHelp_*.so
			rm -rf /usr/local/lib/libHelpComponents_*.so
			rm -rf /usr/local/lib/libRfcComponents_*.so
			rm -rf /usr/local/lib/libStreamMedia_*.so
			ldconfig
		fi
		echo -e "\033[45;37m删除共享库成功\033[0m"
	fi
}
#安装程序
function InstallEnv_Execution()
{
	if [ "$m_EnvInstall" -eq "2" ] || [ "$m_EnvInstall" -eq "3" ] ; then
		echo -e "\033[34m检查到你需要安装程序，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "1" ] ; then
			cp -rf ./XEngine_Linux/xengine /usr/local/bin/xengine
			chmod 777 /usr/local/bin/xengine
		fi
		if [ "$m_EnvRelease" -eq "2" ] ; then
			cp -rf ./XEngine_Linux/xengine /usr/local/bin/xengine
			chmod 777 /usr/local/bin/xengine
		fi
		if [ "$m_EnvRelease" -eq "3" ] ; then
			cp -rf ./XEngine_Mac/xengine /usr/local/bin/xengine
			chmod 777 /usr/local/bin/xengine
		fi
		echo -e "\033[45;37m安装xengine程序成功\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "5" ] || [ "$m_EnvInstall" -eq "6" ] ; then
		echo -e "\033[45;37m检查到你需要删除xengine程序，正在删除中。。。\033[0m"
		rm -rf /usr/local/bin/xengine
		echo -e "\033[45;37m删除xengine程序成功\033[0m"
	fi
}
#清理工作
function InstallEnv_SdkClear()
{
	if [ "$m_EvnFileClear" -eq "1" ] ; then
		rm -rf ./libxengine
		rm -rf ./XEngine_Include
		rm -rf ./XEngine_Linux
		rm -rf ./XEngine_Mac
		echo -e "\033[33m检查到你需要清理工作，清理临时文件成功。。。\033[0m"
	fi
}

InstallEnv_CheckEnv
InstallEnv_Print

echo -e "\033[92m检查你的参数设置中。。。\033[0m"
while  getopts  "abci:h"  arg 
do  
	case  $arg  in  
		a)  
			m_EnvAuthBreak=1
		;;
		b)  
			m_EnvInsBreak=1
		;;
		c)  
			m_EnvFileBreak=1
		;;
		d)
			m_CMDBrew=1
		;;
		i)  
			m_EnvInstall=($OPTARG)
                ;;
		h)  
			echo -e "编译运行环境安装脚本帮助说明"
			echo -e "参数： -a 表示跳过权限检查，默认不跳过"
			echo -e "参数： -b 表示跳过环境检查，默认不跳过"
			echo -e "参数： -c 表示跳过文件检查，默认不跳过"
			echo -e "参数:  -d 表示配置安装brew,默认由用户安装"
			echo -e "参数： -i 是否需要安装开发包到系统中，默认安装头文件"
			echo -e "      0,不执行任何安装"
			echo -e "      1,表示安装开发包中的头文件到你的系统中"
			echo -e "      2,表示安装开发包中的共享库到你的系统中"
			echo -e "      3,表示安装头文件和共享库到你的系统中"
			echo -e "      4,表示从你的系统中删除头文件"
			echo -e "      5,表示从你的系统中删除共享库"
			echo -e "      6,表示从你的系统中删除头文件和共享库"
			echo -e "参数： -h 获取安装帮助"
			exit 0
                ;;                 
		?)  
			echo -e "\033[46;37m参数错误，不支持的参数选项\033[0m"
			exit  1  
		;;  
	esac  
done  

InstallEnv_CheckRoot
InstallEnv_Checkepel
InstallEnv_CheckIns
InstallEnv_CheckFile
InstallEnv_SdkInclude
InstallEnv_SdkShared
InstallEnv_Execution
InstallEnv_SdkClear

echo -e "\033[92m安装运行环境完毕。。。done...\033[0m"
