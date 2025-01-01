// EX10_04.CPP
// Using the protected access specifier
#include <iostream>              // For stream I/O
#include <cstring>               // For strlen() and strcpy()
using namespace std;

// Listing 10_04-01
class CBox
{
   public:
      // Base class constructor
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
                         m_Length(lv), m_Breadth(bv), m_Height(hv)
      {  cout << endl << "CBox constructor called";  }

      // CBox destructor - just to track calls
      ~CBox()
      { cout << "CBox destructor called" << endl; }

   protected:
      double m_Length;
      double m_Breadth;
      double m_Height;
};

class CCandyBox: public CBox
{
   public:
      char* m_Contents;

      // Derived class function to calculate volume
      double Volume() const
      { return m_Length*m_Breadth*m_Height; }

      // Constructor to set dimensions and contents
      // with explicit call of CBox constructor
      CCandyBox(double lv, double bv, double hv, char* str = "Candy")
                                          :CBox(lv, bv, hv)  // Constructor
      {
         cout << endl <<"CCandyBox constructor2 called";
         m_Contents = new char[ strlen(str) + 1 ];
         strcpy(m_Contents, str);
      }

      // Constructor to set contents
      // calls default CBox constructor automatically
      CCandyBox(char* str = "Candy")                         // Constructor
      {
         cout << endl << "CCandyBox constructor1 called";
         m_Contents = new char[ strlen(str) + 1 ];
         strcpy(m_Contents, str);
      }

      ~CCandyBox()                                           // Destructor
      {
         cout << "CCandyBox destructor called" << endl;
         delete[] m_Contents;
      }
};

int main()
{
   CCandyBox myCandyBox;
   CCandyBox myToffeeBox(2, 3, 4, "Stickjaw Toffee");

   cout << endl
        << "myCandyBox volume is " << myCandyBox.Volume()
        << endl
        << "myToffeeBox volume is " << myToffeeBox.Volume();

   // cout << endl << myToffeeBox.m_Length;      // Uncomment this for an error

   cout << endl;
   return 0;
}
