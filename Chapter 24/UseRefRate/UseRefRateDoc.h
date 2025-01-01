// UseRefRateDoc.h : interface of the CUseRefRateDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEREFRATEDOC_H__A322F7EC_7DA8_11D0_96FE_002018349816__INCLUDED_)
#define AFX_USEREFRATEDOC_H__A322F7EC_7DA8_11D0_96FE_002018349816__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CUseRefRateDoc : public CDocument
{
protected: // create from serialization only
	CUseRefRateDoc();
	DECLARE_DYNCREATE(CUseRefRateDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRefRateDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseRefRateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseRefRateDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEREFRATEDOC_H__A322F7EC_7DA8_11D0_96FE_002018349816__INCLUDED_)
