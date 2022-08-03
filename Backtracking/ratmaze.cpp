#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++11 ratmaze.cpp
void maze(string s, int r, int c, vector<vector<bool>> board)
{
  if(r==board.size()-1 && c==board[0].size()-1)
  {
      cout<<s<<endl;
  }
    if(board[r][c]==false)
     return ;
   if(r<board.size()-1)
   {
    maze(s+'d',r+1,c,board);
   }
    if(c<board[0].size()-1)
    {
    maze(s+'r',r,c+1,board);
    }
    return ;
}
int main()
{
     vector<vector<bool>> board={
    {true,false,true},
    {true,false,true},
    {true,true,true} 
     };
   maze("",0,0,board);
    
}