
// MDIDocingView.cpp : implementation of the CMDIDocingView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MDIDocing.h"
#endif

#include "MDIDocingDoc.h"
#include "MDIDocingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDIDocingView

IMPLEMENT_DYNCREATE(CMDIDocingView, CView)

BEGIN_MESSAGE_MAP(CMDIDocingView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMDIDocingView construction/destruction

CMDIDocingView::CMDIDocingView() noexcept
{
	// TODO: add construction code here

}

CMDIDocingView::~CMDIDocingView()
{
}

BOOL CMDIDocingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMDIDocingView drawing

void CMDIDocingView::OnDraw(CDC* /*pDC*/)
{
	CMDIDocingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CMDIDocingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMDIDocingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMDIDocingView diagnostics

#ifdef _DEBUG
void CMDIDocingView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIDocingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIDocingDoc* CMDIDocingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIDocingDoc)));
	return (CMDIDocingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDIDocingView message handlers
