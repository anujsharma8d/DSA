class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        long long total=0;
        long long ans=INT_MIN;
        for(int right=0;right<nums.size();right++){
            total+=nums[right];
            if(right-left+1==k){
                ans=max(ans,total);
                total-=nums[left];
                left++;
            }
        }
        return (double)ans/k;
    }
};