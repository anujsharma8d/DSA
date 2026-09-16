class Solution {
public:
    int fun(vector<int>& coins, int amount,int i,vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(amount<0 || i<0){
            return INT_MAX;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int nottake = fun(coins,amount,i-1,dp);
        int take = fun(coins,amount-coins[i],i,dp);

        if (take != INT_MAX) {
            take+=1;
        }

        return dp[i][amount]=min(nottake,take);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        int ans = fun(coins,amount,n-1,dp);

        return ans==INT_MAX? -1:ans;
    }
};