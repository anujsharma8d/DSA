class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int b = INT_MAX;
            int mini = INT_MAX;
            for(int j=i;j<n;j++){
                b &= nums[j];
                mini= min(mini,nums[j]);
                if(b==mini){
                    count++;
                }
            }
        }
        return count;

    }
};