class Solution {
public:
    int digitFrequencyScore(int n) {
        int res=0;
        while(n!=0){
            res+=n%10;
            n=n/10;
        }
        return res;
    }
};