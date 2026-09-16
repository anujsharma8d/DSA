class Solution {
public:
    int solve(vector<int>& nums, int target,int i,map<pair<int,int>,int> &dp){
        if(i==nums.size()){
            return target==0;
        }
        if(i>nums.size()){
            return 0;
        }
        if(dp.count({i,target})){
            return dp[{i,target}];
        }
        
        int a = solve(nums,target-nums[i],i+1,dp);
        int s = solve(nums,target+nums[i],i+1,dp);

        return dp[{i,target}]=a+s;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> dp; 
        return solve(nums,target,0,dp);
    }
};