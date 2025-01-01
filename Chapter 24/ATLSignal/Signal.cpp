// Signal.cpp : Implementation of CSignal

#include "stdafx.h"
#include "ATLSignal.h"
#include "OurConstants.h"
#include "TrafficSignal.h"
#include "Signal.h"

/////////////////////////////////////////////////////////////////////////////
// CSignal

HRESULT CSignal::OnDraw(ATL_DRAWINFO& di)
{
   RECT& rc = *(RECT*)di.prcBounds;           // Get control rectangle
   HDC hDC = di.hdcDraw;                      // Get the device context
   COLORREF clrBackGround;                    // Control background color
   OLE_COLOR clrClientBackColor;              // Client background color

   // Get client backgound color and convert to COLORREF
   GetAmbientBackColor(clrClientBackColor);                      // Get background
   ::OleTranslateColor(clrClientBackColor,NULL,&clrBackGround);  // & convert

   HBRUSH hbrBackground = CreateSolidBrush(clrBackGround); // Create brush
   FillRect(hDC,&rc,hbrBackground);           // Fill control area

   // Define position and height of the traffic signal
   m_TrafficSignal.SetPosition((rc.right+rc.left)/2,rc.bottom);
   m_TrafficSignal.SetHeight(rc.bottom-rc.top);

   m_TrafficSignal.Draw(hDC);                 // Draw the signal
	return S_OK;
}

LRESULT CSignal::OnLButtonDown(UINT uMsg, WPARAM wParam,
                               LPARAM lParam, BOOL& bHandled)
{
   // If the signal is stopped, start it
   // If the signal is running, stop it
   m_bSignalGo = !m_bSignalGo;
   if(m_bSignalGo)
      StartSignal();
   else
      StopSignal();
   return 0;
}


// Start the signal
void CSignal::StartSignal()
{
   // Setup a timer with the required interval
   m_TrafficSignal.SetSignalState(m_bStartRed ? STOP : GO);
   m_nTimerID = SetTimer(m_nTimerID, (UINT)m_lStopOrGoTime);

   if (!m_nTimerID)
      exit(1);               // No timer so exit

   Invalidate();             // Get the control redrawn
}

// Stop the signal
void CSignal::StopSignal()
{
   KillTimer(m_nTimerID);    // Destroy the timer
   Invalidate();             // Redraw the control
}

LRESULT CSignal::OnTimer(UINT nIDEvent, WPARAM wParam,
                         LPARAM lParam, BOOL& bHandled)
{
   UINT nInterval = 0;                         // Interval in milliseconds

   // Step to the next signal state and set the time interval
   // based on the new state
   int nNewState = m_TrafficSignal.NextState();  // Go to next state

   switch (nNewState)
   {
      case STOP: case GO:
         nInterval = (UINT)m_lStopOrGoTime;      // Stop or Go interval
         break;

      default:
         nInterval = m_nChangeTime;              // Transient interval
   }

	Fire_SignalChanged(nNewState);
   Invalidate();                                 // Redraw the signal
   KillTimer(m_nTimerID);               // Make sure the old timer is dead

   // Set a new timer event
   m_nTimerID = SetTimer(m_nTimerID, nInterval);
   if (!m_nTimerID)                               // No timer...
      exit(1);                                   // ...so end the program

   return 0;
}

STDMETHODIMP CSignal::get_StartRed(BOOL *pVal)
{
   *pVal = m_bStartRed;
	return S_OK;
}

STDMETHODIMP CSignal::put_StartRed(BOOL newVal)
{
   m_bStartRed = newVal;
	return S_OK;
}

STDMETHODIMP CSignal::get_StopOrGoTime(long *pVal)
{
   *pVal = m_lStopOrGoTime;
	return S_OK;
}

STDMETHODIMP CSignal::put_StopOrGoTime(long newVal)
{
   m_lStopOrGoTime = newVal;
	return S_OK;
}
