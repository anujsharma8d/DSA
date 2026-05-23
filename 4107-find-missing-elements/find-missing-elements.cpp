class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        int mini=INT_MAX;
        vector<int> ans;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
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