#include <bits/stdc++.h>
using namespace std;

// Approach --> sort the array and take ceil(h/w.size)
int calculateTime(int workerTime, int height)
{
  // Time = workerTime * (1 + 2 + ... + height)
  // Sum of first h integers = h*(h+1)/2
  return workerTime * (height * (height + 1)) / 2;
}

long long minNumberOfSecondsBrute(int mountainHeight, vector<int> &workerTimes)
{
  int n = workerTimes.size();
  int numOfWorkers = n;
  long long maxTime = INT_MIN;

  if (n == 1)
  {
    return calculateTime(workerTimes[0], mountainHeight);
  }

  sort(workerTimes.begin(), workerTimes.end());
  int remainingHeight = mountainHeight;

  for (int i = 0; i < n; i++)
  {
    long long val = ceil((double)remainingHeight / (numOfWorkers - i));

    maxTime = max(maxTime, (long long)calculateTime(workerTimes[i], val));
    remainingHeight -= val;
  }
  return maxTime;
}



bool check(int mountainHeight, vector<int> &workerTimes, long long mid)
{
  long long totalHeight = 0;
  
  for (int time : workerTimes)
  {
    long long maxProduct = 2 * mid / time; 
    
    // Using quadratic formula: h = (-1 + sqrt(1 + 4*maxProduct)) / 2
    long long discriminant = 1 + 4 * maxProduct;
    long long cutHeight = (-1 + sqrt(discriminant)) / 2;
    
    totalHeight += cutHeight;
    
    if(totalHeight >= mountainHeight) return true;
  }
  
  return totalHeight >= mountainHeight;
}

// Optimal approach --> using Binary search on answer
long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
{
  int n = workerTimes.size();
  long long left = 1;  
  int maxWorkerTime = *max_element(workerTimes.begin(), workerTimes.end());
  
  // Upper bound: Slowest worker does all the work
  long long right = (long long)maxWorkerTime * mountainHeight * (mountainHeight + 1) / 2;
  
  long long ans = right;
  
  while (left <= right)  
  {
    long long mid = left + (right - left) / 2;

    if (check(mountainHeight, workerTimes, mid))
    {
      ans = mid;        
      right = mid - 1;
    }
    else
    {
      left = mid + 1;   
    }
  }
  
  return ans;
}

int main()
{
  vector<int> workerTimes = {2, 1, 1};
  cout << "Minimum time: " << minNumberOfSeconds(4, workerTimes) << endl;
  return 0;
}