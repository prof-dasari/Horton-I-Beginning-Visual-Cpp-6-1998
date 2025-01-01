// EX9_07.cpp
// Trying out a class template
#include <iostream>
using namespace std;

// Put the CBox class definition here

// CSamples class template definition 
template <class T> class CSamples 
{
   public:
      // Constructors
      CSamples(const T values[], int count);
      CSamples(const T& value);
      CSamples(){ m_Free = 0; }

      bool Add(const T& value);            // Insert a value
      T Max() const;                       // Calculate maximum

   private:
      T m_Values[100];                     // Array to store samples
      int m_Free;                          // Index of free location in m_Values
};

// Constructor template definition to accept an array of samples
template<class T> CSamples<T>::CSamples(const T values[], int count)
{
   m_Free = count < 100? count:100;  // Don't exceed the array
   for(int i = 0; i < m_Free; i++)
      m_Values[i] = values[i];       // Store count number of samples
}

// Constructor to accept a single sample
template<class T> CSamples<T>::CSamples(const T& value)
{
   m_Values[0] = value;              // Store the sample
   m_Free = 1;                       // Next is free
}

// Function to add a sample
template<class T> bool CSamples<T>::Add(const T& value)
{
   bool OK = m_Free < 100;            // Indicates there is a free place
   if(OK)
     m_Values[m_Free++] = value;    // OK true, so store the value
   return OK;
}

// Function to obtain maximum sample
template<class T> T CSamples<T>::Max() const
{
   T theMax = m_Free ? m_Values[0] : 0;   // Set first sample or 0 as maximum
   for(int i = 1; i < m_Free; i++)       // Check all the samples
     if(m_Values[i] > theMax)
        theMax = m_Values[i];             // Store any larger sample
    return theMax;
}

int main()
{
   CBox boxes[] = {                          // Create an array of boxes
                   CBox(8.0, 5.0, 2.0),      // Initialize the boxes...
                   CBox(5.0, 4.0, 6.0),
                   CBox(4.0, 3.0, 3.0)
                  };

   // Create the CSamples object to hold CBox objects
   CSamples<CBox> myBoxes(boxes, sizeof boxes / sizeof CBox);

   CBox maxBox = myBoxes.Max();              // Get the biggest box
   cout << endl                              // and output its volume
        << "The biggest box has a volume of "
        << maxBox.Volume()
        << endl;
   return 0;
}
