class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
        }
        int count=0;
        for(int i=n-1;i>n-1-zero;i--){
            if(nums[i]==0){
                count++;
            }
        }
        return zero-count;
    }
};