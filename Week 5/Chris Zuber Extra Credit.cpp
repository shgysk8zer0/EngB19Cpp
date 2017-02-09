/*
  Chris Zuber
  Engr 19c/c++
  Program #6.1 (extra credit)
  Program Descrition: This will calculate pi using various sequences
  Input : sequence number and # terms
  Output: pi, calculated three different ways
*/

#include <iostream>
#include <cmath>

using namespace std;


int main ()
{
    int pick,                        //users choice
        term;                        //For n terms
 double pi(0),                       //sum, approximating pi
        cnt (0);                     //a counter
 
 cout << " Pick a method to calculate pi (1, 2, or 3) " << endl;
 cin >> pick;
 
 if (pick < 1 || pick  >3)
 {
    cerr << " Please enter a valid choice \n";
    system ("pause");
    exit (1);
 }
  
  if (pick == 1)
  {
     cout << " For how many terms? " << endl;
     cin >> term;
     
     for (cnt = 0; cnt < term; cnt++)
          pi+= pow(-1.0 , cnt) / (1.0 + 2.0 * cnt); 
     pi*= 4.0;
     cout << " Pi is equal to " << pi << endl << endl;
 }   
 else  if (pick == 2)
  {
     cout << " For how many terms? " << endl;
     cin >> term;
     
    for (cnt = 0; cnt < term; cnt++)
         pi+= 1.0 / ((1.0 + 4.0 * cnt ) * (3.0 + 4.0 * cnt)); 
      pi*= 8.0;
      cout << " Pi is equal to " << pi << endl << endl;
  }
else
  {
    pi= 24.0 * atan(0.125)+ 8.0 * atan(0.017543859649) + 4.0 
    * atan(0.004184100418);
    cout << " Pi is equal to " << pi << endl << endl << endl;
  }
     system ("PAUSE") ;
        return 0;
}
