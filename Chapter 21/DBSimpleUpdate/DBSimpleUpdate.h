// DBSimpleUpdate.h : main header file for the DBSIMPLEUPDATE application
//

#if !defined(AFX_DBSIMPLEUPDATE_H__F37F0EC5_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
#define AFX_DBSIMPLEUPDATE_H__F37F0EC5_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Orderset.h"

/////////////////////////////////////////////////////////////////////////////
// CDBSimpleUpdateApp:
// See DBSimpleUpdate.cpp for the implementation of this class
//

class CDBSimpleUpdateApp : public CWinApp
{
public:
	CDBSimpleUpdateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSimpleUpdateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDBSimpleUpdateApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBSIMPLEUPDATE_H__F37F0EC5_1EAC_11D2_B73A_A6BF29FB7506__INCLUDED_)
