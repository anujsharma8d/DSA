class Solution {
public:
    bool solve(string s,int open,int i,vector<vector<int>> &dp){
        bool isvalid = false;
        if(i==s.size()){
            return open==0;
        }
        if(dp[i][open]!=-1){
            return dp[i][open];
        }
        if(s[i]=='('){
            isvalid |= solve(s,open+1,i+1,dp);
        }
        else if(s[i]=='*'){
            isvalid|=solve(s,open+1,i+1,dp);
            isvalid|=solve(s,open,i+1,dp);
            if(open>0){
                isvalid|=solve(s,open-1,i+1,dp);
            }
        }
        else{
            if(open>0){
                isvalid |= solve(s,open-1,i+1,dp);
            }
        }
        return dp[i][open]=isvalid;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,0,dp);
    }
};