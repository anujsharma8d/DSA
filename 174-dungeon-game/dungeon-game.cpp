class Solution {
public:
    int minhp(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(i==n-1 && j==m-1){
            return max(1,1-dungeon[i][j]); 
        }
        if(i>n-1 || j>m-1){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=minhp(i,j+1,dungeon,dp);
        int down=minhp(i+1,j,dungeon,dp);
        int need = min(right,down);
        return dp[i][j]=max(1,need-dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minhp(0,0,dungeon,dp);
    }
};