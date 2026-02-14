#include <bits/stdc++.h>
using namespace std;

int longestBalancedSubstring(string s)
{
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n;)
  {
    int j = i;
    while (j < n && s[j] == s[i])
      j++;
    ans = max(ans, j - i);
    i = j;
  }

  auto solveTwo = [&](char x, char y)
  {
    unordered_map<int, int> first;
    int diff = 0;
    int res = 0;
    first[0] = -1;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == x)
        diff++;
      else if (s[i] == y)
        diff--;
      else
      {
        diff = 0;
        first.clear();
        first[0] = i;
        continue;
      }

      if (first.count(diff))
        res = max(res, i - first[diff]);
      else
        first[diff] = i;
    }
    return res;
  };

  ans = max(ans, solveTwo('a', 'b'));
  ans = max(ans, solveTwo('a', 'c'));
  ans = max(ans, solveTwo('b', 'c'));

  unordered_map<long long, int> first;
  int a = 0, b = 0, c = 0;
  first[0] = -1;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'a')
      a++;
    else if (s[i] == 'b')
      b++;
    else
      c++;

    int x = b - a;
    int y = c - a;

    long long key = ((long long)(x) << 32) ^ (unsigned int)y;

    if (first.count(key))
      ans = max(ans, i - first[key]);
    else
      first[key] = i;
  }

  return ans;
}
int main()
{
  string s = "aba";
  cout<<longestBalancedSubstring(s);
  return 0;
}