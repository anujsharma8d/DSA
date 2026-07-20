class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int count = 2;
        int maxi=INT_MIN;
        for(int i=2;i<n;i++){
            if(nums[i-2]+nums[i-1]==nums[i]){
                count++;
            }
            else{
                count = 2;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};