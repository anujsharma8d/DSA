class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int take = n/2;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        long long score=0;
        for(int i=0;i<take;i++){
            score-=nums[i]*nums[i];
        }
        for(int i=take;i<n;i++){
            score+=nums[i]*nums[i];
        }
        return score;
    }
};