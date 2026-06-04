class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v;
        for(int x:nums){
            int maxi=INT_MIN;
            string s=to_string(x);
            for(int i=0;i<s.size();i++){
                maxi=max(maxi,s[i]-'0');
            }
            v.push_back(maxi);
        }
        int maxsum=-1;
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(v[i]==v[j]){
                    maxsum=max(maxsum,nums[i]+nums[j]);
                }
            }
        }
        return maxsum;
    }
};