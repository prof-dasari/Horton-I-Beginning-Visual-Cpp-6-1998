#if !defined(AFX_TRAFFICSIGNALPPG_H__A833B93A_78FF_11D0_9257_00201834E2A3__INCLUDED_)
#define AFX_TRAFFICSIGNALPPG_H__A833B93A_78FF_11D0_9257_00201834E2A3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// TrafficSignalPpg.h : Declaration of the CTrafficSignalPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage : See TrafficSignalPpg.cpp.cpp for implementation.

class CTrafficSignalPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTrafficSignalPropPage)
	DECLARE_OLECREATE_EX(CTrafficSignalPropPage)

// Constructor
public:
	CTrafficSignalPropPage();

// Dialog Data
	//{{AFX_DATA(CTrafficSignalPropPage)
	enum { IDD = IDD_PROPPAGE_TRAFFICSIGNAL };
	BOOL	m_bStartRed;
	long	m_lStopOrGoTime;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTrafficSignalPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAFFICSIGNALPPG_H__A833B93A_78FF_11D0_9257_00201834E2A3__INCLUDED)
