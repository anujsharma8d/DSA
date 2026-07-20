class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        return mpp.size();
    }
};