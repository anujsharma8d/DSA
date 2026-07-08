class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int st=i+1;
            int end=n-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(st<end){
                if(nums[i]+nums[st]+nums[end]==0){
                    ans.push_back({nums[i],nums[st],nums[end]});
                    st++;
                    end--;
                    while(st<end && nums[st]==nums[st-1]){
                        st++;
                    }
                }
                else if(nums[i]+nums[st]+nums[end]>0){
                    end--;
                }
                else{
                    st++;
                }
            }
        }
        return ans;
    }
};