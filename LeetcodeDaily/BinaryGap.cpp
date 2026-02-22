/*868. Binary Gap
Solved
Easy
Topics
premium lock icon
Companies
Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.



Example 1:

Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.*/

#include <bits/stdc++.h>
using namespace std;
int binaryGap(int n)
{
  if(n==0) return 0;
  int k = n;
  int prev = -1;
  int maxGap = 0;

  while(k){
    int bit = k & -k;
    int index = __builtin_ctz(bit);
    if(prev != -1){
      maxGap = max(maxGap, index - prev);
    }
    prev = index;
    k &= k - 1;
  }

  return maxGap;
}
int main()
{

  return 0;
}