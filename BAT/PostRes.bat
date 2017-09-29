@echo off
if "%1" == "Debug" (
 set CurConfig=Debug
) else if "%1" == "Release" (
 set CurConfig=Release
) else (
 echo 未知参数!
 exit /B 1
)
set SOU_PATH=%cd%\Res
cd ..
set DES_PATH=%cd%

Rem 拷贝对话框xml文件和图片
xcopy "%SOU_PATH%\*.*" "%DES_PATH%\%CurConfig%\Res\"  /s  /e