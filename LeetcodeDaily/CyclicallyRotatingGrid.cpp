/*
1914. Cyclically Rotating a Grid

You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:



A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


Return the matrix after applying k cyclic rotations to it.



Example 1:


Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.
Example 2:


Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.


Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109*/

// O(n*m) time complexity and O(n*m) space complexity
// Break the grid into layers and rotate each layer separately
vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
{
  int n = grid.size();
  int m = grid[0].size();
  int layers = min(n, m) / 2;

  for (int layer = 0; layer < layers; layer++)
  {
    int top = layer;
    int left = layer;
    int right = m - layer - 1;
    int bottom = n - layer - 1;

    vector<int> arr;
    // Top row
    for (int i = left; i <= right; i++)
    {
      arr.push_back(grid[top][i]);
    }

    // Right column
    for (int i = top + 1; i <= bottom - 1; i++)
    {
      arr.push_back(grid[i][right]);
    }

    // Bottom row
    for (int i = right; i >= left; i--)
    {
      arr.push_back(grid[bottom][i]);
    }

    // Left column
    for (int i = bottom - 1; i >= top + 1; i--)
    {
      arr.push_back(grid[i][left]);
    }

    int len = arr.size();
    if (len > 0)
    {
      int nor_k = k % len;

      // Counter-clockwise rotation
      rotate(arr.begin(), arr.begin() + nor_k, arr.end());

      int idx = 0;

      // Fill back top row
      for (int i = left; i <= right; i++)
      {
        grid[top][i] = arr[idx++];
      }

      // Fill back right column
      for (int i = top + 1; i <= bottom - 1; i++)
      {
        grid[i][right] = arr[idx++];
      }

      // Fill back bottom row
      for (int i = right; i >= left; i--)
      {
        grid[bottom][i] = arr[idx++];
      }

      // Fill back left column
      for (int i = bottom - 1; i >= top + 1; i--)
      {
        grid[i][left] = arr[idx++];
      }
    }
  }
  return grid;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{

  return 0;
}