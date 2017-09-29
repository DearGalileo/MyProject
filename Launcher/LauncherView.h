
// LauncherView.h : CLauncherView ��Ľӿ�
//

#pragma once


class CLauncherView : public CView
{
protected: // �������л�����
	CLauncherView();
	DECLARE_DYNCREATE(CLauncherView)

// ����
public:
	CLauncherDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CLauncherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFuck();
};

#ifndef _DEBUG  // LauncherView.cpp �еĵ��԰汾
inline CLauncherDoc* CLauncherView::GetDocument() const
   { return reinterpret_cast<CLauncherDoc*>(m_pDocument); }
#endif

