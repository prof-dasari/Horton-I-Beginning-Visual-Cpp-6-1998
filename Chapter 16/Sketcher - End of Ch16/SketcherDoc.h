// SketcherDoc.h : interface of the CSketcherDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKETCHERDOC_H__AD38130E_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
#define AFX_SKETCHERDOC_H__AD38130E_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSketcherDoc : public CDocument
{
protected: // create from serialization only
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// Attributes
public:

protected:
	COLORREF m_Color;        // Current drawing color
	WORD m_Element;          // Current element type
    CTypedPtrList<CObList, CElement*> m_ElementList;  // Element list

// Operations
public:
   WORD GetElementType() const               // Get the element type
   { return m_Element; }

   COLORREF GetElementColor() const          // Get the element color
   { return m_Color; } 

   void AddElement(CElement* pElement)       // Add an element to the list
   { m_ElementList.AddTail(pElement); }

   POSITION GetListHeadPosition() const   // Return list head POSITION value
   { return m_ElementList.GetHeadPosition(); }

   CElement* GetNext(POSITION& aPos) const // Return current element pointer
   { return m_ElementList.GetNext(aPos); }

   POSITION GetListTailPosition() const      // Return list tail POSITION value
   { return m_ElementList.GetTailPosition(); }

   CElement* GetPrev(POSITION& aPos) const   // Return current element pointer
   { return m_ElementList.GetPrev(aPos); }

   void DeleteElement(CElement* pElement);  // Delete an element
   void CSketcherDoc::SendToBack(CElement* pElement);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSketcherDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSketcherDoc)
	afx_msg void OnColorBlack();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnColorRed();
	afx_msg void OnElementCircle();
	afx_msg void OnElementCurve();
	afx_msg void OnElementLine();
	afx_msg void OnElementRectangle();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementCurve(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementRectangle(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKETCHERDOC_H__AD38130E_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
