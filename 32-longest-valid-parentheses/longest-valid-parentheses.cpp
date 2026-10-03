class Solution {
public:
    bool isvalid(string s,int l,int r){
        int count=0;
        for(int i=l;i<r;i++){
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
        if(count==0){
            return true;
        }
        return false;
    }

    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0;
        int close = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                ans=max(ans,open+close);
            }
            else if(close>open){
                open=0;
                close=0;
            }
        }
        open=0;
        close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                ans=max(ans,open+close);
            }
            else if(close>open){
                open=0;
                close=0;
            }
        }
        return ans;
    }
};