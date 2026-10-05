class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<char> st;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(count);
                count=0;
            }
            else{
                int prev = st.top();
                st.pop();
                if(s[i-1]=='('){
                    count=prev+1;
                }
                else{
                    count=prev+2*count;
                }
            }
        }
        return count;
    }
};