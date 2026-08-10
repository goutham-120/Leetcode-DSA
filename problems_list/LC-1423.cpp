/*
1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 
Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum=0,lsum=0,rsum=0; //lsum is sum of points of cards taken from left and rsum is sum of points of cards taken from right, maxsum is global maximum score that can be obtained
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];  //for first window we will take all cards from left and calculate score of that window.
        }
        maxsum=lsum; //assume score of first window is our maximum score
        int r=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
          //sliding the window: we will remove one card from left and add one card from right and calculate score of each window and update maximum score if required.(lsum decs,rsum incs)
            lsum-=cardPoints[i];
            rsum+=cardPoints[r--];
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};
int main(){
    Solution sol;
    vector<int> cardPoints={1,2,3,4,5,6,1};
    int k=3;
    cout<<"maximum score that can be obtained is: "<<sol.maxScore(cardPoints, k)<<endl;
    return 0;
}
