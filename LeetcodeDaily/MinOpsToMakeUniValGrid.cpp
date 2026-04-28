#include <bits/stdc++.h>
using namespace std;

/*2033. Minimum Operations to Make a Uni-Value Grid

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.


Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following:
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.*/

int minOperations(vector<vector<int>> &grid, int x)
{
  vector<int> flattenGrid;

  // Flatten the grid into a 1D vector for easier processing
  for (auto &row : grid)
  {
    for (auto &val : row)
    {
      flattenGrid.push_back(val);
    }
  }

  // Check if it's possible to make all elements equal
  int modValue = flattenGrid[0] % x;
  for (auto &val : flattenGrid)
  {
    if (val % x != modValue)
    {
      return -1; // If any element has a different remainder, it's impossible
    }
  }

  // Sort the flattened grid to find the median
  sort(flattenGrid.begin(), flattenGrid.end());
  int len = flattenGrid.size();
  int median = flattenGrid[len / 2];

  // Calculate the total operations needed to make all elements equal to the median
  int ops = 0;
  for (auto &val : flattenGrid)
  {
    ops += abs(val - median) / x;
  }

  return ops;
}
int main()
{

  return 0;
}