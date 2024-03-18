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
m_EnvAPT='git libssl3 libcurl4 libmysqlclient21 zlib1g libminizip1 libmongoc-1.0-0 libbson-1.0-0 libpq5 libsqlite3-0 libnghttp2-14 libavcodec58 libavdevice58 libavfilter7 libavformat58 libswresample3 libswscale5 net-tools'
m_EnvMAC='curl openssl@3 sqlite zlib minizip mongo-c-driver mysql-client libpq libnghttp2 ffmpeg'

#打印环境
function InstallEnv_Print()
{
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "\033[33m                 XEngine-Toolkit Linux和Mac版本环境安装脚本                    \033[0m"
	echo -e "\033[33m                       运行环境：Linux x64 AND MacOS x64                      \033[0m"
	echo -e "\033[33m                       脚本版本：Ver 8.26.0.1001                              \033[0m"
	echo -e "\033[33m                  安装环境的时候请检查所有三方库下载安装成功                     \033[0m"
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "\033[44;37m当前时间：$m_EnvTimer 执行用户：$m_EnvExecName 你的环境：$m_EnvCurrent\033[0m"
}
#安装条件
function InstallEnv_CheckEnv()
{
	if [ $(getconf WORD_BIT) != '32' ] && [ $(getconf LONG_BIT) != '64' ] ; then
		echo -e "\033[30m本网络引擎只支持64位操作系统，不支持32位。。。\033[0m"
		exit
	fi

	if [ $(uname) == "Linux" ] ; then
		m_EnvRelease=0
		if grep -Eqi "CentOS" /etc/issue || grep -Eq "CentOS" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
		elif grep -Eqi "Rocky Linux" /etc/issue || grep -Eq "Rocky Linux" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
		elif grep -Eqi "Alma Linux" /etc/issue || grep -Eq "Alma Linux" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
		elif grep -Eqi "Red Hat Enterprise Linux Server" /etc/issue || grep -Eq "Red Hat Enterprise Linux Server" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
		elif grep -Eqi "Fedora" /etc/issue || grep -Eq "Fedora" /etc/*-release; then
			m_EnvRelease=1
			m_EnvCurrent=$(cat /etc/redhat-release)
		elif grep -Eqi "Debian" /etc/issue || grep -Eq "Debian" /etc/*-release; then
			m_EnvRelease=2
			m_EnvCurrent=$(cat /etc/issue)
		elif grep -Eqi "Ubuntu" /etc/issue || grep -Eq "Ubuntu" /etc/*-release; then
			m_EnvRelease=2
			m_EnvCurrent=$(cat /etc/issue)
		elif grep -Eqi "Raspbian" /etc/issue || grep -Eq "Raspbian" /etc/*-release; then
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
		echo -e "\033[31m检查你的执行权限中。。。\033[0m"
		ROOT_UID=0
		if [ "$UID" -eq "$ROOT_UID" ] ; then
			echo -e "\033[34m检查到是ROOT权限执行，无法继续,请切换为普通用户。。。\033[0m"
			exit 0
		fi
	else
		echo -e "\033[31m检查你的执行权限中。。。\033[0m"
 		ROOT_UID=0
		if [ "$UID" -eq "$ROOT_UID" ] ; then
			echo -e "\033[34m检查到是ROOT权限执行，继续执行下一步。。。\033[0m"
		else
			echo -e "\033[40;37m检查到你不是ROOT权限，请切换到ROOT权限执行。。。 \033[0m"
			exit 0
		fi
	fi
}
#安装环境扩展源检查
function InstallEnv_Checkepel()
{
	if [ "$m_EnvRelease" -eq "1" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[31m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[31m检查你的扩展源是否安装。。。\033[0m"
			rpmepel='epel-release'
			rpmfusion='rpmfusion-free-release'
			sudo dnf update -y
			if test -z `rpm -qa $rpmepel`
			then 
				echo -e "\033[35m不存在epel扩展源，将开始安装。。。\033[0m"
				sudo dnf install epel-release -y
				echo -e "\033[41;33m$rpmepel 安装完毕\033[0m"
			else
				echo -e "\033[41;37mepel扩展源存在。。。\033[0m"
			fi
			if test -z `rpm -qa | grep $rpmfusion`
			then 
				echo -e "\033[35m不存在rpmfusion扩展源，将开始安装。。。\033[0m"
				sudo dnf install --nogpgcheck https://mirrors.rpmfusion.org/free/el/rpmfusion-free-release-$(rpm -E %rhel).noarch.rpm https://mirrors.rpmfusion.org/nonfree/el/rpmfusion-nonfree-release-$(rpm -E %rhel).noarch.rpm -y
				sudo dnf config-manager --enable crb
				echo -e "\033[41;33m$rpmfusion 安装完毕\033[0m"
			else
				echo -e "\033[41;37mrpmfusion 扩展源存在。。。\033[0m"
			fi
		fi
	elif [ "$m_EnvRelease" -eq "2" ] ; then 
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[31m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[31mUbuntu不需要扩展源。。。\033[0m"
			apt update -y
		fi
	elif [ "$m_EnvRelease" -eq "3" ] ; then 
		if [ "$m_CMDBrew" -eq "1" ] ; then
			echo -e "\033[31mMacos检查是否安装brew。。。\033[0m"
			if ! type brew >/dev/null 2>&1; then
   				echo -e "\033[31mbrew 未安装,开始安装brew。。。\033[0m"
				
				/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
				rm -rf brew-install
				brew update
			else
				echo -e "\033[31mbrew 已安装\033[0m"
			fi
		else
			echo -e "\033[31mBrew配置为用户自己安装。。。\033[0m"
		fi
	fi
} 
#开始安装依赖库
function InstallEnv_CheckIns()
{
	if [ "$m_EnvRelease" -eq "1" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[31m检查到不执行环境安装，跳过运行环境检查步骤。。。\033[0m"
		else
			echo -e "\033[31m开始进行环境检查，如果下载失败，请更换安装源在执行一次。。。\033[0m"
			for i in $m_EnvRPM
			do
				echo -e "\033[45;37m开始检查：$i 是否已经被安装\033[0m"
				if test -z "`rpm -qa $i`"
				then					
					echo -e "\033[35mrpm包$i 没有被安装，开始安装此库的RPM包\033[0m"
					sudo dnf install $i -y
					echo -e "\033[41;33mrpm包$i 安装完毕\033[0m"
				else
					echo -e "\033[41;37mrpm包$i 已经安装\033[0m"
				fi
			done
		fi
	fi

	if [ "$m_EnvRelease" -eq "2" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[31m检查到不执行环境安装，跳过运行环境检查步骤。。。\033[0m"
		else
			echo -e "\033[31m开始进行环境检查，如果下载失败，请更换安装源在执行一次。。。\033[0m"
			for i in $m_EnvAPT
			do
				echo -e "\033[45;37m开始检查：$i 是否已经被安装\033[0m"
				if test -z "`dpkg -l | grep $i`"
				then					
					echo -e "\033[35mdeb包$i 没有被安装，开始安装此库的deb包\033[0m"
					sudo apt install $i -y
					echo -e "\033[41;33mdeb包$i 安装完毕\033[0m"
				else
					echo -e "\033[41;37mdeb包$i 已经安装\033[0m"
				fi
			done
		fi
	fi
	
	if [ "$m_EnvRelease" -eq "3" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[31m检查到不执行环境安装，跳过运行环境检查步骤。。。\033[0m"
		else
			echo -e "\033[31m开始进行环境检查，如果下载失败，请更换安装源在执行一次。。。\033[0m"
			for i in $m_EnvMAC
			do
				echo -e "\033[45;37m开始检查：$i 是否已经被安装\033[0m"
				if test -z "`brew list | grep $i`"
				then					
					echo -e "\033[35mBrew包$i 没有被安装，开始安装此库的Brew包\033[0m"
					brew install $i
					echo -e "\033[41;33mBrew包$i 安装完毕\033[0m"
				else
					echo -e "\033[41;37mBrew包$i 已经安装\033[0m"
				fi
			done
		fi
	fi
}
#是否下载
function InstallEnv_CheckFile()
{
	if [ "$m_EnvFileBreak" -eq "1" ] ; then
		echo -e "\033[36m检测到不需要进行文件存在性检查，跳过文件检查。。。\033[0m"
	else
		local m_bDownload=0
		if [ ! -d "./XEngine_Include/" ];then
			m_bDownload=1
		else
			m_bDownload=0
		fi
	
		if [ "$m_EnvRelease" -eq "1" ] ; then
			echo -e "\033[36m没有检查到文件，需要下载,文件下载中。。。\033[0m"
			git clone https://gitee.com/xyry/libxengine.git
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
		echo -e "\033[45;37m检查到你需要安装SDK头文件，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "3" ] ; then
			cp -rf ./XEngine_Include /usr/local/include
		else
			cp -rf ./XEngine_Include /usr/include/
		fi
		echo -e "\033[45;37m安装头文件完毕\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "4" ] || [ "$m_EnvInstall" -eq "6" ] ; then 
		echo -e "\033[45;37m检查到你需要删除SDK头文件，正在删除中。。。\033[0m"
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
	#Macos
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
		echo -e "\033[31m检查到你需要安装SDK共享库，正在安装中。。。\033[0m"
		rm -rf /usr/local/lib/XEngine_Release
		if [ "$m_EnvRelease" -eq "1" ] ; then
			m_EnvDir=$(pwd)/XEngine_Linux/Centos
		fi
		if [ "$m_EnvRelease" -eq "2" ] ; then
			m_EnvDir=$(pwd)/XEngine_Linux/Ubuntu
		fi
		if [ "$m_EnvRelease" -eq "3" ] ; then
			m_EnvDir=$(pwd)/XEngine_Mac
		fi
		InstallEnv_CopyModule $m_EnvDir
		if [ "$m_EnvRelease" -eq "1" ] || [ "$m_EnvRelease" -eq "2" ] ; then
			ldconfig
		fi
		echo -e "\033[31m安装共享库成功\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "5" ] || [ "$m_EnvInstall" -eq "6" ] ; then
		echo -e "\033[31m检查到你需要删除SDK共享库，正在删除中。。。\033[0m"
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
			#delete will later
			rm -rf /usr/local/lib/XEngine_Release
			rm -rf /etc/ld.so.conf.d/XEngine_LibPath.conf
			ldconfig
		fi
		echo -e "\033[31m删除共享库成功\033[0m"
	fi
}
#安装程序
function InstallEnv_Execution()
{
	if [ "$m_EnvInstall" -eq "2" ] || [ "$m_EnvInstall" -eq "3" ] ; then
		echo -e "\033[31m检查到你需要安装程序，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "1" ] ; then
			cp -rf ./XEngine_Linux/Centos/xengine /usr/local/bin/xengine
			chmod 777 /usr/local/bin/xengine
		fi
		if [ "$m_EnvRelease" -eq "2" ] ; then
			cp -rf ./XEngine_Linux/Ubuntu/xengine /usr/local/bin/xengine
			chmod 777 /usr/local/bin/xengine
		fi
		if [ "$m_EnvRelease" -eq "3" ] ; then
			cp -rf ./XEngine_Mac/xengine /usr/local/bin/xengine
			chmod 777 /usr/local/bin/xengine
		fi
		echo -e "\033[31m安装xengine程序成功\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "5" ] || [ "$m_EnvInstall" -eq "6" ] ; then
		echo -e "\033[31m检查到你需要删除xengine程序，正在删除中。。。\033[0m"
		rm -rf /usr/local/bin/xengine
		echo -e "\033[31m删除xengine程序成功\033[0m"
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
		echo -e "\033[31m检查到你需要清理工作，清理临时文件成功。。。\033[0m"
	fi
}

InstallEnv_CheckEnv
InstallEnv_Print

echo -e "\033[31m检查你的参数设置中。。。\033[0m"
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

echo -e "\033[36m安装运行环境完毕。。。done...\033[0m"
