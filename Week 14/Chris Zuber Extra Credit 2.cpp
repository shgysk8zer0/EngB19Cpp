/*
    Chris Zuber
    Program # Extra Credit 2
    Engr b19 c/c++
    Program Description: Finds edges of a monochrome image
    Input: Array size and data
    Output: The sum of the products of the array
*/

#include <iostream>

using namespace std;

int main()
{
    bool image [50][50],   // user entered image
         edge [50][50];    // edge of image
    int x,                 // width
        y,                 // height
        i,                 // increment for height
        k,                 // increment for width
        n,                 // intermediate
        u (0),            // pixel above
        l (0),            // pixel to left
        r (0),            // pixel to right
        d (0);            // pixel below
    
    cout << "Enter the horizontal size: \t" << endl;
         cin >> x;
    cout << "Enter the vertical size: \t" << endl;
         cin >> y;
    for (n = 0; n <= x + 1; n++)
    {
        image [n][0]= 0;
        image [n][y+1]=0;
    }
    for (i = 0; i <= y + 1; i++)
    {
        image [0][i] = 0;
        image [x+1][i] = 0;
    }   
    cout << "Enter the image: " << endl;
    for (i = 1; i <= y; i++)
        for (n = 1; n <= x; n++)
            cin >> image[n][i];
     for (i = 1; i <= y+1; i++)
         for (n = 1; n <= x+1; n++)
         {
             if (image [n][i])
             {
                u = image [n][i-1];
                d = image [n][i+1];
                l = image [n-1][i];
                r = image [n+1][i];
                if (u && d && l && r)
                    edge [n][i] = 0;
                else edge [n][i] = 1;
             }
         }
      cout << "\n " << "The edges are:" << endl;
      for (i = 1; i <= y; i++)
        for (n = 1; n <= x; n++)
            if (n==1)
               cout << endl << edge[n][i] << " "; 
            else   
               cout << edge[n][i] << " ";    
                       
    cout << endl;    
    system ("pause");
    return 0;
}
 
