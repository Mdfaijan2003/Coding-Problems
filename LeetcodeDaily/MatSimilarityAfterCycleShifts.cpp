/*2946. Matrix Similarity After Cyclic Shifts
Easy
Topics
premium lock icon
Companies
Hint
You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

The following proccess happens k times:

Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.


Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.


Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.



Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

Output: false

Explanation:

In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).



Example 2:

Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2

Output: true

Explanation:



Example 3:

Input: mat = [[2,2],[2,2]], k = 3

Output: true

Explanation:

As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.



Constraints:

1 <= mat.length <= 25
1 <= mat[i].length <= 25
1 <= mat[i][j] <= 25
1 <= k <= 50*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  /* 0 -> m - 1
     1 -> 2
     2 -> 1
     3 -> 4
     4 -> 3*/
  vector<int> leftShift(vector<int> &row, int k)
  {
    int n = row.size();
    vector<int> temp(n, 0);

    for (int i = 0; i < n; i++)
    {
      int ind = (i - k + n) & n;
      temp[ind] = row[i];
    }

    return temp;
  }
  vector<int> rightShift(vector<int> &row, int k)
  {
    int n = row.size();
    vector<int> temp(n, 0);

    for (int i = 0; i < n; i++)
    {
      int ind = (i - k + n) & n;
      temp[ind] = row[i];
    }

    return temp;
  }
  bool areSimilar(vector<vector<int>> &mat, int k)
  {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> similarMat = mat;

    for (int i = 0; i < n; i++)
    {

      similarMat[i] = (i % 2 == 0) ? leftShift[mat[i], k] : rightShift[mat[i], k];
    }
    if (similarMat == mat)
      return true;
    return false;
  }
};
int main()
{

  int n = 4;

  cout << (2 - 1 + n) % n << endl;
  cout << (1 + 1) % n;

  return 0;
}