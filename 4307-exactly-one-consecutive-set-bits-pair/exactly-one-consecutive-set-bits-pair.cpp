class Solution {
public:
    bool consecutiveSetBits(int n) {
        string s = bitset<32>(n).to_string();
        int count=0;
        for(int i=31;i>=1;i--){
            if(s[i]=='1' && s[i-1]=='1'){
                count++;
            }
            if(count>1){
                return false;
            }
        }
        if(count==1){
            return true;
        }
        else{
            return false;
        }
    }
};