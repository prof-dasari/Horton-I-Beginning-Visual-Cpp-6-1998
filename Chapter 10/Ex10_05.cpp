// EX10_05.CPP
// Using a derived class copy constructor
#include <iostream>              // For stream I/O
#include <cstring>               // For strlen() and strcpy()
using namespace std;

// Listing 10_05-01
class CBox                   // Base class definition
{
   public:
      // Base class constructor
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
                         m_Length(lv), m_Breadth(bv), m_Height(hv)
      {  cout << endl << "CBox constructor called";  }

      // Copy constructor
      CBox(const CBox& initB)
      {
         cout << endl << "CBox copy constructor called";
         m_Length = initB.m_Length;
         m_Breadth = initB.m_Breadth;
         m_Height = initB.m_Height;
      }

      // CBox destructor - just to track calls
      ~CBox()
      { cout << "CBox destructor called" << endl; }

   protected:
      double m_Length;
      double m_Breadth;
      double m_Height;
};

// Listing 10_05-02
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
                                         :CBox(lv, bv, hv)   // Constructor
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
   CCandyBox chocBox(2.0, 3.0, 4.0, "Chockies");     // Declare and initialize
   CCandyBox chocolateBox(chocBox);                  // Use copy constructor

   cout << endl
        << "Volume of chocBox is " << chocBox.Volume()
        << endl
        << "Volume of chocolateBox is " << chocolateBox.Volume()
        << endl;

   return 0;
}
