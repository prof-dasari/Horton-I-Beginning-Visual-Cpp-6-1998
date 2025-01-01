// WrxContainerView.cpp : implementation of the CWrxContainerView class
//

#include "stdafx.h"
#include "WrxContainer.h"

#include "WrxContainerDoc.h"
#include "WrxContainerItem.h"
#include "WrxContainerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerView

IMPLEMENT_DYNCREATE(CWrxContainerView, CView)

BEGIN_MESSAGE_MAP(CWrxContainerView, CView)
	//{{AFX_MSG_MAP(CWrxContainerView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerView construction/destruction

CWrxContainerView::CWrxContainerView()
{
	m_pSelection = NULL;
	// TODO: add construction code here

}

CWrxContainerView::~CWrxContainerView()
{
}

BOOL CWrxContainerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerView drawing

void CWrxContainerView::OnDraw(CDC* pDC)
{
	CWrxContainerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	POSITION aPosition = pDoc->GetStartPosition();

	while (aPosition)
	{
		CWrxContainerItem* pItem = (CWrxContainerItem*)pDoc->GetNextItem(aPosition);
		pItem->Draw(pDC, pItem->m_Rect);

		CRectTracker aTracker;
		SetupTracker(pItem, &aTracker);
		aTracker.Draw(pDC);
	}
}

void CWrxContainerView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection

}

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerView printing

BOOL CWrxContainerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWrxContainerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWrxContainerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWrxContainerView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CWrxContainerView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CWrxContainerItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CWrxContainerView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CWrxContainerItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CWrxContainerItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CWrxContainerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CWrxContainerItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);

		pItem->UpdateLink();
		pItem->GetServerSize();
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application
		SelectItem(pItem);
		pItem->InvalidateItem();

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CWrxContainerView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CWrxContainerView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void CWrxContainerView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerView diagnostics

#ifdef _DEBUG
void CWrxContainerView::AssertValid() const
{
	CView::AssertValid();
}

void CWrxContainerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWrxContainerDoc* CWrxContainerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWrxContainerDoc)));
	return (CWrxContainerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerView message handlers

void CWrxContainerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CWrxContainerItem*pHitItem = HitTestItems(point);
	SelectItem(pHitItem);

	if (pHitItem)
	{
		CRectTracker aTracker;
		SetupTracker(pHitItem, &aTracker);
		UpdateWindow();

		if (aTracker.Track(this,point))
		{
			pHitItem->InvalidateItem();
			pHitItem->m_Rect = aTracker.m_rect;
			pHitItem->InvalidateItem();
			GetDocument()->SetModifiedFlag();
		}
	}

	CView::OnLButtonDown(nFlags, point);
}

CWrxContainerItem* CWrxContainerView::HitTestItems(CPoint aPoint)
{
	CWrxContainerDoc* pDoc = GetDocument();
	CWrxContainerItem* pItem = 0;

	POSITION aPosition = pDoc->GetStartPosition();

	while (aPosition)
	{
		pItem = (CWrxContainerItem*)pDoc->GetNextItem(aPosition);
		if (pItem->m_Rect.PtInRect(aPoint))
			return pItem;
	}
	return 0;
}

void CWrxContainerView::SelectItem(CWrxContainerItem *pItem)
{
	if (m_pSelection != pItem)
	{
		if (m_pSelection)
			OnUpdate(0, HINT_UPDATE_ITEM, m_pSelection);

		m_pSelection = pItem;

		if (m_pSelection)
			OnUpdate(0, HINT_UPDATE_ITEM, m_pSelection);
	}
}

void CWrxContainerView::SetupTracker(CWrxContainerItem *pItem, CRectTracker *pTracker)
{
	pTracker->m_rect = pItem->m_Rect;
	if (pItem == m_pSelection)
		pTracker->m_nStyle |= CRectTracker::resizeInside;

	if (pItem->GetType() == OT_LINK)
		pTracker->m_nStyle |= CRectTracker::dottedLine;
	else
		pTracker->m_nStyle |= CRectTracker::solidLine;

	if (pItem->GetItemState() == COleClientItem::openState || pItem->GetItemState() == COleClientItem::activeUIState)
		pTracker->m_nStyle |= CRectTracker::hatchInside;
}

BOOL CWrxContainerView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (pWnd == this && m_pSelection)
	{
		CRectTracker aTracker;
		SetupTracker(m_pSelection, &aTracker);

		if (aTracker.SetCursor(this, nHitTest))
			return TRUE;
	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CWrxContainerView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OnLButtonDown(nFlags, point);
	if (m_pSelection)
		m_pSelection->DoVerb((GetKeyState(VK_CONTROL) < 0) ? OLEIVERB_OPEN : OLEIVERB_PRIMARY, this);

	CView::OnLButtonDblClk(nFlags, point);
}
