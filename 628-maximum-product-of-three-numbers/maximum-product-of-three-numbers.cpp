class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last = nums.size()-1;
        long long first = nums[last]*nums[last-1]*nums[last-2];
        long long second = nums[0]*nums[1]*nums[last];
        return max(first,second);
    }
};