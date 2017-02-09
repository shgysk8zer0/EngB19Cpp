/*
    Chris Zuber
    Engr b19 c/c++
    Program # 13
    Program Description: This program generates a deck of cards
    Input: none
    Output: suit and card values
*/        

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char suit (int);
char convert (int);

int main()
{
    int i(1),                           // accumulator for card array
        n (0),                          // another one for comparison
        card[52];                       // the deck of cards
     
    srand(time(NULL));
    card[0]= rand() % 52 + 1;    
    for (i; i < 52; i++)
        {
            card[i] = rand() % 52 + 1;
            for (n = 0; n < i ; n++)
                if (card[i]==card[n])
                   i--;
        }
    for (i = 0; i < 52; i++)
        { 
             cout << suit((card[i] - 1) / 13 + 3);
             convert(card[i] % 13 +1);
        }
    system ("pause");
    return 0;
}
    
/*
    Function Description - converts card value to suit
    Input : random number [3,6]
    Output : none
*/

char suit (int value)
{
     return (char)value;
}

/*
    Function Description - converts cards to  A, J, Q, or K
    Input : random number [1,13]
    Output : none
*/
char convert (int value)
{    
     switch (value)  
     {
           case 1:
               cout << "A" << endl;
               break;
           case 11:
               cout << "J" << endl;
               break;
           case 12:
               cout << "Q" << endl;
               break;
           case 13:
               cout << "K" << endl;
               break;
           default:
               cout << value << endl;
     }                           
}
