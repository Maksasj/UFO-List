## Getting started

For build instructions see [BUILD.md](./BUILD.md) file

## Navigation:

1. [How to run tests](#run-tests)
2. [VSCODE extensions that has to be installed](#vscode-extensions)

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
