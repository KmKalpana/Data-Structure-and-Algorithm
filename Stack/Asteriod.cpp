#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//When asteroids collide, the resultant fragments are ejected with velocities that are small compared to the orbital velocity of the original asteroid. 
/*We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.*/
 vector<int> asteroidCollision(vector<int>& ast) 
 {
  vector<int>res;
  for(int i=0; i<ast.size(); i++)
  {
      if(res.empty() || ast[i]>0)
      {
          res.push_back(ast[i]);
      }
      else 
      {
          while(!res.empty() && res.back()>0 && res.back()<abs(ast[i]))
          {
              res.pop_back();
          }
          if(!res.empty() && res.back()+ast[i]==0)
          {
              res.pop_back();
          }
          else if(res.empty() || res.back()<0 )
          {
              res.push_back(ast[i]);
          }
      }
  }
   return res;
}
int main()
{
    vector<int>v{-10,10,20,-20};
    vector<int>ans=asteroidCollision(v);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}