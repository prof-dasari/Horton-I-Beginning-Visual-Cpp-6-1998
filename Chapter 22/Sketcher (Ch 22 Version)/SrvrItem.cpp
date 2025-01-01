// SrvrItem.cpp : implementation of the CSketcherSrvrItem class
//

#include "stdafx.h"
#include "Sketcher.h"

#include "Elements.h" 
#include "SketcherDoc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSketcherSrvrItem implementation

IMPLEMENT_DYNAMIC(CSketcherSrvrItem, COleServerItem)

CSketcherSrvrItem::CSketcherSrvrItem(CSketcherDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// TODO: add one-time construction code here
	//  (eg, adding additional clipboard formats to the item's data source)
}

CSketcherSrvrItem::~CSketcherSrvrItem()
{
	// TODO: add cleanup code here
}

void CSketcherSrvrItem::Serialize(CArchive& ar)
{
	// CSketcherSrvrItem::Serialize will be called by the framework if
	//  the item is copied to the clipboard.  This can happen automatically
	//  through the OLE callback OnGetClipboardData.  A good default for
	//  the embedded item is simply to delegate to the document's Serialize
	//  function.  If you support links, then you will want to serialize
	//  just a portion of the document.

	if (!IsLinkedItem())
	{
		CSketcherDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->Serialize(ar);
	}
}

BOOL CSketcherSrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Most applications, like this one, only handle drawing the content
	//  aspect of the item.  If you wish to support other aspects, such
	//  as DVASPECT_THUMBNAIL (by overriding OnDrawEx), then this
	//  implementation of OnGetExtent should be modified to handle the
	//  additional aspect(s).

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CSketcherSrvrItem::OnGetExtent is called to get the extent in
	//  HIMETRIC units of the entire item.  The default implementation
	//  here simply returns a hard-coded number of units.

	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: replace this arbitrary size
   rSize = pDoc->GetDocSize();        // Get the document size

   CClientDC aDC(0);                  // Get device context for conversion
   aDC.SetMapMode(MM_ANISOTROPIC);    // Set map mode that is scaleable

   // Set window extent to 1 inch in each direction in MM_LOENGLISH
   aDC.SetWindowExt(100, -100);       // Set window extent with negative y

   // Set viewport extent to the number of pixels in 1 inch
   aDC.SetViewportExt(aDC.GetDeviceCaps(LOGPIXELSX),
                      aDC.GetDeviceCaps(LOGPIXELSY));

   aDC.LPtoHIMETRIC(&rSize);          // Convert document size to HIMETRIC

   return TRUE;
}

BOOL CSketcherSrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	// Remove this if you use rSize
	UNREFERENCED_PARAMETER(rSize);

	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: set mapping mode and extent
	//  (The extent is usually the same as the size returned from OnGetExtent)
	pDC->SetMapMode(MM_ANISOTROPIC);
    CSize DocSize = pDoc->GetDocSize(); // Get the current document size

    DocSize.cy = -DocSize.cy;         // Invert the y axis for MM_LOENGLISH
	pDC->SetWindowOrg(0,0);
    pDC->SetWindowExt(DocSize);	
	
	// TODO: add drawing code here.  Optionally, fill in the HIMETRIC extent.
	//  All drawing takes place in the metafile device context (pDC).
   POSITION aPos = pDoc->GetListHeadPosition();
   CElement* pElement = 0;     // Store for an element pointer
   while (aPos)                // Loop while aPos is not null
   {
      pElement = pDoc->GetNext(aPos);  // Get the current element pointer

      // If the element is visible...
      if (pDC->RectVisible(pElement->GetBoundRect()))
         pElement->Draw(pDC);          // ...draw it
   }

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherSrvrItem diagnostics

#ifdef _DEBUG
void CSketcherSrvrItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CSketcherSrvrItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
