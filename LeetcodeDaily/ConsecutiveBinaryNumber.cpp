/*1680. Concatenation of Consecutive Binary Numbers

Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.



Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1.
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.*/
#include <bits/stdc++.h>
using namespace std;

// Naive Approach --> Concatenate the binary strings and convert to decimal
int concatenatedBinaryBrute(int n)
{
  string s = "";

  for (int i = 1; i <= n; i++)
  {
    bitset<32> b(i);
    string temp = b.to_string();
    s += temp.erase(0, temp.find_first_not_of('0'));
  }

  // return stoll(s, 0, 2) % 10000000009;

  unsigned long long result = 0;
  int index = s.size() - 1;
  for (char c : s)
  {
    if (c == '1')
    {
      result += (1ULL << index);
    }
    index--;
  }
  return result % 1000000007;
}
// Optimized Approach --> Use bit manipulation to calculate the result without concatenating the binary strings
int concatenatedBinary(int n)
{
  const int MOD = 1e9 + 7;
  long long result = 0;
  int bitLength = 0;

  for (int i = 1; i <= n; i++)
  {
    if ((i & (i - 1)) == 0)
      bitLength++;

    result = ((result << bitLength) % MOD + i) % MOD;
  }

  return result;
}
int main()
{
  cout << concatenatedBinary(42) << endl;
  return 0;
}