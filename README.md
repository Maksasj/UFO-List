Navigation:

1. [How to build project](#project-build)
2. [How to run tests](#run-tests)
3. [VSCODE extensions that has to be installed](#vscode-extensions)

## Project build

### Prerequisites:

-   [Cmake](https://cmake.org/download/) executable
-   [Ninja](https://github.com/ninja-build/ninja/releases) executable

Add paths to these executables in `PATH` environment variable.

### Steps to build:

1. Run this command in project root. This will generate cmake configurations.

```shell
cmake -B build -G Ninja
```

2. Run this command in project root. This will build the project.

```shell
cmake --build build
```

TODO: add separate builds for debug and release

### Troubleshooting 

If cmake detects wrong compiler(probably devkitadv one), try to manually specify path to your compiler in *CMakeLists.txt* file, like so

```
set(CMAKE_C_COMPILER "PATH TO C COMPILER")
set(CMAKE_CXX_COMPILER "PATH TO C++ COMPILER")
```

3. main.exe will appear in `build/main` directory

## Run tests

In order to run all tests at once - build the project and run this command in `build` directory:

```shell
ctest
```

TODO: update tests documentation after adding gclados

## VSCODE extensions

1. [xaver.clang-format](https://github.com/xaverh/vscode-clang-format) (`clang-format` must be installed on your computer as an executable. Download full [LLVM package](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.2))
