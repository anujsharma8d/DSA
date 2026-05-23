class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=nums[n-1];
        int mini=nums[0];
        vector<int> ans;
        int n1=0;
        for(int i=mini;i<=maxi;i++){
            if(nums[n1]!=i){
                ans.push_back(i);
            }
            else{
                n1++;
            }
        }
        return ans;
    }
};