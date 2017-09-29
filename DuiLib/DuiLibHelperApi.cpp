// ************************************************************************** //
// DuiLibHelperApi.h : interface of the CDuiLibHelperApi class
// Copyright(c)2016 by 孙彦春. All rights reserved.
//
// Abstract:
//   本文件中扩展了Duilib的一些函数功能
// 
// ********************  Version 1  *******************
// [维护人员]: 孙彦春            [维护日期]: 2016-06-11
// [维护内容]: 建立初版。
// 
// ************************************************************************** //
#include "stdafx.h"
#include "DuiLibHelperApi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DuiLib
{
	DWORD CovertRGB(DWORD nRgb_)
	{
		DWORD _dw = 0xFF000000;
		DWORD _dwR = GetRValue(nRgb_);
		_dwR = _dwR << 16;
		DWORD _dwG = GetGValue(nRgb_);
		_dwG = _dwG << 8;
		DWORD _dwB = GetBValue(nRgb_);
		_dw |= _dwR;
		_dw |= _dwG;
		_dw |= _dwB;
		return _dw;
	}
}