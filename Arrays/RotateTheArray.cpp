/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]*/
#include <bits/stdc++.h>
using namespace std;
// We have more than 1 way to solve this efficiently.
// 1. Using temp array.
// 2. Rotating one element for k times (inefficient for large k).
// 3. Using reversal algorithm.
void rotate(vector<int> &nums, int k)
{
  int n = nums.size();
  k = k % n;

  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
  reverse(nums.begin(), nums.end());
}
int main()
{

  return 0;
}