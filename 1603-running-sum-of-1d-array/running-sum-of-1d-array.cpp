class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefSum(n,0);
        prefSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefSum[i]=prefSum[i-1]+nums[i];
        }
        return prefSum;
    }
};