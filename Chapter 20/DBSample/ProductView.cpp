// ProductView.cpp : implementation of the CProductView class
//

#include "stdafx.h"
#include "DBSample.h"

#include "ProductSet.h"
#include "DBSampleDoc.h"
#include "ProductView.h"
#include "OurConstants.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProductView

IMPLEMENT_DYNCREATE(CProductView, CRecordView)

BEGIN_MESSAGE_MAP(CProductView, CRecordView)
	//{{AFX_MSG_MAP(CProductView)
	ON_BN_CLICKED(IDC_ORDERS, OnOrders)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductView construction/destruction

CProductView::CProductView()
	: CRecordView(CProductView::IDD)
{
	//{{AFX_DATA_INIT(CProductView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CProductView::~CProductView()
{
}

void CProductView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProductView)
	DDX_FieldText(pDX, IDC_PRODUCTID, m_pSet->m_ProductID, m_pSet);
	DDX_FieldText(pDX, IDC_CATEGORYID, m_pSet->m_CategoryID, m_pSet);
	DDX_FieldText(pDX, IDC_PRODUCTNAME, m_pSet->m_ProductName, m_pSet);
	DDX_FieldText(pDX, IDC_UNITPRICE, m_pSet->m_UnitPrice, m_pSet);
	DDX_FieldText(pDX, IDC_UNITSINSTOCK, m_pSet->m_UnitsInStock, m_pSet);
	DDX_FieldText(pDX, IDC_UNITSONORDER, m_pSet->m_UnitsOnOrder, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CProductView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CProductView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_productSet;
	m_pSet->m_strSort = "[ProductID]";		//Set the sort fields
	CRecordView::OnInitialUpdate();

   // Set the document title to the table name
   if (m_pSet->IsOpen())                   // Verify the recordset is open
   {
      CString strTitle = _T("Table Name"); // Set basic title string
      CString strTable = m_pSet->GetTableName();
      if (!strTable.IsEmpty())             // Verify we have a table name
         strTitle += _T(":") + strTable;   // and add to basic title
      GetDocument()->SetTitle(strTitle);   // Set the document title
   }

	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CProductView printing

BOOL CProductView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProductView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProductView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

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

CDBSampleDoc* CProductView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBSampleDoc)));
	return (CDBSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProductView database support
CRecordset* CProductView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CProductView message handlers

void CProductView::OnOrders() 
{
   ((CMainFrame*)GetParentFrame())->SelectView(ORDER_VIEW);	
}

void CProductView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
   if(bActivate)
   {
      // Update the window caption
      CString strTitle = _T("Table Name");
      CString strTable = m_pSet->GetTableName();
      strTitle += _T(":") + strTable;
      GetDocument()->SetTitle(strTitle);
   }
	
	CRecordView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
