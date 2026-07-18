class Solution {
public:
    bool fun(int i,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(i==0){
            return nums[0]==target;
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=false;
        if(target>=nums[i]){
            take=fun(i-1,target-nums[i],nums,dp);
        }
        bool nottake=fun(i-1,target,nums,dp);
        return dp[i][target]=take||nottake;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return fun(n-1,sum/2,nums,dp);
    }
};