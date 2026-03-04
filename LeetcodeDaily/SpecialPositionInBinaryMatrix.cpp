/*Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).



Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.*/
#include <bits/stdc++.h>
using namespace std;
bool checker(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &vis, int i, int j)
{
  vis[i][j] = 1;
  int k = 0;
  while (k < n)
  {
    vis[i][k] = 1;
    if (mat[i][k] == 1 && k != j)
    {
      return false;
    }
    k++;
  }

  k = 0;
  while (k < m)
  {
    vis[k][j] = 1;
    if (mat[k][j] == 1 && k != i)
    {
      return false;
    }
    k++;
  }

  return true;
}
int numSpecialBrute(vector<vector<int>> &mat)
{
  int m = mat.size();
  int n = mat[0].size();
  vector<vector<int>> vis(m, vector<int>(n, 0));
  int cnt = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mat[i][j] == 1 && !vis[i][j])
      {
        if (checker(m, n, mat, vis, i, j))
          cnt++;
      }
    }
  }
  return cnt;
}
int numSpecial(vector<vector<int>> &mat)
{
  int m = mat.size();
  int n = mat[0].size();
  vector<int> row(m, 0);
  vector<int> col(n, 0);
  int cnt = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mat[i][j] == 1)
      {
        row[i]++;
        col[j]++;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
        cnt++;
    }
  }

  return cnt;
}
int main()
{
  vector<vector<int>> mat = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  cout << numSpecial(mat) << endl;

  return 0;
}