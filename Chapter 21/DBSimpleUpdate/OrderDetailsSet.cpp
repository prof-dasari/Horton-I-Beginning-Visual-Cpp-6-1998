// OrderDetailsSet.cpp : implementation of the COrderDetailsSet class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "OrderDetailsSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsSet implementation

IMPLEMENT_DYNAMIC(COrderDetailsSet, CRecordset)

COrderDetailsSet::COrderDetailsSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COrderDetailsSet)
	m_OrderID = 0;
	m_ProductID = 0;
	m_UnitPrice = _T("");
	m_Quantity = 0;
	m_Discount = 0.0f;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString COrderDetailsSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Sample Data");
}

CString COrderDetailsSet::GetDefaultSQL()
{
	return _T("[Order Details]");
}

void COrderDetailsSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COrderDetailsSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[OrderID]"), m_OrderID);
	RFX_Long(pFX, _T("[ProductID]"), m_ProductID);
	RFX_Text(pFX, _T("[UnitPrice]"), m_UnitPrice);
	RFX_Int(pFX, _T("[Quantity]"), m_Quantity);
	RFX_Single(pFX, _T("[Discount]"), m_Discount);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsSet diagnostics

#ifdef _DEBUG
void COrderDetailsSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COrderDetailsSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
