/*
    Chris Zuber
    Program # 12
    Engr b19 c/c++
    Program Description: This program has students opening/ closing lockers
    Input: None
    Output: A list of open lockers
*/

#include <iostream>
using namespace std;

int main()
{
    int student (0),      // counter for the wave of students
        nth (0);          // an accumulator for which lockers are opened/closed
    bool locker[100] ;    // the lockers (open/close)
    
    for (student = 0; student < 100; student++)
        locker[student]=false;  
    for (student = 0; student < 100; student++)
        {
           for (nth = student; nth < 100; nth += student + 1 )
               locker[nth] =! locker[nth];
           if (locker[student])
              cout << " Locker #" << student + 1 << " is open. " << endl;
        }
    system ("pause");
    return 0;
}
