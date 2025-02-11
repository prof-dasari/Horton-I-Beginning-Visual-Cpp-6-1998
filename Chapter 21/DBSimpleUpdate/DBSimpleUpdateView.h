// DBSimpleUpdateView.h : interface of the CDBSimpleUpdateView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBSIMPLEUPDATEVIEW_H__0BC45D44_5872_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_DBSIMPLEUPDATEVIEW_H__0BC45D44_5872_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COrderDetailsSet;

class CDBSimpleUpdateView : public CRecordView
{
protected: // create from serialization only
	CDBSimpleUpdateView();
	DECLARE_DYNCREATE(CDBSimpleUpdateView)

public:
	//{{AFX_DATA(CDBSimpleUpdateView)
	enum{ IDD = IDD_DBSIMPLEUPDATE_FORM };
	COrderDetailsSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CDBSimpleUpdateDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSimpleUpdateView)
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
	virtual ~CDBSimpleUpdateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBSimpleUpdateView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBSimpleUpdateView.cpp
inline CDBSimpleUpdateDoc* CDBSimpleUpdateView::GetDocument()
   { return (CDBSimpleUpdateDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBSIMPLEUPDATEVIEW_H__0BC45D44_5872_11D2_963F_00A0C94CB8B3__INCLUDED_)
