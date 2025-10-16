#!/bin/bash
m_EnvTimer=$(date)
m_EnvCurrent=0
m_EnvExecName=$(whoami)
m_EnvArch=$(uname -m)
m_EnvInstall=1
m_EnvInsBreak=0
m_EnvFileBreak=0
m_CMDBrew=1
m_EvnFileClear=0
m_EnvAuthBreak=0
m_EnvRelease=0
m_EvnBuildCmd=0
m_EnvRPM='git openssl-libs libcurl zlib minizip mongo-c-driver-libs libpq libsqlite3x libnghttp2'
m_EnvAPT='git zlib1g libpq5 libsqlite3-0 libnghttp2-14'
m_EnvMAC='curl openssl@3 sqlite zlib minizip mongo-c-driver@1 mysql-client@8.0 libpq libnghttp2 ffmpeg@7'

#打印环境
function InstallEnv_Print()
{
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "\033[33m                 XEngine-Toolkit Linux和Mac版本环境安装脚本                    \033[0m"
	echo -e "\033[33m                       脚本版本：Ver 9.29.2.1001                              \033[0m"
	echo -e "\033[33m                  安装环境的时候请检查所有三方库下载安装成功                     \033[0m"
	echo -e "\033[32m|***************************************************************************|\033[0m"
	echo -e "当前时间：$m_EnvTimer 执行用户：$m_EnvExecName 你的架构:$m_EnvArch 版本值:$m_EnvRelease 你的环境：$m_EnvCurrent"
}
#安装条件
function InstallEnv_CheckEnv()
{
	if [ $(getconf LONG_BIT) != '64' ] ; then
		echo -e "\033[31m本网络引擎只支持64位操作系统，不支持32位。。。\033[0m"
		exit
	fi
	
	if [ $(uname) == "Linux" ] ; then
		if [ -f /etc/redhat-release ]; then
			if grep -Eq "CentOS" /etc/redhat-release; then
				m_EnvRelease=1
				m_EnvCurrent=$(cat /etc/redhat-release)
			elif grep -Eq "Rocky Linux" /etc/redhat-release; then
				m_EnvRelease=1
				m_EnvCurrent=$(cat /etc/redhat-release)
			elif grep -Eq "Red Hat Enterprise Linux Server" /etc/redhat-release; then
				m_EnvRelease=1
				m_EnvCurrent=$(cat /etc/redhat-release)
			elif grep -Eq "AlmaLinux" /etc/redhat-release; then
				m_EnvRelease=1
				m_EnvCurrent=$(cat /etc/redhat-release)
			elif grep -Eq "Fedora" /etc/redhat-release; then
				m_EnvRelease=2
				m_EnvCurrent=$(grep "VERSION=" /etc/os-release | cut -d '=' -f 2 | tr -d '"')
			else
        		echo -e "不支持的Red Hat系发行版本，无法继续"
				exit
			fi
		elif [ -f /etc/os-release ]; then
			SystemID=$(grep "^ID=" /etc/os-release | cut -d '=' -f 2 | tr -d '"')
			if [ "$SystemID" = "ubuntu" ]; then
				m_EnvRelease=10
				m_EnvCurrent=$(grep "VERSION=" /etc/os-release | cut -d '"' -f 2)
			elif [ "$SystemID" = "debian" ]; then
				m_EnvRelease=11
				m_EnvCurrent=$(grep "VERSION=" /etc/os-release | cut -d '"' -f 2)
			else
        		echo -e "不支持的发行版本，无法继续"
				exit
			fi
		fi
	elif [ $(uname) == "Darwin" ] ; then
		m_EnvRelease=20
		m_EnvCurrent=$(sw_vers)
	else
		echo -e "不支持的发行版本，无法继续"
		exit
	fi
}
#权限检查
function InstallEnv_CheckRoot()
{
	if [ "$m_EnvRelease" -eq "20" ] ; then
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
	# Centos Redhat
	if [ "$m_EnvRelease" -eq "1" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[34m检查你的扩展源是否安装。。。\033[0m"
			rpmepel='epel-release'
			rpmfusion='rpmfusion-free-release'
			dnf update -y
			if test -z `rpm -qa $rpmepel`
			then 
				echo -e "\033[35m不存在epel扩展源，将开始安装。。。\033[0m"
				dnf install epel-release -y
				echo -e "\033[36m$rpmepel 安装完毕\033[0m"
			else
				echo -e "\033[36mepel扩展源存在。。。\033[0m"
			fi
			if test -z `rpm -qa | grep $rpmfusion`
			then 
				echo -e "\033[35m不存在rpmfusion扩展源，将开始安装。。。\033[0m"
				dnf install --nogpgcheck https://mirrors.rpmfusion.org/free/el/rpmfusion-free-release-$(rpm -E %rhel).noarch.rpm https://mirrors.rpmfusion.org/nonfree/el/rpmfusion-nonfree-release-$(rpm -E %rhel).noarch.rpm -y
				dnf config-manager --enable crb
				echo -e "\033[36m$rpmfusion 安装完毕\033[0m"
			else
				echo -e "\033[36mrpmfusion 扩展源存在。。。\033[0m"
			fi
		fi
	elif [ "$m_EnvRelease" -eq "2" ] ; then 
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[33m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[33mFedora不需要扩展源。。。\033[0m"
			apt update -y
		fi
	elif [ "$m_EnvRelease" -eq "10" ] ; then 
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[33m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[33mUbuntu不需要扩展源。。。\033[0m"
			apt update -y
		fi
	elif [ "$m_EnvRelease" -eq "11" ] ; then 
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[33m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[33mDebian不需要扩展源。。。\033[0m"
			apt update -y
		fi
	elif [ "$m_EnvRelease" -eq "20" ] ; then 
		if [ "$m_CMDBrew" -eq "1" ] && [ "$m_EnvInsBreak" -ne "1" ] ; then
			echo -e "\033[34mMacos检查是否安装brew。。。\033[0m"
			if command -v brew >/dev/null 2>&1; then
   				echo -e "\033[36mbrew 已安装\033[0m"
			else
				echo -e "\033[35mbrew 未安装,开始安装brew。。。\033[0m"
				/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
			fi
			brew update
		else
			echo -e "\033[36mBrew配置为用户自己安装。。。\033[0m"
		fi
	fi
}
#开始安装依赖库
function InstallEnv_CheckIns()
{
	#Centos
	if [ "$m_EnvRelease" -eq "1" ] ; then
		VERSION_ID=$(grep 'VERSION_ID' /etc/os-release | cut -d '"' -f 2 | cut -d '.' -f 1)
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			echo -e "\033[35mrocky开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			if [ "$VERSION_ID" == "9" ] ; then
				m_EnvRPM+=" mysql-libs"
			elif [ "$VERSION_ID" == "10" ]; then
				m_EnvRPM+=" mysql8.4-libs ffmpeg-libs libavdevice"
			else
				echo -e "\033[31mThis script only supports Rockylinux 9 and 10.\033[0m"
				exit 1
			fi
			dnf install --allowerasing $m_EnvRPM -y
			echo -e "\033[36mrocky依赖库安装完毕\033[0m"
			if [ ! -e /usr/local/ffmpeg-xengine/bin/ffmpeg ] && [ "$VERSION_ID" == "9" ]; then
				#lost libfdk-aac-devel libxvid chromaprint libiec61883 libcodec2 libdc1394 libvpl libdrm libmysofa libopenjpeg libplacebo librabbitmq czmq zimg libcdio libgme
				dnf install gcc make wget nasm pkgconf-pkg-config openal-soft-devel libjxl-devel libxml2-devel fontconfig-devel libbs2b-devel libbluray-devel lv2-devel lilv-devel zvbi-devel libwebp-devel libvpx-devel libvorbis-devel libtheora-devel srt-devel speex-devel snappy-devel soxr-devel libopenmpt-devel libmodplug-devel libdav1d-devel libass-devel libaom-devel x264-devel x265-devel fontconfig-devel freetype-devel fribidi-devel harfbuzz-devel gpgme-devel gmp-devel lame-devel opus-devel xvidcore-devel SDL2-devel libzip-devel -y
				# 安装ffmpeg
				echo -e "\033[35mFFMpeg没有被安装,开始安装FFMpeg库\033[0m"
				rm -f ./ffmpeg-7.1.1.tar.gz
				wget https://ffmpeg.org/releases/ffmpeg-7.1.1.tar.gz
				tar zxvf ./ffmpeg-7.1.1.tar.gz
				cd ffmpeg-7.1.1
				m_EvnBuildCmd="--prefix=/usr/local/ffmpeg-xengine --pkg-config=pkg-config --enable-gpl --enable-gnutls --enable-nonfree --enable-version3 --enable-pic"
				m_EvnBuildCmd+=" --disable-debug --disable-static --enable-shared"
				# 图像
				m_EvnBuildCmd+=" --enable-libwebp --enable-sdl2 --enable-libjxl"
				# 音频
				m_EvnBuildCmd+=" --enable-openal --enable-libbs2b --enable-lv2 --enable-libvorbis --enable-libspeex --enable-libsoxr --enable-libopenmpt --enable-libmodplug --enable-libmp3lame --enable-libopus"
				# 视频
				m_EvnBuildCmd+=" --enable-libbluray --enable-libzvbi --enable-libvpx --enable-libtheora --enable-libx264 --enable-libx265 --enable-libdav1d --enable-libaom"
				# 滤镜
				m_EvnBuildCmd+=" --enable-fontconfig --enable-libfreetype --enable-libfribidi --enable-libharfbuzz --enable-libass"
				# 硬件加速
				m_EvnBuildCmd+=""
				# 计算
				m_EvnBuildCmd+=" --enable-gmp"
				# 通信
				m_EvnBuildCmd+=""
				# 三方库
				m_EvnBuildCmd+=" --enable-libxml2 --enable-libsrt --enable-libsnappy --enable-zlib"
				# 附加库
				m_EvnBuildCmd+=" --enable-filter=drawtext"
				# 附加信息
				m_EvnBuildCmd+=" --extra-ldflags="-Wl,-rpath=/usr/local/ffmpeg-xengine/lib""
				./configure $m_EvnBuildCmd
				make
				make install
				make clean
				ldconfig
				cd ..
			fi
		fi
	fi
	#UBuntu
	if [ "$m_EnvRelease" -eq "10" ] ; then
		VERSION_ID=$(grep 'VERSION_ID' /etc/os-release | cut -d '"' -f 2 | cut -d '.' -f 1)
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			# 判断 Ubuntu 版本号
			if [ "$VERSION_ID" == "22" ]; then
				m_EnvAPT+=" gcc make wget nasm libchromaprint-dev libmysofa-dev libcodec2-dev libdrm-dev libdc1394-dev librabbitmq-dev libczmq-dev libgnutls28-dev libopenal-dev libopenjp2-7-dev libxml2-dev frei0r-plugins-dev libbs2b-dev libbluray-dev lv2-dev liblilv-dev libzvbi-dev libwebp-dev libvpx-dev libvorbis-dev libtheora-dev libspeex-dev libsoxr-dev libmodplug-dev libass-dev libx264-dev libx265-dev libfreetype-dev libfribidi-dev libharfbuzz-dev libgmp-dev libmp3lame-dev libopus-dev libxvidcore-dev libsdl2-dev libzip-dev"
    			m_EnvAPT+=" libmysqlclient21 libmongoc-1.0-0 libbson-1.0-0 libfdk-aac-dev libzimg-dev libplacebo-dev libdav1d-dev libaom-dev libfontconfig-dev libgme-dev"
			elif [ "$VERSION_ID" == "24" ]; then
    			m_EnvAPT+=" libmysqlclient21 libmongoc-1.0-0t64 libbson-1.0-0t64 libavcodec-dev libavdevice-dev libavfilter-dev libavformat-dev libswresample-dev libswscale-dev libffmpeg-nvenc-dev"
			else
				echo -e "\033[31mThis script only supports Ubuntu 20.04 and 22.04 and 24.04.\033[0m"
				exit 1
			fi
			echo -e "\033[35mubuntu开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			apt install $m_EnvAPT -y
			echo -e "\033[36mubuntu依赖库安装完毕\033[0m"
			if [ "$VERSION_ID" == "22" ]; then
				if [ ! -e /usr/local/ffmpeg-xengine/bin/ffmpeg ]; then
					# 安装ffmpeg
					echo -e "\033[35mFFMpeg没有被安装,开始安装FFMpeg库\033[0m"
					rm -f ./ffmpeg-7.1.1.tar.gz
					wget https://ffmpeg.org/releases/ffmpeg-7.1.1.tar.gz
					tar zxvf ./ffmpeg-7.1.1.tar.gz
					cd ffmpeg-7.1.1

					m_EvnBuildCmd="--prefix=/usr/local/ffmpeg-xengine --pkg-config=pkg-config --enable-gpl --enable-gnutls --enable-nonfree --enable-version3 --enable-pic"
					m_EvnBuildCmd+=" --disable-debug --disable-static --enable-shared"
					# 图像
					m_EvnBuildCmd+=" --enable-libopenjpeg --enable-libwebp --enable-sdl2"
					# 音频
					m_EvnBuildCmd+=" --enable-chromaprint --enable-libmysofa --enable-libcodec2 --enable-openal --enable-libxvid --enable-lv2 --enable-libvorbis --enable-libspeex --enable-libsoxr --enable-libmodplug --enable-libbs2b --enable-libmp3lame --enable-libopus"
					# 视频
					m_EvnBuildCmd+=" --enable-frei0r --enable-libbluray --enable-libzvbi --enable-libvpx --enable-libtheora --enable-libx264 --enable-libx265"
					# 滤镜
					m_EvnBuildCmd+=" --enable-fontconfig --enable-libfreetype --enable-libfribidi --enable-libharfbuzz --enable-libass"
					# 计算
					m_EvnBuildCmd+=" --enable-gmp"
					# 通信
					m_EvnBuildCmd+=" --enable-libzmq --enable-librabbitmq --enable-libdc1394"
					# 硬件加速
					m_EvnBuildCmd+=" --enable-libdrm"
					# 三方库
					m_EvnBuildCmd+=" --enable-libxml2 --enable-zlib"
					# 附加处理
					m_EvnBuildCmd+=" --enable-filter=drawtext"
					# 附加信息
					m_EvnBuildCmd+=" --extra-ldflags="-Wl,-rpath=/usr/local/ffmpeg-xengine/lib""
					if [ "$VERSION_ID" == "22" ] || [ "$VERSION_ID" == "24" ]; then
						# 图像
						m_EvnBuildCmd+=""
						# 音频
						m_EvnBuildCmd+=" --enable-libfdk-aac --enable-libplacebo --enable-libgme"
						# 视频
						m_EvnBuildCmd+=" --enable-libdav1d --enable-libaom"
						# 滤镜
						m_EvnBuildCmd+=" --enable-libzimg"
						# 计算              
						# 通信
						m_EvnBuildCmd+=""
						# 硬件加速
						m_EvnBuildCmd+=""
						# 三方库
						# 附加处理
						# 附加信息
						if [ "$VERSION_ID" == "24" ]; then
							# 图像
							m_EvnBuildCmd+=" --enable-libjxl"
							# 音频
							m_EvnBuildCmd+=" --enable-libcdio --enable-libopenmpt"
							# 视频
							m_EvnBuildCmd+=""
							# 滤镜
							m_EvnBuildCmd+=""
							# 计算              
							# 通信
							m_EvnBuildCmd+=" --enable-libiec61883"
							# 硬件加速
							m_EvnBuildCmd+=" --enable-libvpl"
							# 三方库
							m_EvnBuildCmd+=" --enable-libsnappy"
							# 附加处理
							# 附加信息
						fi
					fi
					./configure $m_EvnBuildCmd
					make
					make install
					make clean
					ldconfig
					cd ..
				fi
			fi
		fi
	fi
	# debian
	if [ "$m_EnvRelease" -eq "11" ] ; then
		VERSION_ID=$(grep 'VERSION_ID' /etc/os-release | cut -d '"' -f 2 | cut -d '.' -f 1)
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，将不执行扩展源检查。。。\033[0m"
		else
			# 判断版本号
			if [ "$VERSION_ID" == "12" ]; then
				m_EnvAPT+=" gcc make wget nasm libchromaprint-dev libmysofa-dev libcodec2-dev libdrm-dev libdc1394-dev librabbitmq-dev libczmq-dev libgnutls28-dev libopenal-dev libopenjp2-7-dev libxml2-dev frei0r-plugins-dev libbs2b-dev libbluray-dev lv2-dev liblilv-dev libzvbi-dev libwebp-dev libvpx-dev libvorbis-dev libtheora-dev libspeex-dev libsoxr-dev libmodplug-dev libass-dev libx264-dev libx265-dev libfreetype-dev libfribidi-dev libharfbuzz-dev libgmp-dev libmp3lame-dev libopus-dev libxvidcore-dev libsdl2-dev libzip-dev"
				m_EnvAPT+=" libmariadb3 libmongoc-1.0-0 libbson-1.0-0 libsrt-openssl-dev libzimg-dev libplacebo-dev libdav1d-dev libaom-dev libfontconfig-dev libgme-dev libsnappy-dev libopenmpt-dev libjxl-dev libvpl-dev"
			elif [ "$VERSION_ID" == "13" ]; then
				m_EnvAPT+=" libmariadb3 libmongoc-1.0-0t64 libbson-1.0-0t64 libssl-dev libavcodec61 libavfilter10 libavformat61 libswresample5 libswscale8 libavdevice61"
			else
				echo -e "\033[31mThis script only supports debian 12 and 13.\033[0m"
				exit 1
			fi
			echo -e "\033[35mdebian开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			apt install $m_EnvAPT -y
			echo -e "\033[36mdebian依赖库安装完毕\033[0m"
			if [ "$VERSION_ID" == "12" ]; then
				if [ ! -e /usr/local/ffmpeg-xengine/bin/ffmpeg ]; then
					# 安装ffmpeg
					echo -e "\033[35mFFMpeg没有被安装,开始安装FFMpeg库\033[0m"
					rm -f ./ffmpeg-7.1.1.tar.gz
					wget https://ffmpeg.org/releases/ffmpeg-7.1.1.tar.gz
					tar zxvf ./ffmpeg-7.1.1.tar.gz
					cd ffmpeg-7.1.1

					m_EvnBuildCmd="--prefix=/usr/local/ffmpeg-xengine --pkg-config=pkg-config --enable-gpl --enable-gnutls --enable-nonfree --enable-version3 --enable-pic"
					m_EvnBuildCmd+=" --disable-debug --disable-static --enable-shared"
					# 图像
					m_EvnBuildCmd+=" --enable-libopenjpeg --enable-libwebp --enable-sdl2 --enable-libjxl"
					# 音频
					m_EvnBuildCmd+=" --enable-libplacebo --enable-libgme --enable-libopenmpt --enable-chromaprint --enable-libmysofa --enable-libcodec2 --enable-openal --enable-libxvid --enable-lv2 --enable-libvorbis --enable-libspeex --enable-libsoxr --enable-libmodplug --enable-libbs2b --enable-libmp3lame --enable-libopus"
					# 视频
					m_EvnBuildCmd+=" --enable-libdav1d --enable-libaom --enable-frei0r --enable-libbluray --enable-libzvbi --enable-libvpx --enable-libtheora --enable-libx264 --enable-libx265"
					# 滤镜
					m_EvnBuildCmd+=" --enable-fontconfig --enable-libfreetype --enable-libfribidi --enable-libharfbuzz --enable-libass --enable-libzimg"
					# 计算
					m_EvnBuildCmd+=" --enable-gmp"
					# 通信
					m_EvnBuildCmd+=" --enable-libzmq --enable-librabbitmq --enable-libdc1394"
					# 硬件加速
					m_EvnBuildCmd+=" --enable-libdrm --enable-libvpl"
					# 三方库
					m_EvnBuildCmd+=" --enable-libxml2 --enable-zlib --enable-libsnappy"
					# 附加处理
					m_EvnBuildCmd+=" --enable-filter=drawtext"
					# 附加信息
					m_EvnBuildCmd+=" --extra-ldflags="-Wl,-rpath=/usr/local/ffmpeg-xengine/lib""

					./configure $m_EvnBuildCmd
					make
					make install
					make clean
					ldconfig
					cd ..
				fi
			fi
		fi
	fi
	#fedora
	if [ "$m_EnvRelease" -eq "2" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，不执行环境依赖库安装。。。\033[0m"
		else
			echo -e "\033[35mfedora开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
			m_EnvRPM+=" mysql-libs ffmpeg-free"
			dnf install $m_EnvRPM -y
			echo -e "\033[36mdeb依赖库安装完毕\033[0m"
		fi
	fi
	#Macos
	if [ "$m_EnvRelease" -eq "20" ] ; then
		if [ "$m_EnvInsBreak" -eq "1" ] ; then
			echo -e "\033[34m检查你的选项禁用了环境检查，不执行环境依赖库安装。。。\033[0m"
		else
			echo -e "\033[35mmac开始安装依赖库,如果安装失败，请更换安装源在执行一次\033[0m"
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
		fi
	
		if [ "$m_bDownload" -eq "1" ] ; then
			echo -e "\033[36m没有检查到文件，需要下载,文件下载中。。。\033[0m"
			git clone https://github.com/libxengine/libxengine.git
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
		if [ "$m_EnvRelease" -eq "20" ] ; then
			sudo mkdir -p /usr/local/include
			sudo mkdir -p /usr/local/lib
			sudo cp -rf ./XEngine_Include /usr/local/include
		else
			cp -rf ./XEngine_Include /usr/local/include
		fi
		echo -e "\033[45;37m安装头文件完毕\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "4" ] || [ "$m_EnvInstall" -eq "6" ] ; then 
		echo -e "\033[34m检查到你需要删除SDK头文件，正在删除中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "20" ] ; then
			sudo rm -rf /usr/local/include/XEngine_Include
		else
			rm -rf /usr/local/include/XEngine_Include
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
				if [ "$m_EnvRelease" -eq "1" ] || [ "$m_EnvRelease" -eq "2" ] ; then
					cp -rf $PathFile /usr/lib64/$file
				elif [ "$m_EnvRelease" -eq "11" ] ; then
					cp -rf $PathFile /usr/local/lib/$file
				else
					sudo cp -rf $PathFile /usr/local/lib/$file
				fi	
			fi
		fi
	done
}
#安装库文件
function InstallEnv_SdkShared()
{
	if [ "$m_EnvInstall" -eq "2" ] || [ "$m_EnvInstall" -eq "3" ] ; then
		echo -e "\033[34m检查到你需要安装SDK共享库，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "20" ] ; then
			m_EnvDir=$(pwd)/XEngine_Mac
		else
			m_EnvDir=$(pwd)/XEngine_Linux
		fi
		InstallEnv_CopyModule $m_EnvDir
		if [ "$m_EnvRelease" -eq "1" ] || [ "$m_EnvRelease" -eq "2" ] || [ "$m_EnvRelease" -eq "10" ] || [ "$m_EnvRelease" -eq "11" ] ; then
			ldconfig
		fi
		echo -e "\033[45;37m安装共享库成功\033[0m"
	fi
	if [ "$m_EnvInstall" -eq "5" ] || [ "$m_EnvInstall" -eq "6" ] ; then
		echo -e "\033[34m检查到你需要删除SDK共享库，正在删除中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "1" ] || [ "$m_EnvRelease" -eq "2" ] ; then
			rm -rf /usr/lib64/libXEngine_*.so
			rm -rf /usr/lib64/libXClient_*.so
			rm -rf /usr/lib64/libNetHelp_*.so
			rm -rf /usr/lib64/libHelpComponents_*.so
			rm -rf /usr/lib64/libRfcComponents_*.so
			rm -rf /usr/lib64/libStreamMedia_*.so
			rm -rf /usr/local/ffmpeg-xengine
			ldconfig
		elif [ "$m_EnvRelease" -eq "10" ] || [ "$m_EnvRelease" -eq "11" ] ; then
			rm -rf /usr/local/lib/libXEngine_*.so
			rm -rf /usr/local/lib/libXClient_*.so
			rm -rf /usr/local/lib/libNetHelp_*.so
			rm -rf /usr/local/lib/libHelpComponents_*.so
			rm -rf /usr/local/lib/libRfcComponents_*.so
			rm -rf /usr/local/lib/libStreamMedia_*.so
			rm -rf /usr/local/ffmpeg-xengine
			ldconfig
		elif [ "$m_EnvRelease" -eq "20" ] ; then
			sudo rm -rf /usr/local/lib/libXEngine_*.so
			sudo rm -rf /usr/local/lib/libXClient_*.so
			sudo rm -rf /usr/local/lib/libNetHelp_*.so
			sudo rm -rf /usr/local/lib/libHelpComponents_*.so
			sudo rm -rf /usr/local/lib/libRfcComponents_*.so
			sudo rm -rf /usr/local/lib/libStreamMedia_*.so
		fi
		echo -e "\033[45;37m删除共享库成功\033[0m"
	fi
}
#安装程序
function InstallEnv_Execution()
{
	if [ "$m_EnvInstall" -eq "2" ] || [ "$m_EnvInstall" -eq "3" ] ; then
		echo -e "\033[34m检查到你需要安装程序，正在安装中。。。\033[0m"
		if [ "$m_EnvRelease" -eq "20" ] ; then
			cp -rf ./XEngine_Mac/xengine /usr/local/bin/xengine
		else
			cp -rf ./XEngine_Linux/xengine /usr/local/bin/xengine
		fi
		chmod 777 /usr/local/bin/xengine
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
