/*1391. Check if There is a Valid Path in a Grid

You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.



Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6*/

#include <bits/stdc++.h>
using namespace std;
// Approach --> DFS. Back checking is required to ensure that the path is valid in both directions.
int n, m;
unordered_map<int, vector<vector<int>>> directions = {
    {1, {{0, -1}, {0, 1}}},
    {2, {{-1, 0}, {1, 0}}},
    {3, {{0, -1}, {1, 0}}},
    {4, {{0, 1}, {1, 0}}},
    {5, {{0, -1}, {-1, 0}}},
    {6, {{0, 1}, {-1, 0}}}};

bool check(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
{
  if (i == n - 1 && j == m - 1)
    return true;
  visited[i][j] = true;

  for (auto &dir : directions[grid[i][j]])
  {
    int ni = i + dir[0];
    int nj = j + dir[1];

    if (ni < 0 || nj < 0 || ni >= n || nj >= m || visited[ni][nj])
      continue;

    for (auto &back_dir : directions[grid[ni][nj]])
    {
      if (ni + back_dir[0] == i && nj + back_dir[1] == j)
      {
        if (check(grid, ni, nj, visited))
          return true;
      }
    }
  }

  return false;
}

bool hasValidPath(vector<vector<int>> &grid)
{
  n = grid.size();
  m = grid[0].size();

  vector<vector<bool>> visited(n, vector<bool>(m, false));
  return check(grid, 0, 0, visited);
}
int main()
{

  return 0;
}