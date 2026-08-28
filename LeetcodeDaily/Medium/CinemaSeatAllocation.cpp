/*1386. Cinema Seat Allocation
Attempted
Medium
Topics
premium lock icon
Companies
Hint


A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.



Example 1:



Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4


Constraints:

1 <= n <= 109
1 <= reservedSeats.length <= min(10 * n, 104)
reservedSeats[i] == [rowi, seati]
1 <= rowi <= n
1 <= seati <= 10
All reservedSeats[i] are distinct.*/

#include <bits/stdc++.h>
using namespace std;
int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
{
  unordered_map<int, unordered_set<int>> reservedSeat;

  for (auto &seats : reservedSeats)
  {
    int row = seats[0];
    int seat = seats[1];

    reservedSeat[row].insert(seat);
  }

  int count = (n - reservedSeat.size()) * 2; // Empty Rows

  for (auto &[row, bookedSeats] : reservedSeat)
  {

    auto isAvailable = [&](int seat)
    {
      return bookedSeats.find(seat) == bookedSeats.end();
    };

    auto groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
    auto groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
    auto groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

    if (groupA && groupC)
      count += 2;
    else if (groupA || groupB || groupC)
      count += 1;
  }

  return count;
}

int maxNumberOfFamiliesOptimal(int n, vector<vector<int>> &reservedSeats)
{
  unordered_map<int, int> reservedSeat;

  for (auto &seats : reservedSeats)
  {
    int row = seats[0];
    int seat = seats[1];

    reservedSeat[row] |= (1 << seat);
  }

  int count = (n - reservedSeat.size()) * 2; // Empty Rows

  int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
  int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
  int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

  for (auto &[row, bookedSeats] : reservedSeat)
  {

    auto groupA = (bookedSeats & maskA) == 0;
    auto groupB = (bookedSeats & maskB) == 0;
    auto groupC = (bookedSeats & maskC) == 0;

    if (groupA && groupC)
      count += 2;
    else if (groupA || groupB || groupC)
      count += 1;
  }

  return count;
}

int main()
{

  return 0;
}