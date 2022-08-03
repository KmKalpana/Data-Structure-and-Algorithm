#include <iostream>
#include <vector>
#include <string>
using namespace std;
int maze(int r, int c)
{
  if(r==1 || c==1)
  {
      return 1;
  }
    int lh=maze(r-1,c);
    int rh=maze(r,c-1);
    return lh+rh;
}
int main()
{
       cout<<maze(3,3)<<endl;
}