class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = 1e9;
        for(int i=1;;i++){
            int points = i*(i+1)/2;
            if(points>n){
                break;
            }
            int remain = n-points;
            if(remain==0){
                ans=min(ans,i);
            }
            else{
                ans = min(ans, i + 1 + solve(remain, dp));
            }
        }
        return dp[n]=ans;
    }

    int minDays(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};