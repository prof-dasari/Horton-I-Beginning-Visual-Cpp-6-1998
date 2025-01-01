// SketcherView.cpp : implementation of the CSketcherView class
//

#include "stdafx.h"
#include "Sketcher.h"

#include "OurConstants.h"
#include "SketcherDoc.h"
#include "SketcherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CView)

BEGIN_MESSAGE_MAP(CSketcherView, CView)
	//{{AFX_MSG_MAP(CSketcherView)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSketcherView construction/destruction

CSketcherView::CSketcherView()
{
   m_FirstPoint = CPoint(0,0);      // Set 1st recorded point to 0,0
   m_SecondPoint = CPoint(0,0);     // Set 2nd recorded point to 0,0
   m_pTempElement = 0;              // Set temporary element pointer to 0
}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherView drawing

void CSketcherView::OnDraw(CDC* pDC)
{
   CSketcherDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);

   POSITION aPos = pDoc->GetListHeadPosition();
   CElement* pElement = 0;             // Store for an element pointer
   while (aPos)                        // Loop while aPos is not null
   {
      pElement = pDoc->GetNext(aPos);  // Get the current element pointer
      // If the element is visible...
      if (pDC->RectVisible(pElement->GetBoundRect()))
         pElement->Draw(pDC);          // ...draw it
   }
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherView printing

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CSketcherView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherView diagnostics

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSketcherView message handlers

void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
   CClientDC aDC(this);             // Create a device context
   OnPrepareDC(&aDC);               // Prepare the device context
   aDC.DPtoLP(&point);              // Convert point to Logical
   m_FirstPoint = point;            // Record the cursor position
   SetCapture();                    // Capture subsequent mouse messages
}

void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
   CSketcherDoc* pDoc = GetDocument();     // Get the document pointer

   if (this == GetCapture())
      ReleaseCapture();                 // Stop capturing mouse messages

   // If there is an element, add it to the document
   if (m_pTempElement)
   {
      pDoc->AddElement(m_pTempElement);    // Add the element

      // Tell the other views about it
      pDoc->UpdateAllViews(0, 0, m_pTempElement);
      m_pTempElement = 0;                  // Reset the element pointer
      pDoc->NotifyChanged();               // Tell the container...
      pDoc->SetModifiedFlag();             // ...and the server
   }
}

void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
   // Define a Device Context object for the view
   CClientDC aDC(this);
   OnPrepareDC(&aDC);             // Prepare the device context

   if ((nFlags & MK_LBUTTON) && (this == GetCapture()))
   {
      aDC.DPtoLP(&point);         // Convert point to logical
      m_SecondPoint = point;      // Save the current cursor position

      if(m_pTempElement)
      {
         if(CURVE == GetDocument()->GetElementType())   // Is it a curve?
         {  // We are drawing a curve
            // so add a segment to the existing curve
            ((CCurve*)m_pTempElement)->AddSegment(m_SecondPoint);
            m_pTempElement->Draw(&aDC);  // Now draw it
            return;                      // We are done
         }

         aDC.SetROP2(R2_NOTXORPEN);      // Set drawing mode

         // Redraw the old element so it disappears from the view
         m_pTempElement->Draw(&aDC);
         delete m_pTempElement;        // Delete the old element
         m_pTempElement = 0;           // Reset the pointer to 0
      }

      // Create a temporary element of the type and color that
      // is recorded in the document object, and draw it
      m_pTempElement = CreateElement();  // Create a new element
      m_pTempElement->Draw(&aDC);        // Draw the element
   }
}

CElement* CSketcherView::CreateElement()
{
   // Get a pointer to the document for this view
   CSketcherDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);                  // Verify the pointer is good

   // Now select the element using the type stored in the document
   switch (pDoc->GetElementType())
   {
      case RECTANGLE:
         return new CRectangle(m_FirstPoint, m_SecondPoint,
                         pDoc->GetElementColor());
      case CIRCLE:
         return new CCircle(m_FirstPoint, m_SecondPoint,
                         pDoc->GetElementColor());
      case CURVE:
         return new CCurve(m_FirstPoint, m_SecondPoint,
                         pDoc->GetElementColor());
      case LINE:
         return new CLine(m_FirstPoint, m_SecondPoint,
                         pDoc->GetElementColor());

      default:                   // Something's gone wrong
         AfxMessageBox("Bad Element code", MB_OK);
         AfxAbort();
         return NULL;
   }
}

void CSketcherView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
   // Invalidate the area corresponding to the element pointed to
   // if there is one, otherwise invalidate the whole client area
   if (pHint)
   {
      CClientDC aDC(this);            // Create a device context
      OnPrepareDC(&aDC);              // Prepare the device context

      // Get the enclosing rectangle and convert to client coordinates
      CRect aRect = static_cast<CElement*>(pHint)->GetBoundRect();
      aDC.LPtoDP(aRect);
      aRect.NormalizeRect();
      InvalidateRect(aRect);          // Get the area redrawn
   }
   else
      InvalidateRect(0);
}

void CSketcherView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
   CView::OnPrepareDC(pDC, pInfo);
   CSketcherDoc* pDoc = GetDocument();
   pDC->SetMapMode(MM_ANISOTROPIC);
   CSize DocSize = pDoc->GetDocSize();

   // y extent must be negative because document assumes MM_LOENGLISH
   DocSize.cy = -DocSize.cy;   // Change sign of y
   pDC->SetWindowExt(DocSize); // Now set the window extent

   // Get the zoom factor for the server compared to the container
   // If the server isn't in-place active, zoom factor will be 1 to 1
   CSize SizeNum, SizeDenom;             // Places to store zoom factors
   pDoc->GetZoomFactor(&SizeNum, &SizeDenom);

   int xLogPixels = pDC->GetDeviceCaps(LOGPIXELSX);
   int yLogPixels = pDC->GetDeviceCaps(LOGPIXELSY);

   int xExtent = (DocSize.cx * xLogPixels * SizeNum.cx) / (100*SizeDenom.cx);
   int yExtent = (DocSize.cy * yLogPixels * SizeNum.cy) / (100*SizeDenom.cy);
   pDC->SetViewportExt(xExtent, -yExtent); // Set viewport extent
}

