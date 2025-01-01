// SketcherDoc.cpp : implementation of the CSketcherDoc class
//

#include "stdafx.h"
#include "Sketcher.h"

#include "OurConstants.h"
#include "SketcherDoc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CSketcherDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CSketcherDoc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_ELEMENT_CIRCLE, OnElementCircle)
	ON_COMMAND(ID_ELEMENT_CURVE, OnElementCurve)
	ON_COMMAND(ID_ELEMENT_LINE, OnElementLine)
	ON_COMMAND(ID_ELEMENT_RECTANGLE, OnElementRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, OnUpdateElementRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, OnUpdateElementLine)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, OnUpdateElementCurve)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, OnUpdateElementCircle)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc construction/destruction

CSketcherDoc::CSketcherDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here
   m_Element = LINE;            // Set initial element type
   m_Color = BLACK;             // Set initial drawing color
   m_DocSize = CSize(200,200);  // Set document size

}

CSketcherDoc::~CSketcherDoc()
{
   // Get the position at the head of the list
   POSITION aPosition = m_ElementList.GetHeadPosition();

   // Now delete the element pointed to by each list entry
   while (aPosition)
      delete m_ElementList.GetNext(aPosition);

   m_ElementList.RemoveAll();   // Finally delete all pointers
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc server implementation

COleServerItem* CSketcherDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CSketcherSrvrItem* pItem = new CSketcherSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}



/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc serialization

void CSketcherDoc::Serialize(CArchive& ar)
{
   m_ElementList.Serialize(ar);     // Serialize the element list
   if (ar.IsStoring())
   {
      ar << m_Color                // Store the current color
         << m_Element              // the current element type,
         << m_DocSize;             // and the document size
   }
   else
   {
      ar >> m_Color                // Retrieve the current color
         >> m_Element              // the current element type,
         >> m_DocSize;             // and the document size
   }
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc diagnostics

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc commands

void CSketcherDoc::OnColorBlack() 
{
	// TODO: Add your command handler code here
   m_Color = BLACK;       // Set color type as black	
}

void CSketcherDoc::OnColorBlue() 
{
	// TODO: Add your command handler code here
   m_Color = BLUE;       // Set color type as blue		
}

void CSketcherDoc::OnColorGreen() 
{
	// TODO: Add your command handler code here
   m_Color = GREEN;       // Set color type as green	
}

void CSketcherDoc::OnColorRed() 
{
	// TODO: Add your command handler code here
   m_Color = RED;       // Set color type as red		
}

void CSketcherDoc::OnElementCircle() 
{
	// TODO: Add your command handler code here
   m_Element = CIRCLE;       // Set element type as a circle	
}

void CSketcherDoc::OnElementCurve() 
{
	// TODO: Add your command handler code here
   m_Element = CURVE;       // Set element type as a curve
}

void CSketcherDoc::OnElementLine() 
{
	// TODO: Add your command handler code here
   m_Element = LINE;       // Set element type as a line
}

void CSketcherDoc::OnElementRectangle() 
{
	// TODO: Add your command handler code here
   m_Element = RECTANGLE;       // Set element type as a rectangle
}

void CSketcherDoc::OnUpdateElementRectangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current element is a rectangle
   pCmdUI->SetCheck(m_Element==RECTANGLE);
}

void CSketcherDoc::OnUpdateElementLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current element is a line
   pCmdUI->SetCheck(m_Element==LINE);
	
}

void CSketcherDoc::OnUpdateElementCurve(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current element is a curve
   pCmdUI->SetCheck(m_Element==CURVE);
	
}

void CSketcherDoc::OnUpdateElementCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current element is a circle
   pCmdUI->SetCheck(m_Element==CIRCLE);
	
}

void CSketcherDoc::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current color is red
   pCmdUI->SetCheck(m_Element==RED);
}

void CSketcherDoc::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current color is green
   pCmdUI->SetCheck(m_Element==GREEN);
}

void CSketcherDoc::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current color is blue
   pCmdUI->SetCheck(m_Element==BLUE);
}

void CSketcherDoc::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
   // Set Checked if the current color is black
   pCmdUI->SetCheck(m_Element==BLACK);
}
