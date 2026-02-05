/*26. Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
#include<bits/stdc++.h>
using namespace std;
// Move and place.
int removeDuplicate(int arr[], int n){
  if(n == 0) return 0;
  int i=0;
  for(int j=1; j<n; j++){
    if(arr[i] != arr[j]){
      i++;
      arr[i] = arr[j];
    }
  }
  return i+1;
}
int main(){
  cout<<"Enter the size of an array: \n";
  int n;
  cin>>n;
  int arr[n];
  cout<<"Enter the elements in the array: \n";
  for (int i = 0; i < n; i++){
    cin>>arr[i];
  }

  int k = removeDuplicate(arr, n);
  cout<<"Number of unique elements: "<<k<<endl;
  cout<<"Array after removing duplicates: ";
  for (int i = 0; i < k; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}

// Complexity Analysis:
// Time Complexity: O(n), where n is the number of elements in the array. We traverse the array once.
// Space Complexity: O(1), as we are using only a constant amount of extra space