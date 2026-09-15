class Solution {
public:
    int solve(vector<vector<int>>& pairs,int i,int lastidx,vector<vector<int>> &dp){
        if (i>=pairs.size()){
            return 0;
        }
        if(dp[i][lastidx+1]!=-1){
            return dp[i][lastidx+1];
        }
        int nottake = solve(pairs,i+1,lastidx,dp);
        int ans=nottake;
        if(lastidx==-1 || pairs[i][0]>pairs[lastidx][1]){
            int take = 1+solve(pairs,i+1,i,dp);
            ans=max(take,nottake);
        }
        return dp[i][lastidx+1]=ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1)); 
        sort(pairs.begin(),pairs.end());
        return solve(pairs,0,-1,dp);
    }
};