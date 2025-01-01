// OurTrafficSignal.cpp: implementation of the CTrafficSignal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TrafficSignal.h"
#include "OurTrafficSignal.h"
#include "OurConstants.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrafficSignal::CTrafficSignal()
{
   m_ptPosition = CPoint(0, 0); // Set arbitrary position
   m_nHeight = 1000;            // Set arbitrary height
   m_nSignalState = STOP;       // Set initial state to STOP
}

CTrafficSignal::~CTrafficSignal()
{

}

// Change the signal state to the next in sequence
int CTrafficSignal::NextState()
{
   switch (m_nSignalState)
   {
      case STOP:
         m_nSignalState = GO;
         break;
      case GO:
         m_nSignalState = READY_TO_STOP;
         break;
      case READY_TO_STOP:
         m_nSignalState = STOP;
         break;
      default:
         m_nSignalState = STOP;
         AfxMessageBox("Invalid signal state");
   }
   return m_nSignalState;
}

// Draw the signal
void CTrafficSignal::Draw(CDC* pDC)
{
   // Set the pen and brush to draw the signal
   CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(GRAY_BRUSH);
   CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);

   // Define the main body of the signal
   int nLeft = m_ptPosition.x - m_nHeight/7;
   int nTop = m_ptPosition.y - (long)m_nHeight*6L/7L;
   int nRight = m_ptPosition.x + m_nHeight/7;
   int nBottom = m_ptPosition.y;
   
   pDC->Rectangle(nLeft, nTop, nRight, nBottom);  // Draw the body

   // Define the semi-circular top of the signal
   CRect rect(nLeft, nTop - m_nHeight/7, nRight, nTop + m_nHeight/7);
   CPoint ptStart(nRight, nTop);
   CPoint ptEnd(nLeft, nTop);

   pDC->Chord(rect, ptStart, ptEnd);

   // Create brushes for the lights
   CBrush brStop;              // A brush to fill the stop light
   CBrush brReady;             // A brush to fill the ready light
   CBrush brGo;                // A brush to fill the go light

   switch (m_nSignalState)
   {
      case STOP:                                // Red only
         brStop.CreateSolidBrush(RED);
         brReady.CreateSolidBrush(GRAY);
         brGo.CreateSolidBrush(GRAY);
         break;
      case GO:                                  // Green only
         brStop.CreateSolidBrush(GRAY);
         brReady.CreateSolidBrush(GRAY);
         brGo.CreateSolidBrush(GREEN);
         break;
      case READY_TO_STOP:                       // Orange only
         brStop.CreateSolidBrush(GRAY);
         brReady.CreateSolidBrush(ORANGE);
         brGo.CreateSolidBrush(GRAY);
         break;
      default:
         brStop.CreateSolidBrush(GRAY);
         brReady.CreateSolidBrush(GRAY);
         brGo.CreateSolidBrush(GRAY);
   }

   // Define the rectangle bounding the stop light
   int nMargin = (long)m_nHeight * 2L/70L;   // Ten percent of the width
   nLeft += nMargin;                         // Left side of stop light
   nTop += nMargin;                          // Top of stop light
   nRight -= nMargin;                        // Right side of stop light
   int nStep = (long)m_nHeight * 2L/7L;      // Distance between lights
   nBottom = nTop + nStep - 2 * nMargin;     // Bottom of stop light 

   // Draw the stop light
   pDC->SelectObject(&brStop);
   pDC->Ellipse(nLeft, nTop, nRight, nBottom);

   // Set the position of the ready light
   nTop += nStep;
   nBottom += nStep;

   // Draw the ready light
   pDC->SelectObject(&brReady);
   pDC->Ellipse(nLeft, nTop, nRight, nBottom);

   // Set the position of the go light
   nTop += nStep;
   nBottom += nStep;

   // Draw the go light
   pDC->SelectObject(&brGo);
   pDC->Ellipse(nLeft, nTop, nRight, nBottom);

   pDC->SelectObject(pOldBrush);       // Put the old brush back
   pDC->SelectObject(pOldPen);         // Put the old pen back
}
