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
		memset(m_pOption, 0, sizeof(m_pOption));// ���ٳ�ʼ��
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
			_tcscat_s(_pPath, MAX_PATH, _T("\\Res"));//��Դ�ļ�����exeͬĿ¼��res�ļ�����
		}
		return _pPath;
	};

	CDuiString CGuideDlg::GetSkinFile()
	{
		return _T("GuideDlg.xml");//xml�ļ���
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
		// ����¼�
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
		// ��ֵ�ı��¼�
		else if(msg_.sType == DUI_MSGTYPE_VALUECHANGED)
		{
			if (msg_.pSender == m_pSlider)
			{
				// intת����cstrig
				int value = m_pSlider->GetValue();
				CString _str;
				_str.Format(_T("%d"), value);
				m_pEdit->SetText(_str);
			}
		}
		// �ı��ı��¼�
		else if (msg_.sType == DUI_MSGTYPE_TEXTCHANGED)
		{
			if (msg_.pSender == m_pEdit)
			{
				// cstrigת����double
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
	// ������ʵ�ֿؼ���xml�пؼ��İ�
	void CGuideDlg::InitControlPtr()
	{
		// Botton �ؼ� ��С�� 2017-9-26
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
		// Option �ؼ� ��С�� 2017-9-26
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
		// Label�ؼ�  ��С�� 2017-9-26
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

		// Slider�ؼ�  ��С�� 2017-9-26
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
		// Edit�ؼ�  ��С�� 2017-9-26
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
// ������
	// ��̬���� ��С�� 2017-9-26
	//void CGuideDlg::_UpdateUI()
	//{
	//	struct _UIMap
	//	{
	//		// �ɱ����
	//		LPCTSTR m_pParamName6;
	//		LPCTSTR m_pParamName7;
	//		LPCTSTR m_pParamName8;
	//		// ��ʾ״̬
	//		bool m_bShow6;
	//		bool m_bShow7;
	//		bool m_bShow8;
	//		// ͼƬ�ļ�
	//		LPCTSTR m_pPicName;
	//	}__UIMap[] = 
	//	{
	//		{_T("����X(mm)"), _T("���Y(mm)"), _T(""), true, true, false, _T("Geo0.png")},
	//		{_T("����X(mm)"), _T("���Y(mm)"), _T("�뾶r(mm)"), true, true, true, _T("Geo1.png")},
	//		{_T("�뾶R(mm)"), _T(""), _T(""), true, false, false, _T("Geo2.png")},
	//		{_T("����X(mm)"), _T("����Y(mm)"), _T(""), true, true, false, _T("Geo3.png")},
	//		{_T("���L(mm)"), _T("�߶�H(mm)"), _T(""), true, true, false, _T("Geo4.png")},
	//	};
	//	// �޸Ŀɱ������
	//	m_pLabelParam[6]->SetText(__UIMap[m_nGeoIndex].m_pParamName6);
	//	m_pLabelParam[7]->SetText(__UIMap[m_nGeoIndex].m_pParamName7);
	//	m_pLabelParam[8]->SetText(__UIMap[m_nGeoIndex].m_pParamName8);
	//	// �޸Ŀɱ�ؼ��ɼ���
	//	m_pLabelParam[6]->SetVisible(__UIMap[m_nGeoIndex].m_bShow6);
	//	m_pEditParam[6]->SetVisible(__UIMap[m_nGeoIndex].m_bShow6);
	//	m_pLabelParam[7]->SetVisible(__UIMap[m_nGeoIndex].m_bShow7);
	//	m_pEditParam[7]->SetVisible(__UIMap[m_nGeoIndex].m_bShow7);
	//	m_pLabelParam[8]->SetVisible(__UIMap[m_nGeoIndex].m_bShow8);
	//	m_pEditParam[8]->SetVisible(__UIMap[m_nGeoIndex].m_bShow8);
	//	// �޸�����ͼƬ
	//	m_pPicture->SetBkImage(__UIMap[m_nGeoIndex].m_pPicName);
	//}