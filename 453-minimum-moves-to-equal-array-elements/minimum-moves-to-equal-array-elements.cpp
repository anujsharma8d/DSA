class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int num = nums[0];
        for(int i=1;i<n;i++){
            ans+=nums[i]-num;
        }
        return ans;
    }
};