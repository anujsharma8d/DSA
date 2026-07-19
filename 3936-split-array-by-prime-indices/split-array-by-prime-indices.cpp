class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();

        if(n==0){
            return 0;
        }
        vector<bool> prime(n + 1, true);

        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        long long sum1=0;
        long long sum2=0;
        for(int i=0;i<n;i++){
            if(prime[i]){
                sum1+=nums[i];
            }
            else{
                sum2+=nums[i];
            }
        }
        return abs(sum1-sum2);
    }
};