class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix;
        vector<long long> suffix;
        long long sum=0;
        long long maxi=LLONG_MIN;
        long long mini=nums[n-1];
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        for(int i=n-1;i>=0;i--){
            suffix.push_back(mini);
            mini=min(mini,(long long)nums[i]);
        }
        reverse(suffix.begin(),suffix.end());
        for(int i=0;i<n-1;i++){
            long long diff=prefix[i]-suffix[i];
            maxi=max(maxi,diff);
        }
        return maxi;

    }
};