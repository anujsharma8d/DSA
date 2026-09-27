class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> temp;
        vector<int> st;
        vector<int> finish;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                temp.push_back(i);
            }
            if(s[i]==')'){
                int open = temp.back();
                temp.pop_back();
                st.push_back(open);
                finish.push_back(i);
            }
        }
        for(int i=0;i<st.size();i++){
            reverse(s.begin()+st[i]+1,s.begin()+finish[i]);
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=')' && s[i]!='('){
                ans+=s[i];
            }
        }
        return ans;
    }
};