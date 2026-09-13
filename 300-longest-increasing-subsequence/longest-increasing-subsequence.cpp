class Solution {
public:
    int solve(vector<int>& nums,int i,int prevIdx,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prevIdx+1]!=-1){
            return dp[i][prevIdx+1];
        }
        int nottake = solve(nums,i+1,prevIdx,dp);
        int len=nottake;

        if(prevIdx==-1 || nums[i]>nums[prevIdx]){
            int take = 1+solve(nums,i+1,i,dp);
            len = max(nottake,take);
        }
        return dp[i][prevIdx+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};