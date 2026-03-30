#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool canBeEqual(string s1, string s2)
{
  int n = s1.length();
  for (int i = 0; i < n; i++)
  {
    if (s1[i] != s2[i])
    {
      if (i + 2 < n)
      {
        if (s1[i + 2] == s2[i])
          swap(s1[i], s1[i + 2]);
        else
          return false;
      }
    }
  }
  return s1 == s2;
}

// Optimal Approach --> we can swap the first and third character and second and fourth character in any order so we just need to check if the first and third character of both string are same and second and fourth character of both string are same or not.
/*  a b c d
    c d a b */
bool calBeWEqual(string s1, string s2)
{
  return (
             (s1[0] == s2[0] && s1[2] == s2[2]) ||
             (s1[0] == s2[2] && s1[2] == s2[0])) &&
         ((s1[1] == s2[1] && s1[3] == s2[3]) ||
          (s1[1] == s2[3] && s1[3] == s2[1]));
}
int main()
{

  return 0;
}