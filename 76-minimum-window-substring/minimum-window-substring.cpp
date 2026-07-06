class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int left=0;
        int right=0;
        int count = 0;
        int minlen=INT_MAX;
        int idx=-1;
        while(right<s.size()){
            if(mpp[s[right]]>0){
                count++;
            }
            mpp[s[right]]--;
            while(count==t.size()){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    idx=left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        if(idx==-1){
            return "";
        }
        else{
            return s.substr(idx,minlen);
        }
    }
};