/*  LeetCode
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12 */
class Solution {
public:
    int minimum(int a, int b)
    {
        return a<b?a:b;
    }
    int minPathSum(vector<vector<int>>& grid)
    {
     int n=grid.size();
      int m=grid[0].size();
      int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=INT_MAX;
        }
        for(int j=1; j<=m; j++)
        {
            dp[0][j]=INT_MAX;
        }
        dp[1][0]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i==1 && j==1)
            {
               dp[i][j]=dp[i][j-1]+grid[i-1][j-1];
            }
            else 
            {
                dp[i][j]=grid[i-1][j-1]+minimum(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
       return dp[n][m];
    }
};
