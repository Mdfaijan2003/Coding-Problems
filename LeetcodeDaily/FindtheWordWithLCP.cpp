#include <bits/stdc++.h>
using namespace std;
string findTheString(vector<vector<int>> &lcp)
{
  int n = lcp.size();
  string word(n, '#');

  char cur = 'a';

  // Step 1: assign characters
  for (int i = 0; i < n; i++)
  {
    if (word[i] == '#')
    {
      if (cur > 'z')
        return "";
      for (int j = i; j < n; j++)
      {
        if (lcp[i][j] > 0)
        {
          word[j] = cur;
        }
      }
      cur++;
    }
  }

  // Step 2: validate LCP
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (word[i] == word[j])
      {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      }
    }
  }

  // Step 3: compare
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (dp[i][j] != lcp[i][j])
      {
        return "";
      }
    }
  }

  return word;
}
int main()
{

  return 0;
}