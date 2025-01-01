#if !defined(AFX_ORDERVIEW_H__E698985A_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_ORDERVIEW_H__E698985A_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderView record view

#include "OrderSet.h"

class COrderView : public CRecordView
{
public:
	COrderView();           // protected constructor used by dynamic creation

protected:
	DECLARE_DYNCREATE(COrderView)

// Form Data
public:
	//{{AFX_DATA(COrderView)
	enum { IDD = IDD_ORDERS_FORM };
	COrderSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	BOOL HasOrders();
	COrderSet* GetRecordset();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderView)
	public:
	virtual CRecordset* OnGetRecordset();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~COrderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(COrderView)
	afx_msg void OnProducts();
	afx_msg void OnCustomer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERVIEW_H__E698985A_1E24_11D2_BA75_00600873394D__INCLUDED_)
