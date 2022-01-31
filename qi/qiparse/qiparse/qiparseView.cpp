
// qiparseView.cpp : implementation of the CqiparseView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "qiparse.h"
#endif

#include "qiparseDoc.h"
#include "qiparseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CqiparseView

IMPLEMENT_DYNCREATE(CqiparseView, CView)

BEGIN_MESSAGE_MAP(CqiparseView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CqiparseView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CqiparseView construction/destruction

CqiparseView::CqiparseView() noexcept
{
	// TODO: add construction code here

}

CqiparseView::~CqiparseView()
{
}

BOOL CqiparseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CqiparseView drawing

void CqiparseView::OnDraw(CDC* /*pDC*/)
{
	CqiparseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CqiparseView printing


void CqiparseView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CqiparseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CqiparseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CqiparseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CqiparseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CqiparseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CqiparseView diagnostics

#ifdef _DEBUG
void CqiparseView::AssertValid() const
{
	CView::AssertValid();
}

void CqiparseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CqiparseDoc* CqiparseView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CqiparseDoc)));
	return (CqiparseDoc*)m_pDocument;
}
#endif //_DEBUG


// CqiparseView message handlers
