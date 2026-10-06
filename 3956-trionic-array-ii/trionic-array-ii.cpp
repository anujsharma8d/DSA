class Solution {
public:
    long long NEG = -1e18;
    long long solve(vector<int>& nums,int i,int track,vector<vector<long long>> &dp){
        int n=nums.size();
        if(i==n){
            if(track==3){
                return 0;
            }
            else{
                return NEG;
            }
        }
        if(dp[i][track]!=-1){
            return dp[i][track];
        }

        long long take=NEG;
        long long skip=NEG;
        long long ans = NEG;
        
        if(track==3){
            ans=nums[i];
        }
        if(track==0){
            skip = solve(nums,i+1,track,dp);
            ans=max(skip,ans);
        }
        if(i+1<n){
            if(track==0 && nums[i+1]>nums[i]){
                take = nums[i]+solve(nums,i+1,1,dp);
                ans=max(take,ans);
            }
            else if(track==1){
                if(nums[i+1]>nums[i]){
                    take = nums[i]+solve(nums,i+1,1,dp);
                    ans=max(take,ans);
                }
                else if(nums[i+1]<nums[i]){
                    take = nums[i]+solve(nums,i+1,2,dp);
                    ans=max(take,ans);
                }
            }
            else if(track==2){
                if(nums[i+1]<nums[i]){
                    take = nums[i]+solve(nums,i+1,2,dp);
                    ans=max(take,ans);
                }
                else if(nums[i+1]>nums[i]){
                    take = nums[i]+solve(nums,i+1,3,dp);
                    ans=max(take,ans);
                }
            }
            else if(track==3){
                if(nums[i+1]>nums[i]){
                    take = nums[i]+solve(nums,i+1,3,dp);
                    ans=max(take,ans);
                }
            }
        }
        return dp[i][track]=ans;
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(4,-1)); 
        return solve(nums,0,0,dp);
    }
};