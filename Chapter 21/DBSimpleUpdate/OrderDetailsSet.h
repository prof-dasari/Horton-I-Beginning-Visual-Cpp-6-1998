// OrderDetailsSet.h : interface of the COrderDetailsSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORDERDETAILSSET_H__F37F0ECF_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
#define AFX_ORDERDETAILSSET_H__F37F0ECF_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COrderDetailsSet : public CRecordset
{
public:
	COrderDetailsSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COrderDetailsSet)

// Field/Param Data
	//{{AFX_FIELD(COrderDetailsSet, CRecordset)
	long	m_OrderID;
	long	m_ProductID;
	CString	m_UnitPrice;
	int	m_Quantity;
	float	m_Discount;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderDetailsSet)
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

#endif // !defined(AFX_ORDERDETAILSSET_H__F37F0ECF_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)

