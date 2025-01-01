// CustomerView.cpp : implementation file
//

#include "stdafx.h"
#include "DBSample.h"
#include "CustomerView.h"
#include "ProductSet.h"
#include "OrderSet.h"
#include "CustomerSet.h"
#include "DBSampleDoc.h"
#include "OurConstants.h"
#include "MainFrm.h"


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
	//}}AFX_DATA_INIT
}

CCustomerView::~CCustomerView()
{
}

void CCustomerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomerView)
	DDX_FieldText(pDX, IDC_CUSTOMERID, m_pSet->m_CustomerID, m_pSet);
	DDX_FieldText(pDX, IDC_COMPANYNAME, m_pSet->m_CompanyName, m_pSet);
	DDX_FieldText(pDX, IDC_ADDRESS, m_pSet->m_Address, m_pSet);
	DDX_FieldText(pDX, IDC_CITY, m_pSet->m_City, m_pSet);
	DDX_FieldText(pDX, IDC_PHONE, m_pSet->m_Phone, m_pSet);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCustomerView, CRecordView)
	//{{AFX_MSG_MAP(CCustomerView)
	ON_BN_CLICKED(IDC_ORDERS, OnOrders)
	ON_BN_CLICKED(IDC_PRODUCTS, OnProducts)
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
   CDBSampleDoc* pDoc = (CDBSampleDoc*)GetDocument();
   m_pSet = &pDoc->m_CustomerSet;      // Initialize the recordset pointer

   // Set the DB for the customer recordset
   m_pSet->m_pDatabase = pDoc->m_productSet.m_pDatabase;

   // Set the current customer ID as the filter parameter value
   m_pSet->m_CustomerIDparam = pDoc->m_OrderSet.m_CustomerID;
   m_pSet->m_strFilter ="CustomerID = ?";    // Filter on CustomerID field



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

void CCustomerView::OnOrders() 
{
   ((CMainFrame*)GetParentFrame())->SelectView(ORDER_VIEW);	
}

void CCustomerView::OnProducts() 
{
   ((CMainFrame*)GetParentFrame())->SelectView(PRODUCT_VIEW);	
}

void CCustomerView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
   if(bActivate)
   {
      if(!m_pSet->IsOpen())
         return;
      CDBSampleDoc* pDoc = (CDBSampleDoc*)GetDocument();

      // Set current customer ID as parameter
      m_pSet->m_CustomerIDparam = pDoc->m_OrderSet.m_CustomerID;
      m_pSet->Requery();               // Get data from the DB
      CRecordView::OnInitialUpdate();  // Redraw the dialog

      CString strTitle = _T("Table Name:");
      CString strTable = m_pSet->GetTableName();
      if (!strTable.IsEmpty())
         strTitle += strTable;
      else
         strTitle += _T("Multiple Tables");
      pDoc->SetTitle(strTitle);
   }
	
	CRecordView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

BOOL CCustomerView::HasDetails()
{
   if (!m_pSet->IsOpen())
      return FALSE;

   CDBSampleDoc* pDoc = (CDBSampleDoc*)GetDocument();
   m_pSet->m_CustomerIDparam = pDoc->m_OrderSet.m_CustomerID;
   m_pSet->Requery();

   if (m_pSet->IsEOF())
      return FALSE;
   else
      return TRUE;
}
