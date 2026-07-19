class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i < 0 || i >= n) return 0;
        if(j==m-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(grid[i][j]<grid[i][j+1]){
            ans= max(ans,1+fun(i,j+1,grid,dp));
        }
        if(i>0 && grid[i][j]<grid[i-1][j+1]){
            ans= max(ans,1+fun(i-1,j+1,grid,dp));
        }
        if(i<n-1 && grid[i][j]<grid[i+1][j+1]){
            ans= max(ans,1+fun(i+1,j+1,grid,dp));
        }
        
        return dp[i][j]=ans;

    }

    int maxMoves(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int ans = fun(i,0,grid,dp);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};