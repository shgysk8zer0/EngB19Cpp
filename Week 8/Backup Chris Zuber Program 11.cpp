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
    char code_1,          //The color codes
         code_2,          //The color codes
         code_3;          //The color codes
    double decoded_1,
           decoded_2,
           decoded_3,     // decoded      
           ohm;           // The calculated resistance
    
    cout << " Enter the capitalized letter to pick the associated color: \n ";
    print_codes ();
    cout << " Enter 3 colors by giving the capitalized letter. ";
    cin >> code_1 >> code_2 >> code_3;
    decoded_1 = decode(code_1);
    decoded_2 = decode (code_2);
    decoded_3 = decode (code_3);
    ohm =  (10.0 * decoded_1 + decoded_2)* pow (10.0, decoded_3);
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
double decode (char input)
{
   double output;
   switch (input)  
   {
          case 'S':
               output = -2.0;
               break;
          case 'G':
               output = -1.0;
               break;
          case 'B':
               output = 0.0;
               break;
          case 'N':
               output = 1.0;
               break;
          case 'R':
               output = 2.0;
               break;
          case 'O':
               output = 3.0;
               break;
          case 'Y':
               output = 4.0;
               break;
          case 'E':
               output = 5.0;
               break;
          case 'L':
               output = 6.0;
               break;
          case 'V':
               output = 7.0;
               break;
          case 'A':
               output = 8.0;
               break;
          case 'W':
               output = 9.0;
               break;
          default:
                  cerr <<"'"<<input << "' is not a valid selection \n ";
   }     
   return output;    
}
