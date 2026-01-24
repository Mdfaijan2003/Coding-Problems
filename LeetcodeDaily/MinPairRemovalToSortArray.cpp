#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int left, int right, vector<int> temp)
{
  int sum = temp[left] + temp[right];
  int n = temp.size();
  // Add this into the new array
  vector<int> ans;
  for (int i = 0; i < n - 1; i++)
  {
    if (i == left)
    {
      ans[i] = sum;
    }
    if (i >= right)
    {
      ans[i] = temp[i + 1];
    }
    else {
      ans.push_back(temp[i]);
    }
  }

  // Check if the array is sorted
  if(is_sorted(ans.begin(), ans.end())){
    return ans;
  }
  // Try all possible pairs
  dfs(left + 1, right + 1, ans);
}
int minimumPairRemoval(vector<int> &nums)
{
  int n = nums.size();
  vector<int> temp = dfs(0, 1, nums);
  return n - temp.size();
}
int main()
{

  return 0;
}