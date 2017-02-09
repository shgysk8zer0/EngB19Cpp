/*      
        Chris Zuber
        Program Description: This translates characters to ascii values
        Input: character
        Output: ASCII translation
*/

#include <iostream>
using namespace std;

int main()
{
    int a;      // code to character
    char b;     // character to code & used to select conversion
    cout<<"Enter the number"<<endl;
    cin>>a;
    cout<<++a<<endl<<a++;
    
    while (!cin.eof())
    {
          cout << "Press ctrl+z to exit. " << endl;
          cout << "Enter '0' to convert from character to ASCII code. " << endl;
          cout << "Enter '1' to convert from ASCII code to character. " << endl;
          cin >> b;
               if (b == '0')
               {   
                  cout << "Enter a character to translate to ASCII.\n";
                  cin >> a;
                  cout << "\t\n" << a << " is " << (char) a << endl << endl;
               }
               else if (b == '1')
               {
                  cout << "Enter a character to translate to ASCII.\n";
                  cin >> b;
                  cout << "\n\t" << b << " is " << (int) b << endl << endl;
               }
               else
                   cout << "You must enter either '0' or '1'." << endl;
    }
    return 0;
}
