/*1727. Largest Submatrix With Rearrangements

You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

Example 1:


Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:


Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is either 0 or 1.*/

#include <bits/stdc++.h>
using namespace std;

// Pattern recognition --> No movement allowed only rearrangement hence we can apply histogram and 1D approach.
int largestSubmatrix(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> hist(n, vector<int>(m, 0));

  for (int i = 0; i < m; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (matrix[j][i] == 1)
      {
        count++;
      }
      else
      {
        count = 0;
      }
      hist[j][i] = count;
    }
  }

  // Find the max submatrix
  int maxMat = 0;
  for (int i = 0; i < n; i++)
  {
    sort(hist[i].begin(), hist[i].end(), greater<int>());

    for (int j = 0; j < m; j++)
    {
      int val = hist[i][j] * (j + 1);
      maxMat = max(maxMat, val);
    }
  }

  return maxMat;
}
int main()
{
  vector<vector<int>> matrix = {
      {0, 0, 1},
      {1, 1, 1},
      {1, 0, 1}};

  cout << largestSubmatrix(matrix);

  return 0;
}