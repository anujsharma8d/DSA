class Solution {
public:
    int binaryGap(int n) {
        int count=0;
        int ans = 0;
        string s="";
        while(n>0){
            int rem = n%2;
            s+=to_string(rem);
            n/=2;
        }
        int count2=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                count++;
            }
            else{
                ans = max(count,ans);
                count=0;
                count2++;
            }
        }
        if(count2>1){
            return ans+1;
        }
        else{
            return 0;
        }
    }
};