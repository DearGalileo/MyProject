
// stdafx.cpp : 只包括标准包含文件的源文件
// Launcher.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
// 使用duilib必须（2） 骆小俊 2017-9-29
#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\DuiLib.lib")
#else
#pragma comment(lib, "..\\Release\\DuiLib.lib")
#endif
