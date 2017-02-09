/*
  Chris Zuber
  Engr 19c/c++
  Program #2
  Program Description: This program calculates the force of tension on a pulley.
  Input:  Two masses in kilograms  
  Output: the force of tension calculated by t=(2gm1*m2)/(m1*m2)
*/
  
#include <iostream>

using namespace std;

int main()

{
    double m1,                //the first mass
           m2,                //the second mass
           tension,           //calculated tension
           total;             //total mass
  const double gravity=9.81;  //2 times the gravitational constant
    
    cout << " Enter the two masses in kilograms, seperated by spaces: ";
    cin >> m1>>m2 ;
    
    total=m1+m2;
    tension=2*gravity*m1*m2/total;
        
    cout <<endl<<" The tension is "<<tension<< " Newtons."<<endl<<endl;
    
    system ("PAUSE") ;
    return 0;
}
