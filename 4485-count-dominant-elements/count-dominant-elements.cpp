class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if(n==1){
            return 1;
        }
        for(int i=1;i<n-1;i++){
            float avg = (float(nums[i-1])+float(nums[i+1]))/2.0;
            if(nums[i]>=avg){
                count++;
            }
        }
        if(n>1 && nums[0]>=nums[1]){
            count++;
        }
        if(n>1 && nums[n-1]>=nums[n-2]){
            count++;
        }
        return count;
    }
};