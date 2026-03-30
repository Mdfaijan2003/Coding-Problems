/*3548. Equal Sum Grid Partition II
Hard
Topics
premium lock icon
Companies
Hint
You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
If a cell is discounted, the rest of the section must remain connected.
Return true if such a partition exists; otherwise, return false.

Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.



Example 1:

Input: grid = [[1,4],[2,3]]

Output: true

Explanation:



A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
Example 2:

Input: grid = [[1,2],[3,4]]

Output: true

Explanation:



A vertical cut after the first column gives sums 1 + 3 = 4 and 2 + 4 = 6.
By discounting 2 from the right section (6 - 2 = 4), both sections have equal sums and remain connected. Thus, the answer is true.
Example 3:

Input: grid = [[1,2,4],[2,3,5]]

Output: false

Explanation:



A horizontal cut after the first row gives 1 + 2 + 4 = 7 and 2 + 3 + 5 = 10.
By discounting 3 from the bottom section (10 - 3 = 7), both sections have equal sums, but they do not remain connected as it splits the bottom section into two parts ([2] and [5]). Thus, the answer is false.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll total = 0;

bool checkHorCuts(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  unordered_set<ll> st;
  ll top = 0;

  for (int i = 0; i <= m - 2; i++)
  {

    for (int j = 0; j < n; j++)
    {
      st.insert(grid[i][j]);
      top += grid[i][j];
    }

    ll bottom = (total - top);
    ll diff = top - bottom;

    if (diff == 0)
      return true;

    if (diff == (ll)grid[0][0])
      return true;
    if (diff == (ll)grid[0][n - 1])
      return true;
    if (diff == (ll)grid[i][0])
      return true;

    if (i > 0 && n > 1 && st.count(diff))
    {
      return true;
    }
  }

  return false;
}
bool canPartitionGrid(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      total += grid[i][j];
    }
  }
  if (checkHorCuts(grid))
  {
    return true;
  }

  reverse(begin(grid), end(grid));

  if (checkHorCuts(grid))
  {
    return true;
  }

  reverse(begin(grid), end(grid));

  vector<vector<int>> transposeGrid(n, vector<int>(m));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      transposeGrid[j][i] = grid[i][j];
    }
  }

  if (checkHorCuts(transposeGrid))
  {
    return true;
  }
  reverse(begin(transposeGrid), end(transposeGrid));

  if (checkHorCuts(transposeGrid))
  {
    return true;
  }

  return false;
}

int main()
{

  return 0;
}