class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        int beauty=0;
        vector<int> maxi(n);
        vector<int> mini(n);
        maxi[0]=nums[0];
        mini[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i]);
        }
        for(int i=1;i<=n-2;i++){
            if(nums[i]>maxi[i-1] && nums[i]<mini[i+1]){
                beauty+=2;
            }
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                beauty++;
            }
        }
        return beauty;
    }
};