/*
  Chris Zuber
  Engr 19c/c++
  Program #8
  Program Description : The program calculates altitude as a function of time
  Input : None
  Output : .txt file containing a table of t (1-50) and alt
*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main ()
{
 ofstream out ("out.txt");      // file to store data in   
   double t (0.0),              // Time in hours
          alt;                  // Altitude in meters
 
 if (out.fail())
 {
    cerr << " Failed to open output file\n " ;
    system ("PAUSE") ;
    exit (1) ;
 }
 
 do
 {
 alt= -0.12 * pow(t,4.0) + 12.0 * pow(t,3.0) - 380.0 * t*t + 4100.0 * t + 220.0;
 out << t << "\t" << alt << endl;
 t+= 1.0;
 }while (t <= 50.0);
 
 system ("PAUSE");
 return 0;
}
