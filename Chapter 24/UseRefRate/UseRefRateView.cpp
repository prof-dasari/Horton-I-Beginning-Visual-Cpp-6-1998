// UseRefRateView.cpp : implementation of the CUseRefRateView class
//

#include "stdafx.h"
#include "UseRefRate.h"

#include "UseRefRateDoc.h"
#include "RefreshRate.h"
#include "UseRefRateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseRefRateView

IMPLEMENT_DYNCREATE(CUseRefRateView, CFormView)

BEGIN_MESSAGE_MAP(CUseRefRateView, CFormView)
	//{{AFX_MSG_MAP(CUseRefRateView)
	ON_BN_CLICKED(IDC_CALCULATE, OnCalculate)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseRefRateView construction/destruction

CUseRefRateView::CUseRefRateView()
	: CFormView(CUseRefRateView::IDD)
{
	//{{AFX_DATA_INIT(CUseRefRateView)
	m_lHScan = 50;
	m_lRefresh = 0;
	m_lHRes = 0;
	m_lVRes = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
   if(FAILED(CoInitialize(NULL)))                // Initialize COM library
   {
      AfxMessageBox("COM Library init failed");
      AfxAbort();                                // End the program
   }

   // Create a new driver object to handle our COM object
   m_pRefRateDriver = new IRefRate;
   // Create an instance of our COM object using the ProgID
   // and attach the dispinterface
   // to our OleDispatchDriver-derived object
   m_pRefRateDriver->CreateDispatch(_T("RefRate.RefRate.1"));

}

CUseRefRateView::~CUseRefRateView()
{
   if (m_pRefRateDriver)
      delete m_pRefRateDriver;
   CoUninitialize();   // Uninitialize the COM library
}

void CUseRefRateView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUseRefRateView)
	DDX_Text(pDX, IDC_HSCAN, m_lHScan);
	DDX_Text(pDX, IDC_REFRESH, m_lRefresh);
	DDX_Text(pDX, IDC_HRES, m_lHRes);
	DDX_Text(pDX, IDC_VRES, m_lVRes);
	//}}AFX_DATA_MAP
}

BOOL CUseRefRateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUseRefRateView printing

BOOL CUseRefRateView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUseRefRateView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUseRefRateView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CUseRefRateView::OnPrint(CDC* pDC, CPrintInfo*)
{
	// TODO: add code to print the controls
}

/////////////////////////////////////////////////////////////////////////////
// CUseRefRateView diagnostics

#ifdef _DEBUG
void CUseRefRateView::AssertValid() const
{
	CFormView::AssertValid();
}

void CUseRefRateView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUseRefRateDoc* CUseRefRateView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseRefRateDoc)));
	return (CUseRefRateDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseRefRateView message handlers

void CUseRefRateView::OnCalculate() 
{
   UpdateData(TRUE);                   // Get m_HScan from the dialog
   m_lRefresh = m_pRefRateDriver->RefreshRate(m_lHScan);
   m_lHRes = m_pRefRateDriver->GetHRes();
   m_lVRes = m_pRefRateDriver->GetVRes();
   UpdateData(FALSE);                  // Set the values in the dialog
}
