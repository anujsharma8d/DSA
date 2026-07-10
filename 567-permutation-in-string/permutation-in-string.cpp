class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int left=0;
        int count=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s1[i]]++;
        }
        for(int right=0;right<s2.size();right++){
            mpp[s2[right]]--;
            if(mpp[s2[right]]>=0){
                count++;
            }
            if(right-left+1>n){
                mpp[s2[left]]++;
                if(mpp[s2[left]]>0){
                    count--;
                }
                left++;
            }
            if(count==n){
                return true;
            }
        }
        return false;
    }
};