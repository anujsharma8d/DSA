class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int f=0;
        int count=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[f]=nums[i];
                f++;
                count++;
            }

        }
        return count;
    }
};