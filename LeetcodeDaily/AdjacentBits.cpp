#include<bits/stdc++.h>
using namespace std;

bool helper_function(int n, int last){
  int secLast = n & 1;
  if(secLast == last) return false;

  return true;
}
bool hasAlternatingBitsBruteForce(int n){
  int x = n;

  while(x!=0){
    int last = x & 1;
    x = x >> 1;
    if(!helper_function(x, last)) return false;
  }
  return true;
}

// Approach --> Right shift the number and XOR it with the original to produce a value like 11111 (indicating adjacent set bits), then mask the result by ANDing it with its incremented value.

// why unsigned? Ans: To make sure the >> operator shifts in zeros from the left (not copies of the sign bit), which keeps the bit pattern intact for the algorithm to work correctly.
bool hasAlternatingBits(int n){
  unsigned int x = n ^ (n >> 1);
  return ( x & (x + 1)) == 0;
}
int main(){

  cout<<hasAlternatingBitsBruteForce(5);
  
  return 0;
}