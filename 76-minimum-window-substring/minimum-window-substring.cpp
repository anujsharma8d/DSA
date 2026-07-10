class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int left=0;
        int minlen=INT_MAX;
        int count=0;
        int start=0;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]--;
            if(mpp[s[right]]>=0){
                count++;
            }
            while(count==t.size()){
                if(right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    start = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0){
                    count--;
                }
                left++;
            }

        }
        if(minlen == INT_MAX){
            return "";
        }
        else{
            return s.substr(start,minlen);
        }
    }
};