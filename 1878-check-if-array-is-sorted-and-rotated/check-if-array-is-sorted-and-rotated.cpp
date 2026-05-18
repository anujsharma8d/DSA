class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        int temp=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1]){
                temp++;
            }
            else{
                break;
            }
        }
        int st=0;
        for(int i=temp+1;i<n;i++){
            v[st]=nums[i];
            st++;
        }
        for(int i=0;i<temp+1;i++){
            v[st]=nums[i];
            st++;
        }
        for(int i=0;i<n-1;i++){
            if(v[i]<=v[i+1]){

            }
            else{
                return false;
            }
        }
        return true;
    }
};