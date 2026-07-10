class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int left=0;
        unordered_map<char,int> mpp;
        int count=0;
        for(int i=0;i<p.size();i++){
            mpp[p[i]]++;
        }
        for(int right=0;right<s.size();right++){
            mpp[s[right]]--;
            if(mpp[s[right]]>=0){
                count++;
            }
            if(right-left+1>p.size()){
                mpp[s[left]]++;
                if(mpp[s[left]]>0){
                    count--;
                }
                left++;
            }
            if(count==p.size()){
                ans.push_back(left);
            }
        }
        return ans;
    }
};