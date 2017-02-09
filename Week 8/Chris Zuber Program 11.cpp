/*
    Chris Zuber
    Program # 11
    Engr b19 c/c++
    Program Description : This program returns the resistance in ohms
    Input : Three color codes
    Output : The calculated resistance
*/

#include <iostream>
#include <cmath>

using namespace std;
void print_codes ();
double decode (char);

int main()
{   int n;                // input counter  
    char code [3];        // The color codes
    double ohm,           // The calculated resistance
           decoded[3];    // decoded array  
    
    cout << " Enter the capitalized letter to pick the associated color: \n ";
    print_codes ();
    cout << " Enter three colors by giving the capitalized letter. ";
    for (n = 0; n < 3; n++)
        cin >> code [n];
    for (n = 0; n < 3; n++)
        decoded [n] = decode (code [n]);
    ohm =  (10.0 * decoded[0] + decoded[1])* pow (10.0, decoded[2]);
    cout << " The resistance is " << ohm << " ohms " <<endl <<endl ;
    
    system ("PAUSE");
    return 0;
}

/*
    Function Description - Prints color codes
    Input : none
    Output : chart of color codes
*/
void print_codes ()
{
     cout <<" Color \t Code \t Color \t  Code \n S_ilver \t -2 \t Y_ellow \t 4";
     cout << " \n G_old   \t -1 \t gr_E_en \t 5 \n B_lack \t 0 \t b_L_ue \t 6 ";
     cout << " \n brow_N \t 1 \t V_iolet \t 7 \n R_ed    \t 2 \t gr_A_y \t 8 ";
     cout << " \n O_range \t 3 \t W_hite \t 9 " << endl << endl;
}

/*
     Function Description - Decodes color codes
     Input : char color codes
     Output : resistance
*/
double decode (char coded)
{
   double decoded;
   
   switch (coded)  
   {
          case 'S':
               decoded = -2.0;
               break;
          case 'G':
               decoded = -1.0;
               break;
          case 'B':
               decoded = 0.0;
               break;
          case 'N':
               decoded = 1.0;
               break;
          case 'R':
               decoded = 2.0;
               break;
          case 'O':
               decoded = 3.0;
               break;
          case 'Y':
               decoded = 4.0;
               break;
          case 'E':
               decoded = 5.0;
               break;
          case 'L':
               decoded = 6.0;
               break;
          case 'V':
               decoded = 7.0;
               break;
          case 'A':
               decoded = 8.0;
               break;
          case 'W':
               decoded = 9.0;
               break;
          default:
                  cerr <<"'"<< coded << "' is not a valid selection \n ";
                  system ("PAUSE") ;
                  exit (1) ;
   }     
   return decoded;    
}
