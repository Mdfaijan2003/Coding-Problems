/*Leetcode 3634: You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element is at most k times the minimum element.

You may remove any number of elements from nums​​​​​​​ without making it empty.

Return the minimum number of elements to remove so that the remaining array is balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.



Example 1:

Input: nums = [2,1,5], k = 2

Output: 1

Explanation:

Remove nums[2] = 5 to get nums = [2, 1].
Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.*/

#include <bits/stdc++.h>
using namespace std;
bool remove(int start, int end, int k, vector<int> &nums)
{
  if (nums[end] <= nums[start] * k)
  {
    return true;
  }

  return false;
}

int dfs(int start, int end, int k, int count, vector<int> &nums)
{
  bool condn = (nums[end] <= nums[start] * k);
  if (condn)
  {
    return count;
  }
  //  check removing max element
  if (remove(start, end - 1, k, nums))
  {
    count++;
    return count;
  }
  //  check removing min element
  if (remove(start + 1, end, k, nums))
  {
    count++;
    return count;
  }
  // remove both max & min element
  if (remove(start + 1, end - 1, k, nums))
  {
    count += 2;
    return count;
  }

  count += 2;
  // reduce the array and do the same
  return dfs(start + 1, end - 1, k, count, nums);
}
int minRemovalFirstIntuition(vector<int> &nums, int k)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int count = 0;

  count = dfs(0, n - 1, k, count, nums);
  return count;
}
// Sliding window Approach
int minRemoval(vector<int> &nums, int k)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());

  int i = 0;
  int j = 0;
  int maxWindow = 1;
  while (i < n)
  {
    while (j < n && nums[j] <= nums[i] * k)
    {
      j++;
    }
    maxWindow = max(maxWindow, j - i);
    i++;
  }

  return n - maxWindow;
}

int main()
{
  vector<int> nums = {51, 70, 9, 21}; // 9 21 51 70
  cout << minRemoval(nums, 2);
  return 0;
}