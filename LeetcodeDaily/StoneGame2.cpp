/*1140. Stone Game II
Solved
Medium

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104



Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104*/

#include <bits/stdc++.h>
using namespace std;

int n;
int dp[2][101][101];
int solve(vector<int> &piles, int person, int idx, int M)
{
  if (idx >= n)
    return 0;

  if (dp[person][idx][M] != -1)
    return dp[person][idx][M];

  int result = (person == 1) ? -1 : INT_MAX;
  int stones = 0;

  for (int x = 1; x <= min(2 * M, n - idx); x++)
  {
    stones += piles[idx + x - 1];
    if (person == 1)
    {
      result = max(result, stones + solve(piles, 0, idx + x, max(M, x)));
    }
    else
    {
      result = min(result, solve(piles, 1, idx + x, max(M, x)));
    }
  }

  return dp[person][idx][M] = result;
}
int stoneGameII(vector<int> &piles)
{
  n = piles.size();
  memset(dp, -1, sizeof(dp));
  return solve(piles, 1, 0, 1);
}
int main()
{

  return 0;
}