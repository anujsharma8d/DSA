class Solution {
public:
    int fun(int i,int j,vector<int>& piles,vector<vector<int>> &dp){
        if(i==j){
            return piles[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int takeleft = piles[i]-fun(i+1,j,piles,dp);
        int takeright = piles[j]-fun(i,j-1,piles,dp);
        return dp[i][j]=max(takeleft,takeright);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(0,n-1,piles,dp)>0;
    }
};