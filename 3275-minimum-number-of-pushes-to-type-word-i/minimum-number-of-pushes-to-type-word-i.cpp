class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int count=0;
        for(int i=0;i<word.size();i++){
            count++;
            if(count>=9 && count<17){
                ans+=2;
            }
            else if(count>=17 && count<25){
                ans+=3;
            }
            else if(count>=25){
                ans+=4;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};