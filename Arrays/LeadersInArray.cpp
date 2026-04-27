/*Problem Statement: Given an array of integers, find all the elements that are leaders in the array. An element is a leader if it is greater than all the elements to its right side in the array.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> leaders(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans;
  int maxEl = INT_MIN;
  for (int i = n - 1; i >= 0; i--)
  {
    if(nums[i] > maxEl){
      ans.push_back(nums[i]);
      maxEl = nums[i];
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{
  vector<int> nums = {16, 17, 4, 3, 5, 2};
  vector<int> result = leaders(nums);
  for (auto it : result)
  {
    cout << it << " ";
  }

  return 0;
}