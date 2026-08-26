class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int count=0;
        int mini=INT_MAX;
        string ans="";
        int left=0;
        for(int right=0;right<n;right++){
            if(s[right]=='1'){
                count++;
            }
            while(count>k){
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }
            while(left<right && s[left]=='0' && count==k){
                left++;
            }
            if(count==k){
                if(right-left+1<mini){
                    mini=right-left+1;
                    ans=s.substr(left,right-left+1);
                }
                else if(right-left+1==mini){
                    if(s.substr(left,right-left+1)<ans){
                        ans=s.substr(left,right-left+1);
                    }
                }

            }
        }
            return ans;
    }
};