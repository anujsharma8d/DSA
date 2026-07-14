class Solution {
public:
    bool fun(int i,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(i==0){
            return target==nums[0];
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool nottake=fun(i-1,target,nums,dp);
        bool take=false;
        if(target>=nums[i]){
            take=fun(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        if(sum%2!=0){
            return false;
        }
        return fun(n-1,sum/2,nums,dp);

    }
};