/*
761. Special Binary String

Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
You are given a special binary string s.

A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.



Example 1:

Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occurring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
*/

#include <bits/stdc++.h>
using namespace std;
string Special(string &s)
{
  vector<string> res;
  int sum = 0;
  int start = 0;
  for (int i = 0; i < s.length(); i++)
  {
    sum += s[i] == '1' ? 1 : -1;

    if (sum == 0)
    {
      string inner = s.substr(start + 1, i - start - 1);
      res.push_back("1" + Special(inner) + "0");
      start = i + 1;
    }
  }

  sort(res.begin(), res.end(), greater<string>()); // descending order

  string ans = "";
  for (auto &it : res)
  {
    ans += it;
  }

  return ans;
}
string makeLargestSpecialBrute(string s)
{
  return Special(s);
}
string makeLargestSpecial(string s)
{

  vector<string> res;
  int count = 0;
  int start = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '1')
      count++;
    else
      count--;

    if (count == 0)
    {
      string inner = s.substr(start + 1, i - start - 1);
      res.push_back("1" + makeLargestSpecial(inner) + "0");
      start = i + 1;
    }
  }

  sort(res.begin(), res.end(), greater<string>());

  string ans = "";
  for (auto &str : res)
    ans += str;

  return ans;
}

int main()
{

  return 0;
}