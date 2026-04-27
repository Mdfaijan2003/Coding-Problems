/*1559. Detect Cycles in 2D Grid

Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.


Example 1:

Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:

Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:

Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid consists only of lowercase English letters.*/

// Approach: Check for cycle using DFS. If we encounter a visited node, then there is a cycle. We also need to check if the adjacent nodes are same as current node and also we need to check if the adjacent node is not the parent node of current node.
#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, int parent_i, int parent_j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
  int n = grid.size();
  int m = grid[0].size();

  visited[i][j] = true;

  int dir[4][2] = {{-1, 0}, {1, 0}, {0. - 1}, {0, 1}};

  for (auto &it : dir)
  {
    int ni = i + it[0];
    int nj = j + it[1];

    if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == grid[i][j])
    {
      if (dfs(ni, nj, i, j, grid, visited))
        return true;
      else if (ni != parent_i && nj != parent_j)
        return true;
    }
  }
  return false;
}
bool containsCycle(vector<vector<char>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j])
      {
        if (dfs(i, j, -1, -1, grid, visited))
          return true;
      }
    }
  }

  return false;
}
int main()
{

  return 0;
}