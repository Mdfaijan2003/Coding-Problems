/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,1]

Output: 1*/

#include <bits/stdc++.h>
using namespace std;
/*Intuition
1. Using a simple hashmap*/
int singleNumberHashMap(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;

  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }

  for (int i = 0; i < n; i++)
  {
    if (mpp[nums[i]] == 1)
    {
      return nums[i];
    }
  }

  return -1;
}
// 2. Using XOR operator
int singleNumber(vector<int> &nums)
{
  int n= nums.size();
  int num = 0;
  for(int i=0; i<n; i++){
    num = num ^ nums[i];
  }

  return num;
}
int main()
{
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << singleNumber(nums) << endl;

  return 0;
}