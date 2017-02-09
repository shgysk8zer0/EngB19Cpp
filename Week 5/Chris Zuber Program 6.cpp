/*
  Chris Zuber
  Engr 19c/c++
  Program #6
  Program Descrition: This will calculate pi using various sequences
  Input : None
  Output: pi, calculated three different ways
*/

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
      int cnt (0);                       //a counter
const int term (50);                     //number of terms
   double pi_1,                          //first sequence
          pi_2,                          //second sequence
          pi_3,                          //third sequence
          toggle(1.0);                   //alternates values for +/-
  do      
  {
      pi_1+= toggle / (1.0 + 2.0 * cnt);
      pi_2+= 1.0 / (( 1.0 + 4.0 * cnt) * (3.0 + 4.0 * cnt));  
      toggle*= -1.0;
      cnt+= 1;
  } while (cnt < term);
  
  pi_1*= 4.0;
  pi_2*= 8.0;
  pi_3 = 24.0 * atan(0.125)+ 8.0 * atan(0.017543859649) + 4.0 
    * atan(0.004184100418);
  cout << " Using the first sequence, pi is equals " << cnt << pi_1 << endl
 << " Using the second sequence, pi is equals " << pi_2 << endl
 << " Using the third sequence, pi is equals " << pi_3 << endl << endl;
        
 system ("PAUSE");
 return 0;
}
