class Solution {
public:
    int solve(int amount, vector<int>& coins,int i,vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }
        if(amount < 0 || i>=coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int nottake = solve(amount,coins,i+1,dp);
        int take = solve(amount-coins[i],coins,i,dp);

        return dp[i][amount]=take+nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};