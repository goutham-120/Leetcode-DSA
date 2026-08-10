// 852. Peak Index in a Mountain Array

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid-1]<arr[mid]&&arr[mid+1]<arr[mid]) return mid; //if mid is the peak element return mid
            else if(arr[mid-1]<=arr[mid]) l=mid+1; //if the left neighbor is less than or equal to mid, the peak is in the right half
            else r=mid-1; //otherwise, the peak is in the left half
        }
        return 0;
    }
};
int main(){
    Solution sol;
    vector<int> arr={0,1,0};
    cout<<"the peak index in the mountain array is "<<sol.peakIndexInMountainArray(arr)<<endl;
    return 0;
}