/*You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
*/

#include <bits/stdc++.h>
using namespace std;
// Divide the array into 2 halfs check left for b and delete then check right for a and delete it. -- O(N^2)
int minimumDeletion(string s)
{
  int n = s.size();
  int ans = n;

  for (int i = 0; i <= n; i++)
  {
    int deletions = 0;

    // left part: only 'a' allowed
    for (int j = 0; j < i; j++)
    {
      if (s[j] == 'b')
        deletions++;
    }

    // right part: only 'b' allowed
    for (int j = i; j < n; j++)
    {
      if (s[j] == 'a')
        deletions++;
    }

    ans = min(ans, deletions);
  }
  return ans;
}

//optimal approach --> using bcount(how many b's appears before) and deletions(what's the min deletion possible)
int minimumDeletions(string s){
  int bCount = 0;
  int n =s.length();
  int deletions = 0;
  for(char c : s){
    if(c == 'b'){
      bCount++;
    }
    else{
      deletions = min(deletions + 1, bCount);
    }
  }
  return deletions;
}

int main()
{
  string s = "bbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaabababababbbbbbbabababbbbbaaaaaaaababababa"; //expected ans = 32
  cout << minimumDeletion(s);

  return 0;
}