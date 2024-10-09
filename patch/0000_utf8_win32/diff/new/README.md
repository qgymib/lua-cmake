# lua-cmake

Provide modern cmake support for lua.

## Usage

Please add the branch you want to use as submodule.

For example, if you want to use official lua-5.4.6 release, you can use following command:

```bash
git submodule add -b official/lua-5.4.6 https://github.com/qgymib/lua-cmake.git third_party/lua
```

Then add to CMake build tree:

```cmake
add_subdirectory(third_party/lua)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        liblua
)
```

## Patch list

+ [0000_utf8_win32](patch/0000_utf8_win32/README.md)

## Branch

There are two kind of branch:
+ `official/*`: The source code is the same as official release, no modification is made.
+ `unofficial/*`: The source code is sync with official release, while some patches are appended to make Lua better. The patch details are listed on the branch's `README.md`.

For more details about how patch works, checkout [document](patch/README.md).

## License

The files from Lua source code are licensed under the [Lua License](https://www.lua.org/license.html), while the other parts are licensed under the [MIT License](LICENSE).
