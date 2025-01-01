// OrderSet.cpp : implementation file
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
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
	m_CustomerID = _T("");
	m_EmployeeID = 0;
	m_ShipVia = 0;
	m_Freight = _T("");
	m_ShipName = _T("");
	m_ShipAddress = _T("");
	m_ShipCity = _T("");
	m_ShipRegion = _T("");
	m_ShipPostalCode = _T("");
	m_ShipCountry = _T("");
	m_nFields = 14;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString COrderSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Sample Data");
}

CString COrderSet::GetDefaultSQL()
{
	return _T("[Orders]");
}

void COrderSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COrderSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[OrderID]"), m_OrderID);
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	RFX_Long(pFX, _T("[EmployeeID]"), m_EmployeeID);
	RFX_Date(pFX, _T("[OrderDate]"), m_OrderDate);
	RFX_Date(pFX, _T("[RequiredDate]"), m_RequiredDate);
	RFX_Date(pFX, _T("[ShippedDate]"), m_ShippedDate);
	RFX_Long(pFX, _T("[ShipVia]"), m_ShipVia);
	RFX_Text(pFX, _T("[Freight]"), m_Freight);
	RFX_Text(pFX, _T("[ShipName]"), m_ShipName);
	RFX_Text(pFX, _T("[ShipAddress]"), m_ShipAddress);
	RFX_Text(pFX, _T("[ShipCity]"), m_ShipCity);
	RFX_Text(pFX, _T("[ShipRegion]"), m_ShipRegion);
	RFX_Text(pFX, _T("[ShipPostalCode]"), m_ShipPostalCode);
	RFX_Text(pFX, _T("[ShipCountry]"), m_ShipCountry);
	//}}AFX_FIELD_MAP
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

long COrderSet::CreateNewOrderID()
{
  if(!IsOpen())
    Open(CRecordset::dynaset);

  // Check for no records in recordset  
  long newOrderID = 0;
  if(!(IsBOF() && IsEOF()))
  {                                                 // We have records
    MoveFirst();                                    // so go to the first
    while(!IsEOF())                                 // Compare with all the others
    {
      // Save order ID if its larger
      if(newOrderID < m_OrderID)
          newOrderID = m_OrderID;

      MoveNext();                                   // Go to next record
    }
  }
  return ++newOrderID;
}
