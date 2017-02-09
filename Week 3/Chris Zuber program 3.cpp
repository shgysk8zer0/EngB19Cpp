/*
  Chris Zuber
  Engr 19c/c++
  Program #3
  Program Description: 
  Input: Data from two points and a flight path angle between those two points
  Output: coefficient of lift
*/
  
#include <iostream>
#include <cmath>
using namespace std;

int main()

{
    double f_p1,                 //first flight path
           c_l1,                 //first coefficient of lift
           f_p2,                 //second flight path
           c_l2,                 //second coefficient of lift
           angle,                //the calculated angle
           lift;                 //coefficient of lift in question
  const double pi=acos (-1);
 
   
    cout <<"Enter values sepereated by spaces.\n";
    cout <<" Enter the first flight path and coefficient of lift: ";
    cin  >>f_p1>>c_l1;
    cout <<" Enter the second flight path and coefficient of lift: ";
    cin  >>f_p2>>c_l2;
    cout <<" For what coefficient of lift? ";
    cin  >>lift;
    
    f_p2-=f_p1;   
    c_l2-=c_l1;
    lift-=c_l1;
    lift*=f_p2/c_l2;
    angle=f_p1+lift;
    angle*=pi/180;
   
    cout <<"The angle is "<<angle<<" radians."<<endl<<endl;
    system ("PAUSE") ;

    return 0;
}
