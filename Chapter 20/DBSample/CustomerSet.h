#if !defined(AFX_CUSTOMERSET_H__E698985B_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_CUSTOMERSET_H__E698985B_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomerSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomerSet recordset

class CCustomerSet : public CRecordset
{
public:
	CString m_CustomerIDparam;
	CCustomerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCustomerSet)

// Field/Param Data
	//{{AFX_FIELD(CCustomerSet, CRecordset)
	CString	m_CustomerID;
	CString	m_CompanyName;
	CString	m_ContactName;
	CString	m_ContactTitle;
	CString	m_Address;
	CString	m_City;
	CString	m_Region;
	CString	m_PostalCode;
	CString	m_Country;
	CString	m_Phone;
	CString	m_Fax;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomerSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMERSET_H__E698985B_1E24_11D2_BA75_00600873394D__INCLUDED_)
