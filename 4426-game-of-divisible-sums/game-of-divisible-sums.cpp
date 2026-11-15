class Solution {
public:
    long long solve(vector<int>& nums,int i,int turn,vector<vector<long long>> &dp){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][turn]!=LLONG_MIN){
            return dp[i][turn];
        }

        long long takeone = 0;
        long long x = nums[i];
        if(nums[i]%3==0){
            if(turn==0){
                takeone = x+solve(nums,i+1,1,dp);
            }
            else{
                takeone = -x+solve(nums,i+1,0,dp);
            }
        }
        else{
            if(turn==0){
                takeone = x+solve(nums,i+1,0,dp);
            }
            else{
                takeone = -x+solve(nums,i+1,1,dp);
            }
        }
        long long taketwo;
        if(turn == 0) taketwo = LLONG_MIN;
        else taketwo = LLONG_MAX;
        if(i<n-1){
            long long s = 1LL*nums[i]+nums[i+1];
            if(s%3==0){
                if(turn==0){
                    taketwo = s+solve(nums,i+2,1,dp);
                }
                else{
                    taketwo = (-1)*(s)+solve(nums,i+2,0,dp);
                }
            }
            else{
                if(turn==0){
                    taketwo = s+solve(nums,i+2,0,dp);
                }
                else{
                    taketwo = (-1)*(s)+solve(nums,i+2,1,dp);
                }
            }
        }
        if(turn==0){
            return dp[i][turn] = max(takeone,taketwo);
        }
        else{
            return dp[i][turn] = min(takeone,taketwo);
        }
    }
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,LLONG_MIN));
        return solve(nums,0,0,dp);
    }
};