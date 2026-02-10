/*3719. Longest Balanced Subarray I

You are given an integer array nums.

A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.

*/

#include <bits/stdc++.h>
using namespace std;
int longestBalanced(vector<int> &nums)
{
  int n = nums.size();
  if (n < 2)
    return 0;

  int maxWindow = 0;

  for (int i = 0; i < n; i++)
  {
    unordered_set<int> even, odd;

    for (int j = i; j < n; j++)
    {
      if (nums[j] % 2 == 0)
      {
        even.insert(nums[i]);
      }
      else
      {
        odd.insert(nums[i]);
      }

      if (even.size() == odd.size())
      {
        maxWindow = max(maxWindow, j - i + 1);
      }

      if (j - i + 1 + (n - j - 1) <= maxWindow)
        break;
    }
  }

  return maxWindow;
}
int main()
{
  vector<int> nums = {2, 4, 3, 3, 5};
  cout << longestBalanced(nums);
  return 0;
}