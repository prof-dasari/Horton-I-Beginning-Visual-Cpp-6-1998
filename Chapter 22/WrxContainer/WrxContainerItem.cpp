// WrxContainerItem.cpp : implementation of the CWrxContainerItem class
//

#include "stdafx.h"
#include "WrxContainer.h"

#include "WrxContainerDoc.h"
#include "WrxContainerView.h"
#include "WrxContainerItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerItem implementation

IMPLEMENT_SERIAL(CWrxContainerItem, COleClientItem, 0)

CWrxContainerItem::CWrxContainerItem(CWrxContainerDoc* pContainer)
	: COleClientItem(pContainer)
{
	m_Rect.SetRect(10, 10, 100, 100);  // Set initial item position
}

CWrxContainerItem::~CWrxContainerItem()
{
	// TODO: add cleanup code here
	
}

void CWrxContainerItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// When an item is being edited (either in-place or fully open)
	//  it sends OnChange notifications for changes in the state of the
	//  item or visual appearance of its content.

	switch(nCode)
	{
	case OLE_CHANGED:
		InvalidateItem();
		GetServerSize();
		break;
	case OLE_CHANGED_STATE:
		InvalidateItem();
		break;
	}
}

BOOL CWrxContainerItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// During in-place activation CWrxContainerItem::OnChangeItemPosition
	//  is called by the server to change the position of the in-place
	//  window.  Usually, this is a result of the data in the server
	//  document changing such that the extent has changed or as a result
	//  of in-place resizing.
	//
	// The default here is to call the base class, which will call
	//  COleClientItem::SetItemRects to move the item
	//  to the new position.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	InvalidateItem();
	m_Rect = rectPos;
	InvalidateItem();
	GetDocument()->SetModifiedFlag();

	// TODO: update any cache you may have of the item's rectangle/extent

	return TRUE;
}

void CWrxContainerItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// During in-place activation, CWrxContainerItem::OnGetItemPosition
	//  will be called to determine the location of this item.  The default
	//  implementation created from AppWizard simply returns a hard-coded
	//  rectangle.  Usually, this rectangle would reflect the current
	//  position of the item relative to the view used for activation.
	//  You can obtain the view by calling CWrxContainerItem::GetActiveView.

	rPosition = m_Rect;
}

void CWrxContainerItem::OnActivate()
{
    // Allow only one inplace activate item per frame
    CWrxContainerView* pView = GetActiveView();
    ASSERT_VALID(pView);
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void CWrxContainerItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    // Hide the object if it is not an outside-in object
    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CWrxContainerItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleClientItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  CWrxContainerItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleClientItem::Serialize(ar);

	// now store/retrieve data specific to CWrxContainerItem
	if (ar.IsStoring())
	{
		ar << m_Rect;
	}
	else
	{
		ar >> m_Rect;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerItem diagnostics

#ifdef _DEBUG
void CWrxContainerItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CWrxContainerItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////

void CWrxContainerItem::InvalidateItem()
{
	// Pass a hint to update all views in the document
	GetDocument()->UpdateAllViews(0, HINT_UPDATE_ITEM, this);
}

void CWrxContainerItem::GetServerSize()
{
	CSize aSize;
	if (GetCachedExtent(&aSize))
	{
		// Size is specified by OLE in HIMETRIC units
		CClientDC aDC(0);
		aDC.HIMETRICtoDP(&aSize);

		if (aSize != m_Rect.Size() && !IsInPlaceActive())
		{
			InvalidateItem();

			m_Rect.right = m_Rect.left + aSize.cx;
			m_Rect.bottom = m_Rect.top + aSize.cy;

			InvalidateItem();
		}
	}
}
