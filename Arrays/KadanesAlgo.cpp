// Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Examples
// Example 1:
// Input:
//  nums = [2, 3, 5, -2, 7, -4]
// Output:
//  15
// Explanation:
//  The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.

#include <bits/stdc++.h>
using namespace std;
// Kadane's Algorithm
/*1. Move
2. Update sum
3. check if sum < 0 then sum = 0; (as we only carry positive sum)
4. Update max (if applicable)
5. get the answer*/
int maxSubArray(vector<int> &nums)
{
  int n = nums.size();
  int maxSum = INT_MIN;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += nums[i];
    if (sum < 0)
    {
      sum = 0;
    }
    if (sum > maxSum)
    {
      maxSum = sum;
    }
  }
  return maxSum;
}

// There is an follow-up question where the required answer is the subarray not just the sum. For that we can maintain the start and end indices of the subarray.
vector<int> maxSubArray(vector<int> &nums, int n)
{
  int maxSum = INT_MIN;
  int sum = 0;
  int ansStart = -1;
  int ansEnd = -1;
  int start = 0;
  for (int i = 0; i < n; i++)
  {
    if (sum == 0)
      start = i;
    sum += nums[i];
    if (sum < 0)
    {
      sum = 0;
    }
    if (sum > maxSum)
    {
      maxSum = sum;
      ansStart = start;
      ansEnd = i;
    }
  }
  return {ansStart, ansEnd};
}

int main()
{
  vector<int> nums = {2,3,5,-2,7,-4};
  cout<<maxSubArray(nums);

  return 0;
}