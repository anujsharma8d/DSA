class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n-2;
        long long ans=0;
        while(left<right){
            ans+=nums[right];
            left++;
            right-=2;
        }   
        return ans;
    }
};