/*
  Program Description: This will generate a list of all 4 character
  combinations of upper and lower case letters and numbers.
  The point is to show how easy it is to crack a simple code
*/
//include this section to expand
/*
  {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                   'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                   '1','2','3','4','5','6','7','8','9','0'},
*/  
  
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;
 int main()
 {
     ofstream out ("out.txt"); 
     int size(27),
         u,
         v,
         w,
         x,
         y,
         z;
     char a[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},
          b[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},
          c[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},      
          d[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},
          e[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},
          f[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},
          choice;
      /*
      if (out.fail())
      {
         cerr << " Failed to open output file\n " ;
         system ("PAUSE") ;
         exit (1) ;
      }
      cout << "include lower case? Y/N? " <<endl;
      cin >> choice;
      if (toupper(choice)=='Y')
         size+=26;
      cout << "include upper case? Y/N? " <<endl;
      cin >> choice;
      if (toupper(choice)=='Y')
         size+=26;
      cout << "include numbers? Y/N? " <<endl;
      cin >> choice;
      if (toupper(choice)=='Y')
         size+=10;
      */
      for (u=0;u<size;u++)
         for (v=0;v<size;v++)    
             for (w=0;w<size;w++)
                 for (x=0;x<size;x++)
                    out <<a[u]<<b[v]<<c[w]<<d[x]<<endl;
                    /* for (y=0;y<size;y++)
                         for (z=0;z<size;z++)
                             out <<a[u]<<b[v]<<c[w]<<d[x]<<e[y]<<f[z]<<endl;*/
     system ("pause");
     return 0;
}
