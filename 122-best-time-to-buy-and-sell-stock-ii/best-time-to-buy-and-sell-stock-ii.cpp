class Solution {
public:
    int fun(int i,int buy,vector<int>& prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            int take = -prices[i]+fun(i+1,0,prices,dp);
            int nottake=fun(i+1,1,prices,dp);
            profit=max(take,nottake);
        }
        else{
            int take= prices[i]+fun(i+1,1,prices,dp);
            int nottake=fun(i+1,0,prices,dp);
            profit=max(take,nottake);
        }
        return dp[i][buy]=profit;
    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1)); 
        return fun(0,1,prices,dp);
    }
};