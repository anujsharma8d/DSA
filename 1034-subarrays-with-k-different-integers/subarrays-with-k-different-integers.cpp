class Solution {
public:
    int ansk(vector<int>& nums, int k){
        int n=nums.size();
        int left=0;
        int ans=0;
        unordered_map<int,int> mpp;
        for(int right=0;right<n;right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return ansk(nums,k)-ansk(nums,k-1);
    }
};