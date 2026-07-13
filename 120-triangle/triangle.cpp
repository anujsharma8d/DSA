class Solution {
public:
    int minsum(int i,int last,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if (last < 0 || last > i)
            return 1e9;
        if(i==0){
            return triangle[0][0]; 
        }
        if(dp[i][last]!=-1){
            return dp[i][last];
        }
        int up = minsum(i-1,last,triangle,dp);
        int diag = minsum(i-1,last-1,triangle,dp);
        return dp[i][last]=triangle[i][last]+min(up,diag);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1)); 
        for(int j=0;j<n;j++){
           ans=min(ans,minsum(n-1,j,triangle,dp));
        }
        return ans;
    }
};