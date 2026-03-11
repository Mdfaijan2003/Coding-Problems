/*1009. Complement of Base 10 Integer

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.



Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.*/
#include <bits/stdc++.h>

using namespace std;

// Intuition --> XOR the number with its mask(mask ==  all 1s equal to the total number of bits of the number)
int bitwiseComplement(int n){
  int mask = 0;
  int temp = n;
  while(temp){
    mask = (mask << 1) | 1;
    temp >>= 1;
  }

  return n ^ mask;
}
int bitwiseComplementBrute(int n)
{
  string s = bitset<32>(n).to_string();
  s = s.substr(s.find('1'));
  string ans = "";
  for (int i = 0; i < s.length(); i++)
  {
    ans += (s[i] == '1') ? '0' : '1';
  }
  bitset<32> b(ans);
  return b.to_ulong();
}
int main()
{
  cout<<bitwiseComplement(5);

  return 0;
}