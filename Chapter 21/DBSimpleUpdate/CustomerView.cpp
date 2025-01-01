// CustomerView.cpp : implementation file
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "OurConstants.h"
#include "MainFrm.h"
#include "DBSimpleUpdateDoc.h"
#include "CustomerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomerView

IMPLEMENT_DYNCREATE(CCustomerView, CRecordView)

CCustomerView::CCustomerView()
	: CRecordView(CCustomerView::IDD)
{
	//{{AFX_DATA_INIT(CCustomerView)
	m_pSet = NULL;
	m_OrderDate = 0;
	m_RequiredDate = 0;
	m_NewOrderID = 0;
	//}}AFX_DATA_INIT
}

CCustomerView::~CCustomerView()
{
	if (m_pSet)
		delete m_pSet;
}

void CCustomerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomerView)
	DDX_DateTimeCtrl(pDX, IDC_ORDERDATE, m_OrderDate);
	DDX_DateTimeCtrl(pDX, IDC_REQUIREDDATE, m_RequiredDate);
	DDX_FieldText(pDX, IDC_COMPANYNAME, m_pSet->m_CompanyName, m_pSet);
	DDX_Text(pDX, IDC_NEWORDERID, m_NewOrderID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCustomerView, CRecordView)
	//{{AFX_MSG_MAP(CCustomerView)
	ON_BN_CLICKED(IDC_SELECTPRODUCTS, OnSelectproducts)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomerView diagnostics

#ifdef _DEBUG
void CCustomerView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CCustomerView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCustomerView message handlers

CRecordset* CCustomerView::OnGetRecordset()
{
	if (m_pSet != NULL)
		return m_pSet;

	m_pSet = new CCustomerSet(NULL);
	m_pSet->Open();

	return m_pSet;
}

CCustomerSet* CCustomerView::GetRecordset()
{
	CCustomerSet* pData = (CCustomerSet*) OnGetRecordset();
	ASSERT(pData == NULL || pData->IsKindOf(RUNTIME_CLASS(CCustomerSet)));
	return pData;
}

void CCustomerView::OnInitialUpdate()
{
	BeginWaitCursor();
	GetRecordset();
	CRecordView::OnInitialUpdate();
	if (m_pSet->IsOpen())
	{
		CString strTitle = m_pSet->m_pDatabase->GetDatabaseName();
		CString strTable = m_pSet->GetTableName();
		if (!strTable.IsEmpty())
			strTitle += _T(":") + strTable;
		GetDocument()->SetTitle(strTitle);
	}
	EndWaitCursor();

  // Initialize time values  
  SYSTEMTIME Now;
  GetLocalTime(&Now);                            // Get current time
  m_OrderDate = m_RequiredDate = CTime(Now);     // Set time as today

}

void CCustomerView::OnSelectproducts() 
{
	  // Get a pointer to the document  
  CDBSimpleUpdateDoc* pDoc = static_cast<CDBSimpleUpdateDoc*>(GetDocument());

  // Set up order field values from CCustomerSet object  
  pDoc->m_Order.m_CustomerID = m_pSet->m_CustomerID;
  pDoc->m_Order.m_ShipAddress = m_pSet->m_Address;
  pDoc-> m_Order.m_ShipCity = m_pSet->m_City;
  pDoc-> m_Order.m_ShipCountry = m_pSet->m_Country;
  pDoc-> m_Order.m_ShipName = m_pSet->m_CompanyName;
  pDoc-> m_Order.m_ShipPostalCode = m_pSet->m_PostalCode;
  pDoc-> m_Order.m_ShipRegion = m_pSet->m_Region;


  // Set up order field values from CCustomerView dialog input
  pDoc-> m_Order.m_OrderID = m_NewOrderID;               // Generated new ID
  pDoc-> m_Order.m_OrderDate = m_OrderDate;              // From order date control
  pDoc-> m_Order.m_RequiredDate = m_RequiredDate;        // From required date control


  static_cast<CMainFrame*>(GetParentFrame())->SelectView(SELECTPRODUCT_VIEW);
}

void CCustomerView::OnCancel() 
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(ORDERDETAILS_VIEW);
}

void CCustomerView::SetNewOrderID()
{
  // Get a new order ID from the COrderSet object in the document
  m_NewOrderID = static_cast<CDBSimpleUpdateDoc*>(GetDocument())
                                               ->m_OrderSet.CreateNewOrderID();
  UpdateData(FALSE);                           // Transfer data to controls
}
