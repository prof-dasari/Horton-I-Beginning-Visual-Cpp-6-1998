// WrxContainerView.h : interface of the CWrxContainerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WRXCONTAINERVIEW_H__4CF4EA9F_18B5_11D2_BA4B_000000000000__INCLUDED_)
#define AFX_WRXCONTAINERVIEW_H__4CF4EA9F_18B5_11D2_BA4B_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWrxContainerItem;

class CWrxContainerView : public CView
{
protected: // create from serialization only
	CWrxContainerView();
	DECLARE_DYNCREATE(CWrxContainerView)

// Attributes
public:
	CWrxContainerDoc* GetDocument();
	// m_pSelection holds the selection to the current CWrxContainerItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CWrxContainerItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CWrxContainerItem* m_pSelection;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWrxContainerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWrxContainerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWrxContainerView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetupTracker(CWrxContainerItem* pItem, CRectTracker* pTracker);
	void SelectItem(CWrxContainerItem* pItem);
	CWrxContainerItem* HitTestItems(CPoint aPoint);
};

#ifndef _DEBUG  // debug version in WrxContainerView.cpp
inline CWrxContainerDoc* CWrxContainerView::GetDocument()
   { return (CWrxContainerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRXCONTAINERVIEW_H__4CF4EA9F_18B5_11D2_BA4B_000000000000__INCLUDED_)
