// EX2_04.CPP
// Calculating how many rolls of wallpaper are required for a room
#include <iostream>

using namespace std;

int main()
{
   double height = 0.0, width = 0.0, length = 0.0; // Room dimensions
   double perimeter = 0.0;                         // Room perimeter

   const double rollwidth =21.0;          // Standard roll width
   const double rolllength = 12.*33.;     // Standard roll length(33ft.)

   int strips_per_roll = 0;               // Number of strips in a roll
   int strips_reqd = 0;                   // Number of strips needed
   int nrolls = 0;                        // Total number of rolls

   cout << endl                           // Start a new line
        << "Enter the height of the room in inches: ";
   cin >> height;

   cout  << endl                          // Start a new line
         << "Now enter the length and width in inches: ";
   cin >> length >> width;

   strips_per_roll = rolllength/height;   // Get number of strips in a roll
   perimeter = 2.0*(length + width);      // Calculate room perimeter
   strips_reqd = perimeter/rollwidth;     // Get total strips required
   nrolls = strips_reqd/strips_per_roll;  // Calculate number of rolls

   cout << endl
        << "For your room you need " << nrolls << " rolls of wallpaper."
        << endl;

   return 0;
}
