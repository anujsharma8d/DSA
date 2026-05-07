class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]<=nums[i-1]){
                idx=i;
                break;
            }
        }
        return idx;
    }
};