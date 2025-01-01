// DBSimpleUpdateView.cpp : implementation of the CDBSimpleUpdateView class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"

#include "OrderDetailsSet.h"
#include "DBSimpleUpdateDoc.h"
#include "DBSimpleUpdateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateView

IMPLEMENT_DYNCREATE(CDBSimpleUpdateView, CRecordView)

BEGIN_MESSAGE_MAP(CDBSimpleUpdateView, CRecordView)
	//{{AFX_MSG_MAP(CDBSimpleUpdateView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateView construction/destruction

CDBSimpleUpdateView::CDBSimpleUpdateView()
	: CRecordView(CDBSimpleUpdateView::IDD)
{
	//{{AFX_DATA_INIT(CDBSimpleUpdateView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CDBSimpleUpdateView::~CDBSimpleUpdateView()
{
}

void CDBSimpleUpdateView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDBSimpleUpdateView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDBSimpleUpdateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CDBSimpleUpdateView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_orderDetailsSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateView printing

BOOL CDBSimpleUpdateView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDBSimpleUpdateView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDBSimpleUpdateView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateView diagnostics

#ifdef _DEBUG
void CDBSimpleUpdateView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBSimpleUpdateView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBSimpleUpdateDoc* CDBSimpleUpdateView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBSimpleUpdateDoc)));
	return (CDBSimpleUpdateDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateView database support
CRecordset* CDBSimpleUpdateView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateView message handlers
