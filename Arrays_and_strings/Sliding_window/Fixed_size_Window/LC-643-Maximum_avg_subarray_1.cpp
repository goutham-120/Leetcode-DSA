/*
643. Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 
Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 10^5
-104 <= nums[i] <= 10^4

*/

//code:git 
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    double maxx=0.0,curr=0.0;
    for(int i=0;i<k;i++){    //calculating avg of first window
        curr+=nums[i]*1.0/k;
    }
    maxx=curr;    //assume current avg is our maximum avg
    for(int i=k;i<nums.size();i++){     //sliding the window towards right
        curr+=(nums[i]-nums[i-k])*1.0/k;    //this calculates avg of each window
        if(curr>maxx){     //update maximum avg if required
            maxx=curr;
        }
        //(or) maxx=max(curr,maxx);
    }
    return maxx;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    cout<<"maximum avg subarray of given size k of array is :"<<sol.findMaxAverage(nums,k)<<endl;
    return 0;
}