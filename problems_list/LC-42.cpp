// 42. Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
// //  

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105/

//code:
#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int lmax=0,rmax=0; //lmax is the maximum height of the left side of the current index and rmax is the maximum height of the right side of the current index
        int l=0,r=height.size()-1;
        while(l<r){
            lmax=max(lmax,height[l]);//we update the maximum height of the left side and the maximum height of the right side at each index
            rmax=max(rmax,height[r]);
            //
            if(lmax<rmax){
                ans+=(lmax-height[l]); //if the maximum height of the left side is less than the maximum height of the right side then we can trap water at the current index which is equal to the difference between the maximum height of the left side and the height of the current index
                l++;
            }
            else{
                ans+=(rmax-height[r]);//if the maximum height of the right side is less than or equal to the maximum height of the left side then we can trap water at the current index which is equal to the difference between the maximum height of the right side and the height of the current index
                r--;
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"the amount of water that can be trapped is: "<<sol.trap(height)<<endl;
    return 0;
}