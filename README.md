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

3. main.exe will appear in `build/main` directory

### Troubleshooting

If cmake detects wrong compiler(probably devkitadv one), try to manually specify path to your compiler in _CMakeLists.txt_ file, like so

```
set(CMAKE_C_COMPILER "PATH TO C COMPILER")
set(CMAKE_CXX_COMPILER "PATH TO C++ COMPILER")
```

## Run tests

1. Firstly, you need to clone [gclados repository](https://github.com/ArtiomTr/gclados) on your machine.

```shell
git clone https://github.com/ArtiomTr/gclados.git
```

2. Next, follow [gclados build instructions for release](https://github.com/ArtiomTr/gclados/blob/master/BUILD.md#release)

3. Then, `gclados.exe` will appear in `bin` directory. Next, move this executable somewhere on the disk, for example in `C:\Program Files\GcLaDOS\bin`, and add this directory in `PATH` environment variable.

4. To check if everything is fine, type this command in terminal (if executable was found, you won't get an error):

```shell
gclados
```

## VSCODE extensions

1. [xaver.clang-format](https://github.com/xaverh/vscode-clang-format) (`clang-format` must be installed on your computer as an executable. Download full [LLVM package](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.2))
