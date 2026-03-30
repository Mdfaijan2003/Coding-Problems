/*1878. Get Biggest Three Rhombus Sums in a Grid

You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.



Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211*/

#include <bits/stdc++.h>
using namespace std;

long long largest = 0;
long long slargest = 0;
long long sslargest = 0;

void update(int val)
{
  if (val > largest)
  {
    sslargest = slargest;
    slargest = largest;
    largest = val;
  }
  else if (val > slargest && val != largest)
  {
    sslargest = slargest;
    slargest = val;
  }
  else if (val > sslargest && val != slargest && val != largest)
  {
    sslargest = val;
  }
}

int findRhombus(int i, int j, vector<vector<int>> &grid, int n, int m)
{
  if (i + 2 >= n || j - 1 < 0 || j + 1 >= m)
    return grid[i][j];

  int val = grid[i][j];
  val += grid[i + 1][j - 1];
  val += grid[i + 1][j + 1];
  val += grid[i + 2][j];

  return val;
}

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  largest = slargest = sslargest = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      if (i + 2 < n && j - 1 >= 0 && j + 1 < m)
      {
        update(findRhombus(i, j, grid, n, m));
      }
      else
      {
        update(grid[i][j]);
      }
    }
  }

  vector<int> ans;
  set<int> uniqueValues;

  if (largest > 0)
    uniqueValues.insert(largest);
  if (slargest > 0)
    uniqueValues.insert(slargest);
  if (sslargest > 0)
    uniqueValues.insert(sslargest);

  for (auto it = uniqueValues.rbegin(); it != uniqueValues.rend(); ++it)
  {
    ans.push_back(*it);
    if (ans.size() == 3)
      break;
  }

  return ans;
}

class Solution
{
public:
  vector<int> getBiggestThree(vector<vector<int>> &grid)
  {

    int m = grid.size(), n = grid[0].size();

    // left to right diagonals prefix
    vector<vector<int>> d1(m, vector<int>(n));

    // right to left diagonals prefix
    vector<vector<int>> d2(m, vector<int>(n));

    // building d1
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        d1[i][j] = grid[i][j];
        if (i > 0 && j > 0)
          d1[i][j] += d1[i - 1][j - 1];
      }
    }

    // building d2
    for (int i = 0; i < m; i++)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        d2[i][j] = grid[i][j];
        if (i > 0 && j + 1 < n)
          d2[i][j] += d2[i - 1][j + 1];
      }
    }

    set<int> st;

    auto addToSet = [&](int val)
    {
      st.insert(val);
      if (st.size() > 3)
        st.erase(st.begin());
    };

    for (int r = 0; r < m; r++)
    {
      for (int c = 0; c < n; c++)
      {

        // rhombus with side = 0
        addToSet(grid[r][c]);

        for (int side = 1; r - side >= 0 && r + side < m && c - side >= 0 && c + side < n; side++)
        {
          int sum = 0;

          int top_r = r - side, top_c = c;
          int right_r = r, right_c = c + side;
          int bottom_r = r + side, bottom_c = c;
          int left_r = r, left_c = c - side;

          // top to right corner
          sum += d1[right_r][right_c];
          if (top_r - 1 >= 0 && top_c - 1 >= 0)
            sum -= d1[top_r - 1][top_c - 1];

          // right to bottom corner
          sum += d2[bottom_r][bottom_c];
          if (right_r - 1 >= 0 && right_c + 1 < n)
            sum -= d2[right_r - 1][right_c + 1];

          // bottom to left corner
          sum += d1[bottom_r][bottom_c];
          if (left_r - 1 >= 0 && left_c - 1 >= 0)
            sum -= d1[left_r - 1][left_c - 1];

          // left to top corner
          sum += d2[left_r][left_c];
          if (top_r - 1 >= 0 && top_c + 1 < n)
            sum -= d2[top_r - 1][top_c + 1];

          // remove corners counted twice
          sum -= grid[top_r][top_c];
          sum -= grid[right_r][right_c];
          sum -= grid[bottom_r][bottom_c];
          sum -= grid[left_r][left_c];

          addToSet(sum);
        }
      }
    }

    return vector<int>(st.rbegin(), st.rend());
  }
};
int main()
{
  vector<vector<int>> grid = {
      {20, 17, 9, 13, 5, 2, 9, 1, 5}, {14, 9, 9, 9, 16, 18, 3, 4, 12}, {18, 15, 10, 20, 19, 20, 15, 12, 11}, {19, 16, 19, 18, 8, 13, 15, 14, 11}, {4, 19, 5, 2, 19, 17, 7, 2, 2}};
  vector<int> ans = getBiggestThree(grid);
  for (auto it : ans)
  {
    cout << it << ' ';
  }

  return 0;
}