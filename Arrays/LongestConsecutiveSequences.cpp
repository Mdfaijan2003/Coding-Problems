/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3*/

#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &arr)
{
  int n = arr.size();
  if (n == 0)
    return 0;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(arr[i]);
  }
  int cnt = 0;
  int x;
  int longest = 1;
  for (auto it : st)
  {
    if (st.find(it - 1) == st.end())
    {
      cnt = 1;
      x = it;
      while (st.find(x + 1) != st.end())
      {
        x = x + 1;
        cnt += 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}
int main()
{
  vector<int> arr = {1,2,6,7,8};
  cout << longestConsecutive(arr) << endl;

  return 0;
}