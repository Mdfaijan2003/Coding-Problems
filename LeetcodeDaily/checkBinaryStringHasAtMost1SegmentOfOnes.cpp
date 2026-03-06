/*1784. Check if Binary String Has at Most One Segment of Ones
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.



Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
Example 2:

Input: s = "110"
Output: true*/
#include <bits/stdc++.h>
using namespace std;

bool checkOnesSegment(string s)
{
  if (s[0] == '0')
    return false;
  int n = s.length();
  bool flag = false;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1' && flag == false)
    {
      int j = i + 1;
      while (j < n && s[i] == s[j])
      {
        j++;
      }
      flag = true;
      i = j;
    }
    if (s[i] == '1' && flag == true)
      return false;
  }
  return true;
}
int main()
{
  string s = "1001";
  cout << checkOnesSegment(s) << endl;

  return 0;
}