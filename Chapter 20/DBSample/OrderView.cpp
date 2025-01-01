// OrderView.cpp : implementation file
//

#include "stdafx.h"
#include "DBSample.h"
#include "OrderView.h"
#include "ProductSet.h"
#include "OrderSet.h"
#include "DBSampleDoc.h"
#include "OurConstants.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderView

IMPLEMENT_DYNCREATE(COrderView, CRecordView)

COrderView::COrderView()
	: CRecordView(COrderView::IDD)
{
	//{{AFX_DATA_INIT(COrderView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
}

COrderView::~COrderView()
{
}

void COrderView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COrderView)
	DDX_FieldText(pDX, IDC_ORDERID, m_pSet->m_OrderID, m_pSet);
	DDX_FieldText(pDX, IDC_PRODUCTID, m_pSet->m_ProductID, m_pSet);
	DDX_FieldText(pDX, IDC_QUANTITY, m_pSet->m_Quantity, m_pSet);
	DDX_FieldText(pDX, IDC_CUSTOMERID, m_pSet->m_CustomerID, m_pSet);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COrderView, CRecordView)
	//{{AFX_MSG_MAP(COrderView)
	ON_BN_CLICKED(IDC_PRODUCTS, OnProducts)
	ON_BN_CLICKED(IDC_CUSTOMER, OnCustomer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderView diagnostics

#ifdef _DEBUG
void COrderView::AssertValid() const
{
	CRecordView::AssertValid();
}

void COrderView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COrderView message handlers

CRecordset* COrderView::OnGetRecordset()
{
	if (m_pSet != NULL)
		return m_pSet;

	m_pSet = new COrderSet(NULL);
	m_pSet->Open();

	return m_pSet;
}

COrderSet* COrderView::GetRecordset()
{
	COrderSet* pData = (COrderSet*) OnGetRecordset();
	ASSERT(pData == NULL || pData->IsKindOf(RUNTIME_CLASS(COrderSet)));
	return pData;
}

void COrderView::OnInitialUpdate()
{
	BeginWaitCursor();
	CDBSampleDoc* pDoc = (CDBSampleDoc*)GetDocument();   // Get doc pointer
   m_pSet = &pDoc->m_OrderSet;           // Get a pointer to the recordset

   // Use the DB that is open for products recordset
   m_pSet->m_pDatabase = pDoc->m_productSet.m_pDatabase;

   // Set the current product ID as parameter
   m_pSet->m_ProductIDparam = pDoc->m_productSet.m_ProductID;

   // Set the filter as product ID field
   m_pSet->m_strFilter =
     "[ProductID] = ? AND [Orders].[OrderID] = [Order Details].[OrderID]";

	GetRecordset();

   // Now fix the caption
   if (m_pSet->IsOpen())
   {
      CString strTitle = "Table Name:";
      CString strTable = m_pSet->GetTableName();     // Get the table name

      //If the recordset uses 2 or more tables, the name will be empty
      if (!strTable.IsEmpty())
         strTitle += _T(":") + strTable;      // It isn't so use the name
      else
         strTitle += _T("Orders - Multiple Tables"); // Use generic name

      GetDocument()->SetTitle(strTitle);      // Set the document title
   }


	CRecordView::OnInitialUpdate();
	EndWaitCursor();
}

void COrderView::OnProducts() 
{
   ((CMainFrame*)GetParentFrame())->SelectView(PRODUCT_VIEW);	
}

void COrderView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
   if(bActivate)
   {
      // Get a pointer to the document
      CDBSampleDoc* pDoc = (CDBSampleDoc*)GetDocument();

      // Get a pointer to the frame window
      CMainFrame* pMFrame = (CMainFrame*)GetParentFrame();

      // If the last view was the product view, we must re-query
      // the recordset with the product ID from the product recordset
      if(pMFrame->m_CurrentViewID==PRODUCT_VIEW)
      {
         if(!m_pSet->IsOpen())   // Make sure the recordset is open
            return;
         // Set current product ID as parameter
         m_pSet->m_ProductIDparam = pDoc->m_productSet.m_ProductID;
         m_pSet->Requery();      // Get data from the DB
      }

      // Set the window caption
      CString strTitle = _T("Table Name:");
      CString strTable = m_pSet->GetTableName();
      if(!strTable.IsEmpty())
         strTitle += strTable;
      else
         strTitle += _T("Orders - Multiple Tables");
      pDoc->SetTitle(strTitle);
      CRecordView::OnInitialUpdate();       // Update values in dialog
   }
	
	CRecordView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

BOOL COrderView::HasOrders()
{
  CDBSampleDoc* pDoc = (CDBSampleDoc*)GetDocument();

  // If the dataset isn't open, we can't help
  if (!m_pSet->IsOpen())
    return FALSE;

  m_pSet->m_ProductIDparam = pDoc->m_productSet.m_ProductID;
  m_pSet->Requery();      // Get data from the DB

  // If we're already at the end, there are no orders here
  if (m_pSet->IsEOF())
    return FALSE;
  else
    return TRUE;

}

void COrderView::OnCustomer() 
{
   ((CMainFrame*)GetParentFrame())->SelectView(CUSTOMER_VIEW);	
}
