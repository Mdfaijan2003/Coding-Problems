/*
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.



Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
*/

#include <bits/stdc++.h>
using namespace std;
// Optimal Approach: After Analysis the pattern it is found that the max number in the string dictate the answer.
int minPartitionsOptimal(string n)
{
  return *max_element(begin(n), end(n)) - '0';
}
int minPartitions(string n)
{
  int count = 0;

  while(true){
    bool changed = false;
    for(int i=0; i<n.size(); i++){
      if(n[i] != '0'){
        n[i]--;
        changed = true;
      }
    }
    if(!changed) break;
    count++;
  }

  return count;
}
int main()
{
  string n = "27856911546511111000044898454";
  cout << minPartitions(n) << endl;
  cout << minPartitionsOptimal(n) << endl;

  return 0;
}