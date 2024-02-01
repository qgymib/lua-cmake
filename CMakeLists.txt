cmake_minimum_required(VERSION 3.2)
project(lua)

###############################################################################
# Setup library
###############################################################################
add_library(liblua
    src/lapi.c
    src/lcode.c
    src/lctype.c
    src/ldebug.c
    src/ldo.c
    src/ldump.c
    src/lfunc.c
    src/lgc.c
    src/llex.c
    src/lmem.c
    src/lobject.c
    src/lopcodes.c
    src/lparser.c
    src/lstate.c
    src/lstring.c
    src/ltable.c
    src/ltm.c
    src/lundump.c
    src/lvm.c
    src/lzio.c
    src/lauxlib.c
    src/lbaselib.c
    src/lcorolib.c
    src/ldblib.c
    src/liolib.c
    src/lmathlib.c
    src/loadlib.c
    src/loslib.c
    src/lstrlib.c
    src/ltablib.c
    src/lutf8lib.c
    src/linit.c
)

target_include_directories(liblua
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

if (UNIX)
    target_compile_options(liblua PRIVATE -DLUA_USE_LINUX)
    target_link_libraries(liblua PRIVATE m)
endif ()

###############################################################################
# Patches
###############################################################################

option(LUA_PATCH_DISABLE_0000_UTF8_WIN32,
    "Disable UTF-8 support on Windows"
    OFF)
if (LUA_PATCH_DISABLE_0000_UTF8_WIN32)
    target_compile_options(liblua
        PRIVATE
            -DLUA_PATCH_DISABLE_0000_UTF8_WIN32
    )
else ()
    target_sources(liblua
        PRIVATE
            src/lua_patch_0000_utf8_win32.c
    )
endif ()

###############################################################################
# Setup executable
###############################################################################
add_executable(lua
    "src/lua.c"
)
target_link_libraries(lua
    PRIVATE
        liblua
)

add_executable(luac
    "src/luac.c"
)
target_link_libraries(luac
    PRIVATE
        liblua
)
