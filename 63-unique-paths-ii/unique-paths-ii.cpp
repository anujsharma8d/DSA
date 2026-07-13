class Solution {
public:
    int path(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i==0 && j==0 && obstacleGrid[0][0]!=1){
            return 1;
        }
        if(i==0 && j==0 && obstacleGrid[0][0]==1){
            return 0;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            if(obstacleGrid[i][j]==1){
                return 0;
            }
            return dp[i][j]=path(i-1,j,obstacleGrid,dp)+path(i,j-1,obstacleGrid,dp);
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(n-1,m-1,obstacleGrid,dp);
    }
};