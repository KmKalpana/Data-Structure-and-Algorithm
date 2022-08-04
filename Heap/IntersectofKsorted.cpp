/*Was asked this in a phone screen. How do you find the intersection of k sorted arrays. I think interviewer was expecting a heap answer ( similar to union of k sorted arrays using iterators given in EPI ) but I can't really tell if heap is possible or if he was expecting something else. I couldn't solve it. What is the best way to solve this without running a loop around each array.

INPUT: [[1,3,5,7], [1,1,3,5,7],[1,4,7,9], [1,7],[1,2,3,7]]
OUTPUT: [1,7]
*/
#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
    vector<vector<int>> arr{
                           {1,3,5,7},
                           {1,1,3,5,7},
                           {1,4,7,9},
                           {1,7},
                           {1,2,3,7}};
   vector<int>ans;
  set<int>mp(arr[0].begin(),arr[0].end());
  for(int i=1; i<arr.size(); i++)
  {
      vector<int>res;
      for(int j=0; j<arr[1].size(); j++)
      {
          if(mp.count(arr[i][j]))
          {
             res.push_back(arr[i][j]);
          }
      }
      mp.clear();
      for(int i=0; i<res.size(); i++)
      {
          mp.insert(res[i]);
      }
  }
  for(auto it: mp)
  {
      cout<<it<<" ";
  }
}