# Project build

## Prerequisites:

-   [Cmake](https://cmake.org/download/) executable
-   [Ninja](https://github.com/ninja-build/ninja/releases) executable

Add paths to these executables in `PATH` environment variable. [how to add environment variable on windows](<https://learn.microsoft.com/en-us/previous-versions/office/developer/sharepoint-2010/ee537574(v=office.14)#to-add-a-path-to-the-path-environment-variable>)

## Steps to build:

### Debug

```shell
cmake -DCMAKE_BUILD_TYPE=Debug -B cmake-build-debug -G Ninja
cmake --build cmake-build-debug
```

### Release

```shell
cmake -DCMAKE_BUILD_TYPE=Release -B cmake-build-release -G Ninja
cmake --build cmake-build-release
```

## Troubleshooting

If cmake detects wrong compiler(probably devkitadv one), try to manually specify path to your compiler in first command:

```shell
cmake -DCMAKE_C_COMPILER="PATH TO C COMPILER" -B cmake-build-debug -G Ninja
```
