// ProductView.h : interface of the CProductView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTVIEW_H__E698984F_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_PRODUCTVIEW_H__E698984F_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CProductSet;

class CProductView : public CRecordView
{
protected: // create from serialization only
	CProductView();
	DECLARE_DYNCREATE(CProductView)

public:
	//{{AFX_DATA(CProductView)
	enum { IDD = IDD_DBSAMPLE_FORM };
	CProductSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CDBSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProductView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProductView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProductView)
	afx_msg void OnOrders();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ProductView.cpp
inline CDBSampleDoc* CProductView::GetDocument()
   { return (CDBSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRODUCTVIEW_H__E698984F_1E24_11D2_BA75_00600873394D__INCLUDED_)
