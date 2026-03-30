/*You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.



Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.


Constraints:

n == s1.length == s2.length
1 <= n <= 105
s1 and s2 consist only of lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;

// Brute force approach: We can try all possible operations on s1 and check if it becomes equal to s2. However, this approach is not efficient and may lead to a time limit exceeded error for large inputs.
class Solution
{
public:
  bool checkStrings(string s1, string s2)
  {
    if (s1 == s2)
      return true;
    int n = s1.length();
    for (int i = 0; i < n; i++)
    {
      int jump = 2;
      if (s1[i] != s2[i])
      {
        bool flag = false;
        while (i + jump < n)
        {
          if (s1[i + jump] == s2[i])
          {
            swap(s1[i], s1[i + jump]);
            flag = true;
            break;
          }
          jump += 2;
        }
        if (!flag)
          return false;
      }
      if (s1 == s2)
        return true;
    }
    return s1 == s2;
  }
};
// Optimal approach: We can count the frequency of characters at even and odd indices separately for both strings. If the frequency matches for both strings, then we can make them equal by performing the allowed operations. This approach has a time complexity of O(n) and space complexity of O(1) since we are using fixed-size arrays to count frequencies.
bool checkStrings(string s1, string s2)
{
  int n = s1.length();

  vector<int> even(26, 0), odd(26, 0);

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      even[s1[i] - 'a']++;
      even[s2[i] - 'a']--;
    }
    else
    {
      odd[s1[i] - 'a']++;
      odd[s2[i] - 'a']--;
    }
  }

  for (int i = 0; i < 26; i++)
  {
    if (even[i] != 0 || odd[i] != 0)
      return false;
  }

  return true;
}

int main()
{

  return 0;
}