#pragma once
/********************************************************************
//    Created:     2021/09/13  13:31:28
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Types.h
//    File Path:   D:\XEngine\XEngine_SourceCode
//    File Base:   XEngine_Types
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     类型定义头文件,必须加载
//    History:
*********************************************************************/
#ifdef _MSC_BUILD
#define _tcsxcmp strcmp
#define _tcsxncmp strncmp
#define _tcsxnicmp _strnicmp
#define _tcsxlen strlen
#define _tcsxcpy strcpy
#define _tcsxncpy strncpy
#define _tcsxtok strtok
#define _tcsxtok_s strtok_s
#define _tcsxcat strcat
#define _tcsxncat strncat
#define _tcsxchr strchr
#define _tcsxstr strstr
#define _tcsxfget fgets
#define _xtprintf printf
#define _xstprintf sprintf
#define _xsntprintf snprintf
#define _xtputenv _putenv
#define _xtgetenv getenv
#define _ttxof atof
#define _ttxoi atoi
#define _ttxoll atoll
#define _xtunlink _unlink
#define _xtopen _open
#define _xtpopen _popen
#define _xtfopen fopen
#define _xfseeki64 _fseeki64
#define _xtaccess _access
#define _xtstat _stat
#define _xtremove remove
#define _xtrename rename
#define _xtsetlocale setlocale
#define _stxscanf sscanf
#else
#define _tcsxcmp strcmp
#define _tcsxncmp strncmp
#define _tcsxnicmp strncasecmp
#define _tcsxlen strlen
#define _tcsxcpy strcpy
#define _tcsxncpy strncpy
#define _tcsxtok strtok
#define _tcsxtok_s strtok_r
#define _tcsxcat strcat
#define _tcsxncat strncat
#define _tcsxchr strchr
#define _tcsxstr strstr
#define _tcsxfget fgets
#define _xtprintf printf
#define _xstprintf sprintf
#define _xsntprintf snprintf
#define _xtputenv putenv
#define _xtgetenv getenv
#define _ttxof atof
#define _ttxoi atoi
#define _ttxoll atoll
#define _xtunlink unlink
#define _xtopen open
#define _xtpopen popen
#define _xtfopen fopen
#define _xfseeki64 fseeko
#define _xtaccess access
#define _xtstat stat
#define _xtremove remove
#define _xtrename rename
#define _xtsetlocale setlocale
#define _stxscanf sscanf
//其他函数转换
#define closesocket(a) close(a)
#define _pclose pclose
#define _tpclose pclose
#define _lseek lseek
#define _write write
#define _read read
#define _close close
#endif