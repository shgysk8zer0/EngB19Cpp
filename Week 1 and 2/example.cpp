/*
  Chris Zuber
  Engr 19c/c++
  Example #1
  Program Description: This program converts hours to minutes 
  and seconds
  Input:  Hours
  Output: Minutes and seconds
*/
  
#include <iostream>

using namespace std;

int main()
{
    int hours,      //input hours
        minutes,    //hours converted to minutes
        seconds;    //hours converted to seconds
       
    cout << "Input the number of hours: ";
    cin >> hours;
    
    minutes=hours*60;
    seconds=minutes*60;
    
    cout <<endl << hours << " hours is equivalent to " << minutes 
    << " minutes and " << seconds << " seconds" << endl << endl;
    
    system ("PAUSE") ;
    return 0;
}
