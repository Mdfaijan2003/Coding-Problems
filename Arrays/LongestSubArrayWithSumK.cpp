/*Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15
Output:
 4
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
*/
#include <bits/stdc++.h>
using namespace std;
/*Intuition*/
// 1. Using 2 for loops (Brute Force) - O(n^2)
int longestSubarrayBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxLength = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (sum == k)
      {
        maxLength = max(maxLength, j - i + 1);
      }
      else if (sum > k)
      {
        break;
      }
    }
  }
  return maxLength;
}
// 2. Using two pointers - O(n)
int longestSubarray(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxLength = 0;
  int sum = 0;
  int i = 0;
  int j = i;
  while (i < n && j < n && i <= j)
  {
    sum += nums[j];
    while (sum > k && i <= j)
    {
      sum -= nums[i];
      i++;
    }
    if (sum == k)
    {
      maxLength = max(maxLength, j - i + 1);
    }
    j++;
  }
  return maxLength;
}

// If the Array has negative integer then we have to think differently.Now, we use hashmap to store the prefix sums at every index. if prefixSum - k is present in the map then we can update the maxLength.

int longestSubarrayWithNegatives(vector<int> &nums, int k)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  int prefixSum = 0;
  int maxLen = 0;
  for (int i = 0; i < n; i++)
  {
    prefixSum += nums[i];
    if (prefixSum == k)
    {
      maxLen = max(maxLen, i + 1);
    }
    else
    {
      int remove = prefixSum - k;
      if (mpp.find(remove) != mpp.end())
      {
        maxLen = max(maxLen, i - mpp[remove]);
      }
    }
    mpp[prefixSum] = i;
  }

  return maxLen;
}

int main()
{
  vector<int> nums = {1, -1, 5, -2, 3};
  int k = 3;
  cout << longestSubarrayWithNegatives(nums, k) << endl;

  return 0;
}