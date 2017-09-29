#pragma once

namespace DuiLib
{
	class CGuideDlg : public DuiLib::WindowImplBase
	{
	public:
		CGuideDlg(void);	// 构造函数
		~CGuideDlg(void);
	public:
		virtual void InitWindow();	//初始化窗口
	protected:
		virtual DuiLib::CDuiString GetSkinFolder();		// 获取文件路径
		virtual DuiLib::CDuiString GetSkinFile();		// 获取文件名
		virtual LPCTSTR GetWindowClassName(void) const;	// 获取类名
		virtual void Notify(TNotifyUI& msg_);			// 处理消息
		void InitControlPtr();	//绑定界面与数据
	protected:
		CLabelUI* m_pLabel;		//标签
		COptionUI* m_pOption[2];//单选
		CSliderUI* m_pSlider;	// 滑动条
		CEditUI* m_pEdit;		// 编辑框
		CButtonUI* m_pBtnOK;    // 确定
		CButtonUI* m_pBtnCancel;// 取消
	};
}
