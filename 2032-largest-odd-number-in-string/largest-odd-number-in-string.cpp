class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.size();
        int idx = -1;
        string ans="";
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return ans;
        }
        for(int i=0;i<=idx;i++){
            ans+=num[i];
        }
        return ans;

    }
};