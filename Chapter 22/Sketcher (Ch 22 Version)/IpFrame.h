// IpFrame.h : interface of the CInPlaceFrame class
//

#if !defined(AFX_IPFRAME_H__453F74B5_1E4C_11D2_99B1_00104B4C84A4__INCLUDED_)
#define AFX_IPFRAME_H__453F74B5_1E4C_11D2_99B1_00104B4C84A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInPlaceFrame : public COleIPFrameWnd
{
	DECLARE_DYNCREATE(CInPlaceFrame)
public:
	CInPlaceFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInPlaceFrame)
	public:
	virtual BOOL OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInPlaceFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CToolBar    m_wndToolBar;
	COleDropTarget	m_dropTarget;
	COleResizeBar   m_wndResizeBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CInPlaceFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPFRAME_H__453F74B5_1E4C_11D2_99B1_00104B4C84A4__INCLUDED_)
