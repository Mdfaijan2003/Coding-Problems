/*657. Robot Return to Origin

There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.

Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.



Example 1:

Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.*/

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n) where n is the length of the moves string
// Space complexity: O(1) as we are using only a constant amount of space
// Using Coordinate Geometry: We can keep track of the robot's position using two variables, x and y. We can iterate through the moves string and update the x and y coordinates based on the move. For example, if the move is 'R', we can increment x by 1, if it's 'L', we can decrement x by 1, if it's 'U', we can increment y by 1, and if it's 'D', we can decrement y by 1. After processing all the moves, we can check if the robot is back at the origin (0, 0) by checking if x and y are both equal to 0.

bool judgeCircle(string moves)
{
  int x = 0, y = 0;
  int n = moves.size();

  for (int i = 0; i < n; i++)
  {
    if (moves[i] == 'U')
      y++;
    else if (moves[i] == 'D')
      y--;
    else if (moves[i] == 'R')
      x++;
    else if (moves[i] == 'L')
      x--;
  }

  if (x == 0 & y == 0)
    return true;

  return false;
}

int main()
{

  return 0;
}