// ProductSet.cpp : implementation file
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "ProductSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProductSet

IMPLEMENT_DYNAMIC(CProductSet, CRecordset)

CProductSet::CProductSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CProductSet)
	m_ProductID = 0;
	m_ProductName = _T("");
	m_SupplierID = 0;
	m_CategoryID = 0;
	m_QuantityPerUnit = _T("");
	m_UnitPrice = _T("");
	m_UnitsInStock = 0;
	m_UnitsOnOrder = 0;
	m_ReorderLevel = 0;
	m_Discontinued = FALSE;
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CProductSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Sample Data");
}

CString CProductSet::GetDefaultSQL()
{
	return _T("[Products]");
}

void CProductSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CProductSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ProductID]"), m_ProductID);
	RFX_Text(pFX, _T("[ProductName]"), m_ProductName);
	RFX_Long(pFX, _T("[SupplierID]"), m_SupplierID);
	RFX_Long(pFX, _T("[CategoryID]"), m_CategoryID);
	RFX_Text(pFX, _T("[QuantityPerUnit]"), m_QuantityPerUnit);
	RFX_Text(pFX, _T("[UnitPrice]"), m_UnitPrice);
	RFX_Int(pFX, _T("[UnitsInStock]"), m_UnitsInStock);
	RFX_Int(pFX, _T("[UnitsOnOrder]"), m_UnitsOnOrder);
	RFX_Int(pFX, _T("[ReorderLevel]"), m_ReorderLevel);
	RFX_Bool(pFX, _T("[Discontinued]"), m_Discontinued);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CProductSet diagnostics

#ifdef _DEBUG
void CProductSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CProductSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
