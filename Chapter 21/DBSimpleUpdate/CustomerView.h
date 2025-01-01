#if !defined(AFX_CUSTOMERVIEW_H__F37F0EDA_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
#define AFX_CUSTOMERVIEW_H__F37F0EDA_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_

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
	CTime	m_OrderDate;
	CTime	m_RequiredDate;
	long	m_NewOrderID;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void SetNewOrderID();
	CCustomerSet* GetRecordset();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomerView)
		// NOTE - the ClassWizard will add and remove member functions here.
	public:
	virtual CRecordset* OnGetRecordset();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate();
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
	afx_msg void OnSelectproducts();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMERVIEW_H__F37F0EDA_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
