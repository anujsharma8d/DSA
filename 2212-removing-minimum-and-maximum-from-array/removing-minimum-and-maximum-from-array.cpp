class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int maxidx = 0;
        int minidx = 0;
        for(int i = 0;i<nums.size();i++){
            if(mini>nums[i]){
                mini=nums[i];
                minidx=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                maxidx=i;
            }
        }
        int op1 = min(minidx,maxidx)+1+nums.size()-max(minidx,maxidx);
        int op2 = max(maxidx,minidx)+1;
        int op3 = nums.size()-min(maxidx,minidx);
        return min({op1,op2,op3});
    }
};