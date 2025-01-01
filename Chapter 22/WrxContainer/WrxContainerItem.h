// WrxContainerItem.h : interface of the CWrxContainerItem class
//

#if !defined(AFX_WRXCONTAINERTEM_H__928E8092_591A_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_WRXCONTAINERTEM_H__928E8092_591A_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HINT_UPDATE_ITEM 1       // Indicates a hint is present

class CWrxContainerDoc;
class CWrxContainerView;

class CWrxContainerItem : public COleClientItem
{
	DECLARE_SERIAL(CWrxContainerItem)

// Constructors
public:
	CWrxContainerItem(CWrxContainerDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CWrxContainerDoc* GetDocument()
		{ return (CWrxContainerDoc*)COleClientItem::GetDocument(); }
	CWrxContainerView* GetActiveView()
		{ return (CWrxContainerView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWrxContainerItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	void GetServerSize();
	void InvalidateItem();
	CRect m_Rect;
	~CWrxContainerItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRXCONTAINERTEM_H__928E8092_591A_11D2_963F_00A0C94CB8B3__INCLUDED_)
