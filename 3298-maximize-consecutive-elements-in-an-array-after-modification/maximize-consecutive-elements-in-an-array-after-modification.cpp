class Solution {
public:
    int findMethod(vector<int> &nums,int start,int target){
        int n = nums.size();
        int j = lower_bound(nums.begin()+start,nums.end(),target)-nums.begin();

        if(j<n && target==nums[j]){
            return j;
        }
        return -1;

    }


    int solve(int i,int inc,vector<int> &nums,vector<vector<int>> &dp){
        if(dp[i][inc]!=-1){
            return dp[i][inc];
        }

        int currval = nums[i]+inc;

        int len = 1;

        //Case1
        int j = findMethod(nums,i+1,currval+1);
        if(j!=-1){
            len = max(len,1+solve(j,0,nums,dp));
        }

        //Case2
        j = findMethod(nums,i+1,currval);
        if(j!=-1){
            len = max(len,1+solve(j,1,nums,dp));
        }

        return dp[i][inc]=len;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int result = 1;
        for(int i=0;i<n;i++){
            result = max({result,solve(i,0,nums,dp),solve(i,1,nums,dp)});
        }
        return result;
    }
};