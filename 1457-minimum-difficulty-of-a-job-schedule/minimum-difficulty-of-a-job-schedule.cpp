class Solution {
public:
    int solve(vector<int>& jd,int idx,int d,vector<vector<int>> &dp){
        int n = jd.size();
        if(d==1){
            int maxD = jd[idx];
            for(int i=idx;i<n;i++){
                maxD = max(maxD,jd[i]);
            }
            return maxD;
        }
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        int maxD = jd[idx];
        int finalResult =INT_MAX;
        for(int i=idx;i<=n-d;i++){
            maxD = max(maxD,jd[i]);
            int result = maxD + solve(jd,i+1,d-1,dp);
            finalResult = min(finalResult,result);
        }
        return dp[idx][d]=finalResult;
    }

    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        if(d>n){
            return -1;
        }
        return solve(jd,0,d,dp);

    }
};