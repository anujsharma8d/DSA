class Solution {
public:
    long long fib(int i,vector<long long> &dp){
        if(i==1){
            return 0;
        }
        if(i==2){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=fib(i-1,dp)+fib(i-2,dp);
    }
    
    bool threeFibonacciSum(int n) {
        long long num = 0;
        vector<long long> fibo;
        int i =1;
        while(num<n){
            vector<long long> dp(i+1,-1);
            num = fib(i,dp);
            fibo.push_back(num);
            i++;
        }  

        int left=0;
        long long sum=0;
        for(int right=0;right<fibo.size();right++){
            sum+=fibo[right];
            if(right-left+1>3){
                sum-=fibo[left];
                left++;
            }
            if(right-left+1==3){
                if(sum==n){
                    return true;
                }
            }
        }
        return false;
    }
};