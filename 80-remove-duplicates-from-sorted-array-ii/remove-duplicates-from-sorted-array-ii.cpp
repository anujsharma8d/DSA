class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int left=2;
        int right=2;
        while(right!=n){
            if(nums[left-2]==nums[right]){
                right++;
            }
            else{
                nums[left]=nums[right];
                left++;
                right++;
            }
        }
        return left;
    }
};