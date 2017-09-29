
// LauncherView.cpp : CLauncherView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLauncherView 构造/析构

CLauncherView::CLauncherView()
{
	// TODO: 在此处添加构造代码

}

CLauncherView::~CLauncherView()
{
}

BOOL CLauncherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLauncherView 绘制

void CLauncherView::OnDraw(CDC* /*pDC*/)
{
	CLauncherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CLauncherView 打印

BOOL CLauncherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLauncherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CLauncherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CLauncherView 诊断

#ifdef _DEBUG
void CLauncherView::AssertValid() const
{
	CView::AssertValid();
}

void CLauncherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLauncherDoc* CLauncherView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLauncherDoc)));
	return (CLauncherDoc*)m_pDocument;
}
#endif //_DEBUG
