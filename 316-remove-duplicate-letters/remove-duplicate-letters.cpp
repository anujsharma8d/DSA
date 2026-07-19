class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        unordered_map<char,int> lastidx;
        unordered_map<char,int> seen;
        for(int i=0;i<n;i++){
            lastidx[s[i]]=i;
        }
        string s1="";
        for(int i=0;i<n;i++){
            char c=s[i];
            if(seen[c]){
                continue;
            }
            while(!s1.empty() && s1.back()>c && lastidx[s1.back()]>i){
                seen.erase(s1.back());
                s1.pop_back();
            }
            s1.push_back(c);
            seen[c]=true;
        }
        return s1;
    }
};