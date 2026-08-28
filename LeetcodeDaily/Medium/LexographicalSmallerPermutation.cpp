/*3720. Lexicographically Smallest Permutation Greater Than Target
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.



Example 1:

Input: s = "abc", target = "bba"

Output: "bca"

Explanation:

The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
The lexicographically smallest permutation that is strictly greater than target is "bca".
Example 2:

Input: s = "leet", target = "code"

Output: "eelt"

Explanation:

The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
The lexicographically smallest permutation that is strictly greater than target is "eelt".
Example 3:

Input: s = "baba", target = "bbaa"

Output: ""

Explanation:

The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".


Constraints:

1 <= s.length == target.length <= 300
s and target consist of only lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;

string result = "";

bool solve(int idx, string &curr, vector<int> &count, string target, bool greater)
{
  if (idx == target.length())
  {
    if (greater)
    {
      result = curr;
      return true;
    }
    return false;
  }

  for (char ch = 'a'; ch <= 'z'; ch++)
  {

    if (count[ch - 'a'] == 0)
      continue;
    if (!greater && ch < target[idx])
      continue;

    // Do
    curr.push_back(ch);
    count[ch - 'a']--;

    bool isGreater = greater || ch > target[idx];

    if (solve(idx + 1, curr, count, target, isGreater))
      return true;

    // Undo
    curr.pop_back();
    count[ch - 'a']++;
  }

  return false;
}

string lexGreaterPermutation(string s, string target)
{
  int n = s.length();

  // Count the frequency
  vector<int> count(26, 0);
  for (int i = 0; i < n; i++)
  {
    count[s[i] - 'a']++;
  }

  // Solve for every index
  string curr = "";
  solve(0, curr, count, target, false);

  // return result a global variable
  return result;
}
int main()
{

  return 0;
}