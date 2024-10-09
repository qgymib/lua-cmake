# Allow UTF-8 paths on Windows

## Problem

A paths trouble appears on Windows OS when program which uses luajit is placed in a path which contains non-ASCII characters.

Usually on Linux, OS X and other posix and unix-like platforms paths are encoded as UTF-8, therefore no troubles with fopen() function.

On modern Windows versions all paths are encoded as UTF-16LE and also fopen() function on Windows always accepts ANSI-encoded paths, therefore because a codepage mismatch, fopen() think that file is not exists.

To resolve this trouble need to convert accepted path into UTF-16 from UTF-8 and use _wfopen() which accepts UTF-16 paths.

Checkout [Allow UTF-8 paths on Windows](https://github.com/LuaJIT/LuaJIT/commit/7115753e47c9dbcdf64f6e3ee074280fa908afdb) for original patch.

## Enabling

This patch is only enabled on Windows by default.

To disable it, turn on `LUA_PATCH_DISABLE_0000_UTF8_WIN32` when configure CMake.
