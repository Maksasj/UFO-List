# Project build

## Prerequisites:

-   [Cmake](https://cmake.org/download/) executable
-   [Ninja](https://github.com/ninja-build/ninja/releases) executable

Add paths to these executables in `PATH` environment variable. [how to add environment variable on windows](<https://learn.microsoft.com/en-us/previous-versions/office/developer/sharepoint-2010/ee537574(v=office.14)#to-add-a-path-to-the-path-environment-variable>)

TODO: add custom commands to build for debug and release.

## Steps to build:

1. Run this command in project root. This will generate cmake configurations.

```shell
cmake -B build -G Ninja
```

2. Run this command in project root. This will build the project.

```shell
cmake --build build
```

3. main.exe will appear in `build/main` directory

## Troubleshooting

If cmake detects wrong compiler(probably devkitadv one), try to manually specify path to your compiler in first command:

```shell
cmake -DCMAKE_C_COMPILER="PATH TO C COMPILER" -B build -G Ninja
```
