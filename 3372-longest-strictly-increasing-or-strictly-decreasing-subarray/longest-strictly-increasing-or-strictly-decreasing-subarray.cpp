class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int count1=1;
        int count2=1;
        int maxi=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                count1++;
            }
            else{
                count1=1;
            }
            if(nums[i-1]>nums[i]){
                count2++;
            }
            else{
                count2=1;
            }
            maxi=max(maxi,max(count1,count2));
        }
        return maxi;
    }
};