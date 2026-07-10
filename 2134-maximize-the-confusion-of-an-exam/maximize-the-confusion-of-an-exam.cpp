class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0;
        int ans=0;
        int countTrue=0;
        int countFalse=0;
        int maxfreq=0;
        for(int right=0;right<answerKey.size();right++){
            if(answerKey[right]=='T'){
                countTrue++;
            }
            else{
                countFalse++;
            }
            maxfreq=max(countTrue,countFalse);
            while((right-left+1)-maxfreq>k){
                if(answerKey[left]=='T'){
                    countTrue--;
                }
                else{
                    countFalse--;
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};