class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left=0;
        long long sum=0;
        long long ans=0;
        unordered_map<int,int> mpp;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            mpp[nums[right]]++;
            if(right-left+1>k){
                sum-=nums[left];
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            if(mpp.size()==k){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};