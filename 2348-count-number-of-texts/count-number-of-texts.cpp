class Solution {
public:
    const int MOD = 1000000007;

    int solve(string &s,int i,vector<int> &dp){
        int n=s.size();
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long take1=1LL*solve(s,i+1,dp);
        long long take2=0;
        if(i<n-1 && s[i]==s[i+1]){
            take2 = 1LL*solve(s,i+2,dp);
        }
        long long take3=0;
        if(i<n-2 && s[i]==s[i+1] && s[i+1]==s[i+2]){
            take3 = 1LL*solve(s,i+3,dp);
        }
        long long take4=0;
        if(i<n-3 && s[i]==s[i+1] && s[i+1]==s[i+2] && s[i+2]==s[i+3] && (s[i]=='7' || s[i]=='9')){
            take4 = 1LL*solve(s,i+4,dp);
        }

        return dp[i]=(take1+take2+take3+take4)%MOD;
    }

    int countTexts(string pressedKeys) {
        int n=pressedKeys.size();
        vector<int> dp(n,-1);
        return solve(pressedKeys,0,dp);
    }
};