class Solution {
public:
    long long solve(int i,bool isEven,vector<int>& nums,vector<vector<long long>> &dp){
        int n = nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i][isEven]!=-1){
            return dp[i][isEven];
        }
        long long skip = solve(i+1,isEven,nums,dp);
        int val = nums[i];
        if(!isEven){
            val=-val;
        }
        long long take = val+solve(i+1,!isEven,nums,dp);
        return dp[i][isEven]=max(take,skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return solve(0,true,nums,dp);
    }
};