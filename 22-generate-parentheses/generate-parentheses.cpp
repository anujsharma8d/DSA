class Solution {
public:
    bool isvalid(string s){
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
                if(count<0){
                    return false;
                }
            }
        }
        return count==0;
    }

    void solve(int n,vector<string> &ans,string s){
        if(s.size()==2*n){
            if(isvalid(s)){
                ans.push_back(s);
            }
            return;
        }
        solve(n,ans,s+'(');
        solve(n,ans,s+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,ans,"");
        return ans;
    }
};