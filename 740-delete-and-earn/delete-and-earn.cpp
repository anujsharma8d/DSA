class Solution {
public:
    int solve(vector<int>& sum,int i,vector<int> &dp){
        if(i>=sum.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake = solve(sum,i+1,dp);
        int take = sum[i]+solve(sum,i+2,dp);

        return dp[i]=max(take,nottake);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i:nums){
            maxi=max(maxi,i);
        }   
        vector<int> dp(maxi+1,-1);
        vector<int> sum(maxi+1,0);
        for(int i:nums){
            sum[i]+=i;
        }
        return solve(sum,0,dp);
    }
};