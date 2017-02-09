/*
      Chris Zuber
      Engr 19c/c++
      Program #10
      Program Description : This program calculates pi by a choice of methods
      Input : Choice of sequence and the number of terms
      Output : pi
*/

#include <iostream>
#include <cmath>

using namespace std;
 
double method_1(int);
double method_2(int);
double method_3 ();

int main ()
{     
       int term ;     // Number of times to run through program
       char method;   // Choice of method to usee to estimate pi

      
       cout << " Which method would you like to use? 1, 2, or 3? ";
       cin >> method;
       switch (method)
       {     
          case '1':
               cout << " For how many terms? ";
               cin >> term;
               cout << " \n \t Pi equals " << method_1 (term);
               break;
          case '2':
               cout << " For how many terms? ";
               cin >> term;
               cout << " \n \t Pi equals " << method_2 (term);
               break;
          case '3':
               cout << " \n \t Pi equals " << method_3 ();
               break;
          default:
               cerr << method << " is not a valid option. \n" ;
               system ("PAUSE") ;
               exit (1) ;
        }
    
        system ("PAUSE");
        return 0;
}

/*
  Function Description - Calculates pi by method 1
  Input : terms
  Output : Pi
*/
double method_1 (int term)
{
       double pi;
       int n;
       for (n = 0; n < term; n++)
          pi+= pow(-1.0 ,(double) n) / (1.0 + 2.0 * (double) n);
       pi*= 4.0;
       return pi;
} 

/*
       Function Description - Calculates pi by method 2
       Input : terms
       Output : Pi
*/
double method_2 (int term)
{
       double pi;    
       int n;
       for ( n= 0 ; n < term; n++)
          pi+= 1.0 / ((1.0 + 4.0 * (double) n ) * (3.0 + 4.0 * (double) n));         
       pi*= 8.0;
       return pi;
} 

/*
      Function Description - Calculates pi by method 3
      Input : terms
      Output : Pi
*/
double method_3 ()
{
       double pi;
       pi= 24.0 * atan(1.0/8.0)+ 8.0 * atan(1.0/57.0) + 4.0 * atan(1.0 / 239.0);
       return pi;
}
