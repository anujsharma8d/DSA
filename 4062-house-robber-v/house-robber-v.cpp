class Solution {
public:
    long long fun(int i,vector<int>& nums, vector<int>& colors,vector<long long>& dp){
        if(i==0){
            return nums[0];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long take;
        if(colors[i]==colors[i-1]){
            take = nums[i]+fun(i-2,nums,colors,dp);
        }
        else{
            take = nums[i]+fun(i-1,nums,colors,dp);
        }
        long long nottake=fun(i-1,nums,colors,dp);
        return dp[i] = max(take,nottake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long> dp(n,-1);
        return fun(n-1,nums,colors,dp);
    }
};