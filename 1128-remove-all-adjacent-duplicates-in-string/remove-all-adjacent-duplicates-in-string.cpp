class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        string s1="";
        for(int i=0;i<n;i++){
            char c=s[i];
            if(!s1.empty() && s1.back()==c){
                s1.pop_back();
                continue;
            }
            s1.push_back(c);
        }
        return s1;
    }
};