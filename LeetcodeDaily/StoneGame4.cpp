/*1510. Stone Game IV
Solved
Hard
Topics

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.



Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).


Constraints:

1 <= n <= 105*/

/*Solution --> This solve check whether Alice can win or not.
Alice can win only if Bob looses.
So after every step this function checks whether Bob looses or not.*/

#include <bits/stdc++.h>

using namespace std;

int dp[100001];
bool solve(int piles)
{ // Check can Alice win?
  if (piles == 0)
    return false;
  if (dp[piles] != -1)
    return dp[piles];

  for (long long x = 1; x * x <= piles; x++)
  {
    long long square = x * x;

    if (!solve(piles - square))
      return dp[piles] = true;
  }

  return dp[piles] = false;
}
bool winnerSquareGame(int n)
{
  int piles = n;
  memset(dp, -1, sizeof(dp));
  return solve(piles);
}

int main()
{

  return 0;
}