#if !defined(AFX_TRAFFICSIGNALCTL_H__A833B938_78FF_11D0_9257_00201834E2A3__INCLUDED_)
#define AFX_TRAFFICSIGNALCTL_H__A833B938_78FF_11D0_9257_00201834E2A3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// TrafficSignalCtl.h : Declaration of the CTrafficSignalCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl : See TrafficSignalCtl.cpp for implementation.

class CTrafficSignal;

class CTrafficSignalCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTrafficSignalCtrl)

protected:
   CTrafficSignal* m_pSignal;     // Pointer to a traffic signal object
   long m_lStopOrGoTime;          // Duration of stop period, or go period
   UINT m_nChangeTime;            // Duration of orange period
   BOOL m_bSignalGo;              // TRUE indicates the signal is running 
   UINT m_nTimerID;               // Timer event ID

// Constructor
public:
	CTrafficSignalCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrafficSignalCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CTrafficSignalCtrl();

	DECLARE_OLECREATE_EX(CTrafficSignalCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTrafficSignalCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTrafficSignalCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTrafficSignalCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTrafficSignalCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTrafficSignalCtrl)
	BOOL m_bStartRed;
	afx_msg void OnStartRedChanged();
	afx_msg long GetStopOrGoTime();
	afx_msg void SetStopOrGoTime(long nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTrafficSignalCtrl)
	void FireSignalChanged(long lNewState)
		{FireEvent(eventidSignalChanged,EVENT_PARAM(VTS_I4), lNewState);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTrafficSignalCtrl)
	dispidStartRed = 1L,
	dispidStopOrGoTime = 2L,
	eventidSignalChanged = 1L,
	//}}AFX_DISP_ID
	};

private:
	void StopSignal();
	void StartSignal();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAFFICSIGNALCTL_H__A833B938_78FF_11D0_9257_00201834E2A3__INCLUDED)
