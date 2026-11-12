class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l1 = 1;
        int count=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
                l1 = max(l1,count);
            }
            else{
                count=1;
            }
        }
        count=1;
        int l2=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                count++;
                l2 = max(l2,count);
            }
            else{
                count=1;
            }
        }
        return max(l1,l2);
    }
};