/*1888. Minimum Number of Flips to Make the Binary String Alternating

You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.


Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
*/
#include <bits/stdc++.h>
using namespace std;
// Starting with "010101" and Starting with "101010".
int checkDiffer(string s)
{
  int n = s.length();
  int cnt1 = 0; // starting with 0
  int cnt2 = 0; // starting with 1
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      if (s[i] == '1')
        cnt1++;

      if (s[i] == '0')
        cnt2++;
    }
    else
    {
      if (s[i] == '0')
        cnt1++;

      if (s[i] == '1')
        cnt2++;
    }
  }
  return min(cnt1, cnt2);
}
int minFlipsBrute(string s)
{
  int n = s.length();
  string temp = s;
  int ans =  INT_MAX;
  for(int i=0; i<n; i++){
    ans = min(ans, checkDiffer(temp));
    char ch = temp[0];
    temp.erase(temp.begin());
    temp.push_back(ch);
  }
  return ans;
}
// Sliding Window Approach --> O(n) time complexity and O(1) space complexity.
// We will concatenate the string with itself and then we will check for every window of size n how many characters are different from the expected character at that position. The expected character at position i will be '0' if i is even and '1' if i is odd. We will keep track of the minimum number of flips required to make the string alternating for every window of size n and return the minimum of those values.
int minFlips(string s){
  int n = s.length();
  s += s;
  int differ = 0;
  int l = 0;
  int ans = INT_MAX;
  for(int i=0; i<s.length(); i++){
    char expected = ( i % 2) ? '1' : '0';
    if(s[i] != expected) differ++;

    if(i - l + 1 > n){
      char leftExpected = (l % 2) ? '1' : '0';
      if(s[l] != leftExpected) differ--;
      l++;
    }

    if(i - l + 1 == n) ans = min(ans, min(differ, n - differ));
  }
  return ans;
}
int main()
{
  string s = "11011011";
  cout << minFlips(s) << endl;

  return 0;
}

/*101 101 1 1*/