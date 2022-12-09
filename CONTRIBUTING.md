# Contributing guide

READ THIS FILE BEFORE CONTRIBUTING.

## How to run tests

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

5. Build a project and tests executables will appear in build directory

## VSCODE extensions

1. [xaver.clang-format](https://github.com/xaverh/vscode-clang-format)

## Check for clang-format

1. Check if you have clang-format on your machine. If no, [download it here](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.6).

```shell
clang-format --version
```

2. Copy config from [default vscode settings](./.default-vscode/default-settings.json) to `.vscode/settings.json`

3. Now your `c` files should format on save.

## Build / Debug

1. Copy [default-tasks.json](./.default-vscode/default-tasks.json) in `.vscode/tasks.json`. Now you can press `CTRL + SHIFT + B` in order to build project.

2. Copy [default-launch.json](./.default-vscode/default-launch.json) in `.vscode/launch.json`. Now you can press `F5` in order to run `main.exe` in debug mode. `gdb` must be installed on your machine. [how to debug in vscode](https://code.visualstudio.com/docs/editor/debugging)
