class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = nums.size();
        return (nums[s-1]-1)*(nums[s-2]-1);
    }
};