class Solution {
public:
    int solve(int n, vector<int>& costs,int i,vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int cost = INT_MAX;
        int j = i+1;
        if(j<=n){
            cost = min(cost,costs[j-1]+1+solve(n,costs,i+1,dp));
        }
        j = i+2;
        if(j<=n){
            cost = min(cost,costs[j-1]+4+solve(n,costs,i+2,dp));
        }
        j = i+3;
        if(j<=n){
            cost = min(cost,costs[j-1]+9+solve(n,costs,i+3,dp));
        }
        return dp[i]=cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return solve(n,costs,0,dp);
    }
};