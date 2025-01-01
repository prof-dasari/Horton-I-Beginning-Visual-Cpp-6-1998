// TrafficSignalCtl.cpp : Implementation of the CTrafficSignalCtrl ActiveX Control class.

#include "stdafx.h"
#include "TrafficSignal.h"
#include "TrafficSignalCtl.h"
#include "TrafficSignalPpg.h"

#include "OurTrafficSignal.h"
#include "OurConstants.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTrafficSignalCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTrafficSignalCtrl, COleControl)
	//{{AFX_MSG_MAP(CTrafficSignalCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTrafficSignalCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTrafficSignalCtrl)
	DISP_PROPERTY_NOTIFY(CTrafficSignalCtrl, "StartRed", m_bStartRed, OnStartRedChanged, VT_BOOL)
	DISP_PROPERTY_EX(CTrafficSignalCtrl, "StopOrGoTime", GetStopOrGoTime, SetStopOrGoTime, VT_I4)
	DISP_STOCKPROP_BACKCOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTrafficSignalCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTrafficSignalCtrl, COleControl)
	//{{AFX_EVENT_MAP(CTrafficSignalCtrl)
	EVENT_CUSTOM("SignalChanged", FireSignalChanged, VTS_I4)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTrafficSignalCtrl, 1)
	PROPPAGEID(CTrafficSignalPropPage::guid)
END_PROPPAGEIDS(CTrafficSignalCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTrafficSignalCtrl, "TRAFFICSIGNAL.TrafficSignalCtrl.1",
	0xa833b92a, 0x78ff, 0x11d0, 0x92, 0x57, 0, 0x20, 0x18, 0x34, 0xe2, 0xa3)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTrafficSignalCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTrafficSignal =
		{ 0xa833b928, 0x78ff, 0x11d0, { 0x92, 0x57, 0, 0x20, 0x18, 0x34, 0xe2, 0xa3 } };
const IID BASED_CODE IID_DTrafficSignalEvents =
		{ 0xa833b929, 0x78ff, 0x11d0, { 0x92, 0x57, 0, 0x20, 0x18, 0x34, 0xe2, 0xa3 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTrafficSignalOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTrafficSignalCtrl, IDS_TRAFFICSIGNAL, _dwTrafficSignalOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::CTrafficSignalCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTrafficSignalCtrl

BOOL CTrafficSignalCtrl::CTrafficSignalCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TRAFFICSIGNAL,
			IDB_TRAFFICSIGNAL,
			afxRegApartmentThreading,
			_dwTrafficSignalOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::CTrafficSignalCtrl - Constructor

CTrafficSignalCtrl::CTrafficSignalCtrl()
{
   InitializeIIDs(&IID_DTrafficSignal, &IID_DTrafficSignalEvents);

   m_pSignal = new CTrafficSignal;     // Create a signal
   m_bSignalGo = FALSE;                // Signal not running initially
   m_nChangeTime = 1500U;              // Change over time in milliseconds
   m_nTimerID = 10;                    // Timer ID
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::~CTrafficSignalCtrl - Destructor

CTrafficSignalCtrl::~CTrafficSignalCtrl()
{
   delete m_pSignal;                   // Delete the signal
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::OnDraw - Drawing function

void CTrafficSignalCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
   // Set the background using the control's BackColor property
   CBrush brBack(TranslateColor(GetBackColor()));
   // Set the background using the container's ambient BackColor property
   // CBrush brBack(TranslateColor(AmbientBackColor()));

   pdc->FillRect(rcBounds, &brBack);   // Fill the background

   // Set the height of the signal
   m_pSignal->SetHeight(abs(rcBounds.Height())); 

   // The reference point for the signal is the middle of its base
   // so set the position of the signal at the midway point
   // along the bottom of the bound rectangle
   CPoint ptPosition(((long)rcBounds.right + rcBounds.left)/2L, rcBounds.bottom);
   m_pSignal->SetPosition(ptPosition);
   m_pSignal->Draw(pdc);               // Draw the signal
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::DoPropExchange - Persistence support

void CTrafficSignalCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

   // TODO: Call PX_ functions for each persistent custom property.
   PX_Bool(pPX, _T("StartRed"), m_bStartRed, TRUE);
   PX_Long(pPX, _T("StopOrGoTime"), m_lStopOrGoTime, 5000);

   // Set the signal state from the StartRed property
   if(m_bStartRed)
      m_pSignal->SetSignalState(STOP);
   else
      m_pSignal->SetSignalState(GO);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::OnResetState - Reset control to default state

void CTrafficSignalCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::AboutBox - Display an "About" box to the user

void CTrafficSignalCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TRAFFICSIGNAL);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl message handlers

void CTrafficSignalCtrl::OnStartRedChanged() 
{
   // Stop the signal if necessary
   if (m_bSignalGo)
   {
      m_bSignalGo = FALSE;  // Set signal not running
      StopSignal();         // Stop the signal
   }
   // Set the signal object to the appropriate state
   if (m_bStartRed)
      m_pSignal->SetSignalState(STOP);
   else
      m_pSignal->SetSignalState(GO);

   InvalidateControl();  // Get the control redrawn

   SetModifiedFlag();
}

long CTrafficSignalCtrl::GetStopOrGoTime() 
{
   return m_lStopOrGoTime;    // Return the current interval
}

void CTrafficSignalCtrl::SetStopOrGoTime(long nNewValue) 
{
   // Only alter the control if the value is different
   if (m_lStopOrGoTime != nNewValue)
   {
      m_lStopOrGoTime = nNewValue;       // Set the new stop or go time

      OnStartRedChanged();               // Set the initial state
      SetModifiedFlag();
   }
}

void CTrafficSignalCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
   // If the signal is stopped, start it
   // If the signal is running, stop it
   m_bSignalGo = !m_bSignalGo;
   if (m_bSignalGo)
      StartSignal();
   else
      StopSignal();
	
   COleControl::OnLButtonDown(nFlags, point);
}

void CTrafficSignalCtrl::StartSignal()
{
   // Setup a timer with the required interval
   m_nTimerID = SetTimer(m_nTimerID, (UINT)m_lStopOrGoTime, NULL);
   if (!m_nTimerID)
   {
      AfxMessageBox("No Timer!");
      exit(1);
   }
   InvalidateControl();   // Get the control redrawn
}

void CTrafficSignalCtrl::StopSignal()
{
   KillTimer(m_nTimerID);    // Destroy the timer
   InvalidateControl();      // Redraw the control
}

void CTrafficSignalCtrl::OnTimer(UINT nIDEvent) 
{
   UINT nInterval = 0;   // Interval in milliseconds

   // Step to the next state and set the time interval
   // based on the new state
   int nNewState = m_pSignal->NextState();
   switch (nNewState)
   {
      case STOP: case GO:
         nInterval = (UINT)m_lStopOrGoTime;     // Stop or Go interval
         break;
      default:
         nInterval = m_nChangeTime;             // Transient interval
   }
   FireSignalChanged(nNewState);

   InvalidateControl();                         // Redraw the signal
   
   // Make sure the old timer is dead
   KillTimer(m_nTimerID);
   // Set a new timer event
   m_nTimerID = SetTimer(m_nTimerID, nInterval, NULL);
   if (!m_nTimerID)
   {
      AfxMessageBox("No Timer!");
      exit(1);
   }
}
