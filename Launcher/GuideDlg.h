#pragma once

namespace DuiLib
{
	class CGuideDlg : public DuiLib::WindowImplBase
	{
	public:
		CGuideDlg(void);	// ���캯��
		~CGuideDlg(void);
	public:
		virtual void InitWindow();	//��ʼ������
	protected:
		virtual DuiLib::CDuiString GetSkinFolder();		// ��ȡ�ļ�·��
		virtual DuiLib::CDuiString GetSkinFile();		// ��ȡ�ļ���
		virtual LPCTSTR GetWindowClassName(void) const;	// ��ȡ����
		virtual void Notify(TNotifyUI& msg_);			// ������Ϣ
		void InitControlPtr();	//�󶨽���������
	protected:
		CLabelUI* m_pLabel;		//��ǩ
		COptionUI* m_pOption[2];//��ѡ
		CSliderUI* m_pSlider;	// ������
		CEditUI* m_pEdit;		// �༭��
		CButtonUI* m_pBtnOK;    // ȷ��
		CButtonUI* m_pBtnCancel;// ȡ��
	};
}
