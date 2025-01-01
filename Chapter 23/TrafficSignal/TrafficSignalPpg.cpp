// TrafficSignalPpg.cpp : Implementation of the CTrafficSignalPropPage property page class.

#include "stdafx.h"
#include "TrafficSignal.h"
#include "TrafficSignalPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTrafficSignalPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTrafficSignalPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTrafficSignalPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTrafficSignalPropPage, "TRAFFICSIGNAL.TrafficSignalPropPage.1",
	0xa833b92b, 0x78ff, 0x11d0, 0x92, 0x57, 0, 0x20, 0x18, 0x34, 0xe2, 0xa3)


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage::CTrafficSignalPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTrafficSignalPropPage

BOOL CTrafficSignalPropPage::CTrafficSignalPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TRAFFICSIGNAL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage::CTrafficSignalPropPage - Constructor

CTrafficSignalPropPage::CTrafficSignalPropPage() :
	COlePropertyPage(IDD, IDS_TRAFFICSIGNAL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTrafficSignalPropPage)
	m_bStartRed = TRUE;
	m_lStopOrGoTime = 5000;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage::DoDataExchange - Moves data between page and properties

void CTrafficSignalPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTrafficSignalPropPage)
	DDP_Check(pDX, IDC_CHECK1, m_bStartRed, _T("StartRed") );
	DDX_Check(pDX, IDC_CHECK1, m_bStartRed);
	DDP_Text(pDX, IDC_EDIT1, m_lStopOrGoTime, _T("StopOrGoTime") );
	DDX_Text(pDX, IDC_EDIT1, m_lStopOrGoTime);
	//}}AFX_DATA_MAP
    DDV_MinMaxUInt(pDX, m_lStopOrGoTime, 1000, 30000);
    DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage message handlers
