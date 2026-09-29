class Solution {
public:
    bool solve(vector<vector<char>>& grid,int i,int j,int check,vector<vector<vector<int>>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m){
            return false;
        }
        if(grid[i][j]=='('){
            check++;
        }
        else{
            check--;
        }
        if(check<0){
            return false;
        }
        if(i==n-1 && j==m-1){
            return check==0;
        }
        if(dp[i][j][check]!=-1){
            return dp[i][j][check];
        }

        bool right = solve(grid,i,j+1,check,dp);
        bool down = solve(grid,i+1,j,check,dp);

        return dp[i][j][check]=right||down;

    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==')'){
            return false;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m+n,-1)));
        return solve(grid,0,0,0,dp);
    }
};