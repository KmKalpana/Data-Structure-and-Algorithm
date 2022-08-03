#include <iostream>
#include <vector>
#include <string>
using namespace std;
void maze(string s, int r, int c, bool board)
{
  if(r==1 && c==1)
  {
      cout<<s<<endl;
  }
   if(r>1)
    maze(s+'d',r-1,c,board);
    if(c>1)
    maze(s+'r',r,c-1,board);
    return ;
}
int main()
{
    bool board[3][3]={{true,true,true},
    {true,true,true},
    {true,true,true} };
    maze("",3,3,board);
}