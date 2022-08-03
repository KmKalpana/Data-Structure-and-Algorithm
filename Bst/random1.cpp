/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int n=4;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
         cout<<' ';    
        }
        for(int k=n-1-i; k<n; k++)
        {
            cout<<'*';
        }
        cout<<endl;
    }

    return 0;
}
