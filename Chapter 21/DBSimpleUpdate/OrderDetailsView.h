// OrderDetailsView.h : interface of the COrderDetailsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORDERDETAILSVIEW_H__F37F0ECD_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
#define AFX_ORDERDETAILSVIEW_H__F37F0ECD_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COrderDetailsSet;

class COrderDetailsView : public CRecordView
{
protected: // create from serialization only
	COrderDetailsView();
	DECLARE_DYNCREATE(COrderDetailsView)

public:
	//{{AFX_DATA(COrderDetailsView)
	enum { IDD = IDD_DBSIMPLEUPDATE_FORM };
	CButton	m_NewOrder;
	CButton	m_CancelCtrl;
	CButton	m_EditCtrl;
	CEdit	m_QuantityCtrl;
	CEdit	m_DiscountCtrl;
	COrderDetailsSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CDBSimpleUpdateDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderDetailsView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_UpdateMode;
	virtual ~COrderDetailsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COrderDetailsView)
	afx_msg void OnEditorder();
	afx_msg void OnUpdateRecordFirst(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecordLast(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecordNext(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecordPrev(CCmdUI* pCmdUI);
	afx_msg void OnCancel();
	afx_msg void OnNeworder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OrderDetailsView.cpp
inline CDBSimpleUpdateDoc* COrderDetailsView::GetDocument()
   { return (CDBSimpleUpdateDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERDETAILSVIEW_H__F37F0ECD_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
