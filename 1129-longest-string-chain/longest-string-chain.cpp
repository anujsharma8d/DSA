class Solution {
public:
    bool canUse(string &s1,string &s2){
        int p1=0;
        int p2=0;
        int count=0;
        if(s1.size()+1==s2.size()){
            while(p1<s1.size() && p2<s2.size()){
                if(s1[p1]!=s2[p2]){
                    count++;
                    p2++;
                }
                else{
                    p1++;
                    p2++;
                }
                if(count>1){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }

    int solve(vector<string>& words,int i,int lastidx,vector<vector<int>> &dp){
        if(i>=words.size()){
            return 0;
        }
        if(dp[i][lastidx+1]!=-1){
            return dp[i][lastidx+1];
        }
        int nottake = solve(words,i+1,lastidx,dp);
        int ans=nottake;
        if(lastidx==-1 || canUse(words[lastidx],words[i])){
            int take = 1+solve(words,i+1,i,dp);
            ans=max(take,nottake);
        }

        return dp[i][lastidx+1]=ans;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        sort(words.begin(),words.end(),[](const string &a, const string &b){
            return a.size()<b.size();
        });
        return solve(words,0,-1,dp);
    }
};