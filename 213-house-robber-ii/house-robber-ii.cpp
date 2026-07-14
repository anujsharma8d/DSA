class Solution {
public:
    int fun(int i,int end,vector<int>& nums,vector<int> &dp){
        if(i<end){
            return 0;
        }
        if(i==end){
            return nums[end];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = nums[i]+fun(i-2,end,nums,dp);
        int nottake = fun(i-1,end,nums,dp);
        return dp[i]=max(take,nottake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(fun(n-1,1,nums,dp1),fun(n-2,0,nums,dp2));
    }
};