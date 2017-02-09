/*
  Chris Zuber
  Engr 19c/c++
  Program #9
  Program Description : prints 2011 {shamrock} to screen in '*'
  Input : None
  Output : graphics {2011 *shamrock*}
*/

#include <iostream>

using namespace std;
void prn_0 ();
void prn_1 ();
void prn_2 ();
void prn_sr ();

int main()
{
 prn_2 ();
 prn_0 ();
 prn_1 ();
 prn_1 ();
 prn_sr ();
 
 system ("PAUSE");
 return 0;
}

/*
  Function Description - Prints '0' in *'s.
  Input : None
  Output : Graphics
*/
void prn_0 ()
{
       cout << "\n     * * * \n   *       * \n *           * " << endl;
       cout << "   *       * \n     * * * \n " << endl;
}

/*
  Function Description - Prints '1' in *'s.
  Input : None
  Output : Graphics
*/
void prn_1 ()
{
       cout << " \n *          * \n * * * * * * * \n * \n " << endl;
}

/*
  Function Description - Prints '2' in *'s.
  Input : None
  Output : Graphics
*/
void prn_2 ()
{
       cout << " \n * *      * \n *         * \n *   *     * " << endl;
       cout << " *    * * * \n " << endl;
}

/*
  Function Description - Prints a shamrock in *'s.
  Input : None
  Output : Graphics
*/
void prn_sr()
{
       cout << "  **  ** \n  *** ***  *** \n    ***   *****  \n ********** ";
       cout << " \n    ***   ***** \n  *** ***  ***   \n  **  ** " << endl;
}
