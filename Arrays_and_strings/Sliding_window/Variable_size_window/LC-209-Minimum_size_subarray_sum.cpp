/*209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

 Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
*/

//code:
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int minSubArrayLen(int target,vector<int> nums){
    int n=nums.size();
    int minn=n+1,l=0,r=0;           //assuming the minlength is greater than size to see if it updates
    long sum=0;
    for(r=0;r<n;r++){              //r++ expands window 
        sum+=nums[r];
        while(l<=r&&sum>=target){  //shrinks window to get minimum possible length
            if(r-l+1<minn){        //r-l+1 is the size of its window/subarray
                minn=r-l+1;
            } // (or) minn=min(minn,r-l+1);
            sum-=nums[l];
            l++;                   //this l++ shrinks the window from left 
        }
    }
    if(minn==n+1) return 0;        //if minn doesnt change ,that means no subarray sum equals target so return 0
    else return minn;
  }
};
int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    Solution s;
    cout<<"the minimum length of subarray whose sum is greater or equal to target is: "<<s.minSubArrayLen(target,nums)<<endl;
    return 0;
}