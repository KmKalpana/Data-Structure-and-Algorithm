#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int r, int c, int n, vector<vector<int>>&m,vector<vector<int>>&vis)
    {
        if(r<n && r>=0 && c>=0 && c<n && m[r][c]==1 && vis[r][c]==0)
        {
            return true;
        }
        return false;
    }
    void helper(vector<vector<int>>&m, int n, string path, vector<vector<int>>&vis,int r, int c,vector<string>&ans)
    {
        if(r==n-1 && c==n-1)
        {
            ans.push_back(path);
            return ;
        }
        vis[r][c]=1;
        if(check(r-1,c,n,m,vis))
            {
               path.push_back('U');
               helper(m,n,path,vis,r-1,c,ans);
               path.pop_back();
            }
        if(check(r+1,c,n,m,vis))
        {
             path.push_back('D');
          helper(m,n,path,vis,r+1,c,ans); 
           path.pop_back();
        }
        if(check(r,c-1,n,m,vis))
        {
             path.push_back('L');
          helper(m,n,path,vis,r,c-1,ans);  
           path.pop_back();
        }
        if(check(r,c+1,n,m,vis))
        {
             path.push_back('R');
          helper(m,n,path,vis,r,c+1,ans); 
           path.pop_back();
        }
        vis[r][c]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string>ans;
      if(m[n-1][n-1]==0 || m[0][0]==0)
      {
          return ans;
      }
      vector<vector<int>>vis(n,vector<int>(n,0));
         string path="";
         helper(m,n,path,vis,0,0,ans);
      return ans;
    }
int main()
{
     int n=4;
    vector<vector<int>>m;
    m  ={{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}} ;
  vector<string>res=findPath(m,n);
  if(res.size()==0)
  {
      cout<<-1;
  }
  for(int i=0; i<res.size(); i++)
  {
      cout<<res[i]<<" ";
  }
}