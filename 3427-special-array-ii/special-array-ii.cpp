class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> temp;
        vector<bool> ans;
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==0 && nums[i+1]%2!=0 || nums[i]%2!=0 && nums[i+1]%2==0){
                temp.push_back(0);
            }
            else{
                temp.push_back(1);
            }
        }
        vector<int> prefixsum(temp.size()+1,0);
        for (int i = 0; i < temp.size(); i++) {
            prefixsum[i + 1] = prefixsum[i] + temp[i];
        }
            int idx=0;
        for(auto x:queries){
            int l=x[0];
            int r=x[1];
            ans.push_back(prefixsum[r] - prefixsum[l] == 0);
        }
        return ans;
    }
};