class Solution {
public:
    int fun(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int m=grid[0].size();
        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e9;
        }
        if(i==0){
            if(j1==0 && j2==m-1){
                return grid[i][j1]+grid[i][j2];
            }
            else{
                return -1e9;
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi=INT_MIN;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                int change=fun(i-1,j1+a,j2+b,grid,dp);
                if(j1!=j2){
                    change+=grid[i][j1]+grid[i][j2];
                }   
                else{
                    change+=grid[i][j1];
                }
                maxi=max(maxi,change);
            }
        }
        return dp[i][j1][j2]=maxi;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int maxi=INT_MIN;
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                int ans=fun(n-1,j,k,grid,dp);
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};