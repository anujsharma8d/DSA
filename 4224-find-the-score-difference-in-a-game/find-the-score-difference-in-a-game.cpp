class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                count1++;
            }
            if((i+1)%6==0){
                count1++;
            }
            if(count1%2==0){
                sum1+=nums[i];
            }
            if(count1%2!=0){
                sum2+=nums[i];
            }
        }
        return sum1-sum2;
    }
};