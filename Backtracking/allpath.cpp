#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++11 ratmaze.cpp
void maze(string s, int r, int c, vector<vector<bool>> &board, int path[3][3], int step)
{
  if(r==board.size()-1 && c==board[0].size()-1)
  {
      path[r][c]=step;
      for(int i=0; i<3; i++)
      {
        for(int j=0; j<3; j++)
        {
           cout<<path[i][j]<<" ";
        }
        cout<<endl;
      }
      cout<<s<<endl;
      return ;
  }
    if(!board[r][c])
    {
    return ;
    }

    board[r][c]=false;
    path[r][c]=step;
   if(r<board.size()-1)
   {
    maze(s+'D',r+1,c,board,path,step+1);
   }
    if(c<board[0].size()-1)
    {
    maze(s+'R',r,c+1,board,path,step+1);
    }
    if(r>0)
   {
    maze(s+'U',r-1,c,board,path,step+1);
   }
    if(c>0)
    {
    maze(s+'L',r,c-1,board,path,step+1);
    }
    board[r][c]=true;
    path[r][c]=0;
    return ;
}
int main()
{
     vector<vector<bool>> board={
    {true,true,true},
    {true,true,true},
    {true,true,true} 
     };
     int path[3][3]={{1,0,0},
     {0,0,0},
     {0,0,0}
     };
   maze("",0,0,board,path,1);
    
}