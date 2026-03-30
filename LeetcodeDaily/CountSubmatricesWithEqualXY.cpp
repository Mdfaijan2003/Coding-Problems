/*3212. Count Submatrices With Equal Frequency of X and Y
Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.


Example 1:
Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3
Explanation:

Example 2:
Input: grid = [["X","X"],["X","Y"]]

Output: 0
Explanation:
No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:
Input: grid = [[".","."],[".","."]]
Output: 0
Explanation:
No submatrix has at least one 'X'.

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.*/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubmatrices(vector<vector<char>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<pair<int, int>>> countGrid(n, vector<pair<int, int>>(m, {0, 0}));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int count_x = 0;
      int count_y = 0;

      if (grid[i][j] == 'X')
        count_x++;
      if (grid[i][j] == 'Y')
        count_y++;

      if (i > 0)
      {
        count_x += countGrid[i - 1][j].first;
        count_y += countGrid[i - 1][j].second;
      }

      if (j > 0)
      {
        count_x += countGrid[i][j - 1].first;
        count_y += countGrid[i][j - 1].second;
      }

      if (i > 0 && j > 0)
      {
        count_x -= countGrid[i - 1][j - 1].first;
        count_y -= countGrid[i - 1][j - 1].second;
      }

      countGrid[i][j] = {count_x, count_y};
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int x = countGrid[i][j].first;
      int y = countGrid[i][j].second;

      if (x > 0 && x == y)
        result++;
    }
  }

  return result;
}

// optimal approach --> removing reluctant code
int numberOfSubmatrices(vector<vector<char>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  int result = 0;

  vector<vector<pair<int, int>>> countGrid(n, vector<pair<int, int>>(m, {0, 0}));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int count_x = (i > 0 ? countGrid[i - 1][j].first : 0) +
                    (j > 0 ? countGrid[i][j - 1].first : 0) -
                    (i > 0 && j > 0 ? countGrid[i - 1][j - 1].first : 0);

      int count_y = (i > 0 ? countGrid[i - 1][j].second : 0) +
                    (j > 0 ? countGrid[i][j - 1].second : 0) -
                    (i > 0 && j > 0 ? countGrid[i - 1][j - 1].second : 0);

      if (grid[i][j] == 'X')
        count_x++;
      if (grid[i][j] == 'Y')
        count_y++;

      countGrid[i][j] = {count_x, count_y};

      if (count_x > 0 && count_x == count_y)
        result++;
    }
  }

  return result;
}

int main()
{
  vector<vector<char>> grid = {
      {'X', 'Y', '.'},
      {'Y', '.', '.'}};

  cout << numberOfSubmatrices(grid) << endl; // Output: 3

  return 0;
}