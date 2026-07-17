class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string s:words){
            unordered_map<char,int> mpp2;
            unordered_map<char,int> mpp1;
            bool valid =true;
            for(int i=0;i<pattern.size();i++){
                char first = s[i];
                char second = pattern[i];
                if(mpp1.count(first)){
                    if(mpp1[first]!=second){
                        valid=false;
                        break;
                    }
                }
                else{
                    mpp1[first]=second;
                }
                if(mpp2.count(second)){
                    if(mpp2[second]!=first){
                        valid=false;
                        break;
                    }
                }
                else{
                    mpp2[second]=first;
                }
            }
            if (valid) {
                ans.push_back(s);
            }
        }

        return ans;
        
    }
};