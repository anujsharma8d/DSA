class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int x,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0){
            return 1e9;
        }
        x ^= grid[i][j];
        if(i==n-1 && j==m-1){
            return x;
        }
        if(dp[i][j][x]!=-1){
            return dp[i][j][x];
        }
        int right = solve(grid,i+1,j,x,dp);
        int down = solve(grid,i,j+1,x,dp);

        return dp[i][j][x]=min(right,down);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));

        return solve(grid,0,0,0,dp);
    }
};