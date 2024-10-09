#include "lua_patch_0000_utf8_win32.h"

#if defined(__LUA_PATCH_0000_UTF8_WIN32_H__)

#include <assert.h>

WCHAR* lua_utf8_to_wide_win32(const char* str)
{
    int multi_byte_sz = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    size_t buf_sz = multi_byte_sz * sizeof(WCHAR);

    WCHAR* buf = (WCHAR*)malloc(buf_sz);
    int ret = MultiByteToWideChar(CP_UTF8, 0, str, -1, (WCHAR*)buf, multi_byte_sz);
    assert(ret == multi_byte_sz);

    return buf;
}

char* lua_wide_to_utf8_win32(const WCHAR* str)
{
    int utf8_sz = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
    char* utf8 = malloc(utf8_sz + 1);
    if (utf8 == NULL)
    {
        return NULL;
    }

    int ret = WideCharToMultiByte(CP_UTF8, 0, str, -1, utf8, utf8_sz, NULL, NULL);
    assert(ret == utf8_sz);
    utf8[utf8_sz] = '\0';

    return utf8;
}

FILE* lua_fopen_win32(const char* pathname, const char* mode)
{
    wchar_t* filenamew = lua_utf8_to_wide_win32(pathname);
    wchar_t* modew = lua_utf8_to_wide_win32(mode);

    FILE* file = NULL;
    errno_t errcode = _wfopen_s(&file, filenamew, modew);
    free(filenamew);
    free(modew);

    if (errcode != 0)
    {
        errno = errcode;
        return NULL;
    }

    return file;
}

FILE* lua_freopen_win32(const char* pathname, const char* mode, FILE* stream)
{
    wchar_t* filenamew = lua_utf8_to_wide_win32(pathname);
    wchar_t* modew = lua_utf8_to_wide_win32(mode);

    FILE* file = NULL;
    errno_t errcode = _wfreopen_s(&file, filenamew, modew, stream);
    free(filenamew);
    free(modew);

    if (errcode != 0)
    {
        errno = errcode;
        return NULL;
    }

    return file;
}

#endif
