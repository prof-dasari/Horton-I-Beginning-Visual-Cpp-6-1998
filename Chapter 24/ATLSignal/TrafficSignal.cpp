// TrafficSignal.cpp: implementation of the CTrafficSignal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OurConstants.h"
#include "ATLSignal.h"
#include "TrafficSignal.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrafficSignal::CTrafficSignal()
{
   m_ptPosition.x = m_ptPosition.y = 0; // Set arbitrary position
   m_nHeight = 1000;                    // Set arbitrary height
   m_nSignalState = STOP;               // Set initial state to STOP
}


CTrafficSignal::~CTrafficSignal()
{

}

// Change the signal state to the next in sequence
int CTrafficSignal::NextState()
{
   switch (m_nSignalState)
   {
      case STOP:                       // Next after STOP is GO
         m_nSignalState = GO;
         break;
      case GO:                         // Next after GO is READY_TO_STOP
         m_nSignalState = READY_TO_STOP;
         break;
      case READY_TO_STOP:              // Next after READY_TO_STOP is STOP
         m_nSignalState = STOP;
         break;
      default:                         // We should never get to here
         m_nSignalState = STOP;
         MessageBox(NULL, "Invalid signal state", "ATLSignal Error", MB_OK);
   }
   return m_nSignalState;
}

void CTrafficSignal::Draw(HDC& hDC)
{
   // Set the pen and brush to draw the signal
   HBRUSH hGrayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
   HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hGrayBrush);
   HPEN hBlackPen = (HPEN)GetStockObject(BLACK_PEN);
   HPEN hOldPen = (HPEN)SelectObject(hDC, hBlackPen);

   // Define the main body of the signal
   int nLeft = m_ptPosition.x - m_nHeight/7;
   int nTop = m_ptPosition.y - (long)m_nHeight*6L/7L;
   int nRight = m_ptPosition.x + m_nHeight/7;
   int nBottom = m_ptPosition.y;

   Rectangle(hDC, nLeft, nTop, nRight, nBottom);  // Draw the body

   // Draw the semi-circular top of the signal
   Chord(hDC,                         // Device context
         nLeft, nTop - m_nHeight/7,   // Bounding rectangle top-left
         nRight, nTop + m_nHeight/7,  // Bounding rectangle bottom-right
         nRight, nTop,                // Start point
         nLeft, nTop);                // End Point

      // Create brushes for the lights
   HBRUSH hbrStop;              // A brush to fill the stop light
   HBRUSH hbrReady;             // A brush to fill the ready light
   HBRUSH hbrGo;                // A brush to fill the go light

   switch (m_nSignalState)
   {
      case STOP:                                // Red only
         hbrStop = CreateSolidBrush(RED);
         hbrReady = CreateSolidBrush(GRAY);
         hbrGo = CreateSolidBrush(GRAY);
         break;
      case GO:                                  // Green only
         hbrStop = CreateSolidBrush(GRAY);
         hbrReady = CreateSolidBrush(GRAY);
         hbrGo = CreateSolidBrush(GREEN);
         break;
      case READY_TO_STOP:                       // Orange only
         hbrStop = CreateSolidBrush(GRAY);
         hbrReady = CreateSolidBrush(ORANGE);
         hbrGo = CreateSolidBrush(GRAY);
         break;
      default:
         hbrStop = CreateSolidBrush(GRAY);
         hbrReady = CreateSolidBrush(GRAY);
         hbrGo = CreateSolidBrush(GRAY);
   }

   // Define the rectangle bounding the stop light
   int nMargin = (long)m_nHeight * 2L/70L;   // Ten percent of the width
   nLeft += nMargin;                         // Left side of stop light
   nTop += nMargin;                          // Top of stop light
   nRight -= nMargin;                        // Right side of stop light
   int nStep = (long)m_nHeight * 2L/7L;      // Distance between lights
   nBottom = nTop + nStep - 2 * nMargin;     // Bottom of stop light 

   // Draw the stop light
   SelectObject(hDC, hbrStop);
   Ellipse(hDC, nLeft, nTop, nRight, nBottom);

   // Set the position of the ready light
   nTop += nStep;
   nBottom += nStep;

   // Draw the ready light
   SelectObject(hDC, hbrReady);
   Ellipse(hDC, nLeft, nTop, nRight, nBottom);

   // Set the position of the go light
   nTop += nStep;
   nBottom += nStep;

   // Draw the go light
   SelectObject(hDC, hbrGo);
   Ellipse(hDC, nLeft, nTop, nRight, nBottom);

   SelectObject(hDC, hOldBrush);       // Put the old brush back
   SelectObject(hDC, hOldPen);         // Put the old pen back

   // Delete the brushes we have created
   DeleteObject(hbrStop);
   DeleteObject(hbrReady);
   DeleteObject(hbrGo);

}
