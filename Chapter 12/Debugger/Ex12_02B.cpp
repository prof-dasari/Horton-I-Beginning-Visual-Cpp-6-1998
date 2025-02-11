// Ex12_02B.cpp : Completing the test operation

#include <iostream>
using namespace std;
#include "Name.h"
#include "crtdbg.h"

// Function to initialize an array of random names
void init(Name* names, int count)
{
  char* firstnames[] = { "Charles", "Mary", "Arthur", "Emily", "John"};
  int firstsize = sizeof (firstnames)/sizeof(firstnames[0]);
  char* secondnames[] = { "Dickens", "Shelley", "Miller", "Bronte", "Steinbeck"};
  int secondsize = sizeof (secondnames)/sizeof(secondnames[0]);
  char* first = firstnames[0];
  char* second = secondnames[0];

  for(int i = 0 ; i<count ; i++)
  {
    if(i%2)
      first = firstnames[i%firstsize];
    else
      second = secondnames[i%secondsize];

    names[i] = Name(first, second);
  }
}

int main(int argc, char* argv[])
{
  // Turn on free store debugging and leak-checking bits
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF|_CRTDBG_ALLOC_MEM_DF );
  
  // Direct warnings to stdout
  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);

  Name myName("Ivor", "Horton");                 // Try a single object

  // Retrieve and store the name in a local char array  
  char theName[12];
  cout << "\nThe name is " << myName.getName(theName);

  // Store the name in an array in the free store
  char* pName = new char[myName.getNameLength()+1]; 
  cout << "\nThe name is " << myName.getName(pName);

  const int arraysize = 10;
  Name names[arraysize];                          // Try an array

  // Initialize names
  init(names, arraysize);

// Try out comparisons
  char* phrase = 0;                               // Stores a comparison phrase
  char* iName = 0;                                // Stores a complete name  
  char* jName = 0;                                // Stores a complete name  

  for(int i = 0; i < arraysize ; i++)             // Compare each element
  {
    iName = new char[names[i].getNameLength()+1]; // Array to hold first name
    for(int j = i+1 ; j<arraysize ; j++)          // with all the others
    {
      if(names[i] < names[j])
        phrase = " less than ";
      else if(names[i] > names[j])
        phrase = " greater than ";
      else if(names[i] == names[j])      // Superfluous - but it calls the operator function
        phrase = " equal to ";
      jName = new char[names[j].getNameLength()+1]; // Array to hold second name
      cout << endl << names[i].getName(iName) << " is" << phrase 
			  << names[j].getName(jName);
		delete names[j].getName(jName)
	 }
  delete names[i].getName(iName)
  }

  delete [] pName;							 // these delete statements cure the memory leaks
													 // once and for all!
  cout << endl;
  return 0;
}
