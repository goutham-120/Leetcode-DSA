#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    double maxx=0.0,curr=0.0;
    for(int i=0;i<k;i++){
        curr+=nums[i]*1.0/k;
    }
    maxx=curr;             //assume current avg is our maximum avg
    for(int i=k;i<nums.size();i++){
        curr+=(nums[i]-nums[i-k])*1.0/k;
        if(curr>maxx){    //update maximum avg if required
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