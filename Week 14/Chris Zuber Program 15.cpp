/*
    Chris Zuber
    Program # 15
    Engr b19 c/c++
    Program Description: This program finds the sums of the products of an array
    Input: Array size and data
    Output: The sum of the products of the array
*/

#include <iostream>

using namespace std;

int manip(int*, int*, int);

int main()
{
    int x[50],
        y[50],
        i(0),
        size;
    const int max = 50;
        
    while (1)        
    {
           cout << "Enter the number of data points." << endl;
           cin >> size;
           if (size > max)
              cout << "Please enter a max size less than 50." << endl;
           else
               break;
    }
    
    cout << "Enter the X data:\n";
    for (i = 0; i < size; i++)
        cin >> *(x + i);
        
    cout << "Enter the Y data:\n";
    for (i = 0; i < size; i++)
        cin >> *(y + i);    

    cout <<  "The sum of their products is: " << manip (x, y, size) << endl;
    
    system ("pause");
    return 0;
}
 
/*
  Function Description- This finds the sum and product
  Input: Two arrays and size
  Output: The sum of the products
 */
     
int manip(int* a, int* b, int size)
{
    int n(0),
        sum(0);
        
    for (n = 0; n < size; n++)
        *(a + n) *= *(b + n);
    for (n = 0; n  < size ;n++)
        sum += *a++;
    return sum;
}
