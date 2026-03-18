/*3070. Count Submatrices with Top-Left Element and Sum Less Than k

You are given a 0-indexed integer matrix grid and an integer k.
Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

Example 1:

Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.*/

#include <bits/stdc++.h>
using namespace std;

// Approach --> go to every index and use the prefix sum.
int countSubmatrices(vector<vector<int>> &grid, int k)
{
  int n = grid.size();
  int m = grid[0].size();

  // i-1, j-1, 0,0
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i - 1 >= 0)
        grid[i][j] += grid[i - 1][j];
      if (j - 1 >= 0)
        grid[i][j] += grid[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0)
        grid[i][j] += grid[i - 1][j - 1];

      if (grid[i][j] <= k)
        count++;
    }
  }

  return count;
}

int main()
{

  return 0;
}