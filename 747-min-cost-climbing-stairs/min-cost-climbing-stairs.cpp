class Solution {
public:
    int fun(int i,vector<int>& cost,vector<int>& dp){
        int n=cost.size();
        if(i==n-1){
            return cost[n-1];
        }
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i]+min(fun(i+1,cost,dp),fun(i+2,cost,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(fun(0,cost,dp),fun(1,cost,dp));
    }
};