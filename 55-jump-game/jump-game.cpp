class Solution {
public:
    bool fun(int i,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        if(i>=n-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool jump = false;
        for(int j=1;j<=nums[i];j++){
            if(fun(j+i,nums,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;

    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(0,nums,dp);
    }
};