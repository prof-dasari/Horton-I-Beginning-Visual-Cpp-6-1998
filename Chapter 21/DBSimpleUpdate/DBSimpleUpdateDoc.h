// DBSimpleUpdateDoc.h : interface of the CDBSimpleUpdateDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBSIMPLEUPDATEDOC_H__F37F0ECB_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
#define AFX_DBSIMPLEUPDATEDOC_H__F37F0ECB_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OrderDetailsSet.h"
#include "OrderSet.h"	// Added by ClassView
#include "Order.h"	// Added by ClassView


class CDBSimpleUpdateDoc : public CDocument
{
protected: // create from serialization only
	CDBSimpleUpdateDoc();
	DECLARE_DYNCREATE(CDBSimpleUpdateDoc)

// Attributes
public:
	COrderDetailsSet m_orderDetailsSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSimpleUpdateDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	void AddOrderDetails(long ID, CString& price, int qty, float disc);
	bool AddOrder();
	COrder m_Order;
	COrderSet m_OrderSet;
	virtual ~CDBSimpleUpdateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBSimpleUpdateDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBSIMPLEUPDATEDOC_H__F37F0ECB_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
