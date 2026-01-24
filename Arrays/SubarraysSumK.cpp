// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

#include <bits/stdc++.h>
using namespace std;
/*Intuition
Keep the track of prefix sum and check if (prefixSum -k) is present in the map if it is then count it. */
int subarraySum(vector<int> &arr, int k)
{
  int n = arr.size(); // size of the given array.
  unordered_map<int, int> mpp;
  int preSum = 0, cnt = 0;

  mpp[0] = 1; // Setting 0 in the map.
  for (int i = 0; i < n; i++)
  {
    // add current element to prefix Sum:
    preSum += arr[i];
    int remove = preSum - k;
    cnt += mpp[remove];
    mpp[preSum] += 1;
  }
  return cnt;
}

// Brute force
int subarraySumBrute(vector<int> &arr, int k)
{
  int sum = 0;
  int count = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      if (sum == k)
      {
        count++;
      }
    }
    sum = 0;
  }
  return count;
}

int main()
{
  vector<int> arr = {1, 1, 1};
  int k = 2;
  cout << subarraySum(arr, k) << endl;

  return 0;
}