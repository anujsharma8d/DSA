class Solution {
public:
    bool checkGoodInteger(int n) {
        string s=to_string(n);
        int sum=0;
        int sqsum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i]-'0';
            sqsum+=(s[i]-'0')*(s[i]-'0');
        }
        if(sqsum-sum>=50){
            return true;
        }
        return false;
    }
};