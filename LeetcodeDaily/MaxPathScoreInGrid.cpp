/*

3742. Maximum Path Score in a Grid

You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

Each cell contributes a specific score and incurs an associated cost, according to their cell values:

0: adds 0 to your score and costs 0.
1: adds 1 to your score and costs 1.
2: adds 2 to your score and costs 1. ​​​​​​​
Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

Note: If you reach the last cell but the total cost exceeds k, the path is invalid.



Example 1:

Input: grid = [[0, 1],[2, 0]], k = 1

Output: 2

Explanation:​​​​​​​

The optimal path is:

Cell	grid[i][j]	Score	Total
Score	Cost	Total
Cost
(0, 0)	0	0	0	0	0
(1, 0)	2	2	2	1	1
(1, 1)	0	0	2	0	1
Thus, the maximum possible score is 2.

Example 2:

Input: grid = [[0, 1],[1, 2]], k = 1

Output: -1

Explanation:

There is no path that reaches cell (1, 1)​​​​​​​ without exceeding cost k. Thus, the answer is -1.



Constraints:

1 <= m, n <= 200
0 <= k <= 103​​​​​​​
​​​​​​​grid[0][0] == 0
0 <= grid[i][j] <= 2*/

#include <bits/stdc++.h>
using namespace std;
int n;
int m;

// Approach --> Recursion with Backtracking

int calCost(int i, int j, vector<vector<int>> &grid)
{
  int el = grid[i][j];
  int cost = 0;
  switch (el)
  {
  case 0:
    cost = 0;
    break;
  case 1:
    cost = 1;
    break;
  case 2:
    cost = 1;
    break;
  default:
    cost = 0;
    break;
  }
  return cost;
}

int solve(int i, int j, int cost, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp)
{
  if (i == n - 1 && j == m - 1)
    return grid[i][j];

  if (dp[i][j][cost] != -1)
    return dp[i][j][cost];

  int right_score = INT_MIN;
  int down_score = INT_MIN;

  if (i + 1 > n)
  {
    int newCost = cost + calCost(i + 1, j, grid);
    if (newCost <= k)
      right_score = grid[i][j] + solve(i + 1, j, newCost, grid, k, dp);
  }

  if (j + 1 > m)
  {
    int newCost = cost + calCost(i, j + 1, grid);
    if (newCost <= k)
      down_score = grid[i][j] + solve(i, j + 1, newCost, grid, k, dp);
  }

  return dp[i][j][cost] = max(right_score, down_score);
}
int maxPathScore(vector<vector<int>> &grid, int k)
{
  n = grid.size();
  m = grid[0].size();

  int startCost = calCost(0, 0, grid);
  if (startCost > k)
    return -1;
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));

  int ans = solve(0, 0, startCost, grid, k, dp);

  return ans < 0 ? -1 : ans;
}
int main()
{

  return 0;
}