class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int take = -1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                take = take & nums[i];
            }
        }
        return take == -1 ? 0 : take;
    }
};