// RefRate.cpp : Implementation of CRefRate
#include "stdafx.h"
#include "RefreshRate.h"
#include "RefRate.h"

/////////////////////////////////////////////////////////////////////////////
// CRefRate

// Calculate the refresh rate
HRESULT __stdcall CRefRate::RefreshRate(long MaxHScan, long* retval)
{
   int ScreenY = GetSystemMetrics(SM_CYSCREEN); // Get vertical
   ScreenY = (int)(1.04 * ScreenY);             // Allow for overscan areas
   *retval = MaxHScan * 1000 / ScreenY;         // Return to client
   return S_OK;                                 // Return to COM
}

HRESULT __stdcall CRefRate::GetVRes(long* retval)
{
   *retval = GetSystemMetrics(SM_CYSCREEN); // Return horizontal resolution
   return S_OK;                             // Return to COM environment
}

HRESULT __stdcall CRefRate::GetHRes(long* retval)
{
   *retval = GetSystemMetrics(SM_CXSCREEN); // Return vertical resolution
   return S_OK;                             // Return to COM environment
}
