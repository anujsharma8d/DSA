class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGcd.push_back(gcd(nums[i],maxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum=0;
        int left=0;
        int right=n-1;
        while(left<right){
            sum+=gcd(prefixGcd[left],prefixGcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};