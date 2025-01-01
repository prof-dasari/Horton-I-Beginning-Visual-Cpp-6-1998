// OrderDetailsView.cpp : implementation of the COrderDetailsView class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "OurConstants.h"
#include "MainFrm.h"

#include "OrderDetailsSet.h"
#include "DBSimpleUpdateDoc.h"
#include "OrderDetailsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsView

IMPLEMENT_DYNCREATE(COrderDetailsView, CRecordView)

BEGIN_MESSAGE_MAP(COrderDetailsView, CRecordView)
	//{{AFX_MSG_MAP(COrderDetailsView)
	ON_BN_CLICKED(IDC_EDITORDER, OnEditorder)
	ON_UPDATE_COMMAND_UI(ID_RECORD_FIRST, OnUpdateRecordFirst)
	ON_UPDATE_COMMAND_UI(ID_RECORD_LAST, OnUpdateRecordLast)
	ON_UPDATE_COMMAND_UI(ID_RECORD_NEXT, OnUpdateRecordNext)
	ON_UPDATE_COMMAND_UI(ID_RECORD_PREV, OnUpdateRecordPrev)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_NEWORDER, OnNeworder)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsView construction/destruction

COrderDetailsView::COrderDetailsView()
                    : CRecordView(COrderDetailsView::IDD), m_UpdateMode(false)
{
	//{{AFX_DATA_INIT(COrderDetailsView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COrderDetailsView::~COrderDetailsView()
{
}

void COrderDetailsView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COrderDetailsView)
	DDX_Control(pDX, IDC_NEWORDER, m_NewOrder);
	DDX_Control(pDX, IDC_CANCEL, m_CancelCtrl);
	DDX_Control(pDX, IDC_EDITORDER, m_EditCtrl);
	DDX_Control(pDX, IDC_QUANTITY, m_QuantityCtrl);
	DDX_Control(pDX, IDC_DISCOUNT, m_DiscountCtrl);
	DDX_FieldText(pDX, IDC_ORDERID, m_pSet->m_OrderID, m_pSet);
	DDX_FieldText(pDX, IDC_PRODUCTID, m_pSet->m_ProductID, m_pSet);
	DDX_FieldText(pDX, IDC_UNITPRICE, m_pSet->m_UnitPrice, m_pSet);
	DDX_FieldText(pDX, IDC_QUANTITY, m_pSet->m_Quantity, m_pSet);
	DDX_FieldText(pDX, IDC_DISCOUNT, m_pSet->m_Discount, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL COrderDetailsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void COrderDetailsView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_orderDetailsSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsView printing

BOOL COrderDetailsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COrderDetailsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COrderDetailsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsView diagnostics

#ifdef _DEBUG
void COrderDetailsView::AssertValid() const
{
	CRecordView::AssertValid();
}

void COrderDetailsView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBSimpleUpdateDoc* COrderDetailsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBSimpleUpdateDoc)));
	return (CDBSimpleUpdateDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COrderDetailsView database support
CRecordset* COrderDetailsView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COrderDetailsView message handlers

void COrderDetailsView::OnEditorder() 
{
  if(m_pSet->CanUpdate())
  {
    try
    {
      if(m_UpdateMode)
      {                       // When button was clicked we were in edit mode
        m_EditCtrl.SetWindowText("Edit Order");          // Switch button text
        m_CancelCtrl.ShowWindow(SW_HIDE);                // Hide the Cancel button
        m_NewOrder.ShowWindow(SW_SHOW);                 // Show the new order button
        m_pSet->Update();                                // Complete the update
      }
      else
      {                       // When button was clicked we were in read-only mode
        m_EditCtrl.SetWindowText("Update");              // Switch button text
        m_NewOrder.ShowWindow(SW_HIDE);                 // Hide the new order button
        m_CancelCtrl.ShowWindow(SW_SHOW);                // Show the Cancel button
        m_pSet->Edit();                                  // Start the update process
      }
      m_QuantityCtrl.SetReadOnly(m_UpdateMode);	      // Set state of quantity 
      m_DiscountCtrl.SetReadOnly(m_UpdateMode); 	      // & discount edit control
      m_UpdateMode = !m_UpdateMode;            	      // Switch the mode
    }
    catch(CException* pEx)
    {
      pEx->ReportError();                      	      // Display error message
    }
  }
  else
    AfxMessageBox("Recordset is not updateable.");
}

void COrderDetailsView::OnUpdateRecordFirst(CCmdUI* pCmdUI) 
{
  // Disable item if m_UpdateMode is true, enable if false and not the 1st record
  pCmdUI->Enable(!m_UpdateMode && ! IsOnFirstRecord());
}

void COrderDetailsView::OnUpdateRecordLast(CCmdUI* pCmdUI) 
{
  // Disable item if m_UpdateMode is true, enable if false and not the last record
  pCmdUI->Enable(!m_UpdateMode && !IsOnLastRecord());
}

void COrderDetailsView::OnUpdateRecordNext(CCmdUI* pCmdUI) 
{
  // Disable item if m_UpdateMode is true, enable if false and not the last record
  pCmdUI->Enable(!m_UpdateMode && !IsOnLastRecord());
}

void COrderDetailsView::OnUpdateRecordPrev(CCmdUI* pCmdUI) 
{
  // Disable item if m_UpdateMode is true, enable if false and not the 1st record
  pCmdUI->Enable(!m_UpdateMode && ! IsOnFirstRecord());
}

void COrderDetailsView::OnCancel() 
{
  m_pSet->CancelUpdate();                          // Cancel the update operation
  m_EditCtrl.SetWindowText("Edit");                // Switch button text
  m_CancelCtrl.ShowWindow(SW_HIDE);                // Hide the Cancel button
  m_NewOrder.ShowWindow(SW_SHOW);                  // Show the New Order button
  m_QuantityCtrl.SetReadOnly(m_UpdateMode);        // Set state of quantity and  
  m_DiscountCtrl.SetReadOnly(m_UpdateMode);        // discount edit controls
  m_UpdateMode = !m_UpdateMode;                    // Switch the mode
}

void COrderDetailsView::OnNeworder() 
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(NEWORDER_VIEW);
}
