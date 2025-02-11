// EX8_09.CPP
// Using the pointer this
#include <iostream>
using namespace std;

class CBox                              // Class definition at global scope
{
   public:
      // Constructor definition
   CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0): m_Length(lv),
                                                            m_Breadth(bv),
                                                            m_Height(hv)
      {
         cout << endl << "Constructor called.";
      }

      // Function to calculate the volume of a box
      double Volume()
      {
         return m_Length*m_Breadth*m_Height;
      }

      // Function to compare two boxes which returns true (1)
      // if the first is greater than the second, and false (0) 
      // otherwise
      int Compare(CBox xBox)
      {
         return this->Volume() > xBox.Volume();
      }

   private:
      double m_Length;                       // Length of a box in inches
      double m_Breadth;                      // Breadth of a box in inches
      double m_Height;                       // Height of a box in inches

};

int main()
{
   CBox match(2.2, 1.1, 0.5);                // Declare match box
   CBox cigar(8.0, 5.0,1.0);                 // Declare cigar box

   if(cigar.Compare(match))
      cout << endl
           << "match is smaller than cigar";
   else
      cout << endl
           << "match is equal to or larger than cigar";

   cout << endl;
   return 0;
}
