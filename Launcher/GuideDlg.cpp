#include "stdafx.h"
#include "GuideDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DuiLib
{
	CGuideDlg::CGuideDlg(void) :
		m_pBtnOK(NULL),
		m_pBtnCancel(NULL),
		m_pLabel(NULL),
		m_pSlider(NULL),
		m_pEdit(NULL)
	{
		memset(m_pOption, 0, sizeof(m_pOption));// 快速初始化
	}

	CGuideDlg::~CGuideDlg(void)
	{
	}

	CDuiString CGuideDlg::GetSkinFolder()
	{
		static TCHAR _pPath[MAX_PATH];
		static bool _bFirstCall = true;
		if (_bFirstCall)
		{
			::GetModuleFileName(NULL, _pPath, MAX_PATH);
			::PathRemoveFileSpec(_pPath);
			_tcscat_s(_pPath, MAX_PATH, _T("\\Res"));//资源文件放在exe同目录下res文件夹中
		}
		return _pPath;
	};

	CDuiString CGuideDlg::GetSkinFile()
	{
		return _T("GuideDlg.xml");//xml文件名
	};

	LPCTSTR CGuideDlg::GetWindowClassName(void) const
	{
		return _T("CGuideDlg");
	};

	void CGuideDlg::InitWindow()
	{
		InitControlPtr();
		m_pSlider->SetMinValue(0);
		m_pSlider->SetMaxValue(100);
		m_pSlider->SetChangeStep(1);
	}

	void CGuideDlg::Notify(TNotifyUI& msg_)
	{
		// 点击事件
		if (msg_.sType == DUI_MSGTYPE_CLICK)
		{
			if (msg_.pSender == m_pBtnCancel)
			{
				Close(IDCANCEL);
				return;
			}
			else if (msg_.pSender == m_pBtnOK)
			{
				Close(IDOK);
				return;
			}
			else if (msg_.pSender == m_pOption[0])
			{
				m_pLabel->SetBkImage(_T("labelbk0.jpg"));
			}
			else if (msg_.pSender == m_pOption[1])
			{
				m_pLabel->SetBkImage(_T("labelbk1.jpg"));
			}
		}
		// 数值改变事件
		else if(msg_.sType == DUI_MSGTYPE_VALUECHANGED)
		{
			if (msg_.pSender == m_pSlider)
			{
				// int转换成cstrig
				int value = m_pSlider->GetValue();
				CString _str;
				_str.Format(_T("%d"), value);
				m_pEdit->SetText(_str);
			}
		}
		// 文本改变事件
		else if (msg_.sType == DUI_MSGTYPE_TEXTCHANGED)
		{
			if (msg_.pSender == m_pEdit)
			{
				// cstrig转换成double
				int _value;
				CString _strText = m_pEdit->GetText();
				LPCTSTR _pszText = _strText.GetBuffer();
				_value = (int)_tstof(_pszText);

				if (_value < 0) 
				{
					m_pEdit->SetText(_T("0"));
					_value = 0;
				} 
				else if (_value > 100)
				{
					m_pEdit->SetText(_T("100"));
					_value = 100;
				}
				m_pSlider->SetValue(_value);
			}
		}
		return __super::Notify(msg_);
	}
	// 本函数实现控件与xml中控件的绑定
	void CGuideDlg::InitControlPtr()
	{
		// Botton 控件 骆小俊 2017-9-26
		struct _BtnNameMap
		{
			CButtonUI** m_ppBtn; LPCTSTR m_pszName;
		}__BtnNameMap[] =
		{
			{&m_pBtnOK, _T("BtnOK")},
			{&m_pBtnCancel, _T("BtnCancel")},
		};
		for (int _i = 0; _i != _countof(__BtnNameMap); ++_i)
		{
			*(__BtnNameMap[_i].m_ppBtn) = static_cast<CButtonUI*>(m_PaintManager.FindControl(__BtnNameMap[_i].m_pszName));
		}
		// Option 控件 骆小俊 2017-9-26
		struct _OptNameMap
		{
			COptionUI** m_ppOpt; LPCTSTR m_pszName;
		}__OptNameMap[] =
		{
			{ &m_pOption[0], _T("m_pOption0") },
			{ &m_pOption[1], _T("m_pOption1") },
		};
		for (int _i = 0; _i != _countof(__OptNameMap); ++_i)
		{
			*(__OptNameMap[_i].m_ppOpt) = static_cast<COptionUI*>(m_PaintManager.FindControl(__OptNameMap[_i].m_pszName));
		}
		// Label控件  骆小俊 2017-9-26
		struct _LabelNameMap
		{
			CLabelUI** m_ppLabel; LPCTSTR m_pszName;
		}__LabelNameMap[] = 
		{
			{&m_pLabel, _T("LabelPicture")},
		};
		for (int _i = 0; _i != _countof(__LabelNameMap); ++_i)
		{
			*(__LabelNameMap[_i].m_ppLabel) = static_cast<CLabelUI*>(m_PaintManager.FindControl(__LabelNameMap[_i].m_pszName));
		}

		// Slider控件  骆小俊 2017-9-26
		struct _SliderNameMap
		{
			CSliderUI** m_ppSlider; LPCTSTR m_pszName;
		}__SliderNameMap[] =
		{
			{ &m_pSlider, _T("m_pSlider") },
		};
		for (int _i = 0; _i != _countof(__SliderNameMap); ++_i)
		{
			*(__SliderNameMap[_i].m_ppSlider) = static_cast<CSliderUI*>(m_PaintManager.FindControl(__SliderNameMap[_i].m_pszName));
		}
		// Edit控件  骆小俊 2017-9-26
		struct _EditNameMap
		{
			CEditUI** m_ppEditUI; LPCTSTR m_pszName;
		}__EditNameMap[] = 
		{
			{&m_pEdit, _T("m_pEdit")},
		};
		for (int _i = 0; _i != _countof(__EditNameMap); ++_i)
		{
			*(__EditNameMap[_i].m_ppEditUI) = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(__EditNameMap[_i].m_pszName));
		}
	}
}
// 其他：
	// 动态界面 骆小俊 2017-9-26
	//void CGuideDlg::_UpdateUI()
	//{
	//	struct _UIMap
	//	{
	//		// 可变参数
	//		LPCTSTR m_pParamName6;
	//		LPCTSTR m_pParamName7;
	//		LPCTSTR m_pParamName8;
	//		// 显示状态
	//		bool m_bShow6;
	//		bool m_bShow7;
	//		bool m_bShow8;
	//		// 图片文件
	//		LPCTSTR m_pPicName;
	//	}__UIMap[] = 
	//	{
	//		{_T("长度X(mm)"), _T("宽度Y(mm)"), _T(""), true, true, false, _T("Geo0.png")},
	//		{_T("长度X(mm)"), _T("宽度Y(mm)"), _T("半径r(mm)"), true, true, true, _T("Geo1.png")},
	//		{_T("半径R(mm)"), _T(""), _T(""), true, false, false, _T("Geo2.png")},
	//		{_T("长轴X(mm)"), _T("短轴Y(mm)"), _T(""), true, true, false, _T("Geo3.png")},
	//		{_T("宽度L(mm)"), _T("高度H(mm)"), _T(""), true, true, false, _T("Geo4.png")},
	//	};
	//	// 修改可变参数表
	//	m_pLabelParam[6]->SetText(__UIMap[m_nGeoIndex].m_pParamName6);
	//	m_pLabelParam[7]->SetText(__UIMap[m_nGeoIndex].m_pParamName7);
	//	m_pLabelParam[8]->SetText(__UIMap[m_nGeoIndex].m_pParamName8);
	//	// 修改可变控件可见性
	//	m_pLabelParam[6]->SetVisible(__UIMap[m_nGeoIndex].m_bShow6);
	//	m_pEditParam[6]->SetVisible(__UIMap[m_nGeoIndex].m_bShow6);
	//	m_pLabelParam[7]->SetVisible(__UIMap[m_nGeoIndex].m_bShow7);
	//	m_pEditParam[7]->SetVisible(__UIMap[m_nGeoIndex].m_bShow7);
	//	m_pLabelParam[8]->SetVisible(__UIMap[m_nGeoIndex].m_bShow8);
	//	m_pEditParam[8]->SetVisible(__UIMap[m_nGeoIndex].m_bShow8);
	//	// 修改引导图片
	//	m_pPicture->SetBkImage(__UIMap[m_nGeoIndex].m_pPicName);
	//}