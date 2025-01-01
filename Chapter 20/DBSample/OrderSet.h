#if !defined(AFX_ORDERSET_H__E6989859_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_ORDERSET_H__E6989859_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderSet recordset

class COrderSet : public CRecordset
{
public:
	long m_ProductIDparam;
	COrderSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COrderSet)

// Field/Param Data
	//{{AFX_FIELD(COrderSet, CRecordset)
	long	m_OrderID;
	long	m_ProductID;
	CString	m_UnitPrice;
	int		m_Quantity;
	float	m_Discount;
	long	m_OrderID2;
	CString	m_CustomerID;
	long	m_EmployeeID;
	CTime	m_OrderDate;
	CTime	m_RequiredDate;
	CTime	m_ShippedDate;
	long	m_ShipVia;
	CString	m_Freight;
	CString	m_ShipName;
	CString	m_ShipAddress;
	CString	m_ShipCity;
	CString	m_ShipRegion;
	CString	m_ShipPostalCode;
	CString	m_ShipCountry;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderSet)
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

#endif // !defined(AFX_ORDERSET_H__E6989859_1E24_11D2_BA75_00600873394D__INCLUDED_)
