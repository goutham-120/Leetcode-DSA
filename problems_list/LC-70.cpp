/* 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45  
 */

//code:
#include<iostream>
#include<vector>
using namespace std;
class solution{
  public:
    int climbStairs(int n) {
        if(n==0)        //no steps were climbed
          return 0;    
        if(n==1)        //one step so one way
          return 1;
        if(n==2)        //two steps, two ways-(one at a time and both at once)
          return 2;
        vector<int> dp(n+1,0);  //creating a dp vector to use previous values for current
        dp[0]=0;
        dp[1]=1;         //initiallizing known values
        dp[2]=2;
      for(int i=3;i<=n;i++)
      {
        dp[i]=dp[i-1]+dp[i-2];   //it basically means to reach step i, u have two ways -> climb from step i-1,or climb directly from i-2, so added their both's number of ways to climb 

      }   
        return dp[n];    //returning the number of ways to climb the nth stair
    }
};
int main(){
    solution s;
    int n=6;
    cout<<"number of ways to climb "<<n<<" stairs is "<<s.climbStairs(n)<<endl;
}