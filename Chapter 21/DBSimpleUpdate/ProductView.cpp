// ProductView.cpp : implementation file
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "OurConstants.h"
#include "MainFrm.h"
#include "DBSimpleUpdateDoc.h"
#include "ProductView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProductView

IMPLEMENT_DYNCREATE(CProductView, CRecordView)

CProductView::CProductView()
	: CRecordView(CProductView::IDD)
{
	//{{AFX_DATA_INIT(CProductView)
	m_pSet = NULL;
	m_OrderID = 0;
	m_CompanyName = _T("");
	m_Quantity = 0;
	m_Discount = 0.0f;
	//}}AFX_DATA_INIT
}

CProductView::~CProductView()
{
	if (m_pSet)
		delete m_pSet;
}

void CProductView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProductView)
	DDX_FieldText(pDX, IDC_PRODUCTNAME, m_pSet->m_ProductName, m_pSet);
	DDX_Text(pDX, IDC_NEWORDERID, m_OrderID);
	DDX_Text(pDX, IDC_COMPANYNAME, m_CompanyName);
	DDX_Text(pDX, IDC_ORDERQUANTITY, m_Quantity);
	DDX_Text(pDX, IDC_ORDERDISCOUNT, m_Discount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProductView, CRecordView)
	//{{AFX_MSG_MAP(CProductView)
	ON_BN_CLICKED(IDC_SELECTPRODUCT, OnSelectproduct)
	ON_BN_CLICKED(IDC_DONE, OnDone)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductView diagnostics

#ifdef _DEBUG
void CProductView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CProductView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProductView message handlers

CRecordset* CProductView::OnGetRecordset()
{
	if (m_pSet != NULL)
		return m_pSet;

	m_pSet = new CProductSet(NULL);
	m_pSet->Open();

	return m_pSet;
}

CProductSet* CProductView::GetRecordset()
{
	CProductSet* pData = (CProductSet*) OnGetRecordset();
	ASSERT(pData == NULL || pData->IsKindOf(RUNTIME_CLASS(CProductSet)));
	return pData;
}

void CProductView::OnInitialUpdate()
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
}

void CProductView::OnSelectproduct() 
{
  UpdateData(TRUE);                                 // Transfer data from controls

  // Get a pointer to the document  
  CDBSimpleUpdateDoc* pDoc = static_cast<CDBSimpleUpdateDoc*>(GetDocument()); 

  if(!m_OrderAdded)                                 // If order not added
    m_OrderAdded = pDoc->AddOrder();                // then try to add it
  if(m_OrderAdded)
  
  {
     pDoc->AddOrderDetails(m_pSet->m_ProductID,
                           m_pSet->m_UnitPrice,
                           m_Quantity,
                           m_Discount);
    // Now reset the values in the quantity and discount controls
    m_Quantity = 1;
    m_Discount = 0;
    UpdateData(FALSE);                   	// Transfer data to controls
  }
	
}

void CProductView::OnDone() 
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(ORDERDETAILS_VIEW);
}

void CProductView::InitializeView()
{
  // Get a pointer to the document  
  CDBSimpleUpdateDoc* pDoc = static_cast<CDBSimpleUpdateDoc*>(GetDocument());

  m_OrderID = pDoc->m_Order.m_OrderID;
  m_CompanyName = pDoc->m_Order.m_ShipName;
  m_Quantity = 1;                                  // Must order at least 1
  m_Discount = 0;                                  // No default discount
  m_OrderAdded = false;                            // Order not added initially
  UpdateData(FALSE);                               // Transfer data to controls
}
