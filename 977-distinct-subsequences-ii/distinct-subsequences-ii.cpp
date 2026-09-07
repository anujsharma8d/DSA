class Solution {
public:
    int M = 1e9+7;
    int solve(int i,vector<int> &prev,vector<int> &dp){
        if(i==0){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        ans=(2*solve(i-1,prev,dp))%M;
        if(prev[i]!=0){
            int duplicate=solve(prev[i]-1,prev,dp);
            ans=(ans-duplicate+M)%M;
        }
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        vector<int> lastSeen(26,0);
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;i++){
            int idx = s[i-1]-'a';
            prev[i]=lastSeen[idx];
            lastSeen[idx]=i;
        }

        return (solve(n,prev,dp)-1+M)%M;
    }
};