class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1000000007;
        long long gcount=0;
        long long mcount=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<a){
                ans=(ans+gcount+mcount)%MOD;
            }
            else if(nums[i]<=b){
                ans=(ans+gcount)%MOD;
                mcount++;
            }
            else{
                gcount++;
            }
        }
        return (int)ans;
        
        
    }
};