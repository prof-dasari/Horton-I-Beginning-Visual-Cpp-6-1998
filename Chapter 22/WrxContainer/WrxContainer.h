// WrxContainer.h : main header file for the WRXCONTAINER application
//

#if !defined(AFX_WRXCONTAINER_H__4CF4EA95_18B5_11D2_BA4B_000000000000__INCLUDED_)
#define AFX_WRXCONTAINER_H__4CF4EA95_18B5_11D2_BA4B_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWrxContainerApp:
// See WrxContainer.cpp for the implementation of this class
//

class CWrxContainerApp : public CWinApp
{
public:
	CWrxContainerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWrxContainerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWrxContainerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRXCONTAINER_H__4CF4EA95_18B5_11D2_BA4B_000000000000__INCLUDED_)
