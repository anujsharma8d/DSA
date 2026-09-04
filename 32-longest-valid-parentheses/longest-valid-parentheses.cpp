class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;
        int maxi=0;
        for(char c:s){
            if(c=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                int len = open+close;
                maxi=max(maxi,len);
            }
            else if(close>open){
                open=0;
                close=0;
            }
        }
        open=0;
        close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                int len = open+close;
                maxi=max(maxi,len);
            }
            else if(open>close){
                open=0;
                close=0;
            }
        }
        return maxi;
    }
};