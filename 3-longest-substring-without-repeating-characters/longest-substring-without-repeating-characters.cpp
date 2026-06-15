class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(char x:s.substr(i)){
                if(mpp.count(x)){
                    break;
                }
                mpp[x]++;
                count++;
            }
            mpp.clear();
            ans=max(ans,count);
        }
        return ans;
    }
};