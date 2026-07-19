class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i==0){
            return grid[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=0;k<grid.size();k++){
            if(k!=j){
                int sum=grid[i][j]+fun(i-1,k,grid,dp);
                mini = min(sum,mini);
            }
        }
        return dp[i][j]=mini;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n =grid.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1)); 
        for(int j=0;j<n;j++){
            int sum = fun(n-1,j,grid,dp);
            ans=min(sum,ans);
        }        
        return ans;
    }
};