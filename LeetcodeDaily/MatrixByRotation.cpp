#include <bits/stdc++.h>
using namespace std;

// Intuition --> rotate by transposing the mat and then reverse each rows.
// Only 4 rotation is reasonable.
void rotate(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      mat[i][j] = mat[j][i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    reverse(mat[i].begin(), mat[i].end());
  }
}
bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{

  for (int i = 0; i < 4; i++)
  {
    if (mat == target)
      return true;
    rotate(mat);
  }

  return false;
}
int main()
{

  return 0;
}