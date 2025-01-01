// EX10_02.CPP
// Using a function inherited from a base class
#include <iostream>              // For stream I/O
#include <cstring>               // For strlen() and strcpy()
using namespace std;

class CBox
{
   public:
       CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
       m_Length(lv), m_Breadth(bv), m_Height(hv){}

      //Function to calculate the volume of a CBox object
      double Volume() const
      { return m_Length*m_Breadth*m_Height; }

private:
      double m_Length;
      double m_Breadth;
      double m_Height;
};

class CCandyBox: public CBox
{
   public:
      char* m_Contents;

      CCandyBox(char* str = "Candy")             // Constructor
      {
         m_Contents = new char[ strlen(str) + 1 ];
         strcpy(m_Contents, str);
      }

      ~CCandyBox()                               // Destructor
      { delete[] m_Contents; };
};


int main()
{
   CBox myBox(4.0,3.0,2.0);                              // Create CBox object
   CCandyBox myCandyBox;
   CCandyBox myMintBox("Wafer Thin Mints");              // Create CCandyBox object

   cout << endl
        << "myBox occupies " << sizeof  myBox            // Show how much memory
        << " bytes" << endl                              // the objects require
        << "myCandyBox occupies " << sizeof myCandyBox
        << " bytes" << endl
        << "myMintBox occupies " << sizeof myMintBox    
        << " bytes";
   cout << endl                                 
        << "myMintBox volume is " << myMintBox.Volume(); // Get volume of a 
                                                         // CCandyBox object  
   cout << endl;
   return 0;
}
