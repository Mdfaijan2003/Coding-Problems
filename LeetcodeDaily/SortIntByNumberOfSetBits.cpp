/*1356. Sort Integers by The Number of 1 Bits
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.



Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> sortByBits(vector<int> &arr)
{
  int n = arr.size();
  vector<pair<int, int>> bitsCount(n);
  for (int i = 0; i < n; i++)
  {
    bitsCount[i].first = __builtin_popcount(arr[i]);
    bitsCount[i].second = arr[i];
  }
  sort(bitsCount.begin(), bitsCount.end());
  for (int i = 0; i < n; i++)
    arr[i] = bitsCount[i].second;

  return arr;
}
int main()
{
  vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> sortedArr = sortByBits(arr);
  for (int num : sortedArr)
    cout << num << " ";

  return 0;
}