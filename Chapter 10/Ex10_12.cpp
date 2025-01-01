// EX10_12.CPP
// Destructor calls with derived classes
// using objects via a base class pointer
#include <iostream>                          // For stream I/O
using namespace std;

const double PI = 3.14159265;                // Global definition for PI

class CContainer                             // Generic base class for containers
{
   public:

      // Destructor
      ~CContainer()
      { cout << "CContainer destructor called" << endl; }

       // Function for calculating a volume - no content
      // This is defined as a 'pure' virtual function, signified by '= 0'
      virtual double Volume() const = 0;

      // Function to display a volume
      virtual void ShowVolume() const
      {
         cout << endl
              << "Volume is " << Volume();
      }

};

class CBox: public CContainer                // Derived class
{
   public:

      // Destructor
      ~CBox()
      { cout << "CBox destructor called" << endl; }

      // Function to calculate the volume of a CBox object
      virtual double Volume() const
      { return m_Length*m_Breadth*m_Height; }

      // Constructor
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
                             :m_Length(lv), m_Breadth(bv), m_Height(hv){}

   protected:
      double m_Length;
      double m_Breadth;
      double m_Height;

};

class CCan: public CContainer
{
   public:

      // Destructor
      ~CCan()
      { cout << "CCan destructor called" << endl; }

      // Function to calculate the volume of a can
      virtual double Volume() const
      { return 0.25*PI*m_Diameter*m_Diameter*m_Height; }

      // Constructor
      CCan(double hv = 4.0, double dv = 2.0): m_Height(hv), m_Diameter(dv){}

   protected:
      double m_Height;
      double m_Diameter;

};

class CGlassBox: public CBox                 // Derived class
{
   public:

      // Destructor
      ~CGlassBox()
      { cout << "CGlassBox destructor called" << endl; }

      // Function to calculate volume of a CGlassBox
      // allowing 15% for packing
      virtual double Volume() const
      { return 0.85*m_Length*m_Breadth*m_Height; }

      // Constructor
      CGlassBox(double lv, double bv, double hv): CBox(lv, bv, hv){}

};

int main()
{
   // Pointer to abstract base class initialized with CBox object address
   CContainer* pC1 = new CBox(2.0, 3.0, 4.0);

   CCan myCan(6.5, 3.0);                     // Define CCan object
   CGlassBox myGlassBox(2.0, 3.0, 4.0);      // Define CGlassBox object

   pC1->ShowVolume();                        // Output the volume of CBox
   cout << endl << "Delete CBox" << endl;
   delete pC1;                               // Now clean up the free store

   pC1 = new CGlassBox(4.0, 5.0, 6.0);       // Create CGlassBox dynamically
   pC1->ShowVolume();                        // ...output its volume...
   cout << endl << "Delete CGlassBox" << endl;
   delete pC1;                               // ...and delete it

   pC1 = &myCan;                             // Get myCan address in pointer
   pC1->ShowVolume();                        // Output the volume of CCan

   pC1 = &myGlassBox;                        // Get myGlassBox address in pointer
   pC1->ShowVolume();                        // Output the volume of CGlassBox

   cout << endl;
   return 0;
}
