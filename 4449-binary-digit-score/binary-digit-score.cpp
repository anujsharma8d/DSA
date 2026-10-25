class Solution {
public:
    int calculateScore(int a, int b) {
        int s1=0;
        int s2=0;
        while(a!=0){
            int b1 = a%2;
            if(b1==1){
                s1++;
            }
            a/=2;
        }
        while(b!=0){
            int b2 = b%2;
            if(b2==1){
                s2++;
            }
            b/=2;
        }
        if(s1>=s2){
            return s1*s2;
        }
        return s2/s1;
            
    }
};