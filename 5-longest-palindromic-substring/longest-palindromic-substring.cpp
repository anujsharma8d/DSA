class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=1;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen=r-l+1;
                    start=l;
                }
                r++;
                l--;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen=r-l+1;
                    start=l;
                }
                r++;
                l--;
            }
        }
        return s.substr(start,maxlen);
    }
};