class Solution {
public:
    int fun(int i,int buy,int cooldown,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy][cooldown]!=-1){
            return dp[i][buy][cooldown];
        }
        if(cooldown){
            return fun(i+1,1,0,prices,dp);
        }
        int profit=0;
        if(buy){
                int take=-prices[i]+fun(i+1,0,0,prices,dp);
                int nottake=fun(i+1,1,0,prices,dp);
                profit=max(take,nottake);
            }
        else{
            int take=prices[i]+fun(i+1,1,1,prices,dp);
            int nottake=fun(i+1,0,0,prices,dp);
            profit=max(take,nottake);
        }
        return dp[i][buy][cooldown]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return fun(0,1,0,prices,dp);
    }
};