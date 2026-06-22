class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        vector<int> num = {2,3,5};
        for(int fact:num){
            while(n%fact==0){
                n=n/fact;
            }
        }
        if(n==1){
            return true;
        }
        return false;
    }
};