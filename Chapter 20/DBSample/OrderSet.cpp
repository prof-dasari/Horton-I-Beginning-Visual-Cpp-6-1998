// OrderSet.cpp : implementation file
//

#include "stdafx.h"
#include "DBSample.h"
#include "OrderSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderSet

IMPLEMENT_DYNAMIC(COrderSet, CRecordset)

COrderSet::COrderSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COrderSet)
	m_OrderID = 0;
	m_ProductID = 0;
	m_Quantity = 0;
	m_OrderID2 = 0;
	m_CustomerID = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT

	m_ProductIDparam = 0L;    // Set initial parameter value
    m_nParams = 1;            // Set number of parameters

	m_nDefaultType = snapshot;
}


CString COrderSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Sample Data");
}

CString COrderSet::GetDefaultSQL()
{
	return _T("[Order Details],[Orders]");
}

void COrderSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COrderSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Order Details].[OrderID]"), m_OrderID);
	RFX_Long(pFX, _T("[ProductID]"), m_ProductID);
	RFX_Int(pFX, _T("[Quantity]"), m_Quantity);
	RFX_Long(pFX, _T("[Orders].[OrderID]"), m_OrderID2);
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	//}}AFX_FIELD_MAP

   // Set the field type as parameter
   pFX->SetFieldType(CFieldExchange::param);
   RFX_Long(pFX, _T("ProductIDParam"), m_ProductIDparam);

}

/////////////////////////////////////////////////////////////////////////////
// COrderSet diagnostics

#ifdef _DEBUG
void COrderSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COrderSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
