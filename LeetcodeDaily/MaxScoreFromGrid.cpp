/*3225. Maximum Score From Grid Operations

You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.

The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.

Return the maximum score that can be achieved after some number of operations.

Example 1:

Input: grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]

Output: 11

Explanation:


In the first operation, we color all cells in column 1 down to row 3, and in the second operation, we color all cells in column 4 down to the last row. The score of the resulting grid is grid[3][0] + grid[1][2] + grid[3][3] which is equal to 11.

Example 2:

Input: grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]

Output: 94

Explanation:


We perform operations on 1, 2, and 3 down to rows 1, 4, and 0, respectively. The score of the resulting grid is grid[0][0] + grid[1][0] + grid[2][1] + grid[4][1] + grid[1][3] + grid[2][3] + grid[3][3] + grid[4][3] + grid[0][4] which is equal to 94.


Constraints:

1 <= n == grid.length <= 100
n == grid[i].length
0 <= grid[i][j] <= 109*/

#include <bits/stdc++.h>
using namespace std;

// First intuitive approach --- Incorrect.
// long long maximumScore(vector<vector<int>> &grid)
// {
//   int n = grid.size();

//   vector<int> marked(n, -1);
//   vector<int> unmarked(n, -1);

//   for (int col = 1; col < n; col++)
//   {
//     for (int row = 0; row < n; row++)
//     {
//       if (marked[col] >= row || marked[col - 1] >= row)
//         continue;
//       if (grid[row][col] < grid[row][col - 1])
//       {
//         if (unmarked[col] == -1)
//         {
//           marked[col] = max(marked[col], row);
//           unmarked[col - 1] = max(unmarked[col - 1], row);
//         }
//       }
//       if (grid[row][col] > grid[row][col])
//       {
//         if (unmarked[col - 1] == -1)
//         {
//           marked[col - 1] = max(marked[col - 1], row);
//           unmarked[col] = max(unmarked[col], row);
//         }
//       }
//     }
//   }

//   // Calculate the adjacent value
//   vector<vector<bool>> visited(n, vector<bool>(n, false));
//   long long ans = 0;
//   for (int i = 0; i < n; i++)
//   { // col
//     for (int j = 0; j <= marked[i]; j++)
//     { // row
//       if (i - 1 >= 0 && marked[i - 1] < j && !visited[j][i - 1])
//       {
//         ans += grid[j][i - 1];
//         visited[j][i - 1] = true;
//       }
//       if (i + 1 < n && marked[i + 1] < j && !visited[j][i + 1])
//       {
//         ans += grid[j][i + 1];
//         visited[j][i + 1] = true;
//       }
//     }
//   }

//   return ans;
// }

// Optimal Approach --> Using DP

typedef long long ll;

int n;
ll t[2][101][101];

ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>> &grid, vector<vector<ll>> &colPrefixSum)
{
  if (col == n)
    return 0;
  if (t[prevTaken][prevHeight][col] != -1)
    return t[prevTaken][prevHeight][col];

  ll ans = 0;
  for (int height = 0; height < n; height++)
  {
    ll prevColCum = 0;
    ll currColSum = 0;
    if (!prevTaken && height > prevHeight)
    {
      prevColCum += colPrefixSum[height][col] + colPrefixSum[prevHeight][col];
    }
    if (prevHeight > height)
    {
      currColSum += colPrefixSum[prevHeight][col + 1] - colPrefixSum[height][col + 1];
    }

    ll currScoreTaken = prevColCum + currColSum + solve(true, height, col + 1, grid, colPrefixSum);
    ll currScoreNotTaken = solve(false, prevHeight, col + 1, grid, colPrefixSum);

    ans = max(ans, max(currScoreTaken, currScoreNotTaken));
  }
  return t[prevTaken][prevHeight][col] = ans;
}
long long maximumScore(vector<vector<int>> &grid)
{
  n = grid.size();

  // Precompute ColPrefix Sum ---> Cumulated sum of each column
  vector<vector<ll>> colPrefixSum(n + 1, vector<ll>(n + 1, 0));
  for (int col = 1; col < n; col++)
  {
    for (int row = 1; row < n; row++)
    {
      colPrefixSum[row][col] = colPrefixSum[row - 1][col] + grid[row - 1][col - 1];
    }
  }

  return solve(false, 0, 0, grid, colPrefixSum);
}
int main()
{

  return 0;
}