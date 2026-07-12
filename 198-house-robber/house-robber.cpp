class Solution {
public:
    int fun(int idx,vector<int>& nums,vector<int> &dp){
        if(idx<0){
            return 0;
        }
        if(idx==0){
            return nums[0];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=fun(idx-2,nums,dp)+nums[idx];
        int nottake=fun(idx-1,nums,dp);
        return dp[idx]=max(take,nottake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(n-1,nums,dp);
    }
};