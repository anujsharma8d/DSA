class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=0;
        int maxrun = 0;
        int prevrun = -1;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                ones++;
                i++;
            }
            else{
                int curr=0;
                while(i<n && s[i]=='0'){
                    curr++;
                    i++;
                }
                if(prevrun>0){
                    maxrun=max(maxrun,prevrun+curr);
                }
                prevrun = curr;
            }
        } 
        return ones+maxrun;

    }
};