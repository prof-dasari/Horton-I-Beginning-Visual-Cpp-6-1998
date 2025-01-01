// EX9_06.CPP
// Adding CBox objects
#include <iostream>                             // For stream I/O
using namespace std;

class CBox                                      // Class definition at global scope
{
   public:
      // Constructor definition
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0): m_Height(hv)
      {
         m_Length = lv > bv? lv: bv;            // Ensure that 
         m_Breadth = bv < lv? bv: lv;           // length >= breadth
      }

      // Function to calculate the volume of a box
      double Volume() const
      {
         return m_Length*m_Breadth*m_Height;
      }

      // Operator function for 'greater than' which
      // compares volumes of CBox objects.
      int CBox::operator>(const CBox& aBox) const
      {
         return this->Volume() > aBox.Volume();
      }

      // Function to compare a CBox object with a constant
      int operator>(const double& value) const
      {
         return Volume() > value;
      }

      // Function to add two CBox objects
      CBox operator+(const CBox& aBox) const
      {
         // New object has larger length & breadth, and sum of heights
         return CBox(m_Length > aBox.m_Length? m_Length:aBox.m_Length,
                     m_Breadth > aBox.m_Breadth? m_Breadth:aBox.m_Breadth,
                     m_Height + aBox.m_Height);
      }

      // Function to show the dimensions of a box
      void ShowBox() const
      {
         cout << m_Length << " " << m_Breadth << " " << m_Height
              << endl;
      }

   private:
      double m_Length;                          // Length of a box in inches
      double m_Breadth;                         // Breadth of a box in inches
      double m_Height;                          // Height of a box in inches
};

int operator>(const double& value, const CBox& aBox); // Function prototype

int main()
{
   CBox smallBox(4.0, 2.0, 1.0);
   CBox mediumBox(10.0, 4.0, 2.0);
   CBox aBox;
   CBox bBox;

   aBox = smallBox + mediumBox;
   cout << "aBox dimensions are ";
   aBox.ShowBox();

   bBox = aBox + smallBox + mediumBox;
   cout << "bBox dimensions are ";
   bBox.ShowBox();

   return 0;
}

// Function comparing a constant with a CBox object
int operator>(const double& value, const CBox& aBox)
{
   return value > aBox.Volume();
}
