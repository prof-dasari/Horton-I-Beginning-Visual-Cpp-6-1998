// EX10_03.CPP
// Calling a base constructor from a derived class constructor
#include <iostream>          // For stream I/O
#include <string>            // For strlen() and strcpy()
using namespace std;

class CBox
{
   public:

      //Function to calculate the volume of a CBox object
      double Volume(void)
      { return m_Length*m_Breadth*m_Height; }

      // Base class constructor
      CBox(double lv=1.0, double bv=1.0, double hv=1.0)
      {
         cout << endl << "CBox constructor called";
         m_Length = lv;
         m_Breadth = bv;
         m_Height = hv;
      }

   private:
      double m_Length;
      double m_Breadth;
      double m_Height;
};

class CCandyBox: public CBox
{
   public:
      char* m_Contents;

      // Constructor to set dimensions and contents
      // with explicit call of CBox constructor
      CCandyBox(double lv, double bv, double hv, char* str= "Candy")
                                                        :CBox(lv, bv, hv)
      {
          cout << endl <<"CCandyBox constructor2 called";
          m_Contents = new char[ strlen(str) + 1 ];
          strcpy(m_Contents, str);
      }

      // Constructor to set contents
      // calls default CBox constructor automatically
      CCandyBox(char* str= "Candy")
      {
         cout << endl << "CCandyBox constructor1 called";
         m_Contents = new char[ strlen(str) + 1 ];
         strcpy(m_Contents, str);
      }

      ~CCandyBox()                             // Destructor
      { delete[] m_Contents; }
};

int main(void)
{
   CBox myBox(4.0,3.0,2.0);
   CCandyBox myCandyBox;
   CCandyBox myMintBox(1.0,2.0,3.0,"Wafer Thin Mints");

   cout << endl
        << "myBox occupies " << sizeof  myBox  // Show how much memory
        << " bytes" << endl                    // the objects require
        << "myCandyBox occupies " << sizeof myCandyBox
        << " bytes" << endl
        << "myMintBox occupies " << sizeof myMintBox
        << " bytes";
   cout << endl
        << "myMintBox volume is "              // Get volume of a
        << myMintBox.Volume();                 // CCandyBox object
   cout << endl;
   return 0;
}
