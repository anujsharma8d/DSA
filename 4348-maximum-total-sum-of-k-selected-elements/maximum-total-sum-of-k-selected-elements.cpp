class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int n=nums.size();
        for(int i=n-1;i>n-1-k;i--){
            if(mul>0){
                sum+=1LL*mul*nums[i];
            }
            else{
                sum+=nums[i];
            }
            mul--;
        }
        return sum;
    }
};