/*3546. Equal Sum Grid Partition I

You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.



Example 1:

Input: grid = [[1,4],[2,3]]

Output: true*/

#include <bits/stdc++.h>
using namespace std;
// Intuition --> keep track of prefix rows , prefix cols and suffix rows and suffix cols
bool canPartitionGrid(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  vector<int> pre_rows(n, 0);
  vector<int> suf_rows(n, 0);
  vector<int> suf_cols(m, 0);
  vector<int> pre_cols(m, 0);

  // Prefix cal
  unsigned long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      sum += grid[i][j];
    }
    pre_rows[i] = sum;
  }
  // prefix cols cal
  sum = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum += grid[j][i];
    }
    pre_cols[i] = sum;
  }

  // suffix rows cal
  sum = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      sum += grid[i][j];
    }
    suf_rows[i] = sum;
  }
  // suffix cols cal
  sum = 0;
  for (int i = m - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      sum += grid[j][i];
    }
    suf_cols[i] = sum;
  }

  // checks for horizontal

  for (int i = 0; i < n - 1; i++)
  {
    if (pre_rows[i] == suf_rows[i + 1])
    {
      return true;
    }
  }

  for (int i = 0; i < m - 1; i++)
  {
    if (pre_cols[i] == suf_cols[i + 1])
    {
      return true;
    }
  }

  return false;
}

// Optimal approach --> same thing but removing suffix calculation as the total sum which is pre_rows[n -  1] is sufficient to check the condition given.
bool canPartitionGridOpt(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  vector<long long> pre_rows(n, 0);
  vector<long long> pre_cols(n, 0);

  // Prefix cal
  unsigned long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      sum += grid[i][j];
    }
    pre_rows[i] = sum;
  }
  // prefix cols cal
  sum = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum += grid[j][i];
    }
    pre_cols[i] = sum;
  }

  long long total = pre_rows[n - 1];

  // checks for horizontal

  for (int i = 0; i < n - 1; i++)
  {
    if (pre_rows[i] * 2 == total)
    {
      return true;
    }
  }

  for (int i = 0; i < m - 1; i++)
  {
    if (pre_cols[i] * 2 == total)
    {
      return true;
    }
  }

  return false;
}
int main()
{
  vector<vector<int>> grid = {
      {1, 2, 3},
      {3, 2, 1},
      {0, 0, 0}};

  cout << (canPartitionGridOpt(grid) ? "YES\n" : "NO\n");

  return 0;
}