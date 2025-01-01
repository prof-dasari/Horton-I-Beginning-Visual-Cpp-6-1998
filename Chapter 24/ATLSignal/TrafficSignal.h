// TrafficSignal.h: interface for the CTrafficSignal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAFFICSIGNAL_H__CACE7C30_5C4E_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_TRAFFICSIGNAL_H__CACE7C30_5C4E_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTrafficSignal  
{
public:
	CTrafficSignal();
	virtual ~CTrafficSignal();

// Class interface
   void SetPosition(int x, int y)
   {
      m_ptPosition.x = x;
      m_ptPosition.y = y;
   }

   void SetHeight(int nHeight) { m_nHeight =nHeight; }
   void SetSignalState(int nSignalState) { m_nSignalState = nSignalState; }
   int NextState();                            // Change to the next state
   void Draw(HDC& hDC);                        // Draw the traffic signal

private:
   POINT m_ptPosition;    // Bottom center of signal
   int m_nHeight;         // Height of signal
   int m_nSignalState;    // State of signal
};

#endif // !defined(AFX_TRAFFICSIGNAL_H__CACE7C30_5C4E_11D2_963F_00A0C94CB8B3__INCLUDED_)
