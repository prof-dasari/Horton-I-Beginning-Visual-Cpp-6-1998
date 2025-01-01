// UseRefRateView.h : interface of the CUseRefRateView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEREFRATEVIEW_H__A322F7EE_7DA8_11D0_96FE_002018349816__INCLUDED_)
#define AFX_USEREFRATEVIEW_H__A322F7EE_7DA8_11D0_96FE_002018349816__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class IRefRate;                // The RefRate dispatch driver class

class CUseRefRateView : public CFormView
{
protected: // create from serialization only
	CUseRefRateView();
	DECLARE_DYNCREATE(CUseRefRateView)

public:
	//{{AFX_DATA(CUseRefRateView)
	enum { IDD = IDD_USEREFRATE_FORM };
	long	m_lHScan;
	long	m_lRefresh;
	long	m_lHRes;
	long	m_lVRes;
	//}}AFX_DATA

// Attributes
public:
	CUseRefRateDoc* GetDocument();

public:
   IRefRate* m_pRefRateDriver;   // Pointer to dispatch driver for RefRate


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRefRateView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseRefRateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseRefRateView)
	afx_msg void OnCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseRefRateView.cpp
inline CUseRefRateDoc* CUseRefRateView::GetDocument()
   { return (CUseRefRateDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEREFRATEVIEW_H__A322F7EE_7DA8_11D0_96FE_002018349816__INCLUDED_)
