class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int temp=0;
        if(n<4){
            return false;
        }
        for(int i=0;i<n-1;i++){
            if(count==0 && nums[i]<nums[i+1]){
                temp++;
            }
            else if(temp>0 && count==0 && nums[i]>nums[i+1]){
                count++;
                temp++;
            }
            else if(count==1 && nums[i]>nums[i+1]){
                temp++;
            }
            else if(count==1 && nums[i]<nums[i+1]){
                count++;
                temp++;
            }
            else if(count==2 && nums[i]<nums[i+1]){
                temp++;
            }

        }
        return count==2 && temp==n-1;

    }
};