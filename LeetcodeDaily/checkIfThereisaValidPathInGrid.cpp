/**/

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