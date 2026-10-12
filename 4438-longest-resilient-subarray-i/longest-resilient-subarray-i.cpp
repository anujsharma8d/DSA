class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int len=1;
        int sum=nums[0]%k;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]%k==nums[i-1]%k){
                len++;
                sum=(sum+nums[i]%k)%k;
            }
            else{
                sum=nums[i]%k;
                len=1;
            }

            if(len==1 || sum==nums[i]%k){
                ans=max(ans,len);
            }
        }
        return ans;
    }
};