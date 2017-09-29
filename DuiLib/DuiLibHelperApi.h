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
#pragma once
namespace DuiLib
{
	UILIB_API DWORD CovertRGB(DWORD nRgb_);
	inline void SetEnable(CButtonUI* pBtn_, bool bEnable_)
	{
		if (pBtn_)
			pBtn_->SetEnabled(bEnable_);
	}
	inline void SetEnable(CEditUI* pEdit_, bool bEnable_)
	{
		if (pEdit_)
			pEdit_->SetEnabled(bEnable_);
	}
	inline void SetText(CLabelUI* pLabel_, LPCTSTR strText_)
	{
		if (pLabel_)
			pLabel_->SetText(strText_);
	}
	inline void SetVisble(CControlUI* pLabel_, bool bVisible_)
	{
		if (pLabel_)
			pLabel_->SetVisible(bVisible_);
	}
	inline void SetValueD(CLabelUI* pLabel_, double nValue_, double nTimes_, int nPrecision_ = 3)
	{
		if (!pLabel_)
			return ;

		CDuiString _str;
		_str.Format(_T("%.*lf"), nPrecision_, nValue_ * nTimes_);
		pLabel_->SetText(_str);
	}

	inline bool SelectItemCombo(CComboUI* pCombo_, int nIndex_)
	{
		if (!pCombo_)
			return false;
		return pCombo_->SelectItem(nIndex_);
	}

	inline bool SelectItemCombo(CComboUI* pCombo_, LPCTSTR pszText_)
	{
		if (!pCombo_)
			return false;
		return pCombo_->SelectItem(pszText_);
	}

	inline bool SelComboByUserData(CComboUI* pCombo_, CDuiString strUserdata_)
	{
		if (!pCombo_)
			return false;
		int _nCount = pCombo_->GetCount();
		for (int _i = 0; _i != _nCount; ++_i)
		{
			CControlUI* _pControlUI = pCombo_->GetItemAt(_i);
			CDuiString _strUserData = _pControlUI->GetUserData();
			if (_strUserData.Compare(strUserdata_) == 0)
			{
				pCombo_->SelectItem(_i);
				return true;
			}
		}
		return false;
	}

	inline bool GelCurSelUserData(CComboUI* pCombo_, CDuiString& strUserdata_)
	{
		if (!pCombo_)
			return false;
		CListLabelElementUI* _pListLabelElementUI = pCombo_->GetCurSelElement();
		if (!_pListLabelElementUI)
			return false;
		strUserdata_ = _pListLabelElementUI->GetUserData();
		return true;
	}

	inline bool GetCurSelCombo(const CComboUI* pCombo_, int& nIndex_)
	{
		if (!pCombo_) return false;
		nIndex_ = pCombo_->GetCurSel();
		return true;
	}

	inline bool GetCheckBoxStatus(const CCheckBoxUI* pCheckUI_, bool& bCheckStatus_)
	{
		if (!pCheckUI_)
			return false;
		bCheckStatus_ = pCheckUI_->GetCheck();
		return true;
	}

	inline bool SetCheckBoxStatus(CCheckBoxUI* pCheckUI_, bool bCheckStatus_)
	{
		if (!pCheckUI_)
			return false;
		pCheckUI_->SetCheck(bCheckStatus_);
		return true;
	}
}