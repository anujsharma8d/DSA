class Solution {
public:
    int solve(string &s,int i,vector<int> &dp){
        if(i==s.size()){
            return 1;
        }
        if(i>s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take1=0;
        int take2 = 0;
        if(s[i]!='0'){
            take1 = solve(s,i+1,dp);
            if(i<s.size()-1 && stoi(s.substr(i,2))<=26){
                take2 = solve(s,i+2,dp);
            }
        }
        
        return dp[i]=take1+take2;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};