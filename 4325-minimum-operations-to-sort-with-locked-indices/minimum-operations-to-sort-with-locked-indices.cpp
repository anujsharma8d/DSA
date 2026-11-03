class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int count = 0;
        int swapp = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1] && locked[j]==0 && locked[j+1]==0){
                    swap(nums[j],nums[j+1]);
                    swapp++;
                }
                else if(nums[j]>nums[j+1] && locked[j]==1 && locked[j+1]==0){
                    locked[j]=0;
                    count++;
                    swap(nums[j],nums[j+1]);
                    swapp++;
                }
                else if(nums[j]>nums[j+1] && locked[j]==0 && locked[j+1]==1){
                    locked[j+1]=0;
                    count++;
                    swap(nums[j],nums[j+1]);
                    swapp++;
                }
                else if(nums[j]>nums[j+1] && locked[j]==1 && locked[j+1]==1){
                    locked[j]=0;
                    locked[j+1]=0;
                    count+=2;
                    swap(nums[j],nums[j+1]);
                    swapp++;
                }
                // cout<<count<<endl;
                if(count>k){
                    return -1;
                }
            }
        }
        bool asc = true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                asc = false;
            }
        }
        if(!asc){
            return -1;
        }
        return count+swapp;
    }
};