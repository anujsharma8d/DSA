class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st=1;
        int end=1;
        while(end!=nums.size()){
            if(nums[end]!=nums[end-1]){
                nums[st]=nums[end];
                st++;
            }
            end++;
        }
        return st;


    }
};