/*190. Reverse Bits
Reverse bits of a given 32 bits signed integer.
 
Example 1:
Input: n = 43261596
Output: 964176192

Explanation:
Integer	    Binary
43261596	  00000010100101000001111010011100
964176192	  00111001011110000010100101000000
*/


#include <bits/stdc++.h>
using namespace std;
// Simple Idea: get the last digit put in into the first digit.
int reverseBits(int n)
{
  int result = 0;
  for(int i=0; i<32; i++){
    result = (result << 1) | (n & 1);
    n >>= 1;
  }

  return result;
}
int main()
{

  return 0;
}