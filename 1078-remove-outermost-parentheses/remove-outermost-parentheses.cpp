class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int count=0;
        int prev=0;
        for(int i=0;i<n-1;i++){
            prev=count;
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count>0 && prev!=0){
                ans+=s[i];
            }
        }
        return ans;
    }
};