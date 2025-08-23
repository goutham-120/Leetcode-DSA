/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49

Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

*/
//code:
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    int maxArea(vector<int>& height){
        int maxx=0,minn=0;        //maxx will store the maximum area so far
        //minn will hold the lesser height out of the two pointers to calculate area 
        int l=0,r=height.size()-1; //left and right pointers
        while(l<=r){
            minn=min(height[l],height[r]); //minn stored lesser height
            maxx=max(maxx,(r-l)*minn);     //maxx will update if needed
            if(height[l]<=height[r]){      //it means incrementing left pointer can give greater height to get the max area as intially left pointer had less height than right 
                l++;
            }
            else r--;                //same as above but if right had less height we decrement in hope of finding greater height to maximise area
        }
        return maxx;
    }
};
int main(){
    Solution sol;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<"the max area of water obtained from the given heights is "<<sol.maxArea(height)<<endl;
    return 0;
}