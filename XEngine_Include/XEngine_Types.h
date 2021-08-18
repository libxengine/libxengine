#pragma once
#ifdef _WINDOWS
#define F_OK 0
#define SHUT_RDWR SD_BOTH
#define MAP_FAILED NULL
#define HFILE int

#define dlclose FreeLibrary
#else
typedef int XHTHREAD;
//LINUX下面使用
#include <wchar.h>
#define _fseeki64 fseeko
//编码版本转换
#ifdef _UNICODE
#define _stprintf swprintf
#define _stprintf_s swprintf
#define _tprintf wprintf
#define _tprintf_s wprintf
#define _sntprintf snprintf
#define _tcscpy_s(a,b,c) wcscpy(a,c)
#define _tcscpy wcscpy
#define _tcslen wcslen
#define _ttoi wtoi
#define _ttoi64 wtoll
#define _ttof(a) wtof(a);
#define _tcscmp wcscmp
#define _tcsncmp wcsncmp
#define _tcsicmp wcscasecmp
#define _tcsicmp wcscasecmp
#define _tcsnicmp wcsncasecmp
#define _tcsfgets fgetws
#define _tcstok wcstok
#define _tcstok_s wcstok_r
#define _tcscspn wcscspn
#define _tcsncpy_s wcsncpy
#define _tcschr wcschr
#define _tcscat(a,c) strcat(a,c)
#define _tcscat_s(a,b,c) wcscat(a,c)
#define _tcsstr wcsstr
#define _tstat stat
#define _tcstoull wcstoull
#define _tcstoul wcstoul
#define _tcstoi64 wcstoll
#define _tcstol wcstol
#define _tfopen wfopen
#define _tcsrchr wcschr
#define _tfopen_s(a,b,c) freopen(b,c,a)
#define _stscanf swscanf
#define _stscanf_s swscanf
#define wcsmcpy_s(a,b,c,d) memcpy(a,c,d)
#define closesocket(a) close(a)
#define _topen open
#define _lseeki64 lseek64
#define _write write
#define _close close
#define _tcsdup wcsdup
#define _taccess access
#define _tsetlocale setlocale
#else
#define _stprintf sprintf
#define _stprintf_s sprintf
#define _sntprintf snprintf
#define _tprintf printf
#define _tprintf_s printf
#define _tcscpy_s(a,b,c) strcpy(a,c)
#define _tcscpy strcpy
#define _tcsncpy strncpy
#define _tcsncpy_s(a,b,c,d) strncpy(a,c,d)
#define _tcslen strlen
#define _ttoi atoi
#define _ttoi64(a) atoll(a)
#define _ttof(a) atof(a)
#define _tcscmp strcmp
#define _tcsncmp strncmp
#define _tcsicmp strcasecmp
#define _tcsnicmp strncasecmp
#define _tcsfget fgets
#define _tcstok strtok
#define _tcstok_s strtok_r
#define _tcscspn strcspn
#define _tcschr strchr
#define _tcscat(a,b) strcat(a,b)
#define _tcsncat(a,b,c) strncat(a,b,c)
#define _tcscat_s(a,b,c) strcat(a,c)
#define _tcsstr strstr
#define _tcscanf_s sscanf
#define _tstat stat
#define _tcstoull strtoull
#define _tcstoul strtoul
#define _tcstoi64 strtoll
#define _tcstol strtol
#define _tfopen fopen
#define _tcsrchr strchr
#define _tfopen_s(a,b,c) freopen(b,c,a)
#define _stscanf sscanf
#define _stscanf_s sscanf
#define _sntprintf_s snprintf
#define memcpy_s(a,b,c,d) memcpy(a,c,d)
#define closesocket(a) close(a)
#define _topen open
#define _tpopen popen
#define _pclose pclose
#define _lseek lseek
#define _lseeki64 lseek64
#define _write write
#define _close close
#define _tcsdup strdup
#define _taccess access
#define _tsetlocale setlocale
#define __stat64 stat64
#define _stat64 stat64
#define _tunlink unlink
#define _tremove remove
#define _trename rename
#endif
#endif
