
// LauncherView.cpp : CLauncherView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Launcher.h"
#endif

#include "LauncherDoc.h"
#include "LauncherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLauncherView

IMPLEMENT_DYNCREATE(CLauncherView, CView)

BEGIN_MESSAGE_MAP(CLauncherView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLauncherView ����/����

CLauncherView::CLauncherView()
{
	// TODO: �ڴ˴���ӹ������

}

CLauncherView::~CLauncherView()
{
}

BOOL CLauncherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLauncherView ����

void CLauncherView::OnDraw(CDC* /*pDC*/)
{
	CLauncherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLauncherView ��ӡ

BOOL CLauncherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLauncherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLauncherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CLauncherView ���

#ifdef _DEBUG
void CLauncherView::AssertValid() const
{
	CView::AssertValid();
}

void CLauncherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLauncherDoc* CLauncherView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLauncherDoc)));
	return (CLauncherDoc*)m_pDocument;
}
#endif //_DEBUG
