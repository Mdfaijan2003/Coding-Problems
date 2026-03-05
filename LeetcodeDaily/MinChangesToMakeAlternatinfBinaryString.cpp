/*You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.



Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.


Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.*/

#include <bits/stdc++.h>
using namespace std;

int minOperations(string s)
{
  int n = s.length();
  int cnt1 = 0; // starting with '0'
  int cnt2 = 0; // starting with '1'

  for (int i = 0; i < n; i++)
  { 
    if (i % 2 == 0)
    {
      if (s[i] != '0')
        cnt1++;
      if (s[i] != '1')
        cnt2++;
    }
    else
    {
      if (s[i] != '0')
        cnt2++;
      if (s[i] != '1')
        cnt1++;
    }
  }
  return min(cnt1, cnt2);
}
int main()
{
  string s = "10010100";
  cout << minOperations(s) << endl;

  return 0;
}