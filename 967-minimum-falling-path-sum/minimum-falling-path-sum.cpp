class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n=matrix.size();
        if(j<0 || j>=n){
            return 1e9;
        }
        if(i==0){
            return matrix[0][j];
        }
        if(dp[i][j]!=-101){
            return dp[i][j];
        }
        int up = matrix[i][j]+fun(i-1,j,matrix,dp);
        int diagleft = matrix[i][j]+fun(i-1,j-1,matrix,dp);
        int diagright = matrix[i][j]+fun(i-1,j+1,matrix,dp);
        return dp[i][j]=min({up,diagleft,diagright});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-101));
        int mini = INT_MAX;
        for(int j=0;j<n;j++){
            int sum = fun(n-1,j,matrix,dp);
            mini=min(mini,sum);
        }
        return mini;
    }
};