/*
  Chris Zuber
  Engr 19c/c++
  Program # 5
  Program Description: This program tests whether a point set is at the orign,
  on an axis, or which quadrant they are in.
  Input: (X,Y)
  Output: Quadrant or axis
*/
  
#include <iostream>

using namespace std;

int main()
{
    double X,             //the value of x
           Y,             //the value of y
           quad (1.0);    //the quadrant, initialized as 1

 cout << " Enter the points (X,Y), separated by a space. ";
 cin  >> X >> Y;
  
 if (X==0.0 && Y==0.0)
    cout << " The point (0,0) is the origin. " << endl;
    
 else if (X==0.0)
    cout << " The point (0," << Y << ") is on the Y-axis. " << endl;
 else if (Y==0.0)
    cout << " The point (" << X << ",0) is on the X-axis. " << endl;
 else
{
     quad+=(X/Y<0.0)+2.0*(Y<0.0);
     cout << " The point (" << X << "," << Y << ") is in quadrant " << quad
     << endl << endl;
}
 
 system ("PAUSE") ;
 return 0;
}
