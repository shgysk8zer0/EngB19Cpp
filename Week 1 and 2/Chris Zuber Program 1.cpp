/*
  Chris Zuber
  Engr 19c/c++
  Program #1
  Program Description: This program calculates water savings per day in
  liters, compared between two toilets.
  Input:  number of toilets
  Output: savings in liters/day and cost to install new toilets.
*/
  
#include <iostream>

using namespace std;

int main()
{
    int toilets,    //input toilets.
        savings,    //difference between old and new in liters.
        cost;       //cost to install new toilets
       
    cout << "Input the number of toilets: ";
    cin >> toilets;
    
    savings=182*toilets;
    cost=150*toilets;
    
    cout <<endl <<"With "<< toilets << " toilets, you would save " << savings 
    << " liters of water per day." <<endl << "The installation would cost $"
    << cost <<endl << endl;
    
    system ("PAUSE") ;
    return 0;
}
