/*
  Chris Zuber
  Engr 19c/c++
  Program #4
  Program Description: This program calculates the volume of liquid.
  Input: Depth, "R" and radius 
  Output: Volume
*/
  
#include <iostream>
#include <cmath>

using namespace std;

int main()

{
    
    double dep,     //the depth
           rad,     //the radius 
           R,       //depth of cone?
           vol;     //The volume
    const double pi=acos(-1.0);
    
    cout <<" Please enter the radius in meters :";
    cin  >> rad;
    cout << " Please enter the depth in meters :";
    cin  >> dep;
    cout << " What is the height in meters to the top of the cone? ";
    cin  >> R;
    
    if (dep>3.0*R)
       cout << " Overtop. " << endl;
    else if (R>dep)
{
       rad*=dep/R;
       rad*=rad*pi;
       vol=rad*dep/3.0;
       cout <<" Volume equals; " << vol << endl << endl;
}
    else
{
       rad*=rad*pi;
       vol=rad*(dep-2.0*R/3.0);
       cout << " The volume is " << vol << " cubic meters." << endl << endl;
}
    system ("PAUSE") ;

    return 0;
}
