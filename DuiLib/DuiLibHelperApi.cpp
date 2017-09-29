// ************************************************************************** //
// DuiLibHelperApi.h : interface of the CDuiLibHelperApi class
// Copyright(c)2016 by ���崺. All rights reserved.
//
// Abstract:
//   ���ļ�����չ��Duilib��һЩ��������
// 
// ********************  Version 1  *******************
// [ά����Ա]: ���崺            [ά������]: 2016-06-11
// [ά������]: �������档
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