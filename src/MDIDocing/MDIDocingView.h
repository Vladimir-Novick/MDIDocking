
// MDIDocingView.h : interface of the CMDIDocingView class
//

#pragma once


class CMDIDocingView : public CView
{
protected: // create from serialization only
	CMDIDocingView() noexcept;
	DECLARE_DYNCREATE(CMDIDocingView)

// Attributes
public:
	CMDIDocingDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMDIDocingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDIDocingView.cpp
inline CMDIDocingDoc* CMDIDocingView::GetDocument() const
   { return reinterpret_cast<CMDIDocingDoc*>(m_pDocument); }
#endif

