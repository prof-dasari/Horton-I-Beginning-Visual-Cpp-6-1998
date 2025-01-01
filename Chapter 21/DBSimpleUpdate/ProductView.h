#if !defined(AFX_PRODUCTVIEW_H__F37F0EDC_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
#define AFX_PRODUCTVIEW_H__F37F0EDC_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProductView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProductView record view

#include "ProductSet.h"

class CProductView : public CRecordView
{
public:
	CProductView();           // protected constructor used by dynamic creation
protected:
	DECLARE_DYNCREATE(CProductView)

// Form Data
public:
	//{{AFX_DATA(CProductView)
	enum { IDD = IDD_PRODUCT_FORM };
	CProductSet* m_pSet;
	long	m_OrderID;
	CString	m_CompanyName;
	int		m_Quantity;
	float	m_Discount;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	bool m_OrderAdded;
	void InitializeView();
	CProductSet* GetRecordset();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProductView)
		// NOTE - the ClassWizard will add and remove member functions here.
	public:
	virtual CRecordset* OnGetRecordset();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CProductView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CProductView)
	afx_msg void OnSelectproduct();
	afx_msg void OnDone();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRODUCTVIEW_H__F37F0EDC_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
