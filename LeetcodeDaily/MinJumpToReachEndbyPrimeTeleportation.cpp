/*3629. Minimum Jumps to Reach End via Prime Teleportation

You are given an integer array nums of length n.

You start at index 0, and your goal is to reach index n - 1.

From any index i, you may perform one of the following operations:

Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
Return the minimum number of jumps required to reach index n - 1.



Example 1:

Input: nums = [1,2,4,6]

Output: 2

Explanation:

One optimal sequence of jumps is:

Start at index i = 0. Take an adjacent step to index 1.
At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
Thus, the answer is 2.

Example 2:

Input: nums = [2,3,4,7,9]

Output: 2

Explanation:

One optimal sequence of jumps is:

Start at index i = 0. Take an adjacent step to index i = 1.
At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.
Thus, the answer is 2.

Example 3:

Input: nums = [4,6,5,8]

Output: 3

Explanation:

Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.


Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 106*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int maxVal)
{
  vector<bool> prime(maxVal + 1, true);

  prime[0] = prime[1] = false;

  for (int i = 2; i * i <= maxVal; i++)
  {
    if (prime[i])
    {
      for (int j = i * i; j <= maxVal; j += i)
      {
        prime[j] = false;
      }
    }
  }

  return prime;
}

vector<int> getPrimeFactors(int x)
{
  vector<int> factors;

  for (int p = 2; p * p <= x; p++)
  {
    if (x % p == 0)
    {
      factors.push_back(p);

      while (x % p == 0)
        x /= p;
    }
  }

  if (x > 1)
    factors.push_back(x);

  return factors;
}

int minJumps(vector<int> &nums)
{

  int n = nums.size();

  if (n == 1)
    return 0;

  int mx = *max_element(nums.begin(), nums.end());

  vector<bool> isPrime = sieve(mx);

  // prime -> all indices divisible by prime
  unordered_map<int, vector<int>> mp;

  for (int i = 0; i < n; i++)
  {

    vector<int> factors = getPrimeFactors(nums[i]);

    for (int p : factors)
    {
      mp[p].push_back(i);
    }
  }

  queue<int> q;
  vector<int> dist(n, -1);

  q.push(0);
  dist[0] = 0;

  // To avoid reusing same prime teleport many times
  unordered_set<int> usedPrime;

  while (!q.empty())
  {

    int i = q.front();
    q.pop();

    int steps = dist[i];

    if (i == n - 1)
      return steps;

    // Adjacent left
    if (i - 1 >= 0 && dist[i - 1] == -1)
    {
      dist[i - 1] = steps + 1;
      q.push(i - 1);
    }

    // Adjacent right
    if (i + 1 < n && dist[i + 1] == -1)
    {
      dist[i + 1] = steps + 1;
      q.push(i + 1);
    }

    // Prime teleportation
    if (isPrime[nums[i]])
    {

      int p = nums[i];

      if (!usedPrime.count(p))
      {

        usedPrime.insert(p);

        for (int idx : mp[p])
        {

          if (dist[idx] == -1)
          {

            dist[idx] = steps + 1;
            q.push(idx);
          }
        }
      }
    }
  }

  return -1;
}

int main()
{

  return 0;
}