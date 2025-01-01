// Signal.h : Declaration of the CSignal

#ifndef __SIGNAL_H_
#define __SIGNAL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "ATLSignalCP.h"


/////////////////////////////////////////////////////////////////////////////
// CSignal
class ATL_NO_VTABLE CSignal : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ISignal, &IID_ISignal, &LIBID_ATLSIGNALLib>,
	public CComControl<CSignal>,
	public IPersistStreamInitImpl<CSignal>,
	public IOleControlImpl<CSignal>,
	public IOleObjectImpl<CSignal>,
	public IOleInPlaceActiveObjectImpl<CSignal>,
	public IViewObjectExImpl<CSignal>,
	public IOleInPlaceObjectWindowlessImpl<CSignal>,
	public IConnectionPointContainerImpl<CSignal>,
	public IPersistStorageImpl<CSignal>,
	public ISpecifyPropertyPagesImpl<CSignal>,
	public IQuickActivateImpl<CSignal>,
	public IDataObjectImpl<CSignal>,
	public IProvideClassInfo2Impl<&CLSID_Signal, &DIID__ISignalEvents,
																&LIBID_ATLSIGNALLib>,
	public IPropertyNotifySinkCP<CSignal>,
	public CComCoClass<CSignal, &CLSID_Signal>,
	public CProxy_ISignalEvents< CSignal >
{
public:
   CSignal()
   {
      m_bSignalGo = FALSE;         // Not running initially
      m_bStartRed = TRUE;          // Start on red
      m_nTimerID = 100;            // Arbitrary ID for timer
      m_lStopOrGoTime = 5000L;     // Stop or go light on for 5 seconds
      m_nChangeTime = 2000;        // Orange light on for 2 seconds
		m_bWindowOnly = TRUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SIGNAL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSignal)
	COM_INTERFACE_ENTRY(ISignal)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CSignal)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CSignal)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__ISignalEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CSignal)
	CHAIN_MSG_MAP(CComControl<CSignal>)
	DEFAULT_REFLECTION_HANDLER()
   MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
   MESSAGE_HANDLER(WM_TIMER, OnTimer)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// ISignal
public:
	STDMETHOD(get_StopOrGoTime)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_StopOrGoTime)(/*[in]*/ long newVal);
	STDMETHOD(get_StartRed)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_StartRed)(/*[in]*/ BOOL newVal);
   HRESULT OnDraw(ATL_DRAWINFO& di);
   LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
   void StartSignal();                // Start the signal
   void StopSignal();                 // Stop the signal
   LRESULT OnTimer(UINT nIDEvent, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

private:
   CTrafficSignal m_TrafficSignal;   // The traffic signal
   long m_lStopOrGoTime;             // Stop/Go duration in msecs
   BOOL m_bStartRed;                 // TRUE to start on red
   BOOL m_bSignalGo;                 // True to start the signal
   int m_nTimerID;                   // ID of timer controlling the signal
   int m_nChangeTime;                // Time for READY_TO_STOP in msecs.
};

#endif //__SIGNAL_H_
