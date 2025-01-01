// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "refreshrate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IRefRate properties

/////////////////////////////////////////////////////////////////////////////
// IRefRate operations

long IRefRate::RefreshRate(long HScan)
{
   long result;
   static BYTE parms[] =
      VTS_I4;
   InvokeHelper(0x60020000, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
      HScan);
   return result;
}

long IRefRate::GetVRes()
{
   long result;
   InvokeHelper(0x60020001, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
   return result;
}

long IRefRate::GetHRes()
{
   long result;
   InvokeHelper(0x60020002, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
   return result;
}
