/*
    Chris Zuber
    Program # 14
    Engr b19 c/c++
    Program Description: This program has adds and averages odd numbers
    Input: Y/N for continue
    Output: The average
*/

#include <iostream>
#include <vector>
#include <ctype.h>
#include <ctime>

using namespace std;

double avg(int[], int);

int main()
{
     int store,
         vect[100];
     vector<int> odd;
     char cont;
     double average;
    
     srand(time(NULL));
     while (1)
     {
           cout << "Would you like to add another random odd number? " << endl;
           cin >> cont;
           if (toupper(cont)=='N')
                break;
           else if (toupper(cont)=='Y')
           {
				while (1)
				{	
                    store = rand();
                    if (store %2)
                    {
                        odd.insert(odd.end(), store);
                        break;
                    }
				}
			}
            else
                cout << "Please enter Y or N. " << endl;
     }
     for(store = 0; store < odd.size(); store++)
           vect[store] = odd[store];
     average = avg(vect, odd.size());
     cout << "The average is " << average << endl;
     system ("pause");
     return 0;
}       
       
/*
    Function Description - find the average of numbers
    Input : odd numbers
    Output : the average  
*/
double avg (int odd[], int size)
{
       int i,
           sum(0);
       cout <<"The numbers are: "<<endl;
       for (i=0; i < size; i++)
           {
                 sum+= odd[i];
                 cout << odd[i] << endl;
           }
       return (double)sum/(double)size;
}
