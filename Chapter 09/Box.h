// Box.h: interface for the CBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOX_H__E9ED1982_BCFE_11D1_915E_00A0C94515AD__INCLUDED_)
#define AFX_BOX_H__E9ED1982_BCFE_11D1_915E_00A0C94515AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBox
{
public:
   int operator/(const CBox& aBox) const;          // Divide one box into another
   CBox operator*(int n) const;                    // Multiply a box by an integer
   CBox operator+(const CBox& aBox) const;         // Add two boxes
   double GetHeight() const { return m_Height; }   // Get box height
   double GetBreadth() const { return m_Breadth; } // Get box breadth
   double GetLength() const { return m_Length; }   // Get box length
   double Volume() const                           // Calculate volume
   { return m_Length*m_Breadth*m_Height; }

   CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0);
   virtual ~CBox();

private:
   double m_Height;
   double m_Breadth;
   double m_Length;
};


#endif // !defined(AFX_BOX_H__E9ED1982_BCFE_11D1_915E_00A0C94515AD__INCLUDED_)
