// OurTrafficSignal.h: interface for the CTrafficSignal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OURTRAFFICSIGNAL_H__A833B93C_78FF_11D0_9257_00201834E2A3__INCLUDED_)
#define AFX_OURTRAFFICSIGNAL_H__A833B93C_78FF_11D0_9257_00201834E2A3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTrafficSignal  
{
public:
	CTrafficSignal();
	virtual ~CTrafficSignal();

   // Class interface
   void SetPosition(CPoint ptPosition)
		{m_ptPosition = ptPosition;}
   void SetHeight(int nHeight)
		{m_nHeight = nHeight;}
   void Draw(CDC* pDC);                   // Draw the traffic signal
   void SetSignalState(int nState)
		{m_nSignalState = nState;}
   int NextState();                       // Change to the next state

private:
   CPoint m_ptPosition;   // Bottom center of signal
   int m_nHeight;         // Height of signal
   int m_nSignalState;    // State of signal
};

#endif // !defined(AFX_OURTRAFFICSIGNAL_H__A833B93C_78FF_11D0_9257_00201834E2A3__INCLUDED_)
