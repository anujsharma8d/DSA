class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int maxi=nums[0];
        int mini=nums[n-1];
        vector<int> v;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[st]);
            v.push_back(maxi);
            st++;
        }
        for(int i=0;i<n;i++){
            mini=min(mini,nums[end]);
            v[end]=v[end]-mini;
            end--;
        }
        for(int i=0;i<n;i++){
            if(v[i]<=k){
                return i;
            }
        }
        return -1;
    }
};