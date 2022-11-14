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

### Run tests

In order to run all tests at once - run this command in `build` directory:

```shell
ctest
```

TODO: update tests documentation after adding gclados
