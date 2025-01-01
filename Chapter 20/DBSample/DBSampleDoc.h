// DBSampleDoc.h : interface of the CDBSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBSAMPLEDOC_H__E698984D_1E24_11D2_BA75_00600873394D__INCLUDED_)
#define AFX_DBSAMPLEDOC_H__E698984D_1E24_11D2_BA75_00600873394D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ProductSet.h"
#include "OrderSet.h"	// Added by ClassView
#include "CustomerSet.h"	// Added by ClassView


class CDBSampleDoc : public CDocument
{
protected: // create from serialization only
	CDBSampleDoc();
	DECLARE_DYNCREATE(CDBSampleDoc)

// Attributes
public:
	CProductSet m_productSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	CCustomerSet m_CustomerSet;
	COrderSet m_OrderSet;
	virtual ~CDBSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBSAMPLEDOC_H__E698984D_1E24_11D2_BA75_00600873394D__INCLUDED_)
