// RefRate.h : Declaration of the CRefRate

#ifndef __REFRATE_H_
#define __REFRATE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRefRate
class ATL_NO_VTABLE CRefRate : 
   public CComObjectRootEx<CComSingleThreadModel>,
   public CComCoClass<CRefRate, &CLSID_RefRate>,
   public IDispatchImpl<IRefRate, &IID_IRefRate, &LIBID_REFRESHRATELib>
{
public:
   CRefRate()
   {
   }

DECLARE_REGISTRY_RESOURCEID(IDR_REFRATE)

BEGIN_COM_MAP(CRefRate)
   COM_INTERFACE_ENTRY(IRefRate)
   COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IRefRate
public:
   HRESULT __stdcall RefreshRate(long MaxHScan, long* retval);
   HRESULT __stdcall GetVRes(long* retval);
   HRESULT __stdcall GetHRes(long* retval);
};

#endif //__REFRATE_H_
