/*1861. Rotating the Box

You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.



Example 1:



Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:



Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:



Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]


Constraints:

m == boxGrid.length
n == boxGrid[i].length
1 <= m, n <= 500
boxGrid[i][j] is either '#', '*', or '.'.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<char> transform(vector<char> &arr)
  {

    int n = arr.size();

    int empty = n - 1;

    // move from right to left
    for (int j = n - 1; j >= 0; j--)
    {

      if (arr[j] == '*')
      {
        empty = j - 1;
      }

      else if (arr[j] == '#')
      {

        swap(arr[j], arr[empty]);
        empty--;
      }
    }

    return arr;
  }

  vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
  {

    int n = boxGrid.size();
    int m = boxGrid[0].size();

    // transformed grid
    vector<vector<char>> temp(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
      temp[i] = transform(boxGrid[i]);
    }

    // rotate matrix
    vector<vector<char>> ans(m, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {

        ans[j][n - 1 - i] = temp[i][j];
      }
    }

    return ans;
  }
};
int main()
{

  return 0;
}