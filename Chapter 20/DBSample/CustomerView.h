#if !defined(AFX_CUSTOMERVIEW_H__E698985C_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_CUSTOMERVIEW_H__E698985C_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomerView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomerView record view

#include "CustomerSet.h"

class CCustomerView : public CRecordView
{
public:
	CCustomerView();           // protected constructor used by dynamic creation

protected:
	DECLARE_DYNCREATE(CCustomerView)

// Form Data
public:
	//{{AFX_DATA(CCustomerView)
	enum { IDD = IDD_CUSTOMER_FORM };
	CCustomerSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	BOOL HasDetails();
	CCustomerSet* GetRecordset();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomerView)
	public:
	virtual CRecordset* OnGetRecordset();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCustomerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCustomerView)
	afx_msg void OnOrders();
	afx_msg void OnProducts();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMERVIEW_H__E698985C_1E24_11D2_BA75_00600873394D__INCLUDED_)
