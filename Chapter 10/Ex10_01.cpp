// EX10_01.CPP
// Using a derived class
#include <iostream>                              // For stream I/O
#include <cstring>                               // For strlen() and strcpy()
using namespace std;

// Listing 10_01-01
class CBox
{
   public:
      double m_Length;
      double m_Breadth;
      double m_Height;

      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
       m_Length(lv), m_Breadth(bv), m_Height(hv){}
};

// Listing 10_01-02
class CCandyBox: CBox
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
   CBox myBox(4.0, 3.0, 2.0);                    // Create CBox object
   CCandyBox myCandyBox;
   CCandyBox myMintBox("Wafer Thin Mints");      // Create CCandyBox object

   cout << endl
        << "myBox occupies " << sizeof myBox     // Show how much memory
        << " bytes" << endl                      // the objects require
        << "myCandyBox occupies " << sizeof myCandyBox
        << " bytes" << endl
        << "myMintBox occupies " << sizeof myMintBox
        << " bytes";

   cout << endl
        << "myBox length is " << myBox.m_Length;

   myBox.m_Length = 10.0;

   // myCandyBox.m_Length = 10.0;                // uncomment this for an error

   cout << endl;
   return 0;
}
