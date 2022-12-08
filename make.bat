@ECHO OFF

cmake --build build && cd build/main && .\main.exe

cd ..\..
