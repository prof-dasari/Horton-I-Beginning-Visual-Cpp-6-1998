// SketcherDoc.cpp : implementation of the CSketcherDoc class
//

#include "stdafx.h"
#include "Sketcher.h"
#include "PenDialog.h"

#include "Elements.h"
#include "SketcherDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
	//{{AFX_MSG_MAP(CSketcherDoc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_ELEMENT_CIRCLE, OnElementCircle)
	ON_COMMAND(ID_ELEMENT_CURVE, OnElementCurve)
	ON_COMMAND(ID_ELEMENT_LINE, OnElementLine)
	ON_COMMAND(ID_ELEMENT_RECTANGLE, OnElementRectangle)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, OnUpdateElementCircle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, OnUpdateElementCurve)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, OnUpdateElementLine)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, OnUpdateElementRectangle)
	ON_COMMAND(ID_PENWIDTH, OnPenwidth)
	ON_COMMAND(ID_ELEMENT_TEXT, OnElementText)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_TEXT, OnUpdateElementText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc construction/destruction

CSketcherDoc::CSketcherDoc()
{
	// TODO: add one-time construction code here
   m_Element = LINE;   // Set initial element type
   m_Color = BLACK;    // Set initial drawing color
   m_PenWidth = 0;     // Set 1 pixel pen
   m_DocSize = CSize(3000,3000); // Set initial document size 30x30 inches
}

CSketcherDoc::~CSketcherDoc()
{
   // Get the position at the head of the list
   POSITION aPosition = m_ElementList.GetHeadPosition();

   // Now delete the element pointed to by each list entry
   while(aPosition)
      delete m_ElementList.GetNext(aPosition);

   m_ElementList.RemoveAll();   // Finally delete all pointers
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc serialization

void CSketcherDoc::Serialize(CArchive& ar)
{
   m_ElementList.Serialize(ar);    // Serialize the element list

   if (ar.IsStoring())
   {
      ar << m_Color                // Store the current color
         << m_Element              // the current element type,
         << m_PenWidth             // and the current pen width
         << m_DocSize;             // and the current document size
   }
   else
   {
      ar >> m_Color                // Retrieve the current color
         >> m_Element              // the current element type,
         >> m_PenWidth             // and the current pen width
         >> m_DocSize;             // and the current document size
   }
}

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc diagnostics

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSketcherDoc commands

void CSketcherDoc::OnColorBlack() 
{
   m_Color = BLACK;        // Set the drawing color to black	
}

void CSketcherDoc::OnColorBlue() 
{
   m_Color = BLUE;        // Set the drawing color to blue
}

void CSketcherDoc::OnColorGreen() 
{
   m_Color = GREEN;        // Set the drawing color to green
}

void CSketcherDoc::OnColorRed() 
{
   m_Color = RED;        // Set the drawing color to red
}

void CSketcherDoc::OnElementCircle() 
{
   m_Element = CIRCLE;       // Set element type as a circle
}

void CSketcherDoc::OnElementCurve() 
{
   m_Element = CURVE;       // Set element type as a curve
}

void CSketcherDoc::OnElementLine() 
{
   m_Element = LINE;       // Set element type as a line
}

void CSketcherDoc::OnElementRectangle() 
{
   m_Element = RECTANGLE;       // Set element type as a rectangle
}

void CSketcherDoc::OnUpdateColorBlack(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is black
   pCmdUI->SetCheck(m_Color==BLACK);
}

void CSketcherDoc::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is blue
   pCmdUI->SetCheck(m_Color==BLUE);
}

void CSketcherDoc::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is green
   pCmdUI->SetCheck(m_Color==GREEN);
}

void CSketcherDoc::OnUpdateColorRed(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is red
   pCmdUI->SetCheck(m_Color==RED);
}

void CSketcherDoc::OnUpdateElementCircle(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a circle
   pCmdUI->SetCheck(m_Element==CIRCLE);
}

void CSketcherDoc::OnUpdateElementCurve(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a curve
   pCmdUI->SetCheck(m_Element==CURVE);
}

void CSketcherDoc::OnUpdateElementLine(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a line
   pCmdUI->SetCheck(m_Element==LINE);
}

void CSketcherDoc::OnUpdateElementRectangle(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a rectangle
   pCmdUI->SetCheck(m_Element==RECTANGLE);
}

void CSketcherDoc::DeleteElement(CElement* pElement)
{
   if(pElement)
   {
      // If the element pointer is valid,
      // find the pointer in the list and delete it
      SetModifiedFlag();         // Set the modified flag
      POSITION aPosition = m_ElementList.Find(pElement);
      m_ElementList.RemoveAt(aPosition);
      delete pElement;           // Delete the element from the heap
   }
}

void CSketcherDoc::SendToBack(CElement* pElement)
{
   if(pElement)
   {
      // If the element pointer is valid,
      // find the pointer in the list and remove the element
      POSITION aPosition = m_ElementList.Find(pElement);
      m_ElementList.RemoveAt(aPosition);

      m_ElementList.AddHead(pElement);  // Put it back to the beginning
   }
}

// Handler for the pen width menu item
void CSketcherDoc::OnPenwidth()
{
   CPenDialog aDlg;     // Create a local dialog object

   // Set the pen width in the dialog to that stored in the document
   aDlg.m_PenWidth = m_PenWidth;

   // Display the dialog as modal
   // When closed with OK, get the pen width
   if(aDlg.DoModal() == IDOK)
      m_PenWidth = aDlg.m_PenWidth;
}

void CSketcherDoc::OnElementText() 
{
	m_Element = TEXT;
}

void CSketcherDoc::OnUpdateElementText(CCmdUI* pCmdUI) 
{
   // Set checked if the current element is text
   pCmdUI->SetCheck(m_Element == TEXT);
}

// Get the rectangle enclosing the entire document
CRect CSketcherDoc::GetDocExtent() const
{
   CRect DocExtent(0,0,1,1);    // Initial document extent
   CRect ElementBound(0,0,0,0); // Space for element bounding rectangle

   POSITION aPosition = m_ElementList.GetHeadPosition();

   while(aPosition)      // Loop through all the elements in the list
   {
      // Get the bounding rectangle for the element
      ElementBound=(m_ElementList.GetNext(aPosition))->GetBoundRect();

      // Make coordinates of document extent the outer limits
      DocExtent.UnionRect(DocExtent, ElementBound);
   }
   DocExtent.NormalizeRect();
   return DocExtent;
}
