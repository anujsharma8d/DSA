class Solution {
public:
    int fun(int i,int buy,int transactions,vector<int>& prices,vector<vector<vector<int>>> &dp){
        int n=prices.size();
        if(transactions==0){
            return 0;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][buy][transactions]!=-1){
            return dp[i][buy][transactions];
        }
        int profit=0;
        if(buy){
            int take=-prices[i]+fun(i+1,0,transactions,prices,dp);
            int nottake=fun(i+1,1,transactions,prices,dp);
            profit=max(take,nottake);
        }
        else{
            int take=prices[i]+fun(i+1,1,transactions-1,prices,dp);
            int nottake=fun(i+1,0,transactions,prices,dp);
            profit=max(take,nottake);
        }
        return dp[i][buy][transactions]=profit;
    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0,1,2,prices,dp);
    }
};