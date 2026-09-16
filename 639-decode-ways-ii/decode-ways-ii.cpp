class Solution {
public:
    const int MOD = 1000000007;

    int solve(string &s,int i,vector<int> &dp){
        if(i==s.size()){
            return 1;
        }
        if(i>s.size()){
            return 0;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long take1 = 0;
        if(s[i]=='*'){
            take1 = 1LL*9*solve(s,i+1,dp);
        }
        else{
            take1 = 1LL*solve(s,i+1,dp);
        }

        long long take2 = 0;
        if(i<s.size()-1){
            if(s[i]=='*' && s[i+1]!='*'){
                    if(s[i+1]-'0'<=6){
                        take2=2LL*solve(s,i+2,dp);
                    }
                    else{
                        take2=1LL*solve(s,i+2,dp);
                    }
                }
            else if(s[i]=='*' && s[i+1]=='*'){
                if(i<s.size()-1){
                    take2 = 15LL*solve(s,i+2,dp);
                }
            }
            else if(s[i]!='*' && s[i+1]=='*'){
                if(i<s.size()-1){
                    if(s[i]=='1' && s[i+1]=='*'){
                        take2 = 9LL*solve(s,i+2,dp);
                    }
                    else if(s[i]=='2' && s[i+1]=='*'){
                        take2 = 6LL*solve(s,i+2,dp);
                    }
                }
            }
            else{
                if(i<s.size()-1 && stoi(s.substr(i,2))<=26){
                    take2 = 1LL*solve(s,i+2,dp);
                }
            }
        }

        return dp[i]=(take1+take2)%MOD;
        
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};