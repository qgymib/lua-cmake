#if !defined(__LUA_PATCH_0000_UTF8_WIN32_H__) && defined(_WIN32) && !defined(LUA_PATCH_DISABLE_0000_UTF8_WIN32)
#define __LUA_PATCH_0000_UTF8_WIN32_H__

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include <windows.h>
#include <stdio.h>

#define fopen(p, m)         lua_fopen_win32(p, m)
#define freopen(p, m, s)    lua_freopen_win32(p, m, s)

#ifdef __cplusplus
extern "C" {
#endif

char* lua_wide_to_utf8_win32(const WCHAR* str);
WCHAR* lua_utf8_to_wide_win32(const char* str);

FILE* lua_fopen_win32(const char* pathname, const char* mode);
FILE* lua_freopen_win32(const char* pathname, const char* mode, FILE* stream);

#ifdef __cplusplus
}
#endif

#endif
