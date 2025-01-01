// UseRefRate.h : main header file for the USEREFRATE application
//

#if !defined(AFX_USEREFRATE_H__A322F7E6_7DA8_11D0_96FE_002018349816__INCLUDED_)
#define AFX_USEREFRATE_H__A322F7E6_7DA8_11D0_96FE_002018349816__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseRefRateApp:
// See UseRefRate.cpp for the implementation of this class
//

class CUseRefRateApp : public CWinApp
{
public:
	CUseRefRateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRefRateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseRefRateApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEREFRATE_H__A322F7E6_7DA8_11D0_96FE_002018349816__INCLUDED_)
