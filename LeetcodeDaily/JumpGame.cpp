/*3660. Jump Game IX
You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

Jump to index j where j > i is allowed only if nums[j] < nums[i].
Jump to index j where j < i is allowed only if nums[j] > nums[i].
For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i.

Example 1:

Input: nums = [2,1,3]

Output: [2,2,3]

Explanation:

For i = 0: No jump increases the value.
For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump increases the value.
Thus, ans = [2, 2, 3].

Example 2:

Input: nums = [2,3,1]

Output: [3,3,3]

Explanation:

For i = 0: Jump forward to j = 2 as nums[j] = 1 is less than nums[i] = 2, then from i = 2 jump to j = 1 as nums[j] = 3 is greater than nums[2].
For i = 1: Since nums[1] = 3 is the maximum value in nums, no jump increases the value.
For i = 2: Jump to j = 1 as nums[j] = 3 is greater than nums[2] = 1.
Thus, ans = [3, 3, 3].



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109*/

#include <bits/stdc++.h>
using namespace std;
int solve(int i, vector<int> &nums, int maxEl, vector<int> &dp, vector<bool> &vis)
{
  int n = nums.size();

  if (i >= n || i < 0)
    return -1;

  if (nums[i] == maxEl)
    return maxEl;

  if (dp[i] != -1)
    return dp[i];
  if (vis[i])
    return nums[i];

  vis[i] = true;

  int ans = nums[i];

  for (int j = 0; j < n; j++)
  {

    // valid jump condition
    if ((j < i && nums[j] > nums[i]) ||
        (j > i && nums[j] < nums[i]))
    {

      ans = max(ans, solve(j, nums, maxEl, dp, vis));
    }
  }

  return dp[i] = ans;
}

vector<int> maxValue(vector<int> &nums)
{

  int n = nums.size();

  int maxi = *max_element(nums.begin(), nums.end());

  vector<int> dp(n, -1);
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    vector<bool> vis(n, false);
    arr[i] = solve(i, nums, maxi, dp, vis);
  }

  return arr;
}

// Prefix max and suffix min approach to find component boundaries and fill the answer in O(n) time
// Imp Check --> prefixMax[i] <= suffixMin[i + 1]; --> This declare a boundary between two components. All elements in the left component are less than or equal to all elements in the right component. Hence, we can fill the left component with prefixMax[i] and move to the next component.
vector<int> maxValueOptimal(vector<int> &nums)
{

  int n = nums.size();

  vector<int> prefixMax(n);
  vector<int> suffixMin(n);

  prefixMax[0] = nums[0];
  suffixMin[n - 1] = nums[n - 1];

  // Build prefix max
  for (int i = 1; i < n; i++)
  {
    prefixMax[i] = max(prefixMax[i - 1], nums[i]);
  }

  // Build suffix min
  for (int i = n - 2; i >= 0; i--)
  {
    suffixMin[i] = min(suffixMin[i + 1], nums[i]);
  }

  vector<int> arr(n);

  int start = 0;

  for (int i = 0; i < n - 1; i++)
  {

    // Component boundary
    if (prefixMax[i] <= suffixMin[i + 1])
    {

      for (int j = start; j <= i; j++)
      {
        arr[j] = prefixMax[i];
      }

      start = i + 1;
    }
  }

  // Last component
  for (int j = start; j < n; j++)
  {
    arr[j] = prefixMax[n - 1];
  }

  return arr;
}

int main()
{

  return 0;
}