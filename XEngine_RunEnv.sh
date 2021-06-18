#!/bin/bash
clear
m_EnvTimer=$(date)
m_EnvCurrent=0
m_EnvExecName=$(whoami)
m_EnvInstall=1
m_EnvInsBreak=0
m_EnvAuthBreak=0
m_EnvRelease=0
m_EnvRunRPM='redhat-lsb libuuid libpcap openssl-libs libcurl mariadb-connector-c zlib minizip ffmpeg-libs jsoncpp lksctp-tools bluez-libs lirc-libs SDL2 net-snmp-libs mongo-c-driver-libs libpq libsqlite3x rb_libtorrent'
m_EnvRunApt='lsb-core lsb-release libuuid1 libpcap0.8 libssl1.1 libcurl4 libmysqlclient21 zlib1g libminizip1 libjsoncpp1 libsctp1 libbluetooth3 liblircclient0 libsdl2-2.0-0 libsnmp35 libbson-1.0-0 libmongoc-1.0-0 libpq5 libsqlite3-0 libavcodec58 libavdevice58 libavfilter7 libavformat58 libpostproc55 libswresample3 libswscale5 libtorrent-rasterbar9'

#打印环境
function InstallEnv_Print()
{
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "\033[33m                 XEngine-Toolkit Linux版本环境安装脚本                        \033[0m"
	echo -e "\033[33m                       运行环境：Linux x64                                    \033[0m"
	echo -e "\033[33m                       脚本版本：Ver 7.13.0.1001                              \033[0m"
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

	if grep -Eqii "CentOS" /etc/issue || grep -Eq "CentOS" /etc/*-release; then
		m_EnvRelease=1
		m_EnvCurrent=$(cat /etc/redhat-release)
	elif grep -Eqi "Red Hat Enterprise Linux Server" /etc/issue || grep -Eq "Red Hat Enterprise Linux Server" /etc/*-release; then
		m_EnvRelease=1
		m_EnvCurrent=$(cat /etc/redhat-release)
	elif grep -Eqi "Aliyun" /etc/issue || grep -Eq "Aliyun" /etc/*-release; then
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
}
#权限检查
function InstallEnv_CheckRoot()
{
	if [ "$m_EnvAuthBreak" -eq "1" ] ; then
		echo -e "\033[31m检查到你不需要执行权限检查，跳过。。。\033[0m"
	else
	 	echo -e "\033[31m检查你的执行权限中。。。\033[0m"
 		ROOT_UID=0
		if [ "$UID" -eq "$ROOT_UID" ]
		then
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
			yum update -y
			if test -z `rpm -qa $rpmepel`
			then 
				echo -e "\033[35m不存在epel扩展源，将开始安装。。。\033[0m"
				yum install epel-release -y
				echo -e "\033[41;33m$rpmepel 安装完毕\033[0m"
			else
				echo -e "\033[41;37mepel扩展源存在。。。\033[0m"
			fi
			if test -z `rpm -qa | grep $rpmfusion`
			then 
				echo -e "\033[35m不存在rpmfusion扩展源，将开始安装。。。\033[0m"
				sudo dnf install --nogpgcheck https://mirrors.rpmfusion.org/free/el/rpmfusion-free-release-8.noarch.rpm https://mirrors.rpmfusion.org/nonfree/el/rpmfusion-nonfree-release-8.noarch.rpm -y
				sudo dnf config-manager --set-enabled powertools
				echo -e "\033[41;33m$rpmfusion 安装完毕\033[0m"
			else
				echo -e "\033[41;37mrpmfusion 扩展源存在。。。\033[0m"
			fi
		fi
	fi
	if [ "$m_EnvRelease" -eq "2" ] ; then 
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[31m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[31mUbuntu不需要扩展源。。。\033[0m"
			apt update -y
			apt upgrade -y
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
			echo -e "\033[31m开始进行环境检查。。。\033[0m"
			for i in $m_EnvRunRPM
			do
				echo -e "\033[45;37m开始检查：$i 是否已经被安装\033[0m"
				if test -z "`rpm -qa $i`"
				then					
					echo -e "\033[35mrpm包$i 没有被安装，开始安装此库的RPM包\033[0m"
					sudo yum install $i -y
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
			echo -e "\033[31m开始进行环境检查。。。\033[0m"
			for i in $m_EnvRunApt
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
}
#安装头文件
function InstallEnv_SdkInclude()
{
	if [ "$m_EnvInstall" -eq "1" ] || [ "$m_EnvInstall" -eq "3" ] ; then 
		echo -e "\033[45;37m检查到你需要安装SDK头文件，正在安装中。。。\033[0m"
		cp -rf ./XEngine_Include /usr/include/
		chmod 777 /usr/include/XEngine_Include/*
		echo -e "\033[45;37m安装头文件完毕\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "4" ] || [ "$m_EnvInstall" -eq "6" ] ; then 
		echo -e "\033[45;37m检查到你需要删除SDK头文件，正在删除中。。。\033[0m"
		rm -rf /usr/include/XEngine_Include
		echo -e "\033[45;37m删除头文件完毕\033[0m"
	fi
}
#安装SO库
function InstallEnv_SdkShared()
{
	if [ "$m_EnvInstall" -eq "2" ] || [ "$m_EnvInstall" -eq "3" ] ; then
		echo -e "\033[31m检查到你需要安装SDK共享库，正在安装中。。。\033[0m"
		rm -rf /usr/local/lib/XEngine_Release
		if [ "$m_EnvRelease" -eq "1" ] ; then
			cp -rf ./XEngine_Linux/Centos /usr/local/lib/XEngine_Release
		fi
		if [ "$m_EnvRelease" -eq "2" ] ; then
			cp -rf ./XEngine_Linux/Ubuntu /usr/local/lib/XEngine_Release
		fi
		cp -rf ./XEngine_LibPath.conf /etc/ld.so.conf.d/XEngine_LibPath.conf
		ldconfig

		if [ "$m_EnvRelease" -eq "1" ] ; then
			rm -rf /usr/local/lib/XEngine_Release/XEngine_LibEx/*
		fi
		echo -e "\033[31m安装共享库成功\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "5" ] || [ "$m_EnvInstall" -eq "6" ] ; then
		echo -e "\033[31m检查到你需要删除SDK共享库，正在删除中。。。\033[0m"
		rm -rf /usr/local/lib/XEngine_Release
		rm -rf /etc/ld.so.conf.d/XEngine_LibPath.conf
		ldconfig
		echo -e "\033[31m删除共享库成功\033[0m"
	fi
}

InstallEnv_CheckEnv
InstallEnv_Print

echo -e "\033[31m检查你的参数设置中。。。\033[0m"
while  getopts  "abc:h"  arg 
do  
	case  $arg  in  
		a)  
			m_EnvAuthBreak=1
		;;
		b)  
			m_EnvInsBreak=1
		;;
		c)  
			m_EnvInstall=($OPTARG)
                ;;
		h)  
			echo -e "编译运行环境安装脚本帮助说明"
			echo -e "参数： -a 表示跳过权限检查，默认不跳过"
			echo -e "参数： -b 表示跳过环境检查，默认不跳过"
			echo -e "参数： -c 是否需要安装开发包到系统中，默认安装头文件"
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
InstallEnv_SdkInclude
InstallEnv_SdkShared

echo -e "\033[36m安装运行环境完毕。。。done...\033[0m"
