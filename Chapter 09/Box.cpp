// Box.cpp: implementation of the CBox class.
//
//////////////////////////////////////////////////////////////////////

#include "Box.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBox::CBox(double lv, double bv, double hv)
{
   lv = lv <= 0.0? 1.0:lv;                   // Ensure positive
   bv = bv <= 0.0? 1.0:bv;                   // dimensions for
   hv = hv <= 0.0? 1.0:hv;                   // the object

   m_Length = lv > bv? lv:bv;                // Ensure that
   m_Breadth = bv < lv? bv:lv;               // length >= breadth
   m_Height = hv;
}

CBox::~CBox()
{

}

CBox CBox::operator +(const CBox& aBox) const
{
   // New object has larger length and breadth of the two,
   // and sum of the two heights
   return CBox(m_Length > aBox.m_Length? m_Length:aBox.m_Length,
               m_Breadth > aBox.m_Breadth? m_Breadth:aBox.m_Breadth,
               m_Height + aBox.m_Height);
}

CBox CBox::operator *(int n) const
{
   if(n%2)
      return CBox(m_Length, m_Breadth, n*m_Height);           // n odd
   else
      return CBox(m_Length, 2.0*m_Breadth, (n/2)*m_Height);   // n even
}

int CBox::operator /(const CBox& aBox) const
{
   // Temporary for number in horizontal plane this way
   int tc1 = 0;
   // Temporary for number in a plane that way
   int tc2 = 0;

   tc1 = static_cast<int>((m_Length / aBox.m_Length))*
         static_cast<int>((m_Breadth / aBox.m_Breadth)); 	   // to fit
										   // this way
   tc2 = static_cast<int>((m_Length / aBox.m_Breadth))*
         static_cast<int>((m_Breadth / aBox.m_Length));	   // and that way

   //Return best fit
   return static_cast<int>((m_Height / aBox.m_Height))*(tc1 > tc2? tc1:tc2);
}
