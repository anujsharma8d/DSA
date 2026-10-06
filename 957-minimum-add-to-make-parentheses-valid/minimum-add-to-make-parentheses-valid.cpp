class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char> st;
        int count=0;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    count++;
                }
            }
        }
        return st.size()+count;
    }
};