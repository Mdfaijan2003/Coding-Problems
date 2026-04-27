/*Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

Examples
Input: Arr[] = {1,3,2}
Output: {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
Input : Arr[] = {3,2,1}
Output: {1,2,3}
Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the lowest permutation.*/
#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach: Generate all the permutation, sort them and find the next one. (O(n! log n!))
void generatePermutations(vector<int> &nums, int start, vector<vector<int>> &permutation)
{
  if(start == nums.size()){
    permutation.push_back(nums);
    return;
  }

  for(int i = start; i<nums.size(); i++){
    swap(nums[start], nums[i]);
    generatePermutations(nums, start+1, permutation);
    swap(nums[start], nums[i]);
  }
}

vector<int> nextPermutationBrute(vector<int> &nums)
{
  vector<vector<int>> permutations;
  generatePermutations(nums, 0, permutations);
  sort(permutations.begin(), permutations.end());

  for (int i = 0; i < permutations.size(); i++)
  {
    if (permutations[i] == nums)
    {
      if (i == permutations.size() - 1)
      {
        return permutations[0];
      }
      else
      {
        return permutations[i + 1];
      }
    }
  }
}
// Better Approach: Using STL next_permutation function O(n) and O(1) space.
vector<int> nextPermutationSTL(vector<int> &nums)
{
  next_permutation(nums.begin(), nums.end());
  return nums;
}

// Optimal Approach: Find the break point, find the just greater element than the break point, swap them and reverse the elements after the break point. O(n) and O(1) space.
vector<int> nextPermutation(vector<int> &nums)
{
  int n = nums.size();

  int ind = -1;

  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      ind = i;
      break;
    }
  }

  if (ind == -1)
  {
    reverse(nums.begin(), nums.end());
    return nums;
  }

  // next greater element that the break point
  for (int i = n - 1; i >= 0; i--)
  {
    if (nums[i] > nums[ind])
    {
      swap(nums[i], nums[ind]);
      break;
    }
  }

  // reverse the elements after the break point.
  reverse(nums.begin() + ind + 1, nums.end());

  return nums;
}
int main()
{

  vector<int> nums = {1, 3, 2};

  vector<int> result = nextPermutationBrute(nums);

  for (auto it : result)
  {
    cout << it << " ";
  }

  return 0;
}