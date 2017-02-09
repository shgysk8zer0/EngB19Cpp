/*
  Chris Zuber
  Engr 19c/c++
  Program#7
  Program Description : This program estimates using Euler's method
  Input : None
  Output : A table of i, x, y, and the error.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
     int i(0);           // iteration
  double x_new,          // new estimate for x value
         x_old (1.0),    // previous value for x
         y_new,          // new estimate for y value
         y_old (1.0),    // previous y value
         h (0.1),        // step size
         y_true;         // the actual value
  cout << " i \t x \t y " << endl ;
 do
 {
  x_new = x_old + h;
  y_new = y_old + h * ( x_old + 3.0 * y_old / x_old);
  cout << i << "\t " << x_old << "\t " << y_old << endl ;
  i++;
  x_old = x_new;
  y_old = y_new;
 }while (x_new <=2);
  
 y_true = pow(x_old,3.0) * 2.0 - (x_old * x_old) ;
 cout << i << "\t " << x_old << "\t " << y_old << endl ;
 cout << endl << " Exact - Approximate = " << y_true - y_new << endl << endl ;
 system ("PAUSE");
 return 0;
}
