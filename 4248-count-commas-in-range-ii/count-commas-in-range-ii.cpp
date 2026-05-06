class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n<1000){
            ans= 0;
        }
        else if(n<1000000){
            ans=n-999;
        }
        else if(n<1000000000){
            ans=(n-999999)*2;
            ans+=999000;
        }
        else if(n<1000000000000){
            ans=(n-999999999)*3;
            ans+=999000000*2;
            ans+=999000;
        }
        else if(n<1000000000000000){
            ans=(n-999999999999)*4;
            ans+=999000000000*3;
            ans+=999000000*2;
            ans+=999000;
        }
        else if(n<1000000000000000000){
            ans=(n-999999999999999)*5;
            ans+=999000000000000*4;
            ans+=999000000000*3;
            ans+=999000000*2;
            ans+=999000;
        }
        return ans;
    }
};