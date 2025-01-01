// ProductSet.h : interface of the CProductSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTSET_H__E6989851_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_PRODUCTSET_H__E6989851_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CProductSet : public CRecordset
{
public:
	CProductSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CProductSet)

// Field/Param Data
	//{{AFX_FIELD(CProductSet, CRecordset)
	long	m_ProductID;
	CString	m_ProductName;
	long	m_SupplierID;
	long	m_CategoryID;
	CString	m_QuantityPerUnit;
	CString	m_UnitPrice;
	int	m_UnitsInStock;
	int	m_UnitsOnOrder;
	int	m_ReorderLevel;
	BOOL	m_Discontinued;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProductSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRODUCTSET_H__E6989851_1E24_11D2_BA75_00600873394D__INCLUDED_)

